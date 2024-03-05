/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellACE30.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#include "../lib/Cell/CellACE30.h"

void CellACE30::nextState (const Lattice& lattice) {
  State left_state = lattice.getLeftNeighborState(getPosition());
  State right_state = lattice.getRightNeighborState(getPosition());
  // Aplicar la regla 30 para calcular el nuevo estado
  next_state_ = (left_state != right_state) ? 1 : 0;
}