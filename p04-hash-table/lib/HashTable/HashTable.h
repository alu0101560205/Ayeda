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
class HashTable : public Sequence <Key> {
  public:
    HashTable (unsigned tsz, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned bsz)
      : tableSize_(tsz), fd_(fd), fe_(fe), blockSize_(bsz) {
        hashTable_ = new Container*[tableSize_];
        for (size_t i = 0; i < tableSize_; i++) {
          hashTable_[i] = new Container{blockSize_};
        }
      }
    bool search(Key& key) const;
    bool insert(Key& key);
  private:
    size_t tableSize_;
    DispersionFunction<Key>& fd_;
    ExplorationFunction<Key>& fe_;  
    size_t blockSize_;
    Container** hashTable_;
};

/**
 * @brief Función insert estática
*/
template <class Key, class Container>
bool HashTable<Key, Container>::insert(Key& key) {
  int position{0};
  for (size_t i = 0; i < tableSize_; i++) {
    position += (fe_(key, i) + fd_(key));
    position = position % tableSize_;
    if (hashTable_[position]->insert(key) == true) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Función search estática
*/
template <class Key, class Container>
bool HashTable<Key, Container>::search(Key& key) const {
  int position{0};
  for (size_t i = 0; i < tableSize_; i++) {
    position += (fe_(key, i) + fd_(key));
    position = position % tableSize_;
    if (hashTable_[position]->search(key) == true) {
      return true;
    }
  }
  return false;
}

template <class Key>
class HashTable <Key, DynamicSequence<Key>> {
  public:
    HashTable (unsigned tsz, DispersionFunction<Key>& fd) : tableSize_(tsz), fd_(fd) { 
      hashTable_ = new DynamicSequence<Key>*[tableSize_];
    }
    bool search(Key& key) const;
    bool insert(Key& key);
  private:
    DispersionFunction<Key> fd_;
    size_t tableSize_;
    Sequence<Key>* hashTable_;
};

/**
 * @brief Función insert dinámica
*/
template <class Key>
bool HashTable<Key, DynamicSequence<Key>>::insert(Key& key) {
  unsigned int position{0};
  position = fd_(key);
  position = position % tableSize_;
  if (hashTable_[position]->insert(key) == true) {
    return true;
  }
  return false;
}

/**
 * @brief Función search dinámica
*/
template <class Key>
bool HashTable<Key, DynamicSequence<Key>>::search(Key& key) const {
  unsigned int position{0};
  position = fd_(key);
  position = position % tableSize_;
  if (hashTable_[position]->search(key) == true) {
    return true;
  }
  return false;
}

#endif