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

class CellACE : public Cell {
  public:
    virtual void nextState(const Lattice1D& latticce) override = 0;
    virtual std::ostream& display(std::ostream&) override = 0;
};

#endif // CELLACE_H