/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Selection.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 03 2024
  */

#ifndef SELECTIONMETHOD_H
#define SELECTIONMETHOD_H
#include "SortMethod.h"
#include "../Sequence/Sequence.h"
#include "../Sequence/StaticSequence.h"

template <class Key>
class SelectionMethod : public SortMethod<Key> {
  public:
    SelectionMethod(StaticSequence<Key>& sequence, size_t size) : SortMethod<Key>(sequence, size) {}
    void Sort() const override;
};

template <class Key>
void SelectionMethod<Key>::Sort() const {
  Key aux, min;
  for (int i = 0; i < sequence_.getBlockSize(); i++) {
    std::cout << "He entrado en el for\n";
    min = i;
    for (int j = i + 1; j < sequence_.getBlockSize(); j++) {
      if (sequence_[j] < sequence_[min]) {
        min = j;
      }
    }
    aux = sequence_[i];
    sequence_[i] = sequence_[min];
    sequence_[min] = aux;
  }
}

#endif