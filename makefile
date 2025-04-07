# Compiler and flags
CC = gcc
CFLAGS = 

# Libraries
LIBS = -lSDL2 -lGL -lGLEW -lGLU

# Directories
SRC_DIR = src
OBJ_DIR = object
BIN = app

# Find all .c files in src/
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default rule
all: $(BIN)

# Create binary
$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIBS)

# Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Phony targets
.PHONY: all clean

