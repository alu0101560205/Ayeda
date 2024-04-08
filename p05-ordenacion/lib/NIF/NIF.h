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
#include <random>
#include <string>

class NIF {
  public:
    NIF() : value_(std::to_string(rand() % 100000000)) {} // Constructor por defecto que inicializa un dni aleatorio
    NIF(std::string val) : value_(val) {} // Constructor
    bool operator==(const NIF& other) const { return value_ == other.value_; }
    bool operator!=(const NIF& other) const { return !(*this == other); }
    operator long() const { return std::stoi(value_); }
    // Falta getOriginal -> 25418965D
    std::string getValue() const { return value_; }
    friend std::istream& operator>>(std::istream& input, NIF& nif) {
      std::string dni;
      input >> dni;
      nif.value_ = std::stoi(dni.substr(0, dni.size() - 1));
      return input;
    }
    std::string::const_iterator begin() const {return value_.begin(); }
    std::string::const_iterator end() const { return value_.end(); }
  private:
    std::string value_; // Representación numérica del DNI
};


#endif