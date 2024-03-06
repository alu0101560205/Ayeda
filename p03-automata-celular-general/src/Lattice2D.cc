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

