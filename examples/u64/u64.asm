
DEFINE_FUNCTION "u64_add", $0, $C081EB0, $2
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
$16    : POP_SEC
$17    : ADD
$18    : PUSH
$19    : LEA_LOCAL -$3
$1B    : LOAD_WORD
$1C    : PUSH
$1D    : LEA_LOCAL $6
$1F    : LOAD_INT
$20    : PUSH
$21    : LEA_LOCAL -$1
$23    : LOAD_CHAR
$24    : POP_SEC
$25    : ADD
$26    : LOAD_CHAR
$27    : POP_SEC
$28    : ADD
$29    : PUSH
$2A    : LEA_LOCAL $9
$2C    : LOAD_INT
$2D    : PUSH
$2E    : LEA_LOCAL -$1
$30    : LOAD_CHAR
$31    : POP_SEC
$32    : ADD
$33    : LOAD_CHAR
$34    : POP_SEC
$35    : ADD
$36    : STORE_LOCAL -$3, $2
$39    : POP_SEC
$3A    : STORE $1
$3C    : LEA_LOCAL -$3
$3E    : LOAD_WORD
$3F    : SHR_CONST $8
$41    : STORE_LOCAL -$3, $2
$44    : LEA_LOCAL -$1
$46    : LOAD_CHAR
$47    : INC
$48    : STORE_LOCAL -$1, $1
$4B    : COMPARE_LT_CONST $8
$4D    : BZ $F, $C081FC0
$4F    : LEA_LOCAL $6
$51    : LOAD_INT
$52    : LEAVE

DEFINE_FUNCTION "u64_from_int", $53, $C8F06D0, $2
$56    : ENTER -$6
$58    : LEA_LOCAL $6
$5A    : LOAD_INT
$5B    : STORE_LOCAL -$6, $44
$5E    : PUSH
$5F    : LEA_LOCAL $9
$61    : LOAD_LONG
$62    : POP_SEC
$63    : STORE $4
$65    : IMM $4
$67    : STORE_LOCAL -$1, $1
$6A    : LEA_LOCAL $9
$6C    : LOAD_LONG
$6D    : IMM_32_SEC $800000, $0
$70    : BZ $79, $C082000
$72    : IMM $FF
$74    : STORE_LOCAL -$2, $1
$77    : JMP $7E, $C082040
$79    : IMM $0
$7B    : STORE_LOCAL -$2, $1
$7E    : LEA_LOCAL $6
$80    : LOAD_INT
$81    : PUSH
$82    : LEA_LOCAL -$1
$84    : LOAD_CHAR
$85    : POP_SEC
$86    : ADD
$87    : PUSH
$88    : LEA_LOCAL -$2
$8A    : LOAD_CHAR
$8B    : POP_SEC
$8C    : STORE $1
$8E    : LEA_LOCAL -$1
$90    : LOAD_CHAR
$91    : INC
$92    : STORE_LOCAL -$1, $1
$95    : COMPARE_LT_CONST $8
$97    : BZ $7E, $C082080
$99    : LEA_LOCAL $6
$9B    : LOAD_INT
$9C    : LEAVE

DEFINE_FUNCTION "main", $9D, $C8F04F0, $0
$A0    : ENTER -$8
$A2    : LEA_LOCAL -$8
$A4    : PUSH_ARG
$A5    : PUSH_ARG_IMM_32 $4B0, $0
$A8    : CALL "u64_from_int", $C8F06D0
$AA    : ADJ $9
$AC    : LEA_LOCAL -$8
$AE    : PUSH_ARG
$AF    : LEA_LOCAL -$8
$B1    : PUSH_ARG
$B2    : CALL "u64_add", $C081EB0
$B4    : ADJ $6
$B6    : IMM $0
$B8    : LEAVE
$B9    : NOP
