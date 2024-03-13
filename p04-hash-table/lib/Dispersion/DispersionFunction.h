/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file DispersionFunction.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 09 2024
  */

#ifndef DISPERSIONFUNCTION_H
#define DISPERSIONFUNCTION_H
#include <iostream>
#include <cstdlib>

/**
 * @brief Clase base para implementar las funciones de dispersión
*/
template <class Key>
class DispersionFunction {
  public:
    DispersionFunction(unsigned int size) : tableSize_(size) {}
    virtual unsigned operator()(const Key& key) const = 0;
    ~DispersionFunction() {}
    unsigned getTableSize() const { return tableSize_; }
  protected:
    unsigned tableSize_;
};

#endif