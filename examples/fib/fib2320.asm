jp _main
_exit := 0
label _2125479547824
label _2125482759152
label _fib
push r12
ld r12,r2
addi r2,-12
ldi r30,1
str r30,r12,-8
str r30,r12,-4
ld r30l,r26l
dec r30a
str r30l,r12,6
label _2125479548544
ld r30l,r26l
dec r30a
str r30l,r12,6
jq z,_2125479548656
ild r30,r12,-4
str r30,r12,-12
ild r30,r12,-4
push r31
ild r30,r12,-8
pop r31
add r30a,r31a
str r30,r12,-4
ild r30,r12,-12
str r30,r12,-8
jq _2125479548544
label _2125479548656
ild r30,r12,-4
ld r2,r12
pop r12
ret
label _2125479548160
label _main
push r12
ld r12,r2
call _cleartty
ldi r30,s_2125479548432
ld r24,r30
call _print
ldi r24,20
call _fib
ld r24,r30
call _printuint
call _newline
ldi r30,s_2125479548832
ld r24,r30
call _print
ldi r24,30
call _fib
ld r24,r30
call _printuint
call _newline
ldi r30,s_2125479549008
ld r24,r30
call _print
ldi r24,40
call _fib
ld r24,r30
call _printuint
call _newline
ldi r30,s_2125479549184
ld r24,r30
call _print
ldi r24,50
call _fib
ld r24,r30
call _printuint
call _newline
call _waitkeycycle
ld r2,r12
pop r12
ret
label s_2125479549184
dw $66
dw $69
dw $62
dw $28
dw $35
dw $30
dw $29
dw $3D
dw $0
label s_2125479549008
dw $66
dw $69
dw $62
dw $28
dw $34
dw $30
dw $29
dw $3D
dw $0
label s_2125479548832
dw $66
dw $69
dw $62
dw $28
dw $33
dw $30
dw $29
dw $3D
dw $0
label s_2125479548432
dw $66
dw $69
dw $62
dw $28
dw $32
dw $30
dw $29
dw $3D
dw $0