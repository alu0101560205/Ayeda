/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file LinearExploration.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef LINEAREXPLORATION_H
#define LINEAREXPLORATION_H
#include "ExplorationFunction.h"

/**
 * @brief Clase función de exploración lineal
*/
template <class Key>
class LinearExploration : public ExplorationFunction<Key> {
  public:
    unsigned operator()(Key& key, unsigned i) const override {
      return i;
    }
};

#endif