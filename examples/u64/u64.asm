
DEFINE_FUNCTION "u64_add", $0, $73F21AD0, $2
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
$4D    : BZ $F, $73F21B50
$4F    : LEA_LOCAL $6
$51    : LOAD_INT
$52    : LEAVE

DEFINE_FUNCTION "u64_from_int", $53, $74A306E0, $2
$56    : ENTER -$5
$58    : LEA_LOCAL $6
$5A    : LOAD_INT
$5B    : STORE_LOCAL -$5, $43
$5E    : PUSH
$5F    : LEA_LOCAL $9
$61    : LOAD_INT
$62    : POP_SEC
$63    : STORE $3
$65    : IMM $4
$67    : STORE_LOCAL -$1, $1
$6A    : LEA_LOCAL $9
$6C    : LOAD_INT
$6D    : COMPARE_GTEQ_CONST $800000
$6F    : BZ $78, $73F21B80
$71    : IMM $FF
$73    : STORE_LOCAL -$2, $1
$76    : JMP $7D, $73F21BB0
$78    : IMM $0
$7A    : STORE_LOCAL -$2, $1
$7D    : LEA_LOCAL $6
$7F    : LOAD_INT
$80    : PUSH
$81    : LEA_LOCAL -$1
$83    : LOAD_CHAR
$84    : POP_SEC
$85    : ADD
$86    : PUSH
$87    : LEA_LOCAL -$2
$89    : LOAD_CHAR
$8A    : POP_SEC
$8B    : STORE $1
$8D    : LEA_LOCAL -$1
$8F    : LOAD_CHAR
$90    : INC
$91    : STORE_LOCAL -$1, $1
$94    : COMPARE_LT_CONST $8
$96    : BZ $7D, $73F21BE0
$98    : LEA_LOCAL $6
$9A    : LOAD_INT
$9B    : LEAVE

DEFINE_FUNCTION "main", $9C, $74A30160, $0
$9F    : ENTER -$8
$A1    : PUSH_IMM $4B0
$A3    : LEA_LOCAL -$8
$A5    : PUSH
$A6    : CALL "u64_from_int", $74A306E0
$A8    : ADJ $6
$AA    : LEA_LOCAL -$8
$AC    : PUSH
$AD    : LEA_LOCAL -$8
$AF    : PUSH
$B0    : CALL "u64_add", $73F21AD0
$B2    : ADJ $6
$B4    : IMM $0
$B6    : LEAVE
$B7    : NOP
