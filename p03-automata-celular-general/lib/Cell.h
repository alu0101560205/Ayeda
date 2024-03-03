/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Cell.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include "Position.h"
typedef unsigned char State;

class Lattice; // incluimos la clase Lattice

class Cell {
  public:
    Cell(const Position& position, const State& initial_state = 0) : state_(initial_state), next_state_(0), position_(position) {} // Constructor
    State getState() const { return state_; }
    void setState(const State& new_state) {state_ = new_state; }
    virtual void nextState(const Lattice&) = 0;
    virtual std::ostream& display(std::ostream&) = 0;
    Position getPosition() const { return position_; }
    // void setPosition(const Position& pos) { position_ = pos;}
    void updateState() { state_ = next_state_; }
    int nextState(Lattice& lattice);
    int vecindad(Lattice& lattice, int second, int first);
    friend std::ostream& operator<<(std::ostream&, const Cell&);
  protected:
    State state_; // Estado de la célula
    State next_state_;
    PositionDim<2> position_; // Posición en el retículo
};

#endif //CELL_H