/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file RadixSort.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 07 2024
  */

#ifndef RADIXSORT_H
#define RADIXSORT_H
#include "SortMethod.h"
#include "../Sequence/Sequence.h"
#include "../Sequence/StaticSequence.h"

template <class Key>
class RadixSort : public SortMethod<Key> {
  public:
    RadixSort(StaticSequence<Key> sequence, size_t size, bool trace) : SortMethod<Key>(sequence, size, trace) {}
    void Sort() const override;
  private:
    void Rsort() const;
    Key getDigit(Key num, int d) const; 
};

/**
 * @brief Función para obtener el dígito en la posición d de un número
*/
template <class Key>
Key RadixSort<Key>::getDigit(Key num, int d) const {
  for (int i = 1; i < d; i++) {
    num = num / 10;
  }
  return num % 10;
}

/**
 * @brief Método para aplicar el algoritmo RadixSort
*/
template <class Key>
void RadixSort<Key>::Rsort() const {
  // Buscamos el máximo número de la secuencia
  Key maxNum = this->sequence_[0];
  for (size_t i = 1; i < this->sequence_.getBlockSize(); i++) {
    if (this->sequence_[i] > maxNum) {
      maxNum = this->sequence_[i];
    }
  }
  // Determinar el número de dígitos del número más grande
  int digits = 0;
  Key temp = maxNum;
  while (temp > 0) {
    temp = temp / 10;
    digits++;
  }
  // Creamos el auxiliar para almacenar los números en cada dígito
  std::vector<std::vector<Key>> buckets(10);
  int counter{0};
  // Realizar el Radix sort
  for (int d = 1; d <= digits; ++d) {
    // Distribuir los números en los buckets
    for (size_t i = 0; i < this->sequence_.getBlockSize(); ++i) {
      Key digit = getDigit(this->sequence_[i], d);
      buckets[digit].push_back(this->sequence_[i]);
    }
    // Recoger los números de los buckets en la secuencia
    this->sequence_.clear();
    for (int i = 0; i < 10; ++i) {
      for (auto it = buckets[i].begin(); it != buckets[i].end(); ++it) {
        this->sequence_.insert(*it);
      }
      buckets[i].clear();
    }
    if (this->trace_) {
      std::cout << "Iteración " << counter << " : ";
      this->sequence_.printSequence();
      counter++; 
    }
  }
}

/**
 * @brief Método Radix Sort
*/
template <class Key>
void RadixSort<Key>::Sort() const {
  Rsort();
}

#endif