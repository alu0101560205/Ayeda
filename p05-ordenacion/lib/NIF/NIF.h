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
    bool operator<(const NIF& other) const { return value_ < other.value_; }
    bool operator>(const NIF& other) const { return value_ > other.value_; }
    bool operator<=(const NIF& other) const { return value_ <= other.value_; }
    bool operator>=(const NIF& other) const { return value_ >= other.value_; }
    NIF& operator=(const int& value) {
      value_ = std::to_string(value);
      return *this;
    }
    size_t length() const { return value_.length(); }
    operator long() const { return std::stol(value_); }
    std::string getOriginal() const { return value_ + calculateLetter(value_); }
    std::string getValue() const { return value_; }
    friend std::istream& operator>>(std::istream& input, NIF& nif) {
      input >> nif.value_;
      return input;
    }
    std::string::const_iterator begin() const {return value_.begin(); }
    std::string::const_iterator end() const { return value_.end(); }
  private:
    std::string value_; // Representación numérica del DNI
    static char calculateLetter(const std::string& digits) {
      static const std::string letters = "TRWAGMYFPDXBNJZSQVHLCKE";
      int index = std::stol(digits) % letters.size();
      return letters[index];
    }
};


#endif