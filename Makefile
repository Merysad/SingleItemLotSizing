CC=g++
SRC_EXT=cc
BUILD_DIR=build
TARGET=bin/lsapp
SRC_DIR=src
SOURCES=$(shell find $(SRC_DIR) -type f -name '*.$(SRC_EXT)')
OBJECTS=$(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))
CFLAGS=-g -Wall -std=c++11

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $< $(CFLAGS)

clean:
	$(RM) -r $(BUILD_DIR) $(TARGET)