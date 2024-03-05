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

class Lattice2D : public Lattice {
  public:
    Lattice2D (int row, int col) : Lattice(), rows_(row), cols_(col) {
      initializeBoard();
    }
  protected:
    int rows_;
    int cols_;
    std::vector<std::vector<Cell*>> board_;
    Cell dead_cell_;

    void initializeBoard() {
    // Inicializar el tablero con células muertas
      for (int i = 0; i < rows_; ++i) {
        std::vector<Cell*> row;
        for (int j = 0; j < cols_; ++j) {
          row.push_back(new Cell(/* argumentos del constructor de Cell */));
        }
        board_.push_back(row);
      }
    }
};

#endif // LATTICE2D_H