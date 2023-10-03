
DEFINE_FUNCTION "fib", $0, $E07413B0, $1
$3     : ENTER -$C
$5     : IMM_32 $1, $0
$8     : STORE_LOCAL -$8, $4
$B     : STORE_LOCAL -$4, $4
$E     : LEA_LOCAL $6
$10    : LOAD_WORD
$11    : DEC
$12    : STORE_LOCAL $6, $2
$15    : LEA_LOCAL $6
$17    : LOAD_WORD
$18    : DEC
$19    : STORE_LOCAL $6, $2
$1C    : BZ $38, $E07416F0
$1E    : LEA_LOCAL -$4
$20    : LOAD_LONG
$21    : STORE_LOCAL -$C, $4
$24    : LEA_LOCAL -$4
$26    : LOAD_LONG
$27    : PUSH_32
$28    : LEA_LOCAL -$8
$2A    : LOAD_LONG
$2B    : POP_32
$2C    : ADD
$2D    : STORE_LOCAL -$4, $4
$30    : LEA_LOCAL -$C
$32    : LOAD_LONG
$33    : STORE_LOCAL -$8, $4
$36    : JMP $15, $E0741680
$38    : LEA_LOCAL -$4
$3A    : LOAD_LONG
$3B    : LEAVE

DEFINE_FUNCTION "main", $3C, $E0741500, $0
$3F    : ENTER $0
$41    : CALL "_cleartty", $E07409F0
$43    : ADJ $0
$45    : IMM_PROG_OFFSET $BE, $E0741610
$47    : PUSH_ARG
$48    : CALL "_print", $E0740AB0
$4A    : ADJ $3
$4C    : PUSH_ARG_IMM $14
$4E    : CALL "fib", $E07413B0
$50    : ADJ $3
$52    : PUSH_ARG_32
$53    : CALL "_printuint", $E0740E70
$55    : ADJ $6
$57    : CALL "_newline", $E0740FF0
$59    : ADJ $0
$5B    : IMM_PROG_OFFSET $B5, $E07417A0
$5D    : PUSH_ARG
$5E    : CALL "_print", $E0740AB0
$60    : ADJ $3
$62    : PUSH_ARG_IMM $1E
$64    : CALL "fib", $E07413B0
$66    : ADJ $3
$68    : PUSH_ARG_32
$69    : CALL "_printuint", $E0740E70
$6B    : ADJ $6
$6D    : CALL "_newline", $E0740FF0
$6F    : ADJ $0
$71    : IMM_PROG_OFFSET $AC, $E0741850
$73    : PUSH_ARG
$74    : CALL "_print", $E0740AB0
$76    : ADJ $3
$78    : PUSH_ARG_IMM $28
$7A    : CALL "fib", $E07413B0
$7C    : ADJ $3
$7E    : PUSH_ARG_32
$7F    : CALL "_printuint", $E0740E70
$81    : ADJ $6
$83    : CALL "_newline", $E0740FF0
$85    : ADJ $0
$87    : IMM_PROG_OFFSET $A3, $E0741900
$89    : PUSH_ARG
$8A    : CALL "_print", $E0740AB0
$8C    : ADJ $3
$8E    : PUSH_ARG_IMM $32
$90    : CALL "fib", $E07413B0
$92    : ADJ $3
$94    : PUSH_ARG_32
$95    : CALL "_printuint", $E0740E70
$97    : ADJ $6
$99    : CALL "_newline", $E0740FF0
$9B    : ADJ $0
$9D    : CALL "_waitkeycycle", $E0741230
$9F    : ADJ $0
$A1    : LEAVE
$A2    : NOP
db $69, $62, $28, $35, $30, $29, $3D, 0
db $66, $69, $62, $28, $34, $30, $29, $3D, 0
db $66, $69, $62, $28, $33, $30, $29, $3D, 0
db $66, $69, $62, $28, $32, $30, $29, $3D, 0
db 0
