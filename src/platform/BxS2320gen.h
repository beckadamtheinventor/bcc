
#include "include/emitf.h"

void try_resolve_symbols_BxS2320(unsigned int offset) {
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
		if (!(sym->symtype & SYM_RESOLVED)) {
			if (sym->value == offset) {
				sym->symtype |= SYM_RESOLVED;
				sym->resolved_value = PROGRAM_ORIGIN + out - outstart;
				EMITL2("label _%llu\n", (_ptr)sym);
			}
		}
	} while ((sym = sym->prev));

//	printf("\n");
}

uint8_t convert_to_zf_BxS2320(uint8_t bt) {
	if (bt == T_BOOL_CF || bt == T_BOOL_NCF) {
		EMITL("ld r8,r1\nand r8,1\n");
		return T_BOOL_ZF;
	}
	if (bt == T_BOOL_NCF) {
		EMITL("xor r8,1\n");
		return T_BOOL_ZF;
	}
	if (bt == T_BOOL_NZF) {
		return T_BOOL_NZF;
	}
	return bt;
}

uint8_t convert_flag_to_char_BxS2320(uint8_t bt, uint8_t rno) {
	if (bt == T_BOOL_CF) {
		EMITL2("flagand -1\nld r%ua,r1a\n", rno);
	} else if (bt == T_BOOL_NCF) {
		EMITL2("flagand -1\nflagxor 1\nld r%ua,r1a\n", rno);
	} else if (bt == T_BOOL_ZF) {
		EMITL3("flagand -2\nld r%ua,r1a\nshri r%ua,1\n", rno, rno);
	} else if (bt == T_BOOL_NZF) {
		EMITL3("flagand -2\nflagxor 2\nld r%ua,r1a\nshri r%ua,1\n", rno, rno);
	}
	return T_CHAR;
}

void assemble_BxS2320(void) {
	int op = 0, oldopcode;
	_ptr arg, *expr = exprstart;
	uint8_t l, bt = T_VOID, *prevout = out, *prevprevout = out;
	int32_t arg32;
	uint8_t rnop = 30, rnos = 31, rarg = 24;
	symbol *sym, *mainsym;

	PROGRAM_ORIGIN = 0;
	lno = 0;

	if ((mainsym = find_sym("main", 0)) == NULL) {
		error("Missing function main()");
	}

	EMITL("jp _main\n_exit := 0\n");

	// expr++;
	while (1) {
		prevprevout = prevout;
		prevout = out;
		try_resolve_symbols_BxS2320(expr - exprstart);
#ifdef DEBUG
		printf("out offset: %llu expr offset: %llu\n", out-outstart, expr-exprstart);
#endif
		oldopcode = op;
		op = *expr++;
		if (expr >= data_start) {
			break;
		}
		arg32 = arg = *expr;
		switch (op) {
			case IR_NOP:
				break;
			case IR_PUSH_ARG:
			case IR_PUSH_ARG_32:
				EMITL3("ld r%u,r%d\n", rarg, rnop);
				rarg++;
				break;
			case IR_PUSH_ARG_IMM:
				expr++;
				EMITL3("ldi r%u,%d\n", rarg, arg32);
				rarg++;
				break;
			case IR_PUSH_ARG_IMM_32:
				expr++;
				expr++;
				EMITL3("ldi r%u,%d\n", rarg, arg32);
				rarg++;
				break;
			case IR_IMM:
				expr++;
				EMITL3("ldi r%u,%lld\n", rnop, arg);
				bt = T_INT;
				break;
			case IR_IMM_PROG_OFFSET:
				expr++;
				EMITL3("ldi r%u,s_%llu\n", rnop, arg);
				bt = T_INT;
				break;
			case IR_IMM_8:
				expr++;
				EMITL3("ldi r%ua,%lld\n", rnop, arg);
				bt = T_CHAR;
				break;
			case IR_IMM_32_SEC:
				expr++;
				EMITL3("ldi r%u,%u\n", rnos, arg32);
				expr++;
				bt = T_LONG;
				break;
			case IR_IMM_32:
				expr++;
				EMITL3("ldi r%u,%u\n", rnop, arg32);
				expr++;
				bt = T_LONG;
				break;
			case IR_PUSH_TER:
			case IR_PUSH_SEC:
				bt = convert_flag_to_char_BxS2320(bt, rnos);
				EMITL2("push r%u\n", rnos);
				break;
			case IR_PUSH:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				EMITL2("push r%u\n", rnop);
				break;
			case IR_PUSH_IMM_32:
			case IR_PUSH_IMM:
				expr++;
				EMITL2("pushl %lld\n", arg);
				break;
			case IR_PUSH_32:
				EMITL2("push r%u\n", rnos);
				break;
			case IR_POP:
				EMITL2("pop r%u\n", rnop);
				break;
			case IR_POP_TER:
			case IR_POP_SEC:
				EMITL2("pop r%u\n", rnos);
				break;
			case IR_POP_32:
				EMITL2("pop r%u\n", rnos);
				break;
			case IR_EX_SEC_PRI:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				EMITL3("ex r%u,r%u\n", rnop, rnos);
				break;
			case IR_CALL:
				expr++;
				EMITL2("call _%s\n", ((symbol*)arg)->name);
				bt = ((symbol*)arg)->valtype;
				break;
			case IR_ADJ:
				expr++;
				/*
				if (arg != 0) {
					EMITL2("addi r2,%lld\n", arg/3);
				}
				*/
				rarg = 24;
				break;
			case IR_ENTER:
				expr++;
				EMITL("push r12\nld r12,r2\n");
				if (arg != 0) {
					EMITL2("addi r2,%lld\n", arg);
				}
				break;
			case IR_LEAVE:
				EMITL("ld r2,r12\npop r12\nret\n");
				break;
			case IR_EXIT:
				expr++;
				EMITL("jp _exit\n");
				break;
			case IR_LEA_LOCAL:
				expr++;
				if (arg32 != 0) {
					if (arg32 >= -128 && arg < 0) {
						l = *expr++;
						if (l == IR_LOAD_CHAR) {
							EMITL3("ild r%ua,r12,%d\n", rnop, arg32);
						} else if (l == IR_LOAD_WORD) {
							EMITL3("ild r%ul,r12,%d\n", rnop, arg32);
						} else if (l == IR_LOAD_LONG || l == IR_LOAD_INT) {
							EMITL3("ild r%u,r12,%d\n", rnop, arg32);
						} else {
							expr--;
							EMITL3("ld r%u,r12,%d\n", rnop, arg32);
						}
					} else if (arg32 >= 0 && arg32 < 6*3) {
						l = *expr++;
						if (l == IR_LOAD_CHAR) {
							EMITL3("ld r%ua,r%ua\n", rnop, 24+arg32/3);
						} else if (l == IR_LOAD_WORD) {
							EMITL3("ld r%ul,r%ul\n", rnop, 24+arg32/3);
						} else if (l == IR_LOAD_LONG || l == IR_LOAD_INT) {
							EMITL3("ld r%u,r%u\n", rnop, 24+arg32/3);
						} else {
							error("Internal: Can't get address-of register");
						}
					} else {
						EMITL2("ld r%u,r12\n", rnop);
						EMITL3("add r%u,%d\n", rnop, arg32);
						bt = T_PTR;
					}
				} else {
					EMITL2("ld r%u,r12\n", rnop);
					bt = T_PTR;
				}
				break;
			case IR_LEA_GLOBAL:
				expr++;
				EMITL3("ldi r%u,%u\n", rnop, arg32);
				break;
			case IR_STORE_LOCAL:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				l = *expr++;
				if (arg32 >= -128 && arg32 < 128) {
					if (l == T_CHAR) {
						EMITL3("str r%ua,r12,%d\n", rnop, arg32);
					} else if (l == T_WORD) {
						EMITL3("str r%ul,r12,%d\n", rnop, arg32);
					} else {
						EMITL3("str r%u,r12,%d\n", rnop, arg32);
					}
				} else {
					EMITL2("ld r8,r12\nadd r8,%d\n", arg32);
					if (l == T_CHAR) {
						EMITL2("str r%ua,r8\n", rnop);
					} else if (l == T_WORD) {
						EMITL2("str r%ul,r8\n", rnop);
					} else {
						EMITL2("str r%u,r8\n", rnop);
					}
				}
				break;
			case IR_STORE_GLOBAL:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				l = *expr++;
				if (l == T_CHAR) {
					EMITL3("sto r%ua,$%X\n", rnop, arg32);
				} else if (l == T_WORD) {
					EMITL3("sto r%ul,$%X\n", rnop, arg32);
				} else {
					EMITL3("sto r%u,$%X\n", rnop, arg32);
				}
				break;
			case IR_LOAD_CHAR:
				EMITL3("ildr r%ua,r%u\n", rnop, rnop);
				bt = T_CHAR;
				break;
			case IR_LOAD_WORD:
				EMITL3("ildr r%ul,r%u\n", rnop, rnop);
				bt = T_WORD;
				break;
			case IR_LOAD_INT:
			case IR_LOAD_LONG:
				EMITL3("ildr r%u,r%u\n", rnop, rnop);
				bt = T_LONG;
				break;
			case IR_COMPARE_Z:
				if (bt < T_BOOL_CF || bt > T_BOOL_NZF) {
					if (bt == T_CHAR) {
						EMITL3("or r%ua,r%ua\n", rnop, rnop);
					} else if (bt == T_WORD) {
						EMITL3("or r%ul,r%ul\n", rnop, rnop);
					} else if (bt == T_LONG) {
						EMITL3("or r%u,r%u\n", rnop, rnop);
					}
					bt = T_BOOL_ZF;
				}
				break;
			case IR_COMPARE_NZ:
				if (bt < T_BOOL_CF || bt > T_BOOL_NZF) {
					if (bt == T_CHAR) {
						EMITL3("or r%ua,r%ua\n", rnop, rnop);
					} else if (bt == T_WORD) {
						EMITL3("or r%ul,r%ul\n", rnop, rnop);
					} else if (bt == T_LONG) {
						EMITL3("or r%u,r%u\n", rnop, rnop);
					}
					bt = T_BOOL_NZF;
				} else {
					bt ^= 1;
				}
				break;
			case IR_LOR:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("lor r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("lor r%ul,r%ul\n", rnop, rnos);
				} else if (bt == T_INT || bt == T_LONG) {
					EMITL3("lor r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_LAND:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("land r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("land r%ul,r%ul\n", rnop, rnos);
				} else if (bt == T_INT || bt == T_LONG) {
					EMITL3("land r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_NOT:
				if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					bt ^= 1;
				} else if (bt == T_CHAR) {
					EMITL2("xori r%ua,0xFF\n", rnop);
				} else if (bt == T_WORD) {
					EMITL2("xori r%ul,0xFFFF\n", rnop);
				} else {
					EMITL2("xori r%u,0xFFFFFFFF\n", rnop);
				}
				break;
			case IR_OR:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("or r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("or r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("or r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_AND:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("and r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("and r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("and r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_COMPARE_EQ:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmp r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("cmp r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				}
				bt = T_BOOL_ZF;
				break;
			case IR_COMPARE_NEQ:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmp r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("cmp r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_COMPARE_LT:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmp r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("cmp r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_LTEQ:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("inc r%ua\n", rnos);
					EMITL3("cmp r%ua,r%ua\n", rnop, rnos);
					EMITL2("dec r%ua\n", rnos);
				} else if (bt == T_WORD) {
					EMITL2("inc r%ul\n", rnos);
					EMITL3("cmp r%ul,r%ul\n", rnop, rnos);
					EMITL2("dec r%ul\n", rnos);
				} else {
					EMITL2("inc r%u\n", rnos);
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL2("dec r%u\n", rnos);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_GTEQ:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmp r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("cmp r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_COMPARE_GT:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("inc r%ua\n", rnos);
					EMITL3("cmp r%ua,r%ua\n", rnop, rnos);
					EMITL2("dec r%ua\n", rnos);
				} else if (bt == T_WORD) {
					EMITL2("inc r%ul\n", rnos);
					EMITL3("cmp r%ul,r%ul\n", rnop, rnos);
					EMITL2("dec r%ul\n", rnos);
				} else {
					EMITL2("inc r%u\n", rnos);
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL2("dec r%u\n", rnos);
				}
				bt = T_BOOL_CF;
				break;
			case IR_SHL:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("shl r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("shl r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("shl r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_SHR:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("shr r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("shr r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("shr r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_ADD:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("add r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("add r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("add r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_SUB:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("sub r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("sub r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("sub r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_DIV:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("div r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("div r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("div r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_MUL:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("mul r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("mul r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("mul r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_MOD:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("mod r%ua,r%ua\n", rnop, rnos);
				} else if (bt == T_WORD) {
					EMITL3("mod r%ul,r%ul\n", rnop, rnos);
				} else {
					EMITL3("mod r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_NEG:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("ldz r8a\nsub r8a,r%ua\n", rnop);
				} else if (bt == T_WORD) {
					EMITL2("ldz r8l\nsub r8l,r%ul\n", rnop);
				} else {
					EMITL2("ldz r8\nsub r8,r%u\n", rnop);
				}
				break;
			case IR_INC:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("inc r%ua\n", rnop);
				} else if (bt == T_WORD) {
					EMITL2("inc r%ul\n", rnop);
				} else {
					EMITL2("inc r%u\n", rnop);
				}
				break;
			case IR_DEC:
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("dec r%ua\n", rnop);
				} else if (bt == T_WORD) {
					EMITL2("dec r%ul\n", rnop);
				} else {
					EMITL2("dec r%u\n", rnop);
				}
				break;
			case IR_INC_TER:
			case IR_INC_SEC:
				EMITL2("inc r%u\n", rnos);
				break;
			case IR_DEC_TER:
			case IR_DEC_SEC:
				EMITL2("dec r%u\n", rnos);
				break;
			case IR_OR_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("ori r%ua,%llu\n", rnop, arg);
				} else if (bt == T_WORD) {
					EMITL3("ori r%ul,%llu\n", rnop, arg);
				} else {
					EMITL3("ori r%u,%llu\n", rnop, arg);
				}
				break;
			case IR_AND_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("andi r%ua,%llu\n", rnop, arg);
				} else if (bt == T_WORD) {
					EMITL3("andi r%ul,%llu\n", rnop, arg);
				} else {
					EMITL3("andi r%u,%llu\n", rnop, arg);
				}
				break;
			case IR_COMPARE_EQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmpi r%ua,%llu\n", rnop, arg);
				} else if (bt == T_WORD) {
					EMITL3("cmpi r%ul,%llu\n", rnop, arg);
				} else {
					EMITL3("cmpi r%u,%llu\n", rnop, arg);
				}
				bt = T_BOOL_ZF;
				break;
			case IR_COMPARE_NEQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmpi r%ua,%llu\n", rnop, arg);
				} else if (bt == T_WORD) {
					EMITL3("cmpi r%ul,%llu\n", rnop, arg);
				} else {
					EMITL3("cmpi r%u,%llu\n", rnop, arg);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_COMPARE_LT_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmpi r%ua,%llu\n", rnop, arg);
				} else if (bt == T_WORD) {
					EMITL3("cmpi r%ul,%llu\n", rnop, arg);
				} else {
					EMITL3("cmpi r%u,%llu\n", rnop, arg);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_LTEQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmpi r%ua,%llu\n", rnop, arg+1);
				} else if (bt == T_WORD) {
					EMITL3("cmpi r%ul,%llu\n", rnop, arg+1);
				} else {
					EMITL3("cmpi r%u,%llu\n", rnop, arg+1);
				}
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_GT_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmpi r%ua,%llu\n", rnop, arg);
				} else if (bt == T_WORD) {
					EMITL3("cmpi r%ul,%llu\n", rnop, arg);
				} else {
					EMITL3("cmpi r%u,%llu\n", rnop, arg);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_COMPARE_GTEQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmpi r%ua,%llu\n", rnop, arg+1);
				} else if (bt == T_WORD) {
					EMITL3("cmpi r%ul,%llu\n", rnop, arg+1);
				} else {
					EMITL3("cmpi r%u,%llu\n", rnop, arg+1);
				}
				bt = T_BOOL_NCF;
				break;
			case IR_SHL_CONST:
				expr++;
				if (arg != 0) {
					bt = convert_flag_to_char_BxS2320(bt, rnop);
					if (bt == T_CHAR) {
						EMITL3("shli r%ua,%llu\n", rnop, arg);
					} else if (bt == T_WORD) {
						EMITL3("shli r%ul,%llu\n", rnop, arg);
					} else {
						EMITL3("shli r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_SHR_CONST:
				expr++;
				if (arg != 0) {
					bt = convert_flag_to_char_BxS2320(bt, rnop);
					if (bt == T_CHAR) {
						EMITL3("shri r%ua,%llu\n", rnop, arg);
					} else if (bt == T_WORD) {
						EMITL3("shri r%ul,%llu\n", rnop, arg);
					} else {
						EMITL3("shri r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_ADD_CONST:
				expr++;
				if (arg != 0) {
					bt = convert_flag_to_char_BxS2320(bt, rnop);
					if (bt == T_CHAR) {
						EMITL3("addi r%ua,%llu\n", rnop, arg);
					} else if (bt == T_WORD) {
						EMITL3("addi r%ul,%llu\n", rnop, arg);
					} else {
						EMITL3("addi r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_SUB_CONST:
				expr++;
				if (arg != 0) {
					bt = convert_flag_to_char_BxS2320(bt, rnop);
					if (bt == T_CHAR) {
						EMITL3("subi r%ua,%llu\n", rnop, arg);
					} else if (bt == T_WORD) {
						EMITL3("subi r%ul,%llu\n", rnop, arg);
					} else {
						EMITL3("subi r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_MUL_CONST:
				expr++;
				if (arg == 1) {
					if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
						EMITL2("ld r%u,r1\n", rnop);
						if (bt >= T_BOOL_ZF) {
							EMITL2("shri r%u,1\n", rnop);
						}
						if (bt & 1) {
							EMITL2("xori r%u,1", rnop);
						}
					}
				} else if (arg == 0) {
					if (bt == T_CHAR) {
						EMITL2("ldz r%ua\n", rnop);
					} else if (bt == T_WORD) {
						EMITL2("ldz r%ul\n", rnop);
					} else {
						EMITL2("ldz r%u\n", rnop);
					}
				} else {
					if (bt == T_CHAR) {
						EMITL3("muli r%ua,%llu\n", rnop, arg);
					} else if (bt == T_WORD) {
						EMITL3("muli r%ul,%llu\n", rnop, arg);
					} else {
						EMITL3("muli r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_DIV_CONST:
				expr++;
				if (arg != 1) {
					if (arg == 0) {
						EMITL2("ldi r%u,-1\n", rnop);
						bt = T_INT;
						break;
					} else if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
						if (arg > 1) {
							EMITL2("ldz r%u\n", rnop);
							bt = T_CHAR;
						}
					} else {
						if (bt == T_CHAR) {
							EMITL3("divi r%ua,%llu\n", rnop, arg);
						} else if (bt == T_WORD) {
							EMITL3("divi r%ul,%llu\n", rnop, arg);
						} else {
							EMITL3("divi r%u,%llu\n", rnop, arg);
						}
					}
				}
				break;
			case IR_MOD_CONST:
				expr++;
				if (arg == 0) {
					EMITL2("ldi r%u,-1\n", rnop);
					bt = T_INT;
					break;
				} else {
					bt = convert_flag_to_char_BxS2320(bt, rnop);
					if (bt == T_CHAR) {
						EMITL3("modi r%ua,%llu\n", rnop, arg);
					} else if (bt == T_WORD) {
						EMITL3("modi r%ul,%llu\n", rnop, arg);
					} else {
						EMITL3("modi r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_JMP:
				expr++;
				EMITL2("jq _%llu\n", arg);
				break;
			case IR_BZ:
				expr++;
				bt = convert_to_zf_BxS2307(bt);
				EMITL2("jq z,_%llu\n", arg);
				break;
			case IR_BNZ:
				expr++;
				bt = convert_to_zf_BxS2307(bt);
				EMITL2("jq nz,_%llu\n", arg);
				break;
			case IR_STRLEN:
				EMITL2("ld arg0,r%u\n", rnop);
				EMITL2("call _strlen\nld r%u,rval\n", rnop);
				break;
			case IR_STORE:
				expr++;
				bt = convert_flag_to_char_BxS2320(bt, rnop);
				EMITL3("str r%u,r%u\n", rnop, rnos);
				break;
			case IR_STRCPY:
				EMITL2("ld arg0,r%u\n", rnop);
				EMITL2("ld arg1,r%u\n", rnos);
				EMITL("call _strcpy\n");
				break;
			case IR_DEFINE_FUNCTION:
				expr++;
				expr++;
				EMITL2("label _%s\n", ((symbol*)arg)->name);
				break;
			default:
#ifdef PLATFORM_DESKTOP
				printf("Invalid IR code: 0x%X\nLast known valid IR code: 0x%X\n", op, oldopcode);
#endif
				error("Internal: Invalid IR code");
				break;
		}
	}
}
