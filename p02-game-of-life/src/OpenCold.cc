/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file OpenCold.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 28 2024
  */

#include "../lib/OpenCold.h"

/**
 * @brief Constructor de la clase OpenCold
*/
OpenCold::OpenCold (int row, int col, const Border& border) : Lattice(row, col, border) {
  out_limits_cold_ = new Cell({-1, -1}, 0);
}

/**
 * @brief Constructor de la clase OpenCold desde fichero
*/
OpenCold::OpenCold(const char* filename, const Border& border) : Lattice(filename, border) {
  out_limits_cold_ = new Cell({-1, -1}, 0);
}

/**
 * @brief Método GetCell de la clase OpenCold
*/
Cell& OpenCold::getCell(const Position& pos) {
  Position new_pos = pos;
  if (new_pos.first < 0 || new_pos.first >= rows_ || new_pos.second < 0 || new_pos.second >= rows_) {
    return *out_limits_cold_; 
  }
  return *board_[pos.first][pos.second];
}