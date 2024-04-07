/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 05 2024
  */

#include <iostream>
#include "../Sequence/StaticSequence.h"
#include <random>

struct Arguments {
  size_t sizeOfSequence;
  std::string typeSort;
  std::string start;
  bool trace;
};

void Usage();
Arguments ParseArguments(int argc, char* argv[]);
template <class Key> StaticSequence<Key> MakeSequence(Arguments args) {
  StaticSequence<Key> sequence(args.sizeOfSequence);
  Key number;
  if (args.start == "manual") {
    std::cout << "Introduzca los elementos que desea insertar en la secuencia de tamaño" << args.sizeOfSequence << "\n";
    for (size_t i = 0; i < args.sizeOfSequence; i++) {
      std::cout << "Introduzca el valor a insertar: ";
      std::cin >> number;
      sequence.insert(number);
    }
    std::cout << std::endl;
  } else if (args.start == "random") {
    srand(time(nullptr));
    for (size_t i = 0; i < args.sizeOfSequence; i++) {
      Key randomNumber = rand() % 100 + 1;
      sequence.insert(randomNumber);
    }
  }
  return sequence;
}