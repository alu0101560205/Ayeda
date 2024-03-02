/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Reflective.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 27 2024
  */

#include "../lib/Reflective.h"

/**
 * @brief Método para devolver la célula actual
*/
Cell& Reflective::getCell(const Position& pos) {
  Position new_pos = pos;
  int& row = new_pos.first;
  int& col = new_pos.second;
  if (row < 0) row++; // Si nos salimos por arriba
  if (row >= rows_) row--; // Si nos salimos por abajo
  if (col < 0) col++; // Si nos salimos por izquierda
  if (col >= cols_) col--; // Si nos salimos por derecha
  return *board_[row][col];
}