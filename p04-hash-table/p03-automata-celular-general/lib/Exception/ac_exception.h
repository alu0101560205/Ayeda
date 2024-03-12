/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file ac_exception.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 03 2024
  */

#ifndef AC_EXCEPTION
#define AC_EXCEPTION
#include <exception>
#include <stdexcept>
#include <iostream>

class ac_exception : public std::exception {
  public:
    explicit ac_exception(const char* message) : msg(message) {}
    virtual const char* what() const throw() {
      return msg;
    }
  private:
    const char* msg;
};

#endif // AC_EXCEPTION