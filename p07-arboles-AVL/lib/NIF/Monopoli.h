/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Monopoli.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#ifndef MONOPOLI_H
#define MONOPOLI_H
#include <iostream>

/**
 * @brief Clase para insertar en el árbol
 * Modificación pedida
*/
template <class Key>
class Monopoli {
  public:
    Monopoli(int casas, int prop, int hotel, int money) : n_casas_(casas), n_propiedades_(prop), n_hoteles_(hotel),
      dinero_(money) {}
    int getAverage() {
      int average = n_casas_ + n_propiedades_ + n_hoteles_ + dinero_;
      int aux = average;
      return (average/aux);
    }
  private:
    int n_casas_;
    int n_propiedades_;
    int n_hoteles_;
    int dinero_;
};

#endif