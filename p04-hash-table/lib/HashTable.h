/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Hastable.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Sequence.h"
#include "DispersionFunction.h"
#include "ExplorationFunction.h"

template <class Key, class Container = StaticSequence<Key>>
class HashTable : public Sequence<Key> {
  public:
    HashTable(unsigned size, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned blocksize) : tableSize_(size), fd_(fd), fe_(fe), blockSize_(blocksize) {
      table_ = new Container*[tableSize_];
      for (size_t i = 0; i < tableSize_; ++i) {
        table_[i] = new Container(blockSize_);
      }
    }
    ~HashTable() {
      for (size_t i = 0; i < tableSize_; ++i) {
        delete table_[i];
      }
      delete[] table_;
    }

  private:
    Container** table_; // Tabla de dispersión
    size_t tableSize_; // Tamaño de la tabla de dispersión
    DispersionFunction<Key>& fd_; // función de dispersión
    ExplorationFunction<Key>& fe_; // Función de exploración
    size_t blockSize_; // Tamaño del bloque
};

#endif