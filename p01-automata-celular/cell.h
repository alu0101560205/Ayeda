/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file cell.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>

typedef int Position;
typedef unsigned char State;

class Lattice; // incluimos la clase Lattice

class Cell {
  public:
    Cell(const Position& position, const State& initial_state = 0) : position_(position), state_(initial_state) {} // Constructor
    State getState() const;
    Position getPosition() const;
    void setState(State);
    void setPosition(Position);
    int nextState(const Lattice&) const;
    friend std::ostream& operator<<(std::ostream&, const Cell&);
    
  private:
    State state_; // Estado de la célula
    Position position_; // Posición en el retículo
};

#endif //CELL_H