/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file DoubleHashingExploration.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef DOUBLEHASHINGEXPLORATION_H
#define DOUBLEHASHINGEXPLORATION_H
#include "ExplorationFunction.h"

/**
 * @brief Clase función de doble dispersión
*/
template <class Key>
class DoubleHashingExploration : public ExplorationFunction<Key> {
  public:
    DoubleHashingExploration(const DispersionFunction<Key>& f) : f_(f) {}
    unsigned operator()(Key& key, unsigned i) const override {
      return (f_(key) * i);
    }
  private:
    DispersionFunction<Key> f_; // Función de dispersión auxiliar f(k)
};

#endif