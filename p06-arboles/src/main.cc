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
#include "../lib/NIF/NIF.h"
#include <random>
#include <fstream>
#include <chrono>
#include <vector>

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
  
  AB<NIF>* tree = nullptr;
  if (args.treeType == TreeType::ArbolBE) {
    tree = new ABE<NIF>;
  } else if (args.treeType == TreeType::ArbolBB) {
    tree = new ABB<NIF>;
  }

  // En caso de que se desee generar números random
  if (args.initType == "random") {
    // std::random_device rd; // Fuente de entropía del sistema
    // std::mt19937 gen(rd()); // Generador de números aleatorios 
    // std::uniform_int_distribution<int> dist(0, 100); // Rango de números enteros aleatorios
    for (int i = 0; i < args.sequenceSize; ++i) {
      // int randomValue = dist(gen);
      // tree->insertar(randomValue);
      // std::cout << "Insertado: " << randomValue << std::endl;
      NIF randomValue = NIF();
      tree->insertar(randomValue);
      std::cout << "Insertado: " << randomValue.getOriginal() << std::endl;
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
    int count{0};
    NIF value;
    while (inputFile >> value && count < args.sequenceSize) {
      if (tree->insertar(value.getOriginal())) {
        count++;
        std::cout << "Insertado: " << value.getOriginal() << std::endl;
      } else {
        std::cerr << "Error al insertar el NIF: " << value.getOriginal() << std::endl;
      }
    }
    inputFile.close(); // Cerrar el archivo
  }
  ABB<NIF> arbolBusqueda; // Modificacion
  ABE<NIF> arbolEquilibrado; // Modificacion
  for (int i = 0; i < 10000; i++) { // Rellenamos los dos árboles
    NIF valor = NIF();
    arbolBusqueda.insertar(valor);
    NIF valor2 = NIF();
    arbolEquilibrado.insertar(valor2);
  }
  // vector con las claves a buscar
  std::vector<NIF> vector_claves = { NIF("31654782"), NIF("85142369"), NIF("10245803"), NIF("520130507"),
  NIF("40136958"), NIF("54102369"), NIF("98745632"), NIF("12345678"), NIF("45618216"), NIF("56842369")};
  int option;
  NIF keyToInsert;
  NIF keyToSearch;
  do {
    std::cout << "\n--- Menú ---\n";
    std::cout << "[0] Salir\n";
    std::cout << "[1] Insertar clave\n";
    std::cout << "[2] Buscar clave\n";
    std::cout << "[3] Mostrar árbol en inorden\n";
    std::cout << "[4] Mostrar árbol por niveles\n";
    std::cout << "[5] Modificación pedida\n";
    std::cout << "Elige una opción: ";
    std::cin >> option;
    switch (option) {
      case 0:
        // Salir del programa
        break;
      case 1:
        // Insertar clave
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> keyToInsert;
        tree->insertar(keyToInsert);
        std::cout << *tree << std::endl;
        break;
      case 2:
        // Buscar clave
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
        break;
      case 5:
        std::cout << "Tiempo de búsqueda de claves en el árbol de búsqueda" << std::endl;
        for (const NIF& clave : vector_claves) {
          auto start = std::chrono::high_resolution_clock::now(); // Tiempo de inicio
          bool encontrado = arbolBusqueda.buscar(clave); // Realiza la búsqueda
          auto end = std::chrono::high_resolution_clock::now(); // Tiempo de finalización
          std::chrono::duration<double> duracion = end - start;
          std::cout << "Buscar la clave " << clave.getValue() << " en el árbol de Busqueda tardó " << duracion.count() << " segundos." << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Tiempo de búsqueda de claves en el árbol equilibrado" << std::endl;
        for (const NIF& clave : vector_claves) {
          auto start = std::chrono::high_resolution_clock::now(); // Tiempo de inicio
          bool encontrado = arbolEquilibrado.buscar(clave); // Realiza la búsqueda
          auto end = std::chrono::high_resolution_clock::now(); // Tiempo de finalización
          std::chrono::duration<double> duracion = end - start;
          std::cout << "Buscar la clave " << clave.getValue() << " en el árbol Equlibrado tardó " << duracion.count() << " segundos." << std::endl;
        }
        std::cout << std::endl;
        break;
      default:
        std::cout << "Opción no válida. Intenta de nuevo." << std::endl;
        break;
      }
  } while (option != 0);
  delete tree;
  return 0;
}