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
#include "../SortMethod/SortMethod.h"
#include "../SortMethod/SelectionMethod.h"
#include "../SortMethod/QuickSort.h"
#include "../SortMethod/ShellSort.h"
#include "../SortMethod/SortMethod.h"
#include "../SortMethod/RadixSort.h"
#include "../SortMethod/HeapSort.h"
#include "../NIF/NIF.h"
#include <random>

struct Arguments {
  size_t sizeOfSequence;
  std::string typeSort;
  std::string start;
  std::string initFile = "";
  bool trace;
};

void Usage();
Arguments ParseArguments(int argc, char* argv[]);

template <class Key> StaticSequence<Key> MakeSequence(Arguments args) {
  StaticSequence<Key> sequence(args.sizeOfSequence);
  if (args.start == "manual") {
    std::cout << "Introduzca los elementos que desea insertar en la secuencia de tamaño" << args.sizeOfSequence << "\n";
    for (size_t i = 0; i < args.sizeOfSequence; i++) {
      std::cout << "Introduzca el valor a insertar: ";
      Key number;
      std::cin >> number;
      sequence.insert(number);
    }
    std::cout << std::endl;
  } else if (args.start == "random") {
    srand(time(nullptr));
    for (size_t i = 0; i < args.sizeOfSequence; i++) {
      // Key randomNumber = rand() % 100 + 1;
      // sequence.insert(randomNumber);
      Key randomNumber;
      randomNumber = NIF(); // Utilizamos el constructor por defecto de NIF
      sequence.insert(randomNumber);
    }
  }
  return sequence;
}

template <class Key> SortMethod<Key>* TypeSequence(StaticSequence<Key> sequence, Arguments args) {
  SortMethod<Key>* seq;
  std::cout << "Tipo de ordenación: " << args.typeSort << std::endl;
  if (args.typeSort == "select") {
    seq = new SelectionMethod<Key>(sequence, args.sizeOfSequence);
    std::cout << "La secuencia se ordenará mediante el método de Selección\n";
  } else if (args.typeSort == "quick") {
    seq = new QuickSort<Key>(sequence, args.sizeOfSequence);
    std::cout << "La secuencia se ordenará mediante el método QuickSort\n";
  } else if (args.typeSort == "heap") {
    seq = new HeapSort<Key>(sequence, args.sizeOfSequence);
    std::cout << "La secuencia se ordenará mediante el método de HeapSort\n";
  } else if (args.typeSort == "shell") {
    seq = new ShellSort<Key>(sequence, args.sizeOfSequence);
    std::cout << "La secuencia se ordenará mediante el método de ShellSort\n";
  } else if (args.typeSort == "radix") {
    seq = new RadixSort<Key>(sequence, args.sizeOfSequence);
    std::cout << "La secuencia se ordenará mediante el método de RadixSort\n";
  } else {
    std::cout << "Tipo de ordenación no conocido\n";
    Usage();
  }
  return seq;
}