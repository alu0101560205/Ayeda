/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 21 2024
  */

#ifndef TOOLS_H
#define TOOLS_H
#include <iostream>
#include <string>

enum class TreeType { ArbolBE, ArbolBB, ArbolAVL };

struct Arguments {
  TreeType treeType = TreeType::ArbolBE; // Añadimos ABE como predeterminado
  std::string initType;
  int sequenceSize = 0; // Número de elementos para las opciones random y file
  std::string fileName;
};

Arguments ParseArguments(int argc, char* argv[]);

#endif