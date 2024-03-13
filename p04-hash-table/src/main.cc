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
#include "../lib/Exploration/ExplorationFunction.h"
#include "../lib//Sequence/Sequence.h"
#include "../lib//Tools/tools.h"
#include "../lib//NIF/NIF.h"

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
  // Creamos tabla Hash
  size_t size = options.tableSize;
  */
    // Tamaño de la tabla hash (puedes ajustarlo según tus necesidades)
    unsigned int tableSize = 100;

    // Instancia de ModuleDispersion con tamaño de tabla
    ModuleDispersion<int> moduleHash(tableSize);

    // Instancia de SumDispersion con tamaño de tabla
    SumDispersion<std::string> sumHash(tableSize);

    // Ejemplo de uso: calcular la posición para una clave
    int key1 = 42;
    std::string key2 = "hello";

    unsigned position1 = moduleHash(key1);
    unsigned position2 = sumHash(key2);

    // Imprime las posiciones calculadas
    std::cout << "Posición para key1: " << position1 << std::endl;
    std::cout << "Posición para key2: " << position2 << std::endl;

    return 0;
}