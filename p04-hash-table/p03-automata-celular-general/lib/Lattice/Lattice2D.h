/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice2D.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 05 2024
  */

#ifndef LATTICE2D_H
#define LATTICE2D_H
#include "Lattice.h"
#include "Cell/CellLife.h"
#include "../Factory/FactoryCell.h"
#include <fstream>


class Lattice2D : public Lattice {
  public:
    Lattice2D (int row, int col);
    Lattice2D (const char* filename);
    virtual ~Lattice2D();
    virtual Cell& getCell(Position*) const = 0;
    virtual void nextGeneration();
    int Population();
    virtual std::ostream& Display(std::ostream&) = 0;
    virtual Cell& operator[](Position*) const = 0;
    int getRows() const { return rows_; }
    int getCols() const { return cols_; }
  protected:
    int rows_;
    int cols_;
    int neg_rows_;
    int neg_cols_;
    std::vector<std::vector<Cell*>> board_;
};

#endif // LATTICE2D_H