/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file StaticSequence.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef STATICSEQUENCE_h
#define STATICSEQUENCE_h
#include "Sequence.h"

/**
 * @brief Clase para implementar la técnica de dispersión cerrada
*/
template <class Key>
class StaticSequence : public Sequence<Key> {
  public:
    StaticSequence(size_t bSize) : blockSize_(bSize) {
      table_ = new Key*[blockSize_];
      for (size_t i = 0; i < blockSize_; i++) {
        table_[i] = nullptr;
      }
    }
    bool search(Key& key) const override;
    bool insert(Key& key) override;
    bool isFull() const;
  private:
    Key** table_; 
    size_t blockSize_; // Tamaño del bloque
};

/**
 *@brief Método para buscar un elemento en la tabla (estática) 
*/
template <class Key>
bool StaticSequence<Key>::search(Key& key) const {
  for (size_t i = 0; i < blockSize_; i++) {
    if (*table_[i] == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Método para insertar un elemento en la tabla (estática)
*/
template <class Key>
bool StaticSequence<Key>::insert(Key& key) {
  size_t i = 0; 
  while (table_[i] != nullptr && i < this->blockSize_ ) {
    i++;
  }
  if (i == this->blockSize_) return false;
  else table_[i] = new Key(key);
  return true;
}

/**
 * @brief Método para saber si la seciencia está llena
*/
template <class Key>
bool StaticSequence<Key>::isFull() const {
  for (size_t i = 0; i < blockSize_; i++) {
    if (table_[i] == nullptr) {
      return false;
    }
  }
  return true;
}

#endif