/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ExplorationFunction.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef EXPLORATIONFUNCTION_H
#define EXPLORATIONFUNCTION_H
#include <iostream>
#include <cstdlib>
#include "DispersionFunction.h"

/**
 * @brief Clase función de exploración
*/
template <class Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key&, unsigned i) const = 0; // i es el intento de exploración
    virtual ~ExplorationFunction() {}
};

/**
 * @brief Clase función de exploración lineal
*/
template <class Key>
class LinearExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& key, unsigned i) const override {
      return i;
    }
};

/**
 * @brief Clase función de exploración cuadrática
*/
template <class Key> 
class QuadraticExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(const Key& key, unsigned i) const override {
      return (i * i);
    }
};

/**
 * @brief Clase función de doble dispersión
*/
template <class Key>
class DoubleHashingExploration : public ExplorationFunction<Key> {
  public:
    DoubleHashingExploration(const DispersionFunction<Key>& f) : f_(f) {}
    unsigned operator()(const Key& key, unsigned i) const override {
      return (f_(key) * i);
    }
  private:
    DispersionFunction<Key> f_; // Función de dispersión auxiliar f(k)
};

/**
 * @brief Clase función de redispersión
*/
template <class Key>
class RehashingExploration : public ExplorationFunction<Key> {
  public:
    RehashingExploration(const DispersionFunction<Key>& f) : f_(f) {}
    unsigned operator()(const Key& key, unsigned i) const override {
      unsigned hashValue = f_(key);
      for (unsigned count = 0; count < i; count++) {
        hashValue = f_(hashValue);
      }
      return hashValue;
    }
  private:
    const DispersionFunction<Key>& f_; // Función de dispersión auxiliar f(k)
};

#endif