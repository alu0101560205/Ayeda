/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file OpenHot.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 28 2024
  */

#ifndef OPENHOT_H
#define OPENHOT_H
#include "lattice.h"

class OpenHot : public Lattice {
  public:
    OpenHot (int row, int col, const Border& border);
    OpenHot (const char* filename, const Border& border);
    Cell& getCell(const Position& pos) override;
  private:
    int hot_value_ = 1;
    Cell* out_limits_hot_;
};

#endif // OPENHOT_H