/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file cell.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#include "../lib/cell.h"
#include "../lib/lattice.h"

/**
 * @brief Método para acceder al estado de la célula
 * @return state_, estado de la célula
*/
State Cell::getState() const {
  return state_;
}

/**
 * @brief Método para acceder a la posición de la célula
*/
Position Cell::getPosition() const {
  return position_;
}

/**
 * @brief Método para establecer la configuración inicial
 * @param State, estado deseado
*/
void Cell::setState(const State& new_state) {
  state_ = new_state;
}

/**
 * @brief Método para establecer una posición inicial
*/
void Cell::setPosition(Position position) {
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