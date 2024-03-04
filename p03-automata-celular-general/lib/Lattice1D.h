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
    void nextGeneration();
    int Population() const;
    std::ostream& display(std::ostream&);
    Cell& getCell() (Position* pos);
    Cell& operator[](Position* pos) const;
    int getSize() const { return size_; }
  private:
    int size_;
    Cell** cells_;
};

#endif // LATTICE1D_H