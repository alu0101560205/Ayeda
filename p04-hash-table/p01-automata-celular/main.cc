/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file main.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#include <unistd.h>
#include "cell.h"
#include "lattice.h"
#include "tools.h"

int main(int argc, char* argv[]) {
  usage();
  Arguments arguments = parseArguments(argc, argv);
  // Mostramos los argumentos parseados
  std::cout << "Size: " << arguments.size << std::endl;
  std::cout << "Border: " << (arguments.isPeriodic ? "periodic" : (arguments.isOpenHot ? "OpenHot" : "OpenCold")) << std::endl;
  std::cout << "File: " << arguments.file << std::endl;
  std::cout << "----------------------------------------------------------------------------" << std::endl;

  const int lattice_size = arguments.size; // Definimos el tamaño del reticulo
  Lattice lattice(lattice_size); // Creamos un retículo de dicho tamaño
  if (arguments.isPeriodic) {
    lattice.setBorderType(Border::Periodic);
  } else {
    if (arguments.isOpenHot) {
      lattice.setBorderType(Border::OpenHot);
    } else {
      lattice.setBorderType(Border::OpenCold);
    }
  }
  if (!arguments.file.empty()) {
    lattice.initFile(arguments.file); 
  } else {
    lattice.InitialConfiguration();
  }

  // lattice.InitialConfiguration(); // Lo inicializamos
  char entrada = ' ';
  std::cout << "Escriba cualquier caracter para comenzar, o el carácter 'q' para salir" << std::endl;
  while (std::cin >> entrada) {
    if (entrada == 'q') {
      return 1;
    }
    for (int i = 0; i <= 20; i++) {
      std::cout << lattice << std::endl;
      usleep(50000);
      lattice.nextGeneration();
    }
    std::cout << "Si desea continuar presione cualquier tecla, de lo contrario pulse q" << std::endl;
  }
  return 0;
}