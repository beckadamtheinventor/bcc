
DEFINE_FUNCTION "fib", $0, $4EE51870, $1
$3     : ENTER -$C
$5     : IMM_32 $1, $0
$8     : STORE_LOCAL -$8, $4
$B     : STORE_LOCAL -$4, $4
$E     : LEA_LOCAL $2
$10    : LOAD_LONG
$11    : COMPARE_LT_CONST $2
$13    : BNZ $19, $4EE51B40
$15    : LEA_LOCAL -$4
$17    : LOAD_LONG
$18    : LEAVE
$19    : LEA_LOCAL $2
$1B    : LOAD_LONG
$1C    : DEC
$1D    : STORE_LOCAL $2, $4
$20    : BNZ $3C, $4EE51C20
$22    : LEA_LOCAL -$4
$24    : LOAD_LONG
$25    : STORE_LOCAL -$C, $4
$28    : LEA_LOCAL -$4
$2A    : LOAD_LONG
$2B    : PUSH_32
$2C    : LEA_LOCAL -$8
$2E    : LOAD_LONG
$2F    : POP_32
$30    : ADD
$31    : STORE_LOCAL -$4, $4
$34    : LEA_LOCAL -$C
$36    : LOAD_LONG
$37    : STORE_LOCAL -$8, $4
$3A    : JMP $19, $4EE51BB0
$3C    : LEA_LOCAL -$4
$3E    : LOAD_LONG
$3F    : LEAVE

DEFINE_FUNCTION "main", $40, $4EE51940, $0
$43    : ENTER -$5
$45    : IMM $0
$47    : STORE_LOCAL -$1, $1
$4A    : IMM_32 $1, $0
$4D    : STORE_LOCAL -$5, $4
$50    : LEA_LOCAL -$1
$52    : LOAD_CHAR
$53    : COMPARE_NEQ_CONST $9
$55    : BNZ $CF, $4EF99070
$57    : CALL "_cleartty", $4EE509F0
$59    : ADJ $0
$5B    : IMM_PROG_OFFSET $D4, $4EE51CD0
$5D    : PUSH_ARG
$5E    : PUSH_ARG_IMM $7FFF
$60    : CALL "_print", $4EE50AB0
$62    : ADJ $2
$64    : LEA_LOCAL -$5
$66    : LOAD_LONG
$67    : PUSH_ARG_32
$68    : CALL "_printuint", $4EE50E70
$6A    : ADJ $2
$6C    : IMM_PROG_OFFSET $D1, $4EE51D80
$6E    : PUSH_ARG
$6F    : CALL "_printline", $4EE50CF0
$71    : ADJ $1
$73    : LEA_LOCAL -$5
$75    : LOAD_LONG
$76    : PUSH_ARG_32
$77    : CALL "fib", $4EE51870
$79    : ADJ $2
$7B    : PUSH_ARG_32
$7C    : CALL "_printuint", $4EE50E70
$7E    : ADJ $2
$80    : CALL "_waitkeycycle", $4EE512F0
$82    : ADJ $0
$84    : STORE_LOCAL -$1, $1
$87    : LEA_LOCAL -$1
$89    : LOAD_CHAR
$8A    : COMPARE_EQ_CONST $4
$8C    : BNZ $97, $4EE51DF0
$8E    : LEA_LOCAL -$5
$90    : LOAD_LONG
$91    : INC
$92    : STORE_LOCAL -$5, $4
$95    : JMP $CD, $4EF98F90
$97    : LEA_LOCAL -$1
$99    : LOAD_CHAR
$9A    : COMPARE_EQ_CONST $1
$9C    : LEA_LOCAL -$5
$9E    : LOAD_LONG
$9F    : COMPARE_GT_CONST $1
$A1    : LAND
$A2    : BNZ $AD, $4EE51E60
$A4    : LEA_LOCAL -$5
$A6    : LOAD_LONG
$A7    : DEC
$A8    : STORE_LOCAL -$5, $4
$AB    : JMP $CD, $4EF98F20
$AD    : LEA_LOCAL -$1
$AF    : LOAD_CHAR
$B0    : COMPARE_EQ_CONST $3
$B2    : BNZ $BE, $4EE51ED0
$B4    : LEA_LOCAL -$5
$B6    : LOAD_LONG
$B7    : ADD_CONST $10
$B9    : STORE_LOCAL -$5, $4
$BC    : JMP $CD, $4EF98EB0
$BE    : LEA_LOCAL -$1
$C0    : LOAD_CHAR
$C1    : COMPARE_EQ_CONST $2
$C3    : BNZ $CD, $4EE51F40
$C5    : LEA_LOCAL -$5
$C7    : LOAD_LONG
$C8    : SUB_CONST $10
$CA    : STORE_LOCAL -$5, $4
$CD    : JMP $50, $4EF99000
$CF    : LEAVE
$D0    : NOP
db $3D, 0
db $66, $69, $62, $28, 0
db 0
