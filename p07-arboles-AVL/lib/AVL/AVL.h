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
    bool insertar(const Key& k) override;
    bool buscar(const Key& k) const override;
    void activarTraza() { traza_ = true; }
    void desactivarTraza() { traza_ = false; }
  private:
    NodoAVL<Key>* raiz_; // Raíz del árbol AVL
    bool traza_; // Atributo para indicar si el modo traza está activado
    void Rotacion_II(NodoAVL<Key>* &nodo);
    void Rotacion_DD(NodoAVL<Key>* &nodo);
    void Rotacion_ID(NodoAVL<Key>* &nodo);
    void Rotacion_DI(NodoAVL<Key>* &nodo);
    void Inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool& crece);
    void Insert_re_balancea_izq(NodoAVL<Key>* &nodo, bool &crece);
    void Insert_re_balancea_der(NodoAVL<Key>* &nodo, bool &crece);
};

/**
 * @brief Método para implementar la búsqueda de un elemento en el árbol AVL
*/
template <class Key>
bool AVL<Key>::buscar(const Key& k) const {
  // Inicia la búsqueda en la raíz del árbol AVL
  NodoAVL<Key>* nodo = this->raiz_;
  // Recorre el árbol buscando la clave k
  while (nodo != nullptr) {
    // Compara la clave k con la clave del nodo actual
    if (nodo->getDato() == k) {
      // La clave coincide, la búsqueda es exitosa
      return true;
    } else if (k < nodo->getDato()) {
      // Si la clave k es menor, ve hacia el hijo izquierdo
      nodo = static_cast<NodoAVL<Key>*>(nodo->getIzq());
    } else {
      // Si la clave k es mayor, ve hacia el hijo derecho
      nodo = static_cast<NodoAVL<Key>*>(nodo->getDer());
    }
  }
  // Si llegamos aquí, la clave k no se encontró en el árbol
  return false;
}

/**
 * @brief Método para implementar la rotación Izquierda-Izquierda
*/
template <class Key>
void AVL<Key>::Rotacion_II(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = static_cast<NodoAVL<Key>*>(nodo->getIzq());
  nodo->setIzq(nodo1->getDer());
  nodo1->setDer(nodo);
  if (nodo1->getBalance() == 1) {
    nodo->setBalance(0);
    nodo1->setBalance(0);
  } else { // balance == 0
    nodo->setBalance(1);
    nodo1->setBalance(-1);
  }
  nodo = nodo1;
}

/**
 * @brief Método para implementar la rotación Derecha-Derecha
*/
template <class Key>
void AVL<Key>::Rotacion_DD(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = static_cast<NodoAVL<Key>*>(nodo->getDer());
  nodo->setDer(nodo1->getIzq());
  nodo1->setIzq(nodo);
  if (nodo1->getBalance() == -1) {
    nodo->setBalance(0);
    nodo1->setBalance(0);
  } else {
    nodo->setBalance(-1);
    nodo1->setBalance(1);
  }
  nodo = nodo1;
}

/**
 * @brief Método para implementar la rotación Izquierda-Derecha
*/
template <class Key>
void AVL<Key>::Rotacion_ID(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = static_cast<NodoAVL<Key>*>(nodo->getIzq());
  NodoAVL<Key>* nodo2 = static_cast<NodoAVL<Key>*>(nodo1->getDer());
  nodo->setIzq(nodo2->getDer());
  nodo2->setDer(nodo);
  nodo1->setDer(nodo2->getIzq());
  nodo2->setIzq(nodo1);
  if (nodo2->getBalance() == -1) {
    nodo1->setBalance(1);
  } else {
    nodo1->setBalance(0);
  }
  if (nodo2->getBalance() == 1) {
    nodo->setBalance(-1);
  } else {
    nodo->setBalance(0);
  }
  nodo2->setBalance(0);
  nodo = nodo2;
}

/**
 * @brief Método para implementar la rotación Derecha-Izquierda
*/
template <class Key>
void AVL<Key>::Rotacion_DI(NodoAVL<Key>* &nodo) {
  NodoAVL<Key>* nodo1 = static_cast<NodoAVL<Key>*>(nodo->getDer());
  NodoAVL<Key>* nodo2 = static_cast<NodoAVL<Key>*>(nodo1->getIzq());
  nodo->setDer(nodo2->getIzq());
  nodo2->setIzq(nodo);
  nodo1->setIzq(nodo2->getDer());
  nodo2->setDer(nodo1);
  if (nodo2->getBalance() == 1) {
    nodo1->setBalance(-1);
  } else {
    nodo1->setBalance(0);
  }
  if (nodo2->getBalance() == -1) {
    nodo->setBalance(1);
  } else {
    nodo->setBalance(0);
  }
  nodo2->setBalance(0);
  nodo = nodo2;
}

/**
 * @brief Método para insertar valores en el árbol
*/
template <class Key>
bool AVL<Key>::insertar(const Key& k) {
  // Verificamos si la clave ya existe
  if (buscar(k)) {
    std::cout << "La clave " << k << " ya existe, no será insertada\n";
    return false;
  }
  NodoAVL<Key>* nuevo = new NodoAVL<Key>(k, nullptr, nullptr, 0); // Creamos nuevo nodo
  if (!nuevo) {
    std::cout << "Error al generar el nuevo nodo\n";
    return false;
  }
  bool crece = false;
  Inserta_bal(this->raiz_, nuevo, crece);
  std::cout << "estoy aqui\n";
  return true;
}

/**
 * @brief Método auxiliar de insertar
*/
template <class Key>
void AVL<Key>::Inserta_bal(NodoAVL<Key>* &nodo, NodoAVL<Key>* nuevo, bool& crece) {
  if (nodo == nullptr) {
    nodo = nuevo;
    crece = true;
  } else if (nuevo->getDato() < nodo->getDato()) {
    NodoAVL<Key>* izq = static_cast<NodoAVL<Key>*>(nodo->getIzq());
    Inserta_bal(izq, nuevo, crece);
    if (crece) Insert_re_balancea_izq(nodo, crece);
  } else {
    NodoAVL<Key>* der = static_cast<NodoAVL<Key>*>(nodo->getDer());
    Inserta_bal(der, nuevo, crece);
    if (crece) Insert_re_balancea_der(nodo, crece);
  }
}

/**
 * @brief Método para rebalancear a la izquierda
*/
template <class Key>
void AVL<Key>::Insert_re_balancea_izq(NodoAVL<Key>* &nodo, bool &crece){
  switch (nodo->getBalance()) {
  case -1:
    nodo->setBalance(0);
    crece = false;
    break;
  case 0:
    nodo->setBalance(1);
    break;
  case 1:
    NodoAVL<Key>* nodo1 = static_cast<NodoAVL<Key>*>(nodo->getIzq());
    if (nodo1->getBalance() == 1) {
      Rotacion_II(nodo);
    } else {
      Rotacion_ID(nodo);
    }
    crece = false;
    break;
  }
}

/**
 * @brief Método para rebalancear a la derecha
*/
template <class Key>
void AVL<Key>::Insert_re_balancea_der(NodoAVL<Key>* &nodo, bool &crece) {
  switch (nodo->getBalance()) {
  case 1:
    nodo->setBalance(0);
    crece = false;
    break;
  case 0:
    nodo->setBalance(-1);
    break;
  case -1:
    NodoAVL<Key>* nodo1 = static_cast<NodoAVL<Key>*>(nodo->getDer());
    if (nodo1->getBalance() == -1) {
      Rotacion_DD(nodo);
    } else {
      Rotacion_DI(nodo);
    }
    crece = false;
  }
}


#endif