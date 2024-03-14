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
class HashTable : Sequence<Key>{
  public:
    HashTable(unsigned sz, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe,unsigned bsz)
      : tableSize_(sz), fd_(fd), fe_(fe), blockSize_(bsz) {
        for (size_t i = 0; i < tableSize_; i++) {
          table_[i] = new Container[tableSize_];
        }
      }
    HashTable(unsigned sz, DispersionFunction<Key>& fd) : tableSize_(sz), fd_(fd) {
      for (size_t i = 0; i < tableSize_; i++) {
        table_[i] = new DynamicSequence<Key>;
      }
    }
    bool insert(const Key& key) { insert(key); }
    bool search(const Key& key) const { search(key); }
  private:
    size_t tableSize_; 
    Container* table_;
    DispersionFunction<Key>& fd_;
    ExplorationFunction<Key>& fe_;
    size_t blockSize_;
};

#endif