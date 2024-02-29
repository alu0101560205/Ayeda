/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file lattice.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#ifndef LATTICE_H
#define LATTICE_H
#include <iostream>
#include "cell.h"

enum class Border {
  Periodic,
  OpenCold,
  OpenHot
};

class Lattice {
  public:
    Lattice (int size_of_lattice, const Border& border_type = Border::Periodic); // Constructor
    ~Lattice(); // Destructor
    void defaultPositions();
    void InitialConfiguration();
    const Cell& getCell(const Position&) const;
    void nextGeneration();
    friend std::ostream& operator<<(std::ostream&, const Lattice&);
    int getSize() const;
    Border getBorder() const { return border_type_; }
    void setBorderType(Border border);
    void initFile(std::string file);
  private:
    Cell** cells_; // Vector de punteros a células
    int size_;
    Border border_type_;
};

#endif //LATTICE_H