CC = gcc
CFLAGS += -Iinclude/$(TARGET) -Wall -Wextra -g

SRC_DIR = source
TEST_DIR = test
BUILD_DIR = build
TARGET ?= linked_list

SRC := $(shell find $(SRC_DIR)/$(TARGET) -name '*.c')
TEST := $(shell find $(TEST_DIR) -name 'test_$(TARGET).c')
OBJ := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC) $(TEST))

all: $(BUILD_DIR) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean