/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice1DBorders.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef LATTICE1DBORDERS_H
#define LATTICE1DBORDERS_H
#include "Lattice.h"
#include "Lattice1D.h"

class Lattice1D_Open : public Lattice1D {
  public:
    Lattice1D_Open(int size) : Lattice1D(size) {}
    Cell& getCell(const PositionDim<1>& pos) override {
      int index = pos[0];
      if (index < 0 || index >= getSize()) {
        return dead_cell_;
      } else {
        return *cells_[index];
      }
    }
  private:
    // Célula muerta para devolver en caso de que se acceda a posiciones fuera de los límites
    Cell dead_cell_{PositionDim<1>(0)};
};


class Lattice1D_Periodic : public Lattice1D {
  public:
    Lattice1D_Periodic(int size) : Lattice1D(size) {}
    Cell& getCell(const PositionDim<1>& pos) override {
      int index = pos[0] % getSize();
      if (index < 0) {
        index += getSize();
      }
      return *(cells_[index]);
    }
};

#endif // LATTICE1DBORDERS_H