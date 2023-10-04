jp ._main
._exit := 0
label ._1565538261104
label ._1565540946928
label ._fib
push r12
ld r12,r2
addi r2,-12
ldi r30,1
str r30,r12,-8
str r30,r12,-4
ld r30,r24
cmpi r30,2
jq nc, ._1565538261824
ildr r30,r12,-4
ld r2,r12
pop r12
ret
ld r30,r24
dec r30
ld r24,r30
or r30,r30
jq z, ._1565538262048
ildr r30,r12,-4
str r30,r12,-12
ildr r30,r12,-4
push r30
ildr r30,r12,-8
pop r31
add r30,r31
str r30,r12,-4
ildr r30,r12,-12
str r30,r12,-8
jq ._1565538261936
ildr r30,r12,-4
ld r2,r12
pop r12
ret
label ._1565538261440
label ._main
push r12
ld r12,r2
addi r2,-5
ldi r30,0
str r30a,r12,-1
ldi r30,1
str r30,r12,-5
ildr r30a,r12,-1
cmpi r30a,9
jq z, ._1565540978976
call _cleartty
ldi r30,.s_1565538262352
ld r24,r30
ldi r25,32767
call _print
ildr r30,r12,-5
ld r24,r30
call _printuint
ldi r30,.s_1565538262528
ld r24,r30
call _printline
ildr r30,r12,-5
ld r24,r30
call ._fib
ld r24,r30
call _printuint
call _waitkeycycle
str r30a,r12,-1
ildr r30a,r12,-1
cmpi r30a,4
jq nz, ._1565538262640
ildr r30,r12,-5
inc r30
str r30,r12,-5
jq ._1565540978752
ildr r30a,r12,-1
cmpi r30a,1
ildr r30,r12,-5
cmpi r30,1
flagand -1
flagxor 1
ld r30,r1a
land r30a,r31a
or r30a,r30a
jq z, ._1565538262752
ildr r30,r12,-5
dec r30
str r30,r12,-5
jq ._1565540978640
ildr r30a,r12,-1
cmpi r30a,3
jq nz, ._1565538262864
ildr r30,r12,-5
addi r30,16
str r30,r12,-5
jq ._1565540978528
ildr r30a,r12,-1
cmpi r30a,2
jq nz, ._1565540978416
ildr r30,r12,-5
subi r30,16
str r30,r12,-5
jq ._1565540978864
ld r2,r12
pop r12
ret
dw $29
dw $3D
dw $0
dw $66
dw $69
dw $62
dw $28
dw $0
