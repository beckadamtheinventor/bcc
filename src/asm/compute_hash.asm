
assume adl=1
section .text

public _compute_hash

_compute_hash:
	ld iy,0
	add iy,sp
	ld bc,(iy+6)
	ld iy,(iy+3)
	xor a,a
	sbc hl,hl
.loop:
	xor a,(iy)
	ld l,a
	jr nc,.nocarryonbyte0
	inc h
.nocarryonbyte0:
	inc iy
	cpd
	ret po
	ld d,h
	ld e,l
	add hl,hl ; x*2
	add hl,hl ; x*4
	add hl,hl ; x*8
	add hl,hl ; x*16
	add hl,de ; x*16 + x*1 -> x*17
	ld a,l
	jr .loop
