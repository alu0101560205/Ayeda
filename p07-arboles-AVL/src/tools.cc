/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file tools.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date April 21 2024
  */

#include "../lib/Tools/tools.h"

/**
 * @brief Función para procesar los argumentos
*/
Arguments ParseArguments(int argc, char* argv[]) {
  Arguments args;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-ab" && (i + 1 < argc)) {
      std::string treeArg = argv[i + 1];
      if (treeArg == "abe") {
        args.treeType = TreeType::ArbolBE;
      } else if (treeArg == "abb") {
        args.treeType = TreeType::ArbolBB;
      } else if (treeArg == "avl") {
        args.treeType = TreeType::ArbolAVL;
      } else {
        std::cerr << "Error: opción inválida para -ab. Debe ser 'abe' , 'abb' o 'avl'\n";
        exit(EXIT_FAILURE);
      }
      i++;
    } else if (arg == "-init" && (i + 1 < argc)) {
      args.initType = argv[i + 1];
      i++;
      if (args.initType == "random" && i + 1 < argc) {
        args.sequenceSize = std::stoi(argv[i + 1]);
        i++;
      } else if (args.initType == "file" && i + 2 < argc) {
        args.sequenceSize = std::stoi(argv[i + 1]);
        args.fileName = argv[i + 2];
        i += 2;
      } else if (args.initType != "manual") {
        std::cerr << "Error: opción inválida para -init. Debe ser 'manual', 'random <s>', o 'file <s> <f>'.\n";
        exit(EXIT_FAILURE);
      }
    } else {
      std::cerr << "Opción no reconocida: " << arg << "\n";
      exit(EXIT_FAILURE);
    }
  }
  return args;
}