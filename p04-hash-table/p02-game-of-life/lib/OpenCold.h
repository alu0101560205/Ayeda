/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file OpenCold.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 28 2024
  */

#ifndef OPENCOLD_H
#define OPENCOLD_H
#include "lattice.h"

class OpenCold : public Lattice {
  public:
    OpenCold (int row, int col, const Border& border);
    OpenCold(const char* filename, const Border& border);
    Cell& getCell(const Position& pos) override;
  private:
    Cell* out_limits_cold_;
};

#endif // OPENCOLD_H