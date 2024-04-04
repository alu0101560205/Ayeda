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

int main() {
  StaticSequence<int> sequence(5);
  Position pos1 = 2, pos2 = 4, pos3 = 8, pos4 = 1, pos5 = 7;
  sequence.insert(pos1);
  sequence.insert(pos2);
  sequence.insert(pos3);
  sequence.insert(pos4);
  sequence.insert(pos5);
  std::cout << "Sequencia original: ";
  sequence.printSequence();
  SortMethod<int>* selection = new SelectionMethod<int>(sequence, 5);
  selection->Sort();
  std::cout << "Ordenación por seleccion: ";
  sequence.printSequence();
  SortMethod<int>* selection2 = new QuickSort<int>(sequence, 5);
  selection2->Sort();
  std::cout << "Ordenación por QuickSort: ";
  sequence.printSequence();
  SortMethod<int>* selection3 = new HeapSort<int>(sequence, 5);
  selection3->Sort();
  std::cout << "Ordenación por HeapSort: ";
  sequence.printSequence();
  SortMethod<int>* shell = new ShellSort<int>(sequence, 5);
  shell->Sort();
  std::cout << "Ordenación por HeapSort: ";
  sequence.printSequence();
  return 0;
}