/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file StaticSequence.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 02 2024
  */

#include "../lib/Sequence/Sequence.h"
#include "../lib/Sequence/StaticSequence.h"

int main() {
  StaticSequence<int> sequence(10);
  int element = sequence[3];
  std::cout << element << std::endl;
  return 0;
}