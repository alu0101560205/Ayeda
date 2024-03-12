# Definir variables
CC = g++
CFLAGS = -Wall -std=c++11
LIB_DIR = lib
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Obtener todos los archivos .cc en el directorio src/
SRCS := $(wildcard $(SRC_DIR)/*.cc)

# Obtener todos los archivos .o en el directorio build/
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# Nombre del ejecutable
TARGET = $(BIN_DIR)/hashTable

# Regla para el objetivo predeterminado
all: $(TARGET)

# Regla de compilación para los archivos .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Regla de enlace para el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Regla para limpiar los archivos generados
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(BIN_DIR)

# Asegurarse de que los directorios necesarios existan
$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

.PHONY: all clean
