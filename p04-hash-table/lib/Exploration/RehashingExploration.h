/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ReHashingExploration.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef REHASHINGEXPLORATION_H
#define REHASHINGEXPLORATION_H
#include "ExplorationFunction.h"
#include <random>

/**
 * @brief Clase función de redispersión
*/
template <class Key>
class RehashingExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(Key& key, unsigned i) const override {
      srand(key);
      for (unsigned j = 1; j < i; j++) {
        rand();
      }
      return rand();
    }
};

#endif