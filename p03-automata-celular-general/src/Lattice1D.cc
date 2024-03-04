/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice1D.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#include "../lib/Lattice1D.h"
#include "../lib/Cell.h"

/**
 * @brief Método para que el autómata evolucione
*/
void Lattice1D::nextGeneration() {
  Cell** next_state_lattice = new Cell*[size_];
  for (int i = 0; i < size_; i++) {
    next_state_lattice[i] = new Cell(*cells_[i]);
    next_state_lattice[i]->setState(cells_[i]->nextState(*this));
  }
  for (int i = 0; i < size_; i++) {
    cells_[i]->setState(next_state_lattice[i]->getState());
  }
  for (int i = 0; i < size_; i++) {
    delete next_state_lattice[i];
  }
  delete next_state_lattice;
}

/**
 * @brief Método para contabilizar la población en el vector
*/
int Lattice1D::Population() const {
  int alive_cells{0};
  for (int i = 0; i < getSize(); i++) {
    cells_[i]->getState() == 1 ? alive_cells++ : 0;
  }
  return alive_cells;
}

/**
 * @brief Método para visualizar el retículo en pantalla
*/
std::ostream& Lattice1D::display(std::ostream& os) {
  for (int i = 0; i < getSize(); i++) {
    os << (cells_[i]->getState() == 1 ? 'X' : '.');
  }
  return os;
}

/**
 * @brief Método para devolver la célula en una posición dada
*/
Cell& Lattice1D::getCell() (Position* pos) {
  return cells_[pos];
}

/**
 * @brief Sobrecarga del operador []
*/
Cell& Lattice1D::operator[](Position* pos) const {
  return cells_[pos];
}