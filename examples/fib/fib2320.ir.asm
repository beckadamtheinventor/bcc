$0     : LEAVE

DEFINE_FUNCTION "fib", $1, $9E351930, $1
$4     : ENTER -$6
$6     : IMM_32 $1, $0
$9     : STORE_LOCAL -$4, $4
$C     : STORE_LOCAL -$2, $4
$F     : LEA_LOCAL $4
$11    : LOAD_LONG
$12    : COMPARE_LT_CONST $2
$14    : BNZ $1A, $9E351C00
$16    : LEA_LOCAL -$2
$18    : LOAD_LONG
$19    : LEAVE
$1A    : LEA_LOCAL $4
$1C    : LOAD_LONG
$1D    : DEC
$1E    : STORE_LOCAL $4, $4
$21    : BNZ $3D, $9E351CE0
$23    : LEA_LOCAL -$2
$25    : LOAD_LONG
$26    : STORE_LOCAL -$6, $4
$29    : LEA_LOCAL -$2
$2B    : LOAD_LONG
$2C    : PUSH_32
$2D    : LEA_LOCAL -$4
$2F    : LOAD_LONG
$30    : POP_32
$31    : ADD
$32    : STORE_LOCAL -$2, $4
$35    : LEA_LOCAL -$6
$37    : LOAD_LONG
$38    : STORE_LOCAL -$4, $4
$3B    : JMP $1A, $9E351C70
$3D    : LEA_LOCAL -$2
$3F    : LOAD_LONG
$40    : LEAVE

DEFINE_FUNCTION "main", $41, $9E351A00, $0
$44    : ENTER -$3
$46    : IMM $0
$48    : STORE_LOCAL -$1, $1
$4B    : IMM_32 $1, $0
$4E    : STORE_LOCAL -$3, $4
$51    : LEA_LOCAL -$1
$53    : LOAD_CHAR
$54    : COMPARE_NEQ_CONST $9
$56    : BNZ $D2, $9E3E90E0
$58    : CALL "_cleartty", $9E350AB0
$5A    : ADJ $0
$5C    : IMM_PROG_OFFSET $D7, $9E351D90
$5E    : PUSH_ARG
$5F    : PUSH_ARG_IMM $7FFF
$61    : CALL "_print", $9E350B70
$63    : ADJ $2
$65    : LEA_LOCAL -$3
$67    : LOAD_LONG
$68    : PUSH_ARG_32
$69    : CALL "_printuint", $9E350F30
$6B    : ADJ $2
$6D    : IMM_PROG_OFFSET $D4, $9E351E40
$6F    : PUSH_ARG
$70    : CALL "_printline", $9E350DB0
$72    : ADJ $1
$74    : LEA_LOCAL -$3
$76    : LOAD_LONG
$77    : PUSH_ARG_32
$78    : CALL "fib", $9E351930
$7A    : ADJ $2
$7C    : PUSH_ARG_32
$7D    : CALL "_printuint", $9E350F30
$7F    : ADJ $2
$81    : CALL "_waitkeycycle", $9E3513B0
$83    : ADJ $0
$85    : STORE_LOCAL -$1, $1
$88    : LEA_LOCAL -$1
$8A    : LOAD_CHAR
$8B    : COMPARE_EQ_CONST $4
$8D    : BNZ $98, $9E351EB0
$8F    : LEA_LOCAL -$3
$91    : LOAD_LONG
$92    : INC
$93    : STORE_LOCAL -$3, $4
$96    : JMP $D0, $9E3E9000
$98    : LEA_LOCAL -$1
$9A    : LOAD_CHAR
$9B    : COMPARE_EQ_CONST $1
$9D    : PUSH
$9E    : LEA_LOCAL -$3
$A0    : LOAD_LONG
$A1    : COMPARE_GT_CONST $1
$A3    : POP_SEC
$A4    : LAND
$A5    : BNZ $B0, $9E351F20
$A7    : LEA_LOCAL -$3
$A9    : LOAD_LONG
$AA    : DEC
$AB    : STORE_LOCAL -$3, $4
$AE    : JMP $D0, $9E3E8F90
$B0    : LEA_LOCAL -$1
$B2    : LOAD_CHAR
$B3    : COMPARE_EQ_CONST $3
$B5    : BNZ $C1, $9E3E8E40
$B7    : LEA_LOCAL -$3
$B9    : LOAD_LONG
$BA    : ADD_CONST $10
$BC    : STORE_LOCAL -$3, $4
$BF    : JMP $D0, $9E3E8F20
$C1    : LEA_LOCAL -$1
$C3    : LOAD_CHAR
$C4    : COMPARE_EQ_CONST $2
$C6    : BNZ $D0, $9E3E8EB0
$C8    : LEA_LOCAL -$3
$CA    : LOAD_LONG
$CB    : SUB_CONST $10
$CD    : STORE_LOCAL -$3, $4
$D0    : JMP $51, $9E3E9070
$D2    : LEAVE
$D3    : NOP
db $3D, 0
db $66, $69, $62, $28, 0
db 0
