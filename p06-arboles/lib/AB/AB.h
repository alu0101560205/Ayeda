/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file AB.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 17 2024
  */

#ifndef AB_H
#define AB_H
#include <iostream>
#include "../NodoB/NodoB.h"

/**
 * @brief Clase para definir la estructura de árbol binario
*/
template <class Key>
class AB {
  public:
    AB() : raiz_(NULL) {}
    ~AB() { Podar(raiz) }
    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;
    void inorden() const;
    friend operator<<(ostream& os, const Key& k);
    void Podar(NodoB<Key>* &nodo);
    bool EsVacio(NodoB<Key> *nodo);
    bool EsHoja(NodoB<Key> *nodo);
    const int Tam() { return TamRama(raiz_) }
    const int TamRama(NodoB<Key> *nodo);
  private:
    NodoB<Key>* raiz_;
};

/**
 * @brief Método para podar una parte del árbol
*/
template <class Key>
void AB<Key>::Podar(NodoB<Key>* &nodo) {
  if (nodo == NULL) return;
  Podar(nodo->izdo_); // Podar subárbol izquierdo
  Podar(nodo->dcho_); // Podar subárbol derecho
  delete nodo; // Eliminar nodo
  nodo = NULL;
}

/**
 * @brief Método para saber si un nodo está vacío
*/
template <class Key>
bool AB<Key>::EsVacio(NodoB<Key> *nodo) {
  return (nodo == NULL);
}

/**
 * @brief Método para saber si un nodo es hoja, es decir, no tiene
 * hijo izquierdo ni derecho
*/
template <class Key>
bool AB<Key>::EsHoja(NodoB<Key> *nodo) {
  return (!nodo->dcho_ && !nodo->izdo_);
}

/**
 * @brief Método para determinar el tamaño de una rama
*/
template <class Key>
const int AB<Key>::TamRama(NodoB<Key> *nodo) {
  if(nodo == NULL) return 0;
  return (1 + TamRama(nodo->izdo_) + TamRama(nodo->dcho_));
}

#endif