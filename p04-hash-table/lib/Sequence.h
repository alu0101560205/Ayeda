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
class DynamicSequence : public Sequence<Key> {
  public:
    bool search(const Key& key) const override;
    bool insert(const Key& key) override;
  private:
    std::list<Key> elements_; // Lista para almacenar los elementos en caso de colisión
};

/**
 * @brief Clase para implementar la técnica de dispersión cerrada
*/
template <class Key>
class StaticSequence : public Sequence<Key> {
  public:
    StaticSequence(size_t blocksz) : blockSize_(blocksz) {}
    bool search(const Key& key) const override;
    bool insert(const Key& key) override;
    bool isFull() const;
  private:
    size_t currentSize_; = 0; // Tamaño actual de la secuencia
    const size_t blockSize_ = 0; // Tamaño del bloque
    std::array<Key, blockSize_> elements_; // Para almacenar elementos
};

#endif