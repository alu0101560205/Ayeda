/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file FactoryCellACE30.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef FACTORYCELLACE30
#define FACTORYCELLACE30
#include "FactoryCell.h"
#include "../Cell/CellACE30.h"

class FactoryCellACE30 : public FactoryCell {
  public:
    Cell* createCell (const State& state, Position* position) const {
      return new CellACE30(state, position);
    }
};

#endif