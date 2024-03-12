/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Periodic.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#include "../lib/Periodic.h"

Cell& Periodic::getCell(const Position& pos) {
  Position new_pos = pos;
  int& row = new_pos.first;
  int& col = new_pos.second;
  if (row < 0) row = getRows() - 1;
  if (col < 0) col = getCols() - 1;
  if (row >= rows_) row = 0;
  if (col >= cols_) col = 0;
  return *board_[row][col];
}