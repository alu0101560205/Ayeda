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

template <typename Key>
class DispersionFunction {
  public:
    virtual unsigned operator()(const Key&) const = 0;
};

template <typename Key>
class ModuleDispersion {
  public:
    ModuleDispersion(unsigned size) : tableSize(size) {}
    unsigned opera
  private:
    unsigned tableSize_;
};

#endif