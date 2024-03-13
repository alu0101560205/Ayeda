/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file HashTable.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "../Sequence/Sequence.h"
#include "../Sequence/StaticSequence.h"
#include "../Sequence/DynamicSequence.h"
#include "../Dispersion/DispersionFunction.h"
#include "../Exploration/ExplorationFunction.h"

template <class Key, class Container = StaticSequence<Key>>
class HashTable : public Sequence<Key> {
  public:
    HashTable<Key, StaticSequence<Key>>(unsigned sz, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe,unsigned bsz)
      : tableSize_(sz), fd_(fd), fe_(fe), blockSize_(bsz) {
        table_ = new Container[tableSize_];
      }
    HashTable<Key, DynamicSequence<Key>>(unsigned sz, DispersionFunction<Key>>& fd) : tableSize_(sz), fd_(fd) {
      table_ = new Container[tableSize_];
    }
  private:
    size_t tableSize_; 
    Container* table_;
    DispersionFunction<key>& fd_;
    ExplorationFunction<Key>& fe_;
    size_t blockSize_;
};

#endif