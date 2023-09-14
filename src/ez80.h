#ifndef __EZ80_H__
#define __EZ80_H__
// eZ80 opcode defines. Generated from http://mdfs.net/Docs.Comp.eZ80.OpList
// Opcode values are defined little-endian.
// Opcodes are uppercase with underscores for spaces, IND for indirects, IMM for immediates, DD for displacements, etc.
// Each opcode has an accompanying define for how long (in bytes) the opcode (including arguments) is.
// A macro is defined for emitting each opcode to a pointer.

#define EMIT_8(p,o) (*(uint8_t*)(p)++ = (o))
#define EMIT_16(p,o) {*(uint16_t*)(p) = (o); (p) += 2;}
#ifndef uint24_t
#define EMIT_24(p,o) {EMIT_16(p,o); EMIT_8(p,(o)>>16);}
#else
#define EMIT_24(p,o) {*(uint24_t*)(p) = (o); (p) += 3;}
#endif
#define EMIT_32(p,o) {*(uint32_t*)(p) = (o); (p) += 4;}
#define EMIT_8_8(p,o,v) EMIT_16(p,(o)|((v)<<8))
#define EMIT_16_8(p,o,v) EMIT_24(p,(o)|((v)<<16))
#define EMIT_8_24(p,o,v) EMIT_32(p,(o)|((v)<<8))
#define EMIT_8_8_8(p,o,d,v) EMIT_24(p,(o)|((d)<<8)|((v)<<16))
#define EMIT_16_8_8(p,o,d,v) EMIT_32(p,(o)|((d)<<16)|((v)<<24))
#define EMIT_16_24(p,o,v) {EMIT_16(p,o); EMIT_24(p,v);}

#define O_NOP 0x00
#define L_NOP 1
#define EMIT_NOP(p) EMIT_8(p, O_NOP)
#define O_LD_BC_IMM 0x01
#define L_LD_BC_IMM 3
#define EMIT_LD_BC_IMM(p,v) EMIT_8_24(p, O_LD_BC_IMM, v)
#define O_LD_IND_BC_A 0x02
#define L_LD_IND_BC_A 1
#define EMIT_LD_IND_BC_A(p) EMIT_8(p, O_LD_IND_BC_A)
#define O_INC_BC 0x03
#define L_INC_BC 1
#define EMIT_INC_BC(p) EMIT_8(p, O_INC_BC)
#define O_INC_B 0x04
#define L_INC_B 1
#define EMIT_INC_B(p) EMIT_8(p, O_INC_B)
#define O_DEC_B 0x05
#define L_DEC_B 1
#define EMIT_DEC_B(p) EMIT_8(p, O_DEC_B)
#define O_LD_B_IMM 0x06
#define L_LD_B_IMM 2
#define EMIT_LD_B_IMM(p,v) EMIT_8_8(p, O_LD_B_IMM, v)
#define O_RLCA 0x07
#define L_RLCA 1
#define EMIT_RLCA(p) EMIT_8(p, O_RLCA)
#define O_EX_AF_AF 0x08
#define L_EX_AF_AF 1
#define EMIT_EX_AF_AF(p) EMIT_8(p, O_EX_AF_AF)
#define O_ADD_HL_BC 0x09
#define L_ADD_HL_BC 1
#define EMIT_ADD_HL_BC(p) EMIT_8(p, O_ADD_HL_BC)
#define O_LD_A_IND_BC 0x0A
#define L_LD_A_IND_BC 1
#define EMIT_LD_A_IND_BC(p) EMIT_8(p, O_LD_A_IND_BC)
#define O_DEC_BC 0x0B
#define L_DEC_BC 1
#define EMIT_DEC_BC(p) EMIT_8(p, O_DEC_BC)
#define O_INC_C 0x0C
#define L_INC_C 1
#define EMIT_INC_C(p) EMIT_8(p, O_INC_C)
#define O_DEC_C 0x0D
#define L_DEC_C 1
#define EMIT_DEC_C(p) EMIT_8(p, O_DEC_C)
#define O_LD_C_IMM 0x0E
#define L_LD_C_IMM 2
#define EMIT_LD_C_IMM(p,v) EMIT_8_8(p, O_LD_C_IMM, v)
#define O_RRCA 0x0F
#define L_RRCA 1
#define EMIT_RRCA(p) EMIT_8(p, O_RRCA)
#define O_DJNZ_IMM 0x10
#define L_DJNZ_IMM 2
#define EMIT_DJNZ_IMM(p,v) EMIT_8_8(p, O_DJNZ_IMM, v)
#define O_LD_DE_IMM 0x11
#define L_LD_DE_IMM 3
#define EMIT_LD_DE_IMM(p,v) EMIT_8_24(p, O_LD_DE_IMM, v)
#define O_LD_IND_DE_A 0x12
#define L_LD_IND_DE_A 1
#define EMIT_LD_IND_DE_A(p) EMIT_8(p, O_LD_IND_DE_A)
#define O_INC_DE 0x13
#define L_INC_DE 1
#define EMIT_INC_DE(p) EMIT_8(p, O_INC_DE)
#define O_INC_D 0x14
#define L_INC_D 1
#define EMIT_INC_D(p) EMIT_8(p, O_INC_D)
#define O_DEC_D 0x15
#define L_DEC_D 1
#define EMIT_DEC_D(p) EMIT_8(p, O_DEC_D)
#define O_LD_D_IMM 0x16
#define L_LD_D_IMM 2
#define EMIT_LD_D_IMM(p,v) EMIT_8_8(p, O_LD_D_IMM, v)
#define O_RLA 0x17
#define L_RLA 1
#define EMIT_RLA(p) EMIT_8(p, O_RLA)
#define O_JR_IMM 0x18
#define L_JR_IMM 2
#define EMIT_JR_IMM(p,v) EMIT_8_8(p, O_JR_IMM, v)
#define O_ADD_HL_DE 0x19
#define L_ADD_HL_DE 1
#define EMIT_ADD_HL_DE(p) EMIT_8(p, O_ADD_HL_DE)
#define O_LD_A_IND_DE 0x1A
#define L_LD_A_IND_DE 1
#define EMIT_LD_A_IND_DE(p) EMIT_8(p, O_LD_A_IND_DE)
#define O_DEC_DE 0x1B
#define L_DEC_DE 1
#define EMIT_DEC_DE(p) EMIT_8(p, O_DEC_DE)
#define O_INC_E 0x1C
#define L_INC_E 1
#define EMIT_INC_E(p) EMIT_8(p, O_INC_E)
#define O_DEC_E 0x1D
#define L_DEC_E 1
#define EMIT_DEC_E(p) EMIT_8(p, O_DEC_E)
#define O_LD_E_IMM 0x1E
#define L_LD_E_IMM 2
#define EMIT_LD_E_IMM(p,v) EMIT_8_8(p, O_LD_E_IMM, v)
#define O_RRA 0x1F
#define L_RRA 1
#define EMIT_RRA(p) EMIT_8(p, O_RRA)
#define O_JR_NZ_IMM 0x20
#define L_JR_NZ_IMM 2
#define EMIT_JR_NZ_IMM(p,v) EMIT_8_8(p, O_JR_NZ_IMM, v)
#define O_LD_HL_IMM 0x21
#define L_LD_HL_IMM 3
#define EMIT_LD_HL_IMM(p,v) EMIT_8_24(p, O_LD_HL_IMM, v)
#define O_LD_IND_IMM_HL 0x22
#define L_LD_IND_IMM_HL 3
#define EMIT_LD_IND_IMM_HL(p,v) EMIT_8_24(p, O_LD_IND_IMM_HL, v)
#define O_INC_HL 0x23
#define L_INC_HL 1
#define EMIT_INC_HL(p) EMIT_8(p, O_INC_HL)
#define O_INC_H 0x24
#define L_INC_H 1
#define EMIT_INC_H(p) EMIT_8(p, O_INC_H)
#define O_DEC_H 0x25
#define L_DEC_H 1
#define EMIT_DEC_H(p) EMIT_8(p, O_DEC_H)
#define O_LD_H_IMM 0x26
#define L_LD_H_IMM 2
#define EMIT_LD_H_IMM(p,v) EMIT_8_8(p, O_LD_H_IMM, v)
#define O_DAA 0x27
#define L_DAA 1
#define EMIT_DAA(p) EMIT_8(p, O_DAA)
#define O_JR_Z_IMM 0x28
#define L_JR_Z_IMM 2
#define EMIT_JR_Z_IMM(p,v) EMIT_8_8(p, O_JR_Z_IMM, v)
#define O_ADD_HL_HL 0x29
#define L_ADD_HL_HL 1
#define EMIT_ADD_HL_HL(p) EMIT_8(p, O_ADD_HL_HL)
#define O_LD_HL_IND_IMM 0x2A
#define L_LD_HL_IND_IMM 3
#define EMIT_LD_HL_IND_IMM(p,v) EMIT_8_24(p, O_LD_HL_IND_IMM, v)
#define O_DEC_HL 0x2B
#define L_DEC_HL 1
#define EMIT_DEC_HL(p) EMIT_8(p, O_DEC_HL)
#define O_INC_L 0x2C
#define L_INC_L 1
#define EMIT_INC_L(p) EMIT_8(p, O_INC_L)
#define O_DEC_L 0x2D
#define L_DEC_L 1
#define EMIT_DEC_L(p) EMIT_8(p, O_DEC_L)
#define O_LD_L_IMM 0x2E
#define L_LD_L_IMM 2
#define EMIT_LD_L_IMM(p,v) EMIT_8_8(p, O_LD_L_IMM, v)
#define O_CPL 0x2F
#define L_CPL 1
#define EMIT_CPL(p) EMIT_8(p, O_CPL)
#define O_JR_NC_IMM 0x30
#define L_JR_NC_IMM 2
#define EMIT_JR_NC_IMM(p,v) EMIT_8_8(p, O_JR_NC_IMM, v)
#define O_LD_SP_IMM 0x31
#define L_LD_SP_IMM 3
#define EMIT_LD_SP_IMM(p,v) EMIT_8_24(p, O_LD_SP_IMM, v)
#define O_LD_IND_IMM_A 0x32
#define L_LD_IND_IMM_A 3
#define EMIT_LD_IND_IMM_A(p,v) EMIT_8_24(p, O_LD_IND_IMM_A, v)
#define O_INC_SP 0x33
#define L_INC_SP 1
#define EMIT_INC_SP(p) EMIT_8(p, O_INC_SP)
#define O_INC_IND_HL 0x34
#define L_INC_IND_HL 1
#define EMIT_INC_IND_HL(p) EMIT_8(p, O_INC_IND_HL)
#define O_DEC_IND_HL 0x35
#define L_DEC_IND_HL 1
#define EMIT_DEC_IND_HL(p) EMIT_8(p, O_DEC_IND_HL)
#define O_LD_IND_HL_IMM 0x36
#define L_LD_IND_HL_IMM 2
#define EMIT_LD_IND_HL_IMM(p,v) EMIT_8_8(p, O_LD_IND_HL_IMM, v)
#define O_SCF 0x37
#define L_SCF 1
#define EMIT_SCF(p) EMIT_8(p, O_SCF)
#define O_JR_C_IMM 0x38
#define L_JR_C_IMM 2
#define EMIT_JR_C_IMM(p,v) EMIT_8_8(p, O_JR_C_IMM, v)
#define O_ADD_HL_SP 0x39
#define L_ADD_HL_SP 1
#define EMIT_ADD_HL_SP(p) EMIT_8(p, O_ADD_HL_SP)
#define O_LD_A_IND_IMM 0x3A
#define L_LD_A_IND_IMM 3
#define EMIT_LD_A_IND_IMM(p,v) EMIT_8_24(p, O_LD_A_IND_IMM, v)
#define O_DEC_SP 0x3B
#define L_DEC_SP 1
#define EMIT_DEC_SP(p) EMIT_8(p, O_DEC_SP)
#define O_INC_A 0x3C
#define L_INC_A 1
#define EMIT_INC_A(p) EMIT_8(p, O_INC_A)
#define O_DEC_A 0x3D
#define L_DEC_A 1
#define EMIT_DEC_A(p) EMIT_8(p, O_DEC_A)
#define O_LD_A_IMM 0x3E
#define L_LD_A_IMM 2
#define EMIT_LD_A_IMM(p,v) EMIT_8_8(p, O_LD_A_IMM, v)
#define O_CCF 0x3F
#define L_CCF 1
#define EMIT_CCF(p) EMIT_8(p, O_CCF)
#define O_SIS_SUFFIX 0x40
#define L_SIS_SUFFIX 1
#define EMIT_SIS_SUFFIX(p) EMIT_8(p, O_SIS_SUFFIX)
#define O_LD_B_C 0x41
#define L_LD_B_C 1
#define EMIT_LD_B_C(p) EMIT_8(p, O_LD_B_C)
#define O_LD_B_D 0x42
#define L_LD_B_D 1
#define EMIT_LD_B_D(p) EMIT_8(p, O_LD_B_D)
#define O_LD_B_E 0x43
#define L_LD_B_E 1
#define EMIT_LD_B_E(p) EMIT_8(p, O_LD_B_E)
#define O_LD_B_H 0x44
#define L_LD_B_H 1
#define EMIT_LD_B_H(p) EMIT_8(p, O_LD_B_H)
#define O_LD_B_L 0x45
#define L_LD_B_L 1
#define EMIT_LD_B_L(p) EMIT_8(p, O_LD_B_L)
#define O_LD_B_IND_HL 0x46
#define L_LD_B_IND_HL 1
#define EMIT_LD_B_IND_HL(p) EMIT_8(p, O_LD_B_IND_HL)
#define O_LD_B_A 0x47
#define L_LD_B_A 1
#define EMIT_LD_B_A(p) EMIT_8(p, O_LD_B_A)
#define O_LD_C_B 0x48
#define L_LD_C_B 1
#define EMIT_LD_C_B(p) EMIT_8(p, O_LD_C_B)
#define O_LIS_SUFFIX 0x49
#define L_LIS_SUFFIX 1
#define EMIT_LIS_SUFFIX(p) EMIT_8(p, O_LIS_SUFFIX)
#define O_LD_C_D 0x4A
#define L_LD_C_D 1
#define EMIT_LD_C_D(p) EMIT_8(p, O_LD_C_D)
#define O_LD_C_E 0x4B
#define L_LD_C_E 1
#define EMIT_LD_C_E(p) EMIT_8(p, O_LD_C_E)
#define O_LD_C_H 0x4C
#define L_LD_C_H 1
#define EMIT_LD_C_H(p) EMIT_8(p, O_LD_C_H)
#define O_LD_C_L 0x4D
#define L_LD_C_L 1
#define EMIT_LD_C_L(p) EMIT_8(p, O_LD_C_L)
#define O_LD_C_IND_HL 0x4E
#define L_LD_C_IND_HL 1
#define EMIT_LD_C_IND_HL(p) EMIT_8(p, O_LD_C_IND_HL)
#define O_LD_C_A 0x4F
#define L_LD_C_A 1
#define EMIT_LD_C_A(p) EMIT_8(p, O_LD_C_A)
#define O_LD_D_B 0x50
#define L_LD_D_B 1
#define EMIT_LD_D_B(p) EMIT_8(p, O_LD_D_B)
#define O_LD_D_C 0x51
#define L_LD_D_C 1
#define EMIT_LD_D_C(p) EMIT_8(p, O_LD_D_C)
#define O_SIL_SUFFIX 0x52
#define L_SIL_SUFFIX 1
#define EMIT_SIL_SUFFIX(p) EMIT_8(p, O_SIL_SUFFIX)
#define O_LD_D_E 0x53
#define L_LD_D_E 1
#define EMIT_LD_D_E(p) EMIT_8(p, O_LD_D_E)
#define O_LD_D_H 0x54
#define L_LD_D_H 1
#define EMIT_LD_D_H(p) EMIT_8(p, O_LD_D_H)
#define O_LD_D_L 0x55
#define L_LD_D_L 1
#define EMIT_LD_D_L(p) EMIT_8(p, O_LD_D_L)
#define O_LD_D_IND_HL 0x56
#define L_LD_D_IND_HL 1
#define EMIT_LD_D_IND_HL(p) EMIT_8(p, O_LD_D_IND_HL)
#define O_LD_D_A 0x57
#define L_LD_D_A 1
#define EMIT_LD_D_A(p) EMIT_8(p, O_LD_D_A)
#define O_LD_E_B 0x58
#define L_LD_E_B 1
#define EMIT_LD_E_B(p) EMIT_8(p, O_LD_E_B)
#define O_LD_E_C 0x59
#define L_LD_E_C 1
#define EMIT_LD_E_C(p) EMIT_8(p, O_LD_E_C)
#define O_LD_E_D 0x5A
#define L_LD_E_D 1
#define EMIT_LD_E_D(p) EMIT_8(p, O_LD_E_D)
#define O_LIL_SUFFIX 0x5B
#define L_LIL_SUFFIX 1
#define EMIT_LIL_SUFFIX(p) EMIT_8(p, O_LIL_SUFFIX)
#define O_LD_E_H 0x5C
#define L_LD_E_H 1
#define EMIT_LD_E_H(p) EMIT_8(p, O_LD_E_H)
#define O_LD_E_L 0x5D
#define L_LD_E_L 1
#define EMIT_LD_E_L(p) EMIT_8(p, O_LD_E_L)
#define O_LD_E_IND_HL 0x5E
#define L_LD_E_IND_HL 1
#define EMIT_LD_E_IND_HL(p) EMIT_8(p, O_LD_E_IND_HL)
#define O_LD_E_A 0x5F
#define L_LD_E_A 1
#define EMIT_LD_E_A(p) EMIT_8(p, O_LD_E_A)
#define O_LD_H_B 0x60
#define L_LD_H_B 1
#define EMIT_LD_H_B(p) EMIT_8(p, O_LD_H_B)
#define O_LD_H_C 0x61
#define L_LD_H_C 1
#define EMIT_LD_H_C(p) EMIT_8(p, O_LD_H_C)
#define O_LD_H_D 0x62
#define L_LD_H_D 1
#define EMIT_LD_H_D(p) EMIT_8(p, O_LD_H_D)
#define O_LD_H_E 0x63
#define L_LD_H_E 1
#define EMIT_LD_H_E(p) EMIT_8(p, O_LD_H_E)
#define O_LD_H_H 0x64
#define L_LD_H_H 1
#define EMIT_LD_H_H(p) EMIT_8(p, O_LD_H_H)
#define O_LD_H_L 0x65
#define L_LD_H_L 1
#define EMIT_LD_H_L(p) EMIT_8(p, O_LD_H_L)
#define O_LD_H_IND_HL 0x66
#define L_LD_H_IND_HL 1
#define EMIT_LD_H_IND_HL(p) EMIT_8(p, O_LD_H_IND_HL)
#define O_LD_H_A 0x67
#define L_LD_H_A 1
#define EMIT_LD_H_A(p) EMIT_8(p, O_LD_H_A)
#define O_LD_L_B 0x68
#define L_LD_L_B 1
#define EMIT_LD_L_B(p) EMIT_8(p, O_LD_L_B)
#define O_LD_L_C 0x69
#define L_LD_L_C 1
#define EMIT_LD_L_C(p) EMIT_8(p, O_LD_L_C)
#define O_LD_L_D 0x6A
#define L_LD_L_D 1
#define EMIT_LD_L_D(p) EMIT_8(p, O_LD_L_D)
#define O_LD_L_E 0x6B
#define L_LD_L_E 1
#define EMIT_LD_L_E(p) EMIT_8(p, O_LD_L_E)
#define O_LD_L_H 0x6C
#define L_LD_L_H 1
#define EMIT_LD_L_H(p) EMIT_8(p, O_LD_L_H)
#define O_LD_L_L 0x6D
#define L_LD_L_L 1
#define EMIT_LD_L_L(p) EMIT_8(p, O_LD_L_L)
#define O_LD_L_IND_HL 0x6E
#define L_LD_L_IND_HL 1
#define EMIT_LD_L_IND_HL(p) EMIT_8(p, O_LD_L_IND_HL)
#define O_LD_L_A 0x6F
#define L_LD_L_A 1
#define EMIT_LD_L_A(p) EMIT_8(p, O_LD_L_A)
#define O_LD_IND_HL_B 0x70
#define L_LD_IND_HL_B 1
#define EMIT_LD_IND_HL_B(p) EMIT_8(p, O_LD_IND_HL_B)
#define O_LD_IND_HL_C 0x71
#define L_LD_IND_HL_C 1
#define EMIT_LD_IND_HL_C(p) EMIT_8(p, O_LD_IND_HL_C)
#define O_LD_IND_HL_D 0x72
#define L_LD_IND_HL_D 1
#define EMIT_LD_IND_HL_D(p) EMIT_8(p, O_LD_IND_HL_D)
#define O_LD_IND_HL_E 0x73
#define L_LD_IND_HL_E 1
#define EMIT_LD_IND_HL_E(p) EMIT_8(p, O_LD_IND_HL_E)
#define O_LD_IND_HL_H 0x74
#define L_LD_IND_HL_H 1
#define EMIT_LD_IND_HL_H(p) EMIT_8(p, O_LD_IND_HL_H)
#define O_LD_IND_HL_L 0x75
#define L_LD_IND_HL_L 1
#define EMIT_LD_IND_HL_L(p) EMIT_8(p, O_LD_IND_HL_L)
#define O_HALT 0x76
#define L_HALT 1
#define EMIT_HALT(p) EMIT_8(p, O_HALT)
#define O_LD_IND_HL_A 0x77
#define L_LD_IND_HL_A 1
#define EMIT_LD_IND_HL_A(p) EMIT_8(p, O_LD_IND_HL_A)
#define O_LD_A_B 0x78
#define L_LD_A_B 1
#define EMIT_LD_A_B(p) EMIT_8(p, O_LD_A_B)
#define O_LD_A_C 0x79
#define L_LD_A_C 1
#define EMIT_LD_A_C(p) EMIT_8(p, O_LD_A_C)
#define O_LD_A_D 0x7A
#define L_LD_A_D 1
#define EMIT_LD_A_D(p) EMIT_8(p, O_LD_A_D)
#define O_LD_A_E 0x7B
#define L_LD_A_E 1
#define EMIT_LD_A_E(p) EMIT_8(p, O_LD_A_E)
#define O_LD_A_H 0x7C
#define L_LD_A_H 1
#define EMIT_LD_A_H(p) EMIT_8(p, O_LD_A_H)
#define O_LD_A_L 0x7D
#define L_LD_A_L 1
#define EMIT_LD_A_L(p) EMIT_8(p, O_LD_A_L)
#define O_LD_A_IND_HL 0x7E
#define L_LD_A_IND_HL 1
#define EMIT_LD_A_IND_HL(p) EMIT_8(p, O_LD_A_IND_HL)
#define O_LD_A_A 0x7F
#define L_LD_A_A 1
#define EMIT_LD_A_A(p) EMIT_8(p, O_LD_A_A)
#define O_ADD_A_B 0x80
#define L_ADD_A_B 1
#define EMIT_ADD_A_B(p) EMIT_8(p, O_ADD_A_B)
#define O_ADD_A_C 0x81
#define L_ADD_A_C 1
#define EMIT_ADD_A_C(p) EMIT_8(p, O_ADD_A_C)
#define O_ADD_A_D 0x82
#define L_ADD_A_D 1
#define EMIT_ADD_A_D(p) EMIT_8(p, O_ADD_A_D)
#define O_ADD_A_E 0x83
#define L_ADD_A_E 1
#define EMIT_ADD_A_E(p) EMIT_8(p, O_ADD_A_E)
#define O_ADD_A_H 0x84
#define L_ADD_A_H 1
#define EMIT_ADD_A_H(p) EMIT_8(p, O_ADD_A_H)
#define O_ADD_A_L 0x85
#define L_ADD_A_L 1
#define EMIT_ADD_A_L(p) EMIT_8(p, O_ADD_A_L)
#define O_ADD_A_IND_HL 0x86
#define L_ADD_A_IND_HL 1
#define EMIT_ADD_A_IND_HL(p) EMIT_8(p, O_ADD_A_IND_HL)
#define O_ADD_A_A 0x87
#define L_ADD_A_A 1
#define EMIT_ADD_A_A(p) EMIT_8(p, O_ADD_A_A)
#define O_ADC_A_B 0x88
#define L_ADC_A_B 1
#define EMIT_ADC_A_B(p) EMIT_8(p, O_ADC_A_B)
#define O_ADC_A_C 0x89
#define L_ADC_A_C 1
#define EMIT_ADC_A_C(p) EMIT_8(p, O_ADC_A_C)
#define O_ADC_A_D 0x8A
#define L_ADC_A_D 1
#define EMIT_ADC_A_D(p) EMIT_8(p, O_ADC_A_D)
#define O_ADC_A_E 0x8B
#define L_ADC_A_E 1
#define EMIT_ADC_A_E(p) EMIT_8(p, O_ADC_A_E)
#define O_ADC_A_H 0x8C
#define L_ADC_A_H 1
#define EMIT_ADC_A_H(p) EMIT_8(p, O_ADC_A_H)
#define O_ADC_A_L 0x8D
#define L_ADC_A_L 1
#define EMIT_ADC_A_L(p) EMIT_8(p, O_ADC_A_L)
#define O_ADC_A_IND_HL 0x8E
#define L_ADC_A_IND_HL 1
#define EMIT_ADC_A_IND_HL(p) EMIT_8(p, O_ADC_A_IND_HL)
#define O_ADC_A_A 0x8F
#define L_ADC_A_A 1
#define EMIT_ADC_A_A(p) EMIT_8(p, O_ADC_A_A)
#define O_SUB_A_B 0x90
#define L_SUB_A_B 1
#define EMIT_SUB_A_B(p) EMIT_8(p, O_SUB_A_B)
#define O_SUB_A_C 0x91
#define L_SUB_A_C 1
#define EMIT_SUB_A_C(p) EMIT_8(p, O_SUB_A_C)
#define O_SUB_A_D 0x92
#define L_SUB_A_D 1
#define EMIT_SUB_A_D(p) EMIT_8(p, O_SUB_A_D)
#define O_SUB_A_E 0x93
#define L_SUB_A_E 1
#define EMIT_SUB_A_E(p) EMIT_8(p, O_SUB_A_E)
#define O_SUB_A_H 0x94
#define L_SUB_A_H 1
#define EMIT_SUB_A_H(p) EMIT_8(p, O_SUB_A_H)
#define O_SUB_A_L 0x95
#define L_SUB_A_L 1
#define EMIT_SUB_A_L(p) EMIT_8(p, O_SUB_A_L)
#define O_SUB_A_IND_HL 0x96
#define L_SUB_A_IND_HL 1
#define EMIT_SUB_A_IND_HL(p) EMIT_8(p, O_SUB_A_IND_HL)
#define O_SUB_A_A 0x97
#define L_SUB_A_A 1
#define EMIT_SUB_A_A(p) EMIT_8(p, O_SUB_A_A)
#define O_SBC_A_B 0x98
#define L_SBC_A_B 1
#define EMIT_SBC_A_B(p) EMIT_8(p, O_SBC_A_B)
#define O_SBC_A_C 0x99
#define L_SBC_A_C 1
#define EMIT_SBC_A_C(p) EMIT_8(p, O_SBC_A_C)
#define O_SBC_A_D 0x9A
#define L_SBC_A_D 1
#define EMIT_SBC_A_D(p) EMIT_8(p, O_SBC_A_D)
#define O_SBC_A_E 0x9B
#define L_SBC_A_E 1
#define EMIT_SBC_A_E(p) EMIT_8(p, O_SBC_A_E)
#define O_SBC_A_H 0x9C
#define L_SBC_A_H 1
#define EMIT_SBC_A_H(p) EMIT_8(p, O_SBC_A_H)
#define O_SBC_A_L 0x9D
#define L_SBC_A_L 1
#define EMIT_SBC_A_L(p) EMIT_8(p, O_SBC_A_L)
#define O_SBC_A_IND_HL 0x9E
#define L_SBC_A_IND_HL 1
#define EMIT_SBC_A_IND_HL(p) EMIT_8(p, O_SBC_A_IND_HL)
#define O_SBC_A_A 0x9F
#define L_SBC_A_A 1
#define EMIT_SBC_A_A(p) EMIT_8(p, O_SBC_A_A)
#define O_AND_B 0xA0
#define L_AND_B 1
#define EMIT_AND_B(p) EMIT_8(p, O_AND_B)
#define O_AND_C 0xA1
#define L_AND_C 1
#define EMIT_AND_C(p) EMIT_8(p, O_AND_C)
#define O_AND_D 0xA2
#define L_AND_D 1
#define EMIT_AND_D(p) EMIT_8(p, O_AND_D)
#define O_AND_E 0xA3
#define L_AND_E 1
#define EMIT_AND_E(p) EMIT_8(p, O_AND_E)
#define O_AND_H 0xA4
#define L_AND_H 1
#define EMIT_AND_H(p) EMIT_8(p, O_AND_H)
#define O_AND_L 0xA5
#define L_AND_L 1
#define EMIT_AND_L(p) EMIT_8(p, O_AND_L)
#define O_AND_IND_HL 0xA6
#define L_AND_IND_HL 1
#define EMIT_AND_IND_HL(p) EMIT_8(p, O_AND_IND_HL)
#define O_AND_A 0xA7
#define L_AND_A 1
#define EMIT_AND_A(p) EMIT_8(p, O_AND_A)
#define O_XOR_B 0xA8
#define L_XOR_B 1
#define EMIT_XOR_B(p) EMIT_8(p, O_XOR_B)
#define O_XOR_C 0xA9
#define L_XOR_C 1
#define EMIT_XOR_C(p) EMIT_8(p, O_XOR_C)
#define O_XOR_D 0xAA
#define L_XOR_D 1
#define EMIT_XOR_D(p) EMIT_8(p, O_XOR_D)
#define O_XOR_E 0xAB
#define L_XOR_E 1
#define EMIT_XOR_E(p) EMIT_8(p, O_XOR_E)
#define O_XOR_H 0xAC
#define L_XOR_H 1
#define EMIT_XOR_H(p) EMIT_8(p, O_XOR_H)
#define O_XOR_L 0xAD
#define L_XOR_L 1
#define EMIT_XOR_L(p) EMIT_8(p, O_XOR_L)
#define O_XOR_IND_HL 0xAE
#define L_XOR_IND_HL 1
#define EMIT_XOR_IND_HL(p) EMIT_8(p, O_XOR_IND_HL)
#define O_XOR_A 0xAF
#define L_XOR_A 1
#define EMIT_XOR_A(p) EMIT_8(p, O_XOR_A)
#define O_OR_B 0xB0
#define L_OR_B 1
#define EMIT_OR_B(p) EMIT_8(p, O_OR_B)
#define O_OR_C 0xB1
#define L_OR_C 1
#define EMIT_OR_C(p) EMIT_8(p, O_OR_C)
#define O_OR_D 0xB2
#define L_OR_D 1
#define EMIT_OR_D(p) EMIT_8(p, O_OR_D)
#define O_OR_E 0xB3
#define L_OR_E 1
#define EMIT_OR_E(p) EMIT_8(p, O_OR_E)
#define O_OR_H 0xB4
#define L_OR_H 1
#define EMIT_OR_H(p) EMIT_8(p, O_OR_H)
#define O_OR_L 0xB5
#define L_OR_L 1
#define EMIT_OR_L(p) EMIT_8(p, O_OR_L)
#define O_OR_IND_HL 0xB6
#define L_OR_IND_HL 1
#define EMIT_OR_IND_HL(p) EMIT_8(p, O_OR_IND_HL)
#define O_OR_A 0xB7
#define L_OR_A 1
#define EMIT_OR_A(p) EMIT_8(p, O_OR_A)
#define O_CP_B 0xB8
#define L_CP_B 1
#define EMIT_CP_B(p) EMIT_8(p, O_CP_B)
#define O_CP_C 0xB9
#define L_CP_C 1
#define EMIT_CP_C(p) EMIT_8(p, O_CP_C)
#define O_CP_D 0xBA
#define L_CP_D 1
#define EMIT_CP_D(p) EMIT_8(p, O_CP_D)
#define O_CP_E 0xBB
#define L_CP_E 1
#define EMIT_CP_E(p) EMIT_8(p, O_CP_E)
#define O_CP_H 0xBC
#define L_CP_H 1
#define EMIT_CP_H(p) EMIT_8(p, O_CP_H)
#define O_CP_L 0xBD
#define L_CP_L 1
#define EMIT_CP_L(p) EMIT_8(p, O_CP_L)
#define O_CP_IND_HL 0xBE
#define L_CP_IND_HL 1
#define EMIT_CP_IND_HL(p) EMIT_8(p, O_CP_IND_HL)
#define O_CP_A 0xBF
#define L_CP_A 1
#define EMIT_CP_A(p) EMIT_8(p, O_CP_A)
#define O_RET_NZ 0xC0
#define L_RET_NZ 1
#define EMIT_RET_NZ(p) EMIT_8(p, O_RET_NZ)
#define O_POP_BC 0xC1
#define L_POP_BC 1
#define EMIT_POP_BC(p) EMIT_8(p, O_POP_BC)
#define O_JP_NZ_IMM 0xC2
#define L_JP_NZ_IMM 3
#define EMIT_JP_NZ_IMM(p,v) EMIT_8_24(p, O_JP_NZ_IMM, v)
#define O_JP_IMM 0xC3
#define L_JP_IMM 3
#define EMIT_JP_IMM(p,v) EMIT_8_24(p, O_JP_IMM, v)
#define O_CALL_NZ_IMM 0xC4
#define L_CALL_NZ_IMM 3
#define EMIT_CALL_NZ_IMM(p,v) EMIT_8_24(p, O_CALL_NZ_IMM, v)
#define O_PUSH_BC 0xC5
#define L_PUSH_BC 1
#define EMIT_PUSH_BC(p) EMIT_8(p, O_PUSH_BC)
#define O_ADD_A_IMM 0xC6
#define L_ADD_A_IMM 2
#define EMIT_ADD_A_IMM(p,v) EMIT_8_8(p, O_ADD_A_IMM, v)
#define O_RST_00 0xC7
#define L_RST_00 2
#define EMIT_RST_00(p,v) EMIT_8_8(p, O_RST_00, v)
#define O_RET_Z 0xC8
#define L_RET_Z 1
#define EMIT_RET_Z(p) EMIT_8(p, O_RET_Z)
#define O_RET 0xC9
#define L_RET 1
#define EMIT_RET(p) EMIT_8(p, O_RET)
#define O_JP_Z_IMM 0xCA
#define L_JP_Z_IMM 3
#define EMIT_JP_Z_IMM(p,v) EMIT_8_24(p, O_JP_Z_IMM, v)
#define O_CALL_Z_IMM 0xCC
#define L_CALL_Z_IMM 3
#define EMIT_CALL_Z_IMM(p,v) EMIT_8_24(p, O_CALL_Z_IMM, v)
#define O_CALL_IMM 0xCD
#define L_CALL_IMM 3
#define EMIT_CALL_IMM(p,v) EMIT_8_24(p, O_CALL_IMM, v)
#define O_ADC_A_IMM 0xCE
#define L_ADC_A_IMM 2
#define EMIT_ADC_A_IMM(p,v) EMIT_8_8(p, O_ADC_A_IMM, v)
#define O_RST_08 0xCF
#define L_RST_08 1
#define EMIT_RST_08(p) EMIT_8(p, O_RST_08)
#define O_RET_NC 0xD0
#define L_RET_NC 1
#define EMIT_RET_NC(p) EMIT_8(p, O_RET_NC)
#define O_POP_DE 0xD1
#define L_POP_DE 1
#define EMIT_POP_DE(p) EMIT_8(p, O_POP_DE)
#define O_JP_NC_IMM 0xD2
#define L_JP_NC_IMM 3
#define EMIT_JP_NC_IMM(p,v) EMIT_8_24(p, O_JP_NC_IMM, v)
#define O_OUT_IND_IMM_A 0xD3
#define L_OUT_IND_IMM_A 2
#define EMIT_OUT_IND_IMM_A(p,v) EMIT_8_8(p, O_OUT_IND_IMM_A, v)
#define O_CALL_NC_IMM 0xD4
#define L_CALL_NC_IMM 3
#define EMIT_CALL_NC_IMM(p,v) EMIT_8_24(p, O_CALL_NC_IMM, v)
#define O_PUSH_DE 0xD5
#define L_PUSH_DE 1
#define EMIT_PUSH_DE(p) EMIT_8(p, O_PUSH_DE)
#define O_SUB_A_IMM 0xD6
#define L_SUB_A_IMM 2
#define EMIT_SUB_A_IMM(p,v) EMIT_8_8(p, O_SUB_A_IMM, v)
#define O_RST_10 0xD7
#define L_RST_10 1
#define EMIT_RST_10(p) EMIT_8(p, O_RST_10)
#define O_RET_C 0xD8
#define L_RET_C 1
#define EMIT_RET_C(p) EMIT_8(p, O_RET_C)
#define O_EXX 0xD9
#define L_EXX 1
#define EMIT_EXX(p) EMIT_8(p, O_EXX)
#define O_JP_C_IMM 0xDA
#define L_JP_C_IMM 3
#define EMIT_JP_C_IMM(p,v) EMIT_8_24(p, O_JP_C_IMM, v)
#define O_IN_A_IND_IMM 0xDB
#define L_IN_A_IND_IMM 2
#define EMIT_IN_A_IND_IMM(p,v) EMIT_8_8(p, O_IN_A_IND_IMM, v)
#define O_CALL_C_IMM 0xDC
#define L_CALL_C_IMM 3
#define EMIT_CALL_C_IMM(p,v) EMIT_8_24(p, O_CALL_C_IMM, v)
#define O_SBC_A_IMM 0xDE
#define L_SBC_A_IMM 2
#define EMIT_SBC_A_IMM(p,v) EMIT_8_8(p, O_SBC_A_IMM, v)
#define O_RST_18 0xDF
#define L_RST_18 1
#define EMIT_RST_18(p) EMIT_8(p, O_RST_18)
#define O_RET_PO 0xE0
#define L_RET_PO 1
#define EMIT_RET_PO(p) EMIT_8(p, O_RET_PO)
#define O_POP_HL 0xE1
#define L_POP_HL 1
#define EMIT_POP_HL(p) EMIT_8(p, O_POP_HL)
#define O_JP_PO_IMM 0xE2
#define L_JP_PO_IMM 3
#define EMIT_JP_PO_IMM(p,v) EMIT_8_24(p, O_JP_PO_IMM, v)
#define O_EX_IND_SP_HL 0xE3
#define L_EX_IND_SP_HL 1
#define EMIT_EX_IND_SP_HL(p) EMIT_8(p, O_EX_IND_SP_HL)
#define O_CALL_PO_IMM 0xE4
#define L_CALL_PO_IMM 3
#define EMIT_CALL_PO_IMM(p,v) EMIT_8_24(p, O_CALL_PO_IMM, v)
#define O_PUSH_HL 0xE5
#define L_PUSH_HL 1
#define EMIT_PUSH_HL(p) EMIT_8(p, O_PUSH_HL)
#define O_AND_IMM 0xE6
#define L_AND_IMM 2
#define EMIT_AND_IMM(p,v) EMIT_8_8(p, O_AND_IMM, v)
#define O_RST_20 0xE7
#define L_RST_20 1
#define EMIT_RST_20(p) EMIT_8(p, O_RST_20)
#define O_RET_PE 0xE8
#define L_RET_PE 1
#define EMIT_RET_PE(p) EMIT_8(p, O_RET_PE)
#define O_JP_IND_HL 0xE9
#define L_JP_IND_HL 1
#define EMIT_JP_IND_HL(p) EMIT_8(p, O_JP_IND_HL)
#define O_JP_PE_IMM 0xEA
#define L_JP_PE_IMM 3
#define EMIT_JP_PE_IMM(p,v) EMIT_8_24(p, O_JP_PE_IMM, v)
#define O_EX_DE_HL 0xEB
#define L_EX_DE_HL 1
#define EMIT_EX_DE_HL(p) EMIT_8(p, O_EX_DE_HL)
#define O_CALL_PE_IMM 0xEC
#define L_CALL_PE_IMM 3
#define EMIT_CALL_PE_IMM(p,v) EMIT_8_24(p, O_CALL_PE_IMM, v)
#define O_XOR_IMM 0xEE
#define L_XOR_IMM 2
#define EMIT_XOR_IMM(p,v) EMIT_8_8(p, O_XOR_IMM, v)
#define O_RST_28 0xEF
#define L_RST_28 1
#define EMIT_RST_28(p) EMIT_8(p, O_RST_28)
#define O_RET_P 0xF0
#define L_RET_P 1
#define EMIT_RET_P(p) EMIT_8(p, O_RET_P)
#define O_POP_AF 0xF1
#define L_POP_AF 1
#define EMIT_POP_AF(p) EMIT_8(p, O_POP_AF)
#define O_JP_P_IMM 0xF2
#define L_JP_P_IMM 3
#define EMIT_JP_P_IMM(p,v) EMIT_8_24(p, O_JP_P_IMM, v)
#define O_DI 0xF3
#define L_DI 1
#define EMIT_DI(p) EMIT_8(p, O_DI)
#define O_CALL_P_IMM 0xF4
#define L_CALL_P_IMM 3
#define EMIT_CALL_P_IMM(p,v) EMIT_8_24(p, O_CALL_P_IMM, v)
#define O_PUSH_AF 0xF5
#define L_PUSH_AF 1
#define EMIT_PUSH_AF(p) EMIT_8(p, O_PUSH_AF)
#define O_OR_IMM 0xF6
#define L_OR_IMM 2
#define EMIT_OR_IMM(p,v) EMIT_8_8(p, O_OR_IMM, v)
#define O_RST_30 0xF7
#define L_RST_30 1
#define EMIT_RST_30(p) EMIT_8(p, O_RST_30)
#define O_RET_M 0xF8
#define L_RET_M 1
#define EMIT_RET_M(p) EMIT_8(p, O_RET_M)
#define O_LD_SP_HL 0xF9
#define L_LD_SP_HL 1
#define EMIT_LD_SP_HL(p) EMIT_8(p, O_LD_SP_HL)
#define O_JP_M_IMM 0xFA
#define L_JP_M_IMM 3
#define EMIT_JP_M_IMM(p,v) EMIT_8_24(p, O_JP_M_IMM, v)
#define O_EI 0xFB
#define L_EI 1
#define EMIT_EI(p) EMIT_8(p, O_EI)
#define O_CALL_M_IMM 0xFC
#define L_CALL_M_IMM 3
#define EMIT_CALL_M_IMM(p,v) EMIT_8_24(p, O_CALL_M_IMM, v)
#define O_CP_IMM 0xFE
#define L_CP_IMM 2
#define EMIT_CP_IMM(p,v) EMIT_8_8(p, O_CP_IMM, v)
#define O_RST_38 0xFF
#define L_RST_38 1
#define EMIT_RST_38(p) EMIT_8(p, O_RST_38)
#define O_LD_BC_IND_IX_DD 0x07DD
#define L_LD_BC_IND_IX_DD 3
#define EMIT_LD_BC_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_BC_IND_IX_DD, v)
#define O_LD_BC_IND_IY_DD 0x07FD
#define L_LD_BC_IND_IY_DD 3
#define EMIT_LD_BC_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_BC_IND_IY_DD, v)
#define O_ADD_IX_BC 0x09DD
#define L_ADD_IX_BC 2
#define EMIT_ADD_IX_BC(p) EMIT_16(p, O_ADD_IX_BC)
#define O_ADD_IY_BC 0x09FD
#define L_ADD_IY_BC 2
#define EMIT_ADD_IY_BC(p) EMIT_16(p, O_ADD_IY_BC)
#define O_LD_IND_IX_DD_BC 0x0FDD
#define L_LD_IND_IX_DD_BC 3
#define EMIT_LD_IND_IX_DD_BC(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_BC, v)
#define O_LD_IND_IY_DD_BC 0x0FFD
#define L_LD_IND_IY_DD_BC 3
#define EMIT_LD_IND_IY_DD_BC(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_BC, v)
#define O_LD_DE_IND_IX_DD 0x17DD
#define L_LD_DE_IND_IX_DD 3
#define EMIT_LD_DE_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_DE_IND_IX_DD, v)
#define O_LD_DE_IND_IY_DD 0x17FD
#define L_LD_DE_IND_IY_DD 3
#define EMIT_LD_DE_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_DE_IND_IY_DD, v)
#define O_ADD_IX_DE 0x19DD
#define L_ADD_IX_DE 2
#define EMIT_ADD_IX_DE(p) EMIT_16(p, O_ADD_IX_DE)
#define O_ADD_IY_DE 0x19FD
#define L_ADD_IY_DE 2
#define EMIT_ADD_IY_DE(p) EMIT_16(p, O_ADD_IY_DE)
#define O_LD_IND_IX_DD_DE 0x1FDD
#define L_LD_IND_IX_DD_DE 3
#define EMIT_LD_IND_IX_DD_DE(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_DE, v)
#define O_LD_IND_IY_DD_DE 0x1FFD
#define L_LD_IND_IY_DD_DE 3
#define EMIT_LD_IND_IY_DD_DE(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_DE, v)
#define O_LD_IX_IMM 0x21DD
#define L_LD_IX_IMM 4
#define EMIT_LD_IX_IMM(p,v) EMIT_16_24(p, O_LD_IX_IMM, v)
#define O_LD_IY_IMM 0x21FD
#define L_LD_IY_IMM 4
#define EMIT_LD_IY_IMM(p,v) EMIT_16_24(p, O_LD_IY_IMM, v)
#define O_LD_IND_IMM_IX 0x22DD
#define L_LD_IND_IMM_IX 4
#define EMIT_LD_IND_IMM_IX(p,v) EMIT_16_24(p, O_LD_IND_IMM_IX, v)
#define O_LD_IND_IMM_IY 0x22FD
#define L_LD_IND_IMM_IY 4
#define EMIT_LD_IND_IMM_IY(p,v) EMIT_16_24(p, O_LD_IND_IMM_IY, v)
#define O_INC_IX 0x23DD
#define L_INC_IX 2
#define EMIT_INC_IX(p) EMIT_16(p, O_INC_IX)
#define O_INC_IY 0x23FD
#define L_INC_IY 2
#define EMIT_INC_IY(p) EMIT_16(p, O_INC_IY)
#define O_INC_IXH 0x24DD
#define L_INC_IXH 2
#define EMIT_INC_IXH(p) EMIT_16(p, O_INC_IXH)
#define O_INC_IYH 0x24FD
#define L_INC_IYH 2
#define EMIT_INC_IYH(p) EMIT_16(p, O_INC_IYH)
#define O_DEC_IXH 0x25DD
#define L_DEC_IXH 2
#define EMIT_DEC_IXH(p) EMIT_16(p, O_DEC_IXH)
#define O_DEC_IYH 0x25FD
#define L_DEC_IYH 2
#define EMIT_DEC_IYH(p) EMIT_16(p, O_DEC_IYH)
#define O_LD_IXH_IMM 0x26DD
#define L_LD_IXH_IMM 3
#define EMIT_LD_IXH_IMM(p,v) EMIT_16_8(p, O_LD_IXH_IMM, v)
#define O_LD_IYH_IMM 0x26FD
#define L_LD_IYH_IMM 3
#define EMIT_LD_IYH_IMM(p,v) EMIT_16_8(p, O_LD_IYH_IMM, v)
#define O_LD_HL_IND_IX_DD 0x27DD
#define L_LD_HL_IND_IX_DD 3
#define EMIT_LD_HL_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_HL_IND_IX_DD, v)
#define O_LD_HL_IND_IY_DD 0x27FD
#define L_LD_HL_IND_IY_DD 3
#define EMIT_LD_HL_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_HL_IND_IY_DD, v)
#define O_ADD_IX_IX 0x29DD
#define L_ADD_IX_IX 2
#define EMIT_ADD_IX_IX(p) EMIT_16(p, O_ADD_IX_IX)
#define O_ADD_IY_IX 0x29FD
#define L_ADD_IY_IX 2
#define EMIT_ADD_IY_IX(p) EMIT_16(p, O_ADD_IY_IX)
#define O_LD_IX_IND_IMM 0x2ADD
#define L_LD_IX_IND_IMM 4
#define EMIT_LD_IX_IND_IMM(p,v) EMIT_16_24(p, O_LD_IX_IND_IMM, v)
#define O_LD_IY_IND_IMM 0x2AFD
#define L_LD_IY_IND_IMM 4
#define EMIT_LD_IY_IND_IMM(p,v) EMIT_16_24(p, O_LD_IY_IND_IMM, v)
#define O_DEC_IX 0x2BDD
#define L_DEC_IX 2
#define EMIT_DEC_IX(p) EMIT_16(p, O_DEC_IX)
#define O_DEC_IY 0x2BFD
#define L_DEC_IY 2
#define EMIT_DEC_IY(p) EMIT_16(p, O_DEC_IY)
#define O_INC_IXL 0x2CDD
#define L_INC_IXL 2
#define EMIT_INC_IXL(p) EMIT_16(p, O_INC_IXL)
#define O_INC_IYL 0x2CFD
#define L_INC_IYL 2
#define EMIT_INC_IYL(p) EMIT_16(p, O_INC_IYL)
#define O_DEC_IXL 0x2DDD
#define L_DEC_IXL 2
#define EMIT_DEC_IXL(p) EMIT_16(p, O_DEC_IXL)
#define O_DEC_IYL 0x2DFD
#define L_DEC_IYL 2
#define EMIT_DEC_IYL(p) EMIT_16(p, O_DEC_IYL)
#define O_LD_IXL_IMM 0x2EDD
#define L_LD_IXL_IMM 3
#define EMIT_LD_IXL_IMM(p,v) EMIT_16_8(p, O_LD_IXL_IMM, v)
#define O_LD_IYL_IMM 0x2EFD
#define L_LD_IYL_IMM 3
#define EMIT_LD_IYL_IMM(p,v) EMIT_16_8(p, O_LD_IYL_IMM, v)
#define O_LD_IND_IX_DD_HL 0x2FDD
#define L_LD_IND_IX_DD_HL 3
#define EMIT_LD_IND_IX_DD_HL(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_HL, v)
#define O_LD_IND_IY_DD_HL 0x2FFD
#define L_LD_IND_IY_DD_HL 3
#define EMIT_LD_IND_IY_DD_HL(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_HL, v)
#define O_LD_IY_IND_IX_DD 0x31DD
#define L_LD_IY_IND_IX_DD 3
#define EMIT_LD_IY_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_IY_IND_IX_DD, v)
#define O_LD_IY_IND_IY_DD 0x31FD
#define L_LD_IY_IND_IY_DD 3
#define EMIT_LD_IY_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_IY_IND_IY_DD, v)
#define O_INC_IND_IX_DD 0x34DD
#define L_INC_IND_IX_DD 3
#define EMIT_INC_IND_IX_DD(p,v) EMIT_16_8(p, O_INC_IND_IX_DD, v)
#define O_INC_IND_IY_DD 0x34FD
#define L_INC_IND_IY_DD 3
#define EMIT_INC_IND_IY_DD(p,v) EMIT_16_8(p, O_INC_IND_IY_DD, v)
#define O_DEC_IND_IX_DD 0x35DD
#define L_DEC_IND_IX_DD 3
#define EMIT_DEC_IND_IX_DD(p,v) EMIT_16_8(p, O_DEC_IND_IX_DD, v)
#define O_DEC_IND_IY_DD 0x35FD
#define L_DEC_IND_IY_DD 3
#define EMIT_DEC_IND_IY_DD(p,v) EMIT_16_8(p, O_DEC_IND_IY_DD, v)
#define O_LD_IND_IX_DD_IMM 0x36DD
#define L_LD_IND_IX_DD_IMM 4
#define EMIT_LD_IND_IX_DD_IMM(p,d,v) EMIT_16_8_8(p, O_LD_IND_IX_DD_IMM, d, v)
#define O_LD_IND_IY_DD_IMM 0x36FD
#define L_LD_IND_IY_DD_IMM 4
#define EMIT_LD_IND_IY_DD_IMM(p,d,v) EMIT_16_8_8(p, O_LD_IND_IY_DD_IMM, d, v)
#define O_LD_IX_IND_IX_DD 0x37DD
#define L_LD_IX_IND_IX_DD 3
#define EMIT_LD_IX_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_IX_IND_IX_DD, v)
#define O_LD_IX_IND_IY_DD 0x37FD
#define L_LD_IX_IND_IY_DD 3
#define EMIT_LD_IX_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_IX_IND_IY_DD, v)
#define O_ADD_IX_SP 0x39DD
#define L_ADD_IX_SP 2
#define EMIT_ADD_IX_SP(p) EMIT_16(p, O_ADD_IX_SP)
#define O_ADD_IY_SP 0x39FD
#define L_ADD_IY_SP 2
#define EMIT_ADD_IY_SP(p) EMIT_16(p, O_ADD_IY_SP)
#define O_LD_IND_IX_DD_IY 0x3EDD
#define L_LD_IND_IX_DD_IY 3
#define EMIT_LD_IND_IX_DD_IY(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_IY, v)
#define O_LD_IND_IY_DD_IY 0x3EFD
#define L_LD_IND_IY_DD_IY 3
#define EMIT_LD_IND_IY_DD_IY(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_IY, v)
#define O_LD_IND_IX_DD_IX 0x3FDD
#define L_LD_IND_IX_DD_IX 3
#define EMIT_LD_IND_IX_DD_IX(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_IX, v)
#define O_LD_IND_IY_DD_IX 0x3FFD
#define L_LD_IND_IY_DD_IX 3
#define EMIT_LD_IND_IY_DD_IX(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_IX, v)
#define O_LD_B_IXH 0x44DD
#define L_LD_B_IXH 2
#define EMIT_LD_B_IXH(p) EMIT_16(p, O_LD_B_IXH)
#define O_LD_B_IYH 0x44FD
#define L_LD_B_IYH 2
#define EMIT_LD_B_IYH(p) EMIT_16(p, O_LD_B_IYH)
#define O_LD_B_IXL 0x45DD
#define L_LD_B_IXL 2
#define EMIT_LD_B_IXL(p) EMIT_16(p, O_LD_B_IXL)
#define O_LD_B_IYL 0x45FD
#define L_LD_B_IYL 2
#define EMIT_LD_B_IYL(p) EMIT_16(p, O_LD_B_IYL)
#define O_LD_B_IND_IX_DD 0x46DD
#define L_LD_B_IND_IX_DD 3
#define EMIT_LD_B_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_B_IND_IX_DD, v)
#define O_LD_B_IND_IY_DD 0x46FD
#define L_LD_B_IND_IY_DD 3
#define EMIT_LD_B_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_B_IND_IY_DD, v)
#define O_LD_C_IXH 0x4CDD
#define L_LD_C_IXH 2
#define EMIT_LD_C_IXH(p) EMIT_16(p, O_LD_C_IXH)
#define O_LD_C_IYH 0x4CFD
#define L_LD_C_IYH 2
#define EMIT_LD_C_IYH(p) EMIT_16(p, O_LD_C_IYH)
#define O_LD_C_IXL 0x4DDD
#define L_LD_C_IXL 2
#define EMIT_LD_C_IXL(p) EMIT_16(p, O_LD_C_IXL)
#define O_LD_C_IYL 0x4DFD
#define L_LD_C_IYL 2
#define EMIT_LD_C_IYL(p) EMIT_16(p, O_LD_C_IYL)
#define O_LD_C_IND_IX_DD 0x4EDD
#define L_LD_C_IND_IX_DD 3
#define EMIT_LD_C_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_C_IND_IX_DD, v)
#define O_LD_C_IND_IY_DD 0x4EFD
#define L_LD_C_IND_IY_DD 3
#define EMIT_LD_C_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_C_IND_IY_DD, v)
#define O_LD_D_IXH 0x54DD
#define L_LD_D_IXH 2
#define EMIT_LD_D_IXH(p) EMIT_16(p, O_LD_D_IXH)
#define O_LD_D_IYH 0x54FD
#define L_LD_D_IYH 2
#define EMIT_LD_D_IYH(p) EMIT_16(p, O_LD_D_IYH)
#define O_LD_D_IXL 0x55DD
#define L_LD_D_IXL 2
#define EMIT_LD_D_IXL(p) EMIT_16(p, O_LD_D_IXL)
#define O_LD_D_IYL 0x55FD
#define L_LD_D_IYL 2
#define EMIT_LD_D_IYL(p) EMIT_16(p, O_LD_D_IYL)
#define O_LD_D_IND_IX_DD 0x56DD
#define L_LD_D_IND_IX_DD 3
#define EMIT_LD_D_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_D_IND_IX_DD, v)
#define O_LD_D_IND_IY_DD 0x56FD
#define L_LD_D_IND_IY_DD 3
#define EMIT_LD_D_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_D_IND_IY_DD, v)
#define O_LD_E_IXH 0x5CDD
#define L_LD_E_IXH 2
#define EMIT_LD_E_IXH(p) EMIT_16(p, O_LD_E_IXH)
#define O_LD_E_IYH 0x5CFD
#define L_LD_E_IYH 2
#define EMIT_LD_E_IYH(p) EMIT_16(p, O_LD_E_IYH)
#define O_LD_E_IXL 0x5DDD
#define L_LD_E_IXL 2
#define EMIT_LD_E_IXL(p) EMIT_16(p, O_LD_E_IXL)
#define O_LD_E_IYL 0x5DFD
#define L_LD_E_IYL 2
#define EMIT_LD_E_IYL(p) EMIT_16(p, O_LD_E_IYL)
#define O_LD_E_IND_IX_DD 0x5EDD
#define L_LD_E_IND_IX_DD 3
#define EMIT_LD_E_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_E_IND_IX_DD, v)
#define O_LD_E_IND_IY_DD 0x5EFD
#define L_LD_E_IND_IY_DD 3
#define EMIT_LD_E_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_E_IND_IY_DD, v)
#define O_LD_IXH_B 0x60DD
#define L_LD_IXH_B 2
#define EMIT_LD_IXH_B(p) EMIT_16(p, O_LD_IXH_B)
#define O_LD_IYH_B 0x60FD
#define L_LD_IYH_B 2
#define EMIT_LD_IYH_B(p) EMIT_16(p, O_LD_IYH_B)
#define O_LD_IXH_C 0x61DD
#define L_LD_IXH_C 2
#define EMIT_LD_IXH_C(p) EMIT_16(p, O_LD_IXH_C)
#define O_LD_IYH_C 0x61FD
#define L_LD_IYH_C 2
#define EMIT_LD_IYH_C(p) EMIT_16(p, O_LD_IYH_C)
#define O_LD_IXH_D 0x62DD
#define L_LD_IXH_D 2
#define EMIT_LD_IXH_D(p) EMIT_16(p, O_LD_IXH_D)
#define O_LD_IYH_D 0x62FD
#define L_LD_IYH_D 2
#define EMIT_LD_IYH_D(p) EMIT_16(p, O_LD_IYH_D)
#define O_LD_IXH_E 0x63DD
#define L_LD_IXH_E 2
#define EMIT_LD_IXH_E(p) EMIT_16(p, O_LD_IXH_E)
#define O_LD_IYH_E 0x63FD
#define L_LD_IYH_E 2
#define EMIT_LD_IYH_E(p) EMIT_16(p, O_LD_IYH_E)
#define O_LD_IXH_IXH 0x64DD
#define L_LD_IXH_IXH 2
#define EMIT_LD_IXH_IXH(p) EMIT_16(p, O_LD_IXH_IXH)
#define O_LD_IYH_IYH 0x64FD
#define L_LD_IYH_IYH 2
#define EMIT_LD_IYH_IYH(p) EMIT_16(p, O_LD_IYH_IYH)
#define O_LD_IXH_IXL 0x65DD
#define L_LD_IXH_IXL 2
#define EMIT_LD_IXH_IXL(p) EMIT_16(p, O_LD_IXH_IXL)
#define O_LD_IYH_IYL 0x65FD
#define L_LD_IYH_IYL 2
#define EMIT_LD_IYH_IYL(p) EMIT_16(p, O_LD_IYH_IYL)
#define O_LD_H_IND_IX_DD 0x66DD
#define L_LD_H_IND_IX_DD 3
#define EMIT_LD_H_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_H_IND_IX_DD, v)
#define O_LD_H_IND_IX_DD 0x66FD
#define L_LD_H_IND_IX_DD 3
#define EMIT_LD_H_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_H_IND_IX_DD, v)
#define O_LD_IXH_A 0x67DD
#define L_LD_IXH_A 2
#define EMIT_LD_IXH_A(p) EMIT_16(p, O_LD_IXH_A)
#define O_LD_IYH_A 0x67FD
#define L_LD_IYH_A 2
#define EMIT_LD_IYH_A(p) EMIT_16(p, O_LD_IYH_A)
#define O_LD_IXL_B 0x68DD
#define L_LD_IXL_B 2
#define EMIT_LD_IXL_B(p) EMIT_16(p, O_LD_IXL_B)
#define O_LD_IYL_B 0x68FD
#define L_LD_IYL_B 2
#define EMIT_LD_IYL_B(p) EMIT_16(p, O_LD_IYL_B)
#define O_LD_IXL_C 0x69DD
#define L_LD_IXL_C 2
#define EMIT_LD_IXL_C(p) EMIT_16(p, O_LD_IXL_C)
#define O_LD_IYL_C 0x69FD
#define L_LD_IYL_C 2
#define EMIT_LD_IYL_C(p) EMIT_16(p, O_LD_IYL_C)
#define O_LD_IXL_D 0x6ADD
#define L_LD_IXL_D 2
#define EMIT_LD_IXL_D(p) EMIT_16(p, O_LD_IXL_D)
#define O_LD_IYL_D 0x6AFD
#define L_LD_IYL_D 2
#define EMIT_LD_IYL_D(p) EMIT_16(p, O_LD_IYL_D)
#define O_LD_IXL_E 0x6BDD
#define L_LD_IXL_E 2
#define EMIT_LD_IXL_E(p) EMIT_16(p, O_LD_IXL_E)
#define O_LD_IYL_E 0x6BFD
#define L_LD_IYL_E 2
#define EMIT_LD_IYL_E(p) EMIT_16(p, O_LD_IYL_E)
#define O_LD_IXL_IXH 0x6CDD
#define L_LD_IXL_IXH 2
#define EMIT_LD_IXL_IXH(p) EMIT_16(p, O_LD_IXL_IXH)
#define O_LD_IYL_IYH 0x6CFD
#define L_LD_IYL_IYH 2
#define EMIT_LD_IYL_IYH(p) EMIT_16(p, O_LD_IYL_IYH)
#define O_LD_IXL_IXL 0x6DDD
#define L_LD_IXL_IXL 2
#define EMIT_LD_IXL_IXL(p) EMIT_16(p, O_LD_IXL_IXL)
#define O_LD_IYL_IYL 0x6DFD
#define L_LD_IYL_IYL 2
#define EMIT_LD_IYL_IYL(p) EMIT_16(p, O_LD_IYL_IYL)
#define O_LD_L_IND_IX_DD 0x6EDD
#define L_LD_L_IND_IX_DD 3
#define EMIT_LD_L_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_L_IND_IX_DD, v)
#define O_LD_L_IND_IY_DD 0x6EFD
#define L_LD_L_IND_IY_DD 3
#define EMIT_LD_L_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_L_IND_IY_DD, v)
#define O_LD_IXL_A 0x6FDD
#define L_LD_IXL_A 2
#define EMIT_LD_IXL_A(p) EMIT_16(p, O_LD_IXL_A)
#define O_LD_IYL_A 0x6FFD
#define L_LD_IYL_A 2
#define EMIT_LD_IYL_A(p) EMIT_16(p, O_LD_IYL_A)
#define O_LD_IND_IX_DD_B 0x70DD
#define L_LD_IND_IX_DD_B 3
#define EMIT_LD_IND_IX_DD_B(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_B, v)
#define O_LD_IND_IY_DD_B 0x70FD
#define L_LD_IND_IY_DD_B 3
#define EMIT_LD_IND_IY_DD_B(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_B, v)
#define O_LD_IND_IX_DD_C 0x71DD
#define L_LD_IND_IX_DD_C 3
#define EMIT_LD_IND_IX_DD_C(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_C, v)
#define O_LD_IND_IY_DD_C 0x71FD
#define L_LD_IND_IY_DD_C 3
#define EMIT_LD_IND_IY_DD_C(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_C, v)
#define O_LD_IND_IX_DD_D 0x72DD
#define L_LD_IND_IX_DD_D 3
#define EMIT_LD_IND_IX_DD_D(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_D, v)
#define O_LD_IND_IY_DD_D 0x72FD
#define L_LD_IND_IY_DD_D 3
#define EMIT_LD_IND_IY_DD_D(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_D, v)
#define O_LD_IND_IX_DD_E 0x73DD
#define L_LD_IND_IX_DD_E 3
#define EMIT_LD_IND_IX_DD_E(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_E, v)
#define O_LD_IND_IY_DD_E 0x73FD
#define L_LD_IND_IY_DD_E 3
#define EMIT_LD_IND_IY_DD_E(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_E, v)
#define O_LD_IND_IX_DD_H 0x74DD
#define L_LD_IND_IX_DD_H 3
#define EMIT_LD_IND_IX_DD_H(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_H, v)
#define O_LD_IND_IY_DD_H 0x74FD
#define L_LD_IND_IY_DD_H 3
#define EMIT_LD_IND_IY_DD_H(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_H, v)
#define O_LD_IND_IX_DD_L 0x75DD
#define L_LD_IND_IX_DD_L 3
#define EMIT_LD_IND_IX_DD_L(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_L, v)
#define O_LD_IND_IY_DD_L 0x75FD
#define L_LD_IND_IY_DD_L 3
#define EMIT_LD_IND_IY_DD_L(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_L, v)
#define O_LD_IND_IX_DD_A 0x77DD
#define L_LD_IND_IX_DD_A 3
#define EMIT_LD_IND_IX_DD_A(p,v) EMIT_16_8(p, O_LD_IND_IX_DD_A, v)
#define O_LD_IND_IY_DD_A 0x77FD
#define L_LD_IND_IY_DD_A 3
#define EMIT_LD_IND_IY_DD_A(p,v) EMIT_16_8(p, O_LD_IND_IY_DD_A, v)
#define O_LD_A_IXH 0x7CDD
#define L_LD_A_IXH 2
#define EMIT_LD_A_IXH(p) EMIT_16(p, O_LD_A_IXH)
#define O_LD_A_IYH 0x7CFD
#define L_LD_A_IYH 2
#define EMIT_LD_A_IYH(p) EMIT_16(p, O_LD_A_IYH)
#define O_LD_A_IXL 0x7DDD
#define L_LD_A_IXL 2
#define EMIT_LD_A_IXL(p) EMIT_16(p, O_LD_A_IXL)
#define O_LD_A_IYL 0x7DFD
#define L_LD_A_IYL 2
#define EMIT_LD_A_IYL(p) EMIT_16(p, O_LD_A_IYL)
#define O_LD_A_IND_IX_DD 0x7EDD
#define L_LD_A_IND_IX_DD 3
#define EMIT_LD_A_IND_IX_DD(p,v) EMIT_16_8(p, O_LD_A_IND_IX_DD, v)
#define O_LD_A_IND_IY_DD 0x7EFD
#define L_LD_A_IND_IY_DD 3
#define EMIT_LD_A_IND_IY_DD(p,v) EMIT_16_8(p, O_LD_A_IND_IY_DD, v)
#define O_ADD_A_IXH 0x84DD
#define L_ADD_A_IXH 2
#define EMIT_ADD_A_IXH(p) EMIT_16(p, O_ADD_A_IXH)
#define O_ADD_A_IYH 0x84FD
#define L_ADD_A_IYH 2
#define EMIT_ADD_A_IYH(p) EMIT_16(p, O_ADD_A_IYH)
#define O_ADD_A_IXL 0x85DD
#define L_ADD_A_IXL 2
#define EMIT_ADD_A_IXL(p) EMIT_16(p, O_ADD_A_IXL)
#define O_ADD_A_IYL 0x85FD
#define L_ADD_A_IYL 2
#define EMIT_ADD_A_IYL(p) EMIT_16(p, O_ADD_A_IYL)
#define O_ADD_A_IND_IX_DD 0x86DD
#define L_ADD_A_IND_IX_DD 3
#define EMIT_ADD_A_IND_IX_DD(p,v) EMIT_16_8(p, O_ADD_A_IND_IX_DD, v)
#define O_ADD_A_IND_IY_DD 0x86FD
#define L_ADD_A_IND_IY_DD 3
#define EMIT_ADD_A_IND_IY_DD(p,v) EMIT_16_8(p, O_ADD_A_IND_IY_DD, v)
#define O_ADC_A_IXH 0x8CDD
#define L_ADC_A_IXH 2
#define EMIT_ADC_A_IXH(p) EMIT_16(p, O_ADC_A_IXH)
#define O_ADC_A_IYH 0x8CFD
#define L_ADC_A_IYH 2
#define EMIT_ADC_A_IYH(p) EMIT_16(p, O_ADC_A_IYH)
#define O_ADC_A_IXL 0x8DDD
#define L_ADC_A_IXL 2
#define EMIT_ADC_A_IXL(p) EMIT_16(p, O_ADC_A_IXL)
#define O_ADC_A_IYL 0x8DFD
#define L_ADC_A_IYL 2
#define EMIT_ADC_A_IYL(p) EMIT_16(p, O_ADC_A_IYL)
#define O_ADC_A_IND_IX_DD 0x8EDD
#define L_ADC_A_IND_IX_DD 3
#define EMIT_ADC_A_IND_IX_DD(p,v) EMIT_16_8(p, O_ADC_A_IND_IX_DD, v)
#define O_ADC_A_IND_IY_DD 0x8EFD
#define L_ADC_A_IND_IY_DD 3
#define EMIT_ADC_A_IND_IY_DD(p,v) EMIT_16_8(p, O_ADC_A_IND_IY_DD, v)
#define O_SUB_A_IXH 0x94DD
#define L_SUB_A_IXH 2
#define EMIT_SUB_A_IXH(p) EMIT_16(p, O_SUB_A_IXH)
#define O_SUB_A_IYH 0x94FD
#define L_SUB_A_IYH 2
#define EMIT_SUB_A_IYH(p) EMIT_16(p, O_SUB_A_IYH)
#define O_SUB_A_IXL 0x95DD
#define L_SUB_A_IXL 2
#define EMIT_SUB_A_IXL(p) EMIT_16(p, O_SUB_A_IXL)
#define O_SUB_A_IYL 0x95FD
#define L_SUB_A_IYL 2
#define EMIT_SUB_A_IYL(p) EMIT_16(p, O_SUB_A_IYL)
#define O_SUB_A_IND_IX_DD 0x96DD
#define L_SUB_A_IND_IX_DD 3
#define EMIT_SUB_A_IND_IX_DD(p,v) EMIT_16_8(p, O_SUB_A_IND_IX_DD, v)
#define O_SUB_A_IND_IY_DD 0x96FD
#define L_SUB_A_IND_IY_DD 3
#define EMIT_SUB_A_IND_IY_DD(p,v) EMIT_16_8(p, O_SUB_A_IND_IY_DD, v)
#define O_SBC_A_IXH 0x9CDD
#define L_SBC_A_IXH 2
#define EMIT_SBC_A_IXH(p) EMIT_16(p, O_SBC_A_IXH)
#define O_SBC_A_IYH 0x9CFD
#define L_SBC_A_IYH 2
#define EMIT_SBC_A_IYH(p) EMIT_16(p, O_SBC_A_IYH)
#define O_SBC_A_IXL 0x9DDD
#define L_SBC_A_IXL 2
#define EMIT_SBC_A_IXL(p) EMIT_16(p, O_SBC_A_IXL)
#define O_SBC_A_IYL 0x9DFD
#define L_SBC_A_IYL 2
#define EMIT_SBC_A_IYL(p) EMIT_16(p, O_SBC_A_IYL)
#define O_SBC_A_IND_IX_DD 0x9EDD
#define L_SBC_A_IND_IX_DD 3
#define EMIT_SBC_A_IND_IX_DD(p,v) EMIT_16_8(p, O_SBC_A_IND_IX_DD, v)
#define O_SBC_A_IND_IY_DD 0x9EFD
#define L_SBC_A_IND_IY_DD 3
#define EMIT_SBC_A_IND_IY_DD(p,v) EMIT_16_8(p, O_SBC_A_IND_IY_DD, v)
#define O_AND_IXH 0xA4DD
#define L_AND_IXH 2
#define EMIT_AND_IXH(p) EMIT_16(p, O_AND_IXH)
#define O_AND_IYH 0xA4FD
#define L_AND_IYH 2
#define EMIT_AND_IYH(p) EMIT_16(p, O_AND_IYH)
#define O_AND_IXL 0xA5DD
#define L_AND_IXL 2
#define EMIT_AND_IXL(p) EMIT_16(p, O_AND_IXL)
#define O_AND_IYL 0xA5FD
#define L_AND_IYL 2
#define EMIT_AND_IYL(p) EMIT_16(p, O_AND_IYL)
#define O_AND_IND_IX_DD 0xA6DD
#define L_AND_IND_IX_DD 3
#define EMIT_AND_IND_IX_DD(p,v) EMIT_16_8(p, O_AND_IND_IX_DD, v)
#define O_AND_IND_IY_DD 0xA6FD
#define L_AND_IND_IY_DD 3
#define EMIT_AND_IND_IY_DD(p,v) EMIT_16_8(p, O_AND_IND_IY_DD, v)
#define O_XOR_IXH 0xACDD
#define L_XOR_IXH 2
#define EMIT_XOR_IXH(p) EMIT_16(p, O_XOR_IXH)
#define O_XOR_IYH 0xACFD
#define L_XOR_IYH 2
#define EMIT_XOR_IYH(p) EMIT_16(p, O_XOR_IYH)
#define O_XOR_IXL 0xADDD
#define L_XOR_IXL 2
#define EMIT_XOR_IXL(p) EMIT_16(p, O_XOR_IXL)
#define O_XOR_IYL 0xADFD
#define L_XOR_IYL 2
#define EMIT_XOR_IYL(p) EMIT_16(p, O_XOR_IYL)
#define O_XOR_IND_IX_DD 0xAEDD
#define L_XOR_IND_IX_DD 3
#define EMIT_XOR_IND_IX_DD(p,v) EMIT_16_8(p, O_XOR_IND_IX_DD, v)
#define O_XOR_IND_IY_DD 0xAEFD
#define L_XOR_IND_IY_DD 3
#define EMIT_XOR_IND_IY_DD(p,v) EMIT_16_8(p, O_XOR_IND_IY_DD, v)
#define O_OR_IXH 0xB4DD
#define L_OR_IXH 2
#define EMIT_OR_IXH(p) EMIT_16(p, O_OR_IXH)
#define O_OR_IYH 0xB4FD
#define L_OR_IYH 2
#define EMIT_OR_IYH(p) EMIT_16(p, O_OR_IYH)
#define O_OR_IXL 0xB5DD
#define L_OR_IXL 2
#define EMIT_OR_IXL(p) EMIT_16(p, O_OR_IXL)
#define O_OR_IYL 0xB5FD
#define L_OR_IYL 2
#define EMIT_OR_IYL(p) EMIT_16(p, O_OR_IYL)
#define O_OR_IND_IX_DD 0xB6DD
#define L_OR_IND_IX_DD 3
#define EMIT_OR_IND_IX_DD(p,v) EMIT_16_8(p, O_OR_IND_IX_DD, v)
#define O_OR_IND_IY_DD 0xB6FD
#define L_OR_IND_IY_DD 3
#define EMIT_OR_IND_IY_DD(p,v) EMIT_16_8(p, O_OR_IND_IY_DD, v)
#define O_CP_IXH 0xBCDD
#define L_CP_IXH 2
#define EMIT_CP_IXH(p) EMIT_16(p, O_CP_IXH)
#define O_CP_IYH 0xBCFD
#define L_CP_IYH 2
#define EMIT_CP_IYH(p) EMIT_16(p, O_CP_IYH)
#define O_CP_IXL 0xBDDD
#define L_CP_IXL 2
#define EMIT_CP_IXL(p) EMIT_16(p, O_CP_IXL)
#define O_CP_IYL 0xBDFD
#define L_CP_IYL 2
#define EMIT_CP_IYL(p) EMIT_16(p, O_CP_IYL)
#define O_CP_IND_IX_DD 0xBEDD
#define L_CP_IND_IX_DD 3
#define EMIT_CP_IND_IX_DD(p,v) EMIT_16_8(p, O_CP_IND_IX_DD, v)
#define O_CP_IND_IY_DD 0xBEFD
#define L_CP_IND_IY_DD 3
#define EMIT_CP_IND_IY_DD(p,v) EMIT_16_8(p, O_CP_IND_IY_DD, v)
#define O_POP_IX 0xE1DD
#define L_POP_IX 2
#define EMIT_POP_IX(p) EMIT_16(p, O_POP_IX)
#define O_POP_IY 0xE1FD
#define L_POP_IY 2
#define EMIT_POP_IY(p) EMIT_16(p, O_POP_IY)
#define O_EX_IND_SP_IX 0xE3DD
#define L_EX_IND_SP_IX 2
#define EMIT_EX_IND_SP_IX(p) EMIT_16(p, O_EX_IND_SP_IX)
#define O_EX_IND_SP_IY 0xE3FD
#define L_EX_IND_SP_IY 2
#define EMIT_EX_IND_SP_IY(p) EMIT_16(p, O_EX_IND_SP_IY)
#define O_PUSH_IX 0xE5DD
#define L_PUSH_IX 2
#define EMIT_PUSH_IX(p) EMIT_16(p, O_PUSH_IX)
#define O_PUSH_IY 0xE5FD
#define L_PUSH_IY 2
#define EMIT_PUSH_IY(p) EMIT_16(p, O_PUSH_IY)
#define O_JP_IND_IX 0xE9DD
#define L_JP_IND_IX 2
#define EMIT_JP_IND_IX(p) EMIT_16(p, O_JP_IND_IX)
#define O_JP_IND_IY 0xE9FD
#define L_JP_IND_IY 2
#define EMIT_JP_IND_IY(p) EMIT_16(p, O_JP_IND_IY)
#define O_LD_SP_IX 0xF9DD
#define L_LD_SP_IX 2
#define EMIT_LD_SP_IX(p) EMIT_16(p, O_LD_SP_IX)
#define O_LD_SP_IY 0xF9FD
#define L_LD_SP_IY 2
#define EMIT_LD_SP_IY(p) EMIT_16(p, O_LD_SP_IY)
#define O_RLC_B 0xCB
#define L_RLC_B 1
#define EMIT_RLC_B(p) EMIT_8(p, O_RLC_B)
#define O_RLC_C 0x01CB
#define L_RLC_C 2
#define EMIT_RLC_C(p) EMIT_16(p, O_RLC_C)
#define O_RLC_D 0x02CB
#define L_RLC_D 2
#define EMIT_RLC_D(p) EMIT_16(p, O_RLC_D)
#define O_RLC_E 0x03CB
#define L_RLC_E 2
#define EMIT_RLC_E(p) EMIT_16(p, O_RLC_E)
#define O_RLC_H 0x04CB
#define L_RLC_H 2
#define EMIT_RLC_H(p) EMIT_16(p, O_RLC_H)
#define O_RLC_L 0x05CB
#define L_RLC_L 2
#define EMIT_RLC_L(p) EMIT_16(p, O_RLC_L)
#define O_RLC_IND_HL 0x06CB
#define L_RLC_IND_HL 2
#define EMIT_RLC_IND_HL(p) EMIT_16(p, O_RLC_IND_HL)
#define O_RLC_A 0x07CB
#define L_RLC_A 2
#define EMIT_RLC_A(p) EMIT_16(p, O_RLC_A)
#define O_RRC_B 0x08CB
#define L_RRC_B 2
#define EMIT_RRC_B(p) EMIT_16(p, O_RRC_B)
#define O_RRC_C 0x09CB
#define L_RRC_C 2
#define EMIT_RRC_C(p) EMIT_16(p, O_RRC_C)
#define O_RRC_D 0x0ACB
#define L_RRC_D 2
#define EMIT_RRC_D(p) EMIT_16(p, O_RRC_D)
#define O_RRC_E 0x0BCB
#define L_RRC_E 2
#define EMIT_RRC_E(p) EMIT_16(p, O_RRC_E)
#define O_RRC_H 0x0CCB
#define L_RRC_H 2
#define EMIT_RRC_H(p) EMIT_16(p, O_RRC_H)
#define O_RRC_L 0x0DCB
#define L_RRC_L 2
#define EMIT_RRC_L(p) EMIT_16(p, O_RRC_L)
#define O_RRC_IND_HL 0x0ECB
#define L_RRC_IND_HL 2
#define EMIT_RRC_IND_HL(p) EMIT_16(p, O_RRC_IND_HL)
#define O_RRC_A 0x0FCB
#define L_RRC_A 2
#define EMIT_RRC_A(p) EMIT_16(p, O_RRC_A)
#define O_RL_B 0x10CB
#define L_RL_B 2
#define EMIT_RL_B(p) EMIT_16(p, O_RL_B)
#define O_RL_C 0x11CB
#define L_RL_C 2
#define EMIT_RL_C(p) EMIT_16(p, O_RL_C)
#define O_RL_D 0x12CB
#define L_RL_D 2
#define EMIT_RL_D(p) EMIT_16(p, O_RL_D)
#define O_RL_E 0x13CB
#define L_RL_E 2
#define EMIT_RL_E(p) EMIT_16(p, O_RL_E)
#define O_RL_H 0x14CB
#define L_RL_H 2
#define EMIT_RL_H(p) EMIT_16(p, O_RL_H)
#define O_RL_L 0x15CB
#define L_RL_L 2
#define EMIT_RL_L(p) EMIT_16(p, O_RL_L)
#define O_RL_IND_HL 0x16CB
#define L_RL_IND_HL 2
#define EMIT_RL_IND_HL(p) EMIT_16(p, O_RL_IND_HL)
#define O_RL_A 0x17CB
#define L_RL_A 2
#define EMIT_RL_A(p) EMIT_16(p, O_RL_A)
#define O_RR_B 0x18CB
#define L_RR_B 2
#define EMIT_RR_B(p) EMIT_16(p, O_RR_B)
#define O_RR_C 0x19CB
#define L_RR_C 2
#define EMIT_RR_C(p) EMIT_16(p, O_RR_C)
#define O_RR_D 0x1ACB
#define L_RR_D 2
#define EMIT_RR_D(p) EMIT_16(p, O_RR_D)
#define O_RR_E 0x1BCB
#define L_RR_E 2
#define EMIT_RR_E(p) EMIT_16(p, O_RR_E)
#define O_RR_H 0x1CCB
#define L_RR_H 2
#define EMIT_RR_H(p) EMIT_16(p, O_RR_H)
#define O_RR_L 0x1DCB
#define L_RR_L 2
#define EMIT_RR_L(p) EMIT_16(p, O_RR_L)
#define O_RR_IND_HL 0x1ECB
#define L_RR_IND_HL 2
#define EMIT_RR_IND_HL(p) EMIT_16(p, O_RR_IND_HL)
#define O_RR_A 0x1FCB
#define L_RR_A 2
#define EMIT_RR_A(p) EMIT_16(p, O_RR_A)
#define O_SLA_B 0x20CB
#define L_SLA_B 2
#define EMIT_SLA_B(p) EMIT_16(p, O_SLA_B)
#define O_SLA_C 0x21CB
#define L_SLA_C 2
#define EMIT_SLA_C(p) EMIT_16(p, O_SLA_C)
#define O_SLA_D 0x22CB
#define L_SLA_D 2
#define EMIT_SLA_D(p) EMIT_16(p, O_SLA_D)
#define O_SLA_E 0x23CB
#define L_SLA_E 2
#define EMIT_SLA_E(p) EMIT_16(p, O_SLA_E)
#define O_SLA_H 0x24CB
#define L_SLA_H 2
#define EMIT_SLA_H(p) EMIT_16(p, O_SLA_H)
#define O_SLA_L 0x25CB
#define L_SLA_L 2
#define EMIT_SLA_L(p) EMIT_16(p, O_SLA_L)
#define O_SLA_IND_HL 0x26CB
#define L_SLA_IND_HL 2
#define EMIT_SLA_IND_HL(p) EMIT_16(p, O_SLA_IND_HL)
#define O_SLA_A 0x27CB
#define L_SLA_A 2
#define EMIT_SLA_A(p) EMIT_16(p, O_SLA_A)
#define O_SRA_B 0x28CB
#define L_SRA_B 2
#define EMIT_SRA_B(p) EMIT_16(p, O_SRA_B)
#define O_SRA_C 0x29CB
#define L_SRA_C 2
#define EMIT_SRA_C(p) EMIT_16(p, O_SRA_C)
#define O_SRA_D 0x2ACB
#define L_SRA_D 2
#define EMIT_SRA_D(p) EMIT_16(p, O_SRA_D)
#define O_SRA_E 0x2BCB
#define L_SRA_E 2
#define EMIT_SRA_E(p) EMIT_16(p, O_SRA_E)
#define O_SRA_H 0x2CCB
#define L_SRA_H 2
#define EMIT_SRA_H(p) EMIT_16(p, O_SRA_H)
#define O_SRA_L 0x2DCB
#define L_SRA_L 2
#define EMIT_SRA_L(p) EMIT_16(p, O_SRA_L)
#define O_SRA_IND_HL 0x2ECB
#define L_SRA_IND_HL 2
#define EMIT_SRA_IND_HL(p) EMIT_16(p, O_SRA_IND_HL)
#define O_SRA_A 0x2FCB
#define L_SRA_A 2
#define EMIT_SRA_A(p) EMIT_16(p, O_SRA_A)
#define O_SRL_B 0x38CB
#define L_SRL_B 2
#define EMIT_SRL_B(p) EMIT_16(p, O_SRL_B)
#define O_SRL_C 0x39CB
#define L_SRL_C 2
#define EMIT_SRL_C(p) EMIT_16(p, O_SRL_C)
#define O_SRL_D 0x3ACB
#define L_SRL_D 2
#define EMIT_SRL_D(p) EMIT_16(p, O_SRL_D)
#define O_SRL_E 0x3BCB
#define L_SRL_E 2
#define EMIT_SRL_E(p) EMIT_16(p, O_SRL_E)
#define O_SRL_H 0x3CCB
#define L_SRL_H 2
#define EMIT_SRL_H(p) EMIT_16(p, O_SRL_H)
#define O_SRL_L 0x3DCB
#define L_SRL_L 2
#define EMIT_SRL_L(p) EMIT_16(p, O_SRL_L)
#define O_SRL_IND_HL 0x3ECB
#define L_SRL_IND_HL 2
#define EMIT_SRL_IND_HL(p) EMIT_16(p, O_SRL_IND_HL)
#define O_SRL_A 0x3FCB
#define L_SRL_A 2
#define EMIT_SRL_A(p) EMIT_16(p, O_SRL_A)
#define O_BIT_0_B 0x40CB
#define L_BIT_0_B 2
#define EMIT_BIT_0_B(p) EMIT_16(p, O_BIT_0_B)
#define O_BIT_0_C 0x41CB
#define L_BIT_0_C 2
#define EMIT_BIT_0_C(p) EMIT_16(p, O_BIT_0_C)
#define O_BIT_0_D 0x42CB
#define L_BIT_0_D 2
#define EMIT_BIT_0_D(p) EMIT_16(p, O_BIT_0_D)
#define O_BIT_0_E 0x43CB
#define L_BIT_0_E 2
#define EMIT_BIT_0_E(p) EMIT_16(p, O_BIT_0_E)
#define O_BIT_0_H 0x44CB
#define L_BIT_0_H 2
#define EMIT_BIT_0_H(p) EMIT_16(p, O_BIT_0_H)
#define O_BIT_0_L 0x45CB
#define L_BIT_0_L 2
#define EMIT_BIT_0_L(p) EMIT_16(p, O_BIT_0_L)
#define O_BIT_0_IND_HL 0x46CB
#define L_BIT_0_IND_HL 2
#define EMIT_BIT_0_IND_HL(p) EMIT_16(p, O_BIT_0_IND_HL)
#define O_BIT_0_A 0x47CB
#define L_BIT_0_A 2
#define EMIT_BIT_0_A(p) EMIT_16(p, O_BIT_0_A)
#define O_BIT_1_B 0x48CB
#define L_BIT_1_B 2
#define EMIT_BIT_1_B(p) EMIT_16(p, O_BIT_1_B)
#define O_BIT_1_C 0x49CB
#define L_BIT_1_C 2
#define EMIT_BIT_1_C(p) EMIT_16(p, O_BIT_1_C)
#define O_BIT_1_D 0x4ACB
#define L_BIT_1_D 2
#define EMIT_BIT_1_D(p) EMIT_16(p, O_BIT_1_D)
#define O_BIT_1_E 0x4BCB
#define L_BIT_1_E 2
#define EMIT_BIT_1_E(p) EMIT_16(p, O_BIT_1_E)
#define O_BIT_1_H 0x4CCB
#define L_BIT_1_H 2
#define EMIT_BIT_1_H(p) EMIT_16(p, O_BIT_1_H)
#define O_BIT_1_L 0x4DCB
#define L_BIT_1_L 2
#define EMIT_BIT_1_L(p) EMIT_16(p, O_BIT_1_L)
#define O_BIT_1_IND_HL 0x4ECB
#define L_BIT_1_IND_HL 2
#define EMIT_BIT_1_IND_HL(p) EMIT_16(p, O_BIT_1_IND_HL)
#define O_BIT_1_A 0x4FCB
#define L_BIT_1_A 2
#define EMIT_BIT_1_A(p) EMIT_16(p, O_BIT_1_A)
#define O_BIT_2_B 0x50CB
#define L_BIT_2_B 2
#define EMIT_BIT_2_B(p) EMIT_16(p, O_BIT_2_B)
#define O_BIT_2_C 0x51CB
#define L_BIT_2_C 2
#define EMIT_BIT_2_C(p) EMIT_16(p, O_BIT_2_C)
#define O_BIT_2_D 0x52CB
#define L_BIT_2_D 2
#define EMIT_BIT_2_D(p) EMIT_16(p, O_BIT_2_D)
#define O_BIT_2_E 0x53CB
#define L_BIT_2_E 2
#define EMIT_BIT_2_E(p) EMIT_16(p, O_BIT_2_E)
#define O_BIT_2_H 0x54CB
#define L_BIT_2_H 2
#define EMIT_BIT_2_H(p) EMIT_16(p, O_BIT_2_H)
#define O_BIT_2_L 0x55CB
#define L_BIT_2_L 2
#define EMIT_BIT_2_L(p) EMIT_16(p, O_BIT_2_L)
#define O_BIT_2_IND_HL 0x56CB
#define L_BIT_2_IND_HL 2
#define EMIT_BIT_2_IND_HL(p) EMIT_16(p, O_BIT_2_IND_HL)
#define O_BIT_2_A 0x57CB
#define L_BIT_2_A 2
#define EMIT_BIT_2_A(p) EMIT_16(p, O_BIT_2_A)
#define O_BIT_3_B 0x58CB
#define L_BIT_3_B 2
#define EMIT_BIT_3_B(p) EMIT_16(p, O_BIT_3_B)
#define O_BIT_3_C 0x59CB
#define L_BIT_3_C 2
#define EMIT_BIT_3_C(p) EMIT_16(p, O_BIT_3_C)
#define O_BIT_3_D 0x5ACB
#define L_BIT_3_D 2
#define EMIT_BIT_3_D(p) EMIT_16(p, O_BIT_3_D)
#define O_BIT_3_E 0x5BCB
#define L_BIT_3_E 2
#define EMIT_BIT_3_E(p) EMIT_16(p, O_BIT_3_E)
#define O_BIT_3_H 0x5CCB
#define L_BIT_3_H 2
#define EMIT_BIT_3_H(p) EMIT_16(p, O_BIT_3_H)
#define O_BIT_3_L 0x5DCB
#define L_BIT_3_L 2
#define EMIT_BIT_3_L(p) EMIT_16(p, O_BIT_3_L)
#define O_BIT_3_IND_HL 0x5ECB
#define L_BIT_3_IND_HL 2
#define EMIT_BIT_3_IND_HL(p) EMIT_16(p, O_BIT_3_IND_HL)
#define O_BIT_3_A 0x5FCB
#define L_BIT_3_A 2
#define EMIT_BIT_3_A(p) EMIT_16(p, O_BIT_3_A)
#define O_BIT_4_B 0x60CB
#define L_BIT_4_B 2
#define EMIT_BIT_4_B(p) EMIT_16(p, O_BIT_4_B)
#define O_BIT_4_C 0x61CB
#define L_BIT_4_C 2
#define EMIT_BIT_4_C(p) EMIT_16(p, O_BIT_4_C)
#define O_BIT_4_D 0x62CB
#define L_BIT_4_D 2
#define EMIT_BIT_4_D(p) EMIT_16(p, O_BIT_4_D)
#define O_BIT_4_E 0x63CB
#define L_BIT_4_E 2
#define EMIT_BIT_4_E(p) EMIT_16(p, O_BIT_4_E)
#define O_BIT_4_H 0x64CB
#define L_BIT_4_H 2
#define EMIT_BIT_4_H(p) EMIT_16(p, O_BIT_4_H)
#define O_BIT_4_L 0x65CB
#define L_BIT_4_L 2
#define EMIT_BIT_4_L(p) EMIT_16(p, O_BIT_4_L)
#define O_BIT_4_IND_HL 0x66CB
#define L_BIT_4_IND_HL 2
#define EMIT_BIT_4_IND_HL(p) EMIT_16(p, O_BIT_4_IND_HL)
#define O_BIT_4_A 0x67CB
#define L_BIT_4_A 2
#define EMIT_BIT_4_A(p) EMIT_16(p, O_BIT_4_A)
#define O_BIT_5_B 0x68CB
#define L_BIT_5_B 2
#define EMIT_BIT_5_B(p) EMIT_16(p, O_BIT_5_B)
#define O_BIT_5_C 0x69CB
#define L_BIT_5_C 2
#define EMIT_BIT_5_C(p) EMIT_16(p, O_BIT_5_C)
#define O_BIT_5_D 0x6ACB
#define L_BIT_5_D 2
#define EMIT_BIT_5_D(p) EMIT_16(p, O_BIT_5_D)
#define O_BIT_5_E 0x6BCB
#define L_BIT_5_E 2
#define EMIT_BIT_5_E(p) EMIT_16(p, O_BIT_5_E)
#define O_BIT_5_H 0x6CCB
#define L_BIT_5_H 2
#define EMIT_BIT_5_H(p) EMIT_16(p, O_BIT_5_H)
#define O_BIT_5_L 0x6DCB
#define L_BIT_5_L 2
#define EMIT_BIT_5_L(p) EMIT_16(p, O_BIT_5_L)
#define O_BIT_5_IND_HL 0x6ECB
#define L_BIT_5_IND_HL 2
#define EMIT_BIT_5_IND_HL(p) EMIT_16(p, O_BIT_5_IND_HL)
#define O_BIT_5_A 0x6FCB
#define L_BIT_5_A 2
#define EMIT_BIT_5_A(p) EMIT_16(p, O_BIT_5_A)
#define O_BIT_6_B 0x70CB
#define L_BIT_6_B 2
#define EMIT_BIT_6_B(p) EMIT_16(p, O_BIT_6_B)
#define O_BIT_6_C 0x71CB
#define L_BIT_6_C 2
#define EMIT_BIT_6_C(p) EMIT_16(p, O_BIT_6_C)
#define O_BIT_6_D 0x72CB
#define L_BIT_6_D 2
#define EMIT_BIT_6_D(p) EMIT_16(p, O_BIT_6_D)
#define O_BIT_6_E 0x73CB
#define L_BIT_6_E 2
#define EMIT_BIT_6_E(p) EMIT_16(p, O_BIT_6_E)
#define O_BIT_6_H 0x74CB
#define L_BIT_6_H 2
#define EMIT_BIT_6_H(p) EMIT_16(p, O_BIT_6_H)
#define O_BIT_6_L 0x75CB
#define L_BIT_6_L 2
#define EMIT_BIT_6_L(p) EMIT_16(p, O_BIT_6_L)
#define O_BIT_6_IND_HL 0x76CB
#define L_BIT_6_IND_HL 2
#define EMIT_BIT_6_IND_HL(p) EMIT_16(p, O_BIT_6_IND_HL)
#define O_BIT_6_A 0x77CB
#define L_BIT_6_A 2
#define EMIT_BIT_6_A(p) EMIT_16(p, O_BIT_6_A)
#define O_BIT_7_B 0x78CB
#define L_BIT_7_B 2
#define EMIT_BIT_7_B(p) EMIT_16(p, O_BIT_7_B)
#define O_BIT_7_C 0x79CB
#define L_BIT_7_C 2
#define EMIT_BIT_7_C(p) EMIT_16(p, O_BIT_7_C)
#define O_BIT_7_D 0x7ACB
#define L_BIT_7_D 2
#define EMIT_BIT_7_D(p) EMIT_16(p, O_BIT_7_D)
#define O_BIT_7_E 0x7BCB
#define L_BIT_7_E 2
#define EMIT_BIT_7_E(p) EMIT_16(p, O_BIT_7_E)
#define O_BIT_7_H 0x7CCB
#define L_BIT_7_H 2
#define EMIT_BIT_7_H(p) EMIT_16(p, O_BIT_7_H)
#define O_BIT_7_L 0x7DCB
#define L_BIT_7_L 2
#define EMIT_BIT_7_L(p) EMIT_16(p, O_BIT_7_L)
#define O_BIT_7_IND_HL 0x7ECB
#define L_BIT_7_IND_HL 2
#define EMIT_BIT_7_IND_HL(p) EMIT_16(p, O_BIT_7_IND_HL)
#define O_BIT_7_A 0x7FCB
#define L_BIT_7_A 2
#define EMIT_BIT_7_A(p) EMIT_16(p, O_BIT_7_A)
#define O_RES_0_B 0x80CB
#define L_RES_0_B 2
#define EMIT_RES_0_B(p) EMIT_16(p, O_RES_0_B)
#define O_RES_0_C 0x81CB
#define L_RES_0_C 2
#define EMIT_RES_0_C(p) EMIT_16(p, O_RES_0_C)
#define O_RES_0_D 0x82CB
#define L_RES_0_D 2
#define EMIT_RES_0_D(p) EMIT_16(p, O_RES_0_D)
#define O_RES_0_E 0x83CB
#define L_RES_0_E 2
#define EMIT_RES_0_E(p) EMIT_16(p, O_RES_0_E)
#define O_RES_0_H 0x84CB
#define L_RES_0_H 2
#define EMIT_RES_0_H(p) EMIT_16(p, O_RES_0_H)
#define O_RES_0_L 0x85CB
#define L_RES_0_L 2
#define EMIT_RES_0_L(p) EMIT_16(p, O_RES_0_L)
#define O_RES_0_IND_HL 0x86CB
#define L_RES_0_IND_HL 2
#define EMIT_RES_0_IND_HL(p) EMIT_16(p, O_RES_0_IND_HL)
#define O_RES_0_A 0x87CB
#define L_RES_0_A 2
#define EMIT_RES_0_A(p) EMIT_16(p, O_RES_0_A)
#define O_RES_1_B 0x88CB
#define L_RES_1_B 2
#define EMIT_RES_1_B(p) EMIT_16(p, O_RES_1_B)
#define O_RES_1_C 0x89CB
#define L_RES_1_C 2
#define EMIT_RES_1_C(p) EMIT_16(p, O_RES_1_C)
#define O_RES_1_D 0x8ACB
#define L_RES_1_D 2
#define EMIT_RES_1_D(p) EMIT_16(p, O_RES_1_D)
#define O_RES_1_E 0x8BCB
#define L_RES_1_E 2
#define EMIT_RES_1_E(p) EMIT_16(p, O_RES_1_E)
#define O_RES_1_H 0x8CCB
#define L_RES_1_H 2
#define EMIT_RES_1_H(p) EMIT_16(p, O_RES_1_H)
#define O_RES_1_L 0x8DCB
#define L_RES_1_L 2
#define EMIT_RES_1_L(p) EMIT_16(p, O_RES_1_L)
#define O_RES_1_IND_HL 0x8ECB
#define L_RES_1_IND_HL 2
#define EMIT_RES_1_IND_HL(p) EMIT_16(p, O_RES_1_IND_HL)
#define O_RES_1_A 0x8FCB
#define L_RES_1_A 2
#define EMIT_RES_1_A(p) EMIT_16(p, O_RES_1_A)
#define O_RES_2_B 0x90CB
#define L_RES_2_B 2
#define EMIT_RES_2_B(p) EMIT_16(p, O_RES_2_B)
#define O_RES_2_C 0x91CB
#define L_RES_2_C 2
#define EMIT_RES_2_C(p) EMIT_16(p, O_RES_2_C)
#define O_RES_2_D 0x92CB
#define L_RES_2_D 2
#define EMIT_RES_2_D(p) EMIT_16(p, O_RES_2_D)
#define O_RES_2_E 0x93CB
#define L_RES_2_E 2
#define EMIT_RES_2_E(p) EMIT_16(p, O_RES_2_E)
#define O_RES_2_H 0x94CB
#define L_RES_2_H 2
#define EMIT_RES_2_H(p) EMIT_16(p, O_RES_2_H)
#define O_RES_2_L 0x95CB
#define L_RES_2_L 2
#define EMIT_RES_2_L(p) EMIT_16(p, O_RES_2_L)
#define O_RES_2_IND_HL 0x96CB
#define L_RES_2_IND_HL 2
#define EMIT_RES_2_IND_HL(p) EMIT_16(p, O_RES_2_IND_HL)
#define O_RES_2_A 0x97CB
#define L_RES_2_A 2
#define EMIT_RES_2_A(p) EMIT_16(p, O_RES_2_A)
#define O_RES_3_B 0x98CB
#define L_RES_3_B 2
#define EMIT_RES_3_B(p) EMIT_16(p, O_RES_3_B)
#define O_RES_3_C 0x99CB
#define L_RES_3_C 2
#define EMIT_RES_3_C(p) EMIT_16(p, O_RES_3_C)
#define O_RES_3_D 0x9ACB
#define L_RES_3_D 2
#define EMIT_RES_3_D(p) EMIT_16(p, O_RES_3_D)
#define O_RES_3_E 0x9BCB
#define L_RES_3_E 2
#define EMIT_RES_3_E(p) EMIT_16(p, O_RES_3_E)
#define O_RES_3_H 0x9CCB
#define L_RES_3_H 2
#define EMIT_RES_3_H(p) EMIT_16(p, O_RES_3_H)
#define O_RES_3_L 0x9DCB
#define L_RES_3_L 2
#define EMIT_RES_3_L(p) EMIT_16(p, O_RES_3_L)
#define O_RES_3_IND_HL 0x9ECB
#define L_RES_3_IND_HL 2
#define EMIT_RES_3_IND_HL(p) EMIT_16(p, O_RES_3_IND_HL)
#define O_RES_3_A 0x9FCB
#define L_RES_3_A 2
#define EMIT_RES_3_A(p) EMIT_16(p, O_RES_3_A)
#define O_RES_4_B 0xA0CB
#define L_RES_4_B 2
#define EMIT_RES_4_B(p) EMIT_16(p, O_RES_4_B)
#define O_RES_4_C 0xA1CB
#define L_RES_4_C 2
#define EMIT_RES_4_C(p) EMIT_16(p, O_RES_4_C)
#define O_RES_4_D 0xA2CB
#define L_RES_4_D 2
#define EMIT_RES_4_D(p) EMIT_16(p, O_RES_4_D)
#define O_RES_4_E 0xA3CB
#define L_RES_4_E 2
#define EMIT_RES_4_E(p) EMIT_16(p, O_RES_4_E)
#define O_RES_4_H 0xA4CB
#define L_RES_4_H 2
#define EMIT_RES_4_H(p) EMIT_16(p, O_RES_4_H)
#define O_RES_4_L 0xA5CB
#define L_RES_4_L 2
#define EMIT_RES_4_L(p) EMIT_16(p, O_RES_4_L)
#define O_RES_4_IND_HL 0xA6CB
#define L_RES_4_IND_HL 2
#define EMIT_RES_4_IND_HL(p) EMIT_16(p, O_RES_4_IND_HL)
#define O_RES_4_A 0xA7CB
#define L_RES_4_A 2
#define EMIT_RES_4_A(p) EMIT_16(p, O_RES_4_A)
#define O_RES_5_B 0xA8CB
#define L_RES_5_B 2
#define EMIT_RES_5_B(p) EMIT_16(p, O_RES_5_B)
#define O_RES_5_C 0xA9CB
#define L_RES_5_C 2
#define EMIT_RES_5_C(p) EMIT_16(p, O_RES_5_C)
#define O_RES_5_D 0xAACB
#define L_RES_5_D 2
#define EMIT_RES_5_D(p) EMIT_16(p, O_RES_5_D)
#define O_RES_5_E 0xABCB
#define L_RES_5_E 2
#define EMIT_RES_5_E(p) EMIT_16(p, O_RES_5_E)
#define O_RES_5_H 0xACCB
#define L_RES_5_H 2
#define EMIT_RES_5_H(p) EMIT_16(p, O_RES_5_H)
#define O_RES_5_L 0xADCB
#define L_RES_5_L 2
#define EMIT_RES_5_L(p) EMIT_16(p, O_RES_5_L)
#define O_RES_5_IND_HL 0xAECB
#define L_RES_5_IND_HL 2
#define EMIT_RES_5_IND_HL(p) EMIT_16(p, O_RES_5_IND_HL)
#define O_RES_5_A 0xAFCB
#define L_RES_5_A 2
#define EMIT_RES_5_A(p) EMIT_16(p, O_RES_5_A)
#define O_RES_6_B 0xB0CB
#define L_RES_6_B 2
#define EMIT_RES_6_B(p) EMIT_16(p, O_RES_6_B)
#define O_RES_6_C 0xB1CB
#define L_RES_6_C 2
#define EMIT_RES_6_C(p) EMIT_16(p, O_RES_6_C)
#define O_RES_6_D 0xB2CB
#define L_RES_6_D 2
#define EMIT_RES_6_D(p) EMIT_16(p, O_RES_6_D)
#define O_RES_6_E 0xB3CB
#define L_RES_6_E 2
#define EMIT_RES_6_E(p) EMIT_16(p, O_RES_6_E)
#define O_RES_6_H 0xB4CB
#define L_RES_6_H 2
#define EMIT_RES_6_H(p) EMIT_16(p, O_RES_6_H)
#define O_RES_6_L 0xB5CB
#define L_RES_6_L 2
#define EMIT_RES_6_L(p) EMIT_16(p, O_RES_6_L)
#define O_RES_6_IND_HL 0xB6CB
#define L_RES_6_IND_HL 2
#define EMIT_RES_6_IND_HL(p) EMIT_16(p, O_RES_6_IND_HL)
#define O_RES_6_A 0xB7CB
#define L_RES_6_A 2
#define EMIT_RES_6_A(p) EMIT_16(p, O_RES_6_A)
#define O_RES_7_B 0xB8CB
#define L_RES_7_B 2
#define EMIT_RES_7_B(p) EMIT_16(p, O_RES_7_B)
#define O_RES_7_C 0xB9CB
#define L_RES_7_C 2
#define EMIT_RES_7_C(p) EMIT_16(p, O_RES_7_C)
#define O_RES_7_D 0xBACB
#define L_RES_7_D 2
#define EMIT_RES_7_D(p) EMIT_16(p, O_RES_7_D)
#define O_RES_7_E 0xBBCB
#define L_RES_7_E 2
#define EMIT_RES_7_E(p) EMIT_16(p, O_RES_7_E)
#define O_RES_7_H 0xBCCB
#define L_RES_7_H 2
#define EMIT_RES_7_H(p) EMIT_16(p, O_RES_7_H)
#define O_RES_7_L 0xBDCB
#define L_RES_7_L 2
#define EMIT_RES_7_L(p) EMIT_16(p, O_RES_7_L)
#define O_RES_7_IND_HL 0xBECB
#define L_RES_7_IND_HL 2
#define EMIT_RES_7_IND_HL(p) EMIT_16(p, O_RES_7_IND_HL)
#define O_RES_7_A 0xBFCB
#define L_RES_7_A 2
#define EMIT_RES_7_A(p) EMIT_16(p, O_RES_7_A)
#define O_SET_0_B 0xC0CB
#define L_SET_0_B 2
#define EMIT_SET_0_B(p) EMIT_16(p, O_SET_0_B)
#define O_SET_0_C 0xC1CB
#define L_SET_0_C 2
#define EMIT_SET_0_C(p) EMIT_16(p, O_SET_0_C)
#define O_SET_0_D 0xC2CB
#define L_SET_0_D 2
#define EMIT_SET_0_D(p) EMIT_16(p, O_SET_0_D)
#define O_SET_0_E 0xC3CB
#define L_SET_0_E 2
#define EMIT_SET_0_E(p) EMIT_16(p, O_SET_0_E)
#define O_SET_0_H 0xC4CB
#define L_SET_0_H 2
#define EMIT_SET_0_H(p) EMIT_16(p, O_SET_0_H)
#define O_SET_0_L 0xC5CB
#define L_SET_0_L 2
#define EMIT_SET_0_L(p) EMIT_16(p, O_SET_0_L)
#define O_SET_0_IND_HL 0xC6CB
#define L_SET_0_IND_HL 2
#define EMIT_SET_0_IND_HL(p) EMIT_16(p, O_SET_0_IND_HL)
#define O_SET_0_A 0xC7CB
#define L_SET_0_A 2
#define EMIT_SET_0_A(p) EMIT_16(p, O_SET_0_A)
#define O_SET_1_B 0xC8CB
#define L_SET_1_B 2
#define EMIT_SET_1_B(p) EMIT_16(p, O_SET_1_B)
#define O_SET_1_C 0xC9CB
#define L_SET_1_C 2
#define EMIT_SET_1_C(p) EMIT_16(p, O_SET_1_C)
#define O_SET_1_D 0xCACB
#define L_SET_1_D 2
#define EMIT_SET_1_D(p) EMIT_16(p, O_SET_1_D)
#define O_SET_1_E 0xCBCB
#define L_SET_1_E 2
#define EMIT_SET_1_E(p) EMIT_16(p, O_SET_1_E)
#define O_SET_1_H 0xCCCB
#define L_SET_1_H 2
#define EMIT_SET_1_H(p) EMIT_16(p, O_SET_1_H)
#define O_SET_1_L 0xCDCB
#define L_SET_1_L 2
#define EMIT_SET_1_L(p) EMIT_16(p, O_SET_1_L)
#define O_SET_1_IND_HL 0xCECB
#define L_SET_1_IND_HL 2
#define EMIT_SET_1_IND_HL(p) EMIT_16(p, O_SET_1_IND_HL)
#define O_SET_1_A 0xCFCB
#define L_SET_1_A 2
#define EMIT_SET_1_A(p) EMIT_16(p, O_SET_1_A)
#define O_SET_2_B 0xD0CB
#define L_SET_2_B 2
#define EMIT_SET_2_B(p) EMIT_16(p, O_SET_2_B)
#define O_SET_2_C 0xD1CB
#define L_SET_2_C 2
#define EMIT_SET_2_C(p) EMIT_16(p, O_SET_2_C)
#define O_SET_2_D 0xD2CB
#define L_SET_2_D 2
#define EMIT_SET_2_D(p) EMIT_16(p, O_SET_2_D)
#define O_SET_2_E 0xD3CB
#define L_SET_2_E 2
#define EMIT_SET_2_E(p) EMIT_16(p, O_SET_2_E)
#define O_SET_2_H 0xD4CB
#define L_SET_2_H 2
#define EMIT_SET_2_H(p) EMIT_16(p, O_SET_2_H)
#define O_SET_2_L 0xD5CB
#define L_SET_2_L 2
#define EMIT_SET_2_L(p) EMIT_16(p, O_SET_2_L)
#define O_SET_2_IND_HL 0xD6CB
#define L_SET_2_IND_HL 2
#define EMIT_SET_2_IND_HL(p) EMIT_16(p, O_SET_2_IND_HL)
#define O_SET_2_A 0xD7CB
#define L_SET_2_A 2
#define EMIT_SET_2_A(p) EMIT_16(p, O_SET_2_A)
#define O_SET_3_B 0xD8CB
#define L_SET_3_B 2
#define EMIT_SET_3_B(p) EMIT_16(p, O_SET_3_B)
#define O_SET_3_C 0xD9CB
#define L_SET_3_C 2
#define EMIT_SET_3_C(p) EMIT_16(p, O_SET_3_C)
#define O_SET_3_D 0xDACB
#define L_SET_3_D 2
#define EMIT_SET_3_D(p) EMIT_16(p, O_SET_3_D)
#define O_SET_3_E 0xDBCB
#define L_SET_3_E 2
#define EMIT_SET_3_E(p) EMIT_16(p, O_SET_3_E)
#define O_SET_3_H 0xDCCB
#define L_SET_3_H 2
#define EMIT_SET_3_H(p) EMIT_16(p, O_SET_3_H)
#define O_SET_3_L 0xDDCB
#define L_SET_3_L 2
#define EMIT_SET_3_L(p) EMIT_16(p, O_SET_3_L)
#define O_SET_3_IND_HL 0xDECB
#define L_SET_3_IND_HL 2
#define EMIT_SET_3_IND_HL(p) EMIT_16(p, O_SET_3_IND_HL)
#define O_SET_3_A 0xDFCB
#define L_SET_3_A 2
#define EMIT_SET_3_A(p) EMIT_16(p, O_SET_3_A)
#define O_SET_4_B 0xE0CB
#define L_SET_4_B 2
#define EMIT_SET_4_B(p) EMIT_16(p, O_SET_4_B)
#define O_SET_4_C 0xE1CB
#define L_SET_4_C 2
#define EMIT_SET_4_C(p) EMIT_16(p, O_SET_4_C)
#define O_SET_4_D 0xE2CB
#define L_SET_4_D 2
#define EMIT_SET_4_D(p) EMIT_16(p, O_SET_4_D)
#define O_SET_4_E 0xE3CB
#define L_SET_4_E 2
#define EMIT_SET_4_E(p) EMIT_16(p, O_SET_4_E)
#define O_SET_4_H 0xE4CB
#define L_SET_4_H 2
#define EMIT_SET_4_H(p) EMIT_16(p, O_SET_4_H)
#define O_SET_4_L 0xE5CB
#define L_SET_4_L 2
#define EMIT_SET_4_L(p) EMIT_16(p, O_SET_4_L)
#define O_SET_4_IND_HL 0xE6CB
#define L_SET_4_IND_HL 2
#define EMIT_SET_4_IND_HL(p) EMIT_16(p, O_SET_4_IND_HL)
#define O_SET_4_A 0xE7CB
#define L_SET_4_A 2
#define EMIT_SET_4_A(p) EMIT_16(p, O_SET_4_A)
#define O_SET_5_B 0xE8CB
#define L_SET_5_B 2
#define EMIT_SET_5_B(p) EMIT_16(p, O_SET_5_B)
#define O_SET_5_C 0xE9CB
#define L_SET_5_C 2
#define EMIT_SET_5_C(p) EMIT_16(p, O_SET_5_C)
#define O_SET_5_D 0xEACB
#define L_SET_5_D 2
#define EMIT_SET_5_D(p) EMIT_16(p, O_SET_5_D)
#define O_SET_5_E 0xEBCB
#define L_SET_5_E 2
#define EMIT_SET_5_E(p) EMIT_16(p, O_SET_5_E)
#define O_SET_5_H 0xECCB
#define L_SET_5_H 2
#define EMIT_SET_5_H(p) EMIT_16(p, O_SET_5_H)
#define O_SET_5_L 0xEDCB
#define L_SET_5_L 2
#define EMIT_SET_5_L(p) EMIT_16(p, O_SET_5_L)
#define O_SET_5_IND_HL 0xEECB
#define L_SET_5_IND_HL 2
#define EMIT_SET_5_IND_HL(p) EMIT_16(p, O_SET_5_IND_HL)
#define O_SET_5_A 0xEFCB
#define L_SET_5_A 2
#define EMIT_SET_5_A(p) EMIT_16(p, O_SET_5_A)
#define O_SET_6_B 0xF0CB
#define L_SET_6_B 2
#define EMIT_SET_6_B(p) EMIT_16(p, O_SET_6_B)
#define O_SET_6_C 0xF1CB
#define L_SET_6_C 2
#define EMIT_SET_6_C(p) EMIT_16(p, O_SET_6_C)
#define O_SET_6_D 0xF2CB
#define L_SET_6_D 2
#define EMIT_SET_6_D(p) EMIT_16(p, O_SET_6_D)
#define O_SET_6_E 0xF3CB
#define L_SET_6_E 2
#define EMIT_SET_6_E(p) EMIT_16(p, O_SET_6_E)
#define O_SET_6_H 0xF4CB
#define L_SET_6_H 2
#define EMIT_SET_6_H(p) EMIT_16(p, O_SET_6_H)
#define O_SET_6_L 0xF5CB
#define L_SET_6_L 2
#define EMIT_SET_6_L(p) EMIT_16(p, O_SET_6_L)
#define O_SET_6_IND_HL 0xF6CB
#define L_SET_6_IND_HL 2
#define EMIT_SET_6_IND_HL(p) EMIT_16(p, O_SET_6_IND_HL)
#define O_SET_6_A 0xF7CB
#define L_SET_6_A 2
#define EMIT_SET_6_A(p) EMIT_16(p, O_SET_6_A)
#define O_SET_7_B 0xF8CB
#define L_SET_7_B 2
#define EMIT_SET_7_B(p) EMIT_16(p, O_SET_7_B)
#define O_SET_7_C 0xF9CB
#define L_SET_7_C 2
#define EMIT_SET_7_C(p) EMIT_16(p, O_SET_7_C)
#define O_SET_7_D 0xFACB
#define L_SET_7_D 2
#define EMIT_SET_7_D(p) EMIT_16(p, O_SET_7_D)
#define O_SET_7_E 0xFBCB
#define L_SET_7_E 2
#define EMIT_SET_7_E(p) EMIT_16(p, O_SET_7_E)
#define O_SET_7_H 0xFCCB
#define L_SET_7_H 2
#define EMIT_SET_7_H(p) EMIT_16(p, O_SET_7_H)
#define O_SET_7_L 0xFDCB
#define L_SET_7_L 2
#define EMIT_SET_7_L(p) EMIT_16(p, O_SET_7_L)
#define O_SET_7_IND_HL 0xFECB
#define L_SET_7_IND_HL 2
#define EMIT_SET_7_IND_HL(p) EMIT_16(p, O_SET_7_IND_HL)
#define O_SET_7_A 0xFFCB
#define L_SET_7_A 2
#define EMIT_SET_7_A(p) EMIT_16(p, O_SET_7_A)
#define O_RLC_IND_IX_DD 0x06CBDD
#define L_RLC_IND_IX_DD 5
#define EMIT_RLC_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RLC_IND_IX_DD, v, 0x6)
#define O_RLC_IND_IY_DD 0x06CBFD
#define L_RLC_IND_IY_DD 5
#define EMIT_RLC_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RLC_IND_IY_DD, v, 0x6)
#define O_RRC_IND_IX_DD 0x0ECBDD
#define L_RRC_IND_IX_DD 5
#define EMIT_RRC_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RRC_IND_IX_DD, v, 0xE)
#define O_RRC_IND_IY_DD 0x0ECBFD
#define L_RRC_IND_IY_DD 5
#define EMIT_RRC_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RRC_IND_IY_DD, v, 0xE)
#define O_RL_IND_IX_DD 0x16CBDD
#define L_RL_IND_IX_DD 5
#define EMIT_RL_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RL_IND_IX_DD, v, 0x16)
#define O_RL_IND_IY_DD 0x16CBFD
#define L_RL_IND_IY_DD 5
#define EMIT_RL_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RL_IND_IY_DD, v, 0x16)
#define O_RR_IND_IX_DD 0x1ECBDD
#define L_RR_IND_IX_DD 5
#define EMIT_RR_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RR_IND_IX_DD, v, 0x1E)
#define O_RR_IND_IY_DD 0x1ECBFD
#define L_RR_IND_IY_DD 5
#define EMIT_RR_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RR_IND_IY_DD, v, 0x1E)
#define O_SLA_IND_IX_DD 0x26CBDD
#define L_SLA_IND_IX_DD 5
#define EMIT_SLA_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SLA_IND_IX_DD, v, 0x26)
#define O_SLA_IND_IY_DD 0x26CBFD
#define L_SLA_IND_IY_DD 5
#define EMIT_SLA_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SLA_IND_IY_DD, v, 0x26)
#define O_SRA_IND_IX_DD 0x2ECBDD
#define L_SRA_IND_IX_DD 5
#define EMIT_SRA_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SRA_IND_IX_DD, v, 0x2E)
#define O_SRA_IND_IY_DD 0x2ECBFD
#define L_SRA_IND_IY_DD 5
#define EMIT_SRA_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SRA_IND_IY_DD, v, 0x2E)
#define O_SRL_IND_IX_DD 0x3ECBDD
#define L_SRL_IND_IX_DD 5
#define EMIT_SRL_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SRL_IND_IX_DD, v, 0x3E)
#define O_SRL_IND_IY_DD 0x3ECBFD
#define L_SRL_IND_IY_DD 5
#define EMIT_SRL_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SRL_IND_IY_DD, v, 0x3E)
#define O_BIT_0_IND_IX_DD 0x46CBDD
#define L_BIT_0_IND_IX_DD 5
#define EMIT_BIT_0_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_0_IND_IX_DD, v, 0x46)
#define O_BIT_0_IND_IY_DD 0x46CBFD
#define L_BIT_0_IND_IY_DD 5
#define EMIT_BIT_0_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_0_IND_IY_DD, v, 0x46)
#define O_BIT_1_IND_IX_DD 0x4ECBDD
#define L_BIT_1_IND_IX_DD 5
#define EMIT_BIT_1_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_1_IND_IX_DD, v, 0x4E)
#define O_BIT_1_IND_IY_DD 0x4ECBFD
#define L_BIT_1_IND_IY_DD 5
#define EMIT_BIT_1_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_1_IND_IY_DD, v, 0x4E)
#define O_BIT_2_IND_IX_DD 0x56CBDD
#define L_BIT_2_IND_IX_DD 5
#define EMIT_BIT_2_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_2_IND_IX_DD, v, 0x56)
#define O_BIT_2_IND_IY_DD 0x56CBFD
#define L_BIT_2_IND_IY_DD 5
#define EMIT_BIT_2_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_2_IND_IY_DD, v, 0x56)
#define O_BIT_3_IND_IX_DD 0x5ECBDD
#define L_BIT_3_IND_IX_DD 5
#define EMIT_BIT_3_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_3_IND_IX_DD, v, 0x5E)
#define O_BIT_3_IND_IY_DD 0x5ECBFD
#define L_BIT_3_IND_IY_DD 5
#define EMIT_BIT_3_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_3_IND_IY_DD, v, 0x5E)
#define O_BIT_4_IND_IX_DD 0x66CBDD
#define L_BIT_4_IND_IX_DD 5
#define EMIT_BIT_4_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_4_IND_IX_DD, v, 0x66)
#define O_BIT_4_IND_IY_DD 0x66CBFD
#define L_BIT_4_IND_IY_DD 5
#define EMIT_BIT_4_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_4_IND_IY_DD, v, 0x66)
#define O_BIT_5_IND_IX_DD 0x6ECBDD
#define L_BIT_5_IND_IX_DD 5
#define EMIT_BIT_5_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_5_IND_IX_DD, v, 0x6E)
#define O_BIT_5_IND_IY_DD 0x6ECBFD
#define L_BIT_5_IND_IY_DD 5
#define EMIT_BIT_5_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_5_IND_IY_DD, v, 0x6E)
#define O_BIT_6_IND_IX_DD 0x76CBDD
#define L_BIT_6_IND_IX_DD 5
#define EMIT_BIT_6_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_6_IND_IX_DD, v, 0x76)
#define O_BIT_6_IND_IY_DD 0x76CBFD
#define L_BIT_6_IND_IY_DD 5
#define EMIT_BIT_6_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_6_IND_IY_DD, v, 0x76)
#define O_BIT_7_IND_IX_DD 0x7ECBDD
#define L_BIT_7_IND_IX_DD 5
#define EMIT_BIT_7_IND_IX_DD(p,v) EMIT_16_8_8(p, O_BIT_7_IND_IX_DD, v, 0x7E)
#define O_BIT_7_IND_IY_DD 0x7ECBFD
#define L_BIT_7_IND_IY_DD 5
#define EMIT_BIT_7_IND_IY_DD(p,v) EMIT_16_8_8(p, O_BIT_7_IND_IY_DD, v, 0x7E)
#define O_RES_0_IND_IX_DD 0x86CBDD
#define L_RES_0_IND_IX_DD 5
#define EMIT_RES_0_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_0_IND_IX_DD, v, 0x86)
#define O_RES_0_IND_IY_DD 0x86CBFD
#define L_RES_0_IND_IY_DD 5
#define EMIT_RES_0_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_0_IND_IY_DD, v, 0x86)
#define O_RES_1_IND_IX_DD 0x8ECBDD
#define L_RES_1_IND_IX_DD 5
#define EMIT_RES_1_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_1_IND_IX_DD, v, 0x8E)
#define O_RES_1_IND_IY_DD 0x8ECBFD
#define L_RES_1_IND_IY_DD 5
#define EMIT_RES_1_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_1_IND_IY_DD, v, 0x8E)
#define O_RES_2_IND_IX_DD 0x96CBDD
#define L_RES_2_IND_IX_DD 5
#define EMIT_RES_2_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_2_IND_IX_DD, v, 0x96)
#define O_RES_2_IND_IY_DD 0x96CBFD
#define L_RES_2_IND_IY_DD 5
#define EMIT_RES_2_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_2_IND_IY_DD, v, 0x96)
#define O_RES_3_IND_IX_DD 0x9ECBDD
#define L_RES_3_IND_IX_DD 5
#define EMIT_RES_3_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_3_IND_IX_DD, v, 0x9E)
#define O_RES_3_IND_IY_DD 0x9ECBFD
#define L_RES_3_IND_IY_DD 5
#define EMIT_RES_3_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_3_IND_IY_DD, v, 0x9E)
#define O_RES_4_IND_IX_DD 0xA6CBDD
#define L_RES_4_IND_IX_DD 5
#define EMIT_RES_4_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_4_IND_IX_DD, v, 0xA6)
#define O_RES_4_IND_IY_DD 0xA6CBFD
#define L_RES_4_IND_IY_DD 5
#define EMIT_RES_4_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_4_IND_IY_DD, v, 0xA6)
#define O_RES_5_IND_IX_DD 0xAECBDD
#define L_RES_5_IND_IX_DD 5
#define EMIT_RES_5_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_5_IND_IX_DD, v, 0xAE)
#define O_RES_5_IND_IY_DD 0xAECBFD
#define L_RES_5_IND_IY_DD 5
#define EMIT_RES_5_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_5_IND_IY_DD, v, 0xAE)
#define O_RES_6_IND_IX_DD 0xB6CBDD
#define L_RES_6_IND_IX_DD 5
#define EMIT_RES_6_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_6_IND_IX_DD, v, 0xB6)
#define O_RES_6_IND_IY_DD 0xB6CBFD
#define L_RES_6_IND_IY_DD 5
#define EMIT_RES_6_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_6_IND_IY_DD, v, 0xB6)
#define O_RES_7_IND_IX_DD 0xBECBDD
#define L_RES_7_IND_IX_DD 5
#define EMIT_RES_7_IND_IX_DD(p,v) EMIT_16_8_8(p, O_RES_7_IND_IX_DD, v, 0xBE)
#define O_RES_7_IND_IY_DD 0xBECBFD
#define L_RES_7_IND_IY_DD 5
#define EMIT_RES_7_IND_IY_DD(p,v) EMIT_16_8_8(p, O_RES_7_IND_IY_DD, v, 0xBE)
#define O_SET_0_IND_IX_DD 0xC6CBDD
#define L_SET_0_IND_IX_DD 5
#define EMIT_SET_0_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_0_IND_IX_DD, v, 0xC6)
#define O_SET_0_IND_IY_DD 0xC6CBFD
#define L_SET_0_IND_IY_DD 5
#define EMIT_SET_0_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_0_IND_IY_DD, v, 0xC6)
#define O_SET_1_IND_IX_DD 0xCECBDD
#define L_SET_1_IND_IX_DD 5
#define EMIT_SET_1_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_1_IND_IX_DD, v, 0xCE)
#define O_SET_1_IND_IY_DD 0xCECBFD
#define L_SET_1_IND_IY_DD 5
#define EMIT_SET_1_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_1_IND_IY_DD, v, 0xCE)
#define O_SET_2_IND_IX_DD 0xD6CBDD
#define L_SET_2_IND_IX_DD 5
#define EMIT_SET_2_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_2_IND_IX_DD, v, 0xD6)
#define O_SET_2_IND_IY_DD 0xD6CBFD
#define L_SET_2_IND_IY_DD 5
#define EMIT_SET_2_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_2_IND_IY_DD, v, 0xD6)
#define O_SET_3_IND_IX_DD 0xDECBDD
#define L_SET_3_IND_IX_DD 5
#define EMIT_SET_3_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_3_IND_IX_DD, v, 0xDE)
#define O_SET_3_IND_IY_DD 0xDECBFD
#define L_SET_3_IND_IY_DD 5
#define EMIT_SET_3_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_3_IND_IY_DD, v, 0xDE)
#define O_SET_4_IND_IX_DD 0xE6CBDD
#define L_SET_4_IND_IX_DD 5
#define EMIT_SET_4_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_4_IND_IX_DD, v, 0xE6)
#define O_SET_4_IND_IY_DD 0xE6CBFD
#define L_SET_4_IND_IY_DD 5
#define EMIT_SET_4_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_4_IND_IY_DD, v, 0xE6)
#define O_SET_5_IND_IX_DD 0xEECBDD
#define L_SET_5_IND_IX_DD 5
#define EMIT_SET_5_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_5_IND_IX_DD, v, 0xEE)
#define O_SET_5_IND_IY_DD 0xEECBFD
#define L_SET_5_IND_IY_DD 5
#define EMIT_SET_5_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_5_IND_IY_DD, v, 0xEE)
#define O_SET_6_IND_IX_DD 0xF6CBDD
#define L_SET_6_IND_IX_DD 5
#define EMIT_SET_6_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_6_IND_IX_DD, v, 0xF6)
#define O_SET_6_IND_IY_DD 0xF6CBFD
#define L_SET_6_IND_IY_DD 5
#define EMIT_SET_6_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_6_IND_IY_DD, v, 0xF6)
#define O_SET_7_IND_IX_DD 0xFECBDD
#define L_SET_7_IND_IX_DD 5
#define EMIT_SET_7_IND_IX_DD(p,v) EMIT_16_8_8(p, O_SET_7_IND_IX_DD, v, 0xFE)
#define O_SET_7_IND_IY_DD 0xFECBFD
#define L_SET_7_IND_IY_DD 5
#define EMIT_SET_7_IND_IY_DD(p,v) EMIT_16_8_8(p, O_SET_7_IND_IY_DD, v, 0xFE)
#define O_IN0_B_IND_IMM 0xED
#define L_IN0_B_IND_IMM 2
#define EMIT_IN0_B_IND_IMM(p,v) EMIT_8_8(p, O_IN0_B_IND_IMM, v)
#define O_OUT0_IND_IMM_B 0x01ED
#define L_OUT0_IND_IMM_B 3
#define EMIT_OUT0_IND_IMM_B(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_B, v)
#define O_LEA_BC_IX_DD 0x02ED
#define L_LEA_BC_IX_DD 3
#define EMIT_LEA_BC_IX_DD(p,v) EMIT_16_8(p, O_LEA_BC_IX_DD, v)
#define O_LEA_BC_IY_DD 0x03ED
#define L_LEA_BC_IY_DD 3
#define EMIT_LEA_BC_IY_DD(p,v) EMIT_16_8(p, O_LEA_BC_IY_DD, v)
#define O_TST_A_B 0x04ED
#define L_TST_A_B 2
#define EMIT_TST_A_B(p) EMIT_16(p, O_TST_A_B)
#define O_LD_BC_IND_HL 0x07ED
#define L_LD_BC_IND_HL 2
#define EMIT_LD_BC_IND_HL(p) EMIT_16(p, O_LD_BC_IND_HL)
#define O_IN0_C_IND_IMM 0x08ED
#define L_IN0_C_IND_IMM 3
#define EMIT_IN0_C_IND_IMM(p,v) EMIT_16_8(p, O_IN0_C_IND_IMM, v)
#define O_OUT0_IND_IMM_C 0x09ED
#define L_OUT0_IND_IMM_C 3
#define EMIT_OUT0_IND_IMM_C(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_C, v)
#define O_TST_A_C 0x0CED
#define L_TST_A_C 2
#define EMIT_TST_A_C(p) EMIT_16(p, O_TST_A_C)
#define O_LD_IND_HL_BC 0x0FED
#define L_LD_IND_HL_BC 2
#define EMIT_LD_IND_HL_BC(p) EMIT_16(p, O_LD_IND_HL_BC)
#define O_IN0_D_IND_IMM 0x10ED
#define L_IN0_D_IND_IMM 3
#define EMIT_IN0_D_IND_IMM(p,v) EMIT_16_8(p, O_IN0_D_IND_IMM, v)
#define O_OUT0_IND_IMM_D 0x11ED
#define L_OUT0_IND_IMM_D 3
#define EMIT_OUT0_IND_IMM_D(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_D, v)
#define O_LEA_DE_IX_DD 0x12ED
#define L_LEA_DE_IX_DD 3
#define EMIT_LEA_DE_IX_DD(p,v) EMIT_16_8(p, O_LEA_DE_IX_DD, v)
#define O_LEA_DE_IY_DD 0x13ED
#define L_LEA_DE_IY_DD 3
#define EMIT_LEA_DE_IY_DD(p,v) EMIT_16_8(p, O_LEA_DE_IY_DD, v)
#define O_TST_A_D 0x14ED
#define L_TST_A_D 2
#define EMIT_TST_A_D(p) EMIT_16(p, O_TST_A_D)
#define O_LD_DE_IND_HL 0x17ED
#define L_LD_DE_IND_HL 2
#define EMIT_LD_DE_IND_HL(p) EMIT_16(p, O_LD_DE_IND_HL)
#define O_IN0_E_IND_IMM 0x18ED
#define L_IN0_E_IND_IMM 3
#define EMIT_IN0_E_IND_IMM(p,v) EMIT_16_8(p, O_IN0_E_IND_IMM, v)
#define O_OUT0_IND_IMM_E 0x19ED
#define L_OUT0_IND_IMM_E 3
#define EMIT_OUT0_IND_IMM_E(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_E, v)
#define O_TST_A_E 0x1CED
#define L_TST_A_E 2
#define EMIT_TST_A_E(p) EMIT_16(p, O_TST_A_E)
#define O_LD_IND_HL_DE 0x1FED
#define L_LD_IND_HL_DE 2
#define EMIT_LD_IND_HL_DE(p) EMIT_16(p, O_LD_IND_HL_DE)
#define O_IN0_H_IND_IMM 0x20ED
#define L_IN0_H_IND_IMM 3
#define EMIT_IN0_H_IND_IMM(p,v) EMIT_16_8(p, O_IN0_H_IND_IMM, v)
#define O_OUT0_IND_IMM_H 0x21ED
#define L_OUT0_IND_IMM_H 3
#define EMIT_OUT0_IND_IMM_H(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_H, v)
#define O_LEA_HL_IX_DD 0x22ED
#define L_LEA_HL_IX_DD 3
#define EMIT_LEA_HL_IX_DD(p,v) EMIT_16_8(p, O_LEA_HL_IX_DD, v)
#define O_LEA_HL_IY_DD 0x23ED
#define L_LEA_HL_IY_DD 3
#define EMIT_LEA_HL_IY_DD(p,v) EMIT_16_8(p, O_LEA_HL_IY_DD, v)
#define O_TST_A_H 0x24ED
#define L_TST_A_H 2
#define EMIT_TST_A_H(p) EMIT_16(p, O_TST_A_H)
#define O_LD_HL_IND_HL 0x27ED
#define L_LD_HL_IND_HL 2
#define EMIT_LD_HL_IND_HL(p) EMIT_16(p, O_LD_HL_IND_HL)
#define O_IN0_L_IND_IMM 0x28ED
#define L_IN0_L_IND_IMM 3
#define EMIT_IN0_L_IND_IMM(p,v) EMIT_16_8(p, O_IN0_L_IND_IMM, v)
#define O_OUT0_IND_IMM_L 0x29ED
#define L_OUT0_IND_IMM_L 3
#define EMIT_OUT0_IND_IMM_L(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_L, v)
#define O_TST_A_L 0x2CED
#define L_TST_A_L 2
#define EMIT_TST_A_L(p) EMIT_16(p, O_TST_A_L)
#define O_LD_IND_HL_HL 0x2FED
#define L_LD_IND_HL_HL 2
#define EMIT_LD_IND_HL_HL(p) EMIT_16(p, O_LD_IND_HL_HL)
#define O_LEA_IX_IX_DD 0x32ED
#define L_LEA_IX_IX_DD 3
#define EMIT_LEA_IX_IX_DD(p,v) EMIT_16_8(p, O_LEA_IX_IX_DD, v)
#define O_LEA_IY_IY_DD 0x33ED
#define L_LEA_IY_IY_DD 3
#define EMIT_LEA_IY_IY_DD(p,v) EMIT_16_8(p, O_LEA_IY_IY_DD, v)
#define O_TST_A_IND_HL 0x34ED
#define L_TST_A_IND_HL 2
#define EMIT_TST_A_IND_HL(p) EMIT_16(p, O_TST_A_IND_HL)
#define O_LD_IY_IND_HL 0x36ED
#define L_LD_IY_IND_HL 2
#define EMIT_LD_IY_IND_HL(p) EMIT_16(p, O_LD_IY_IND_HL)
#define O_LD_IX_IND_HL 0x37ED
#define L_LD_IX_IND_HL 2
#define EMIT_LD_IX_IND_HL(p) EMIT_16(p, O_LD_IX_IND_HL)
#define O_IN0_A_IND_IMM 0x38ED
#define L_IN0_A_IND_IMM 3
#define EMIT_IN0_A_IND_IMM(p,v) EMIT_16_8(p, O_IN0_A_IND_IMM, v)
#define O_OUT0_IND_IMM_A 0x39ED
#define L_OUT0_IND_IMM_A 3
#define EMIT_OUT0_IND_IMM_A(p,v) EMIT_16_8(p, O_OUT0_IND_IMM_A, v)
#define O_TST_A_A 0x3CED
#define L_TST_A_A 2
#define EMIT_TST_A_A(p) EMIT_16(p, O_TST_A_A)
#define O_LD_IND_HL_IY 0x3EED
#define L_LD_IND_HL_IY 2
#define EMIT_LD_IND_HL_IY(p) EMIT_16(p, O_LD_IND_HL_IY)
#define O_LD_IND_HL_IX 0x3FED
#define L_LD_IND_HL_IX 2
#define EMIT_LD_IND_HL_IX(p) EMIT_16(p, O_LD_IND_HL_IX)
#define O_IN_B_IND_BC 0x40ED
#define L_IN_B_IND_BC 2
#define EMIT_IN_B_IND_BC(p) EMIT_16(p, O_IN_B_IND_BC)
#define O_OUT_IND_BC_B 0x41ED
#define L_OUT_IND_BC_B 2
#define EMIT_OUT_IND_BC_B(p) EMIT_16(p, O_OUT_IND_BC_B)
#define O_SBC_HL_BC 0x42ED
#define L_SBC_HL_BC 2
#define EMIT_SBC_HL_BC(p) EMIT_16(p, O_SBC_HL_BC)
#define O_LD_IND_IMM_BC 0x43ED
#define L_LD_IND_IMM_BC 4
#define EMIT_LD_IND_IMM_BC(p,v) EMIT_16_24(p, O_LD_IND_IMM_BC, v)
#define O_NEG 0x44ED
#define L_NEG 2
#define EMIT_NEG(p) EMIT_16(p, O_NEG)
#define O_RETN 0x45ED
#define L_RETN 2
#define EMIT_RETN(p) EMIT_16(p, O_RETN)
#define O_IM_0 0x46ED
#define L_IM_0 2
#define EMIT_IM_0(p) EMIT_16(p, O_IM_0)
#define O_LD_I_A 0x47ED
#define L_LD_I_A 2
#define EMIT_LD_I_A(p) EMIT_16(p, O_LD_I_A)
#define O_IN_C_IND_BC 0x48ED
#define L_IN_C_IND_BC 2
#define EMIT_IN_C_IND_BC(p) EMIT_16(p, O_IN_C_IND_BC)
#define O_OUT_IND_BC_C 0x49ED
#define L_OUT_IND_BC_C 2
#define EMIT_OUT_IND_BC_C(p) EMIT_16(p, O_OUT_IND_BC_C)
#define O_ADC_HL_BC 0x4AED
#define L_ADC_HL_BC 2
#define EMIT_ADC_HL_BC(p) EMIT_16(p, O_ADC_HL_BC)
#define O_LD_BC_IND_IMM 0x4BED
#define L_LD_BC_IND_IMM 4
#define EMIT_LD_BC_IND_IMM(p,v) EMIT_16_24(p, O_LD_BC_IND_IMM, v)
#define O_MLT_BC 0x4CED
#define L_MLT_BC 2
#define EMIT_MLT_BC(p) EMIT_16(p, O_MLT_BC)
#define O_RETI 0x4DED
#define L_RETI 2
#define EMIT_RETI(p) EMIT_16(p, O_RETI)
#define O_LD_R_A 0x4FED
#define L_LD_R_A 2
#define EMIT_LD_R_A(p) EMIT_16(p, O_LD_R_A)
#define O_IN_D_IND_BC 0x50ED
#define L_IN_D_IND_BC 2
#define EMIT_IN_D_IND_BC(p) EMIT_16(p, O_IN_D_IND_BC)
#define O_OUT_IND_BC_D 0x51ED
#define L_OUT_IND_BC_D 2
#define EMIT_OUT_IND_BC_D(p) EMIT_16(p, O_OUT_IND_BC_D)
#define O_SBC_HL_DE 0x52ED
#define L_SBC_HL_DE 2
#define EMIT_SBC_HL_DE(p) EMIT_16(p, O_SBC_HL_DE)
#define O_LD_IND_IMM_DE 0x53ED
#define L_LD_IND_IMM_DE 4
#define EMIT_LD_IND_IMM_DE(p,v) EMIT_16_24(p, O_LD_IND_IMM_DE, v)
#define O_LEA_IX_IY_DD 0x54ED
#define L_LEA_IX_IY_DD 3
#define EMIT_LEA_IX_IY_DD(p,v) EMIT_16_8(p, O_LEA_IX_IY_DD, v)
#define O_LEA_IY_IX_DD 0x55ED
#define L_LEA_IY_IX_DD 3
#define EMIT_LEA_IY_IX_DD(p,v) EMIT_16_8(p, O_LEA_IY_IX_DD, v)
#define O_IM_1 0x56ED
#define L_IM_1 2
#define EMIT_IM_1(p) EMIT_16(p, O_IM_1)
#define O_LD_A_I 0x57ED
#define L_LD_A_I 2
#define EMIT_LD_A_I(p) EMIT_16(p, O_LD_A_I)
#define O_IN_E_IND_BC 0x58ED
#define L_IN_E_IND_BC 2
#define EMIT_IN_E_IND_BC(p) EMIT_16(p, O_IN_E_IND_BC)
#define O_OUT_IND_BC_E 0x59ED
#define L_OUT_IND_BC_E 2
#define EMIT_OUT_IND_BC_E(p) EMIT_16(p, O_OUT_IND_BC_E)
#define O_ADC_HL_DE 0x5AED
#define L_ADC_HL_DE 2
#define EMIT_ADC_HL_DE(p) EMIT_16(p, O_ADC_HL_DE)
#define O_LD_DE_IND_IMM 0x5BED
#define L_LD_DE_IND_IMM 4
#define EMIT_LD_DE_IND_IMM(p,v) EMIT_16_24(p, O_LD_DE_IND_IMM, v)
#define O_MLT_DE 0x5CED
#define L_MLT_DE 2
#define EMIT_MLT_DE(p) EMIT_16(p, O_MLT_DE)
#define O_IM_2 0x5EED
#define L_IM_2 2
#define EMIT_IM_2(p) EMIT_16(p, O_IM_2)
#define O_LD_A_R 0x5FED
#define L_LD_A_R 2
#define EMIT_LD_A_R(p) EMIT_16(p, O_LD_A_R)
#define O_IN_H_IND_BC 0x60ED
#define L_IN_H_IND_BC 2
#define EMIT_IN_H_IND_BC(p) EMIT_16(p, O_IN_H_IND_BC)
#define O_OUT_IND_BC_H 0x61ED
#define L_OUT_IND_BC_H 2
#define EMIT_OUT_IND_BC_H(p) EMIT_16(p, O_OUT_IND_BC_H)
#define O_SBC_HL_HL 0x62ED
#define L_SBC_HL_HL 2
#define EMIT_SBC_HL_HL(p) EMIT_16(p, O_SBC_HL_HL)
#define O_TST_A_IMM 0x64ED
#define L_TST_A_IMM 3
#define EMIT_TST_A_IMM(p,v) EMIT_16_8(p, O_TST_A_IMM, v)
#define O_PEA_IX_DD 0x65ED
#define L_PEA_IX_DD 3
#define EMIT_PEA_IX_DD(p,v) EMIT_16_8(p, O_PEA_IX_DD, v)
#define O_PEA_IY_DD 0x66ED
#define L_PEA_IY_DD 3
#define EMIT_PEA_IY_DD(p,v) EMIT_16_8(p, O_PEA_IY_DD, v)
#define O_RRD 0x67ED
#define L_RRD 2
#define EMIT_RRD(p) EMIT_16(p, O_RRD)
#define O_IN_L_IND_BC 0x68ED
#define L_IN_L_IND_BC 2
#define EMIT_IN_L_IND_BC(p) EMIT_16(p, O_IN_L_IND_BC)
#define O_OUT_IND_BC_L 0x69ED
#define L_OUT_IND_BC_L 2
#define EMIT_OUT_IND_BC_L(p) EMIT_16(p, O_OUT_IND_BC_L)
#define O_ADC_HL_HL 0x6AED
#define L_ADC_HL_HL 2
#define EMIT_ADC_HL_HL(p) EMIT_16(p, O_ADC_HL_HL)
#define O_MLT_HL 0x6CED
#define L_MLT_HL 2
#define EMIT_MLT_HL(p) EMIT_16(p, O_MLT_HL)
#define O_LD_MB_A 0x6DED
#define L_LD_MB_A 2
#define EMIT_LD_MB_A(p) EMIT_16(p, O_LD_MB_A)
#define O_LD_A_MB 0x6EED
#define L_LD_A_MB 2
#define EMIT_LD_A_MB(p) EMIT_16(p, O_LD_A_MB)
#define O_RLD 0x6FED
#define L_RLD 2
#define EMIT_RLD(p) EMIT_16(p, O_RLD)
#define O_SBC_HL_SP 0x72ED
#define L_SBC_HL_SP 2
#define EMIT_SBC_HL_SP(p) EMIT_16(p, O_SBC_HL_SP)
#define O_LD_IND_IMM_SP 0x73ED
#define L_LD_IND_IMM_SP 4
#define EMIT_LD_IND_IMM_SP(p,v) EMIT_16_24(p, O_LD_IND_IMM_SP, v)
#define O_TSTIO_IMM 0x74ED
#define L_TSTIO_IMM 3
#define EMIT_TSTIO_IMM(p,v) EMIT_16_8(p, O_TSTIO_IMM, v)
#define O_SLP 0x76ED
#define L_SLP 2
#define EMIT_SLP(p) EMIT_16(p, O_SLP)
#define O_IN_A_IND_BC 0x78ED
#define L_IN_A_IND_BC 2
#define EMIT_IN_A_IND_BC(p) EMIT_16(p, O_IN_A_IND_BC)
#define O_OUT_IND_BC_A 0x79ED
#define L_OUT_IND_BC_A 2
#define EMIT_OUT_IND_BC_A(p) EMIT_16(p, O_OUT_IND_BC_A)
#define O_ADC_HL_SP 0x7AED
#define L_ADC_HL_SP 2
#define EMIT_ADC_HL_SP(p) EMIT_16(p, O_ADC_HL_SP)
#define O_LD_SP_IND_IMM 0x7BED
#define L_LD_SP_IND_IMM 4
#define EMIT_LD_SP_IND_IMM(p,v) EMIT_16_24(p, O_LD_SP_IND_IMM, v)
#define O_MLT_SP 0x7CED
#define L_MLT_SP 2
#define EMIT_MLT_SP(p) EMIT_16(p, O_MLT_SP)
#define O_STMIX 0x7DED
#define L_STMIX 2
#define EMIT_STMIX(p) EMIT_16(p, O_STMIX)
#define O_RSMIX 0x7EED
#define L_RSMIX 2
#define EMIT_RSMIX(p) EMIT_16(p, O_RSMIX)
#define O_INIM 0x82ED
#define L_INIM 2
#define EMIT_INIM(p) EMIT_16(p, O_INIM)
#define O_OTIM 0x83ED
#define L_OTIM 2
#define EMIT_OTIM(p) EMIT_16(p, O_OTIM)
#define O_INI2 0x84ED
#define L_INI2 2
#define EMIT_INI2(p) EMIT_16(p, O_INI2)
#define O_INDM 0x8AED
#define L_INDM 2
#define EMIT_INDM(p) EMIT_16(p, O_INDM)
#define O_OTDM 0x8BED
#define L_OTDM 2
#define EMIT_OTDM(p) EMIT_16(p, O_OTDM)
#define O_IND2 0x8CED
#define L_IND2 2
#define EMIT_IND2(p) EMIT_16(p, O_IND2)
#define O_INIMR 0x92ED
#define L_INIMR 2
#define EMIT_INIMR(p) EMIT_16(p, O_INIMR)
#define O_OTIMR 0x93ED
#define L_OTIMR 2
#define EMIT_OTIMR(p) EMIT_16(p, O_OTIMR)
#define O_INI2R 0x94ED
#define L_INI2R 2
#define EMIT_INI2R(p) EMIT_16(p, O_INI2R)
#define O_INDMR 0x9AED
#define L_INDMR 2
#define EMIT_INDMR(p) EMIT_16(p, O_INDMR)
#define O_OTDMR 0x9BED
#define L_OTDMR 2
#define EMIT_OTDMR(p) EMIT_16(p, O_OTDMR)
#define O_IND2R 0x9CED
#define L_IND2R 2
#define EMIT_IND2R(p) EMIT_16(p, O_IND2R)
#define O_LDI 0xA0ED
#define L_LDI 2
#define EMIT_LDI(p) EMIT_16(p, O_LDI)
#define O_CPI 0xA1ED
#define L_CPI 2
#define EMIT_CPI(p) EMIT_16(p, O_CPI)
#define O_INI 0xA2ED
#define L_INI 2
#define EMIT_INI(p) EMIT_16(p, O_INI)
#define O_OTI 0xA3ED
#define L_OTI 2
#define EMIT_OTI(p) EMIT_16(p, O_OTI)
#define O_OTI2 0xA4ED
#define L_OTI2 2
#define EMIT_OTI2(p) EMIT_16(p, O_OTI2)
#define O_LDD 0xA8ED
#define L_LDD 2
#define EMIT_LDD(p) EMIT_16(p, O_LDD)
#define O_CPD 0xA9ED
#define L_CPD 2
#define EMIT_CPD(p) EMIT_16(p, O_CPD)
#define O_IND 0xAAED
#define L_IND 2
#define EMIT_IND(p) EMIT_16(p, O_IND)
#define O_OTD 0xABED
#define L_OTD 2
#define EMIT_OTD(p) EMIT_16(p, O_OTD)
#define O_OTD2 0xACED
#define L_OTD2 2
#define EMIT_OTD2(p) EMIT_16(p, O_OTD2)
#define O_LDIR 0xB0ED
#define L_LDIR 2
#define EMIT_LDIR(p) EMIT_16(p, O_LDIR)
#define O_CPIR 0xB1ED
#define L_CPIR 2
#define EMIT_CPIR(p) EMIT_16(p, O_CPIR)
#define O_INIR 0xB2ED
#define L_INIR 2
#define EMIT_INIR(p) EMIT_16(p, O_INIR)
#define O_OTIR 0xB3ED
#define L_OTIR 2
#define EMIT_OTIR(p) EMIT_16(p, O_OTIR)
#define O_ORI2R 0xB4ED
#define L_ORI2R 2
#define EMIT_ORI2R(p) EMIT_16(p, O_ORI2R)
#define O_LDDR 0xB8ED
#define L_LDDR 2
#define EMIT_LDDR(p) EMIT_16(p, O_LDDR)
#define O_CPDR 0xB9ED
#define L_CPDR 2
#define EMIT_CPDR(p) EMIT_16(p, O_CPDR)
#define O_INDR 0xBAED
#define L_INDR 2
#define EMIT_INDR(p) EMIT_16(p, O_INDR)
#define O_OTDR 0xBBED
#define L_OTDR 2
#define EMIT_OTDR(p) EMIT_16(p, O_OTDR)
#define O_OTD2R 0xBCED
#define L_OTD2R 2
#define EMIT_OTD2R(p) EMIT_16(p, O_OTD2R)
#endif