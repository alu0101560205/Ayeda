/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellACE110.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#include "../lib/CellACE110.h"

/**
 * @brief Método para aplicar la función de transición
*/
int CellACE110::nextState(const Lattice& lattice) {
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