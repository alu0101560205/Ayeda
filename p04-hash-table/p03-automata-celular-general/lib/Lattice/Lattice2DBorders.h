/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice2DBorders.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 06 2024
  */

#ifndef LATTICE2DBORDERS_H
#define LATTICE2DBORDERS_H
#include "Lattice2D.h"

class Lattice2DReflective : public Lattice2D {
  public:
    Lattice2DReflective(int row, int col) : Lattice2D(row, col) {}
    Cell& getCell(Position*) const;
    void nextGeneration();
};

class Lattice2DNoBorder : public Lattice2D {
  Lattice2DNoBorder(int row, int col) : Lattice2D(row, col) {}
  Cell& getCell(Position*) const;
  void nextGeneration();
  void expandMatrix();
};

#endif