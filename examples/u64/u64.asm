
DEFINE_FUNCTION "0init", $0, $AC821B90
$2     : ENTER $0
$4     : LEAVE

DEFINE_FUNCTION "print", $207C0, $207C0, $AD1B07C0

DEFINE_FUNCTION "u64_add", $7, $AD1B0810
$9     : ENTER -$7
$B     : IMM $0
$D     : STORE_LOCAL -$1, $1
$10    : IMM $0
$12    : STORE_LOCAL -$7, $3
$15    : LEA_LOCAL $6
$17    : LOAD_INT
$18    : PUSH
$19    : LEA_LOCAL -$1
$1B    : LOAD_CHAR
$1C    : POP_SEC
$1D    : ADD
$1E    : PUSH
$1F    : LEA_LOCAL -$7
$21    : LOAD_INT
$22    : PUSH
$23    : LEA_LOCAL $6
$25    : LOAD_INT
$26    : PUSH
$27    : LEA_LOCAL -$1
$29    : LOAD_CHAR
$2A    : POP_SEC
$2B    : ADD
$2C    : LAND
$2D    : POP_SEC
$2E    : ADD
$2F    : PUSH
$30    : LEA_LOCAL $9
$32    : LOAD_INT
$33    : PUSH
$34    : LEA_LOCAL -$1
$36    : LOAD_CHAR
$37    : POP_SEC
$38    : ADD
$39    : LAND
$3A    : POP_SEC
$3B    : ADD
$3C    : STORE_LOCAL -$7, $3
$3F    : POP_SEC
$40    : STORE $1
$42    : LEA_LOCAL -$7
$44    : LOAD_INT
$45    : SHR_CONST $8
$47    : STORE_LOCAL -$7, $3
$4A    : LEA_LOCAL -$1
$4C    : LOAD_CHAR
$4D    : INC
$4E    : STORE_LOCAL -$1, $1
$51    : COMPARE_LT_CONST $8
$53    : BZ $15, $AD1B0720
$55    : LEA_LOCAL $6
$57    : LOAD_INT
$58    : LEAVE

DEFINE_FUNCTION "u64_from_int", $59, $AD1B10F0
$5B    : ENTER -$5
$5D    : LEA_LOCAL $6
$5F    : LOAD_INT
$60    : STORE_LOCAL -$5, $44
$63    : PUSH
$64    : LEA_LOCAL $9
$66    : LOAD_LONG
$67    : POP_SEC
$68    : STORE $4
$6A    : IMM $4
$6C    : STORE_LOCAL -$1, $1
$6F    : LEA_LOCAL $9
$71    : LOAD_LONG
$72    : IMM_32_SEC $80000000, $80
$75    : COMPARE_GTEQ
$76    : BNZ $7F, $AD1B0A40
$78    : IMM $FF
$7A    : STORE_LOCAL -$2, $1
$7D    : JMP $84, $AD1B08B0
$7F    : IMM $0
$81    : STORE_LOCAL -$2, $1
$84    : LEA_LOCAL $6
$86    : LOAD_INT
$87    : PUSH
$88    : LEA_LOCAL -$1
$8A    : LOAD_CHAR
$8B    : POP_SEC
$8C    : ADD
$8D    : PUSH
$8E    : LEA_LOCAL -$2
$90    : LOAD_CHAR
$91    : POP_SEC
$92    : STORE $1
$94    : LEA_LOCAL -$1
$96    : LOAD_CHAR
$97    : INC
$98    : STORE_LOCAL -$1, $1
$9B    : COMPARE_LT_CONST $8
$9D    : BZ $84, $AD1B0AE0
$9F    : LEA_LOCAL $6
$A1    : LOAD_INT
$A2    : LEAVE

DEFINE_FUNCTION "u64_to_int", $A3, $AD1B1170
$A5    : ENTER -$3
$A7    : LEA_LOCAL $6
$A9    : LOAD_INT
$AA    : STORE_LOCAL -$3, $44
$AD    : LEA_LOCAL -$3
$AF    : LOAD_INT
$B0    : LOAD_LONG
$B1    : LEAVE

DEFINE_FUNCTION "u64_to_hexstr", $B2, $AD1B11F0
$B4    : ENTER -$5
$B6    : IMM_PROG_OFFSET $15A, $AD1B0630
$B8    : STORE_LOCAL -$3, $8
$BB    : IMM $10
$BD    : STORE_LOCAL -$4, $1
$C0    : LEA_LOCAL $6
$C2    : LOAD_INT
$C3    : INC
$C4    : STORE_LOCAL $6, $8
$C7    : LOAD_CHAR
$C8    : STORE_LOCAL -$5, $1
$CB    : LEA_LOCAL -$4
$CD    : LOAD_CHAR
$CE    : SUB_CONST $2
$D0    : STORE_LOCAL -$4, $1
$D3    : LEA_LOCAL $9
$D5    : LOAD_INT
$D6    : PUSH
$D7    : LEA_LOCAL -$3
$D9    : LOAD_INT
$DA    : PUSH
$DB    : LEA_LOCAL -$5
$DD    : LOAD_CHAR
$DE    : SHR_CONST $4
$E0    : POP_SEC
$E1    : ADD
$E2    : LAND
$E3    : POP_SEC
$E4    : STORE $1
$E6    : LEA_LOCAL $9
$E8    : LOAD_INT
$E9    : INC
$EA    : STORE_LOCAL $9, $8
$ED    : LEA_LOCAL $9
$EF    : LOAD_INT
$F0    : PUSH
$F1    : LEA_LOCAL -$3
$F3    : LOAD_INT
$F4    : PUSH
$F5    : LEA_LOCAL -$5
$F7    : LOAD_CHAR
$F8    : AND_CONST $F
$FA    : POP_SEC
$FB    : ADD
$FC    : LAND
$FD    : POP_SEC
$FE    : STORE $1
$100   : LEA_LOCAL $9
$102   : LOAD_INT
$103   : INC
$104   : STORE_LOCAL $9, $8
$107   : LEA_LOCAL -$4
$109   : LOAD_CHAR
$10A   : COMPARE_GT_CONST $0
$10C   : BZ $C0, $AD1B0770
$10E   : LEA_LOCAL $9
$110   : LOAD_INT
$111   : ADD_CONST $1
$113   : EX_SEC_PRI
$114   : IMM $0
$116   : STORE $3
$118   : LEA_LOCAL $9
$11A   : LOAD_INT
$11B   : SUB_CONST $10
$11D   : LEAVE

DEFINE_FUNCTION "main", $11E, $AD1B05E0
$120   : ENTER -$21
$122   : PUSH_ARG_IMM_32 $4D2, $0
$125   : LEA_LOCAL -$8
$127   : PUSH_ARG
$128   : CALL "u64_from_int", $AD1B10F0
$12A   : ADJ $9
$12C   : PUSH_ARG_IMM_32 $162E, $0
$12F   : LEA_LOCAL -$10
$131   : PUSH_ARG
$132   : CALL "u64_from_int", $AD1B10F0
$134   : ADJ $9
$136   : LEA_LOCAL -$10
$138   : PUSH_ARG
$139   : LEA_LOCAL -$8
$13B   : PUSH_ARG
$13C   : CALL "u64_add", $AD1B0810
$13E   : ADJ $6
$140   : LEA_LOCAL -$21
$142   : PUSH_ARG
$143   : LEA_LOCAL -$8
$145   : PUSH_ARG
$146   : CALL "u64_to_hexstr", $AD1B11F0
$148   : ADJ $6
$14A   : LEA_LOCAL -$21
$14C   : PUSH_ARG
$14D   : CALL "print", $207C0, $AD1B07C0
$14F   : ADJ $3
$151   : LEA_LOCAL -$8
$153   : PUSH_ARG
$154   : CALL "u64_to_int", $AD1B1170
$156   : ADJ $3
$158   : LEAVE
$159   : NOP
db $31, $32, $33, $34, $35, $36, $37, $38, $39, $41, $42, $43, $44, $45, $46, 0
db 0
