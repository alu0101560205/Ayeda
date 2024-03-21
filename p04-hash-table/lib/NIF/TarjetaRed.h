/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file TarjetaRed.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 21 2024
  */

#ifndef TARJETA_H
#define TARJETA_H
#include "NIF.h"

// Modificación
class TarjetaRed : public NIF {
  public:
    TarjetaRed (std::string mac, int vel, std::string marca, bool hv, std::string model, int salida) 
      : direccion_mac_(mac), velocidad_(vel), marca_(marca), hv_(hv), modelo_(model), salidas_(salida) {}
    operator long () const {
      long total = std::stoi(direccion_mac_) + velocidad_ + std::stoi(marca_) + hv_ + std::stoi(modelo_) + salidas_;
      return total;
    }
  private: 
    std::string direccion_mac_;
    int velocidad_;
    std::string marca_;
    bool hv_;
    std::string modelo_;
    int salidas_;
};

#endif