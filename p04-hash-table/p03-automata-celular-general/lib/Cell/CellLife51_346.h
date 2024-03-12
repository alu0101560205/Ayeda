/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellLife51_346.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef CELLLIFE51_346
#define CELLLIFE51_346
#include "CellLife.h"

class CellLife51_346 : public CellLife {
  CellLife51_346(const State& state, Position* position) : CellLife(state, position) {}
  void nextState(Lattice&);
};

#endif