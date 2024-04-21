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

int main() {

    ABE<int> arbol;
    ABB<int> arbolbusqueda;

    // Inserta algunos elementos en el árbol
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(18);
    
    std::cout << "Árbol binario equilibrado\n";
    std::cout << arbol;
    std::cout << std::endl;

    std::cout << "Recorrido inorden:\n";
    arbol.inorden();
    std::cout << std::endl;

    std::cout << "Búsqueda del elemento 8 en el árbol: ";
    std::cout << arbol.buscar(8) << std::endl << std::endl;

    std::cout << "Arbol binario de búsqueda\n";
    arbolbusqueda.insertar(10);
    arbolbusqueda.insertar(8);
    arbolbusqueda.insertar(2);
    arbolbusqueda.insertar(15);
    arbolbusqueda.insertar(14);
    arbolbusqueda.insertar(3);
    arbolbusqueda.insertar(12);
    
    std::cout << arbolbusqueda << std::endl;
    std::cout << "Búsqueda del elemento 12 en el árbol: ";
    std::cout << arbol.buscar(12) << std::endl;

    return 0;
}