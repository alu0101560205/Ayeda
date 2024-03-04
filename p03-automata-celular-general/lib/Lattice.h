/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef LATTICE_H
#define LATTICE_H
#include "Position.h"
#include "Cell.h"

class Lattice {
  public:
    ~Lattice() { }
    virtual Cell& getCell() (Position* pos) = 0;
    virtual void nextGeneration() = 0;
    virtual Cell& Lattice::operator[](Position*) const = 0;
    virtual int Lattice::Population() const = 0;
    virtual std::ostream& display(std::ostream&) = 0;
    friend std::ostream & operator<<(std::ostream& os, Lattice& lattice) {
      lattice.display(os);
      return os;
    }
};

#endif // LATTICE_H