/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file PseudorandomDispersion.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef PSEUDORANDOMDISPERSION_H
#define PSEUDORANDOMDISPERSION_H
#include "DispersionFunction.h"
#include <random>

/**
 * @brief Función pseudoaleatoria
*/
template <class Key>
class PseudorandomDispersion : public DispersionFunction<Key> {
  public:
    PseudorandomDispersion(unsigned int size) : DispersionFunction<Key>(size) {}
    unsigned operator()(Key& key) const override {
      srand(key);
      return rand();
    }
};

#endif