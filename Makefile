 # Set the compiler to gcc
CC = gcc

# Set the flags for the compiler; -lcs50 links the CS50 library
CFLAGS = -lcs50

# Pattern rule:
# This tells make how to build any target (the program name) from a .c file of the same name.
# For example, if you run 'make 01hello', make will look for 01hello.c and use this rule.
#
# $@ is a special variable that stands for the target name (e.g., 01hello)
# $< is a special variable that stands for the first prerequisite (e.g., 01hello.c)
#
# The command compiles the .c file and produces an executable with the same name as the .c file (but without the .c extension).
%: %.c
	$(CC) $< $(CFLAGS) -o $@

# Usage:
#   make 01hello
# This will compile 01hello.c into an executable named 01hello, linking with the CS50 library.