/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file cell.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <utility> // Para std::pair

typedef std::pair<int,int> Position;
typedef unsigned char State;

class Lattice; // incluimos la clase Lattice

class Cell {
  public:
    Cell(const Position& position, const State& initial_state = 0) : state_(initial_state), next_state_(0), position_(position) {} // Constructor
    State getState() const;
    void setState(const State&);
    Position getPosition() const;
    void setPosition(Position);
    void updateState() { state_ = next_state_; }
    int nextState(Lattice& lattice);
    int vecindad(Lattice& lattice, int second, int first);
    friend std::ostream& operator<<(std::ostream&, const Cell&);
  private:
    State state_; // Estado de la célula
    State next_state_;
    Position position_; // Posición en el retículo
};

#endif //CELL_H