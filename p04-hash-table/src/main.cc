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
#include "../lib/Exploration/ExplorationFunction.h"
#include "../lib/Exploration/LinearExploration.h"
#include "../lib/Exploration/QuadraticExploration.h"
#include "../lib//Sequence/Sequence.h"
#include "../lib/Sequence/DynamicSequence.h"
#include "../lib/Sequence/StaticSequence.h"
#include "../lib//Tools/tools.h"
#include "../lib//NIF/NIF.h"
#include "../lib/HashTable/HashTable.h"

int main(int argc, char* argv[]) {
  /*
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
  */
  std::cout << "Probando con secuencia estática:" << std::endl;
    ModuleDispersion<NIF> dispersionFunction(100);
    LinearExploration<NIF> explorationFunction;
    HashTable<NIF, StaticSequence<NIF>> staticHashTable(100, dispersionFunction, explorationFunction, 10);

    // Insertar elementos en la tabla estática
    staticHashTable.insert(NIF(12345678));
    staticHashTable.insert(NIF(87654321));
    staticHashTable.insert(NIF(55555555));

    // Buscar elementos en la tabla estática
    std::cout << "Buscando elemento '12345678': " << (staticHashTable.search(NIF(12345678)) ? "Encontrado" : "No encontrado") << std::endl;
    std::cout << "Buscando elemento '99999999': " << (staticHashTable.search(NIF(99999999)) ? "Encontrado" : "No encontrado") << std::endl;

    // // Prueba con tabla hash y secuencia dinámica
    // std::cout << "\nProbando con secuencia dinámica:" << std::endl;
    // SumDispersion<NIF> dispFunc(100);
    // HashTable<NIF, DynamicSequence<NIF>> dynamicHashTable(100, dispFunc);

    // // Insertar elementos en la tabla dinámica
    // dynamicHashTable.insert(NIF(12345678));
    // dynamicHashTable.insert(NIF(87654321));
    // dynamicHashTable.insert(NIF(55555555));

    // // Buscar elementos en la tabla dinámica
    // std::cout << "Buscando elemento '12345678': " << (dynamicHashTable.search(NIF(12345678)) ? "Encontrado" : "No encontrado") << std::endl;
    // std::cout << "Buscando elemento '99999999': " << (dynamicHashTable.search(NIF(99999999)) ? "Encontrado" : "No encontrado") << std::endl;

    return 0;
}


