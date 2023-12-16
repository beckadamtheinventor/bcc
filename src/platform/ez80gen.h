
#include "include/ez80.h"
#include "include/ti84pceg.h"

#define LOAD_HL(a) if (!(hlisconst && hlvalue == (unsigned)(a))) { if ((unsigned)(a) == 0) {EMIT_OR_A(out); EMIT_SBC_HL_HL(out);} else if ((unsigned)(a) == -1) {EMIT_SCF(out); EMIT_SBC_HL_HL(out);} else {EMIT_LD_HL_IMM(out, (unsigned)(a));} hlvalue = (a); hlisconst = true; }
#define LOAD_DE(a) if (!(deisconst && devalue == (unsigned)(a))) {EMIT_LD_DE_IMM(out, (unsigned)(a)); devalue = (a); deisconst = true;}
#define LOAD_BC(a) if (!(bcisconst && bcvalue == (unsigned)(a))) {EMIT_LD_BC_IMM(out, (unsigned)(a)); bcvalue = (a); bcisconst = true;}

/*
 * Primary registers
 *  32-bit: AUHL
 *  24-bit: UHL
 *  16-bit: HL
 *   8-bit: A
 * Secondary registers
 *  32-bit: CUDE
 *  24-bit: UDE
 *  16-bit: DE
 *   8-bit: E
 */


uint8_t ez80_convert_flag_to_char(uint8_t bt) {
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

uint8_t ez80_convert_to_zf(uint8_t bt) {
	if (bt == T_CHAR) {
		EMIT_OR_A(out);
		bt = T_BOOL_ZF;
	} else if (bt == T_WORD) {
		EMIT_LD_A_H(out);
		EMIT_OR_L(out);
		bt = T_BOOL_ZF;
	} else if (bt == T_INT) {
		EMIT_ADD_HL_BC(out);
		EMIT_OR_A(out);
		EMIT_SBC_HL_BC(out);
		bt = T_BOOL_ZF;
	} else if (bt == T_LONG) {
		EMIT_ADD_HL_BC(out);
		EMIT_XOR_A(out);
		EMIT_LD_D_A(out);
		EMIT_LD_A_E(out);
		EMIT_SBC_HL_BC(out);
		EMIT_SBC_A_D(out);
		bt = T_BOOL_ZF;
	} else if (bt == T_BOOL_CF) {
		EMIT_SBC_A_A(out);
		EMIT_AND_IMM(out, 1);
		bt = T_BOOL_ZF;
	} else if (bt == T_BOOL_NCF) {
		EMIT_SBC_A_A(out);
		EMIT_INC_A(out);
		bt = T_BOOL_ZF;
	}
	if (bt == T_BOOL_ZF) {
		EMIT_LD_A_IMM(out, 1);
		EMIT_JR_Z_IMM(out, L_XOR_A);
		EMIT_XOR_A(out);
		EMIT_OR_A(out);
	}
	return T_BOOL_NZF;
}

uint8_t ez80_convert_reg_type_secondary(uint8_t bt, uint8_t nt) {
	if (bt == T_VOID || nt == T_VOID) {
		error("Internal: Cannot convert to/from void type");
	}
	if (!(nt == bt || ((nt >= T_PTR || nt == T_INT) && (bt >= T_PTR || bt == T_INT)))) {
		if (nt == T_WORD) {
			if (bt == T_CHAR) {
				EMIT_LD_D_IMM(out, 0);
			}
		} else if (nt == T_INT || nt >= T_PTR) {
			if (bt == T_CHAR) {
				EMIT_LD_B_IMM(out, 1);
				EMIT_MLT_BC(out);
			} else if (bt == T_WORD) {
				EMIT_PUSH_HL(out);
				EMIT_SIS_SUFFIX(out);
				EMIT_EX_DE_HL(out);
				EMIT_EX_DE_HL(out);
				EMIT_POP_HL(out);
			}
		} else if (nt == T_LONG) {
			if (bt == T_CHAR) {
				EMIT_LD_D_IMM(out, 1);
				EMIT_MLT_DE(out);
				EMIT_LD_C_D(out);
			} else if (bt == T_WORD) {
				EMIT_PUSH_HL(out);
				EMIT_SIS_SUFFIX(out);
				EMIT_EX_DE_HL(out);
				EMIT_EX_DE_HL(out);
				EMIT_POP_HL(out);
				EMIT_LD_C_IMM(out, 0);
			} else {
				// bt == T_INT
				EMIT_LD_C_IMM(out, 0);
			}
		}
	}
	return nt;
}

uint8_t ez80_convert_reg_type(uint8_t bt, uint8_t nt) {
	// printf("Converting types %u to %u\n", bt, nt);
	if (bt == T_VOID || nt == T_VOID) {
		error("Internal: Cannot convert to/from void type");
	}
	if (!(nt == bt || ((nt >= T_PTR || nt == T_INT) && (bt >= T_PTR || bt == T_INT)))) {
		if (nt == T_CHAR) {
			EMIT_LD_A_L(out);
		} else if (nt == T_WORD) {
			if (bt == T_CHAR) {
				EMIT_LD_H_IMM(out, 0);
				EMIT_LD_L_A(out);
			}
		} else if (nt == T_INT || nt >= T_PTR) {
			if (bt == T_CHAR) {
				EMIT_LD_H_IMM(out, 1);
				EMIT_LD_L_A(out);
				EMIT_MLT_HL(out);
			} else if (bt == T_WORD) {
				EMIT_PUSH_DE(out);
				EMIT_SIS_SUFFIX(out);
				EMIT_EX_DE_HL(out);
				EMIT_EX_DE_HL(out);
				EMIT_POP_DE(out);
			}
		} else if (nt == T_LONG) {
			if (bt == T_CHAR) {
				EMIT_LD_D_IMM(out, 1);
				EMIT_MLT_DE(out);
				EMIT_LD_C_D(out);
			} else if (bt == T_WORD) {
				EMIT_PUSH_DE(out);
				EMIT_SIS_SUFFIX(out);
				EMIT_EX_DE_HL(out);
				EMIT_EX_DE_HL(out);
				EMIT_POP_DE(out);
				EMIT_XOR_A(out);
			} else {
				// bt == T_INT
				EMIT_XOR_A(out);
			}
		}
	}
	return nt;
}

void ez80_equalize_types(uint8_t *bt, uint8_t *st) {
	if ((*bt & T_MASK) > (*st & T_MASK)) {
		*st = ez80_convert_reg_type_secondary(*st, *bt);
	} else {
		*bt = ez80_convert_reg_type(*bt, *st);
	}
}

void ez80_exchange_primary_secondary(uint8_t bt) {
	if (bt == T_LONG) {
		EMIT_PUSH_DE(out);
		EMIT_LD_E_A(out);
		EMIT_LD_A_C(out);
		EMIT_LD_C_E(out);
		EMIT_EX_IND_SP_HL(out);
		EMIT_POP_DE(out);
	} else if (bt == T_CHAR) {
		EMIT_LD_D_E(out);
		EMIT_LD_E_A(out);
		EMIT_LD_A_D(out);
	} else {
		EMIT_EX_DE_HL(out);
	}
}


void assemble_eZ80(void) {
	bool argispowerof2 = false, hlisconst = false, deisconst = false, bcisconst = false;
	unsigned int hlvalue, devalue, bcvalue;
	int op = 0, oldopcode;
	_ptr arg, *expr = exprstart;
	uint8_t l, bt = T_VOID, st = T_VOID, *leaveaddress = NULL, *last_compare_ptr = NULL, *prevout = out, *prevprevout = out;
	symbol *sym, *mainsym, *initsym;
	uint8_t *addrtmp;

	globaladdr = TI_pixelShadow;
	PROGRAM_ORIGIN = TI_userMem;

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
	EMIT_CALL_IMM(out, TI_ClrScrnFull);
	EMIT_CALL_IMM(out, TI_HomeUp);
	// call hidden init function if defined
	if ((initsym = find_sym("0init", 0)) != NULL) {
		EMIT_CALL_IMM(out, 0);
		resolve_later(out - (outstart + 3), initsym);
	}
	EMIT_CALL_IMM(out, 0);
	resolve_later(out - (outstart + 3), mainsym);
	exitroutineptr = PROGRAM_ORIGIN + out - outstart;
	addrtmp = exitroutineptr + 1;
	EMIT_LD_SP_IMM(out, 0);
	memcpy(&outstart[errsp_offset], &addrtmp, 3);
	EMIT_CALL_IMM(out, TI_RunIndicOn);
	EMIT_JP_IMM(out, TI_HomeUp);
	// expr++;
	while (1) {
		prevprevout = prevout;
		prevout = out;
		try_resolve_symbols(expr - exprstart);
#ifdef DEBUG
		printf("out offset: %llu expr offset: %llu\n", out-outstart, expr-exprstart);
#endif
		oldopcode = op;
		op = *expr++;
		if (expr >= data_start) {
			break;
		}
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
				if (expr[-2] == IR_PUSH && *expr == IR_EX_SEC_PRI) {
					out = prevprevout;
					LOAD_DE(arg);
					expr++;
				} else {
					LOAD_HL(arg);
				}
				bt = T_INT;
				break;
			case IR_IMM_PROG_OFFSET:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				if (expr[-2] == IR_PUSH && *expr == IR_EX_SEC_PRI) {
					out = prevprevout;
					EMIT_LD_DE_IMM(out, 0);
					expr++;
					deisconst = false;
				} else {
					EMIT_LD_HL_IMM(out, 0);
					hlisconst = false;
				}
				break;
			case IR_IMM_8:
				expr++;
				if (expr[-2] == IR_PUSH && *expr == IR_EX_SEC_PRI) {
					out = prevprevout;
					EMIT_LD_E_IMM(out, (unsigned)arg);
					expr++;
					deisconst = false;
				} else {
					EMIT_LD_A_IMM(out, (unsigned)arg);
				}
				bt = T_CHAR;
				break;
			case IR_IMM_32:
				expr++;
				if (expr[-2] == IR_PUSH_32 && expr[1] == IR_EX_SEC_PRI) {
					out = prevprevout;
					LOAD_DE(arg);
					EMIT_LD_C_IMM(out, (unsigned)*expr);
					expr++;
					st = T_LONG;
				} else {
					LOAD_HL(arg);
					EMIT_LD_A_IMM(out, (unsigned)*expr);
					bt = T_LONG;
				}
				expr++;
				break;
			case IR_IMM_32_SEC:
				expr++;
				LOAD_DE(arg);
				EMIT_LD_C_IMM(out, (unsigned)*expr);
				expr++;
				bcisconst = true;
				bcvalue = arg;
				st = T_LONG;
				break;
			case IR_PUSH_ARG:
			case IR_PUSH:
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_LONG) {
					EMIT_PUSH_HL(out);
					EMIT_PUSH_DE(out);
				} else if (bt == T_CHAR) {
					EMIT_LD_L_A(out);
					EMIT_PUSH_HL(out);
				} else {
					EMIT_PUSH_HL(out);
				}
				push_reg_with_type(bt);
				break;
			case IR_PUSH_ARG_IMM_32:
			case IR_PUSH_IMM_32:
				expr++;
				EMIT_LD_C_IMM(out, (unsigned)*expr);
				expr++;
				EMIT_PUSH_BC(out);
				LOAD_BC(arg);
				EMIT_PUSH_BC(out);
				bcisconst = false;
				push_reg_with_type(T_LONG);
				break;
			case IR_PUSH_ARG_32:
			case IR_PUSH_32:
				EMIT_PUSH_HL(out);
			case IR_PUSH_SEC:
				EMIT_PUSH_DE(out);
				push_reg_with_type(bt);
				break;
			case IR_PUSH_TER:
				EMIT_PUSH_BC(out);
				push_reg_with_type(bt);
				break;
			case IR_POP:
				bt = pop_reg_with_type();
				EMIT_POP_HL(out);
				if (bt == T_LONG) {
					EMIT_POP_DE(out);
					deisconst = false;
				}
				hlisconst = false;
				break;
			case IR_POP_SEC:
				st = pop_reg_with_type();
				if (st == T_LONG) {
					EMIT_POP_BC(out);
					EMIT_INC_SP(out);
					EMIT_POP_AF(out);
					EMIT_DEC_SP(out);
					bcisconst = false;
				} else {
					EMIT_POP_DE(out);
					deisconst = false;
				}
				break;
			case IR_POP_TER:
				st = pop_reg_with_type();
				if (st == T_LONG) {
					EMIT_POP_BC(out);
					EMIT_INC_SP(out);
					EMIT_POP_AF(out);
					EMIT_DEC_SP(out);
				} else {
					EMIT_POP_BC(out);
				}
				bcisconst = false;
				break;
			case IR_POP_32:
				st = pop_reg_with_type();
				EMIT_POP_BC(out);
				EMIT_INC_SP(out);
				EMIT_POP_AF(out);
				EMIT_DEC_SP(out);
				bcisconst = false;
				break;
			case IR_EX_SEC_PRI:
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_LONG || st == T_LONG) {
					bcisconst = false;
				}
				deisconst = false;
				hlisconst = false;
				ez80_exchange_primary_secondary(bt);
				l = st;
				st = bt;
				bt = l;
				break;
			case IR_CALL:
				expr++;
				if (expr[0] == IR_ADJ && (expr[2] == IR_LEAVE || expr[2] == IR_EXIT)) {
					EMIT_LD_SP_IX(out);
					EMIT_POP_IX(out);
					resolve_later(out + 1 - outstart, arg);
					EMIT_JP_IMM(out, 0);
					expr = &expr[3];
				} else if (expr[0] == IR_LEAVE || expr[0] == IR_EXIT) {
					EMIT_LD_SP_IX(out);
					EMIT_POP_IX(out);
					resolve_later(out + 1 - outstart, arg);
					EMIT_JP_IMM(out, 0);
					expr++;
				} else {
					resolve_later(out + 1 - outstart, arg);
					EMIT_CALL_IMM(out, 0);
				}
				bt = ((symbol*)arg)->valtype;
				bcisconst = false;
				deisconst = false;
				hlisconst = false;
				break;
			case IR_ADJ:
				expr++;
				if (arg <= 15) {
					int i = 0;
					while (i < arg) {
						EMIT_POP_BC(out);
						i += 3;
					}
					bcisconst = false;
				} else {
					EMIT_LD_HL_IMM(out, (unsigned)arg);
					EMIT_ADD_HL_SP(out);
					EMIT_LD_SP_HL(out);
					hlisconst = false;
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
			case IR_PUSH_ARG_IMM:
			case IR_PUSH_IMM:
				expr++;
				LOAD_BC(arg);
				EMIT_PUSH_BC(out);
				push_reg_with_type(T_INT);
				break;
			case IR_LEA_LOCAL:
				expr++;
				l = *expr++;
				if ((expr[-4] == IR_PUSH || expr[-4] == IR_PUSH_32) && *expr == IR_EX_SEC_PRI) {
					expr++;
					out = prevprevout;
					if (l == IR_LOAD_CHAR) {
						EMIT_LD_E_IND_IX_DD(out, (unsigned)arg);
						st = T_CHAR;
						deisconst = false;
					} else if (l == IR_LOAD_WORD) {
						EMIT_PUSH_HL(out);
						EMIT_LD_HL_IND_IX_DD(out, (unsigned)arg);
						EMIT_SIS_SUFFIX(out);
						EMIT_EX_DE_HL(out);
						EMIT_POP_HL(out);
						st = T_WORD;
						deisconst = false;
					} else if (l == IR_LOAD_INT) {
						EMIT_LD_DE_IND_IX_DD(out, (unsigned)arg);
						st = T_INT;
						deisconst = false;
					} else if (l == IR_LOAD_LONG) {
						if ((unsigned)(arg+3+0x80) < 0x100) {
							EMIT_LD_DE_IND_IX_DD(out, (unsigned)arg);
							EMIT_LD_C_IND_IX_DD(out, arg+3);
						} else {
							EMIT_PUSH_IX(out);
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_ADD_IX_BC(out);
							EMIT_LD_DE_IND_IX_DD(out, 0);
							EMIT_LD_C_IND_IX_DD(out, 3);
							EMIT_POP_IX(out);
						}
						st = T_LONG;
						deisconst = false;
						bcisconst = false;
					} else {
						EMIT_LD_DE_IND_IX_DD(out, (unsigned)arg);
						st = T_PTR;
						expr--;
						expr--;
						deisconst = false;
					}
				} else {
					if (l == IR_LOAD_CHAR) {
						EMIT_LD_A_IND_IX_DD(out, (unsigned)arg);
						bt = T_CHAR;
					} else if (l == IR_LOAD_WORD) {
						// probably don't *need* to zero the upper byte here
						EMIT_LD_HL_IND_IX_DD(out, (unsigned)arg);
						// EMIT_LD_DE_IND_IX_DD(out, (unsigned)arg);
						// EMIT_SIS_SUFFIX(out);
						// EMIT_EX_DE_HL(out);
						bt = T_WORD;
						// deisconst = false;
						hlisconst = false;
					} else if (l == IR_LOAD_INT) {
						EMIT_LD_HL_IND_IX_DD(out, (unsigned)arg);
						bt = T_INT;
						hlisconst = false;
					} else if (l == IR_LOAD_LONG) {
						if ((unsigned)(arg+3+0x80) < 0x100) {
							EMIT_LD_HL_IND_IX_DD(out, (unsigned)arg);
							EMIT_LD_A_IND_IX_DD(out, arg+3);
						} else {
							EMIT_PUSH_IX(out);
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_ADD_IX_BC(out);
							EMIT_LD_HL_IND_IX_DD(out, 0);
							EMIT_LD_A_IND_IX_DD(out, 3);
							EMIT_POP_IX(out);
							bcisconst = false;
						}
						bt = T_LONG;
						hlisconst = false;
					} else {
						expr--;
						if ((unsigned)(arg+0x80) < 0x100) {
							EMIT_LEA_HL_IX_DD(out, arg);
						} else {
							EMIT_LEA_HL_IX_DD(out, 0);
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_ADD_HL_BC(out);
							bt = T_PTR;
							bcisconst = false;
							hlisconst = false;
						}
					}
				}
				break;
			case IR_LEA_GLOBAL:
				expr++;
				l = *expr++;
				bt = 0;
				if (hlisconst && hlvalue == arg) {
					if (l == IR_LOAD_CHAR) {
						EMIT_LD_A_IND_HL(out);
					} else if (l == IR_LOAD_WORD || l == IR_LOAD_INT) {
						EMIT_LD_HL_IND_HL(out);
					} else if (l == IR_LOAD_LONG) {
						EMIT_LD_DE_IND_HL(out);
						EMIT_INC_HL(out);
						EMIT_INC_HL(out);
						EMIT_INC_HL(out);
						EMIT_LD_A_IND_HL(out);
						EMIT_EX_DE_HL(out);
					} else {
						expr--;
						bt = T_PTR;
					}
				} else {
					if (l == IR_LOAD_CHAR) {
						EMIT_LD_A_IND_IMM(out, (unsigned)arg);
					} else if (l == IR_LOAD_WORD || l == IR_LOAD_INT) {
						EMIT_LD_HL_IND_IMM(out, (unsigned)arg);
						hlisconst = false;
					} else if (l == IR_LOAD_LONG) {
						EMIT_LD_HL_IND_IMM(out, (unsigned)arg);
						EMIT_LD_A_IND_IMM(out, (unsigned)(arg+3));
						deisconst = false;
					} else {
						expr--;
						LOAD_HL(arg);
						bt = T_PTR;
					}
				}
				if (bt == 0) {
					bt = l + T_CHAR - IR_LOAD_CHAR;
				}
				break;
			case IR_STORE_LOCAL:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				l = *expr++;
				if (bt == T_CHAR && l != T_CHAR) {
					EMIT_OR_A(out);
					EMIT_SBC_HL_HL(out);
					if (l == T_LONG) {
						EMIT_LD_E_L(out);
					}
					EMIT_LD_L_A(out);
					bt = l;
					hlisconst = false;
				}
				if ((unsigned)(arg+0x80) < 0x100) {
					if (l == T_CHAR) {
						if (bt == T_CHAR) {
							EMIT_LD_IND_IX_DD_A(out, (unsigned)arg);
						} else {
							EMIT_LD_IND_IX_DD_L(out, (unsigned)arg);
						}
					} else if (l == T_WORD) {
						if ((unsigned)(arg+1+0x80) < 0x100) {
							EMIT_LD_IND_IX_DD_L(out, (unsigned)arg);
							EMIT_LD_IND_IX_DD_H(out, arg+1);
						} else {
							EMIT_INC_IX(out);
							EMIT_LD_IND_IX_DD_L(out, arg-1);
							EMIT_LD_IND_IX_DD_H(out, (unsigned)arg);
							EMIT_DEC_IX(out);
						}
					} else if (l == T_LONG) {
						if ((unsigned)(arg+3+0x80) < 0x100) {
							EMIT_LD_IND_IX_DD_HL(out, (unsigned)arg);
							EMIT_LD_IND_IX_DD_E(out, (unsigned)(arg+3));
						} else {
							EMIT_PUSH_IX(out);
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_ADD_IX_BC(out);
							EMIT_LD_IND_IX_DD_HL(out, 0);
							EMIT_LD_IND_IX_DD_E(out, 3);
							EMIT_POP_IX(out);
							bcisconst = false;
						}
					} else {
						EMIT_LD_IND_IX_DD_HL(out, (unsigned)arg);
					}
				} else {
					if (l != T_CHAR) {
						EMIT_PUSH_HL(out);
						EMIT_PUSH_HL(out);
					}
					EMIT_LEA_HL_IX_DD(out, 0);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_ADD_HL_BC(out);
					if (l == T_CHAR) {
						EMIT_LD_IND_HL_A(out);
					} else {
						EMIT_POP_BC(out);
						if (l == T_WORD) {
							EMIT_LD_IND_HL_C(out);
							EMIT_INC_HL(out);
							EMIT_LD_IND_HL_B(out);
						} else {
							EMIT_LD_IND_HL_BC(out);
							if (l == T_LONG) {
								EMIT_INC_HL(out);
								EMIT_INC_HL(out);
								EMIT_INC_HL(out);
								EMIT_LD_IND_HL_E(out);
							}
						}
						EMIT_POP_HL(out);
					}
					bcisconst = false;
				}
				break;
			case IR_STORE_GLOBAL:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				l = *expr++;
				if (bt == T_CHAR && l != T_CHAR) {
					EMIT_OR_A(out);
					EMIT_SBC_HL_HL(out);
					if (l == T_LONG) {
						EMIT_LD_E_L(out);
					}
					EMIT_LD_L_A(out);
					bt = l;
					hlisconst = false;
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
					deisconst = false;
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
				deisconst = false;
				hlisconst = false;
				bt = T_WORD;
				break;
			case IR_LOAD_INT:
				EMIT_LD_HL_IND_HL(out);
				bt = T_INT;
				hlisconst = false;
				break;
			case IR_LOAD_LONG:
				EMIT_LD_DE_IND_HL(out);
				EMIT_INC_HL(out);
				EMIT_INC_HL(out);
				EMIT_INC_HL(out);
				EMIT_LD_L_IND_HL(out);
				EMIT_EX_DE_HL(out);
				bt = T_LONG;
				deisconst = false;
				hlisconst = false;
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
				bt = ez80_convert_flag_to_char(bt);
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
					hlisconst = false;
				} else {
					EMIT_ADD_HL_BC(out);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					EMIT_JR_NZ_IMM(out, L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_DE(out);
					hlisconst = false;
				}
				bt = T_BOOL_NZF;
				break;
			case IR_LAND:
				bt = ez80_convert_flag_to_char(bt);
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
					hlisconst = false;
				} else {
					EMIT_ADD_HL_BC(out);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					EMIT_JR_NZ_IMM(out, L_EX_DE_HL+L_SBC_HL_DE);
					EMIT_EX_DE_HL(out);
					EMIT_SBC_HL_DE(out);
					hlisconst = false;
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
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__inot);
				}
				hlisconst = false;
				break;
			case IR_OR:
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_OR_E(out);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sor);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lor);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__ior);
				}
				hlisconst = false;
				break;
			case IR_AND:
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_AND_E(out);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sand);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__land);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__iand);
				}
				hlisconst = false;
				break;
			case IR_COMPARE_EQ:
			case IR_COMPARE_NEQ:
				bt = ez80_convert_flag_to_char(bt);
				EMIT_OR_A(out);
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
					hlisconst = false; // DE might not also be const anymore?
				} else if (bt == T_LONG) {
					EMIT_LD_C_A(out);
					EMIT_LD_A_E(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
					hlisconst = false;
				} else {
					EMIT_SBC_HL_DE(out);
					hlisconst = false;
				}
				bt = (op == IR_COMPARE_EQ) ? T_BOOL_ZF : T_BOOL_NZF;
				break;
			case IR_COMPARE_LT:
			case IR_COMPARE_GTEQ:
			case IR_COMPARE_LTEQ:
			case IR_COMPARE_GT:
				bt = ez80_convert_flag_to_char(bt);
				st = ez80_convert_reg_type_secondary(st, bt);
				if (op == IR_COMPARE_LTEQ || op == IR_COMPARE_GT) {
					EMIT_SCF(out);
				} else {
					EMIT_OR_A(out);
				}
				if (bt == T_CHAR) {
					EMIT_SBC_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
					hlisconst = false;
				} else if (bt == T_LONG) {
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_C(out);
					hlisconst = false;
				} else {
					EMIT_SBC_HL_DE(out);
					hlisconst = false;
				}
				bt = (op == IR_COMPARE_LT || op == IR_COMPARE_LTEQ) ? T_BOOL_CF : T_BOOL_NCF;
				break;
			case IR_SHL:
				bt = ez80_convert_flag_to_char(bt);
				st = ez80_convert_reg_type_secondary(st, T_CHAR);
				if (bt == T_CHAR) {
					EMIT_LD_B_E(out);
				} else {
					EMIT_LD_C_E(out);
				}
				// EMIT_EX_DE_HL(out);
				EMIT_LD_C_E(out);
				if (bt == T_CHAR) {
					EMIT_CALL_IMM(out, TI__bshl);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sshl);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lshl);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__ishl);
				}
				bcisconst = false;
				hlisconst = false;
				break;
			case IR_SHR:
				bt = ez80_convert_flag_to_char(bt);
				st = ez80_convert_reg_type_secondary(st, T_CHAR);
				if (bt == T_CHAR) {
					EMIT_LD_B_E(out);
				} else {
					EMIT_LD_C_E(out);
				}
				// EMIT_EX_DE_HL(out);
				EMIT_LD_C_E(out);
				if (bt == T_CHAR) {
					EMIT_CALL_IMM(out, TI__bshru);
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__sshru);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lshru);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__ishru);
				}
				bcisconst = false;
				hlisconst = false;
				break;
			case IR_ADD:
				bt = ez80_convert_flag_to_char(bt);
				ez80_equalize_types(&bt, &st);
				if (bt == T_CHAR) {
					EMIT_ADD_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_ADD_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_ADD_HL_BC(out);
					EMIT_ADC_A_C(out);
				} else {
					EMIT_ADD_HL_DE(out);
				}
				hlisconst = false;
				break;
			case IR_SUB:
				bt = ez80_convert_flag_to_char(bt);
				ez80_equalize_types(&bt, &st);
				if (bt == T_CHAR) {
					EMIT_SUB_A_E(out);
				} else if (bt == T_WORD) {
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_DE(out);
				} else if (bt == T_LONG) {
					EMIT_OR_A(out);
					EMIT_SBC_HL_DE(out);
					EMIT_SBC_A_C(out);
					deisconst = false;
				} else {
					EMIT_OR_A(out);
					EMIT_SBC_HL_DE(out);
				}
				hlisconst = false;
				break;
			case IR_DIV:
				bt = ez80_convert_flag_to_char(bt);
				ez80_equalize_types(&bt, &st);
				if (bt == T_CHAR) {
					EMIT_LD_H_IMM(out, 0);
					EMIT_LD_L_A(out);
					EMIT_LD_B_H(out);
					EMIT_LD_C_E(out);
					EMIT_CALL_IMM(out, TI__sdivu);
					EMIT_LD_A_L(out);
				} else if (bt == T_WORD) {
					EMIT_LD_B_D(out);
					EMIT_LD_C_E(out);
					EMIT_CALL_IMM(out, TI__sdivu);
				} else if (bt == T_LONG) {
					EMIT_PUSH_DE(out);
					EMIT_POP_BC(out);
					EMIT_LD_E_A(out);
					EMIT_CALL_IMM(out, TI__ldivu);
					EMIT_LD_A_E(out);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__idivu);
				}
				bcisconst = false;
				hlisconst = false;
				break;
			case IR_MUL:
				bt = ez80_convert_flag_to_char(bt);
				ez80_equalize_types(&bt, &st);
				if (bt == T_CHAR) {
					EMIT_LD_D_A(out);
					EMIT_MLT_DE(out);
					EMIT_EX_DE_HL(out);
					bt = T_INT;
				} else if (bt == T_WORD) {
					EMIT_CALL_IMM(out, TI__smulu);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lmulu);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__imulu);
				}
				bcisconst = false;
				hlisconst = false;
				break;
			case IR_MOD:
				bt = ez80_convert_flag_to_char(bt);
				ez80_equalize_types(&bt, &st);
				if (bt == T_CHAR) {
					EMIT_LD_H_IMM(out, 0);
					EMIT_LD_L_A(out);
					EMIT_LD_B_H(out);
					EMIT_LD_C_E(out);
					EMIT_CALL_IMM(out, TI__sdivu);
					EMIT_LD_A_L(out);
				} else if (bt == T_WORD) {
					EMIT_LD_B_D(out);
					EMIT_LD_C_E(out);
					EMIT_CALL_IMM(out, TI__sremu);
				} else if (bt == T_LONG) {
					EMIT_CALL_IMM(out, TI__lremu);
					deisconst = false;
				} else {
					EMIT_CALL_IMM(out, TI__idvrmu);
					EMIT_EX_DE_HL(out);
					deisconst = false;
				}
				bcisconst = false;
				hlisconst = false;
				break;
			case IR_NEG:
				bt = ez80_convert_flag_to_char(bt);
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
						bcisconst = false;
					} else {
						EMIT_SBC_HL_DE(out);
					}
				}
				if (bt != T_CHAR) {
					hlisconst = false;
					deisconst = false;
				}
				break;
			case IR_INC:
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_INC_A(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_INC_HL(out);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, 1);
					EMIT_ADD_HL_BC(out);
					EMIT_ADC_A_B(out);
					bcisconst = false;
				} else {
					EMIT_INC_HL(out);
				}
				if (bt != T_CHAR) {
					hlisconst = false;
				}
				break;
			case IR_DEC:
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_DEC_A(out);
				} else if (bt == T_WORD) {
					EMIT_SIS_SUFFIX(out);
					EMIT_DEC_HL(out);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, 1);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					EMIT_SBC_A_B(out);
					bcisconst = false;
				} else {
					EMIT_DEC_HL(out);
				}
				if (bt != T_CHAR) {
					hlisconst = false;
				}
				break;
			case IR_INC_SEC:
				EMIT_INC_DE(out);
				deisconst = false;
				break;
			case IR_INC_TER:
				EMIT_INC_BC(out);
				bcisconst = false;
				break;
			case IR_DEC_SEC:
				EMIT_DEC_DE(out);
				deisconst = false;
				break;
			case IR_DEC_TER:
				EMIT_DEC_BC(out);
				bcisconst = false;
				break;
			case IR_OR_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
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
					EMIT_LD_E_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__lor);
					EMIT_LD_A_E(out);
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__ior);
				}
				if (bt != T_CHAR) {
					hlisconst = false;
					bcisconst = true;
					bcvalue = arg;
				}
				break;
			case IR_AND_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
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
					EMIT_LD_E_A(out);
					EMIT_XOR_A(out);
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__land);
					EMIT_LD_A_E(out);
					deisconst = false;
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__iand);
				}
				if (bt != T_CHAR) {
					hlisconst = false;
					bcisconst = true;
					bcvalue = arg;
				}
				break;
			case IR_COMPARE_NEQ_CONST:
			case IR_COMPARE_EQ_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
					if ((unsigned)arg < 256) {
						EMIT_SBC_A_B(out);
					} else {
						EMIT_SBC_A_IMM(out, 0);
					}
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
				}
				if (bt != T_CHAR) {
					hlisconst = false;
					bcisconst = true;
					bcvalue = arg;
				}
				bt = (op == IR_COMPARE_EQ_CONST ? T_BOOL_ZF : T_BOOL_NZF);
				break;
			case IR_COMPARE_LT_CONST:
			case IR_COMPARE_GTEQ_CONST:
			case IR_COMPARE_LTEQ_CONST:
			case IR_COMPARE_GT_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				if (op == IR_COMPARE_LTEQ_CONST || op == IR_COMPARE_GT_CONST) {
					arg++;
				}
				if (bt == T_CHAR) {
					EMIT_CP_IMM(out, (unsigned)arg);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SIS_SUFFIX(out);
					EMIT_SBC_HL_BC(out);
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
					if ((unsigned)arg < 256) {
						EMIT_SBC_A_B(out);
					} else {
						EMIT_SBC_A_IMM(out, 0);
					}
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_OR_A(out);
					EMIT_SBC_HL_BC(out);
				}
				if (bt != T_CHAR) {
					bcisconst = true;
					bcvalue = arg;
				}
				hlisconst = false;
				bt = (op == IR_COMPARE_LT_CONST || op == IR_COMPARE_LTEQ_CONST) ? T_BOOL_CF : T_BOOL_NCF;
				break;
			case IR_SHL_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					if (arg >= 8) {
						EMIT_XOR_A(out);
					} else if (arg > L_LD_B_E+L_ADD_A_A+L_DJNZ_IMM) {
						EMIT_LD_B_IMM(out, (unsigned)arg);
						EMIT_ADD_A_A(out);
						EMIT_DJNZ_IMM(out, -(L_DJNZ_IMM+L_ADD_A_A));
						bcisconst = false;
					} else {
						while (arg-- > 0) {
							EMIT_ADD_A_A(out);
						}
					}
				} else if (bt == T_LONG) {
					if (arg >= 32) {
						EMIT_XOR_A(out);
						EMIT_SBC_HL_HL(out);
					} else if (arg == 1) {
						EMIT_ADD_HL_HL(out);
						EMIT_ADC_A_A(out);
					} else {
						EMIT_LD_C_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__lshl);
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
						bcisconst = false;
					} else {
						while (arg-- > 0) {
							EMIT_ADD_HL_HL(out);
						}
					}
					/*
					if (bt == T_WORD) {
						EMIT_SIS_SUFFIX(out);
						EMIT_EX_DE_HL(out);
						EMIT_EX_DE_HL(out);
						deisconst = false;
					}
					*/
				}
				hlisconst = false;
				break;
			case IR_SHR_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					if (arg >= 8) {
						EMIT_XOR_A(out);
					} else if (arg > (L_LD_B_E+L_OR_A+L_RRA+L_DJNZ_IMM)/(L_OR_A+L_RRA)) {
						EMIT_LD_B_IMM(out, (unsigned)arg);
						EMIT_OR_A(out);
						EMIT_RRA(out);
						EMIT_DJNZ_IMM(out, -(L_DJNZ_IMM+L_RRA+L_OR_A));
						bcisconst = false;
					} else {
						while (arg-- > 0) {
							EMIT_OR_A(out);
							EMIT_RRA(out);
						}
					}
				} else if (bt == T_WORD) {
					if (arg >= 16) {
						EMIT_LD_H_IMM(out, 0);
						EMIT_LD_L_H(out);
						hlisconst = true;
						hlvalue = 0;
					} else {
						EMIT_LD_C_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__sshru);
						bcisconst = false;
						hlisconst = false;
					}
				} else if (bt == T_LONG) {
					if (arg >= 32) {
						EMIT_XOR_A(out);
						EMIT_SBC_HL_HL(out);
						hlisconst = true;
						hlvalue = 0;
					} else {
						EMIT_LD_C_IMM(out, (unsigned)arg);
						EMIT_LD_E_A(out);
						EMIT_CALL_IMM(out, TI__lshru);
						EMIT_LD_A_E(out);
						bcisconst = false;
						hlisconst = false;
					}
				} else {
					if (arg >= 24) {
						EMIT_OR_A(out);
						EMIT_SBC_HL_HL(out);
						hlisconst = true;
						hlvalue = 0;
					} else {
						EMIT_LD_C_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__ishru);
						bcisconst = false;
						hlisconst = false;
					}
				}
				break;
			case IR_ADD_CONST:
				expr++;
				if (arg != 0) {
					bt = ez80_convert_flag_to_char(bt);
					if (bt == T_CHAR) {
						if (arg == 1) {
							EMIT_INC_A(out);
						} else if (arg == -1) {
							EMIT_DEC_A(out);
						} else {
							EMIT_ADD_A_IMM(out, (unsigned)arg);
						}
					} else if (bt == T_LONG) {
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_ADD_HL_BC(out);
						if ((unsigned)arg < 256) {
							EMIT_ADC_A_B(out);
						} else {
							EMIT_ADC_A_IMM(out, 0);
						}
						bcisconst = true;
						bcvalue = arg;
					} else {
						if (bt == T_WORD) {
							EMIT_SIS_SUFFIX(out);
						}
						if (arg == 1) {
							EMIT_INC_HL(out);
						} else if (arg == -1) {
							EMIT_DEC_HL(out);
						} else {
							out -= L_SIS_SUFFIX;
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							if (bt == T_WORD) {
								EMIT_SIS_SUFFIX(out);
							}
							EMIT_ADD_HL_BC(out);
						}
						bcisconst = true;
						bcvalue = arg;
					}
				}
				hlisconst = false;
				break;
			case IR_SUB_CONST:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				if (bt == T_CHAR) {
					EMIT_SUB_A_IMM(out, (unsigned)arg);
					break;
				} else if (bt == T_LONG) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_SBC_HL_BC(out);
					if ((unsigned)arg < 256) {
						EMIT_SBC_A_B(out);
					} else {
						EMIT_SBC_A_IMM(out, 0);
					}
				} else {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					if (bt == T_WORD) {
						EMIT_SIS_SUFFIX(out);
					}
					EMIT_SBC_HL_BC(out);
				}
				bcisconst = true;
				bcvalue = arg;
				hlisconst = false;
				break;
			case IR_MUL_CONST:
				expr++;
				if (arg == 1) {
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
						hlisconst = false;
						bt = T_INT;
					}
				} else {
					if (bt == T_CHAR) {
						EMIT_LD_H_IMM(out, (unsigned)arg);
						EMIT_LD_L_A(out);
						EMIT_MLT_HL(out);
						bt = T_WORD;
					} else if (bt == T_LONG) {
						if (arg == 0) {
							EMIT_XOR_A(out);
							EMIT_SBC_HL_HL(out);
							hlisconst = true;
							hlvalue = 0;
						} else if (arg == 2) {
							EMIT_ADD_HL_HL(out);
							EMIT_ADC_A_A(out);
							hlisconst = false;
						} else if (arg > 2) {
							EMIT_LD_DE_IMM(out, (unsigned)arg);
							if ((unsigned)arg < 256) {
								EMIT_LD_C_D(out);
							} else {
								EMIT_LD_C_IMM(out, 0);
							}
							EMIT_CALL_IMM(out, TI__lmulu);
							hlisconst = false;
							deisconst = true;
							devalue = arg;
						}
					} else {
						if (arg == 0) {
							EMIT_OR_A(out);
							EMIT_SBC_HL_HL(out);
							hlisconst = true;
							hlvalue = 0;
						} else if (arg == 2) {
							EMIT_ADD_HL_HL(out);
						} else if (arg == 3) {
							EMIT_PUSH_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_POP_DE(out);
							EMIT_ADD_HL_DE(out);
							deisconst = false;
						} else if (arg == 4) {
							EMIT_ADD_HL_HL(out);
							EMIT_ADD_HL_HL(out);
						} else if (arg == 5) {
							EMIT_PUSH_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_POP_DE(out);
							EMIT_ADD_HL_DE(out);
							deisconst = false;
						} else if (arg == 6) {
							EMIT_PUSH_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_POP_DE(out);
							EMIT_ADD_HL_DE(out);
							EMIT_ADD_HL_DE(out);
							deisconst = false;
						} else if (arg == 7) {
							EMIT_PUSH_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_POP_DE(out);
							EMIT_ADD_HL_DE(out);
							EMIT_ADD_HL_DE(out);
							EMIT_ADD_HL_DE(out);
							deisconst = false;
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
							deisconst = false;
						} else if (arg == 10) {
							EMIT_ADD_HL_HL(out);
							EMIT_PUSH_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_POP_DE(out);
							EMIT_ADD_HL_DE(out);
							deisconst = false;
						} else if (arg == 16) {
							EMIT_ADD_HL_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_ADD_HL_HL(out);
							EMIT_ADD_HL_HL(out);
						} else if (arg > 2) {
							EMIT_LD_BC_IMM(out, (unsigned)arg);
							EMIT_CALL_IMM(out, TI__imulu);
							bcisconst = true;
							bcvalue = arg;
						}
					}
					hlisconst = false;
				}
				break;
			case IR_DIV_CONST:
				expr++;
				if (arg != 1) {
					if (arg == 0) {
						EMIT_SCF(out);
						EMIT_SBC_HL_HL(out);
						bt = T_INT;
						hlisconst = true;
						hlvalue = -1;
						break;
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
							EMIT_LD_H_IMM(out, 0);
							EMIT_LD_L_A(out);
							EMIT_LD_B_H(out);
							EMIT_LD_C_E(out);
							EMIT_CALL_IMM(out, TI__sdivu);
							EMIT_LD_A_L(out);
						}
					} else if (bt == T_WORD) {
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__sdivu);
					} else if (bt == T_LONG) {
						EMIT_LD_E_A(out);
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_XOR_A(out);
						EMIT_CALL_IMM(out, TI__ldivu);
						EMIT_LD_A_E(out);
					} else {
						EMIT_LD_BC_IMM(out, (unsigned)arg);
						EMIT_CALL_IMM(out, TI__idivu);
					}
					bcisconst = true;
					bcvalue = arg;
					hlisconst = false;
				}
				break;
			case IR_MOD_CONST:
				expr++;
				if (arg == 0) {
					EMIT_SCF(out);
					EMIT_SBC_HL_HL(out);
					bt = T_INT;
					hlisconst = true;
					hlvalue = -1;
					break;
				} else if (bt >= T_BOOL_CF && bt <= T_BOOL_NZF) {
					bt = ez80_convert_flag_to_char(bt);
				} else if (bt == T_CHAR) {
					EMIT_LD_H_IMM(out, 0);
					EMIT_LD_L_A(out);
					EMIT_LD_B_H(out);
					EMIT_LD_C_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__sremu);
				} else if (bt == T_WORD) {
					EMIT_LD_BC_IMM(out, (unsigned)arg);
					EMIT_CALL_IMM(out, TI__sremu);
					break;
				} else if (bt == T_LONG) {
					EMIT_LD_E_A(out);
					EMIT_LD_BC_IMM(out, arg);
					EMIT_XOR_A(out);
					EMIT_CALL_IMM(out, TI__lremu);
					EMIT_LD_A_E(out);
				} else {
					EMIT_LD_BC_IMM(out, arg);
					EMIT_CALL_IMM(out, TI__iremu);
				}
				bcisconst = true;
				bcvalue = arg;
				hlisconst = false;
				break;
			case IR_JMP:
				expr++;
				resolve_later(out + 1 - outstart, arg);
				EMIT_JP_IMM(out, 0);
				bcisconst = false;
				deisconst = false;
				hlisconst = false;
				break;
			case IR_BZ:
			case IR_BNZ:
				expr++;
				if (bt >= T_BOOL_CF && bt <= T_BOOL_NCF) {
					if ((bt ^ (op - IR_BZ)) & 1) {
						EMIT_JP_NC_IMM(out, 0);
					} else {
						EMIT_JP_C_IMM(out, 0);
					}
				} else if (bt >= T_BOOL_ZF && bt <= T_BOOL_NZF) {
					if ((bt ^ (op - IR_BZ)) & 1) {
						EMIT_JP_NZ_IMM(out, 0);
					} else {
						EMIT_JP_Z_IMM(out, 0);
					}
				} else {
					bt = ez80_convert_to_zf(bt);
					if (op == IR_BZ) {
						EMIT_JP_Z_IMM(out, 0);
					} else {
						EMIT_JP_NZ_IMM(out, 0);
					}
				}
				resolve_later(out + -3 - outstart, arg);
				break;
			case IR_STRLEN:
				EMIT_PUSH_HL(out);
				EMIT_CALL_IMM(out, TI__strlen);
				EMIT_POP_BC(out);
				bcisconst = hlisconst;
				bcvalue = hlvalue;
				hlisconst = false;
				break;
			case IR_STORE:
				expr++;
				bt = ez80_convert_flag_to_char(bt);
				bt = ez80_convert_reg_type(bt, arg);
				st = ez80_convert_reg_type_secondary(st, T_PTR);
				if (bt == T_CHAR) {
					EMIT_LD_IND_DE_A(out);
				} else if (bt == T_WORD) {
					EMIT_EX_DE_HL(out);
					EMIT_LD_IND_HL_E(out);
					EMIT_INC_HL(out);
					EMIT_LD_IND_HL_D(out);
					EMIT_EX_DE_HL(out);
					deisconst = false;
				} else if (bt == T_INT) {
					EMIT_EX_DE_HL(out);
					EMIT_LD_IND_HL_DE(out);
					EMIT_EX_DE_HL(out);
					deisconst = false;
				} else if (bt == T_LONG) {
					EMIT_EX_DE_HL(out);
					EMIT_LD_IND_HL_DE(out);
					EMIT_INC_HL(out);
					EMIT_INC_HL(out);
					EMIT_INC_HL(out);
					EMIT_LD_IND_HL_A(out);
					EMIT_EX_DE_HL(out);
					deisconst = false;
					hlisconst = false;
				}
				break;
			case IR_STRCPY:
				EMIT_PUSH_BC(out);
				EMIT_PUSH_HL(out);
				EMIT_CALL_IMM(out, TI__strcpy);
				EMIT_POP_HL(out);
				EMIT_POP_BC(out);
				deisconst = false;
				break;
			case IR_DEFINE_FUNCTION:
				expr++;
				bcisconst = false;
				deisconst = false;
				hlisconst = false;
				break;
			case IR_SET_BT:
				bt = arg;
				expr++;
				break;
			case IR_SET_ST:
				st = arg;
				expr++;
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
