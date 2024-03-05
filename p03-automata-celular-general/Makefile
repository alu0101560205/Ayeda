# Definición de variables
CC = g++
CFLAGS = -std=c++11 -Wall
INCLUDE_DIRS = -I./lib/Cell -I./lib/Exception -I./lib/Factory -I./lib/Lattice -I./lib/Position
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin
EXECUTABLE = my_program_name

# Lista de archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc, $(OBJ_DIR)/%.o, $(SRCS))

# Regla de compilación
$(BIN_DIR)/$(EXECUTABLE): $(OBJS)
		@mkdir -p $(BIN_DIR)
		$(CC) $(CFLAGS) $(INCLUDE_DIRS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Limpiar archivos objeto y ejecutable
clean:
		@rm -rf $(OBJ_DIR) $(BIN_DIR)

# Ejecutar el programa
run: $(BIN_DIR)/$(EXECUTABLE)
		./$(BIN_DIR)/$(EXECUTABLE)
