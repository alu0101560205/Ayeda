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
#include "../lib/Tools/tools.h"

int main(int argc, char* argv[]) {
  // Arguments options = ParseArguments(argc, argv);
  // StaticSequence<int> sequence = MakeSequence<int>(options);
  // std::cout << "Sequencia original: ";
  // sequence.printSequence();
  // // SortMethod<int>* selection = new SelectionMethod<int>(sequence, 5);
  // // selection->Sort();
  // // std::cout << "Ordenación por seleccion: ";
  // // sequence.printSequence();
  // SortMethod<int>* selection2 = new QuickSort<int>(sequence, 5);
  // selection2->Sort();
  // std::cout << "Ordenación por QuickSort: ";
  // sequence.printSequence();
  // // SortMethod<int>* selection3 = new HeapSort<int>(sequence, 5);
  // // selection3->Sort();
  // // std::cout << "Ordenación por HeapSort: ";
  // // sequence.printSequence();
  // // SortMethod<int>* shell = new ShellSort<int>(sequence, 5);
  // // shell->Sort();
  // // std::cout << "Ordenación por ShellSort: ";
  // // sequence.printSequence();
  StaticSequence<int> sequence(10);
  Position p1(9), p2(265), p3(56), p4(26), p5(78), p6(520), p7(3), p8(4), p9(8965), p10(526);
  sequence.insert(p1);
  sequence.insert(p2);
  sequence.insert(p3);
  sequence.insert(p4);
  sequence.insert(p5);
  sequence.insert(p6);
  sequence.insert(p7);
  sequence.insert(p8);
  sequence.insert(p9);
  sequence.insert(p10);
  sequence.printSequence();
  SortMethod<int>* selection = new QuickSort<int>(sequence, 10);
  selection->Sort();
  sequence.printSequence();
  return 0;
}