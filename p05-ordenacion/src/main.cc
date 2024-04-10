/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file main.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 02 2024
  */

#include "../lib/Sequence/Sequence.h"
#include "../lib/Sequence/StaticSequence.h"
#include "../lib/SortMethod/SortMethod.h"
#include "../lib/SortMethod/SelectionMethod.h"
#include "../lib/SortMethod/QuickSort.h"
#include "../lib/SortMethod/HeapSort.h"
#include "../lib/SortMethod/ShellSort.h"
#include "../lib/SortMethod/RadixSort.h"
#include "../lib/NIF/NIF.h"
#include "../lib/Tools/tools.h"

int main(int argc, char* argv[]) {
  Arguments options = ParseArguments(argc, argv);
  StaticSequence<NIF> sequence = MakeSequence<NIF>(options);
  std::cout << "Sequencia original: ";
  sequence.printSequence();
  if (options.trace == true) {
    std::cout << "La traza del algoritmo de ordenación se mostrará" << std::endl << std::endl;
  } else {
    std::cout << "La traza del algoritmo no se mostrará\n";
  }
  if (options.typeSort == "select") {
    SortMethod<NIF>* selection = new SelectionMethod<NIF>(sequence, options.sizeOfSequence, options.trace);
    selection->Sort();
    std::cout << "Ordenación por seleccion: ";
    sequence.printSequence();
  } else if (options.typeSort == "quick") {
    SortMethod<NIF>* selection2 = new QuickSort<NIF>(sequence, options.sizeOfSequence, options.trace);
    selection2->Sort();
    std::cout << "Ordenación por QuickSort: ";
    sequence.printSequence();
  } else if (options.typeSort == "heap") {
    SortMethod<NIF>* selection3 = new HeapSort<NIF>(sequence, options.sizeOfSequence, options.trace);
    selection3->Sort();
    std::cout << "Ordenación por HeapSort: ";
    sequence.printSequence();
  } else if (options.typeSort == "shell") {
    SortMethod<NIF>* shell = new ShellSort<NIF>(sequence, options.sizeOfSequence, options.trace);
    shell->Sort();
    std::cout << "Ordenación por ShellSort: ";
    sequence.printSequence();
  } else if (options.typeSort == "radix") {
    SortMethod<NIF>* radix = new RadixSort<NIF>(sequence, options.sizeOfSequence, options.trace);
    radix->Sort();
    std::cout << "Ordenación por RadixSort: ";
    sequence.printSequence();
  }
  return 0;
}