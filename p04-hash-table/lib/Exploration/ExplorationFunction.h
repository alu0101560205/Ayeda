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
#include "../Dispersion/DispersionFunction.h"

/**
 * @brief Clase función de exploración
*/
template <class Key>
class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key&, unsigned i) const = 0; // i es el intento de exploración
    virtual ~ExplorationFunction() {}
};

#endif