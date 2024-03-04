/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file CellACE110.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef CELLACE110_H
#define CELLACE110_H
#include "CellACE.h"

class CellACE110 : public CellACE {
  public:
    int nextState(const Lattice& lattice);
};

#endif // CELLACE110_H