# bcc

Beck's C Compiler.
Designed based on "c4.c - C in four functions" by Robert Swierczek.

# Building

NOTE: currently only does anything on the PC build.

`make` build files for CE family calculators running TIOS

`make -f bos.makefile` build files for CE family calculators running BOS

`make -f pc.makefile` build files for PC (Windows/Linux/MacOS)

# Feature Set

Integer, string, and character literals including hexadecimal and common escape codes.

ANSI style functions, with additional syntax to assign an address to a function in the function prototype.

Operator precedence.

Constant folding.

