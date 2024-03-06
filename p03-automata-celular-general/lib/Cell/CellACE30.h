/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellACE.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */
#ifndef CELLACE30_H
#define CELLACE30_H
#include "CellACE.h"
#include "Position.h"

class CellACE30 : public CellACE {
  public:
    CellACE30 (const State& state, Position* position) : CellACE(state, position) {}
    virtual void nextState (const Lattice& lattice);
};

#endif