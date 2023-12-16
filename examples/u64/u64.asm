
DEFINE_FUNCTION "0init", $0, $534519B0
$2     : ENTER $0
$4     : LEAVE

DEFINE_FUNCTION "u64_add", $5, $53CD0360
$7     : ENTER -$7
$9     : IMM $0
$B     : STORE_LOCAL -$1, $1
$E     : IMM $0
$10    : STORE_LOCAL -$7, $3
$13    : LEA_LOCAL $6
$15    : LOAD_INT
$16    : PUSH
$17    : LEA_LOCAL -$1
$19    : LOAD_CHAR
$1A    : MUL_CONST $1
$1C    : POP_SEC
$1D    : ADD
$1E    : PUSH
$1F    : LEA_LOCAL -$7
$21    : LOAD_INT
$22    : PUSH
$23    : LEA_LOCAL $6
$25    : LOAD_INT
$26    : PUSH
$27    : LEA_LOCAL -$1
$29    : LOAD_CHAR
$2A    : MUL_CONST $1
$2C    : POP_SEC
$2D    : ADD
$2E    : LOAD_CHAR
$2F    : POP_SEC
$30    : ADD
$31    : PUSH
$32    : LEA_LOCAL $9
$34    : LOAD_INT
$35    : PUSH
$36    : LEA_LOCAL -$1
$38    : LOAD_CHAR
$39    : MUL_CONST $1
$3B    : POP_SEC
$3C    : ADD
$3D    : LOAD_CHAR
$3E    : POP_SEC
$3F    : ADD
$40    : STORE_LOCAL -$7, $3
$43    : POP_SEC
$44    : STORE $1
$46    : LEA_LOCAL -$7
$48    : LOAD_INT
$49    : SHR_CONST $8
$4B    : STORE_LOCAL -$7, $3
$4E    : LEA_LOCAL -$1
$50    : LOAD_CHAR
$51    : INC
$52    : STORE_LOCAL -$1, $1
$55    : COMPARE_LT_CONST $8
$57    : BZ $13, $53CD0860
$59    : LEA_LOCAL $6
$5B    : LOAD_INT
$5C    : LEAVE

DEFINE_FUNCTION "u64_from_int", $5D, $53CD0ED0
$5F    : ENTER -$5
$61    : LEA_LOCAL $6
$63    : LOAD_INT
$64    : STORE_LOCAL -$5, $44
$67    : PUSH
$68    : LEA_LOCAL $9
$6A    : LOAD_LONG
$6B    : POP_SEC
$6C    : STORE $4
$6E    : IMM $4
$70    : STORE_LOCAL -$1, $1
$73    : LEA_LOCAL $9
$75    : LOAD_LONG
$76    : IMM_32_SEC $80000000, $80
$79    : COMPARE_GTEQ
$7A    : BNZ $83, $53CD0A40
$7C    : IMM $FF
$7E    : STORE_LOCAL -$2, $1
$81    : JMP $88, $53CD03B0
$83    : IMM $0
$85    : STORE_LOCAL -$2, $1
$88    : LEA_LOCAL $6
$8A    : LOAD_INT
$8B    : PUSH
$8C    : LEA_LOCAL -$1
$8E    : LOAD_CHAR
$8F    : MUL_CONST $1
$91    : POP_SEC
$92    : ADD
$93    : PUSH
$94    : LEA_LOCAL -$2
$96    : LOAD_CHAR
$97    : POP_SEC
$98    : STORE $1
$9A    : LEA_LOCAL -$1
$9C    : LOAD_CHAR
$9D    : INC
$9E    : STORE_LOCAL -$1, $1
$A1    : COMPARE_LT_CONST $8
$A3    : BZ $88, $53CD0590
$A5    : LEA_LOCAL $6
$A7    : LOAD_INT
$A8    : LEAVE

DEFINE_FUNCTION "main", $A9, $53CD0630
$AB    : ENTER -$8
$AD    : PUSH_ARG_IMM_32 $4B0, $0
$B0    : LEA_LOCAL -$8
$B2    : PUSH_ARG
$B3    : CALL "u64_from_int", $53CD0ED0
$B5    : ADJ $9
$B7    : LEA_LOCAL -$8
$B9    : PUSH_ARG
$BA    : LEA_LOCAL -$8
$BC    : PUSH_ARG
$BD    : CALL "u64_add", $53CD0360
$BF    : ADJ $6
$C1    : IMM $0
$C3    : LEAVE
$C4    : NOP
