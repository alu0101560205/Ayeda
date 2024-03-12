/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file FactoryCell.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef FACTORYCELL_H
#define FACTORYCELL_H
#include "Cell.h"

class FactoryCell {
  public:
    virtual Cell* createCell(Position* position, const State& state) const = 0;
};

#endif //FACTORYCELL_H