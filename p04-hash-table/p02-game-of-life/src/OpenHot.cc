/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file OpenHot.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 28 2024
  */

#include "../lib/OpenHot.h"

/**
 * @brief Constructor de la clase OpenHot
*/
OpenHot::OpenHot (int row, int col, const Border& border) : Lattice(row, col, border) {
  out_limits_hot_ = new Cell ({-1, -1}, hot_value_);
}

/**
 * Construcción de la clase OpenHot desde fichero
*/
OpenHot::OpenHot (const char* filename, const Border& border) : Lattice(filename, border) {
  out_limits_hot_ = new Cell ({-1, -1}, hot_value_);
}

/**
 * @brief Método GetCell de la clase OpenHot;
*/
Cell& OpenHot::getCell(const Position& pos) {
  if (pos.first < 0 || pos.first >= getRows() || pos.second < 0 || pos.second >= getCols()) {
    return *out_limits_hot_;
  }
  return *board_[pos.first][pos.second];
}