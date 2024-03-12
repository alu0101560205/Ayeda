/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file cell.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#include "cell.h"
#include "lattice.h"

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
void Cell::setState(State new_state) {
  state_ = new_state;
}

/**
 * @brief Método para establecer una posición inicial
*/
void Cell::setPosition(Position position) {
  position_ = position;
}

/**
 * @brief Método para aplicar la función de transición para obtener
 * el estado de la célula en la siguiente generación
*/
int Cell::nextState(const Lattice& lattice) const {
  int lattice_size = lattice.getSize();
  State left_state, right_state;
  switch (lattice.getBorder()) {
    case Border::OpenCold:
      left_state = (getPosition() == 0) ? 0 : lattice.getCell(getPosition() - 1).getState(); 
      right_state = (getPosition() == lattice.getSize() - 1) ? 0 : lattice.getCell(getPosition() + 1).getState();
      break;
    case Border::OpenHot:
      left_state = (getPosition() == 0) ? 1 : lattice.getCell(getPosition() - 1).getState(); 
      right_state = (getPosition() == lattice.getSize() - 1) ? 1 : lattice.getCell(getPosition() + 1).getState(); 
      break;
    case Border::Periodic:
      left_state = (getPosition() == 0) ? lattice.getCell(lattice_size - 1).getState() : lattice.getCell(getPosition() - 1).getState();
      right_state = (getPosition() == lattice_size - 1) ? lattice.getCell(0).getState() : lattice.getCell(getPosition() + 1).getState();
      break;
  }
  State nextState = (getState() + right_state + (getState() * right_state) + (left_state * getState() * right_state)) % 2;
  return nextState;
}

std::ostream& operator<<(std::ostream& os , const Cell& cell) {
  os << (cell.getState() == 1 ? 'X' : ' ');
  return os;
}