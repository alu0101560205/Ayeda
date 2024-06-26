/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ShellSort.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 04 2024
  */

#ifndef SHELLSORT_H
#define SHELLSORT_H
#include "SortMethod.h"
#include "../Sequence/StaticSequence.h"

template <class Key>
class ShellSort : public SortMethod<Key> {
  public:
    ShellSort(StaticSequence<Key> sequence, size_t size, bool trace) : SortMethod<Key>(sequence, size, trace) {}
    void Sort() const override;
  private:
    void DeltaSort(int delta, int n, int& counter) const;
};

/**
 * @brief Método DeltaSort para ordenar
*/
template <class Key>
void ShellSort<Key>::DeltaSort(int delta, int n, int& counter) const {
  int x{0}, j{0};
  for (int i = delta; i < n; i++) {
    x = this->sequence_[i];
    j = i;
    while ((j >= delta) && (x < this->sequence_[j - delta])) {
      this->sequence_[j] = this->sequence_[j - delta];
      j = j - delta;
    }
    this->sequence_[j] = x;
    if (this->trace_) {
      std::cout << "Iteración " << counter << " :";
      this->sequence_.printSequence();
      counter++;
    }
  }
}

/**
 * @brief Método ShellSort
*/
template <class Key>
void ShellSort<Key>::Sort() const {
  int n = this->sequence_.getBlockSize() - 1;
  int delta = n;
  int counter{0};
  while (delta > 1) {
    delta /= 2;
    DeltaSort(delta, n, counter);
  }
}

#endif