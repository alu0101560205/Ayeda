/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <fstream>
#include <string>
#include "lattice.h"

struct Arguments {
  int size;
  bool isPeriodic;
  bool isOpenHot;
  std::string file;
};

void usage();
Arguments parseArguments(int argc, char* argv[]);


#endif // TOOLS_H