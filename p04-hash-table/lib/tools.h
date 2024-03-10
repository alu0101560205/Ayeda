/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#include <iostream>
#include <string>

struct Options {
  unsigned tableSize;
  std::string dispersionFunction;
  std::string hashType;
  unsigned blockSize;
  std::string explorationFunction;
};

void Usage();
Options ParseArguments(int argc, char* argv[]);