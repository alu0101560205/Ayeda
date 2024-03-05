/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice1D.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef LATTICE1D_H
#define LATTICE1D_H
#include "Lattice.h"

class Lattice1D : public Lattice {
  public:
    Lattice1D (int size) : size_(size), cells_(new Cell*[size]) {}
    void nextGeneration();
    int Population() const;
    std::ostream& display(std::ostream&);
    virtual Cell& getCell (const PositionDim<1>& pos) = 0;
    Cell& operator[](const PositionDim<1>& pos) const;
    int getSize() const { return size_; }
  protected:
    int size_;
    Cell** cells_;
};

#endif // LATTICE1D_H