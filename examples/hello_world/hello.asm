
DEFINE_FUNCTION "0init", $0, $776998
$2     : ENTER $0
$4     : LEAVE

DEFINE_FUNCTION "os_PutStrLine", $21D30, $21D30, $776D98

DEFINE_FUNCTION "os_NewLine", $207F0, $207F0, $7704B0

DEFINE_FUNCTION "testfunction", $9, $770518
$B     : ENTER $0
$D     : LEA_LOCAL $C
$F     : LOAD_INT
$10    : PUSH
$11    : LEA_LOCAL $6
$13    : LOAD_INT
$14    : POP_SEC
$15    : MUL
$16    : PUSH
$17    : LEA_LOCAL $9
$19    : LOAD_INT
$1A    : POP_SEC
$1B    : ADD
$1C    : LEAVE

DEFINE_FUNCTION "main", $1D, $77A198
$1F    : ENTER -$C
$21    : IMM_PROG_OFFSET $56, $779D30
$23    : STORE_LOCAL -$3, $41
$26    : PUSH_ARG
$27    : CALL "os_PutStrLine", $21D30, $776D98
$29    : ADJ $3
$2B    : CALL "os_NewLine", $207F0, $7704B0
$2D    : ADJ $0
$2F    : IMM $7B
$31    : STORE_LOCAL -$6, $3
$34    : IMM $2B
$36    : STORE_LOCAL -$9, $3
$39    : IMM $64
$3B    : STORE_LOCAL -$C, $3
$3E    : LEA_LOCAL -$3
$40    : LOAD_INT
$41    : PUSH
$42    : LEA_LOCAL -$C
$44    : LOAD_INT
$45    : PUSH_ARG
$46    : LEA_LOCAL -$9
$48    : LOAD_INT
$49    : PUSH_ARG
$4A    : LEA_LOCAL -$6
$4C    : LOAD_INT
$4D    : PUSH_ARG
$4E    : CALL "testfunction", $770518
$50    : ADJ $9
$52    : POP_SEC
$53    : ADD
$54    : LEAVE
$55    : PUSH_ARG
db $65, $6C, $6C, $6F, $20, $57, $6F, $72, $6C, $64, $21, 0
db 0
