/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 27 2024
  */

#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "lattice.h"

struct ProgramArguments {
  int parse_rows = 0;
  int parse_cols = 0;
  std::string init_file;
  std::string border_type;
};

void Usage();
ProgramArguments ParseArguments(int argc, char* argv[]);
void UsoLetras();

#endif // TOOLS_H