/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Position.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include <stdarg.h>
#include "ac_exception.h"

typedef int Coor_t;

class Position {
  public:
    virtual Coor_t operator[](unsigned int) const = 0; // Operador de acceso a la i-ésima coordenada
};

template <int Dim=2> // El valor predeterminado de Dim es 2 si no se proporciona otro
class PositionDim : public Position {
  public:
    PositionDim(int sz, ...) { // Constructor con lista variable de parámetros, sz es el número de argumentos
      va_list vl;
      va_start(vl, sz); // v1 apuntará al primer argumentos después de sz
      for(int d = 0; d < Dim; d++) {
        Coordinates_[d] = va_arg(vl, Coor_t);
      }
      va_end(vl); // Finalizamos el uso de la lista variable de argumentos
    }

    Coor_t operator[](unsigned int i) const {
      if (i < Dim) {
        return Coordinates_[i];
      } else {
        throw ac_exception("Acceso fuera de rango a las coordenadas."); 
      }
    }
  private:
    Coor_t Coordinates_[Dim];
};

#endif // POSITION_H