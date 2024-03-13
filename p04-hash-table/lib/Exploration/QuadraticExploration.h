/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file QuadraticExploration.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef QUADRATICEXPLORATION_H
#define QUADRATICEXPLORATION_H
#include "ExplorationFunction.h"

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

#endif