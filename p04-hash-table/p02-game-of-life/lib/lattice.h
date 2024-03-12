/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file lattice.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "cell.h"

enum Border {
  noBorder,
  reflective,
  openCold,
  openHot,
  periodic
};

class Lattice {
  public:
    Lattice(int row, int col, const Border& border); // Constructor
    Lattice(const char* filename, const Border& border); // Constructor desde fichero
    ~Lattice();
    void nextGeneration(); // Método para que el autómata evolucione
    std::size_t Population() const; // Contador de células vivas en el tablero
    Cell& operator[](const Position& pos); // Sobrecarga del operador []
    void expandMatrix(); // Expandir matrix
    virtual Cell& getCell(const Position& pos) = 0; // Método virtual puro
    int getCols() const { return cols_; }
    int getRows() const { return rows_; }
    Border getBorder() const { return type_of_border_; }
    const Cell& operator[](const Position& pos) const {
      return *board_[pos.first][pos.second];
    }
    friend std::ostream& operator<<(std::ostream& os, const Lattice& lattice);
    void RellenarTablero();
  protected:
    int rows_; // Número de filas del tablero
    int cols_; // Número de columnas del tablero
    std::vector<std::vector<Cell*>> board_; // Tablero representado con una matriz de punteros a células
    int neg_rows_;
    int neg_cols_;
    Border type_of_border_;
};



#endif // LATTICE_H