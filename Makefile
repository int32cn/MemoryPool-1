# Makefile \
.PHONY: clean all

CC = gcc 
CFLAGS = -g -Wall
CFLAGS_OBJS = -g -Wall -c

INC = -I inc/

BUILD_DIR = build
SOURCES = sample/main.c src/MemoryPool.c
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/MemoryPool.o

TARGET = $(BUILD_DIR)/MemoryPool/

all: dir $(TARGET)

dir:
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	@echo "generate target"
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/main.o: sample/main.c
	@echo "generate Sample object"
	$(CC) $(CFLAGS_OBJS) $(INC) $< -o $@
$(BUILD_DIR)/MemoryPool.o: src/MemoryPool.c
	@echo "generate memory pool object"
	$(CC) $(CFLAGS_OBJS) $(INC) $< -o $@

clean:
	@echo "Cleaning"
	@rm -r $(BUILD_DIR)/*

