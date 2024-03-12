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

#include "../lib/Cell/CellACE110.h"

void CellACE110::nextState (const Lattice& lattice) {
  PositionDim<1> current_pos = getPosition();
  State left_state = lattice.getState(current_pos[0] - 1);
  State right_state = lattice.getState(current_pos[0] + 1);
  // Aplicar la regla 30 para calcular el nuevo estado
  next_state_ = ((state_ + right_state) + (state_ * right_state) + (left_state * state_ * right_state)) % 2;
}