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
#include <queue>
#include "../NodoB/NodoB.h"

/**
 * @brief Clase para definir la estructura de árbol binario
*/
template <class Key>
class AB {
  public:
    AB() : raiz_(NULL) {}
    virtual ~AB() { Podar(raiz_); }
    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;
    void inordenRecursivo(NodoB<Key>* nodo) const;
    void inorden() const { inordenRecursivo(raiz_); }
    void Podar(NodoB<Key>* &nodo);
    bool EsVacio(NodoB<Key> *nodo);
    bool EsHoja(NodoB<Key> *nodo);
    const int Tam() { return TamRama(raiz_); }
    const int TamRama(NodoB<Key> *nodo);
    const int Alt() { return AltN(raiz_); }
    const int AltN(NodoB<Key> *nodo);
    NodoB<Key>*& getRaiz() const { return const_cast<NodoB<Key>*&>(raiz_); }
  protected:
    NodoB<Key>* raiz_;
};

/**
 * @brief Método para podar una parte del árbol
*/
template <class Key>
void AB<Key>::Podar(NodoB<Key>* &nodo) {
  if (nodo == NULL) return;
  Podar(nodo->getIzq()); // Podar subárbol izquierdo
  Podar(nodo->getDer()); // Podar subárbol derecho
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
  return (!nodo->getDer() && !nodo->getIzq());
}

/**
 * @brief Método para determinar el tamaño de una rama
*/
template <class Key>
const int AB<Key>::TamRama(NodoB<Key> *nodo) {
  if(nodo == NULL) return 0;
  return (1 + TamRama(nodo->getIzq()) + TamRama(nodo->getDer()));
}

/**
 * @brief Método para determinar la altura
*/
template <class Key>
const int AB<Key>::AltN(NodoB<Key> *nodo) {
  if (nodo == NULL) return 0;
  int alt_i = AltN(nodo->getIzq());
  int alt_d = AltN(nodo->getDer());
  if (alt_d > alt_i) {
    return ++alt_d;
  } else {
    return ++alt_i;
  }
}

/**
 * @brief Método para realizar el recorrido inorden
*/
template <class Key>
void AB<Key>::inordenRecursivo(NodoB<Key>* nodo) const {
  if (nodo) {
    inordenRecursivo(nodo->getIzq());
    std::cout << nodo->getDato() << " ";
    inordenRecursivo(nodo->getDer());
  }
}

/**
 * @brief Sobrecarga del operador de salida
*/
template <class Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& ab) {
  std::queue<NodoB<Key>*> cola;
  // Si el árbol está vacio
  if (ab.getRaiz() == nullptr) {
    os << "[.]" << std::endl;
    return os;
  }
  // Agregamos la raiz a la cola
  cola.push(ab.getRaiz());
  // Nivel actual
  int nivel_actual = 0;
  // Cantidad de nodos en el nivel actual
  while (!cola.empty()) {
    os << "Nivel " << nivel_actual << ": ";
    // Recorrer nodos en el nivel actual
    int nodos_en_nivel = cola.size();
    // Recorrer todos los nodos en el nivel actual
    for (int i = 0; i < nodos_en_nivel; i++) {
      NodoB<Key>* nodo = cola.front(); // Obtener el nodo del frente de la cola
      cola.pop(); // Eliminar el nodo de la cola
      // Imprimir el nodo o subárbol vacío
      if (nodo) {
        os << "[" << nodo->getDato() << "] ";
        cola.push(nodo->getIzq()); // Agregar el hijo izquierdo a la cola
        cola.push(nodo->getDer()); // Agregar el hijo derecho a la cola
      } else {
        os << "[.] ";
      }
    }
    os << std::endl; // Salto de línea al finalizar el nivel
    nivel_actual++;
  }
  return os;  // Devuelve el flujo de salida
}

#endif