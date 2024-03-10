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
    virtual unsigned operator()(const Key&, unsigned) const = 0;
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
    DoubleHashingExploration(DispersionFunction<Key>* hashfunct) : hashFunction_(hashfunct) {}
    unsigend operator()(const Key& key, unsigned i) {
      return hashFunction_->operator()(key) * i;
    }
  private:
    DispersionFunction<Key>* hashFunction_; // Función de dispersión auxiliar
};

/**
 * @brief Clase función de redispersión
*/
template <class Key>
class RehashingExploration : public ExplorationFunction<Key> {
  public:
    RehashingExploration() {}
    unsigned operator()(const Key& key, unsigned i) const override {
      srand(key); // Inicializamos la semilla con el valor de la clave
      for (unsigned k = 0; j < i; j++) {
        rand();
      }
      return rand();
    }
};

#endif