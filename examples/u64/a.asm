
DEFINE_FUNCTION "u64_add", $0, $C02D0540, $2
$3     : ENTER -$3
$5     : IMM $0
$7     : STORE_LOCAL -$1, $1
$A     : IMM $0
$C     : STORE_LOCAL -$3, $2
$F     : LEA_LOCAL $6
$11    : LOAD_INT
$12    : PUSH
$13    : LEA_LOCAL -$1
$15    : LOAD_CHAR
$16    : MUL_CONST $1
$18    : POP_SEC
$19    : ADD
$1A    : PUSH
$1B    : LEA_LOCAL -$3
$1D    : LOAD_WORD
$1E    : PUSH
$1F    : LEA_LOCAL $6
$21    : LOAD_INT
$22    : PUSH
$23    : LEA_LOCAL -$1
$25    : LOAD_CHAR
$26    : MUL_CONST $1
$28    : POP_SEC
$29    : ADD
$2A    : LOAD_CHAR
$2B    : POP_SEC
$2C    : ADD
$2D    : PUSH
$2E    : LEA_LOCAL $9
$30    : LOAD_INT
$31    : PUSH
$32    : LEA_LOCAL -$1
$34    : LOAD_CHAR
$35    : MUL_CONST $1
$37    : POP_SEC
$38    : ADD
$39    : LOAD_CHAR
$3A    : POP_SEC
$3B    : ADD
$3C    : STORE_LOCAL -$3, $2
$3F    : POP_SEC
$40    : STORE $1
$42    : LEA_LOCAL -$3
$44    : LOAD_WORD
$45    : SHR_CONST $8
$47    : STORE_LOCAL -$3, $2
$4A    : LEA_LOCAL -$1
$4C    : LOAD_CHAR
$4D    : INC
$4E    : STORE_LOCAL -$1, $1
$51    : COMPARE_LT_CONST $8
$53    : BZ $F, $C02D11A0
$55    : LEA_LOCAL $6
$57    : LOAD_INT
$58    : LEAVE

DEFINE_FUNCTION "u64_from_int", $59, $C02D0860, $2
$5C    : ENTER -$6
$5E    : LEA_LOCAL $6
$60    : LOAD_INT
$61    : STORE_LOCAL -$6, $44
$64    : PUSH
$65    : LEA_LOCAL $9
$67    : LOAD_LONG
$68    : POP_SEC
$69    : STORE $4
$6B    : IMM $4
$6D    : STORE_LOCAL -$1, $1
$70    : LEA_LOCAL $9
$72    : LOAD_LONG
$73    : IMM_32_SEC $800000, $0
$76    : BZ $7F, $C02D1200
$78    : IMM $FF
$7A    : STORE_LOCAL -$2, $1
$7D    : JMP $84, $C02D1240
$7F    : IMM $0
$81    : STORE_LOCAL -$2, $1
$84    : LEA_LOCAL $6
$86    : LOAD_INT
$87    : PUSH
$88    : LEA_LOCAL -$1
$8A    : LOAD_CHAR
$8B    : MUL_CONST $1
$8D    : POP_SEC
$8E    : ADD
$8F    : PUSH
$90    : LEA_LOCAL -$2
$92    : LOAD_CHAR
$93    : POP_SEC
$94    : STORE $1
$96    : LEA_LOCAL -$1
$98    : LOAD_CHAR
$99    : INC
$9A    : STORE_LOCAL -$1, $1
$9D    : COMPARE_LT_CONST $8
$9F    : BZ $84, $C02D1280
$A1    : LEA_LOCAL $6
$A3    : LOAD_INT
$A4    : LEAVE

DEFINE_FUNCTION "main", $A5, $C02D0900, $0
$A8    : ENTER -$8
$AA    : PUSH_ARG_IMM_32 $4B0, $0
$AD    : LEA_LOCAL -$8
$AF    : PUSH_ARG
$B0    : CALL "u64_from_int", $C02D0860
$B2    : ADJ $9
$B4    : LEA_LOCAL -$8
$B6    : PUSH_ARG
$B7    : LEA_LOCAL -$8
$B9    : PUSH_ARG
$BA    : CALL "u64_add", $C02D0540
$BC    : ADJ $6
$BE    : IMM $0
$C0    : LEAVE
$C1    : NOP
