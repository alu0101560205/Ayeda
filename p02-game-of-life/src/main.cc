/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file main.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#include "../lib/cell.h"
#include "../lib/lattice.h"
#include "../lib/NoBorder.h"
#include "../lib/Reflective.h"
#include "../lib/tools.h"
#include "../lib/OpenHot.h"
#include "../lib/OpenCold.h"

int main (int argc, char* argv[]) {
  ProgramArguments args = ParseArguments(argc, argv);
  int new_rows, new_cols;
  if (args.init_file == "") {
    new_rows = args.parse_rows;
    new_cols = args.parse_cols;
  }
  Lattice* lattice;
  if (args.border_type == "noborder") {
    if (args.init_file == "") {
      lattice = new NoBorder(new_rows, new_cols, noBorder);
    } else {
      lattice = new NoBorder("input.txt", noBorder);
      std::cout << "Se ha creado un tablero NoBorder desde fichero" << std::endl;
    }
  } else if (args.border_type == "reflective") {
    if (args.init_file == "") {
      lattice = new Reflective(new_rows, new_cols, reflective);
      lattice->RellenarTablero();
    } else {
      lattice = new Reflective("input.txt", reflective);    
    }
  } else if (args.border_type == "openhot") {
    if (args.init_file == "") {
      lattice = new OpenHot(new_rows, new_cols, openHot);
      lattice->RellenarTablero();
    } else {
      lattice = new OpenHot("input.txt", openHot);    
    }
  } else if (args.border_type == "opencold") {
    if (args.init_file == "") {
      lattice = new OpenCold(new_rows, new_cols, openCold);
      lattice->RellenarTablero();
    } else {
      lattice = new OpenCold("input.txt", openCold);    
    }
  }
  // std::cout << lattice[0][Position(1,3)].vecindad(*lattice) << std::endl;
  // Usar los argumentos procesados
  std::cout << "Tamaño del tablero: " << lattice->getRows() << "x" << lattice->getCols() << std::endl;
  if (args.init_file != "") {
    std::cout << "Archivo de inicialización: " << args.init_file << std::endl;
  }
  std::cout << "Tipo de borde: " << args.border_type << std::endl;
  char entrada = ' ';
  bool mostrar_tablero = true;
  std::cout << "\nTablero inicial:\n" << *lattice << std::endl;
  UsoLetras();
  std::ofstream outfile("output.txt");
  while (std::cin >> entrada) {
    std::cout << std::endl;
    switch (entrada) {
    case 'x':
      return 0;
      break;
    case 'n':
      mostrar_tablero = true;
      if (mostrar_tablero) {
        std::cout << *lattice << std::endl;
      }
      lattice->nextGeneration();
      break;
    case 'L':
      mostrar_tablero = true;
      for (int i = 0; i < 5; i++) {
        if (mostrar_tablero) {
          std::cout << *lattice << std::endl;
        }
        lattice->nextGeneration();
      }
      break;
    case 'c':
      mostrar_tablero = false;
      std::cout << "La población en el tablero es: " << lattice->Population() << std::endl;
      break;
    case 's':
      std::cout << "El tablero se guardará en el fichero output.txt" << std::endl;
      outfile << *lattice << std::endl;
      outfile.close();
      break;
    default:
      std::cout << "Error, letra no reconocida " << std::endl;
      break;
    }
    std::cout << "Si desea continuar presione alguna de las teclas especificadas ";
  }
  return 0;
}