/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ABE.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 19 2024
  */

#ifndef ABE_H
#define ABE_H
#include <iostream>
#include "../AB/AB.h"

/**
 * @brief Clase para representar el árbol binario equilibrado
*/
template <class Key>
class ABE : public AB<Key> {
  public:
    ABE() : AB<Key>() {}
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
  private:
    void InsertarEquilRama(const Key& k, NodoB<Key> *nodo);
};

/**
 * @brief Método para insertar en equilibrio
*/
template <class Key>
bool ABE<Key>::insertar(const Key& k) {
  if (this->raiz_ == NULL) {
    this->raiz_ = new NodoB<Key>(k, NULL, NULL);
  } else {
    InsertarEquilRama(k, this->raiz_);
    return 1;
  }
  return 0;
}

/**
 * @brief Método auxiliar para insertar en equilibrio
*/
template <class Key>
void ABE<Key>::InsertarEquilRama(const Key& k, NodoB<Key> *nodo) {
  if (this->TamRama(nodo->getIzq()) <= this->TamRama(nodo->getDer())) {
    if (nodo->getIzq() != NULL) {
      InsertarEquilRama(k, nodo->getIzq());
    } else {
      nodo->getIzq() = new NodoB<Key>(k, NULL, NULL);
    }
  } else {
    if (nodo->getDer() != NULL) {
      InsertarEquilRama(k, nodo->getDer());
    } else {
      nodo->getDer() = new NodoB<Key>(k, NULL, NULL);
    }
  }
}

/**
 * @brief Método para buscar un elemento en un árbol binario equilibrado
*/
template <class Key>
bool ABE<Key>::buscar(const Key& k) const {

}

#endif