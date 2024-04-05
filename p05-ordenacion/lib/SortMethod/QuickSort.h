/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file QuickSort.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 04 2024
  */

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "SortMethod.h"
#include "../Sequence/Sequence.h"
#include "../Sequence/StaticSequence.h"

template <class Key>
class QuickSort : public SortMethod<Key> {
  public:
    QuickSort(StaticSequence<Key>& sequence, size_t size) : SortMethod<Key>(sequence, size) {}
    void Sort() const override;
  private:
    void Qsort(int ini, int fin) const;
};

/**
 * @brief Método de ordenación QuickSort
*/
template <class Key>
void QuickSort<Key>::Sort() const {
  int ini = 0; // Indice inicial
  int fin = int(this->sequenceSize_ - 1); // Índice final
  Qsort(ini, fin);
}

/**
 * @brief Método de ordenación
*/
template <class Key>
void QuickSort<Key>::Qsort(int ini, int fin) const {
  if (ini < fin) {
    Key i{ini}, f{fin};
    Key pivote = (i + f) / 2; // Punto de pivote
    while (i <= f) {
      while (this->sequence_[i] < this->sequence_[pivote]) i++;
      while (this->sequence_[f] > this->sequence_[pivote]) f--;
      if (i <= f) {
        std::swap(this->sequence_[i], this->sequence_[f]);
        i++;
        f--;
      }
    }
    if (ini < f) Qsort(ini, f);
    if (i < fin) Qsort(i, fin);
  }
}

#endif