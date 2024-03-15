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
class HashTable {
  public:
    
};

template <class Key>
class HashTable <DynamicSequence<Key>> {

};

#endif