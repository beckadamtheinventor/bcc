
#include "include/emitf.h"

void try_resolve_symbols_BxS2307(unsigned int offset) {
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
			EMITL2("label _%llu\n", (_ptr)sym);
		}
	} while ((sym = sym->prev));

//	printf("\n");
}

uint8_t convert_to_zf_BxS2307(uint8_t bt) {
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

uint8_t convert_flag_to_char_BxS2307(uint8_t bt, uint8_t rno) {
	if (bt == T_BOOL_CF) {
		EMITL3("ldi r%u, 0\ncld c, r%u, 1\n", rno, rno);
	} else if (bt == T_BOOL_NCF) {
		EMITL3("ldi r%u, 0\ncld nc, r%u, 1\n", rno, rno);
	} else if (bt == T_BOOL_ZF) {
		EMITL3("ldi r%u, 0\ncld z, r%u, 1\n", rno, rno);
	} else if (bt == T_BOOL_NZF) {
		EMITL3("ldi r%u, 0\ncld nz, r%u, 1\n", rno, rno);
	}
	return T_WORD;
}

void assemble_BxS2307(void) {
	int op = 0, oldopcode;
	_ptr arg, *expr = exprstart;
	uint8_t l, bt = T_VOID, *prevout = out, *prevprevout = out;
	uint32_t arg32;
	uint8_t rnop = 9, rnop2 = 10, rnos = 11, rnos2 = 12, rarg = 16;
	symbol *sym, *mainsym;

	PROGRAM_ORIGIN = 0;
	lno = 0;

	if ((mainsym = find_sym("main", 0)) == NULL) {
		error("Missing function main()");
	}

	EMITL("call _main\n_exit := 0\n");

	// expr++;
	while (1) {
		prevprevout = prevout;
		prevout = out;
		try_resolve_symbols_BxS2307(expr - exprstart);
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
				EMITL3("ld r%u,r%u\n", rarg, rnop);
				rarg++;
				break;
			case IR_PUSH_ARG_32:
				EMITL3("ld r%u,r%u\n", rarg, rnop);
				rarg++;
				EMITL3("ld r%u,r%u\n", rarg, rnop2);
				rarg++;
				break;
			case IR_PUSH_ARG_IMM:
				expr++;
				EMITL3("ld r%u,%u\n", rarg, arg32&0xffff);
				rarg++;
				break;
			case IR_PUSH_ARG_IMM_32:
				expr++;
				expr++;
				EMITL3("ld r%u,%u\n", rarg, arg32&0xffff);
				rarg++;
				EMITL3("ld r%u,%u\n", rarg, arg32>>16);
				rarg++;
				break;
			case IR_IMM:
				expr++;
				EMITL3("ldi r%u,%llu\n", rnop, arg);
				bt = T_INT;
				break;
			case IR_IMM_PROG_OFFSET:
				expr++;
				EMITL3("ldi r%u,s_%llu\n", rnop, arg);
				bt = T_INT;
				break;
			case IR_IMM_8:
				expr++;
				EMITL3("ldi r%u,%llu\n", rnop, arg);
				bt = T_CHAR;
				break;
			case IR_IMM_32_SEC:
				expr++;
				EMITL3("ldi r%u,%u\n", rnos, arg32&0xffff);
				EMITL3("ldi r%u,%u\n", rnos2, arg32>>16);
				expr++;
				bt = T_LONG;
				break;
			case IR_IMM_32:
				expr++;
				EMITL3("ldi r%u,%u\n", rnop, arg32&0xffff);
				EMITL3("ldi r%u,%u\n", rnop2, arg32>>16);
				expr++;
				bt = T_LONG;
				break;
			case IR_PUSH_TER:
			case IR_PUSH_SEC:
			case IR_PUSH:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("push r%u\npush r%u\n", rnop, rnop2);
				} else {
					EMITL2("push r%u\n", rnop);
				}
				break;
			case IR_PUSH_IMM_32:
				expr++;
				EMITL3("ldi r8,%u\npush r8\nldi r8, %u\npush r8\n", arg32&0xffff, arg32>>16);
				break;
			case IR_PUSH_IMM:
				expr++;
				EMITL2("ldi r8,%llu\npush r8\n", arg);
				break;
			case IR_PUSH_32:
				EMITL3("push r%u\npush r%u\n", rnos, rnos2);
				break;
			case IR_POP:
				EMITL2("pop r%u\n", rnop);
				break;
			case IR_POP_TER:
			case IR_POP_SEC:
				EMITL2("pop r%u\n", rnos);
				break;
			case IR_POP_32:
				EMITL3("pop r%u\npop r%u\n", rnos, rnos2);
				break;
			case IR_EX_SEC_PRI:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL2("ld r8,r%u\n", rnop);
				EMITL3("ld r%u,r%u\n", rnop, rnos);
				EMITL2("ld r%u,r8\n", rnos);
				break;
			case IR_CALL:
				expr++;
				if (expr[0] == IR_ADJ && (expr[2] == IR_LEAVE || expr[2] == IR_EXIT)) {
					EMITL("ld r254,r2\n");
					EMITL2("jp _%s\n", ((symbol*)arg)->name);
					expr = &expr[3];
					rarg -= arg / 3;
				} else if (expr[0] == IR_LEAVE || expr[0] == IR_EXIT) {
					EMITL("ld r254,r2\n");
					EMITL2("jp _%s\n", ((symbol*)arg)->name);
					expr++;
				} else {
					EMITL2("call _%s\n", ((symbol*)arg)->name);
				}
				bt = ((symbol*)arg)->valtype;
				break;
			case IR_ADJ:
				expr++;
				EMITL2("add r2,%d\n", (int32_t)arg);
				rarg -= arg / 3;
				break;
			case IR_ENTER:
				expr++;
				EMITL("push r254\nld r254,r2\n");
				EMITL2("add r2,%d\n", (int32_t)arg);
				break;
			case IR_LEAVE:
				EMITL("ld r2,r254\npop r254\nret\n");
				break;
			case IR_EXIT:
				expr++;
				EMITL("ld r2,r254\npop r254\njp _exit\n");
				break;
			case IR_LEA_LOCAL:
				expr++;
				if (arg > 0) {
					l = *expr++;
					if (l == IR_LOAD_CHAR) {
						EMITL3("ld r%u,r%llu\n", rnop, 14+arg/3);
						EMITL2("and r%u,$FF\n", rnop);
					} else if (l == IR_LOAD_WORD || l == IR_LOAD_INT) {
						EMITL3("ld r%u,r%llu\n", rnop, 14+arg/3);
					} else if (l == IR_LOAD_LONG) {
						EMITL3("ld r%u,r%llu\n", rnop, 14+arg/3);
						EMITL3("ld r%u,r%llu\n", rnop2, 15+arg/3);
					} else {
						error("Internal: can't get address of register");
					}
				} else {
					EMITL2("ld r%u,r254\n", rnop);
					EMITL3("add r%u,%lld\n", rnop, arg);
					bt = T_PTR;
				}
				break;
			case IR_LEA_GLOBAL:
				expr++;
				EMITL3("ld r%u,%llu\n", rnop, arg);
				break;
			case IR_STORE_LOCAL:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				l = *expr++;
				EMITL("ld r8,r254\n");
				EMITL2("add r8,%lld\n", arg);
				if (l == T_CHAR) {
					EMITL2("str r%u,r8\n", rnop);
				} else if (l == T_LONG) {
					EMITL2("strw r%u,r8\n", rnop);
					EMITL("add r8,2\n");
					EMITL2("strw r%u,r8\n", rnop);
				} else {
					EMITL2("strw r%u,r8\n", rnop);
				}
				break;
			case IR_STORE_GLOBAL:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				l = *expr++;
				if (l == T_CHAR) {
					EMITL3("sto r%u,%llu\n", rnop, arg);
				} else if (l == T_LONG) {
					EMITL3("stow r%u,%llu\n", rnop, arg);
					EMITL3("stow r%u,%llu\n", rnop2, arg+2);
				} else {
					EMITL3("stow r%u,%llu\n", rnop, arg);
				}
				break;
			case IR_LOAD_CHAR:
				EMITL3("ild r%u,r%u\n", rnop, rnop);
				bt = T_CHAR;
				break;
			case IR_LOAD_INT:
			case IR_LOAD_WORD:
				EMITL3("ildw r%u,r%u\n", rnop, rnop);
				bt = T_WORD;
				break;
			case IR_LOAD_LONG:
				EMITL3("ildw r%u,r%u,2\n", rnop2, rnop);
				EMITL3("ildw r%u,r%u\n", rnop, rnop);
				bt = T_LONG;
				break;
			case IR_COMPARE_Z:
				if (bt < T_BOOL_CF || bt > T_BOOL_NZF) {
					if (bt == T_CHAR) {
						EMITL2("and r%u,$FF\n", rnop);
						bt = T_BOOL_ZF;
					} else if (bt == T_WORD) {
						EMITL2("and r%u,$FFFF\n", rnop);
						bt = T_BOOL_ZF;
					} else if (bt == T_LONG) {
						EMITL3("or r%u,r%u,r3\n", rnop, rnop2);
						bt = T_BOOL_ZF;
					} else {
						EMITL3("or r%u,r%u\n", rnop, rnop);
						bt = T_BOOL_ZF;
					}
				}
				break;
			case IR_COMPARE_NZ:
				if (bt < T_BOOL_CF || bt > T_BOOL_NZF) {
					if (bt == T_CHAR) {
						EMITL2("and r%u,$FF\n", rnop);
						bt = T_BOOL_NZF;
					} else if (bt == T_LONG) {
						EMITL3("or r%u,r%u,r3\n", rnop, rnop2);
						bt = T_BOOL_NZF;
					} else {
						EMITL3("or r%u,r%u\n", rnop, rnop);
						bt = T_BOOL_NZF;
					}
				} else {
					bt ^= 1;
				}
				break;
			case IR_LOR:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("and r%u,$FF\n", rnop);
				} else if (bt == T_LONG) {
					EMITL3("or r%u,r%u,r8\n", rnop, rnop2);
				} else {
					EMITL3("or r%u,r%u\n", rnop, rnop);
				}
				EMITL3("cld z,r%u,r%u\n", rnop, rnos);
				break;
			case IR_LAND:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_CHAR) {
					EMITL2("and r%u,$FF\n", rnop);
				} else if (bt == T_LONG) {
					EMITL3("or r%u,r%u,r8\n", rnop, rnop2);
				} else {
					EMITL3("or r%u,r%u\n", rnop, rnop);
				}
				EMITL2("cld z,r%u,0\n", rnop);
				EMITL3("cld nz,r%u,r%u\n", rnop, rnos);
				break;
			case IR_NOT:
				if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					bt ^= 1;
				} else if (bt == T_CHAR) {
					EMITL2("xor r%u,0xFF\n", rnop);
				} else if (bt == T_LONG) {
					EMITL2("xor r%u,0xFFFF\n", rnop);
					EMITL2("xor r%u,0xFFFF\n", rnop2);
				} else {
					EMITL2("xor r%u,0xFFFF\n", rnop);
				}
				break;
			case IR_OR:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("or r%u,r%u\n", rnop, rnos);
					EMITL3("or r%u,r%u\n", rnop2, rnos2);
				} else {
					EMITL3("or r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_AND:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("or r%u,r%u\n", rnop, rnos);
					EMITL3("or r%u,r%u\n", rnop2, rnos2);
				} else {
					EMITL3("or r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_COMPARE_EQ:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				} else if (bt == T_LONG) {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL("ld r8,r1\n");
					EMITL3("cmp r%u,r%u\n", rnop2, rnos2);
					EMITL("and r8,r1\n");
					EMITL("and r8,2\n");
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				}
				bt = T_BOOL_ZF;
				break;
			case IR_COMPARE_NEQ:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_CHAR) {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				} else if (bt == T_LONG) {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL("ld r8,r1\n");
					EMITL3("cmp r%u,r%u\n", rnop2, rnos2);
					EMITL("and r8,r1\n");
					EMITL("and r8,2\n");
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
				}
				bt = T_BOOL_NZF;
				break;
			case IR_COMPARE_LT:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL("ld r8,r1\n");
					EMITL3("cmp r%u,r%u\n", rnop2, rnos2);
					EMITL("and r8,r1\n");
					EMITL("and r8,1\n");
					bt = T_BOOL_ZF;
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					bt = T_BOOL_CF;
				}
				break;
			case IR_COMPARE_LTEQ:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("inc r%u\nadc r%u,0\n", rnos, rnos2);
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL("ld r8,r1\n");
					EMITL3("cmp r%u,r%u\n", rnop2, rnos2);
					EMITL("and r8,r1\n");
					EMITL("and r8,1\n");
					bt = T_BOOL_ZF;
				} else {
					EMITL2("inc r%u\n", rnos);
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					bt = T_BOOL_CF;
				}
				break;
			case IR_COMPARE_GTEQ:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL("ld r8,r1\n");
					EMITL3("cmp r%u,r%u\n", rnop2, rnos2);
					EMITL("and r8,r1\n");
					EMITL("and r8,1\n");
					bt = T_BOOL_NZF;
				} else {
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					bt = T_BOOL_NCF;
				}
				break;
			case IR_COMPARE_GT:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("inc r%u\nadc r%u,0\n", rnos, rnos2);
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					EMITL("ld r8,r1\n");
					EMITL3("cmp r%u,r%u\n", rnop2, rnos2);
					EMITL("and r8,r1\n");
					EMITL("and r8,1\n");
					bt = T_BOOL_ZF;
				} else {
					EMITL2("inc r%u\n", rnos);
					EMITL3("cmp r%u,r%u\n", rnop, rnos);
					bt = T_BOOL_CF;
				}
				break;
			case IR_SHL:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _lshl\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("shl r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_SHR:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _lshr\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("shr r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_ADD:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _ladd\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("add r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_SUB:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _lsub\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("sub r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_DIV:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _ldiv\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("div r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_MUL:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _lmul\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("mul r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_MOD:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL3("ld r18,r%u\nld r19,r%u\n", rnos, rnos2);
					EMITL("call _lmod\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("mod r%u,r%u\n", rnop, rnos);
				}
				break;
			case IR_NEG:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("ld r8,0\nsub r8,r%u,r%u\n", rnop, rnop);
					EMITL3("sub r8,r%u,r%u\n", rnop2, rnop2);
				} else {
					EMITL3("ld r8,0\nsub r8,r%u,r%u\n", rnop, rnop);
				}
				break;
			case IR_INC:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("inc r%u\nadc r%u,0\n", rnop, rnop2);
				} else {
					EMITL2("inc r%u\n", rnop);
				}
				break;
			case IR_DEC:
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (bt == T_LONG) {
					EMITL3("dec r%u\nsbc r%u,0\n", rnop, rnop2);
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
				EMITL2("inc r%u\n", rnos);
				break;
			case IR_OR_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("or r%u,%llu\n", rnop, arg);
				break;
			case IR_AND_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("and r%u,%llu\n", rnop, arg);
				break;
			case IR_COMPARE_EQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("cmp r%u,%llu\n", rnop, arg);
				bt = T_BOOL_ZF;
				break;
			case IR_COMPARE_NEQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("cmp r%u,%llu\n", rnop, arg);
				bt = T_BOOL_NZF;
				break;
			case IR_COMPARE_LT_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("cmp r%u,%llu\n", rnop, arg);
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_LTEQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("cmp r%u,%llu\n", rnop, arg+1);
				bt = T_BOOL_CF;
				break;
			case IR_COMPARE_GT_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("cmp r%u,%llu\n", rnop, arg+1);
				bt = T_BOOL_NCF;
				break;
			case IR_COMPARE_GTEQ_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("cmp r%u,%llu\n", rnop, arg);
				bt = T_BOOL_NCF;
				break;
			case IR_SHL_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("shl r%u,%llu\n", rnop, arg);
				break;
			case IR_SHR_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				EMITL3("shr r%u,%llu\n", rnop, arg);
				break;
			case IR_ADD_CONST:
				expr++;
				if (arg != 0) {
					bt = convert_flag_to_char_BxS2307(bt, rnop);
					if (bt == T_LONG) {
						EMITL3("add r%u,%llu\n", rnop, arg);
						EMITL2("adc r%u,0\n", rnop2);
					} else {
						EMITL3("add r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_SUB_CONST:
				expr++;
				if (arg != 0) {
					bt = convert_flag_to_char_BxS2307(bt, rnop);
					if (bt == T_LONG) {
						EMITL3("sub r%u,%llu\n", rnop, arg);
						EMITL2("sbc r%u,0\n", rnop2);
					} else {
						EMITL3("sub r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_MUL_CONST:
				expr++;
				if (arg == 1) {
					if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
						EMITL2("ld r%u,r1\n", rnop);
						if (bt >= T_BOOL_ZF) {
							EMITL2("shr r%u,1\n", rnop);
						}
						if (bt & 1) {
							EMITL2("xor r%u,1", rnop);
						}
					}
				} else {
					if (bt == T_LONG) {
						EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
						EMITL2("ld r18,%llu\nld r19,0\n", arg);
						EMITL("call _lmul\n");
						EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
					} else {
						EMITL3("mul r%u,r%u\n", rnop, rnos);
					}
				}
				break;
			case IR_DIV_CONST:
				expr++;
				if (arg != 1) {
					if (arg == 0) {
						EMITL2("ld r%u,-1\n", rnop);
						bt = T_INT;
						break;
					} else if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
						if (arg > 1) {
							EMITL2("ld r%u,0\n", rnop);
							bt = T_CHAR;
						}
					} else if (bt == T_LONG) {
						EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
						EMITL2("ld r18,%llu\nld r19,r0\n", arg);
						EMITL("call _ldiv\n");
						EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
					} else {
						EMITL3("div r%u,%llu\n", rnop, arg);
					}
				}
				break;
			case IR_MOD_CONST:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				if (arg == 0) {
					EMITL2("ld r%u,-1\n", rnop);
					bt = T_INT;
					break;
				} else if (bt == T_LONG) {
					EMITL3("ld r16,r%u\nld r17,r%u\n", rnop, rnop2);
					EMITL2("ld r18,%llu\nld r19,r0\n", arg);
					EMITL("call _lmod\n");
					EMITL3("ld r%u,r16\nld r%u,r17\n", rnop, rnop2);
				} else {
					EMITL3("div r%u,%llu\n", rnop, arg);
				}
				break;
			case IR_JMP:
				expr++;
				EMITL2("jp _%llu\n", arg);
				break;
			case IR_BZ:
				expr++;
				bt = convert_to_zf_BxS2307(bt);
				EMITL2("jp z,_%llu\n", arg);
				break;
			case IR_BNZ:
				expr++;
				bt = convert_to_zf_BxS2307(bt);
				EMITL2("jp nz,_%llu\n", arg);
				break;
			case IR_STRLEN:
				EMITL2("ld r16,r%u\n", rnop);
				EMITL2("call _strlen\nld r%u,r16\n", rnop);
				break;
			case IR_STORE:
				expr++;
				bt = convert_flag_to_char_BxS2307(bt, rnop);
				break;
			case IR_STRCPY:
				EMITL2("ld r16,r%u\n", rnop);
				EMITL2("ld r17,r%u\n", rnop);
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
