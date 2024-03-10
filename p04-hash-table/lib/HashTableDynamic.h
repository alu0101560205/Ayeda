/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file HastableDynamic.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef HASHTABLEDYNAMIC_H
#define HASHTABLEDYNAMIC_H
#include <iostream>
#include "Sequence.h"
#include "ExplorationFunction.h"
#include "DispersionFunction.h"

template <class Key, DynamicSequence<Key>>
class HashTable : public Sequence<Key> {
  public:
    HashTable(unsigned size, DispersionFunction<Key>& fd) : tableSize_(size) {
      table_ = new DynamicSequence<Key>[tableSize_];
    }
    ~HashTable() { delete [] table_; }
  private:
    size_t tableSize_;
    DynamicSequence<Key>* table_;
};

#endif