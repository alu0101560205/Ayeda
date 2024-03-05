/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file FactoryCellACE110.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef FACTORYCELLACE110_H
#define FACTORYCELLACE110_H
#include "FactoryCell.h"
#include "../Cell/CellACE110.h"

class FactoryCellACE110 : public FactoryCell {
  public:
    Cell* createCell(const State& state, Position* position) {
      return new CellACE110(state, position);
    }
};

#endif