/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Sequence.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#include "../lib/Sequence.h"

/**
 * @brief Función search para dispersión abierta
*/
template <class Key>
bool  DynamicSequence<Key>::search(const Key& key) const {
  for (const auto& element : elements_) {
    if (element == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Función insert para dispersión abierta
*/
template <class Key>
bool DynamicSequence<Key>::insert(const Key& key) {
  elements_.push_back(key); // Insertar el elemento en la lista
  return true;
}

/**
 * @brief Función search para dispersión cerrada
*/
template <class Key>
bool StaticSequence<Key>::search(const Key& key) const {
  for (size_t i = 0; i < size_; i++) {
    if (elements_[i] == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Función insert para dispersión cerrada
*/
template <class Key>
bool StaticSequence<Key>::insert(const Key& key) {
  if (size_ < blockSize) {
    elements_[size_++] = key;
    return true;
  }
  return false;
}

/**
 * @brief Método para verificar si la secuencia está llena
*/
template <class Key>
bool StaticSequence<Key>::isFull() const {
  return currentSize_ == blockSize_;
}