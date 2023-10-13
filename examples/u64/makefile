
NAME ?= u64

ifeq ($(OS),Windows_NT)
NATIVEPATH = $(subst /,\,$1)
BCCDIR := ..\\..\\

else
NATIVEPATH = $(subst \,/,$1)
BCCDIR := ../../

endif

all: $(NAME).c
	$(BCCDIR)bcc $(NAME).c -a $(NAME).asm -o $(NAME).bin

var: all
	convbin -i $(NAME).bin -o $(NAME).8xp -j bin -k 8xp -n DEMO

srcvar:
	convbin -i $(NAME).c -o DEMOSRC.8xv -j bin -k 8xv -n DEMOSRC
