
DEFINE_FUNCTION "fib", $0, $1E327F40120, 1
ENTER -12
IMM_32 1, 0
STORE_LOCAL 0, 4
STORE_LOCAL 0, 4
LEA_LOCAL 6
LOAD_WORD
DEC
STORE_LOCAL 6, 2
LEA_LOCAL 6
LOAD_WORD
DEC
STORE_LOCAL 6, 2
BZ $38, $1E327F403B0
LEA_LOCAL 0
LOAD_LONG
STORE_LOCAL 0, 4
LEA_LOCAL 0
LOAD_LONG
PUSH_32
LEA_LOCAL 0
LOAD_LONG
POP_32
ADD
STORE_LOCAL 0, 4
LEA_LOCAL 0
LOAD_LONG
STORE_LOCAL 0, 4
JMP $15, $1E327F40350
LEA_LOCAL 0
LOAD_LONG
LEAVE

DEFINE_FUNCTION "main", $3C, $1E327F40200, 0
ENTER 0
PUSH_IMM 20
CALL "fib", $1E327F40120
EX_SEC_PRI
ADJ 3
EX_SEC_PRI
PUSH_IMM 30
CALL "fib", $1E327F40120
EX_SEC_PRI
ADJ 3
EX_SEC_PRI
PUSH_IMM 40
CALL "fib", $1E327F40120
EX_SEC_PRI
ADJ 3
EX_SEC_PRI
PUSH_IMM 50
CALL "fib", $1E327F40120
EX_SEC_PRI
ADJ 3
EX_SEC_PRI
LEAVE
NOP
