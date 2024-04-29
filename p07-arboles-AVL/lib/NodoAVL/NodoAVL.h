/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file NodoAVL.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 29 2024
  */

#ifndef NODOAVL_H
#define NODOAVL_H
#include <iostream>
#include "../NodoB/NodoB.h"

/**
 * @brief Clase para definir los nodos del árbol AVL
*/
template <class Key>
class NodoAVL : public NodoB<Key> {
  public:
    NodoAVL(Key dato, NodoB<Key>* izq = nullptr, NodoB<Key>* dcho = nullptr, int balance = 0) : NodoB<Key>(dato, izq, dcho), bal_(balance) {}
    int getBalance() const { return bal_; }
    void setBalance(int balance) { bal_ = balance; }
  private:
    int bal_; // Factor de balanceo del nodo
};

#endif