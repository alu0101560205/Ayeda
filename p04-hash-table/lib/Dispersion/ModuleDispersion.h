/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ModuleDispersion.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef MODULEDISPERSION_H
#define MODULEDISPERSION_H
#include "DispersionFunction.h"

/**
 * @brief Función módulo
*/
template <class Key>
class ModuleDispersion : public DispersionFunction<Key> {
  public:
    ModuleDispersion(unsigned int size) : DispersionFunction<Key>(size) {}
    unsigned operator()(Key& key) const override {
      return (static_cast<long>(key) % this->getTableSize());
    }
};

#endif