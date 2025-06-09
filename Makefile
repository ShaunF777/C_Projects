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

# Clean target: removes all compiled executables
# This finds all .c files, strips the .c extension, and removes the corresponding executables
clean:
	rm -f $(patsubst %.c,%,$(wildcard *.c))

# Mark clean as a phony target (it doesn't create a file named "clean")
.PHONY: clean

# Usage:
#   make 01hello    - compiles 01hello.c into executable 01hello
#   make clean      - removes all compiled executables