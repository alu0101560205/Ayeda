/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Sequence.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 02 2024
  */

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <array>
#include <vector>

/**
 * @brief Clase Sequence
*/
template <class Key>
class Sequence {
  public:
    virtual bool search(Key& key) const = 0;
    virtual bool insert(Key& key) = 0;
    virtual Key operator[](const Position& pos) const = 0;
    virtual ~Sequence() {}
};

#endif