/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file NodoB.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 29 2024
  */

#ifndef NODOB_H
#define NODOB_H
#include <iostream>

/**
 * @brief Clase para definir los nodos del árbol binario
*/
template <class Key>
class NodoB {
  public:
    NodoB(Key dato, NodoB<Key>* izq = NULL, NodoB<Key>* dcho = NULL) : dato_(dato), izdo_(izq), dcho_(dcho) {}
    NodoB*& getIzq() { return izdo_; }
    void setIzq(NodoB<Key>* nodo) { izdo_ = nodo; }
    NodoB*& getDer() { return dcho_; }
    void setDer(NodoB<Key>* nodo) { dcho_ = nodo; }
    Key getDato() { return dato_; }
    
  protected:
    Key dato_; // Contiene la información a almacenar en los nodos
    NodoB<Key>* izdo_; // Hijo izquierdo del nodo binario
    NodoB<Key>* dcho_; // Hijo derecho del nodo binario
};

#endif