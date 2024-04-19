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
    // Crea una instancia de ArbolBinarioEquilibrado
    ABE<int> arbol;

    // Inserta algunos elementos en el árbol
    arbol.insertar(10);
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(18);

    // Muestra los elementos en orden o realiza otras pruebas
    std::cout << arbol;
    std::cout << std::endl;
    // Puedes agregar un método en la clase ArbolBinarioEquilibrado para imprimir el árbol o verificar su equilibrio

    // Aquí puedes agregar más pruebas según tus necesidades

    return 0;
}