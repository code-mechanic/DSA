# Target data structure for problem solving
TARGET ?= queue

# Supported data structures
DATA_STRUCTURES += linked_list
DATA_STRUCTURES += stack
DATA_STRUCTURES += queue

# Directories
SRC_DIR := source
INC_DIR := include
TEST_DIR := test
BUILD_DIR := build
LIB_DIR := $(BUILD_DIR)/lib
BIN_DIR := $(BUILD_DIR)/bin

# Compiler and flags
CC := gcc
INC_FLAGS := $(addprefix -I$(INC_DIR)/, $(DATA_STRUCTURES))
CFLAGS := $(INC_FLAGS) -Wall -Wextra -std=c11
AR := ar
ARFLAGS := rcs

# Output library
LIB_NAME := libdatastructures.a
LIB_PATH := $(LIB_DIR)/$(LIB_NAME)

# Library source files
LIB_SRC_FILES := $(shell find $(SRC_DIR) -name '*.c' ! -path '$(SRC_DIR)/**/problems/*')
LIB_OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(LIB_SRC_FILES))

# Test source files and executables
TEST_SRC_FILES := $(wildcard $(TEST_DIR)/*.c)
TEST_BIN_FILES := $(patsubst $(TEST_DIR)/%.c, $(BIN_DIR)/%, $(TEST_SRC_FILES))

# Problems source files and executables
PROBLEM_SRC_FILES := $(shell find $(addsuffix /problems, $(addprefix $(SRC_DIR)/, $(TARGET))) -name '*.c')
PROBLEM_BIN_FILES := $(patsubst $(SRC_DIR)/$(TARGET)/problems/%.c, $(BIN_DIR)/%, $(PROBLEM_SRC_FILES))

# Default target
all: $(LIB_PATH) test problems

test: $(TEST_BIN_FILES)

problems: $(PROBLEM_BIN_FILES)

var_check:
	@echo $(LIB_OBJ_FILES)

# Create build dirs if not exist
$(shell mkdir -p $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR))

# Rule to create static library
$(LIB_PATH): $(LIB_OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

# Rule to build object files for static library
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile test files and link with static lib
$(BIN_DIR)/%: $(TEST_DIR)/%.c $(LIB_PATH)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -ldatastructures -o $@

# Rule to compile problem files and link with static lib
$(BIN_DIR)/%: $(SRC_DIR)/$(TARGET)/problems/%.c $(LIB_PATH)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -ldatastructures -o $@

# Clean target
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
