/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.h
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 05 2024
  */

#include "../lib/Tools/tools.h"

/**
 * @brief Modo de uso del programa
*/
void Usage() {
  std::cout << "Modo de uso: ./orden -size <s> -ord <m> -init <i> [f] -trace <y|n>\n";
  std::cout << "s -> Tamaño de la secuencia\n";
  std::cout << "m -> Método de ordenación que se pretende usar, las opciones son:\n";
  std::cout << "     - select\n";
  std::cout << "     - quick\n";
  std::cout << "     - heap\n";
  std::cout << "     - shell\n";
  std::cout << "     - radix\n";
  std::cout << "i -> forma de introducir los datos (manual, random o file). En caso de file, adjuntar fichero\n";
  std::cout << "La opción trace nos permite mostrar la traza durante la ejecución\n";
}

/**
 * @brief Función para el paso de argumentos
*/
Arguments ParseArguments(int argc, char* argv[]) {
  Arguments arguments;
  if (argc < 8) {
    Usage();
    throw std::invalid_argument("No se han proporcionado argumentos obligatorios");
  }
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-size") {
      arguments.sizeOfSequence = std::stoi(argv[i + 1]);
      ++i;
    } else if (arg == "-ord") {
      arguments.typeSort = argv[i + 1];
      ++i;
    } else if (arg == "-init") {
      arguments.start = argv[i + 1];
      ++i;
      if (arguments.start == "file") {
        std::cout << "Entre al if\n";
        arguments.initFile = argv[i + 1];
        ++i;
      }
    } else if (arg == "-trace") {
      if (std::string(argv[i + 1]) == "y") {
        arguments.trace = true;
      }
      if (std::string(argv[i + 1]) == "n") {
        arguments.trace = false;
      }
      ++i;
    }
  }
  return arguments;
}
