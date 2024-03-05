/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Cell.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#include "../lib/Cell/Cell.h"

/**
 * @brief Constructor de la clase Cell
*/
Cell::Cell(const State& initial_state, Position* position) {
  state_ = initial_state;
  position_ = position;
}

/**
 * @brief Método para acceder a la vecindad
*/
int Cell::vecindad(Lattice& lattice, int second, int first) {
  int total_cells_alive{0};
  int i = first;
  int j = second;
  //std::cout << "Entré a vecindad\n";
  total_cells_alive += lattice.getCell({i - 1, j - 1}).getState(); // Esquina sup izq
  total_cells_alive += lattice.getCell({i - 1, j}).getState(); // Centro superior
  total_cells_alive += lattice.getCell({i - 1, j + 1}).getState(); // Esquina superior derecha
  total_cells_alive += lattice.getCell({i, j + 1}).getState(); // Centro derecha
  total_cells_alive += lattice.getCell({i + 1, j + 1}).getState(); // Esquina inferior derecha
  total_cells_alive += lattice.getCell({i + 1, j}).getState(); // Centro inferior
  total_cells_alive += lattice.getCell({i + 1, j - 1}).getState(); // Esquina inferior izquierda
  total_cells_alive += lattice.getCell({i, j - 1}).getState(); // Centro izquierda
  return total_cells_alive;
}

/**
 * @brief Sobrecarga del operador de salida
*/
std::ostream& operator<<(std::ostream& os , const Cell& cell) {
  os << (cell.getState() == 1 ? 'X' : '.');
  return os;
}