/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Periodic.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#ifndef PERIODIC_H
#define PERIODIC_H

#include <iostream>
#include "lattice.h"

class Periodic : public Lattice {
  public:
    Periodic (int row, int col, const Border& border) : Lattice(row, col, border) {}
    Periodic (const char* filename, const Border& border) : Lattice (filename, border) {}
    Cell& getCell(const Position& pos) override;
};

#endif // PERIODIC_H