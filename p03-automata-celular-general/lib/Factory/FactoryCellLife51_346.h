/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file FactoryCellLife51_346.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef FACTORYCELLLIFE51_346_H
#define FACTORYCELLLIFE_51_346_H
#include "FactoryCell.h"
#include "../Cell/CellLife51_346.h"

class FactoryCellLife51_346 : public FactoryCell {
  Cell* createCell(const State& state, Position* position) {
    return new CellLife51_346(state, position);
  }
};

#endif