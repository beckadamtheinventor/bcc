
DEFINE_FUNCTION "os_PutStrLine", $21D30, $21D30, $15DF3040310, 0

DEFINE_FUNCTION "testfunction", $3, $15DF3040350, 3
ENTER 0
LEA_LOCAL 12
LOAD_INT
PUSH
LEA_LOCAL 6
LOAD_INT
POP_SEC
MUL
PUSH
LEA_LOCAL 9
LOAD_INT
POP_SEC
ADD
LEAVE

DEFINE_FUNCTION "main", $18, $15DF3040AA0, 0
ENTER -12
IMM_PROG_OFFSET $50, $15DF3041000
STORE_LOCAL $FFFFFFFD, 8
PUSH
CALL "os_PutStrLine", $21D30, $15DF3040310
ADJ 3
IMM 123
STORE_LOCAL $FFFFFFFA, 3
IMM 43
STORE_LOCAL $FFFFFFF7, 3
IMM 100
STORE_LOCAL $FFFFFFF4, 3
LEA_LOCAL $FFFFFFFD
LOAD_INT
PUSH
LEA_LOCAL $FFFFFFFA
LOAD_INT
PUSH
LEA_LOCAL $FFFFFFF7
LOAD_INT
PUSH
LEA_LOCAL $FFFFFFF4
LOAD_INT
PUSH
CALL "testfunction", $15DF3040350
EX_SEC_PRI
ADJ 9
EX_SEC_PRI
POP_SEC
ADD
LEAVE
NOP
db $65, $6C, $6C, $6F, $20, $57, $6F, $72, $6C, $64, $21, 0
db 0
