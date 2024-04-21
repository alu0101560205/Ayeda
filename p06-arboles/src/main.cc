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
#include "../lib/NodoB/NodoB.h"

int main() {

    ABE<int> arbol;

    // Inserta algunos elementos en el árbol
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(18);

    std::cout << arbol;
    std::cout << std::endl;

    std::cout << "Recorrido inorden:\n";
    arbol.inorden();
    std::cout << std::endl;

    std::cout << "Búsqueda del elemento 7 en el árbol: ";
    std::cout << arbol.buscar(8) << std::endl;

    // arbol.insertar(26);
    // arbol.insertar(87);
    // std::cout << arbol;
    // std::cout << "Recorrido inorden:\n";
    // arbol.inorden();
    // std::cout << std::endl;
    return 0;
}