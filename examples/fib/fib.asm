
DEFINE_FUNCTION "0init", $0, $D70D1C90
$2     : ENTER $0
$4     : LEAVE

DEFINE_FUNCTION "fib", $5, $D7A703B0
$7     : ENTER -$C
$9     : IMM_32 $1, $0
$C     : STORE_LOCAL -$8, $4
$F     : STORE_LOCAL -$4, $4
$12    : LEA_LOCAL $6
$14    : LOAD_WORD
$15    : DEC
$16    : STORE_LOCAL $6, $2
$19    : LEA_LOCAL $6
$1B    : LOAD_WORD
$1C    : DEC
$1D    : STORE_LOCAL $6, $2
$20    : BNZ $3C, $D7A706A0
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
$3A    : JMP $19, $D7A70630
$3C    : LEA_LOCAL -$4
$3E    : LOAD_LONG
$3F    : LEAVE

DEFINE_FUNCTION "main", $40, $D7A70430
$42    : ENTER $0
$44    : PUSH_ARG_IMM $14
$46    : CALL "fib", $D7A703B0
$48    : ADJ $3
$4A    : PUSH_ARG_IMM $1E
$4C    : CALL "fib", $D7A703B0
$4E    : ADJ $3
$50    : PUSH_ARG_IMM $28
$52    : CALL "fib", $D7A703B0
$54    : ADJ $3
$56    : PUSH_ARG_IMM $32
$58    : CALL "fib", $D7A703B0
$5A    : ADJ $3
$5C    : LEAVE
$5D    : NOP
