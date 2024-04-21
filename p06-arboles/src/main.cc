/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file main.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 17 2024
  */

#include "../lib/AB/AB.h"
#include "../lib/ABE/ABE.h"
#include "../lib/ABB/ABB.h"
#include "../lib/NodoB/NodoB.h"
#include "../lib/Tools/tools.h"
#include <random>
#include <fstream>

int main(int argc, char* argv[]) {
  Arguments args = ParseArguments(argc, argv);
  std::cout << "Tipo de árbol: " << (args.treeType == TreeType::ArbolBE ? "ABE" : "ABB") << "\n";
  std::cout << "Forma de inicialización: " << args.initType << "\n";
  if (args.initType == "random") {
    std::cout << "Número de elementos a generar: " << args.sequenceSize << "\n";
  } else if (args.initType == "file") {
    std::cout << "Número de elementos a leer: " << args.sequenceSize << "\n";
    std::cout << "Nombre del archivo: " << args.fileName << "\n";
  }
  
  AB<int>* tree = nullptr;
  if (args.treeType == TreeType::ArbolBE) {
    tree = new ABE<int>;
  } else if (args.treeType == TreeType::ArbolBB) {
    tree = new ABB<int>;
  }

  // En caso de que se desee generar números random
  if (args.initType == "random") {
    std::random_device rd; // Fuente de entropía del sistema
    std::mt19937 gen(rd()); // Generador de números aleatorios 
    std::uniform_int_distribution<int> dist(0, 20); // Rango de números enteros aleatorios
    for (int i = 0; i < args.sequenceSize; ++i) {
      int randomValue = dist(gen);
      tree->insertar(randomValue);
      std::cout << "Insertado: " << randomValue << std::endl;
    }
  }

  // En caso de que se desee hacer el árbol desde fichero
  if (args.initType == "file") {
    std::string filename = args.fileName;
    std::ifstream inputFile(filename); // Abrimos el archivo
    if (!inputFile.is_open()) {
      std::cerr << "Error: No se pudo abrir el archivo " << filename << std::endl;
      delete tree;
      return 1; // Salida con código de error
    }
    int value, count{0};
    while (inputFile >> value && count < args.sequenceSize) {
      tree->insertar(value);
      count++;
      std::cout << "Insertado: " << value << std::endl;
    }
    inputFile.close(); // Cerrar el archivo
  }

  int option;
  do {
    std::cout << "\n--- Menú ---\n";
    std::cout << "[0] Salir\n";
    std::cout << "[1] Insertar clave\n";
    std::cout << "[2] Buscar clave\n";
    std::cout << "[3] Mostrar árbol en inorden\n";
    std::cout << "[4] Mostrar árbol por niveles\n";
    std::cout << "Elige una opción: ";
    std::cin >> option;
    switch (option) {
      case 0:
        // Salir del programa
        break;
      case 1:
        // Insertar clave
        int keyToInsert;
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> keyToInsert;
        tree->insertar(keyToInsert);
        std::cout << *tree << std::endl;
        break;
      case 2:
        // Buscar clave
        int keyToSearch;
        std::cout << "Introduce la clave a buscar: ";
        std::cin >> keyToSearch;
        if (tree->buscar(keyToSearch)) {
          std::cout << "La clave " << keyToSearch << " fue encontrada en el árbol." << std::endl;
        } else {
          std::cout << "La clave " << keyToSearch << " no fue encontrada en el árbol." << std::endl;
        }
        break;
      case 3:
        // Mostrar árbol en orden
        tree->inorden();
        break;
      case 4:
        std::cout << *tree << std::endl;
      default:
        std::cout << "Opción no válida. Intenta de nuevo." << std::endl;
        break;
      }
  } while (option != 0);
  delete tree;
  return 0;
}