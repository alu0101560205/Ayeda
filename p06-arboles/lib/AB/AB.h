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
    virtual bool insertar(const Key& k) = 0;
    virtual bool buscar(const Key& k) const = 0;
    void inorden() const;
    friend operator>>(istream& is, const Key& k);
  private:
    NodoB<Key>* raiz_;
};

#endif