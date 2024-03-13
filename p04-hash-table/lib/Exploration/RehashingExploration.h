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