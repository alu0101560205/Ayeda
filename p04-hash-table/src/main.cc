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
#include "../lib/DispersionFunction.h"
#include "../lib/ExplorationFunction.h"
#include "../lib/HashTableDynamic.h"
#include "../lib/HashTableStatic.h"
#include "../lib/Sequence.h"
#include "../lib/tools.h"
#include "../lib/NIF.h"

using Key = NIF;

int main(int argc, char* argv[]) {
  Options options = ParseArguments(argc, argv);
  // Creamos el objeto de la función de dispersión
  DispersionFunction<Key>* dispersionFunction = nullptr;
  if (options.dispersionFunction == "mod") {
    dispersionFunction = new ModuleDispersion<Key>(options.tableSize);
  } else if (options.dispersionFunction == "sum") {
    dispersionFunction = new SumDispersion<Key>(options.tableSize);
  } else if (options.dispersionFunction == "random") {
    dispersionFunction = new PseudorandomDispersion<Key>(options.tableSize);
  } else {
    throw std::invalid_argument("Función de dispersión desconocida");
  }
  // Creamos el objeto de la función de exploración (opcional)
  ExplorationFunction<Key>* explorationFunction = nullptr;
  if (!options.explorationFunction.empty()) {
    if (options.explorationFunction == "linear") {
      explorationFunction = new LinearExploration<Key>();
    } else if (options.explorationFunction == "quadratic") {
      explorationFunction = new QuadraticExploration<Key>();
    } else if (options.explorationFunction == "doubleHashing") {
      explorationFunction = new DoubleHashingExploration<Key>(dispersionFunction);
    } else if (options.explorationFunction == "rehashing") {
      explorationFunction = new RehashingExploration<Key>();
    } else {
      throw std::invalid_argument("Función de exploración desconocida");
    }
  }
  // Creamos tabla Hash
  size_t size = options.tableSize;
    
}