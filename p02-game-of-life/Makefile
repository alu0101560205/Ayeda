# Directorios
SRC_DIR := src
LIB_DIR := lib
BUILD_DIR := build

# Compilador y flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall

# Archivos a compilar
SRCS := $(wildcard $(SRC_DIR)/*.cc)
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(wildcard $(LIB_DIR)/*.h)

# Nombre del ejecutable
TARGET := game

.PHONY: all clean

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR) $(TARGET)