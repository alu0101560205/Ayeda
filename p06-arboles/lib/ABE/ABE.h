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
    bool insertar(const Key& k);
    bool buscar(const Key& k) const;
};

#endif