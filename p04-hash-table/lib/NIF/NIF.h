/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file NIF.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef NIF_H
#define NIF_H
#include <iostream>
#include <cstdlib>

class NIF {
  public:
    NIF() : value_(rand() % 100000000) {} // Constructor por defecto que inicializa un dni aleatorio
    NIF(long int val) : value_(val) {} // Constructor
    bool operator==(const NIF& other) const { return value_ == other.value_; }
    bool operator!=(const NIF& other) const { return !(*this == other); }
    operator long() const { return value_; }
    // Falta getOriginal -> 25418965D
  private:
    int value_; // Representación numérica del DNI
};

#endif