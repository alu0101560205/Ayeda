/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ABB.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 20 2024
  */

#ifndef ABB_H
#define ABB_H
#include <iostream>
#include "../AB/AB.h"

/**
 * @brief Clase para representar el árbol binario de búsqueda
*/
template <class Key>
class ABB : public AB<Key> {
  public:
    ABB() : AB<Key>() {}
    bool insertar(const Key& k) override { return InsertarRama(this->raiz_, k); }
    bool buscar(const Key& k) const override { return BuscarRama(this->raiz_, k); }
  private:
    NodoB<Key>* BuscarRama(NodoB<Key>* nodo, Key clave) const;
    bool InsertarRama(NodoB<Key>* &nodo, Key clave);
};

/**
 * @brief Método auxiliar para realizar la búsqueda
*/
template <class Key>
NodoB<Key>* ABB<Key>::BuscarRama(NodoB<Key>* nodo, Key clave) const {
  if (nodo == NULL) return NULL;
  if (clave == nodo->getDato()) return nodo;
  if (clave < nodo->getDato()) return BuscarRama(nodo->getIzq(), clave);
  return BuscarRama(nodo->getDer(), clave);
}

/**
 * @brief Método auxiliar para la insercción en árbol de búsqueda
*/
template <class Key>
bool ABB<Key>::InsertarRama(NodoB<Key>* &nodo, Key clave) {
  if (nodo == NULL) {
    nodo = new NodoB<Key>(clave, NULL, NULL);
    return true;
  } else if (clave < nodo->getDato()) {
    return InsertarRama(nodo->getIzq(), clave);
  } else if (clave > nodo->getDato()) {
    return InsertarRama(nodo->getDer(), clave);
  } else {
    return false; // Si ya existe, no inserta y devuelve false
  }
}

#endif