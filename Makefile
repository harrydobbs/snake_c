# Makefile for SDL2 project

# Compiler
CC := gcc

# Compiler Flags
CFLAGS := -Wall -Wextra -std=c99 `sdl2-config --cflags`

# Linker Flags
LDFLAGS := `sdl2-config --libs`

# Source Files
SRC := $(wildcard src/*.c)

# Executable name
EXEC := snake_c

# Build directory
BUILDDIR := build

# Default make target
all: $(BUILDDIR) $(BUILDDIR)/$(EXEC)

# Rule for creating the build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Rule for building the final executable
$(BUILDDIR)/$(EXEC): $(SRC) 
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)

# Clean rule
clean: 
	rm -rf $(BUILDDIR)

# Phony targets
.PHONY: all clean
