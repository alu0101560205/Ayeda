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
    StaticSequence(size_t tSize, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, size_t bSize) 
      : tableSize_(tSize), fd_(fd), fe_(fe), blockSize_(bSize) {
        table_ = new Sequence<Key>*[tableSize_];
        for (size_t i = 0; i < tableSize_; i++) {
          table_[i] = new Container[blockSize_];
        }
      }
    bool search(const Key& key) const override;
    bool insert(const Key& key) override;
    bool isFull() const;
  private:
    size_t tableSize_; // Tamaño de la tabla
    Sequence<Key>** table_; // Array con tableSize posiciones, con punteros a objetos Sequence<Key>
    DispersionFunction<Key>& fd_; // Función de dispersión
    ExplorationFunction<Key>& fe_; // Función de exploración
    size_t blockSize_; // Tamaño del bloque
};

/**
 *@brief Método para buscar un elemento en la tabla (estática) 
*/
template <class Key>
bool StaticSequence<Key>::search(const Key& key) const {
  for (size_t i = 0; i < tableSize_; i++) {
    if (table_[k] == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Método para insertar un elemento en la tabla (estática)
*/
template <class Key>
bool StaticSequence<Key>::insert(const Key& key) {
  
}

#endif