/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#include "tools.h"
#include "cell.h"

/**
 * @brief Función que nos indica el modo de uso del programa
*/
void usage() {
  std::cout << "Práctica 1 - Algoritmos y Estructuras de Datos Avanzada" << std::endl;
  std::cout << "Estela Fernández Trujillo" << std::endl;
  std::cout << "Modo de uso: ./celular -size <n> -border <b [v] -init <file>" << std::endl;
  std::cout << "Parámetros: n -> tamaño del retículo" << std::endl;
  std::cout << "b -> open, periodic. En caso de open, v puede valer 0 (fria) o 1(caliente)" << std::endl;
  std::cout << "file -> fichero con array de estados con la configuración inicial" << std::endl << std::endl;
  std::cout << "----------------------------------------------------------------------------" << std::endl;
}

/**
 * @brief Función para el paso de argumentos por línea de comandos
*/

Arguments parseArguments(int argc, char* argv[]) {
  // Inicializamos los argumentos
  Arguments arguments; 
  arguments.size = 0;
  arguments.isPeriodic = false;
  arguments.isOpenHot = false;
  arguments.file = "";
  bool configurationFile = false;
  
  // Iteramos sobre los argumentos
  for (int i = 1; i < argc; i++) {
    std::string actual_arg = argv[i];
    if (actual_arg == "-size" && (i + 1 < argc)) {
      arguments.size = std::stoi(argv[++i]);
    } else if (actual_arg == "-border" && (i + 1 < argc)) {
      std::string border_type = argv[++i];
      if (border_type == "periodic") {
        arguments.isPeriodic = true;
      } else if (border_type == "open" && (i + 1 < argc)) {
        int cold_warm = std::stoi(argv[++i]);
        arguments.isOpenHot = (cold_warm == 1 ? true : false);
      }
    } else if (actual_arg == "-init" && (i + 1 < argc)) {
        arguments.file = (argv[++i]);
    }
  }
  return arguments;
}
