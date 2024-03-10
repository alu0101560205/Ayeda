/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Sequence.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <list>
#include <array>

/**
 * @brief Clase para elegir entre dispersión abierta o cerrada
*/
template <class Key>
class Sequence {
  public:
    virtual bool search(const Key& key) const = 0;
    virtual bool insert(const Key& key) = 0;
    virtual ~Sequence() {}
};

/**
 * @brief Clase para implementar la técnica de dispersión abierta
*/
template <class Key>
class OpenAddressingSequence : public Sequence<Key> {
  public:
    bool search(const Key& key) const override;
    bool insert(const Key& key) override;
  private:
    std::list<Key> elements_; // Lista para almacenar los elementos en caso de colisión
};

/**
 * @brief Clase para implementar la técnica de dispersión cerrada
*/
template <class Key, size_t blockSize>
class ClosedAddressingSequence : public Sequence<Key> {
  public:
    bool search(const Key& key) const override;
    bool insert(const Key& key) override;
  private:
    std::array<Key, blockSize> elements_;
    size_t size_ = 0; // Tamaño actual de la secuencia
};

#endif