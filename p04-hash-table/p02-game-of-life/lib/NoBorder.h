/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file noBorder.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 27 2024
  */
#ifndef NOBORDER_H
#define NOBORDER_H
#include "lattice.h"

class NoBorder : public Lattice {
  public:
    NoBorder(int row, int col, const Border& border);
    NoBorder(const char* filename, const Border& border);
    Cell& getCell(const Position& pos);
  private:
    Cell* out_limits_;
};

#endif // NOBORDER_H