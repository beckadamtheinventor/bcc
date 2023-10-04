
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

// #define DEBUG

#ifdef PLATFORM_DESKTOP

#define _malloc malloc
#define _free free

#else
	// CE Specific defines
#include <tice.h>

#ifdef BOS_BUILD
	// BOS Specific defines
#include <bos.h>

#define _malloc sys_Malloc
#define _free sys_Free

#else
	// TI-OS Specific defines
#include <fileioc.h>
#include <graphx.h>

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
	return &__mallocmem[(j - (uint8_t*)&__mallocalloc) * __mallocblocksize];
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
	SYM_CONST_FUNCTION,
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
	T_STRUCT,
	T_TYPEDEF,
	T_BOOL,
	T_STR,
	T_BOOL_CF = 26,
	T_BOOL_NCF,
	T_BOOL_ZF,
	T_BOOL_NZF,
	T_MASK = 0x1f,
	T_INLINE_DATA = 0x20,
	T_PTR = 0x40,
};

enum {
	IR_NOP,
	IR_IMM, // load immediate 24-bit value
	IR_IMM_PROG_OFFSET, // load immediate 24-bit value offset of expr from exprstart
	IR_IMM_32, // load immediate 32-bit value
	IR_IMM_32_SEC, // load immediate 32-bit value into secondary register
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
	IR_COMPARE_Z, // compare primary register == 0, storing the result to the primary register
	IR_COMPARE_NZ, // compare primary register != 0, storing the result to the primary register

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
	IR_STRCPY, // strcpy(primary, secondary)
	IR_STORE, // store arg bytes of primary to address in secondary
	IR_SET_ONE_IF_NOT_ZERO, // set primary to 1 if primary is not zero
	IR_DEFINE_FUNCTION, // Define function here. arg0 is symbol, arg1 is number of arguments

	IR_PUSH_ARG,
	IR_PUSH_ARG_32,
	IR_PUSH_ARG_IMM,
	IR_PUSH_ARG_IMM_32,

	IR_INVALID_OPCODE,
};

enum {
	TK_NUM = 128, TK_STR, TK_CHAR, TK_DATA, TK_FUN, TK_ID,
	TK_IF, TK_ELSE, TK_WHILE, TK_DO, TK_ENUM, TK_RETURN, TK_SIZEOF, TK_TYPEDEF, TK_STRUCT, TK_INCLUDE,
	TK_ASSIGN, TK_ADDEQ, TK_SUBEQ, TK_MULEQ, TK_DIVEQ, TK_MODEQ, TK_COND, TK_LOR, TK_LAND, TK_OR, TK_XOR, TK_AND,
	TK_EQ, TK_NE, TK_LT, TK_GT, TK_LTEQ, TK_GTEQ, TK_SHL, TK_SHR, TK_ADD, TK_SUB, TK_MUL, TK_DIV, TK_MOD,
	TK_STRUCTPTRACCESS, TK_STRUCTACCESS,
	TK_INC, TK_DEC,
};

enum {
	FMT_CE = 1,
	FMT_BOS,
#ifdef PLATFORM_DESKTOP
	FMT_BXS2307,
	FMT_BXS2320,
#endif
};

#ifdef PLATFORM_DESKTOP
#include "ir_data.h"
#endif

#define FUNCTION_MAX_NUM_ARGS 16
#define sizeof_symbol(name) (strlen(name)+sizeof(symbol))
typedef struct _symbol {
	uint8_t symtype, valtype, allowfree;
	unsigned int datalen;
#ifdef PLATFORM_DESKTOP
	long long value;
	long long resolved_value;
#else
	uint32_t value;
	uint32_t resolved_value;
#endif
	uint8_t *functionargs;
	struct _symbol *members;
	struct _symbol *prev, *next;
	uint16_t hash;
	char name[1];
} symbol;

bool tkisconst = true;
uint8_t tk, tkvaltype;
#ifdef PLATFORM_DESKTOP
bool reverse_argument_stack = false;
#else
bool reverse_argument_stack = true;
#endif

#ifdef BOS_BUILD
uint8_t outformat = FMT_BOS;
#else
uint8_t outformat = FMT_CE;
#endif
symbol *tksym = NULL;
char *tkname;
unsigned int tknamelen;
char *srcdata;
#ifdef PLATFORM_DESKTOP
#define IR_OUTPUT_SIZE 1024000
#define OUTPUT_BUFFER_SIZE 16384000
#define DATA_RESOLVE_STACK_SIZE 4096
#define RESOLVE_STACK_SIZE 65536
#define SYM_STACK_SAVE_SIZE 256
#define _int int32_t
#define _ptr long long
#define signext(v) ((v>=0x80000000)?((v)|0xffffffff00000000llu):(v))
#else
#define IR_OUTPUT_SIZE 32768
#define OUTPUT_BUFFER_SIZE 0xFFE8
#define DATA_RESOLVE_STACK_SIZE 1024
#define RESOLVE_STACK_SIZE 4096
#define SYM_STACK_SAVE_SIZE 16
#define _int int
#define _ptr unsigned int
#define signext(v) (v)
#endif

#define FUNCTION_ARGUMENT_STACK_SIZE 32
typedef struct _function_argument_stack_item {
	_ptr *expr, *expr_end
} function_argument_stack_item;
function_argument_stack_item function_argument_stack[FUNCTION_ARGUMENT_STACK_SIZE];
unsigned int function_argument_stack_sp;
char *tkvalstr;
uint32_t tkval;
_ptr *resolvestack, *resolvestackstart, *expr, *exprstart, *data_start, *data_resolve_stack;
_int data_resolve_sp = 0;
uint8_t *out, *outstart;
unsigned int tkvallen, errsp_offset, exitroutineptr, lno, srcoffset, srclen, globaladdr, PROGRAM_ORIGIN = 0;
symbol *symtable = NULL;
symbol **localsymstack = NULL;

#ifndef PLATFORM_DESKTOP
#ifndef BOS_BUILD
void console_printline(const char *s) {
	static uint8_t y = 2;
	gfx_PrintStringXY(s, 2, y);
	y += 10;
}
#endif
#endif

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
		gui_PrintInt(lno);
	}
	sys_WaitKeyCycle();
#else
	console_printline(s);
	if (lno > 0) {
		console_printline("Error on line");
		gfx_PrintUInt(lno, 0);
	}
	while (!os_GetCSC());
	gfx_End();
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
		if (!((unsigned)(c&~0x20)-'A' < 26 || (unsigned)c-'0' < 10 || c == '_')) {
			srcoffset += strlen(a) - 1;
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


#ifdef PLATFORM_DESKTOP
symbol *add_sym(const char *name, unsigned int namelen, uint8_t symtype, uint8_t valtype, long long value)
#else
symbol *add_sym(const char *name, unsigned int namelen, uint8_t symtype, uint8_t valtype, int value)
#endif
{
	symbol *sym;
	if (namelen == 0) {
		namelen = strlen(name);
	}
	sym = _malloc(sizeof(symbol)+namelen);
	if (sym == NULL) {
		error("Out of memory");
	}
	memset(sym, 0, sizeof(symbol));
	// link new symbol into linked list of symbols
	if (symtable != NULL) {
		symtable->next = sym;
	}
	sym->prev = symtable;
	symtable = sym;

	// copy symbol name
	memcpy(sym->name, name, namelen);
	sym->name[namelen] = 0;
	sym->symtype = symtype;
	sym->valtype = valtype;
	sym->allowfree = 1;
	sym->value = value;
	sym->hash = compute_hash(name, namelen);
	sym->next = NULL;
#ifdef DEBUG
	printf("Added symbol \"%s\" symtype %X valtype %X value %llX hash %X\n", (char*)&sym->name, symtype, valtype, value, sym->hash);
#endif
	return sym;
}

symbol *add_sym_function(const char *name, unsigned int namelen, uint8_t symtype, uint8_t valtype, char *value, uint8_t args[]) {
	symbol *sym = add_sym(name, namelen, symtype, valtype, value);
	sym->functionargs = _malloc(args[0] + 1);
	memcpy(sym->functionargs, args, args[0] + 1);
	sym->resolved_value = value;
#ifdef DEBUG
	printf("Symbol is function value named \"%s\".\n", (char*)sym->resolved_value);
#endif
	return sym;
}

symbol *make_anon_sym(unsigned int val, uint8_t valtype) {
	symbol *sym, *tmp;
	if ((sym = _malloc(sizeof(symbol))) == NULL) {
		error("Out of memory");
	}
	memset(sym, 0, sizeof(symbol));
	sym->allowfree = 0;
	sym->value = val;
	sym->valtype = valtype;
	if (symtable != NULL) {
		symtable->next = sym;
	}
	sym->prev = symtable;
	symtable = sym;
	sym->next = NULL;
#ifdef DEBUG
	printf("Added anon symbol 0x%llX\n", (long long)sym);
#endif
	return sym;
}

symbol *make_anon_sym_str(unsigned int offset, char *str, unsigned int len) {
	symbol *sym = make_anon_sym(offset, T_STR);
#ifdef DEBUG
	printf("Resolving data later at offset 0x%llX pointer 0x%llX length 0x%X\n", expr-exprstart, (_ptr)ptr, len);
#endif
	data_resolve_stack[data_resolve_sp++] = (_ptr)sym;
	data_resolve_stack[data_resolve_sp++] = (_ptr)str;
	data_resolve_stack[data_resolve_sp++] = len;
	return sym;
}



void save_sym_stack(void) {
	// static size_t num_calls = 1;
	// printf("save_sym_stack called %lld times\n", num_calls++);

	// push to the symbol save stack
	*++localsymstack = symtable;
}

// free sym stack from current down to saved point, pop symbol save stack
void free_local_symbols(void) {
	// static size_t num_calls = 1;
	symbol *tmp2;
	symbol *sym = symtable;
	symbol *tmp = *localsymstack;
	*localsymstack-- = NULL;
	// printf("free_local_symbols called %lld times\n", num_calls++);

	if (tmp != NULL) {
		do {
			// break if we've reached the saved point in the symbol stack
			if (sym == tmp) {
				break;
			}
			if (sym->allowfree > 0) {
#ifdef DEBUG
				printf("Freeing symbol \"%s\"\n", sym->name);
#endif
				tmp2 = sym->prev;
				sym->prev = NULL;
				_free(sym);
				sym = tmp2;
			} else {
#ifdef DEBUG
				printf("Not freeing symbol \"%s\"\n", sym->name);
#endif
				tmp2 = sym->prev;
				sym->prev = tmp->prev;
				sym->next = tmp;
				tmp->prev = sym;
				sym = tmp2;
			}
		} while (sym != NULL);
	}
	symtable = tmp;
}

// search for a symbol in the symbol table, returning NULL if not found.
symbol *find_sym(const char *name, unsigned int namelen) {
	uint16_t hash = compute_hash(name, (namelen>0)?namelen:strlen(name));
	symbol *sym;
#ifdef DEBUG
	if (namelen > 0) {
		char *symname = _malloc(namelen+1);
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
	if (symtable != NULL) {
		sym = symtable;
		do {
			// printf("Checking symbol at %llX\n", (long long)sym);
			// printf("Checking symbol \"%s\" with hash 0x%X at 0x%llX\n", (char*)&sym->name, sym->hash, (long long int)sym);
			if (hash == sym->hash) {
				if (!strncmp(name, sym->name, namelen)) {
					// printf("Returning symbol \"%s\" with hash 0x%X at 0x%llX\n", sym->name, sym->hash, (long long int)sym);
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
	if (tk) {
		tk2 = peekchar();
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
			getchar();
			if (consume_token("include")) {
				tk = TK_INCLUDE;
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
			uint32_t num = 0;
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
			uint32_t num = 0;
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
					srcoffset++;
				} else if ((peekchar()&~0x20) == 'T') {
					tkval = '\t';
					srcoffset++;
				} else if ((peekchar()&~0x20) == 'R') {
					tkval = '\r';
					srcoffset++;
				} else if (peekchar() == '0') {
					tkval = '\0';
					srcoffset++;
				} else {
					tkval = getchar();
				}
			} else {
				tkval = getchar();
			}
			if (getchar() != '\'') {
				error("Unterminated char literal");
			}
			tkvaltype = T_CHAR;
			tk = TK_CHAR;
			tkisconst = true;
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
			if ((ptr = _malloc(srcoffset-i)) == NULL) {
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
		} else if (!(tk == ';' || tk == ',' || tk == '~' || tk == ';' || tk == '{' || tk == '}' || tk == '(' || tk == ')' || tk == '[' || tk == ']' || tk == ',' || tk == ':')) {
#ifdef PLATFORM_DESKTOP
			printf("tk = \"%c\" 0x%X\n", tk, tk);
#endif
			error("Invalid token");
		}
	}
#ifdef DEBUG
	printf("tk = %X \"%c\"\n", tk, tk);
#endif
	// printf("tk = \"%c\" 0x%X\n", tk, tk);
}

void expression(uint8_t level) {
	bool primaryisconst = true, primaryisptr = false;
	uint8_t primarytype;
	int32_t primary;
	_ptr *d, *tmpexpr = expr;
	unsigned int argno;
	int tmp;
	symbol *sym;

	//printf("%u\n", lno);
	//printf("tk = %X tkval = %X\n", tk, tkval);
	if (!tk) {
		error("Unexpected EOF");
	} else if (tk == TK_NUM || tk == TK_STR || tk == TK_DATA || tk == TK_CHAR) {
		if (tk == TK_STR || tk == TK_DATA) {
			*++expr = IR_IMM_PROG_OFFSET;
			*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
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
			if (tkvaltype & T_INLINE_DATA) {
				if (tkvaltype >= T_PTR) {
					*++expr = IR_IMM;
					*++expr = 3 * tkvallen;
				} else if ((tkvaltype & T_MASK) == T_STR) {
					*++expr = IR_IMM;
					*++expr = tkvallen;
				} else if ((tkvaltype & T_MASK) >= T_CHAR && (tkvaltype & T_MASK) <= T_LONG) {
					*++expr = IR_IMM;
					*++expr = (tkvaltype & T_MASK) * tkvallen;
				} else {
					error("sizeof: Invalid/unsupported or non-constant size value/type");
				}
			} else if (tkvaltype >= T_PTR) {
				*++expr = IR_IMM;
				*++expr = 3;
			} else if (tkvaltype == T_STR) {
				*++expr = IR_IMM_PROG_OFFSET;
				*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
				*++expr = IR_STRLEN;
				tkisconst = false;
			} else if (tkvaltype >= T_CHAR && tkvaltype <= T_LONG) {
				*++expr = IR_IMM;
				*++expr = tkvaltype;
			} else {
				error("sizeof: Invalid/unsupported or non-constant size value/type");
			}
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
			argno = 0;
			if ((sym->symtype & SYM_MASK) != SYM_FUNCTION && (sym->symtype & SYM_MASK) != SYM_CONST_FUNCTION) {
				error("can't call non-function value as function");
			}
			tk_next();
			if (reverse_argument_stack) {
				// keep track of argument IR generation start
				function_argument_stack_sp = 0;
				function_argument_stack[0].expr = expr;
				while (tk != ')') {
					// adding each expression IR start and end to a FILO stack
					function_argument_stack_sp++;
					function_argument_stack[function_argument_stack_sp].expr = expr;
					expression(TK_ASSIGN);
					if (sym->functionargs == NULL && argno > 0 || argno > sym->functionargs[0]) {
						error("Too many arguments for function");
					}
					if (tkisconst) {
						if (sym->functionargs[sym->functionargs[0]+1-argno] == T_LONG) {
							*++expr = IR_PUSH_ARG_IMM_32;
							*++expr = tkval;
							*++expr = tkval >> 24;
							tmp += 6;
						} else {
							*++expr = IR_PUSH_ARG_IMM;
							*++expr = tkval;
							tmp += 3;
						}
					} else if (sym->functionargs[sym->functionargs[0]+1-argno] == T_LONG) {
						*++expr = IR_PUSH_ARG_32;
						tmp += 6;
					} else {
						*++expr = IR_PUSH_ARG;
						tmp += 3;
					}
					function_argument_stack[function_argument_stack_sp].expr_end = expr;
					if (tk == ',') { // maybe unnecessary check?
						tk_next();
					}
					argno++;
				}
				function_argument_stack[0].expr_end = expr;
				// copy argument expression IR backwards
				while (function_argument_stack_sp > 0) {
					_ptr *e = function_argument_stack[function_argument_stack_sp].expr;
					while (e < function_argument_stack[function_argument_stack_sp].expr_end) {
						*++expr = *++e;
					}
					function_argument_stack_sp--;
				}
				// overwrite the forwards expression IR with the backwards argument expression IR
				for (unsigned int i = 1; i <= function_argument_stack[0].expr_end - function_argument_stack[0].expr; i++) {
					function_argument_stack[0].expr[i] = function_argument_stack[0].expr_end[i];
				}
				// rewind the IR output
				expr = function_argument_stack[0].expr_end;
			} else {
				while (tk != ')') {
					expression(TK_ASSIGN);
					if (sym->functionargs == NULL && argno > 0 || argno > sym->functionargs[0]) {
						error("Too many arguments for function");
					}
					if (tkisconst) {
						if (sym->functionargs[argno+1] == T_LONG) {
							*++expr = IR_PUSH_ARG_IMM_32;
							*++expr = tkval;
							*++expr = tkval >> 24;
							tmp += 6;
						} else {
							*++expr = IR_PUSH_ARG_IMM;
							*++expr = tkval;
							tmp += 3;
						}
					} else if (sym->functionargs[argno+1] == T_LONG) {
						*++expr = IR_PUSH_ARG_32;
						tmp += 6;
					} else {
						*++expr = IR_PUSH_ARG;
						tmp += 3;
					}
					function_argument_stack[function_argument_stack_sp].expr_end = expr;
					if (tk == ',') { // maybe unnecessary check?
						tk_next();
					}
					argno++;
				}
			}
			if (sym->functionargs == NULL && argno > 0 || argno > sym->functionargs[0]) {
				error("Too many arguments for function");
			}
			tk_next();
			*++expr = IR_CALL;
			*++expr = sym;
			*++expr = IR_ADJ;
			*++expr = tmp;
			if ((sym->valtype & T_MASK) == T_STR) {
				tkvaltype = (sym->valtype & ~T_MASK) | T_CHAR;
			} else {
				tkvaltype = sym->valtype;
			}
			tkisconst = false;
		} else if (sym->symtype & SYM_LOCAL) {
			// local value
			*++expr = IR_LEA_LOCAL;
			*++expr = signext(sym->value);
			//printf("sym->valtype = 0x%X\n", sym->valtype);
			if (sym->valtype <= T_LONG) {
				*++expr = sym->valtype + IR_LOAD_CHAR - T_CHAR;
			} else {
				*++expr = IR_LOAD_INT;
			}
			tkvaltype = sym->valtype;
			tkisconst = false;
		} else if (sym->symtype & SYM_GLOBAL) {
			// global value
			*++expr = IR_LEA_GLOBAL;
			*++expr = sym->value;
			if (sym->valtype <= T_LONG) {
				*++expr = sym->valtype + IR_LOAD_CHAR - T_CHAR;
			} else {
				*++expr = IR_LOAD_INT;
			}
			tkvaltype = sym->valtype;
			tkisconst = false;
		} else if ((sym->symtype & SYM_MASK) == SYM_CONSTANT) {
			tkvaltype = sym->valtype;
			tkval = sym->value;
			tkisconst = true;
		} else {
			// printf("0x%X \"%s\"\n", sym->symtype, sym->name);
			error("Invalid variable type");
		}
		while (tk == '[') {
			primary = tkval;
			primarytype = tkvaltype;
			primaryisconst = tkisconst;
			tk_next();
			d = expr;
			if (!primaryisconst) {
				*++expr = IR_PUSH;
			}
			expression(TK_ASSIGN);
			if (tk != ']') {
				error("Missing closing bracket");
			}
			if (primarytype == T_PTR) {
				error("Cannot index pointer to void");
			} else if (primarytype < T_PTR && primarytype != T_STR && !(primarytype & T_INLINE_DATA)) {
				error("Pointer type expected");
			} else {
				if (tkisconst && primaryisconst) { // constant[constant]
					expr = d; // rewind emitted data for constant expression
					if ((primarytype & T_MASK) >= T_TYPEDEF) {
						tkval = primary + tkval;
					} else {
						tkval = primary + tkval * (primarytype & T_MASK);
					}
				} else if (primaryisconst) { // constant[var]
					if ((primarytype & T_MASK) < T_TYPEDEF) {
						*++expr = IR_MUL_CONST;
						*++expr = primarytype & T_MASK;
					}
					*++expr = IR_ADD_CONST;
					*++expr = primary; // primary is not destroyed if the expression is not constant
					tkisconst = false;
				} else if (tkisconst) { // var[constant]
					expr = d;
					*++expr = IR_ADD_CONST;
					if ((primarytype & T_MASK) >= T_TYPEDEF) {
						*++expr = tkval;
					} else {
						*++expr = tkval * (primarytype & T_MASK);
					}
					tkisconst = false;
				} else {
					if ((primarytype & T_MASK) < T_TYPEDEF) {
						*++expr = IR_MUL_CONST;
						*++expr = primarytype & T_MASK;
					}
					*++expr = IR_POP_SEC;
					*++expr = IR_ADD;
					tkisconst = false;
				}
				if (primarytype & T_INLINE_DATA) {
					*++expr = IR_LOAD_CHAR + (primarytype & T_MASK) - T_CHAR;
					tkvaltype &= ~T_INLINE_DATA;
				} else {
					if (primarytype >= T_PTR * 2) {
						*++expr = IR_LOAD_INT;
					} else {
						*++expr = IR_LOAD_CHAR + (primarytype & T_MASK) - T_CHAR;
					}
					tkvaltype -= T_PTR;
				}
			}
			primaryisptr = true;
			tk_next();
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
				error("Invalid type cast: quadruple (4x) pointers and beyond are not supported");
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
		primaryisptr = true;
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
			if (sym == NULL) {
				error("Invalid value for increment/decrement");
			}
			*++expr = (tmp == TK_INC) ? IR_INC : IR_DEC;
			*++expr = (sym->symtype & SYM_GLOBAL) ? IR_STORE_GLOBAL : IR_STORE_LOCAL;
			*++expr = signext(sym->value);
			if ((tkvaltype & T_MASK) == T_STR) {
				*++expr = (tkvaltype & ~T_MASK) | T_CHAR;
			} else {
				*++expr = tkvaltype;
			}
		} else {
			error("Invalid value increment/decrement");
		}
	} else {
		// printf("tk=0x%X \"%c\"\n", tk, tk);
		error("Invalid expression");
	}

	if (tk < level) {
		return;
	}

	primary = tkval;
	primarytype = tkvaltype;
	primaryisconst = tkisconst;

	while (tk >= level) { // precedence climbing
		tmp = tkvaltype;
		if (tk == TK_ASSIGN) {
			if (primaryisptr) {
				if (!primaryisconst) {
					*expr = IR_PUSH;
				} else {
					expr--;
				}
				d = expr;
				tk_next();
				expression(TK_ASSIGN);
				if (tkisconst) {
					expr = d;
					if (primaryisconst) { // indirect const = const
						expr--;
						if ((primarytype & T_MASK) == T_LONG) {
							*++expr = IR_IMM_32;
							*++expr = tkval;
							*++expr = tkval >> 24;
						} else {
							*++expr = IR_IMM;
							*++expr = tkval;
						}
						*++expr = IR_STORE_GLOBAL;
						*++expr = primary;
					} else { // indirect var = const
						*expr = IR_EX_SEC_PRI;
						if ((primarytype & T_MASK) == T_LONG) {
							*++expr = IR_IMM_32;
							*++expr = tkval;
							*++expr = tkval >> 24;
						} else {
							*++expr = IR_IMM;
							*++expr = tkval;
						}
						*++expr = IR_STORE;
					}
				} else {
					if (primaryisconst) { // indirect const = var
						*++expr = IR_STORE_GLOBAL;
						*++expr = primary;
					} else { // indirect var = var
						*++expr = IR_POP_SEC;
						*++expr = IR_STORE;
					}
				}
				if ((primarytype & T_MASK) == T_STR) {
					*++expr = T_CHAR;
				} else {
					*++expr = primarytype & T_MASK;
				}
			} else {
				if (sym == NULL) {
					error("Invalid variable assignment");
				}
				expr = tmpexpr;
				tk_next();
				expression(TK_ASSIGN);
				if (tkisconst) {
					if (tmp == T_LONG) {
						*++expr = IR_IMM_32;
						*++expr = tkval;
						*++expr = tkval >> 24;
					} else if (tkvaltype == T_STR) {
						*++expr = IR_IMM_PROG_OFFSET;
						*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
					} else {
						*++expr = IR_IMM;
						*++expr = tkval;
					}
				}
				*++expr = (sym->symtype & SYM_GLOBAL) ? IR_STORE_GLOBAL : IR_STORE_LOCAL;
				*++expr = signext(sym->value);
				*++expr = tmp;
			}
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
				*d = make_anon_sym(expr + 3 - exprstart, T_PTR);
				*++expr = IR_JMP;
				d = ++expr;
				expression(TK_COND);
				*d = make_anon_sym(expr + 1 - exprstart, T_PTR);
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
				if (primarytype == T_LONG) {
					*++expr = IR_PUSH_32;
				} else {
					*++expr = IR_PUSH;
				}
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
				if (tkisconst) {
#ifdef PLATFORM_DESKTOP
					if (primarytype == T_LONG && (outformat == FMT_BOS || outformat == FMT_CE))
#else
					if (primarytype == T_LONG)
#endif
					{
						*expr = IR_IMM_32_SEC; // load secondary instead of push / load pri / pop sec / ex
						*++expr = tkval;
						*++expr = tkval >> 24;
						*++expr = tmp + IR_OR - TK_OR;
					} else {
						*expr = tmp + IR_OR_CONST - TK_OR; // constant operation instead of push / load pri / pop sec / ex / operation
						*++expr = tkval;
					}
					primaryisconst = false;
				} else {
					if (primarytype == T_LONG) {
						*++expr = IR_POP_32;
					} else {
						*++expr = IR_POP_SEC;
					}
					*++expr = tmp + IR_OR - TK_OR;
				}
			}
		} else if (tk == TK_INC || tk == TK_DEC) {
			if (*expr >= IR_LOAD_CHAR && *expr <= IR_LOAD_LONG) {
				if (sym == NULL) {
					error("Invalid value for post increment/decrement");
				}
				*++expr = (tk == TK_INC) ? IR_INC : IR_DEC;
				*++expr = (sym->symtype & SYM_GLOBAL) ? IR_STORE_GLOBAL : IR_STORE_LOCAL;
				*++expr = signext(sym->value);
				*++expr = tkvaltype & T_MASK;
				primaryisconst = false;
			} else {
				error("Invalid value for post increment/decrement");
			}
			tk_next();
		} else {
			error("Invalid syntax");
		}
	}
	tkval = primary;
	tkvaltype = primarytype;
	tkisconst = primaryisconst;
}

void compile(void);

int statement(int stackdepth) {
	_ptr *a, *b;
	// printf("tk=0x%X\n", tk);
	if (tk == TK_ID && tksym != NULL && tksym->valtype == T_TYPEDEF) {
		symbol *sym;
		uint8_t bt = tksym->value;
		tk_next();
		while (tk != ';') {
			uint8_t ty = bt;
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
			sym = add_sym(tkname, tknamelen, SYM_LOCAL, ty, 0);
			tk_next();
			if (tk == '[') {
				tk_next();
				if (tk == TK_NUM) {
					sym->datalen = tkval;
				} else if (tksym != NULL) {
					if (!(tksym->symtype & SYM_CONSTANT)) {
						error("Local array length initializer must be constant");
					}
					sym->datalen = tksym->value;
				} else {
					error("Invalid local declaration");
				}
				stackdepth -= sym->datalen * ((sym->valtype>=T_PTR)?T_INT:(sym->valtype & T_MASK));
				sym->valtype |= T_INLINE_DATA;
				tk_next();
				if (tk != ']') {
					error("Missing closing bracket");
				}
				tk_next();
			} else if ((ty & T_MASK) <= T_LONG) {
				stackdepth -= (ty & T_MASK);
			}
			sym->value = stackdepth;
			if (tk == TK_ASSIGN) {
				tk_next();
				// printf("tk=0x%X\"%c\"\n", tk, tk);
				if (tk == TK_NUM) {
					if (sym->valtype & T_INLINE_DATA) {
						error("Invalid local initializer for inline data local");
					}
					if ((sym->valtype & T_MASK) == T_LONG) {
						*++expr = IR_IMM_32;
						*++expr = tkval;
						*++expr = tkval >> 24;
					} else {
						*++expr = IR_IMM;
						*++expr = tkval;
					}
					*++expr = IR_STORE_LOCAL;
					*++expr = signext(sym->value);
					*++expr = sym->valtype & T_MASK;
					tk_next();
				} else if (tk == TK_STR) {
					*++expr = IR_IMM_PROG_OFFSET;
					*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
					if (sym->valtype & T_INLINE_DATA) {
						*++expr = IR_EX_SEC_PRI;
						*++expr = IR_LEA_LOCAL;
						*++expr = signext(sym->value);
						*++expr = IR_STRCPY;
					} else if ((sym->valtype & T_MASK) == T_STR) {
						*++expr = IR_STORE_LOCAL;
						*++expr = signext(sym->value);
						*++expr = sym->valtype & T_MASK;
					} else {
						error("Invalid local type for string initializer");
					}
					tk_next();
				} else if (tk == '{') {
					tk_next();
					do {
						if (tk == TK_NUM) {
							if ((sym->valtype & T_MASK) == T_LONG) {
								*++expr = IR_IMM_32;
								*++expr = tkval;
								*++expr = tkval >> 24;
							} else {
								*++expr = IR_IMM;
								*++expr = tkval;
							}
							*++expr = sym->value;
							*++expr = sym->valtype & T_MASK;
						} else if (tk == TK_STR) {
							if ((sym->valtype & T_MASK) == T_LONG) {
								error("Invalid local type for string array initializer");
							}
							*++expr = IR_IMM_PROG_OFFSET;
							*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
						} else {
							error("Invalid value in local initializer array");
						}
						tk_next();
						if (tk == ',') {
							tk_next();
							if (tk == '}') {
								error("Expected value following comma in local initializer array");
							}
						}
					} while (tk != '}');
					tk_next();
				} else {
					error("Invalid local initializer");
				}
			}
			if (tk == ',') {
				tk_next();
				if (tk == ';') {
					error("Missing local declaration following comma");
				}
			}
		}
	} else if (tk == TK_IF) {
		tk_next();
		if (tk != '(') {
			error("Missing open parenthesis");
		}
		tk_next();
		expression(TK_ASSIGN);
		if (tk != ')') {
			error("Missing closing parenthesis");
		}
		tk_next();
		*++expr = IR_BNZ;
		b = ++expr;
		stackdepth = statement(stackdepth);
		if (tk == TK_ELSE) {
			*b = make_anon_sym(expr + 3 - exprstart, T_PTR);
			*++expr = IR_JMP;
			b = ++expr;
			tk_next();
			stackdepth = statement(stackdepth);
		}
		*b = make_anon_sym(expr + 1 - exprstart, T_PTR);
	} else if (tk == TK_WHILE) {
		uint8_t while_expression_is_const = 0;
		tk_next();
		a = expr + 1;
		if (tk != '(') {
			error("Missing open parenthesis");
		}
		tk_next();
		expression(TK_ASSIGN);
		if (tkisconst) {
			// printf("Optimizing while(constant)\n");
			while_expression_is_const = (tkval>0)?2:1;
		}
		if (tk != ')') {
			error("Missing closing parenthesis");
		}
		tk_next();
		if (while_expression_is_const == 0) {
			*++expr = IR_BNZ;
			b = ++expr;
		}
		if (tk != ';') {
			stackdepth = statement(stackdepth);
		}
		if (while_expression_is_const == 1) {
			// printf("Optimizing while(false)\n");
			expr = b; // rewind body of while(0)
		}
		*++expr = IR_JMP; // jump back to start of loop
		*++expr = make_anon_sym(a - exprstart, T_PTR);
		if (while_expression_is_const == 0) {
			*b = make_anon_sym(expr + 1 - exprstart, T_PTR); // set exit jump location for non-constant while
		}
	} else if (tk == TK_DO) {
		tk_next();
		a = expr + 1;
		if (tk == '{') {
			tk_next();
			while (tk != '}') {
				stackdepth = statement(stackdepth);
			}
		} else if (tk != ';') {
			stackdepth = statement(stackdepth);
		}
		tk_next();
		if (tk != TK_WHILE) {
			error("Missing while in do ... while loop.");
		}
		tk_next();
		if (tk != '(') {
			error("Missing open parenthesis");
		}
		tk_next();
		expression(TK_ASSIGN);
		if (tk != ')') {
			error("Missing closing parenthesis");
		}
		tk_next();
		if (tk != ';') {
			error("Missing semicolon");
		}
		tk_next();
		*++expr = IR_BZ;
		*++expr = make_anon_sym(a - exprstart, T_PTR);
	} else if (tk == TK_RETURN) {
		tk_next();
		// printf("Parsing return statement\n");
		if (tk != ';') {
			expression(TK_ASSIGN);
		}
		if (tkisconst) {
			if (tkvaltype == T_STR) {
				*++expr = IR_IMM_PROG_OFFSET;
				*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
			} else if (tkvaltype == T_LONG) {
				*++expr = IR_IMM_32;
				*++expr = tkval;
				*++expr = tkval >> 24;
			} else {
				*++expr = IR_IMM;
				*++expr = tkval;
			}
		}
		*++expr = IR_LEAVE;
		if (tk != ';') {
			error("Missing semicolon");
		}
		tk_next();
	} else if (tk == '{') {
		save_sym_stack();
		tk_next();
		while (tk != '}') {
			stackdepth = statement(stackdepth);
		}
		tk_next();
		free_local_symbols();
	} else if (tk == ';') {
		tk_next();
	} else {
		expression(TK_ASSIGN);
		if (tk != ';') {
			error("Missing semicolon");
		}
		tk_next();
	}
	return stackdepth;
}

void precompile(void) {
	if ((symtable = _malloc(sizeof(symbol))) == NULL) {
		error("Failed to malloc space for initial symbol");
	}
	if ((data_resolve_stack = _malloc(sizeof(int) * DATA_RESOLVE_STACK_SIZE)) == NULL) {
		error("Failed to malloc space for data resolution stack");
	}
	if ((localsymstack = _malloc(sizeof(symbol*) * SYM_STACK_SAVE_SIZE)) == NULL) {
		error("Failed to malloc space for symbol stack local save stack");
	}
	if ((resolvestack = resolvestackstart = _malloc(RESOLVE_STACK_SIZE*sizeof(_ptr))) == NULL) {
		error("Failed to malloc space for address resolution stack\n");
	}
	memset(symtable, 0, sizeof(symbol));
	memset(localsymstack, 0, sizeof(symbol*) * SYM_STACK_SAVE_SIZE);
#ifdef PLATFORM_DESKTOP
	if (outformat == FMT_BOS || outformat == FMT_CE) {
		reverse_argument_stack = true;
#endif
	add_sym("bool", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_BOOL);
	add_sym("void", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_VOID);
	add_sym("unsigned", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_INT);
	add_sym("char", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
	add_sym("short", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
	add_sym("int", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_INT);
	add_sym("long", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
	add_sym("uint8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
	add_sym("uint16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
	add_sym("uint24_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_INT);
	add_sym("uint32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
	add_sym("int8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
	add_sym("int16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
	add_sym("int24_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_INT);
	add_sym("int32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
#ifdef PLATFORM_DESKTOP
	} else if (outformat == FMT_BXS2307) {
		add_sym("bool", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_BOOL);
		add_sym("void", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_VOID);
		add_sym("unsigned", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("char", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
		add_sym("short", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("int", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("long", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym("uint8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
		add_sym("uint16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("uint32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym("int8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
		add_sym("int16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("int32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
	} else if (outformat == FMT_BXS2320) {
		add_sym("bool", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_BOOL);
		add_sym("void", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_VOID);
		add_sym("unsigned", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym("char", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
		add_sym("short", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("int", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym("long", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym("uint8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
		add_sym("uint16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("uint32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym("int8_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_CHAR);
		add_sym("int16_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_WORD);
		add_sym("int32_t", 0, SYM_CONSTANT|SYM_RESOLVED, T_TYPEDEF, T_LONG);
		add_sym_function("memcpy", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_memcpy", (uint8_t[]){3, T_PTR+T_VOID, T_PTR+T_VOID, T_LONG});
		add_sym_function("rmemcpy", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_rmemcpy", (uint8_t[]){3, T_PTR+T_VOID, T_PTR+T_VOID, T_LONG});
		add_sym_function("strlen", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_INT, "_strlen", (uint8_t[]){1, T_PTR+T_CHAR});
		add_sym_function("strcpy", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_strcpy", (uint8_t[]){2, T_PTR+T_CHAR, T_PTR+T_CHAR});
		add_sym_function("strncpy", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_strncpy", (uint8_t[]){3, T_PTR+T_CHAR, T_PTR+T_CHAR, T_LONG});
		add_sym_function("memcmp", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_INT, "_memcmp", (uint8_t[]){3, T_PTR+T_VOID, T_PTR+T_VOID, T_LONG});
		add_sym_function("strcmp", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_INT, "_strcmp", (uint8_t[]){2, T_PTR+T_CHAR, T_PTR+T_CHAR});
		add_sym_function("strncmp", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_INT, "_strncmp", (uint8_t[]){3, T_PTR+T_CHAR, T_PTR+T_CHAR, T_LONG});
		add_sym_function("memset", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_memset", (uint8_t[]){3, T_PTR+T_VOID, T_WORD, T_LONG});
		add_sym_function("memcpy_repeat", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_memcpy_repeat", (uint8_t[]){4, T_PTR+T_VOID, T_WORD, T_LONG, T_LONG});
		add_sym_function("inittty", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_inittty", (uint8_t[]){0});
		add_sym_function("cleartty", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_cleartty", (uint8_t[]){0});
		add_sym_function("print", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_print", (uint8_t[]){2, T_PTR+T_CHAR, T_WORD});
		add_sym_function("printchar", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_printchar", (uint8_t[]){2, T_CHAR, T_WORD});
		add_sym_function("printcharat", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_printcharat", (uint8_t[]){3, T_CHAR, T_WORD, T_WORD});
		add_sym_function("printline", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_printline", (uint8_t[]){2, T_PTR+T_CHAR, T_WORD});
		add_sym_function("printint", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_printint", (uint8_t[]){2, T_LONG, T_WORD});
		add_sym_function("printuint", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_printuint", (uint8_t[]){2, T_LONG, T_WORD});
		add_sym_function("settextxy", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_settextxy", (uint8_t[]){2, T_CHAR, T_CHAR});
		add_sym_function("nextcol", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_nextcol", (uint8_t[]){0});
		add_sym_function("newline", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_VOID, "_newline", (uint8_t[]){0});
		add_sym_function("getkey", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_CHAR, "_getkey", (uint8_t[]){0});
		add_sym_function("waitkey", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_CHAR, "_waitkey", (uint8_t[]){0});
		add_sym_function("waitkeycycle", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_CHAR, "_waitkeycycle", (uint8_t[]){0});
		add_sym_function("verticalmenu", 0, SYM_CONST_FUNCTION|SYM_RESOLVED, T_WORD, "_menu", (uint8_t[]){1, T_PTR+T_VOID});
		add_sym("sk_down", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 1);
		add_sym("sk_left", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 2);
		add_sym("sk_right", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 3);
		add_sym("sk_up", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 4);
		add_sym("sk_a", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 8);
		add_sym("sk_b", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 9);
		add_sym("sk_x", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 10);
		add_sym("sk_y", 0, SYM_CONSTANT|SYM_RESOLVED, T_LONG, 11);
	}
#endif
}

void resolve_later(unsigned int offset, symbol *val) {
	*resolvestack++ = val;
	*resolvestack++ = offset;
}

void postcompile(void) {
	if (*expr != IR_EXIT && *expr != IR_LEAVE) {
		*++expr = IR_EXIT;
	}
	expr++;
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
	_ptr *stackdepthloc;
	uint8_t bt, ty;
	int i;
	lno = 1;
	tk_next();
	while (tk) {
		if (tk == TK_INCLUDE) {
			unsigned int i, savedsrcoffset, savedsrclen, savedlno;
			char *fname, *savedsrc, ch;
#ifdef PLATFORM_DESKTOP
			FILE *fd;
#else
#ifdef BOS_BUILD
			void *fd;
#else
			uint8_t fd;
#endif
#endif
			tk_next();
			i = srcoffset;
			if (tk == TK_LT) {
#ifdef PLATFORM_DESKTOP
				error("#include <> not yet implemented on this platform");
#else
#ifndef BOS_BUILD
				error("#include <> not yet implemented on this platform");
#endif
#endif
				while ((ch = srcdata[srcoffset++]) != '>') {
					if (ch == '\n') {
						error("Unexpected line break");
					}
				}
				if (srcoffset-i <= 1) {
					error("Invalid #include file name");
				}
				if ((fname = _malloc(srcoffset+1-i)) == NULL) {
					error("Out of memory");
				}
				memcpy(fname, &srcdata[i], srcoffset-i);
				fname[srcoffset-i] = 0;
			} else if (tk == TK_STR) {
				fname = tkvalstr;
			} else {
				error("Invalid #include statement");
			}
			while (getchar() != '\n');
			savedsrc = srcdata;
			savedsrcoffset = srcoffset;
			savedsrclen = srclen;
			savedlno = lno;
#ifdef PLATFORM_DESKTOP
			if ((fd = fopen(fname, "r")) == NULL) {
				error("Include file not found");
			}
			fseek(fd, 0, 2);
			srclen = ftell(fd);
			fseek(fd, 0, 0);
			if ((srcdata = _malloc(srclen)) == NULL) {
				error("Out of memory");
			}
			fread(srcdata, srclen, 1, fd);
			fclose(fd);
			printf("Compiling included source file \"%s\"\n", fname);
#else
#ifdef BOS_BUILD
			if ((fd = fs_OpenFile(fname)) == -1) {
				error("Include file not found");
			}
			srcdata = fs_GetFDPtr(fd);
			srclen = fs_GetFDLen(fd);
			gui_Print("Compiling included source \"");
			gui_Print(fname);
			gui_PrintLine("\"");
#else
			if ((fd = ti_Open(fname, "r")) == -1) {
				error("Include file not found");
			}
			srcdata = ti_GetDataPtr(fd);
			srclen = ti_GetSize(fd);
			ti_Close(fd);
			console_printline("Compiling included source");
			console_printline(fname);
#endif
#endif
			srcoffset = lno = 0;
			compile();
#ifdef PLATFORM_DESKTOP
			printf("Finished compiling included file\n");
#else
#ifdef BOS_BUILD
			gui_PrintLine("Finished compiling included file");
#else
			console_printline("Finished compiling included file");
#endif
#endif
			_free(srcdata);
			_free(fname);
			srcdata = savedsrc;
			srcoffset = savedsrcoffset;
			srclen = savedsrclen;
			lno = savedlno + 1;
			goto nexttoken;
		} else if (tk == TK_ENUM) {
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
			// printf("tk=0x%X\n", tk);
			goto nexttoken;
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
			sym = add_sym(tkname, tknamelen, SYM_GLOBAL, ty, 0);
			tk_next();
			// printf("tk = %X \"%c\"\n", tk, tk);
			if (tk == '[') {
				tk_next();
				sym->value = globaladdr;
				if (tk == TK_NUM) {
					globaladdr += tkval * ((sym->valtype>=T_PTR)?T_INT:(sym->valtype & T_MASK));
				} else if (tksym != NULL) {
					if (!(tksym->symtype & SYM_CONSTANT)) {
						error("Global array length initializer must be constant");
					}
					globaladdr += tksym->value * ((sym->valtype>=T_PTR)?T_INT:(sym->valtype & T_MASK));
				} else {
					error("Invalid global declaration");
				}
				sym->valtype |= T_INLINE_DATA;
				tk_next();
				if (tk != ']') {
					error("Missing closing bracket");
				}
				tk_next();
			} else if (tk == '(') { // function declaration
				save_sym_stack();
				sym->symtype = SYM_FUNCTION;
				sym->value = expr + 1 - exprstart;
				sym->functionargs = _malloc(FUNCTION_MAX_NUM_ARGS+1);
#ifdef DEBUG
				printf("Function offset 0x%llX\n", expr + 1 - exprstart);
#endif
				*++expr = IR_DEFINE_FUNCTION;
				*++expr = sym;
				tk_next();
				stackdepth = nargs = 0;
				argdepth = 6;
				while (tk != ')') {
					// printf("Parsing function parameter\n");
					ty = T_INT;
					if (tk == TK_ID && tksym != NULL && tksym->valtype == T_TYPEDEF) {
						ty = tksym->value;
						tk_next();
					}
					while (tk == TK_MUL) {
						tk_next();
						ty += T_PTR;
					}
					if (ty == T_VOID && argdepth == 6 && tk == ')') {
						break;
					}
					// printf("parsed parameter with type 0x%X\n", ty);
					if (tk != TK_ID) {
						error("Invalid parameter declaration");
					}
					if (tksym != NULL && (tksym->symtype & SYM_LOCAL)) {
						// printf("Parameter name: \"%s\"\n", tksym->name);
						error("Duplicate parameter declaration");
					}
					add_sym(tkname, tknamelen, SYM_LOCAL, ty, argdepth);
					// printf("added local symbol with type 0x%X name \"%s\"\n", ty, tksym->name);
					sym->functionargs[++nargs] = ty;
					if ((ty & T_MASK) == T_LONG) {
						argdepth += 6;
					} else {
						argdepth += 3;
					}
					tk_next();
					if (tk == ',') {
						tk_next();
						if (tk == ')') {
							error("Missing argument declaration following comma");
						}
					}
				}
				// printf("Parsed %u function parameters\n", nargs);
				sym->functionargs[0] = nargs;
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
					} else if (tk != ';') {
						error("Missing semicolon following function prototype");
					}
					goto nexttoken;
				} else {
					tk_next();
					// printf("Function start\n");

					*++expr = IR_ENTER;
					*++expr = 0;
					stackdepthloc = expr;
					while (tk != '}') {
						// printf("Reading function statement\n");
						stackdepth = statement(stackdepth);
					}
					// printf("Function end\n");
					*stackdepthloc = stackdepth;
					if (*expr != IR_EXIT && *expr != IR_LEAVE) {
						*++expr = IR_LEAVE;
					}
				}
#ifdef DEBUG
				printf("Freeing locals\n");
#endif
				free_local_symbols();
#ifdef DEBUG
				printf("Freed locals\n");
#endif
				goto nexttoken;
			} else {
				sym->value = globaladdr;
				if (ty & T_INLINE_DATA) {
					globaladdr += sym->datalen;
				} else if ((ty & T_MASK) > 0) {
					globaladdr += (ty & T_MASK);
				} else if (ty >= T_PTR) {
					globaladdr += 3;
				} else {
					error("Invalid global declaration");
				}
			}
			if (tk == TK_ASSIGN) {
				tk_next();
				// printf("tk=0x%X\"%c\"\n", tk, tk);
				if (tk == TK_NUM) {
					if (sym->valtype & T_INLINE_DATA) {
						error("Invalid global initializer for inline data global");
					}
					if ((sym->valtype & T_MASK) == T_LONG) {
						*++expr = IR_IMM_32;
						*++expr = tkval;
						*++expr = tkval >> 24;
					} else {
						*++expr = IR_IMM;
						*++expr = tkval;
					}
					*++expr = IR_STORE_GLOBAL;
					*++expr = signext(sym->value);
					*++expr = sym->valtype & T_MASK;
					tk_next();
				} else if (tk == TK_STR) {
					*++expr = IR_IMM_PROG_OFFSET;
					*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
					if (sym->valtype & T_INLINE_DATA) {
						*++expr = IR_EX_SEC_PRI;
						*++expr = IR_LEA_GLOBAL;
						*++expr = signext(sym->value);
						*++expr = IR_STRCPY;
					} else if ((sym->valtype & T_MASK) == T_STR) {
						*++expr = IR_STORE_GLOBAL;
						*++expr = signext(sym->value);
						*++expr = sym->valtype & T_MASK;
					} else {
						error("Invalid local type for string initializer");
					}
					tk_next();
				} else if (tk == '{') {
					unsigned int counter = 0;
					tk_next();
					do {
						if (tk == TK_NUM) {
							if ((sym->valtype & T_MASK) == T_LONG) {
								*++expr = IR_IMM_32;
								*++expr = tkval;
								*++expr = tkval >> 24;
							} else {
								*++expr = IR_IMM;
								*++expr = tkval;
							}
							*++expr = sym->value;
							*++expr = sym->valtype & T_MASK;
						} else if (tk == TK_STR) {
							if ((sym->valtype & T_MASK) == T_LONG) {
								error("Invalid type for global string array initializer");
							}
							*++expr = IR_IMM_PROG_OFFSET;
							*++expr = make_anon_sym_str(expr+1-exprstart, tkvalstr, tkvallen);
						} else {
							error("Invalid value in global initializer array");
						}
						counter++;
						tk_next();
						if (tk == ',') {
							tk_next();
							if (tk == '}') {
								error("Expected value following comma in global initializer array");
							}
						}
					} while (tk != '}');
				} else {
					error("Invalid global initializer");
				}
			}
		}
	nexttoken:;
		tk_next();
	}
}

void try_resolve_symbols_generic(unsigned int offset) {
	symbol *sym;
	if ((sym = symtable) == NULL) {
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
		if (sym->value == offset) {
			out += sprintf(out, "label .s_%llu\n", (_ptr)sym);
		}
	} while ((sym = sym->prev));
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
		if (!(sym->symtype & SYM_RESOLVED)) {
			if (sym->value >= (data_start - exprstart)) {
				sym->symtype |= SYM_RESOLVED;
				//printf("Symbol %s value %X\n", (char*)&sym->name, sym->value);
				sym->resolved_value = PROGRAM_ORIGIN + (out - outstart) + sym->value - (data_start - exprstart);
			}
		}
		sym = sym->prev;
	}

#ifdef PLATFORM_DESKTOP
	if (outformat == FMT_BOS || outformat == FMT_CE) {
#endif
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
					//printf("Symbol name: \"%s\"\n", (char*)&sym->name);
					//printf("Symbol value: %u\n", sym->value);
					//printf("Symbol type: 0x%X\n", sym->valtype);
					//printf("Output offset: %u\n", offset);
					//printf("data_start-exprstart = %llu\n", data_start - exprstart);
					error("Internal: Failed to resolve symbol in assembly step");
				}
			}
		}
#ifdef PLATFORM_DESKTOP
	}
#endif
	if (expr > data_start) {
#ifdef PLATFORM_DESKTOP
		if (outformat == FMT_BOS || outformat == FMT_CE) {
#endif
			for (unsigned int i = 0; i < expr-data_start; i++) {
				*out++ = data_start[i];
			}
#ifdef PLATFORM_DESKTOP
		} else {
			if (outformat == FMT_BXS2307 || outformat == FMT_BXS2320) {
				for (unsigned int i = 0; i < expr-data_start; i++) {
					try_resolve_symbols_generic(&data_start[i] - exprstart);
					out += sprintf(out, "dw $%X\n", (uint16_t)data_start[i]);
				}
			} else {
				for (unsigned int i = 0; i < expr-data_start; i++) {
					try_resolve_symbols_generic(&data_start[i] - exprstart);
					out += sprintf(out, "db $%X\n", (uint8_t)data_start[i]);
				}
			}
		}
#endif
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

#include "platform/ez80gen.h"

#ifdef PLATFORM_DESKTOP
#include "platform/BxS2307gen.h"
#include "platform/BxS2320gen.h"

void assemble(void) {
	if (outformat == FMT_BOS || outformat == FMT_CE) {
		assemble_eZ80();
	} else if (outformat == FMT_BXS2307) {
		assemble_BxS2307();
	} else if (outformat == FMT_BXS2320) {
		assemble_BxS2320();
	}
}
#else
#define assemble assemble_eZ80
#endif

int main(int argc, char **argv) {
	unsigned int exprlen, datalen;
#ifdef PLATFORM_DESKTOP
	unsigned int bufferlen;
	FILE *fd;
	char *buffer, *afile = "a.asm", *bfile = "a.out";
	_ptr oldopcode;
	if (argc < 2) {
		printf("Usage: %s src [-o bin] [-f [BOS|CE|BxS2307|BxS2320]]\n", argv[0]);
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

	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-o")) {
			if (++i < argc) {
				bfile = argv[i];
			} else {
			missingargument:;
				printf("Missing argument following %s\n", argv[i-1]);
			}
		} else if (!strcmp(argv[i], "-a")) {
			if (++i < argc) {
				afile = argv[i];
			} else {
				goto missingargument;
			}
		} else if (!strcmp(argv[i], "-f")) {
			if (++i < argc) {
				if (!strcmp(argv[i], "BOS")) {
					outformat = FMT_BOS;
				} else if (!strcmp(argv[i], "CE")) {
					outformat = FMT_CE;
				} else if (!strcmp(argv[i], "BxS2307")) {
					outformat = FMT_BXS2307;
				} else if (!strcmp(argv[i], "BxS2320")) {
					outformat = FMT_BXS2320;
				} else {
					printf("Unknown output format specifier \"%s\"\n", argv[i]);
					return 0;
				}
			} else {
				goto missingargument;
			}
		}
	}

	if ((expr = exprstart = _malloc(IR_OUTPUT_SIZE * sizeof(_ptr))) == NULL) {
		printf("Failed to malloc %u bytes of space for IR output.\n", (unsigned int)(IR_OUTPUT_SIZE * sizeof(_ptr)));
		return 1;
	}
	srcoffset = 0;
	expr--;
	precompile();
	compile();
	postcompile();
	exprlen = data_start - exprstart;
	datalen = expr - data_start;
	printf("Compiled %u bytes of IR.\n", (unsigned int)(exprlen*sizeof(_ptr)));

	if ((buffer = _malloc(exprlen * 32 + datalen * 4)) == NULL) {
		printf("Failed to malloc %u bytes of space for file output buffer.\n", exprlen * 32 + datalen * 4);
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
			printf("%u: %llu %d %s\n", i, opcode, nargs, IR_STRINGS[opcode]);
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
			} else {
				bufferlen += sprintf(&buffer[bufferlen], "$%-6X: ", i);
			}
			memcpy(&buffer[bufferlen], IR_STRINGS[opcode], strlen(IR_STRINGS[opcode]));
			bufferlen += strlen(IR_STRINGS[opcode]);
			if (nargs > 0) {
				buffer[bufferlen++] = ' ';
				if (opcode == IR_DEFINE_FUNCTION || opcode == IR_CALL || opcode == IR_JMP || opcode == IR_BZ || opcode == IR_BNZ || opcode == IR_IMM_PROG_OFFSET) {
					symbol *tmpsym = exprstart[i+1];
					if ((tmpsym->symtype & SYM_MASK) == SYM_CONST_FUNCTION) {
						bufferlen += sprintf(&buffer[bufferlen], "\"%s\", ", (char*)tmpsym->resolved_value);
					} else if (tmpsym->name[0] == 0) {
						bufferlen += sprintf(&buffer[bufferlen], "$%llX, ", tmpsym->value);
					} else if (tmpsym->symtype & SYM_RESOLVED) {
						bufferlen += sprintf(&buffer[bufferlen], "\"%s\", $%llX, ", tmpsym->name, tmpsym->resolved_value);
					} else {
						bufferlen += sprintf(&buffer[bufferlen], "\"%s\", ", tmpsym->name);
					}
					if (opcode == IR_DEFINE_FUNCTION) {
						bufferlen += sprintf(&buffer[bufferlen], "$%llX, ", tmpsym->value);
					}
				}
				while (nargs > 0) {
					int arglen;
					i++;
					nargs--;
					if ((uint32_t)(-exprstart[i]) < 65536 && (uint32_t)(exprstart[i]) > 0) {
						arglen = sprintf(&buffer[bufferlen], "-$%X", (uint32_t)-exprstart[i]);
					} else {
						arglen = sprintf(&buffer[bufferlen], "$%X", (uint32_t)exprstart[i]);
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

	if ((fd = fopen(afile, "w")) == NULL) {
		printf("Failed to open destination file \"%s\".\n", afile);
		return -2;
	}
	fwrite(buffer, bufferlen, 1, fd);
	fclose(fd);
	
	printf("Wrote %u bytes of IR assembly to \"%s\".\n", bufferlen, afile);

	if (argc >= 4) {
		char *atype = "eZ80";
		if ((out = outstart = _malloc(OUTPUT_BUFFER_SIZE)) == NULL) {
			printf("Failed to malloc %u bytes of space for output buffer\n", OUTPUT_BUFFER_SIZE);
			return 1;
		}
		assemble();
		postassemble();
		if ((fd = fopen(bfile, "wb")) == NULL) {
			printf("Failed to open destination file \"%s\"\n", bfile);
			return -2;
		}
		fwrite(outstart, out-outstart, 1, fd);
		fclose(fd);
		if (outformat == FMT_BXS2307) {
			atype = "BxS2307";
		} else if (outformat == FMT_BXS2320) {
			atype = "BxS2320";
		}
		printf("Wrote %lld bytes of %s assembly to \"%s\"\n", out-outstart, atype, bfile);
	}
#else
#define OUT_BUFFER_LOC 0xD52C00
#define EXPR_BUFFER_LOC (OUT_BUFFER_LOC+0x8000)

#ifdef BOS_BUILD
	void *fd;
	if (argc < 2) {
		gui_PrintLine("Usage: bcc src [bin]");
		return 0;
	}
	if ((fd = fs_OpenFile(argv[1])) == -1) {
		gui_PrintLine("Source file not found.");
		return -1;
	}
	srcdata = fs_GetFDPtr(fd);
	srclen = fs_GetFDLen(fd);
	expr = exprstart = EXPR_BUFFER_LOC;
	precompile();
	compile();
	postcompile();
	exprlen = data_start - exprstart;
	datalen = expr - data_start;
	outstart = out = OUT_BUFFER_LOC;
	assemble();
	postassemble();
	if ((fd = fs_CreateFile(argv[2], 0, out-outstart)) == -1) {
		gui_PrintLine("Failed to create output file.");
		return -2;
	}
	if ((fd = fs_WriteRaw(outstart, out-outstart, 1, fd, 0)) == -1) {
		gui_PrintLine("Failed to write output file.");
		return -2;
	}
	gui_Print("Finished. Output ");
	gui_PrintInt(out-outstart);
	gui_PrintLine(" bytes");
#else
	uint8_t fd;

    // Enable lowercase
    asm("ld iy, 0D00080h");
    asm("set 3, (iy+024h)");

	gfx_Begin();
	console_printline("Beck's C Compiler");
	if (argc < 2) {
		console_printline("Usage: \"src bin\":prgmBCC");
		goto endmain;
	}
	console_printline("Compiling");
	gfx_PrintString(argv[1]);
	if ((fd = ti_Open(argv[1], "r"))) {
		srcdata = ti_GetDataPtr(fd);
		srclen = ti_GetSize(fd);
		ti_Close(fd);
	} else if ((fd = ti_OpenVar(argv[1], "r", 5))) {
		srcdata = ti_GetDataPtr(fd);
		srclen = ti_GetSize(fd);
		ti_Close(fd);
		console_printline("Detokenizing program source");
		if ((fd = ti_Open("_bcctmp_", "w"))) {
			uint8_t *ptr = srcdata;
			uint8_t *end = &srcdata[srclen];
			outstart = out = OUT_BUFFER_LOC;
			while (ptr < end) {
				unsigned int slen;
				if (*ptr == 0x3F) { // convert TI newlines to semicolon followed by ASCII newline
					*out++ = ';';
					*out++ = '\n';
					ptr++;
				} else if (*ptr == 0x6) { // token string for open brace is 0xC1 (TI ASCII) and we need ASCII
					*out++ = '[';
					ptr++;
				} else if ((unsigned)*ptr-'A' < 26) { // convert uppercase to lowercase
					*out++ = *ptr++ + 'a' - 'A';
				} else if (*ptr == 'A'+27) { // convert Theta to underscore
					*out++ = '_';
					ptr++;
				} else { // otherwise use the token string
					char *s = ti_GetTokenString(&ptr, NULL, &slen);
					if (slen > 0) {
						memcpy(out, s, slen);
						if ((unsigned)*out-'A' < 26) { // support While token and whatnot
							*out = *out + 'a' - 'A';
						}
						out += slen;
					}
				}
			}
			// probably no need to archive the tokenized source, since we aren't using usermem for compilation
			// and by the time it would be archived, we know there's enough usermem to contain it.
			/*
			if (!ti_ArchiveHasRoom(out-outstart)) {
				ti_Close(fd);
				console_printline("Not enough space in archive");
				console_printline("Please run GarbageCollect");
				goto endmain;
			}
			*/
			ti_Write(outstart, out-outstart, 1, fd);
			//ti_SetArchiveStatus(1, fd);
			ti_Rewind(fd);
			srcdata = ti_GetDataPtr(fd);
			srclen = ti_GetSize(fd);
			ti_Close(fd);
			console_printline("Finished Detokenizing");
		} else {
			console_printline("Failed to open temp appvar _bcctmp_");
			goto endmain;
		}
	} else {
		console_printline("Source file not found.");
		goto endmain;
	}
	expr = exprstart = EXPR_BUFFER_LOC;
	precompile();
	compile();
	postcompile();
	exprlen = data_start - exprstart;
	datalen = expr - data_start;
	outstart = out = OUT_BUFFER_LOC;
	assemble();
	postassemble();
	ti_SetGCBehavior(gfx_End, gfx_Begin);
	if ((fd = ti_OpenVar(argv[2], "w", 6))) {
		ti_Write(outstart, out-outstart, 1, fd);
		ti_SetArchiveStatus(1, fd);
		ti_Close(fd);
		console_printline("Finished. Output ");
		gfx_PrintUInt(out-outstart, 0);
		gfx_PrintString(" bytes");
	} else {
		console_printline("Failed to create output file.");
	}
	ti_Delete("_bcctmp_");
endmain:;
	while (!os_GetCSC());
	gfx_End();
#endif
#endif
	return 0;
}

