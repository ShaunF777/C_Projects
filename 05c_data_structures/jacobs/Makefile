# Define the compiler
CC = gcc

# Define the flags for the compiler 
CFLAGS = -Wall -Werror -std=c11 # removed -Wextra

# Define the target executable
TARGET = $(EXE)

# Define the source files
SRCS = $(wildcard *.c)                # List all .c source files in the folder 

# Define the object files
OBJS = $(SRCS:.c=.o)

# Define the libraries to link against
LIBS = -lcs50

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# In this makefile
#- *CC* specifies the compiler.
#- *CFLAGS* includes compiler flags for warnings and standards.
#- *TARGET* is the name of the executable.
#- *SRCS* lists the source files.
#- *OBJS* converts source files to object files.
#- *LIBS* includes the CS50 library.
#- *all* is the default target to build the executable.
#- *clean* removes build files.