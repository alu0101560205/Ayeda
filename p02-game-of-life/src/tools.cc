/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 27 2024
  */

#include "../lib/tools.h"

/**
 * @brief Función para mostrar un mensaje de ayuda
*/
void Usage() {
  std::cout << "Uso: ./game -size <M> <N> [-init <file>] -border <b>" << std::endl;
  std::cout << "  -size <M> <N>: Especifica el tamaño del tablero (M filas x N columnas)." << std::endl;
  std::cout << "  -init <file>: (Opcional) Nombre del archivo que contiene el estado inicial del tablero." << std::endl;
  std::cout << "  -border <b>: Especifica el tipo de borde (reflective o noborder)." << std::endl;
}

/**
 * @brief Función para gestionar los argumentos por línea de comandos
*/
ProgramArguments ParseArguments(int argc, char* argv[]) {
  ProgramArguments arguments;
  // bool size_arg = false;
  if (argc < 5) {
    std::cerr << "Error: Argumentos insuficientes." << std::endl;
    Usage();
  }
  // Procesamos los argumentos
  for (int i = 1; i < argc; i++) {
    std::string actual_arg = argv[i];
    if (actual_arg == "-size" && ((i + 2) < argc)) {
      arguments.parse_rows = std::stoi(argv [i + 1]);
      arguments.parse_cols = std::stoi(argv[i + 2]);
      // size_arg = true;
      i += 2;
    } else if (actual_arg == "-init" && (i + 1 < argc)) {
      arguments.init_file = argv[i + 1];
      i++;
    } else if (actual_arg == "-border" && (i + 1 < argc)) {
      arguments.border_type = argv[i + 1];
      i++;
    } else {
      std::cerr << "Error: Argumento no reconocido " << actual_arg << std::endl;
      Usage();
    }
  }
  if (arguments.parse_rows == 0 || arguments.parse_cols == 0 || arguments.border_type.empty()) {
    if (arguments.init_file == "") {
      std::cerr << "Error: Especifica un tamaño válido para el tablero (-size) y un tipo de borde (-border)." << std::endl;
    }
  }
  return arguments;
}

/**
 * @brief Opciones de las letras
*/
void UsoLetras() {
  std::cout << "El caracter 'x' finaliza el programa" << std::endl;
  std::cout << "El caracter 'n' calcula y muestra la siguiente generación" << std::endl;
  std::cout << "El caracter 'L' calcula y muestra las siguinetes cinco generaciones" << std::endl;
  std::cout << "El caracter 'c' deja de mostrar el tablero y muestra la población" << std::endl;
  std::cout << "El caracter 's' salva el tablero en un fichero" << std::endl;
}