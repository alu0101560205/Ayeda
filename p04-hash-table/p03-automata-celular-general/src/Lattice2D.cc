/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice2D.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 06 2024
  */

#include "../lib/Lattice/Lattice2D.h"

/**
 * @brief Constructor de la clase Lattice 2D
*/
Lattice2D::Lattice2D (int row, int col) {
  rows_ = row;
  cols_ = col;
  // Inicializamos el tablero con punteros nulos
  board_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    board_[i].resize(cols_);
  }
  // Creamos las células en memoria dinámica y las agregamos al tablero
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      PositionDim<2> pos(i, j); // Posición de la célula en el tablero
      State state = 0; // Estado inicial a muerta
      board_[i][j] = FactoryCell (pos, state); // Creamos la nueva célula y la agregamos al tablero
    }
  }
}

/**
 * @brief Constructor desde fichero
*/
Lattice2D::Lattice2D (const char* filename) {
  std::ifstream file(filename); // Abrimos el archivo
  if (!file.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo");
  }
  // Leemos las dimensiones del tablero
  int rows{0}, cols{0};
  file >> rows >> cols;
  if (rows <= 0 || cols <= 0) { // Si las dimensiones son inválidas
    throw std::runtime_error("Dimensiones del tablero no válidas");
  }
  // Redimensionamos el tablero con las dimensiones especificadas
  rows_ = rows;
  cols_ = cols;
  board_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    board_[i].resize(cols_);
  }
  // Leemos los estados de las células del archivo
  char cellState;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      file >> cellState;
      if (cellState == 'X') {
        board_[i][j] = new Cell({i, j}, 1); // Nueva célula viva en la posición (i,j)
      } else if (cellState == '.') {
        board_[i][j] = new Cell({i, j}, 0); // Nueva cálula muerta en la posición (i,j)
      }
    }
  }
  file.close(); // Cerramos el archivo
}

/**
 * @brief Destructor de la clase Lattice
*/
Lattice2D::~Lattice2D() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      delete board_[i][j];
    }
  }
}

/**
 * @brief Método para calcular la población en el retículo
*/
int Lattice2D::Population() {
  int population{0}; // Inicializamos la población a cero
  // Iteramos sobre las células del tablero
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      PositionDim<2> pos(i, j);
      if (getCell(&pos).getState() == 1) { // Verificamos si la célula está viva
        population++; // Incrementamos población
      }
    }
  }
  return population; // Devolvemos el número total de células vivas
}

