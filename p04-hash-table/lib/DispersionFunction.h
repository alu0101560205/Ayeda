/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file DispersionFunction.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 09 2024
  */

#ifndef DISPERSIONFUNCTION_H
#define DISPERSIONFUNCTION_H
#include <iostream>
#include <cstdlib>

/**
 * @brief Clase base para implementar las funciones de dispersión
*/
template <typename Key>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Key& key) const = 0;
    ~DispersionFunction() {}
  protected:
    unsigned tableSize_;
};

/**
 * @brief Función módulo
*/
template <typename Key>
class ModuleDispersion : public DispersionFunction<Key> {
  public:
    ModuleDispersion(unsigned int size) : tableSize_(size) {}
    unsigned operator()(const Key& key) const override {
      return key % tableSize_;
    }
};

/**
 * @brief Función basada en la suma
*/
template <typename Key>
class SumDispersion : public DispersionFunction<Key> {
  public:
    SumDispersion(unsigned int size) : tableSize_(size) {}
    unsigned operator()(const Key& key) const override {
      unsigned sum{0};
      for (const auto& val : key) {
        sum += val;
      }
      return sum % tableSize_;
    }
};

/**
 * @brief Función pseudoaleatoria
*/
template <typename Key>
class PseudorandomDispersion : public DispersionFunction<Key> {
  public:
    PseudorandomDispersion(unsigned int size) tableSize_(size) {}
    unsigned operator()(const Key& key) const override {
      srand(key);
      return rand() % tableSize_;
    }
};

#endif