call _main
_exit := 0
label _1769728384688
label _1769728381520
label _u64_add
push r254
ld r254,r2
add r2,-3
ldi r9,0
ld r8,r254
add r8,-1
str r9,r8
ldi r9,0
ld r8,r254
add r8,-3
strw r9,r8
label _1769728384960
ld r9,r16
push r9
ld r9,r254
add r9,-1
ild r9,r9
pop r11
add r9,r11
push r9
ld r9,r254
add r9,-3
ildw r9,r9
push r9
ld r9,r16
push r9
ld r9,r254
add r9,-1
ild r9,r9
pop r11
add r9,r11
ild r9,r9
pop r11
add r9,r11
push r9
ld r9,r17
push r9
ld r9,r254
add r9,-1
ild r9,r9
pop r11
add r9,r11
ild r9,r9
pop r11
add r9,r11
ld r8,r254
add r8,-3
strw r9,r8
pop r11
ld r9,r254
add r9,-3
ildw r9,r9
shr r9,8
ld r8,r254
add r8,-3
strw r9,r8
ld r9,r254
add r9,-1
ild r9,r9
inc r9
ld r8,r254
add r8,-1
str r9,r8
cmp r9,8
ld r8,r1
and r8,1
jp z,_1769728384960
ld r9,r16
ld r2,r254
pop r254
ret
label _1769737225936
label _u64_from_int
push r254
ld r254,r2
add r2,-6
ld r9,r16
ldi r9, 0
cld z, r9, 1
ld r8,r254
add r8,-6
strw r9,r8
push r9
ld r9,r17
ld r10,r18
pop r11
ldi r9,4
ld r8,r254
add r8,-1
str r9,r8
ld r9,r17
ld r10,r18
ldi r11,0
ldi r12,128
jp z,_1769728385024
ldi r9,255
ld r8,r254
add r8,-2
str r9,r8
jp _1769728385088
label _1769728385024
ldi r9,0
ld r8,r254
add r8,-2
str r9,r8
label _1769728385152
label _1769728385088
ld r9,r16
push r9
ld r9,r254
add r9,-1
ild r9,r9
pop r11
add r9,r11
push r9
ld r9,r254
add r9,-2
ild r9,r9
pop r11
ld r9,r254
add r9,-1
ild r9,r9
inc r9
ld r8,r254
add r8,-1
str r9,r8
cmp r9,8
ld r8,r1
and r8,1
jp z,_1769728385152
ld r9,r16
ld r2,r254
pop r254
ret
label _1769737225456
label _main
push r254
ld r254,r2
add r2,-8
ld r9,r254
add r9,-8
ld r16,r9
ld r17,1200
ld r18,0
call _u64_from_int
add r2,9
ld r9,r254
add r9,-8
ld r16,r9
ld r9,r254
add r9,-8
ld r17,r9
call _u64_add
add r2,6
ldi r9,0
ld r2,r254
pop r254
ret