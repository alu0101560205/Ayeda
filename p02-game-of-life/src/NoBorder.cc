/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file noBorder.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 27 2024
  */

#include "../lib/NoBorder.h"

/**
 * @brief Constructor de la clase NoBorder
*/
NoBorder::NoBorder(int row, int col, const Border& border) : Lattice(row, col, border) {
  out_limits_ = new Cell (std::pair<int, int>(-1, -1), 0);
}

/**
 * @brief Constructor desde fichero
*/
NoBorder::NoBorder(const char* filename, const Border& border) : Lattice(filename, border) {
  out_limits_ = new Cell (std::pair<int, int>(-1, -1), 0);
}

/**
 * @brief Método que devuelve la célula actual
*/
Cell& NoBorder::getCell(const Position& pos) {
  int first = pos.first;
  int second = pos.second;
  if (first < 0 || second < 0 || second >= getCols() || first >= getRows()) {
    return *out_limits_;
  }
  return *board_[first][second];
}