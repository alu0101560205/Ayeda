/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file AVL.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 29 2024
  */

#ifndef AVL_H
#define AVL_H
#include "../ABB/ABB.h"
#include "../NodoAVL/NodoAVL.h"

/**
 * @brief Clase para definir el árbol AVL
*/
template <class Key>
class AVL : public ABB<Key> {
  public:
    AVL() : ABB<Key>(), traza_(false) {}
    bool insertar(const Key& k) override { return InsertarRama(this->raiz_, k); }
    void activarTraza() { traza_ = true; }
    void desactivarTraza() { traza_ = false; }
  private:
    NodoAVL<Key>* raiz_; // Raíz del árbol AVL
    bool traza_; // Atributo para indicar si el modo traza está activado
    bool InsertarRama(NodoB<Key>*& nodo, Key clave);
    void Equilibrar(NodoAVL<Key>*& nodo);
    void rotacionIzquierda(NodoAVL<Key>*& nodo);
    void rotacionDerecha(NodoAVL<Key>*& nodo);
    int calcularBalance(NodoAVL<Key>* nodo);
};

/**
 * @brief Método para insertar una rama
*/
template <class Key>
bool AVL<Key>::InsertarRama(NodoB<Key>*& nodo, Key clave) {
  if (!nodo) {
    nodo = new NodoAVL<Key>(clave);
    return true;
  }
  if (clave < nodo->getDato()) {
    if (!InsertarRama(nodo->getIzq(), clave)) {
      return false;
    }
  } else if (clave > nodo->getDato()) {
    if (!InsertarRama(nodo->getDer(), clave)) {
      return false;
    }
  } else {
    // El valor ya existe en el árbol
    return false;
  }
  // Equilibrar el nodo después de la inserción
  NodoAVL<Key>* nodoAVL = static_cast<NodoAVL<Key>*>(nodo);
  equilibrar(nodoAVL);
  return true;
}

/**
 * @brief Método para equilibrar el árbol AVL después de la insercción
*/
template <class Key>
void AVL<Key>::Equilibrar(NodoAVL<Key>*& nodo) {
  // Calcula el factor de balanceo
  int balance = calcularBalance(nodo);
  // Rotación necesaria si el factor de balanceo no está dentro del rango de [-1, 1]
  if (balance > 1) {
    // Subárbol izquierdo está desbalanceado
    if (calcularBalance(nodo->getIzq()) < 0) {
      // Rotación ID (Izquierda-Derecha)
      if (traza_) {
        std::cout << "Árbol antes de la rotación ID en nodo " << nodo->getDato() << ":\n";
        imprimirArbol(nodo);
        std::cout << "Aplicando rotación ID...\n";
      }
      rotacionIzquierda(nodo->getIzq()); // Rotación izquierda en el subárbol izquierdo
    }
    // Rotación II (Izquierda-Izquierda)
    if (traza_) {
      std::cout << "Árbol antes de la rotación II en nodo " << nodo->getDato() << ":\n";
      imprimirArbol(nodo);
      std::cout << "Aplicando rotación II...\n";
    }
    rotacionDerecha(nodo); // Rotación derecha en el nodo actual
  } else if (balance < -1) {
    // Subárbol derecho está desbalanceado
    if (calcularBalance(nodo->getDer()) > 0) {
      // Rotación DI (Derecha-Izquierda)
      if (traza_) {
        std::cout << "Árbol antes de la rotación DI en nodo " << nodo->getDato() << ":\n";
        imprimirArbol(nodo);
        std::cout << "Aplicando rotación DI...\n";
      }
      rotacionDerecha(nodo->getDer()); // Rotación derecha en el subárbol derecho
    }
    // Rotación DD (Derecha-Derecha)
    if (traza_) {
      std::cout << "Árbol antes de la rotación DD en nodo " << nodo->getDato() << ":\n";
      imprimirArbol(nodo);
      std::cout << "Aplicando rotación DD...\n";
    }
    rotacionIzquierda(nodo); // Rotación izquierda en el nodo actual
  }
}

/**
 * @brief Método para la rotación a la izquierda
*/
template <class Key>
void AVL<Key>::rotacionIzquierda(NodoAVL<Key>*& nodo) {
  NodoAVL<Key>* hijoDerecho = static_cast<NodoAVL<Key>*>(nodo->getDer());
  nodo->setDer(hijoDerecho->getIzq());
  hijoDerecho->setIzq(nodo);
  nodo = hijoDerecho;

  // Actualizar los factores de balanceo
  static_cast<NodoAVL<Key>*>(nodo->getIzq())->actualizarFactorBalanceo();
  hijoDerecho->actualizarFactorBalanceo();
}

/**
 * @brief Método para rotar a la derecha
*/
template <class Key>
void AVL<Key>::rotacionDerecha(NodoAVL<Key>*& nodo) {
  NodoAVL<Key>* hijoIzquierdo = static_cast<NodoAVL<Key>*>(nodo->getIzq());
  nodo->setIzq(hijoIzquierdo->getDer());
  hijoIzquierdo->setDer(nodo);
  nodo = hijoIzquierdo;

  // Actualizar los factores de balanceo
  static_cast<NodoAVL<Key>*>(nodo->getDer())->actualizarFactorBalanceo();
  hijoIzquierdo->actualizarFactorBalanceo();
}

/**
 * @brief Método para calcular el balanceo
*/
template <class Key>
int AVL<Key>::calcularBalance(NodoAVL<Key>* nodo) {
  if (!nodo) {
    return 0; // Si el nodo es nulo, el balance es cero
  }
    
  int alturaIzquierda = altura(static_cast<NodoAVL<Key>*>(nodo->getIzq()));
  int alturaDerecha = altura(static_cast<NodoAVL<Key>*>(nodo->getDer()));

  // Retorna la diferencia entre la altura del subárbol izquierdo y derecho
  return alturaIzquierda - alturaDerecha;
}

#endif