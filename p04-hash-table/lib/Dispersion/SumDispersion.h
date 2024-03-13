/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file SumDispersion.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef SUMDISPERSIONDISPERSION_H
#define SUMDISPERSIONDISPERSION_H
#include "DispersionFunction.h"

/**
 * @brief Función basada en la suma
*/
template <class Key>
class SumDispersion : public DispersionFunction<Key> {
  public:
    SumDispersion(unsigned int size) : DispersionFunction<Key>(size) {}
    unsigned operator()(const Key& key) const override {
      unsigned sum{0};
      for (const auto& val : key) {
        sum += val;
      }
      return sum % this->getTableSize();
    }
};

#endif