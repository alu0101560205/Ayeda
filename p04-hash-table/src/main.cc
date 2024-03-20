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
#include "../lib/Dispersion/DispersionFunction.h"
#include "../lib/Dispersion/ModuleDispersion.h"
#include "../lib/Dispersion/SumDispersion.h"
#include "../lib/Dispersion/PseudoRandomDispersion.h"
#include "../lib/Exploration/ExplorationFunction.h"
#include "../lib/Exploration/LinearExploration.h"
#include "../lib/Exploration/QuadraticExploration.h"
#include "../lib/Exploration/RehashingExploration.h"
#include "../lib/Exploration/DoubleHashingExploration.h"
#include "../lib//Sequence/Sequence.h"
#include "../lib/Sequence/DynamicSequence.h"
#include "../lib/Sequence/StaticSequence.h"
#include "../lib//Tools/tools.h"
#include "../lib/HashTable/HashTable.h"
#include "../lib/NIF/NIF.h"
#include <string>

int main(int argc, char* argv[]) {
  NIF dni;
  Options options = ParseArguments(argc, argv);
  // Creamos el objeto de la función de dispersión
  DispersionFunction<NIF>* dispersionFunction = nullptr;
  if (options.dispersionFunction == "mod") {
    dispersionFunction = new ModuleDispersion<NIF>(options.tableSize);
  } else if (options.dispersionFunction == "sum") {
    dispersionFunction = new SumDispersion<NIF>(options.tableSize);
  } else if (options.dispersionFunction == "random") {
    dispersionFunction = new PseudorandomDispersion<NIF>(options.tableSize);
  } else {
    throw std::invalid_argument("Función de dispersión desconocida");
  }
  // Creamos el objeto de la función de exploración (opcional)
  ExplorationFunction<NIF>* explorationFunction = nullptr;
  if (!options.explorationFunction.empty()) {
    if (options.explorationFunction == "lineal") {
      explorationFunction = new LinearExploration<NIF>();
    } else if (options.explorationFunction == "quadratic") {
      explorationFunction = new QuadraticExploration<NIF>();
    } else if (options.explorationFunction == "doubleHashing") {
      explorationFunction = new DoubleHashingExploration<NIF>(*dispersionFunction);
    } else if (options.explorationFunction == "rehashing") {
      explorationFunction = new RehashingExploration<NIF>();
    } else {
      throw std::invalid_argument("Función de exploración desconocida");
    }
  } 
  
  
  // ModuleDispersion<NIF> disp(100);
  // QuadraticExploration<NIF> expl;
  HashTable<NIF, StaticSequence<NIF>> tabla(options.tableSize, *dispersionFunction, *explorationFunction, options.blockSize);
  NIF input;
  while (std::cin >> input) {
    std::cout << tabla.insert(input) << std::endl;
  }
  return 0;
}
