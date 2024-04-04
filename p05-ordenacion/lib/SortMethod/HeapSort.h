/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file HeapSort.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 03 2024
  */

#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "SortMethod.h"
#include "../Sequence/Sequence.h"
#include "../Sequence/StaticSequence.h"

template <class Key>
class HeapSort : public SortMethod<Key> {
  public:
    HeapSort(StaticSequence<Key> sequence, size_t size) : SortMethod<Key>(sequence,size) {}
    void Sort() const override;
  private:
    void Baja(int i, int n) const;
};

/**
 * @brief Método de baja
*/
template <class Key>
void HeapSort<Key>::Baja(int i, int n) const {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && this->sequence_[l] > this->sequence_[largest]) {
    largest = l;
  }
  if (r < n && this->sequence_[r] > this->sequence_[largest]) {
    largest = r;
  }
  if (largest != i) {
    std::swap(this->sequence_[i], this->sequence_[largest]);
    Baja(largest, n);
  }
}

/**
 * @brief Método de ordenación por HeapSort
*/
template <class Key>
void HeapSort<Key>::Sort() const {
  int n = this->sequence_.getBlockSize();
  for (int i = n - 1; i >= 0; i--) {
    Baja(i, n);
  }
  for (int i = n - 1; i >= 0; i--) {
    std::swap(this->sequence_[0], this->sequence_[i]);
    Baja(0, i);
  }
}

#endif