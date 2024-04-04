/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file SortMethod.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 03 2024
  */

#ifndef SORTMETHOD_H
#define SORTMETHOD_H
#include "../Sequence/StaticSequence.h"

template <class Key>
class SortMethod {
  public:
    SortMethod (StaticSequence<Key>& sequence, size_t size) : sequence_(sequence), sequenceSize_(size) {}
    virtual void Sort() const = 0; 
  protected:
    StaticSequence<Key>& sequence_;
    size_t sequenceSize_;
};

#endif