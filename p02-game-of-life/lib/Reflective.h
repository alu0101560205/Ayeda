/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Reflective.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 27 2024
  */

#ifndef REFLECTIVE_H
#define REFLECTIVE_H
#include "lattice.h"

class Reflective : public Lattice {
  public:
    Reflective(int row, int col, Border border) : Lattice(row, col, border) {} // Constructor que llama al constructor de Lattice
    Reflective(const char* filename, const Border& border) : Lattice(filename, border) {}
    Cell& getCell(const Position& pos) override;
};

#endif // REFLECTIVE_H