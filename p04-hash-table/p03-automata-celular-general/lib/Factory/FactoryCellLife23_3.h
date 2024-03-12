/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file FactoryCellLife23_3.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef FACTORYCELLLIFE23_3_H
#define FACTORYCELLLIFE23_3_H
#include "FactoryCell.h"
#include "../Cell/CellLife23_3.h"

class FactoryCellLife23_3 : public FactoryCell {
  public:
    Cell* createCell(const State& state, Position* position) {
      return new CellLife23_3(state, position);
    }
};

#endif