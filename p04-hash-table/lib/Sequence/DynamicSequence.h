/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file DynamicSequence.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 13 2024
  */

#ifndef DYNAMICSEQUENCE_H
#define DYNAMICSEQUENCE_H
#include "Sequence.h"
#include <list>

/**
 * @brief Clase para implementar la técnica de dispersión abierta
*/
template <class Key>
class DynamicSequence : public Sequence<Key> {
  public:
    DynamicSequence() {}
    bool search(Key& key) const override;
    bool insert(Key& key) override;
  private:
    std::list<Key> elements_; // Lista para almacenar los elementos en caso de colisión
};

/**
 * @brief Método para buscar un elemento en la tabla
*/
template<class Key>
bool DynamicSequence<Key>::search (Key& key) const {
  for (auto i = elements_.begin(); i != elements_.end(); i++) {
    if (*i == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Método para insertar un elemento en la tabla
*/
template <class Key>
bool DynamicSequence<Key>::insert(Key& key) {
  if (!search(key)) { // Si el elemento no está en la lista
    elements_.push_back(key); // Lo pusheamos al final
    return true;
  }
  return false;
}

#endif