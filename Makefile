# Variables
CC = gcc
CFLAGS = -Wall -g  # Add -g for debugging, or -O2 for optimization

# Use wildcard to find all .c files
SRCS = $(wildcard *.c)

# Define the obj directory
OBJDIR = obj

# Automatically create object files list in the obj directory
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Name of the output binary
TARGET = my_program

# Default target to build the program
all: $(OBJDIR) $(TARGET)

# Rule to link the object files into the final binary
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Rule to create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Rule to compile .c files into .o files in the obj directory
$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove object files
clean:
	rm -f $(OBJS)

# fclean target to remove object files, the obj directory, and the binary
fclean: clean
	rm -rf $(OBJDIR) $(TARGET)

# re target to force rebuild the project (clean + build)
re: fclean all

