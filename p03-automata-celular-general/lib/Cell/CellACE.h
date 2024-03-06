/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellACE.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef CELLACE_H
#define CELLACE_H

#include <iostream>
#include "Cell.h"

struct Vecindad {
  State left;
  State right;
};

class CellACE : public Cell {
  public:
    CellACE(const State& state, Position* position) : Cell(state, position) {}
    virtual void nextState(const Lattice& latticce) = 0;
  protected:
    void display(std::ostream&);
    Vecindad getNeighbors(Position* pos, Lattice& lattice);
};

#endif // CELLACE_H