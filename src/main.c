
/**
 * BCC -- Beck's C Compiler
 * Author: Adam "beckadamtheinventor" Beckingham
 * 
 * Based on c4.c by Robert Swierczek
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "ez80.h"
#include "ti84pceg.h"

// #define DEBUG

#ifdef PLATFORM_DESKTOP

#define _malloc malloc
#define _free free

#else

#include <tice.h>

#ifdef BOS_BUILD
	// BOS Specific defines
#include <bos.h>

#define _malloc sys_Malloc
#define _free sys_Free

#else
	// TI-OS Specific defines
#include <fileioc.h>

// Implement similar malloc/free from BOS on TI-OS
#define __mallocblocksize 16
#define __mallocnumblocks 1024
#define __malloclen (__mallocblocksize*__mallocnumblocks)
uint8_t __mallocalloc[__mallocnumblocks];
uint8_t __mallocmem[__mallocnumblocks*__mallocblocksize];

void *_malloc(unsigned int amt) {
	static bool hasInit = false;
	uint8_t *i = &__mallocalloc;
	uint8_t *j;
	unsigned int k;
	if (!hasInit) {
		memset((void*)&__mallocalloc, 0, __mallocnumblocks);
		hasInit = true;
	}
	do {
		unsigned int k;
		while (*i && i < (void*)&__mallocalloc[sizeof(__mallocalloc)])
			i++;
		if (*i)
			return NULL;
		j = i;
		k = __mallocblocksize;
		while (!*i && i < (void*)&__mallocalloc[sizeof(__mallocalloc)] && k < amt) {
			i++;
			k += __mallocblocksize;
		}
	} while (k < amt);
	i = j;
	k = __mallocblocksize;
	*i++ = 1;
	while (k < amt) {
		*i++ = 2;
		k += __mallocblocksize;
	}
	return &__mallocmem[j - (uint8_t*)&__mallocalloc];
}

int _free(uint8_t *ptr) {
	if (ptr < (uint8_t*)&__mallocmem || ptr > (uint8_t*)&__mallocmem[sizeof(__mallocmem)])
		return 1;
	ptr = (uint8_t*)&__mallocalloc[(ptr - (uint8_t*)&__mallocmem) / __mallocblocksize];
	*ptr++ = 0;
	while (*ptr == 2)
		*ptr++ = 0;
	return 0;
}

#endif
#endif


enum {
	SYM_DEFINE = 1,
	SYM_CONSTANT,
	SYM_FUNCTION,
	SYM_EXPR,
	SYM_VAR,
	SYM_MASK = 0x1F,
	SYM_RESOLVED = 0x20,
	SYM_LOCAL = 0x40,
	SYM_GLOBAL = 0x80,
};

enum {
	T_VOID = 0,
// make sure that char, word, num, and long in this enum are equal to 1, 2, 3, and 4.
	T_CHAR = 1,
	T_WORD,
	T_NUM,
	T_INT = T_NUM,
	T_LONG,
	T_TYPEDEF,
	T_STRUCT,
	T_BOOL,
	T_STR,
	T_INLINE_DATA,
	T_BOOL_CF = 26,
	T_BOOL_NCF,
	T_BOOL_ZF,
	T_BOOL_NZF,
	T_MASK = 31,
	T_PTR = 32,
};

enum {
	IR_NOP,
	IR_IMM, // load immediate 24-bit value
	IR_IMM_PROG_OFFSET, // load immediate 24-bit value offset of expr from exprstart
	IR_IMM_32, // load immediate 32-bit value
	IR_IMM_8, // load immediate 8-bit value
	IR_PUSH, // push primary register
	IR_PUSH_SEC, // push secondary register
	IR_PUSH_TER, // push tertiary register
	IR_PUSH_IMM, // load and push immediate value
	IR_PUSH_32, // push 32-bit value
	IR_PUSH_IMM_32, // load and push immediate 32-bit value
	IR_POP, // pop into primary register
	IR_POP_SEC, // pop into secondary register
	IR_POP_TER, // pop into tertiary register
	IR_POP_32, // pop 32-bit value into secondary register
	IR_EX_SEC_PRI, // exchange primary and secondary registers
	IR_CALL, // call immediate
	IR_ADJ, // adjust stack
	IR_ENTER, // enter function, adjust stack
	IR_LEAVE, // pop stack, exit function
	IR_EXIT, // exit program
	IR_STORE_LOCAL, // store primary to local variable
	IR_STORE_GLOBAL, // store primary to global variable
	IR_LEA_LOCAL, // load effective address of local variable
	IR_LEA_GLOBAL, // load effective address of global variable
	IR_LOAD_CHAR, // load indirect character (8-bit)
	IR_LOAD_WORD, // load indirect word (16-bit)
	IR_LOAD_INT, // load indirect int (24-bit)
	IR_LOAD_LONG, // load indirect long (32-bit)
	IR_COMPARE_Z, // compare secondary register == 0, storing the result to the primary register
	IR_COMPARE_NZ, // compare secondary register != 0, storing the result to the primary register

// <make sure the following tokens are in the same order as their corresponding token values>
	IR_LOR, // logical OR secondary by primary register, storing to primary
	IR_LAND, // logical AND secondary by primary register, storing to primary
	IR_NOT, // bitwise NOT primary register
	IR_OR, // bitwise OR secondary by primary register, storing to primary
	IR_XOR, // bitwise XOR secondary by primary register, storing to primary
	IR_AND, // bitwise AND secondary by primary register, storing to primary
	IR_COMPARE_EQ, // compare secondary register == primary register, storing the result to the primary register
	IR_COMPARE_NEQ, // compare secondary register != primary register, storing the result to the primary register
	IR_COMPARE_LT, // compare secondary register < primary register, storing the result to the primary register
	IR_COMPARE_GT, // compare secondary register > primary register, storing the result to the primary register
	IR_COMPARE_LTEQ, // compare secondary register <= primary register, storing the result to the primary register
	IR_COMPARE_GTEQ, // compare secondary register >= primary register, storing the result to the primary register
	IR_SHL, // shift left secondary by primary register, storing to primary
	IR_SHR, // shift right secondary by primary register, storing to primary
	IR_ADD, // add secondary by primary register, storing to primary
	IR_SUB, // subtract secondary by primary register, storing to primary
	IR_MUL, // multiply secondary by primary register, storing to primary
	IR_DIV, // divide secondary by primary register, storing to primary
	IR_MOD, // modulo secondary by primary register, storing to primary
// </>

	IR_NEG, // negate primary register (subtract from 0)
	IR_INC, // increment primary register
	IR_INC_SEC, // increment secondary register
	IR_INC_TER, // increment tertiary register
	IR_DEC, // decrement primary register
	IR_DEC_SEC, // decrement secondary register
	IR_DEC_TER, // decrement tertiary register

	IR_OR_CONST, // bitwise OR by constant
	IR_XOR_CONST, // bitwise XOR by constant
	IR_AND_CONST, // bitwise AND by constant
	IR_COMPARE_EQ_CONST, // compare primary equal to constant
	IR_COMPARE_NEQ_CONST, // compare primary not equal to constant
	IR_COMPARE_LT_CONST, // compare primary less than constant
	IR_COMPARE_GT_CONST, // compare primary greater than constant
	IR_COMPARE_LTEQ_CONST, // compare primary less than or equal to constant
	IR_COMPARE_GTEQ_CONST, // compare primary greater than or equal to constant
	IR_SHL_CONST, // shift primary left by constant
	IR_SHR_CONST, // shift primary right by constant
	IR_ADD_CONST, // add primary by constant
	IR_SUB_CONST, // subtract primary by constant
	IR_MUL_CONST, // multiply primary by constant
	IR_DIV_CONST, // divide primary by constant
	IR_MOD_CONST, // modulo primary by constant

	IR_JMP, // jump
	IR_BZ, // branch if zero
	IR_BNZ, // branch if non-zero
	
	IR_STRLEN, // get strlen of primary register, storing into primary register

	IR_SET_ONE_IF_NOT_ZERO, // set primary to 1 if primary is not zero
	IR_DEFINE_FUNCTION, // Define function here. arg0 is symbol, arg1 is number of arguments

	IR_INVALID_OPCODE,
};

enum {
	TK_NUM = 128, TK_STR, TK_CHAR, TK_DATA, TK_FUN, TK_ID,
	TK_IF, TK_ELSE, TK_WHILE, TK_DO, TK_ENUM, TK_RETURN, TK_SIZEOF, TK_TYPEDEF, TK_STRUCT,
	TK_ASSIGN, TK_ADDEQ, TK_SUBEQ, TK_MULEQ, TK_DIVEQ, TK_MODEQ, TK_COND, TK_LOR, TK_LAND, TK_OR, TK_XOR, TK_AND,
	TK_EQ, TK_NE, TK_LT, TK_GT, TK_LTEQ, TK_GTEQ, TK_SHL, TK_SHR, TK_ADD, TK_SUB, TK_MUL, TK_DIV, TK_MOD,
	TK_STRUCTPTRACCESS, TK_STRUCTACCESS,
	TK_INC, TK_DEC,
};

enum {
	FMT_CE = 1,
	FMT_BOS,
};

#ifdef PLATFORM_DESKTOP
#include "ir_data.h"
#endif

#define sizeof_symbol(name) (strlen(name)+sizeof(symbol))
typedef struct _symbol {
	uint8_t symtype, valtype;
	unsigned int value;
	uint8_t valueupper;
	unsigned int resolved_value;
	struct _symbol *prev, *next;
	uint16_t hash;
	char name[1];
} symbol;

bool tkisconst = true;
uint8_t tk, tkvaltype, outformat = FMT_CE, primarytype = T_VOID;
symbol *tksym = NULL;
char *tkname;
unsigned int tknamelen;
char *srcdata;
#ifdef PLATFORM_DESKTOP
#define IR_OUTPUT_SIZE 1024000
#define OUTPUT_BUFFER_SIZE 4096000
#define DATA_RESOLVE_STACK_SIZE 4096
#define RESOLVE_STACK_SIZE 65536
#define SYM_STACK_SAVE_SIZE 256
#define _int int32_t
#define _ptr long long
#else
#define IR_OUTPUT_SIZE 32768
#define OUTPUT_BUFFER_SIZE 0xFFE8
#define DATA_RESOLVE_STACK_SIZE 1024
#define RESOLVE_STACK_SIZE 4096
#define SYM_STACK_SAVE_SIZE 16
#define _int int
#define _ptr unsigned int
#endif
char *tkvalstr;
int tkval, tkvallen, primary;
int8_t tkvalupper;
_ptr *resolvestack, *resolvestackstart, *expr, *exprstart, *data_start, *data_resolve_stack;
_int data_resolve_sp = 0;
uint8_t *out, *outstart;
unsigned int errsp_offset, exitroutineptr, lno, srcoffset, srclen, globaladdr = TI_pixelShadow, PROGRAM_ORIGIN = TI_userMem;
symbol *symtable = NULL;
symbol **localsymstack = NULL;

void error(const char *s) {
#ifdef PLATFORM_DESKTOP
	printf("%s\n", s);
	if (lno > 0) {
		printf("Error on line %u\n", lno);
	}
	exit(1);
#else
#ifdef BOS_BUILD
	gui_PrintLine(s);
	if (lno > 0) {
		gui_Print("Error on line ");
		gui_PrintUInt(lno);
	}
	sys_WaitKeyCycle();
#else
	os_HomeUp();
	os_PutStrFull(s);
	if (lno > 0) {
		printf("Error on line %u\n", lno);
	}
	while (!os_GetCSC());
#endif
#endif
	exit(1);
}

int getchar() {
	if (srcoffset >= srclen) {
		return 0;
	}
	return srcdata[srcoffset++];
}
#define peekchar() srcdata[srcoffset]

/*
int seek(int offset, int whence) {
	switch (whence) {
		case 2:
			if (offset >= srclen)
				return -1;
			srcoffset = srclen - srcoffset;
			break;
		case 1:
			if (srcoffset + offset >= srclen)
				return -1;
			srcoffset += offset;
			break;
		case 0:
		default:
			if (offset >= srclen)
				return -1;
			srcoffset = offset;
			break;
	}
	return srcoffset;
}
*/

bool check_token(const char *a) {
	const char *b = &srcdata[srcoffset-1];
	while (*b++ == *a++) {
		if (!*a)
			return true;
	}
	return false;
}

bool consume_token(const char *a) {
	if (check_token(a)) {
		char c = srcdata[srcoffset+strlen(a)-1];
		if (c == ' ' || c == '\t' || c == '\n') {
			srcoffset += strlen(a);
			return true;
		}
	}
	return false;
}

bool consume_token_line(const char *a) {
	if (consume_token(a)) {
		while (getchar() != '\n') if (peekchar() == -1) break;
		lno++;
		return true;
	}
	return false;
}

uint16_t compute_hash(const char *data, unsigned int len);
#ifdef PLATFORM_DESKTOP
uint16_t compute_hash(const char *data, unsigned int len) {
	uint16_t hash = 0;
	for (unsigned int i = 0; i < len; i++) {
		hash = hash*17 + data[i] - 1;
	}
	return hash;
}
#endif


symbol *add_sym(const char *name, unsigned int namelen, uint8_t symtype, uint8_t valtype, int value) {
	symbol *sym;
	if (namelen == 0) {
		namelen = strlen(name);
	}
	sym = _malloc(sizeof(symbol)+namelen);
	if (sym == NULL) {
		error("Out of memory");
	}
	// link new symbol into linked list of symbols
	if (symtable != NULL) {
		symtable->next = sym;
	}
	sym->prev = symtable;
	symtable = sym;

	// copy symbol name
	memcpy(&sym->name, name, namelen);
	sym->name[namelen] = 0;
	sym->symtype = symtype;
	sym->valtype = valtype;
	sym->value = value;
	sym->hash = compute_hash(name, namelen);
	sym->next = NULL;
#ifdef DEBUG
	printf("Added symbol \"%s\" symtype %X valtype %X value %X hash %X\n", (char*)&sym->name, symtype, valtype, value, sym->hash);
#endif
	symtable = sym;
	return sym;
}

symbol *make_tmp_sym(unsigned int val, uint8_t valtype) {
	symbol *sym;
	if ((sym = malloc(sizeof(symbol))) == NULL) {
		error("Out of memory");
	}
	memset(sym, 0, sizeof(symbol));
	sym->value = val;
	sym->valtype = valtype;
	return sym;
}

symbol *make_tmp_sym_str(unsigned int offset, char *str, unsigned int len) {
	symbol *sym = make_tmp_sym(offset, T_STR);
#ifdef DEBUG
	printf("Resolving data later at offset 0x%llX pointer 0x%llX length 0x%X\n", expr-exprstart, (_ptr)ptr, len);
#endif
	data_resolve_stack[data_resolve_sp++] = (_ptr)sym;
	data_resolve_stack[data_resolve_sp++] = (_ptr)str;
	data_resolve_stack[data_resolve_sp++] = len;
	return sym;
}



void save_sym_stack(void) {
	// push to the symbol save stack
	*localsymstack++ = symtable;
}

// free sym stack from current down to saved point, pop symbol save stack
void free_local_symbols(void) {
	symbol *sym = symtable;
	symbol *tmp = *--localsymstack;
	do {
		// break if we've reached the saved point in the symbol stack
		if (sym == tmp) {
			break;
		}
#ifdef DEBUG
		printf("Freeing symbol \"%s\"\n", sym->next->name);
#endif
		if (sym->next != NULL) {
			free(sym->next);
		}
		sym->next = NULL;
	} while ((sym = sym->prev) != NULL);
	symtable = tmp;
}

// search for a symbol in the symbol table, returning NULL if not found.
symbol *find_sym(const char *name, unsigned int namelen) {
	uint16_t hash = compute_hash(name, (namelen>0)?namelen:strlen(name));
	symbol *sym = symtable;
#ifdef DEBUG
	if (namelen > 0) {
		char *symname = malloc(namelen+1);
		memcpy(symname, name, namelen);
		symname[namelen] = 0;
		printf("Searching for symbol \"%s\" with hash %X\n", symname, hash);
	} else {
		printf("Searching for symbol \"%s\" with hash %X\n", name, hash);
	}
#else
	if (namelen == 0) {
		namelen = strlen(name);
	}
#endif
	if (sym != NULL) {
		do {
			// printf("Checking symbol with hash %X\n", sym->hash);
			if (hash == sym->hash) {
				if (!strncmp(name, &sym->name, namelen)) {
					return sym;
				}
			}
		} while ((sym = sym->prev));
	}
	return sym;
}

uint8_t readHexByte(void) {
	char upper = getchar();
	char lower = getchar();
	uint8_t val;
	if ((unsigned)(upper&~0x20)-'A'<26) {
		val = (upper+10-'A') << 4;
	} else if ((unsigned)upper-'0'<10) {
		val = (upper-'0') << 4;
	} else {
		error("Invalid hex nibble");
	}
	if ((unsigned)(lower&~0x20)-'A'<26) {
		val |= lower+10-'A';
	} else if ((unsigned)lower-'0'<10) {
		val |= lower-'0';
	} else {
		error("Invalid hex nibble");
	}
	return val;
}

_int search_data_resolve_stack(char *ptr, unsigned int len) {
	_int sp = data_resolve_sp;
	while (sp > 0) {
		unsigned int l = data_resolve_stack[--sp];
		char *p = data_resolve_stack[--sp];
		symbol *sym = data_resolve_stack[--sp];
		if (len == l && !memcmp(p, ptr, len)) {
			return sp;
		}
	}
	return 0;
}

void tk_next(void) {
	char tk2;
	tk = getchar();
	while (tk == ' ' || tk == '\t' || tk == '\n') {
		if (tk == '\n') {
			lno++;
		}
		tk = getchar();
	}
	if (tk && !(tk == ';' || tk == ',' || tk == '~' || tk == ';' || tk == '{' || tk == '}' || tk == '(' || tk == ')' || tk == ']' || tk == ',' || tk == ':')) {
		tk2 = peekchar();
		tksym = NULL;
		if (tk == '/' && tk2 == '/') {
			while (tk && tk != '\n') {
				tk = getchar();
				if (tk == '\\') {
					if (getchar() == '\n') {
						lno++;
					}
				}
			}
			if (tk == '\n') {
				lno++;
			}
			if (tk) {
				tk_next();
			}
		} else if (tk == '/' && tk2 == '*') {
			while (tk) {
				tk = getchar();
				if (tk == '*' && peekchar() == '/') {
					getchar();
					break;
				}
				else if (tk == '\n') {
					lno++;
				}
			}
			if (tk) {
				tk_next();
			}
		} else if (tk == '#') {
			if (consume_token_line("define")) {
				return;
			} else if (consume_token_line("include")) {
				return;
			} else {
				error("Invalid/unimplemented preprocessor token");
			}
		} else if (consume_token("if")) {
			tk = TK_IF;
		} else if (consume_token("else")) {
			tk = TK_ELSE;
		} else if (consume_token("while")) {
			tk = TK_WHILE;
		} else if (consume_token("do")) {
			tk = TK_DO;
		} else if (consume_token("sizeof")) {
			tk = TK_SIZEOF;
		} else if (consume_token("return")) {
			tk = TK_RETURN;
		} else if (consume_token("enum")) {
			tk = TK_ENUM;
		} else if (tk == '.') {
			tk = TK_STRUCTACCESS;
		} else if (tk == '?') {
			tk = TK_COND;
		} else if (tk == '!') {
			if (tk2 == '=') {
				getchar();
				tk = TK_NE;
			}
		} else if (tk == '=') {
			if (tk2 == '=') {
				getchar();
				tk = TK_EQ;
			} else {
				tk = TK_ASSIGN;
			}
		} else if (tk == '<') {
			if (tk2 == tk) {
				getchar();
				tk = TK_SHL;
			} else if (tk2 == '=') {
				getchar();
				tk = TK_LTEQ;
			} else {
				tk = TK_LT;
			}
		} else if (tk == '>') {
			if (tk2 == tk) {
				getchar();
				tk = TK_SHR;
			} else if (tk2 == '=') {
				getchar();
				tk = TK_GTEQ;
			} else {
				tk = TK_GT;
			}
		} else if (tk == '+') {
			if (tk2 == tk) {
				getchar();
				tk = TK_INC;
			} else if (tk2 == '=') {
				getchar();
				tk = TK_ADDEQ;
			} else {
				tk = TK_ADD;
			}
		} else if (tk == '-') {
			if (tk2 == tk) {
				getchar();
				tk = TK_DEC;
			} else if (tk2 == '=') {
				getchar();
				tk = TK_SUBEQ;
			} else if (tk2 == '>') {
				getchar();
				tk = TK_STRUCTPTRACCESS;
			} else {
				tk = TK_SUB;
			}
		} else if (tk == '*') {
			if (tk2 == '=') {
				getchar();
				tk = TK_MULEQ;
			} else {
				tk = TK_MUL;
			}
		} else if (tk == '/') {
			if (tk2 == '=') {
				getchar();
				tk = TK_DIVEQ;
			} else {
				tk = TK_DIV;
			}
		} else if (tk == '/') {
			if (tk2 == '=') {
				getchar();
				tk = TK_MODEQ;
			} else {
				tk = TK_MOD;
			}
		} else if (tk == '|') {
			if (tk2 == tk) {
				getchar();
				tk = TK_LOR;
			} else {
				tk = TK_OR;
			}
		} else if (tk == '&') {
			if (tk2 == tk) {
				getchar();
				tk = TK_LAND;
			} else {
				tk = TK_AND;
			}
		} else if (tk == '^') {
			tk = TK_XOR;
		} else if ((unsigned)(tk&~0x20)-'A' < 26 || tk == '_') {
			unsigned int i = srcoffset-1;
			do {
				tk = getchar();
			} while ((unsigned)(tk&~0x20)-'A' < 26 || (unsigned)tk-'0' < 10 || tk == '_');
			// printf("Got ID token at offset %u\n", i);
			srcoffset--;
			tkname = &srcdata[i];
			tknamelen = srcoffset - i;
			tksym = find_sym(tkname, tknamelen);
			if (tksym != NULL) {
				tkvaltype = tksym->valtype;
				tkval = tksym->value;
			}
			tk = TK_ID;
		} else if (tk == '0' && (tk2&~0x20) == 'X') {
			int num = 0;
			srcoffset++;
			tk = getchar();
			while ((unsigned)tk-'0' < 10 || (unsigned)(tk&~0x20)-'A' < 6) {
				num = num * 16 + ((tk>='A')?((tk&~0x20)+10-'A'):(tk-'0'));
				tk = getchar();
			}
			tkval = num;
			tkvaltype = T_NUM;
			tk = TK_NUM;
			tkisconst = true;
			srcoffset--;
		} else if ((unsigned)tk-'0' < 10) {
			int num = 0;
			do {
				num = num * 10 + tk - '0';
			} while ((unsigned)(tk = getchar())-'0' < 10);
			tkval = num;
			tkvaltype = T_NUM;
			tk = TK_NUM;
			tkisconst = true;
			srcoffset--;
		} else if (tk == '\'') {
			if (tk2 == '\\') {
				getchar();
				if (peekchar() == 'x') {
					getchar();
					tkval = readHexByte();
				} else if ((peekchar()&~0x20) == 'N') {
					tkval = '\n';
				} else if ((peekchar()&~0x20) == 'T') {
					tkval = '\t';
				} else if ((peekchar()&~0x20) == 'R') {
					tkval = '\r';
				} else if (peekchar() == '0') {
					tkval = '\0';
				} else {
					tkval = getchar();
				}
			} else {
				tkval = getchar();
			}
			if (getchar() != tk) {
				error("Unterminated char literal");
			}
			tkvaltype = T_CHAR;
			tk = TK_CHAR;
			tkisconst = true;
			srcoffset--;
		} else if (tk == '"') {
			unsigned int i = srcoffset;
			char *ptr;
			do {
				tk2 = getchar();
				if (tk2 == '\\') {
					if ((getchar()&~0x20) == 'X') {
						getchar();
						getchar();
					}
					tk2 = getchar();
				}
			} while (tk2 != '"');
	//		printf("Got string with length %u\n", srcoffset-i);
			if ((ptr = malloc(srcoffset-i)) == NULL) {
				error("Out of memory");
			}
			tk = TK_STR;
			tkisconst = true;
			tkvalstr = ptr;
			tkvallen = srcoffset - i;
			tkval = search_data_resolve_stack(tkvalstr, tkvallen);
			tkvaltype = T_STR;
			srcoffset = i;
			while (1) {
				tk2 = getchar();
				if (tk2 == '\\') {
					if ((peekchar()&~0x20) == 'X') {
						getchar();
						*ptr++ = readHexByte();
					} else if ((peekchar()&~0x20) == 'N') {
						*ptr++ = '\n';
					} else if ((peekchar()&~0x20) == 'T') {
						*ptr++ = '\t';
					} else if ((peekchar()&~0x20) == 'R') {
						*ptr++ = '\r';
					} else if (peekchar() == '0') {
						*ptr++ = '\0';
					} else {
						if (peekchar() == '\n') {
							lno++;
						} else {
							*ptr++ = getchar();
						}
					}
				} else if (tk2 == '"') {
					*ptr = '\0';
					break;
				} else {
					*ptr++ = tk2;
				}
			}
		} else {
			error("Invalid token");
		}
	}
}

void expression(uint8_t level) {
	bool primaryisconst = true;
	_ptr *d, *tmpexpr = expr;
	int tmp;
	symbol *sym;

//	printf("tk = %X tkval = %X\n", tk, tkval);
	if (!tk) {
		error("Unexpected EOF");
	} else if (tk == TK_NUM || tk == TK_STR || tk == TK_DATA || tk == TK_CHAR) {
		if (tk == TK_STR || tk == TK_DATA) {
			*++expr = IR_IMM_PROG_OFFSET;
			*++expr = make_tmp_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
			tkisconst = false;
		} else if ((tkvaltype & T_MASK) == T_LONG) {
			if (!tkisconst) {
				*++expr = IR_IMM_32;
				*++expr = tkval;
				*++expr = tkval >> 24;
			}
		} else {
			if (!tkisconst) {
				*++expr = IR_IMM;
				*++expr = tkval;
			}
		}
		tk_next();
	} else if (tk == TK_SIZEOF) {
		tk_next();
		if (tk == '(') {
			_ptr *savedexpr = expr;
			tk_next();
			expression(TK_ASSIGN);
			expr = savedexpr;
			if (tk != ')') {
				error("sizeof: Missing closing parenthesis");
			}
			if (tkvaltype >= T_PTR) {
				*++expr = IR_IMM;
				*++expr = 3;
			} else if (tkvaltype == T_STR) {
				*++expr = IR_IMM_PROG_OFFSET;
				*++expr = make_tmp_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
				*++expr = IR_STRLEN;
				tkisconst = false;
			} else if (tkvaltype >= T_CHAR && tkvaltype <= T_LONG) {
				*++expr = IR_IMM;
				*++expr = tkvaltype;
			} else {
				error("sizeof: Invalid/unsupported or non-constant size value/type");
			}
		// } else if (tk == TK_ID) {
			// sym = (symbol*)tkval;
			// if (sym->valtype == TK_CHAR) {
				// EMIT_LD_HL_IMM(1);
			// } else if (sym->valtype == TK_NUM || sym->valtype >= T_PTR) {
				// EMIT_LD_HL_IMM(3);
			// } else if (sym->valtype == TK_STR) {
				// EMIT_LD_HL_IMM(sym->value);
				// EMIT_INST_8(PUSH_HL);
				// EMIT_INST_8_24(CALL_IMM, _STRLEN);
				// EMIT_INST_8(POP_BC);
			// }
		// } else if (tk == TK_NUM || tkvaltype >= T_PTR) {
			// EMIT_LD_HL_IMM(3);
		// } else if (tk == TK_STR) {
			// EMIT_LD_HL_IMM(sym->value);
			// EMIT_INST_8(PUSH_HL);
			// EMIT_INST_8_24(CALL_IMM, _STRLEN);
			// EMIT_INST_8(POP_BC);
		// } else if (tk == TK_DATA) {
			// error("Cannot get sizeof arbitrary length data");
		} else {
			error("sizeof: Missing open parenthesis following sizeof token");
		}
	} else if (tk == TK_ID) {
		sym = tksym;
//		printf("symbol \"%s\"\n", sym->name);
		if (sym == NULL) {
			error("Undeclared Identifier");
		}
		tk_next();
//		printf("tk = %X\n", tk);
		if (tk == '(') {
			// function call
			tmp = 0;
			if ((sym->symtype & SYM_MASK) != SYM_FUNCTION) {
				error("can't call non-function value as function");
			}
			tk_next();
			while (tk != ')') {
				expression(TK_ASSIGN);
				if (tkvaltype == T_LONG) {
					*++expr = IR_PUSH_32;
					tmp += 6;
				} else {
					*++expr = IR_PUSH;
					tmp += 3;
				}
				if (tk == ',') { // maybe unnecessary check?
					tk_next();
				}
			}
			tk_next();
			*++expr = IR_CALL;
			*++expr = sym;
			if (sym->valtype != T_VOID) {
				*++expr = IR_EX_SEC_PRI;
			}
			*++expr = IR_ADJ;
			*++expr = tmp;
			if (sym->valtype != T_VOID) {
				*++expr = IR_EX_SEC_PRI;
			}
			tkvaltype = sym->valtype;
			tkisconst = false;
		} else if (sym->symtype & SYM_LOCAL) {
			// local value
			*++expr = IR_LEA_LOCAL;
			*++expr = sym->value;
			if (sym->valtype <= T_LONG) {
				*++expr = sym->valtype + IR_LOAD_CHAR - T_CHAR;
			} else {
				*++expr = IR_LOAD_INT;
			}
			tkisconst = false;
		} else if (sym->symtype & SYM_GLOBAL) {
			// global value
			*++expr = IR_LEA_GLOBAL;
			*++expr = sym->value;
			if (sym->valtype < T_PTR) {
				*++expr = 3 + IR_LOAD_CHAR - T_CHAR;
			} else {
				*++expr = sym->valtype + IR_LOAD_CHAR - T_CHAR;
			}
			tkisconst = false;
		} else {
			error("Invalid variable type");
		}
	} else if (tk == '(') {
		tk_next();
		if (tk == TK_TYPEDEF) {
			tmp = sym->value;
			tk_next();
			while (tk == TK_MUL) {
				tmp += T_PTR;
				tk_next();
			}
			if (tmp >= 256) {
				error("Invalid type cast: octuple (8x) pointers and beyond are not supported");
			}
			if (tk != ')') {
				error("Invalid type cast: missing closing parenthesis");
			}
			expression(TK_INC);
			tkvaltype = tmp;
		} else {
			expression(TK_ASSIGN);
			if (tk != ')') {
				error("Missing closing parenthesis");
			}
			tk_next();
		}
	} else if (tk == TK_MUL) {
		tk_next();
		expression(TK_INC);
		if (tkvaltype < T_PTR) {
			error("Invalid dereference");
		}
		tkvaltype -= T_PTR;
		// Make sure IR_LOAD_CHAR, IR_LOAD_WORD, IR_LOAD_INT, IR_LOAD_LONG are in sequence.
		// as well as T_CHAR, T_WORD, T_INT, and T_LONG.
		if (tkvaltype >= T_CHAR && tkvaltype <= T_LONG) {
			*++expr = tkvaltype + IR_LOAD_CHAR - T_CHAR;
		} else if (tkvaltype == T_BOOL) {
			*++expr = IR_LOAD_CHAR;
		} else {
			error("Invalid/unsupported type for dereference");
		}
	} else if (tk == TK_AND) {
		tk_next();
		expression(TK_INC);
		if (*expr >= IR_LOAD_CHAR && *expr <= IR_LOAD_LONG) {
			--expr;
		} else {
			error("Invalid/unsupported type for address-of operator");
		}
		tkvaltype += T_PTR;
	} else if (tk == '!') {
		tk_next();
		expression(TK_INC);
		if (tkisconst) {
			tkval = (tkval == 0 ? 1 : 0);
			tkvaltype = T_CHAR;
		} else {
			*++expr = IR_COMPARE_Z;
			tkisconst = false;
			tkvaltype = T_CHAR;
		}
	} else if (tk == '~') {
		tk_next();
		expression(TK_INC);
		if (tkisconst) {
			tkval = ~tkval;
		} else {
			*++expr = IR_NOT;
			tkisconst = false;
		}
	} else if (tk == TK_ADD) {
		tk_next();
		expression(TK_INC);
	} else if (tk == TK_SUB) {
		tk_next();
		expression(TK_INC);
		if (tkisconst) {
			tkval = -tkval;
		} else {
			*++expr = IR_NEG;
		}
	} else if (tk == TK_INC || tk == TK_DEC) {
		tmp = tk;
		tk_next();
		expression(TK_INC);
		if (*expr >= IR_LOAD_CHAR && *expr <= IR_LOAD_LONG) {
			*++expr = (tmp == TK_INC) ? IR_INC : IR_DEC;
			*++expr = (tksym->symtype & SYM_GLOBAL) ? IR_STORE_GLOBAL : IR_STORE_LOCAL;
			*++expr = tksym->value;
			*++expr = tkvaltype & T_MASK;
		} else {
			error("Invalid value increment/decrement");
		}
	} else {
		error("Invalid expression");
	}

	primary = tkval;
	primarytype = tkvaltype;
	primaryisconst = tkisconst;

	while (tk >= level) { // precedence climbing
		tmp = tkvaltype;
		if (tk == TK_ASSIGN) {
			if (sym == NULL) {
				error("Invalid variable assignment");
			}
			expr = tmpexpr;
			tk_next();
			expression(TK_ASSIGN);
			if (tkisconst) {
				if (tkvaltype == T_LONG) {
					*++expr = IR_IMM_32;
					*++expr = tkval;
					*++expr = tkvalupper;
				} else if (tkvaltype == T_STR) {
					*++expr = IR_IMM_PROG_OFFSET;
					*++expr = make_tmp_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
				} else {
					*++expr = IR_IMM;
					*++expr = tkval;
				}
			}
			*++expr = (sym->symtype & SYM_GLOBAL) ? IR_STORE_GLOBAL : IR_STORE_LOCAL;
			*++expr = sym->value;
			*++expr = tkvaltype;
		} else if (tk == TK_COND) {
			if (tkisconst) {
				bool tkistrue = tkval;
				tk_next();
				d = expr;
				expression(TK_ASSIGN); // consume true case
				if (!tkistrue) {
					expr = d; // ignore true case if conditional is always false
				}
				if (tk != ':') {
					error("Missing colon in condition operator");
				}
				tk_next();
				d = expr;
				expression(TK_COND); // consume false case
				if (!tkistrue) {
					expr = d; // ignore false case if conditional is always true
				}
			} else {
				tk_next();
				*++expr = IR_BZ;
				d = ++expr;
				expression(TK_ASSIGN);
				if (tk != ':') {
					error("Missing colon in condition operator");
				}
				tk_next();
				*d = make_tmp_sym(expr + 3 - exprstart, T_PTR);
				*++expr = IR_JMP;
				d = ++expr;
				expression(TK_COND);
				*d = make_tmp_sym(expr + 1 - exprstart, T_PTR);
			}
		} else if (tk == TK_LOR) {
			tk_next();
			d = expr;
			expression(TK_LOR+1);
			if (tkisconst && primaryisconst) {
				primary = primary || tkval;
			} else if (tkisconst) {
				if (tkval == 0) {
					*++expr = IR_SET_ONE_IF_NOT_ZERO;
				} else {
					expr = d;
				}
			} else if (primaryisconst) {
				if (primary == 0) {
					*++expr = IR_SET_ONE_IF_NOT_ZERO;
				} else {
					expr = d;
				}
			} else {
				*++expr = IR_LOR;
				primaryisconst = false;
			}
		} else if (tk == TK_LAND) {
			tk_next();
			d = expr;
			expression(TK_LAND+1);
			if (tkisconst && primaryisconst) {
				primary = primary && tkval;
			} else if (tkisconst) {
				if (tkval != 0) {
					*++expr = IR_SET_ONE_IF_NOT_ZERO;
					primaryisconst = false;
				} else {
					expr = d;
				}
			} else if (primaryisconst) {
				if (primary != 0) {
					*++expr = IR_SET_ONE_IF_NOT_ZERO;
					primaryisconst = false;
				} else {
					expr = d;
				}
			} else {
				*++expr = IR_LAND;
				primaryisconst = false;
			}
		} else if (tk >= TK_OR && tk <= TK_MOD) {
			tmp = tk;
			tk_next();
			if (!primaryisconst) {
				*++expr = IR_PUSH;
			}
			expression(tmp+1);
			if (primaryisconst) {
				if (tkisconst) {
					if (tmp == TK_OR) {
						primary |= tkval;
					} else if (tmp == TK_AND) {
						primary &= tkval;
					} else if (tmp == TK_EQ) {
						primary = primary == tkval;
					} else if (tmp == TK_NE) {
						primary = primary != tkval;
					} else if (tmp == TK_LT) {
						primary = primary < tkval;
					} else if (tmp == TK_GT) {
						primary = primary > tkval;
					} else if (tmp == TK_LTEQ) {
						primary = primary <= tkval;
					} else if (tmp == TK_GTEQ) {
						primary = primary >= tkval;
					} else if (tmp == TK_SHL) {
						primary = primary << tkval;
					} else if (tmp == TK_SHR) {
						primary = primary >> tkval;
					} else if (tmp == TK_ADD) {
						primary = primary + tkval;
					} else if (tmp == TK_SUB) {
						primary = primary - tkval;
					} else if (tmp == TK_MUL) {
						primary = primary * tkval;
					} else if (tmp == TK_DIV) {
						if (tkval == 0) {
							error("Divide by zero");
						} else {
							primary = primary / tkval;
						}
					} else if (tmp == TK_MOD) {
						if (tkval == 0) {
							error("Modulo by zero");
						} else {
							primary = primary % tkval;
						}
					}
				} else {
					*++expr = tmp + IR_OR_CONST - TK_OR;
					*++expr = primary;
					primaryisconst = false;
				}
			} else {
				*++expr = IR_POP_SEC;
				*++expr = tmp + IR_OR - TK_OR;
			}
		} else if (tk == TK_INC || tk == TK_DEC) {
			if (*expr >= IR_LOAD_CHAR && *expr <= IR_LOAD_LONG) {
				*++expr = (tk == TK_INC) ? IR_INC : IR_DEC;
				*++expr = (tksym->symtype & SYM_GLOBAL) ? IR_STORE_GLOBAL : IR_STORE_LOCAL;
				*++expr = tkvaltype & T_MASK;
				*++expr = tksym->value;
			} else {
				error("Invalid value for post increment/decrement");
			}
			tk_next();
		} else if (tk == '[') {
			tk_next();
			if (!primaryisconst) {
				*++expr = IR_PUSH;
			}
			d = expr;
			expression(TK_ASSIGN);
			if (tk != ']') {
				error("Missing closing bracket");
			}
			tk_next();
			if ((tkvaltype & T_MASK) <= T_LONG && tkvaltype > T_PTR) {
				if (tkisconst && primaryisconst) { // constant[constant]
					expr = d; // rewind emitted data for constant expression
					primary += tkval * (tkvaltype & T_MASK);
					*++expr = IR_IMM;
					*++expr = primary;
				} else if (primaryisconst) { // constant[var]
					*++expr = IR_MUL_CONST;
					*++expr = tkvaltype & T_MASK;
					*++expr = IR_ADD_CONST;
					*++expr = primary; // primary is not destroyed if the expression is not constant
				} else if (tkisconst) { // var[constant]
					*++expr = IR_ADD_CONST;
					*++expr = tkval * (tkvaltype & T_MASK);
				} else if ((tkvaltype & T_MASK) > 1) {
					*++expr = IR_MUL_CONST;
					*++expr = tkvaltype & T_MASK;
					*++expr = IR_ADD;
				} else {
					*++expr = IR_POP_SEC;
					*++expr = IR_ADD;
				}
				*++expr = IR_LOAD_CHAR + primarytype - T_CHAR;
			} else if (tkvaltype < T_PTR) {
				error("Pointer type expected");
			} else if (tkvaltype == T_PTR) {
				error("Cannot index pointer to void");
			}
		} else {
			error("Invalid syntax");
		}
	}
	tkval = primary;
	tkvaltype = primarytype;
	tkisconst = primaryisconst;
}

void statement(void) {
	_ptr *a, *b;
	if (tk == TK_IF) {
		tk_next();
		if (tk != '(') {
			error("Missing open parenthesis");
		}
		expression(TK_ASSIGN);
		if (tk != ')') {
			error("Missing closing parenthesis");
		}
		*++expr = IR_BZ;
		b = ++expr;
		statement();
		if (tk == TK_ELSE) {
			*b = make_tmp_sym(expr + 3 - exprstart, T_PTR);
			*++expr = IR_JMP;
			b = ++expr;
			tk_next();
			statement();
		}
		*b = make_tmp_sym(expr + 1 - exprstart, T_PTR);
	} else if (tk == TK_WHILE) {
		tk_next();
		a = expr + 1;
		if (tk != '(') {
			error("Missing open parenthesis");
		}
		tk_next();
		expression(TK_ASSIGN);
		if (tk != '(') {
			error("Missing closing parenthesis");
		}
		tk_next();
		*++expr = IR_BZ;
		b = ++expr;
		statement();
		*++expr = IR_JMP;
		*++expr = make_tmp_sym(a - exprstart, T_PTR);
		*b = make_tmp_sym(expr + 1 - exprstart, T_PTR);
	} else if (tk == TK_DO) {
		tk_next();
		a = expr + 1;
		statement();
		if (tk != TK_WHILE) {
			error("Missing while in do ... while loop.");
		}
		tk_next();
		if (tk != '(') {
			error("Missing open parenthesis");
		}
		tk_next();
		*++expr = IR_BZ;
		b = ++expr;
		expression(TK_ASSIGN);
		if (tk != ')') {
			error("Missing closing parenthesis");
		}
		tk_next();
		if (tk != ';') {
			error("Missing semicolon");
		}
		tk_next();
		*b = make_tmp_sym(a - exprstart, T_PTR);
	} else if (tk == TK_RETURN) {
		tk_next();
		if (tk != ';') {
			expression(TK_ASSIGN);
		}
		*++expr = IR_LEAVE;
		if (tk != ';') {
			error("Missing semicolon");
		}
		tk_next();
	} else if (tk == '{') {
		tk_next();
		while (tk != '}') {
			statement();
		}
		tk_next();
	} else if (tk == ';') {
		tk_next();
	} else {
		expression(TK_ASSIGN);
		if (tk != ';') {
			error("Missing semicolon");
		}
		tk_next();
	}
}

void precompile(void) {
	if ((symtable = malloc(sizeof(symbol))) == NULL) {
		error("Failed to malloc space for initial symbol");
	}
	if ((data_resolve_stack = malloc(sizeof(int) * DATA_RESOLVE_STACK_SIZE)) == NULL) {
		error("Failed to malloc space for data resolution stack");
	}
	if ((localsymstack = malloc(sizeof(symbol*) * SYM_STACK_SAVE_SIZE)) == NULL) {
		error("Failed to malloc space for symbol stack local save stack");
	}
	if ((resolvestack = resolvestackstart = malloc(RESOLVE_STACK_SIZE*sizeof(_ptr))) == NULL) {
		error("Failed to malloc space for address resolution stack\n");
	}
	memset(symtable, 0, sizeof(symbol));
	add_sym("void", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 0);
	add_sym("unsigned", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 3);
	add_sym("char", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 1);
	add_sym("short", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 2);
	add_sym("int", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 3);
	add_sym("long", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 4);
	add_sym("uint8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 1);
	add_sym("uint16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 2);
	add_sym("uint24_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 3);
	add_sym("uint32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 4);
	add_sym("int8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 1);
	add_sym("int16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 2);
	add_sym("int24_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 3);
	add_sym("int32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, 4);
}

void resolve_later(unsigned int offset, symbol *val) {
	*resolvestack++ = val;
	*resolvestack++ = offset;
}

void postcompile(void) {
	data_start = ++expr;
	while (data_resolve_sp > 0) {
		unsigned int len = (unsigned int)data_resolve_stack[--data_resolve_sp];
		char *ptr = (char*)data_resolve_stack[--data_resolve_sp];
		symbol *sym = data_resolve_stack[--data_resolve_sp];
		// printf("0x%llX 0x%llX\n", expr-exprstart, data_start-exprstart);
		sym->value = expr - exprstart;
		for (unsigned int i = 0; i < len; i++) {
			*expr++ = ptr[i];
		}
	}
}

void compile(void) {
	symbol *sym;
	int argdepth, stackdepth, nargs;
	uint8_t bt, ty;
	int i;
	lno = 1;
	tk_next();
	while (tk) {
		if (tk == TK_ENUM) {
			tk_next();
			if (tk != '{') {
				tk_next();
			}
			if (tk == '{') {
				tk_next();
				i = 0;
				while (tk != '}') {
					if (tk != TK_ID) {
						error("Invalid enum identifier");
					}
					tk_next();
					if (tk == TK_ASSIGN) {
						tk_next();
						if (tk != TK_NUM) {
							error("Invalid enum initializer");
						}
						i = tkval;
						tk_next();
					}
					add_sym(tkname, tknamelen, SYM_CONSTANT, T_INT, i);
				}
				tk_next();
			}
			continue;
		} else if (tksym != NULL) {
			if (tksym->valtype == T_TYPEDEF) {
				bt = tksym->value;
			} else {
				bt = T_VOID;
			}
			tk_next();
		} else {
			error("Invalid identifier at start of line");
		}
		while (tk != ';' && tk != '}') {
			ty = bt;
			while (tk == TK_MUL) {
				tk_next();
				ty += T_PTR;
			}
			if (tk != TK_ID) {
				error("Invalid global declaration");
			}
			if (tksym != NULL) {
				error("Duplicate global declaration");
			}
			sym = add_sym(tkname, tknamelen, 0, ty, 0);
			tk_next();
			// printf("tk = %X \"%c\"\n", tk, tk);
			if (tk == '(') { // function declaration
				save_sym_stack();
				sym->symtype = SYM_FUNCTION;
				sym->value = expr + 1 - exprstart;
#ifdef DEBUG
				printf("Function offset 0x%llX\n", expr + 1 - exprstart);
#endif
				*++expr = IR_DEFINE_FUNCTION;
				*++expr = sym;
				tk_next();
				stackdepth = nargs = 0;
				argdepth = 6;
				while (tk != ')') {
					ty = T_INT;
					if (tkvaltype == T_TYPEDEF) {
						ty = tkval;
						tk_next();
					}
					while (tk == TK_MUL) {
						tk_next();
						ty += T_PTR;
					}
					if (tk != TK_ID) {
						error("Invalid parameter declaration");
					}
					if (tksym != NULL && tksym->symtype & SYM_LOCAL) {
						error("Duplicate parameter declaration");
					}
					add_sym(tkname, tknamelen, SYM_LOCAL, ty, argdepth);

					if (ty & T_MASK == T_LONG) {
						argdepth += 6;
					} else {
						argdepth += 3;
					}
					nargs++;
					tk_next();
					if (tk == ',') {
						tk_next();
						if (tk == ')') {
							error("Missing argument declaration following comma");
						}
					}
				}
				*++expr = nargs;
				tk_next();
				if (tk != '{') {
					if (tk == TK_ASSIGN) {
						free_local_symbols();
						tk_next();
						expression(TK_ASSIGN);
						if (!tkisconst) {
							error("Function assignment value must be constant");
						}
						sym->value = tkval;
						sym->resolved_value = tkval;
						sym->symtype |= SYM_RESOLVED;
						// printf("Assigned %s = 0x%X\n", (char*)&sym->name, tkval);
						if (tk != ';') {
							error("Expected semicolon following function assignment value");
						}
						goto nexttoken;
					} else if (tk == ';') {
						free_local_symbols();
						goto nexttoken;
					} else {
						error("Missing open brace in function declaration");
					}
				}
				tk_next();
				// printf("Function start\n");
				while (tksym != NULL && tkvaltype == T_TYPEDEF) {
					bt = tkval;
					tk_next();
					while (tk != ';') {
						ty = bt;
						while (tk == TK_MUL) {
							tk_next();
							ty += T_PTR;
						}
						if (tk != TK_ID) {
							error("Invalid local declaration");
						}
						if (tksym != NULL && tksym->symtype & SYM_LOCAL) {
							error("Duplicate local declaration");
						}
						if (ty & T_MASK == T_LONG) {
							stackdepth -= 4;
						} else {
							stackdepth -= 3;
						}
						add_sym(tkname, tknamelen, SYM_LOCAL, ty, stackdepth);
						tk_next();
						if (tk == ',') {
							tk_next();
							if (tk == ')') {
								error("Missing local declaration following comma");
							}
						}
					}
					tk_next();
				}
				*++expr = IR_ENTER;
				*++expr = stackdepth;
				while (tk != '}') {
					// printf("Reading function statement\n");
					statement();
				}
				if (*expr != IR_EXIT && *expr != IR_LEAVE) {
					*++expr = IR_LEAVE;
				}
				free_local_symbols();
			} else {
				add_sym(tkname, tknamelen, SYM_GLOBAL, ty, globaladdr);
				if (ty & T_MASK > 0) {
					globaladdr += ty & T_MASK;
				} else {
					error("Invalid global declaration");
				}
			}
		}
	nexttoken:;
		tk_next();
	}
	if (*expr != IR_EXIT && *expr != IR_LEAVE) {
		*++expr = IR_EXIT;
	}
	expr++;
}

uint8_t convert_flag_to_char(uint8_t bt) {
	if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
		if (bt == T_BOOL_ZF) {
			EMIT_LD_A_IMM(out, 1);
			EMIT_JR_Z_IMM(out, L_SUB_A_A);
			EMIT_SUB_A_A(out);
		} else if (bt == T_BOOL_NZF) {
			EMIT_LD_A_IMM(out, 1);
			EMIT_JR_NZ_IMM(out, L_SUB_A_A);
			EMIT_SUB_A_A(out);
		} else if (bt == T_BOOL_CF) {
			EMIT_CCF(out);
			EMIT_SBC_A_A(out);
			EMIT_INC_A(out);
		} else {
			EMIT_SBC_A_A(out);
			EMIT_INC_A(out);
		}
		return T_CHAR;
	}
	return bt;
}

void exchage_primary_secondary(uint8_t bt) {
	if (bt == T_WORD) {
		EMIT_SIS_SUFFIX(out);
	}
	if (bt != T_CHAR) {
		EMIT_EX_DE_HL(out);
	}
	if (bt == T_LONG || bt == T_CHAR) {
		EMIT_LD_C_A(out);
		EMIT_LD_A_E(out);
		EMIT_LD_E_C(out);
	}
}

void exchage_for_boot_math(uint8_t bt) {
	if (bt == T_CHAR) {
		EMIT_LD_C_L(out);
		EMIT_LD_B_E(out);
	} else if (bt == T_WORD) {
		EMIT_LD_C_E(out);
		EMIT_LD_B_D(out);
	} else if (bt != T_LONG) {
		EMIT_PUSH_HL(out);
		EMIT_POP_BC(out);
		EMIT_EX_DE_HL(out);
	}
}

void postassemble(void) {
	_ptr *sp = resolvestack;
	symbol *sym = symtable;
	while (sym != NULL) {
		//if (!(sym->symtype & SYM_RESOLVED)) {
		//	printf("\"%s\" value %X\nCurrent offset %llX\n", (char*)&sym->name, sym->value, data_start - exprstart);
		//	printf("%llu\n", data_start - exprstart);
		//}
		// if (sym->symtype & SYM_RESOLVED) {
		//	printf("  resolved to: %X\n", sym->resolved_value);
		// } else {
		//	printf("  not yet resolved\n");
		// }
		if (sym->value >= (data_start - exprstart)) {
			if (!(sym->symtype & SYM_RESOLVED)) {
				sym->symtype |= SYM_RESOLVED;
				printf("Symbol %s value %X\n", (char*)&sym->name, sym->value);
				sym->resolved_value = PROGRAM_ORIGIN + (out - outstart) + sym->value - (data_start - exprstart);
			}
		}
		sym = sym->prev;
	}

	while (sp > resolvestackstart) {
		unsigned int offset = *--sp;
		sym = *--sp;
		if (sym == NULL) {
			memcpy(&outstart[offset], &exitroutineptr, 3);
		} else {
			if (sym->symtype & SYM_RESOLVED) {
#ifdef DEBUG
				printf("resolving symbol \"%s\" use at offset 0x%X with value 0x%X\n", (char*)&sym->name, offset, sym->resolved_value);
#endif
				memcpy(&outstart[offset], &sym->resolved_value, 3);
			} else if (sym->value >= (data_start - exprstart)) {
				unsigned int tmpval = PROGRAM_ORIGIN + (out - outstart) + sym->value - (data_start - exprstart);
				memcpy(&outstart[offset], &tmpval, 3);
			} else {
				printf("Symbol name: \"%s\"\n", (char*)&sym->name);
				printf("Symbol value: %u\n", sym->value);
				printf("Symbol type: 0x%X\n", sym->valtype);
				printf("Output offset: %u\n", offset);
				printf("data_start-exprstart = %llu\n", data_start - exprstart);
				error("Internal: Failed to resolve symbol in assembly step");
			}
		}
	}
	if (expr > data_start) {
		for (unsigned int i = 0; i < expr-data_start; i++) {
			*out++ = data_start[i];
		}
	}
}

void try_resolve_symbols(unsigned int offset) {
	symbol *sym = symtable;
	if (sym == NULL) {
		return;
	}
	do {
		//if (!(sym->symtype & SYM_RESOLVED)) {
		//	printf("\"%s\" value %X\nCurrent offset %X\n", (char*)&sym->name, sym->value, offset);
		//}
		// if (sym->symtype & SYM_RESOLVED) {
		//	printf("  resolved to: %X\n", sym->resolved_value);
		// } else {
		//	printf("  not yet resolved\n");
		// }
		if (!(sym->symtype & SYM_RESOLVED) && sym->value == offset) {
			sym->symtype |= SYM_RESOLVED;
			sym->resolved_value = PROGRAM_ORIGIN + out - outstart;
		}
	} while ((sym = sym->prev));

//	printf("\n");
}

void assemble(void) {
	bool hlisbytelike = false, deisbytelike = false, bcisbytelike = false;
	bool zf = false, cf = false, argispowerof2 = false;
	int op;
	_ptr arg, *expr = exprstart;
	uint8_t l, bt = T_INT, *leaveaddress = NULL, *last_compare_ptr = NULL;
	symbol *sym, *mainsym;
	uint8_t *addrtmp;

	lno = 0;

	if ((mainsym = find_sym("main", 0)) == NULL) {
		error("Missing function main()");
	}

	if (outformat == FMT_BOS) {
		memcpy(out, "\x18\x04REX", 6);
		out += 6;
	} else if (outformat == FMT_CE) {
		memcpy(out, "\xEF\x7B", 2);
		out += 2;
		PROGRAM_ORIGIN -= 2;
	} else {
		error("Invalid output format");
	}
	EMIT_LD_IND_IMM_SP(out, 0);
	errsp_offset = out - (outstart + 3);
	EMIT_CALL_IMM(out, TI_RunIndicOff);
	EMIT_CALL_IMM(out, TI_HomeUp);
	try_resolve_symbols(expr - exprstart);
	if (mainsym->symtype & SYM_RESOLVED) {
		EMIT_CALL_IMM(out, mainsym->resolved_value);
	} else {
		EMIT_CALL_IMM(out, 0);
		resolve_later(out - (outstart + 3), mainsym);
	}
	exitroutineptr = PROGRAM_ORIGIN + out - outstart;
	addrtmp = exitroutineptr + 1;
	EMIT_LD_SP_IMM(out, 0);
	memcpy(&outstart[errsp_offset], &addrtmp, 3);
	EMIT_CALL_IMM(out, TI_RunIndicOn);
	EMIT_JP_IMM(out, TI_HomeUp);
	while (expr < data_start) {
		try_resolve_symbols(expr - exprstart);
		op = *expr++;
		arg = *expr;
		if (arg > 0) {
			while (!(arg & 1)) {
				arg >>= 1;
			}
			argispowerof2 = (arg > 1);
		} else {
			argispowerof2 = false;
		}
		arg = *expr;
		switch (op) {
			case IR_NOP:
				break;
			case IR_IMM:
				expr++;
				if (hlisbytelike && (unsigned)arg < 0x100) {
					EMIT_LD_L_IMM(out, (unsigned)arg);
				} else {
					EMIT_LD_HL_IMM(out, (unsigned)arg);
				}
				bt = T_INT;
				break;
			case IR_IMM_PROG_OFFSET:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				EMIT_LD_HL_IMM(out, 0);
				break;
			case IR_IMM_8:
				expr++;
				EMIT_LD_A_IMM(out, (unsigned)arg);
				bt = T_CHAR;
				break;
			case IR_IMM_32:
				expr++;
				EMIT_LD_HL_IMM(out, (unsigned)arg);
				EMIT_LD_E_IMM(out, (unsigned)*expr);
				expr++;
				bt = T_LONG;
				break;
			case IR_PUSH:
				bt = convert_flag_to_char(bt);
				if (bt == T_LONG) {
					EMIT_PUSH_HL(out);
					EMIT_PUSH_DE(out);
				} else if (bt == T_CHAR) {
					EMIT_LD_L_A(out);
					EMIT_PUSH_HL(out);
				} else {
					EMIT_PUSH_HL(out);
				}
				break;
			case IR_PUSH_IMM_32:
				expr++;
				if (hlisbytelike && (unsigned)arg < 0x100) {
					EMIT_LD_L_IMM(out, (unsigned)arg);
				} else {
					EMIT_LD_HL_IMM(out, (unsigned)arg);
				}
				EMIT_LD_E_IMM(out, *++expr);
			case IR_PUSH_32:
				EMIT_PUSH_HL(out);
			case IR_PUSH_SEC:
				EMIT_PUSH_DE(out);
				break;
			case IR_PUSH_TER:
				EMIT_PUSH_BC(out);
				break;
			case IR_POP:
				EMIT_POP_HL(out);
				bt = T_INT;
				break;
			case IR_POP_SEC:
				EMIT_POP_DE(out);
				break;
			case IR_POP_TER:
				EMIT_POP_BC(out);
				break;
			case IR_POP_32:
				EMIT_POP_BC(out);
				EMIT_LD_A_C(out);
				EMIT_POP_BC(out);
				bt = T_LONG;
				break;
			case IR_EX_SEC_PRI:
				EMIT_EX_DE_HL(out);
				break;
			case IR_CALL:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				//if (expr[0] == IR_ADJ && expr[1] == 0 && (expr[2] == IR_LEAVE || expr[2] == IR_EXIT)) {
				//	EMIT_JP_IMM(out, 0);
				//} else {
					EMIT_CALL_IMM(out, 0);
				//}
				break;
			case IR_ADJ:
				expr++;
				if (arg <= 15) {
					int i = 0;
					while (i < arg) {
						EMIT_POP_BC(out);
						i += 3;
					}
				} else {
					EMIT_LD_HL_IMM(out, (unsigned)arg);
					EMIT_ADD_HL_SP(out);
					EMIT_LD_SP_HL(out);
				}
				break;
			case IR_ENTER:
				expr++;
				if (arg == 0) {
					EMIT_CALL_IMM(out, TI__frameset0);
				} else {
					EMIT_LD_HL_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__frameset);
				}
				leaveaddress = NULL;
				break;
			case IR_LEAVE:
				if (leaveaddress != NULL && (unsigned)(leaveaddress+0x80+L_JR_IMM-out)<0x100) {
					EMIT_JR_IMM(out, leaveaddress-out+L_JR_IMM);
				} else {
					leaveaddress = out;
					EMIT_LD_SP_IX(out);
					EMIT_POP_IX(out);
					EMIT_RET(out);
				}
				break;
			case IR_EXIT:
				expr++;
				resolve_later(out + 1 - outstart, 0);
				EMIT_JP_IMM(out, 0);
				break;
			case IR_PUSH_IMM:
				expr++;
				if ((unsigned)arg < 0x100) {
					if (hlisbytelike) {
						EMIT_LD_L_IMM(out, (unsigned)arg);
						EMIT_PUSH_HL(out);
					} else if (deisbytelike) {
						EMIT_LD_E_IMM(out, (unsigned)arg);
						EMIT_PUSH_DE(out);
					} else if (bcisbytelike) {
						EMIT_LD_C_IMM(out, (unsigned)arg);
						EMIT_PUSH_BC(out);
					} else {
						EMIT_LD_HL_IMM(out, (unsigned)arg);
						EMIT_PUSH_HL(out);
					}
				} else {
					EMIT_LD_HL_IMM(out, (unsigned)arg);
					EMIT_PUSH_HL(out);
				}
				break;
			case IR_LEA_LOCAL:
				expr++;
				if ((unsigned)arg+0x80 < 0x100) {
					l = *expr++;
					if (l == IR_LOAD_CHAR) {
						EMIT_LD_A_IND_IX_DD(out, (unsigned)arg);
						bt = T_CHAR;
					} else if (l == IR_LOAD_WORD) {
						EMIT_LD_DE_IND_IX_DD(out, (unsigned)arg);
						EMIT_SIS_SUFFIX(out);
						EMIT_EX_DE_HL(out);
						bt = T_WORD;
					} else if (l == IR_LOAD_INT) {
						EMIT_LD_HL_IND_IX_DD(out, (unsigned)arg);
						bt = T_INT;
					} else if (l == IR_LOAD_LONG) {
						if ((unsigned)arg+3+0x80 < 0x100) {
							EMIT_LD_HL_IND_IX_DD(out, (unsigned)arg);
							EMIT_LD_E_IND_IX_DD(out, arg+3);
						} else {
							EMIT_PUSH_IX(out);
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_ADD_IX_BC(out);
							EMIT_LD_HL_IND_IX_DD(out, 0);
							EMIT_LD_E_IND_IX_DD(out, 3);
							EMIT_POP_IX(out);
						}
						bt = T_LONG;
					} else {
						bt = T_PTR;
						expr--;
					}
				} else {
					EMIT_LEA_HL_IX_DD(out, 0);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_ADD_HL_BC(out);
					bt = T_PTR;
				}
				break;
			case IR_LEA_GLOBAL:
				expr++;
				l = *expr++;
				if (l == IR_LOAD_CHAR) {
					EMIT_LD_A_IND_IMM(out, (unsigned)arg);
					bt = T_CHAR;
				} else if (l == IR_LOAD_WORD) {
					EMIT_LD_DE_IND_IMM(out, (unsigned)arg);
					EMIT_SIS_SUFFIX(out);
					EMIT_EX_DE_HL(out);
					bt = T_WORD;
				} else if (l == IR_LOAD_INT) {
					EMIT_LD_HL_IND_IMM(out, (unsigned)arg);
					bt = T_INT;
				} else if (l == IR_LOAD_LONG) {
					EMIT_LD_HL_IND_IMM(out, (unsigned)arg);
					EMIT_LD_DE_IND_IMM(out, arg+3);
					bt = T_LONG;
				} else {
					expr--;
					bt = T_PTR;
				}
				break;
			case IR_STORE_LOCAL:
				expr++;
				bt = convert_flag_to_char(bt);
				l = *expr++;
				if (bt == T_CHAR && l != T_CHAR) {
					EMIT_OR_A(out);
					EMIT_SBC_HL_HL(out);
					if (l == T_LONG) {
						EMIT_LD_E_L(out);
					}
					EMIT_LD_L_A(out);
					bt = l;
				}
				if ((unsigned)arg+0x80 < 0x100) {
					if (l == T_CHAR) {
						EMIT_LD_IND_IX_DD_L(out, (unsigned)arg);
					} else if (l == T_WORD) {
						if ((unsigned)arg+0x81 < 0x100) {
							EMIT_LD_IND_IX_DD_L(out, (unsigned)arg);
							EMIT_LD_IND_IX_DD_H(out, arg+1);
						} else {
							EMIT_INC_IX(out);
							EMIT_LD_IND_IX_DD_L(out, arg-1);
							EMIT_LD_IND_IX_DD_H(out, (unsigned)arg);
							EMIT_DEC_IX(out);
						}
					} else if (l == T_LONG) {
						if ((unsigned)arg+0x83 < 0x100) {
							EMIT_LD_IND_IX_DD_HL(out, (unsigned)arg);
							EMIT_LD_IND_IX_DD_E(out, arg+3);
						} else {
							EMIT_PUSH_IX(out);
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_ADD_IX_BC(out);
							EMIT_LD_IND_IX_DD_HL(out, 0);
							EMIT_LD_IND_IX_DD_E(out, 3);
							EMIT_POP_IX(out);
						}
					} else {
						EMIT_LD_IND_IX_DD_HL(out, (unsigned)arg);
					}
				}
				break;
			case IR_STORE_GLOBAL:
				expr++;
				bt = convert_flag_to_char(bt);
				l = *expr++;
				if (bt == T_CHAR && l != T_CHAR) {
					EMIT_OR_A(out);
					EMIT_SBC_HL_HL(out);
					if (l == T_LONG) {
						EMIT_LD_E_L(out);
					}
					EMIT_LD_L_A(out);
					bt = l;
				}
				if (l == T_CHAR) {
					if (bt != T_CHAR) {
						EMIT_LD_A_L(out);
					}
					EMIT_LD_IND_IMM_A(out, (unsigned)arg);
				} else if (l == T_WORD) {
					EMIT_EX_DE_HL(out);
					EMIT_LD_HL_IMM(out, (unsigned)arg);
					EMIT_LD_IND_HL_E(out);
					EMIT_INC_HL(out);
					EMIT_LD_IND_HL_D(out);
					EMIT_EX_DE_HL(out);
				} else if (l == T_LONG) {
					EMIT_LD_IND_IMM_HL(out, (unsigned)arg);
					EMIT_LD_A_E(out);
					EMIT_LD_IND_IMM_A(out, arg+3);
				} else {
					EMIT_LD_IND_IMM_HL(out, (unsigned)arg);
				}
				break;
			case IR_LOAD_CHAR:
				EMIT_LD_A_IND_HL(out);
				bt = T_CHAR;
				break;
			case IR_LOAD_WORD:
				EMIT_LD_L_IND_HL(out);
				EMIT_INC_HL(out);
				EMIT_LD_H_IND_HL(out);
				EMIT_SIS_SUFFIX(out);
				EMIT_EX_DE_HL(out);
				bt = T_WORD;
				break;
			case IR_LOAD_INT:
				EMIT_LD_HL_IND_HL(out);
				bt = T_INT;
				break;
			case IR_LOAD_LONG:
				EMIT_LD_DE_IND_HL(out);
				EMIT_INC_HL(out);
				EMIT_INC_HL(out);
				EMIT_INC_HL(out);
				EMIT_LD_L_IND_HL(out);
				EMIT_EX_DE_HL(out);
				bt = T_LONG;
				break;
			case IR_COMPARE_Z:
				if (bt < T_BOOL_CF || bt > T_BOOL_NZF) {
					last_compare_ptr = out;
					if (bt == T_CHAR) {
						EMIT_OR_A(out);
						bt = T_BOOL_ZF;
					} else if (bt == T_WORD) {
						EMIT_LD_A_H(out);
						EMIT_OR_L(out);
						bt = T_BOOL_ZF;
					} else if (bt == T_LONG) {
						EMIT_LD_C_IMM(out, 0);
						EMIT_ADD_HL_BC(out);
						EMIT_ADC_A_C(out);
						EMIT_SBC_HL_BC(out);
						EMIT_SBC_A_C(out);
						bt = T_BOOL_ZF;
					} else {
						EMIT_ADD_HL_BC(out);
						EMIT_SBC_HL_BC(out);
						bt = T_BOOL_ZF;
					}
				}
				break;
			case IR_COMPARE_NZ:
				if (bt < T_BOOL_CF || bt > T_BOOL_NZF) {
					last_compare_ptr = out;
					if (bt == T_CHAR) {
						EMIT_OR_A(out);
						bt = T_BOOL_NZF;
					} else if (bt == T_WORD) {
						EMIT_LD_A_H(out);
						EMIT_OR_L(out);
						bt = T_BOOL_NZF;
					} else if (bt == T_LONG) {
						EMIT_LD_C_IMM(out, 0);
						EMIT_ADD_HL_BC(out);
						EMIT_ADC_A_C(out);
						EMIT_SBC_HL_BC(out);
						EMIT_SBC_A_C(out);
						bt = T_BOOL_NZF;
					} else {
						EMIT_ADD_HL_BC(out);
						EMIT_SBC_HL_BC(out);
						bt = T_BOOL_NZF;
					}
				} else {
					bt ^= 1;
				}
				break;
			case IR_LOR:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_OR_A(out);
					EMIT_JR_NZ_IMM(out, L_OR_E);
					EMIT_OR_E(out);
				} else if (bt == T_WORD) {
					EMIT_LD_A_H(out);
					EMIT_OR_L(out);
					EMIT_JR_NZ_IMM(out, L_OR_D+L_OR_E);
					EMIT_OR_D(out);
					EMIT_OR_E(out);
				} else if (bt == T_LONG) {
					EMIT_OR_E(out);
					EMIT_JR_NZ_IMM(out, L_ADD_HL_DE+L_SBC_HL_DE+L_JR_NZ_IMM+L_EX_DE_HL+L_SBC_HL_BC);
					EMIT_ADD_HL_DE(out);
					EMIT_SBC_HL_DE(out);
					EMIT_JR_NZ_IMM(out, L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_DE(out);
				} else {
					EMIT_ADD_HL_BC(out);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					EMIT_JR_NZ_IMM(out, L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_LAND:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_OR_A(out);
					EMIT_JR_Z_IMM(out, L_OR_E);
					EMIT_OR_E(out);
				} else if (bt == T_WORD) {
					EMIT_LD_A_H(out);
					EMIT_OR_L(out);
					EMIT_JR_Z_IMM(out, L_OR_D+L_OR_E);
					EMIT_OR_D(out);
					EMIT_OR_E(out);
				} else if (bt == T_LONG) {
					EMIT_OR_E(out);
					EMIT_JR_Z_IMM(out, L_ADD_HL_DE+L_SBC_HL_DE+L_JR_NZ_IMM+L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_ADD_HL_DE(out);
					EMIT_SBC_HL_DE(out);
					EMIT_JR_Z_IMM(out, L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_DE(out);
				} else {
					EMIT_ADD_HL_BC(out);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					EMIT_JR_NZ_IMM(out, L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_NOT:
				if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					bt ^= 1;
				} else if (bt == T_CHAR) {
					EMIT_NEG(out);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__snot);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lnot);
				} else {
					EMIT_CALL_IMM(out, TI__inot);
				}
				break;
			case IR_OR:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_OR_E(out);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sor);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lor);
				} else {
					EMIT_CALL_IMM(out, TI__ior);
				}
				break;
			case IR_AND:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_AND_E(out);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sand);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__land);
				} else {
					EMIT_CALL_IMM(out, TI__iand);
				}
				break;
			case IR_COMPARE_EQ:
				bt = convert_flag_to_char(bt);
				EMIT_OR_A(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
				} else {
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_ZF;
				break;
			case IR_COMPARE_NEQ:
				bt = convert_flag_to_char(bt);
				EMIT_OR_A(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
				} else {
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_COMPARE_LT:
				bt = convert_flag_to_char(bt);
				EMIT_SCF(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
				} else {
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_COMPARE_LTEQ:
				bt = convert_flag_to_char(bt);
				EMIT_OR_A(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
				} else {
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_COMPARE_GTEQ:
				bt = convert_flag_to_char(bt);
				EMIT_SCF(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
				} else {
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_GT:
				bt = convert_flag_to_char(bt);
				EMIT_OR_A(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
				} else {
					EMIT_SBC_HL_DE(out);
				}
				bt = T_BOOL_CF;
				break;
			case IR_SHL:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_LD_B_L(out);
				} else {
					EMIT_LD_C_L(out);
				}
				EMIT_EX_DE_HL(out);
				if (bt == T_CHAR) {
					EMIT_CALL_IMM(out, TI__bshl);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sshl);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__lshl);
				} else {
					EMIT_CALL_IMM(out, TI__ishl);
				}
				break;
			case IR_SHR:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_LD_B_L(out);
				} else {
					EMIT_LD_C_L(out);
				}
				EMIT_EX_DE_HL(out);
				if (bt == T_CHAR) {
					EMIT_CALL_IMM(out, TI__bshru);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sshru);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__lshru);
				} else {
					EMIT_CALL_IMM(out, TI__ishru);
				}
				break;
			case IR_ADD:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_ADD_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_ADD_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_ADD_HL_BC(out);
					EMIT_ADC_A_E(out);
					EMIT_LD_E_A(out);
				} else {
					EMIT_ADD_HL_DE(out);
				}
				break;
			case IR_SUB:
				bt = convert_flag_to_char(bt);
				if (bt != T_LONG) {
					exchage_primary_secondary(bt);
				}
				if (bt == T_CHAR) {
					EMIT_SUB_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_OR_A(out);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_E(out);
					EMIT_LD_E_A(out);
				} else {
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
				}
				break;
			case IR_DIV:
				bt = convert_flag_to_char(bt);
				exchage_for_boot_math(bt);
				if (bt == T_CHAR) {
					EMIT_LD_L_A(out);
					EMIT_LD_H_IMM(out, 0);
					EMIT_LD_C_E(out);
					EMIT_LD_B_H(out);
					EMIT_CALL_IMM(out, TI__sdivu);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sdivu);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__ldivu);
				} else {
					EMIT_CALL_IMM(out, TI__idivu);
				}
				break;
			case IR_MUL:
				bt = convert_flag_to_char(bt);
				if (bt != T_CHAR) {
					exchage_for_boot_math(bt);
				}
				if (bt == T_CHAR) {
					EMIT_LD_D_A(out);
					EMIT_MLT_DE(out);
					EMIT_EX_DE_HL(out);
					bt = T_INT;
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__smulu);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lmulu);
				} else {
					EMIT_CALL_IMM(out, TI__imulu);
				}
				break;
			case IR_MOD:
				bt = convert_flag_to_char(bt);
				exchage_for_boot_math(bt);
				if (bt == T_CHAR) {
					EMIT_LD_L_A(out);
					EMIT_LD_H_IMM(out, 0);
					EMIT_LD_C_E(out);
					EMIT_LD_B_H(out);
					EMIT_CALL_IMM(out, TI__sremu);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sremu);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lremu);
				} else {
					EMIT_CALL_IMM(out, TI__iremu);
				}
				break;
			case IR_NEG:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CPL(out);
				} else {
					EMIT_EX_DE_HL(out);
					EMIT_XOR_A(out);
					EMIT_SBC_HL_HL(out);
					if (bt == T_WORD) {
						EMIT_SIS_SUFFIX(out);
						EMIT_SBC_HL_DE(out);
					} else if (bt == T_LONG) {
						EMIT_LD_C_A(out);
						EMIT_LD_A_E(out);
						EMIT_SBC_HL_BC(out);
						EMIT_SBC_A_C(out);
						EMIT_LD_E_A(out);
					} else {
						EMIT_SBC_HL_BC(out);
					}
				}
				break;
			case IR_INC:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_INC_A(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_INC_HL(out);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, 1);
					EMIT_ADD_HL_BC(out);
					EMIT_ADC_A_E(out);
					EMIT_LD_E_A(out);
				} else {
					EMIT_INC_HL(out);
				}
				break;
			case IR_DEC:
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_DEC_A(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_DEC_HL(out);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, 1);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					EMIT_ADC_A_E(out);
					EMIT_LD_E_A(out);
				} else {
					EMIT_DEC_HL(out);
				}
				break;
			case IR_INC_SEC:
				EMIT_INC_DE(out);
				break;
			case IR_INC_TER:
				EMIT_INC_BC(out);
				break;
			case IR_DEC_SEC:
				EMIT_DEC_DE(out);
				break;
			case IR_DEC_TER:
				EMIT_DEC_BC(out);
				break;
			case IR_OR_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_OR_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_A_H(out);
					EMIT_OR_IMM(out, (unsigned)arg>>8);
					EMIT_LD_H_A(out);
					EMIT_LD_A_L(out);
					EMIT_OR_IMM(out, arg&0xff);
					EMIT_LD_L_A(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__lor);
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__ior);
				}
				break;
			case IR_AND_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_AND_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_A_H(out);
					EMIT_AND_IMM(out, (unsigned)arg>>8);
					EMIT_LD_H_A(out);
					EMIT_LD_A_L(out);
					EMIT_AND_IMM(out, arg&0xff);
					EMIT_LD_L_A(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__land);
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__iand);
				}
				break;
			case IR_COMPARE_EQ_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				} else {
					EMIT_OR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				}
				bt = T_BOOL_ZF;
				break;
			case IR_COMPARE_NEQ_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				} else {
					EMIT_OR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_COMPARE_LT_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				} else {
					EMIT_OR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_LTEQ_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, arg+1);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, arg+1);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, arg+1);
					EMIT_SBC_HL_BC(out);
				} else {
					EMIT_OR_A(out);
					EMIT_LD_BC_IMM(out, arg+1);
					EMIT_SBC_HL_BC(out);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_GT_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, arg+1);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, arg+1);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, arg+1);
					EMIT_SBC_HL_BC(out);
				} else {
					EMIT_OR_A(out);
					EMIT_LD_BC_IMM(out, arg+1);
					EMIT_SBC_HL_BC(out);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_COMPARE_GTEQ_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				} else {
					EMIT_OR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_SHL_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					if (arg >= 8) {
						EMIT_XOR_A(out);
					} else if (arg > L_LD_B_E+L_ADD_A_A+L_DJNZ_IMM) {
						EMIT_LD_B_IMM(out, (unsigned)arg);
						EMIT_ADD_A_A(out);
						EMIT_DJNZ_IMM(out, -(L_DJNZ_IMM+L_ADD_A_A));
					} else {
						while (arg-- > 0) {
							EMIT_ADD_A_A(out);
						}
					}
				} else if (bt == T_LONG) {
					if (arg >= 32) {
						EMIT_XOR_A(out);
						EMIT_LD_E_A(out);
						EMIT_SBC_HL_HL(out);
					} else if (arg > 1) {
						EMIT_LD_C_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__lshl);
					} else {
						EMIT_XOR_A(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADC_A_E(out);
						EMIT_LD_E_A(out);
					}
				} else {
					if (bt == T_WORD && arg >= 16) {
						EMIT_LD_L_IMM(out, 0);
						EMIT_LD_H_L(out);
					} else if (bt == T_INT && arg >= 24) {
						EMIT_OR_A(out);
						EMIT_SBC_HL_HL(out);
					} else if (arg > L_LD_B_E+L_ADD_HL_HL+L_DJNZ_IMM) {
						EMIT_LD_B_IMM(out, (unsigned)arg);
						EMIT_ADD_HL_HL(out);
						EMIT_DJNZ_IMM(out, -(L_DJNZ_IMM+L_ADD_HL_HL));
					} else {
						while (arg-- > 0) {
							EMIT_ADD_HL_HL(out);
						}
					}
					if (bt == T_WORD) {
						EMIT_SIS_SUFFIX(out);
						EMIT_EX_DE_HL(out);
						EMIT_EX_DE_HL(out);
					}
				}
				break;
			case IR_SHR_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					if (arg >= 8) {
						EMIT_XOR_A(out);
					} else if (arg > (L_LD_B_E+L_OR_A+L_RRA+L_DJNZ_IMM)/(L_OR_A+L_RRA)) {
						EMIT_LD_B_IMM(out, (unsigned)arg);
						EMIT_OR_A(out);
						EMIT_RRA(out);
						EMIT_DJNZ_IMM(out, -(L_DJNZ_IMM+L_RRA+L_OR_A));
					} else {
						while (arg-- > 0) {
							EMIT_OR_A(out);
							EMIT_RRA(out);
						}
					}
				} else if (bt == T_WORD) {
					EMIT_LD_C_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__sshru);
				} else if (bt == T_LONG) {
					EMIT_LD_C_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__lshru);
				} else {
					EMIT_LD_C_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__ishru);
				}
				break;
			case IR_ADD_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_ADD_A_IMM(out, (unsigned)arg);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_XOR_A(out);
					EMIT_ADD_HL_BC(out);
					EMIT_ADC_A_E(out);
					EMIT_LD_E_A(out);
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					if (bt == T_WORD) {
						EMIT_SIS_SUFFIX(out);
					}
					EMIT_ADD_HL_BC(out);
				}
				break;
			case IR_SUB_CONST:
				expr++;
				bt = convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_SUB_A_IMM(out, (unsigned)arg);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_IMM(out, 0);
					EMIT_LD_E_A(out);
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					if (bt == T_WORD) {
						EMIT_SIS_SUFFIX(out);
					}
					EMIT_SBC_HL_BC(out);
				}
				break;
			case IR_MUL_CONST:
				expr++;
				if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					if (bt == T_BOOL_CF) {
						EMIT_JR_C_IMM(out, L_LD_HL_IMM);
						EMIT_OR_A(out);
					} else if (bt == T_BOOL_ZF) {
						EMIT_JR_Z_IMM(out, L_LD_HL_IMM);
						EMIT_OR_A(out);
					} else if (bt == T_BOOL_NCF) {
						EMIT_JR_NC_IMM(out, L_LD_HL_IMM);
					} else {
						EMIT_JR_NZ_IMM(out, L_LD_HL_IMM);
						EMIT_OR_A(out);
					}
					EMIT_SBC_HL_HL(out);
					EMIT_JR_IMM(out, L_LD_HL_IMM);
					EMIT_LD_HL_IMM(out, (unsigned)arg);
				} else if (bt == T_CHAR) {
					EMIT_LD_H_IMM(out, (unsigned)arg);
					EMIT_LD_L_A(out);
					EMIT_MLT_HL(out);
					bt = T_INT;
				} else if (bt == T_LONG) {
					if (arg == 0) {
						EMIT_OR_A(out);
						EMIT_SBC_HL_HL(out);
						EMIT_LD_E_L(out);
					} else if (arg == 2) {
						EMIT_LD_A_E(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADC_A_A(out);
					} else if (arg > 2) {
						EMIT_XOR_A(out);
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__lmulu);
					}
				} else {
					if (arg == 0) {
						EMIT_OR_A(out);
						EMIT_SBC_HL_HL(out);
					} else if (arg == 2) {
						EMIT_ADD_HL_HL(out);
					} else if (arg == 3) {
						EMIT_PUSH_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_POP_DE(out);
						EMIT_ADD_HL_DE(out);
					} else if (arg == 4) {
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
					} else if (arg == 5) {
						EMIT_PUSH_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_POP_DE(out);
						EMIT_ADD_HL_DE(out);
					} else if (arg == 6) {
						EMIT_PUSH_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_POP_DE(out);
						EMIT_ADD_HL_DE(out);
						EMIT_ADD_HL_DE(out);
					} else if (arg == 7) {
						EMIT_PUSH_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_POP_DE(out);
						EMIT_ADD_HL_DE(out);
						EMIT_ADD_HL_DE(out);
						EMIT_ADD_HL_DE(out);
					} else if (arg == 8) {
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
					} else if (arg == 9) {
						EMIT_PUSH_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_POP_DE(out);
						EMIT_ADD_HL_DE(out);
					} else if (arg == 10) {
						EMIT_ADD_HL_HL(out);
						EMIT_PUSH_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_POP_DE(out);
						EMIT_ADD_HL_DE(out);
					} else if (arg == 16) {
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
						EMIT_ADD_HL_HL(out);
					} else if (arg > 2) {
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__imulu);
					}
				}
				break;
			case IR_DIV_CONST:
				expr++;
				if (arg == 0) {
					EMIT_SCF(out);
					EMIT_SBC_HL_HL(out);
					bt = T_INT;
				} else if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					if (arg > 1) {
						EMIT_XOR_A(out);
						bt = T_CHAR;
					}
				} else if (bt == T_CHAR) {
					if (arg == 2) {
						EMIT_RRA(out);
					} else if (arg == 4) {
						EMIT_RRA(out);
						EMIT_RRA(out);
					} else if (arg == 8) {
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
					} else if (arg == 16) {
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
					} else if (arg == 32) {
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
					} else if (arg == 64) {
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
					} else if (arg == 128) {
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
						EMIT_RRA(out);
					} else if (arg >= 256) {
						EMIT_XOR_A(out);
					} else {
						EMIT_LD_L_A(out);
						EMIT_LD_H_IMM(out, 0);
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__sdivu);
					}
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__sdivu);
				} else if (bt == T_LONG) {
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__ldivu);
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__idivu);
				}
				break;
			case IR_MOD_CONST:
				expr++;
				
				if (arg == 0) {
					EMIT_SCF(out);
					EMIT_SBC_HL_HL(out);
					bt = T_INT;
				} else if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					bt = convert_flag_to_char(bt);
				} else if (bt == T_CHAR) {

				}
				break;
			case IR_JMP:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				EMIT_JP_IMM(out, 0);
				break;
			case IR_BZ:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				EMIT_JP_Z_IMM(out, 0);
				break;
			case IR_BNZ:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				EMIT_JP_NZ_IMM(out, 0);
				break;
			case IR_STRLEN:
				EMIT_PUSH_HL(out);
				EMIT_CALL_IMM(out, TI__strlen);
				EMIT_POP_BC(out);
				break;
			case IR_DEFINE_FUNCTION:
				expr++;
				expr++;
				break;
			default:
				printf("Invalid IR code: %X\n", op);
				//error("Internal: Invalid intermediate representation code");
				break;
		}
	}
}

int main(int argc, char **argv) {
#ifdef PLATFORM_DESKTOP
	FILE *fd;
	unsigned int exprlen, datalen, bufferlen;
	char *buffer;
	_ptr oldopcode;
	if (argc < 2) {
		printf("Usage: %s src [bin]\n", argv[0]);
		return 0;
	}
	if ((fd = fopen(argv[1], "r")) == NULL) {
		printf("Source file \"%s\" not found.\n", argv[1]);
		return -1;
	}
	fseek(fd, 0, 2);
	srclen = ftell(fd);
	fseek(fd, 0, 0);
	if ((srcdata = _malloc(srclen)) == NULL) {
		printf("Failed to malloc %u bytes of space for source data.\n", srclen);
		return 1;
	}
	fread(srcdata, srclen, 1, fd);
	fclose(fd);

	if ((expr = exprstart = malloc(IR_OUTPUT_SIZE * sizeof(_ptr))) == NULL) {
		printf("Failed to malloc %u bytes of space for IR output.\n", (unsigned int)(IR_OUTPUT_SIZE * sizeof(int32_t)));
		return 1;
	}
	srcoffset = 0;
	expr--;
	precompile();
	compile();
	postcompile();
	exprlen = data_start - exprstart;
	datalen = expr - data_start;
	printf("Compiled %u bytes of IR.\n", (unsigned int)(exprlen*sizeof(_int)));

	if ((buffer = malloc(exprlen * 32 + datalen * 4)) == NULL) {
		printf("Failed to malloc %u bytes of space for file output buffer.\n", exprlen * 40);
		return 1;
	}
	bufferlen = 0;
	lno = 0;
	for (unsigned int i = 0; i < exprlen; i++) {
		_int num;
		_ptr opcode = NULL;
		oldopcode = opcode;
		opcode = exprstart[i];
		if (opcode >= 0 && opcode < IR_INVALID_OPCODE) {
			int8_t nargs = IR_ARGS[opcode];
#ifdef DEBUG
			printf("%u: %u %d %s\n", i, opcode, nargs, IR_STRINGS[opcode]);
			if (nargs >= 1) {
				printf(" arg0: %lld 0x%llX\n", exprstart[i+1], exprstart[i+1]);
			}
			if (nargs >= 2) {
				printf(" arg1: %lld 0x%llX\n", exprstart[i+2], exprstart[i+2]);
			}
			if (nargs >= 3) {
				printf(" arg2: %lld 0x%llX\n", exprstart[i+3], exprstart[i+3]);
			}
#endif
			if (opcode == IR_DEFINE_FUNCTION) {
				buffer[bufferlen++] = '\n';
			}
			memcpy(&buffer[bufferlen], IR_STRINGS[opcode], strlen(IR_STRINGS[opcode]));
			bufferlen += strlen(IR_STRINGS[opcode]);
			if (nargs > 0) {
				buffer[bufferlen++] = ' ';
				if (opcode == IR_DEFINE_FUNCTION || opcode == IR_CALL || opcode == IR_JMP || opcode == IR_BZ || opcode == IR_BNZ || opcode == IR_IMM_PROG_OFFSET) {
					symbol *tmpsym = exprstart[i+1];
					if (tmpsym->symtype & SYM_RESOLVED) {
						bufferlen += sprintf(&buffer[bufferlen], "\"%s\", $%X, ", (char*)&tmpsym->name, tmpsym->resolved_value);
					} else if (tmpsym->name[0] == 0) {
						bufferlen += sprintf(&buffer[bufferlen], "$%X, ", tmpsym->value);
					} else {
						bufferlen += sprintf(&buffer[bufferlen], "\"%s\", ", (char*)&tmpsym->name);
					}
					if (opcode == IR_DEFINE_FUNCTION) {
						bufferlen += sprintf(&buffer[bufferlen], "$%X, ", tmpsym->value);
					}
				}
				while (nargs > 0) {
					int arglen;
					i++;
					nargs--;
					if (exprstart[i] > 65536 && exprstart[i] < -65536llu) {
						arglen = sprintf(&buffer[bufferlen], "$%llX", exprstart[i]);
					} else if (exprstart[i] >= -65536llu) {
						arglen = sprintf(&buffer[bufferlen], "-%llu", -exprstart[i]);
					} else {
						arglen = sprintf(&buffer[bufferlen], "%llu", exprstart[i]);
					}
					if (arglen <= 0) {
						printf("Internal: sprintf failed with argument %llu (%llX)\n", exprstart[i], exprstart[i]);
					}
					bufferlen += arglen;
					if (nargs > 0) {
						buffer[bufferlen++] = ',';
						buffer[bufferlen++] = ' ';
					}
				}
			}
			buffer[bufferlen++] = '\n';
		} else {
			buffer[bufferlen++] = '?';
			buffer[bufferlen++] = '\n';
			printf("Invalid IR code: 0x%llX\nLast known valid IR code: 0x%llX\n", opcode, oldopcode);
			//error("Internal: Invalid intermediate representation code");
		}
	}
	if (datalen > 0) {
		buffer[bufferlen++] = 'd';
		buffer[bufferlen++] = 'b';
		buffer[bufferlen++] = ' ';
		for (unsigned int i = 1; i <= datalen; i++) {
			const uint8_t powers[3] = {100, 10, 1};
			if (data_start[i] != 0) {
				bufferlen += sprintf(&buffer[bufferlen], "$%llX, ", data_start[i]);
			} else {
				buffer[bufferlen++] = '0';
				buffer[bufferlen++] = '\n';
				if (i < datalen) {
					buffer[bufferlen++] = 'd';
					buffer[bufferlen++] = 'b';
					buffer[bufferlen++] = ' ';
				}
			}
		}
	}

	if ((fd = fopen(argv[2], "w")) == NULL) {
		printf("Failed to open destination file \"%s\".\n", argv[2]);
		return -2;
	}
	fwrite(buffer, bufferlen, 1, fd);
	fclose(fd);
	
	printf("Wrote %u bytes of IR assembly to \"%s\".\n", bufferlen, argv[2]);

	if (argc >= 4) {
		if ((out = outstart = malloc(OUTPUT_BUFFER_SIZE)) == NULL) {
			printf("Failed to malloc %u bytes of space for output buffer\n", OUTPUT_BUFFER_SIZE);
			return 1;
		}
		assemble();
		postassemble();
		if ((fd = fopen(argv[3], "w")) == NULL) {
			printf("Failed to open destination file \"%s\"\n", argv[3]);
			return -2;
		}
		fwrite(outstart, out-outstart, 1, fd);
		fclose(fd);
		printf("Wrote %lld bytes of eZ80 assembly to \"%s\"\n", out-outstart, argv[3]);
	}
#else
#ifdef BOS_BUILD
	if (argc < 2) {
		gui_PrintLine("Usage: bcc src [bin]");
		return 0;
	}
#else
	if (argc < 2) {
		os_PutStrFull("Usage: bcc src [bin]");
		return 0;
	}
#endif
#endif
	return 0;
}

