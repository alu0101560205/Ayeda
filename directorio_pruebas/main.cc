/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file main.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 10 2024
  */

#include <iostream>
#include "DispersionFunction.h"
#include "ExplorationFunction.h"

// int main(int argc, char* argv[]) {
//   unsigned int tableSize = 100; // Tamaño de la tabla hash
//   // Instancia de ModuleDispersion con tamaño de tabla
//   ModuleDispersion<int> moduleHash(tableSize);
//   // Instancia de SumDispersion con tamaño de tabla
//   SumDispersion<std::string> sumHash(tableSize);
//   // Instancia de Pseudorandomdispersion con tamaño de la tabla
//   PseudorandomDispersion<double> randomHash(tableSize);
//   // Ejemplo de uso: calcular la posición para una clave
//   int key1 = 42;
//   std::string key2 = "hello";
//   double key3 = 83.2;
//   unsigned position1 = moduleHash(key1);
//   unsigned position2 = sumHash(key2);
//   unsigned position3 = randomHash(key3);
//   // Imprime las posiciones calculadas
//   std::cout << "Posición para key1: " << position1 << std::endl;
//   std::cout << "Posición para key2: " << position2 << std::endl;
//   std::cout << "Posición para key3: " << position3 << std::endl;
//   return 0;
// }


int main() {
  // Definir una función de dispersión
  ModuleDispersion<int> dispersionFunction(100); // Ejemplo de función de dispersión con una tabla de tamaño 100

  // Crear una instancia de la función de redispersión
  QuadraticExploration<int> rehashingExploration;

  // Probar la función de redispersión
  int key = 42; // Clave de ejemplo
  unsigned iterations = 3; // Número de iteraciones de redispersión
  
  std::cout << "Key: " << key << std::endl;
  for (unsigned i = 0; i < iterations; ++i) {
    key += rehashingExploration(key, i);
    std::cout << "Redispersión " << i + 1 << ": " << key << std::endl;
  }
  return 0;
}
