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
  Position pos1 = 2;
  sequence.insert(pos1);
  Position pos2 = 4;
  sequence.insert(pos2);
  Position pos3 = 8;
  sequence.insert(pos3);
  int element = sequence[0];
  int element2 = sequence[1];
  int element3 = sequence[2];
  std::cout << element << " " << element2 << " " << element3 << std::endl;
  return 0;
}