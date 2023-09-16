
NAME ?= bcc
COMPRESSED ?= YES
ICON ?= bccx16.png
DESCRIPTION ?= "Beck's C Compiler"

CFLAGS ?= -Wall -Wextra -Oz -DBOS_BUILD
CXXFLAGS ?= -Wall -Wextra -Oz -DBOS_BUILD

include $(CEDEV)/bos/meta/makefile.mk
