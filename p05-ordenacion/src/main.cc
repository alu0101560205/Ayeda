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
#include "../lib/Tools/tools.h"

int main(int argc, char* argv[]) {
  Arguments options = ParseArguments(argc, argv);
  StaticSequence<int> sequence = MakeSequence<int>(options);
  std::cout << "Sequencia original: ";
  sequence.printSequence();
  // SortMethod<int>* selection = new SelectionMethod<int>(sequence, options.sizeOfSequence);
  // selection->Sort();
  // std::cout << "Ordenación por seleccion: ";
  // sequence.printSequence();
  // SortMethod<int>* selection2 = new QuickSort<int>(sequence, options.sizeOfSequence);
  // selection2->Sort();
  // std::cout << "Ordenación por QuickSort: ";
  // sequence.printSequence();
  // SortMethod<int>* selection3 = new HeapSort<int>(sequence, options.sizeOfSequence);
  // selection3->Sort();
  // std::cout << "Ordenación por HeapSort: ";
  // sequence.printSequence();
  // SortMethod<int>* shell = new ShellSort<int>(sequence, options.sizeOfSequence);
  // shell->Sort();
  // std::cout << "Ordenación por ShellSort: ";
  // sequence.printSequence();
  SortMethod<int>* radix = new RadixSort<int>(sequence, options.sizeOfSequence);
  radix->Sort();
  std::cout << "Ordenación por RadixSort: ";
  sequence.printSequence();
  return 0;
}