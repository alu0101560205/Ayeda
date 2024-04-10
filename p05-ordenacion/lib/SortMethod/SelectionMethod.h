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
    SelectionMethod(StaticSequence<Key>& sequence, size_t size, bool trace) : SortMethod<Key>(sequence, size, trace) {}
    void Sort() const override;
};

/**
 * @brief Método ordenación por selección
*/
template <class Key>
void SelectionMethod<Key>::Sort() const {
  Key aux;
  int min;
  int counter{0};
  for (size_t i = 0; i < this->sequence_.getBlockSize(); i++) {
    min = i;
    for (size_t j = i + 1; j < this->sequence_.getBlockSize(); j++) {
      if (this->sequence_[j] < this->sequence_[min]) {
        min = j;
      }
    }
    aux = this->sequence_[i];
    this->sequence_[i] = this->sequence_[min];
    this->sequence_[min] = aux;
    if (this->trace_) {
      std::cout << "Iteración " << counter << " : ";
      this->sequence_.printSequence();
      counter++; 
    }
  }
}

#endif