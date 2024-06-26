/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellLife.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef CELLLIFE_H
#define CELLLIFE_H
#include "Cell.h"

class CellLife : public Cell {
  public:
    CellLife(const State& state, Position* position) : Cell(state, position) {}
    void nextState(Lattice& lattice);
  protected:
    void display(std::ostream&);
    int getNeighbors(Position* pos, Lattice& lattice);
};

#endif