/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ABE.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 29 2024
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
    bool InsertarEquilRama(const Key& k, NodoB<Key> *nodo);
};

/**
 * @brief Método para insertar en equilibrio
*/
template <class Key>
bool ABE<Key>::insertar(const Key& k) {
  if (this->raiz_ == NULL) {
    this->raiz_ = new NodoB<Key>(k, NULL, NULL);
    return true;
  } else {
    return InsertarEquilRama(k, this->raiz_);
  }
}

/**
 * @brief Método auxiliar para insertar en equilibrio
*/
template <class Key>
bool ABE<Key>::InsertarEquilRama(const Key& k, NodoB<Key> *nodo) {
  // Verificamos si el valor ya está en el árbol
  if (k == nodo->getDato()) return false;
  // Determinar la rama en la que se debe insertar el nuevo elemento
  if (this->TamRama(nodo->getIzq()) <= this->TamRama(nodo->getDer())) {
    if (nodo->getIzq() != NULL) {
      InsertarEquilRama(k, nodo->getIzq()); // Insertar en el subárbol izquierdo
    } else {
      nodo->setIzq(new NodoB<Key>(k, NULL, NULL)); // Insertar nuevo nodo en el subárbol izquierdo
      return true;
    }
  } else {
    if (nodo->getDer() != nullptr) {
      InsertarEquilRama(k, nodo->getDer()); // Insertar en el subárbol derecho
    } else {
      nodo->setDer(new NodoB<Key>(k, NULL, NULL));
      return true;
    }
  }
  return false;
}

/**
 * @brief Método para buscar un elemento en un árbol binario equilibrado
*/
template <class Key>
bool ABE<Key>::buscar(const Key& k) const {
  if (this->raiz_ == nullptr) {
    return false;
  }
  // Cola para realizar la búsqueda por niveles
  std::queue<std::pair<NodoB<Key>*, int>> cola;
  cola.push({this->raiz_, 0});

  // Realizar la búsqueda por niveles
  while (!cola.empty()) {
    auto [nodo, nivel] = cola.front();
    cola.pop();
    // Si el nodo es NULL, pasamos al siguiente
    if (nodo == nullptr) {
      continue;
    }
    // Si el valor del nodo es igual al valor buscado, retornamos true
    if (nodo->getDato() == k) {
      return true;
    }
    // Insertamos los hijos del nodo en la cola
    cola.push({nodo->getIzq(), nivel + 1});
    cola.push({nodo->getDer(), nivel + 1});
  }
  return false; // Si no encontramos el valor buscado
}

#endif