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
 * @brief Constructor de Cell
*/
Cell::Cell(const State& initial_state, Position* position) {
  state_ = initial_state;
  position_ = position;
}

/**
 * @brief Método para acceder a la vecindad y contar el número de
 * células vivas
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
 * @brief Método para aplicar la función de transición para obtener
 * el estado de la célula en la siguiente generación
*/
int Cell::nextState(Lattice& lattice) {
  int first = this->getPosition().first;
  int second = this->getPosition().second;
  //std::cout << "Entré a nextstste\n";
  int alive_cells = vecindad(lattice, second, first);
  if (getState() == 1) { // Si está viva
    if (alive_cells == 2 ||  alive_cells == 3) {
      next_state_ = 1;
    } else {
      next_state_ = 0;
    }
  } else if (getState() == 0) { // Si está muerta
    if (alive_cells == 3) {
      next_state_ = 1;
    } else {
      next_state_ = 0;
    }
  }
  return getState(); // Devolvemos el estado de la célula después de ser actualizado
}

/**
 * @brief Sobrecarga del operador de salida
*/
std::ostream& operator<<(std::ostream& os , const Cell& cell) {
  os << (cell.getState() == 1 ? 'X' : '.');
  return os;
}