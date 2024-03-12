/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellLife23_3.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef CELLLIFE23_3
#define CELLLIFE23_3
#include "CellLife.h"

class CellLife23_3 : public CellLife {
  CellLife23_3(const State& state, Position* position) : CellLife(state, position) {}
  void nextState(Lattice&);
};

#endif