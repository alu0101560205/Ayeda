/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file lattice.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 12 2024
  */

#include "lattice.h"
#include <fstream>

/**
 * @brief Constructor de la clase Lattice
 * @param size_of_lattice, tamaño del reticulo
*/
Lattice::Lattice(const int size_of_lattice, const Border& border_type) {
  border_type_ = border_type;
  size_ = size_of_lattice;
  cells_ = new Cell*[size_];
  defaultPositions();
}

/**
 * @brief Posiciones por defecto
*/
void Lattice::defaultPositions() {
  for (int i = 0; i < size_; i++) {
     cells_[i] = new Cell(i); // A la vez que iteramos cargamos las posiciones
  }
}

/**
 * @brief Destructor de la clase Lattice
*/
Lattice::~Lattice() {
  for (int i = 0; i < size_; i++) {
    delete cells_[i];
  }
  delete cells_;
}

/**
 * @brief Método para acceder al tamaño de Lattice
*/
int Lattice::getSize() const {
  return size_;
}

/**
 * @brief Método para cargar la configuración general del autómata celular. 
 * Inicializa el estado de cada célula de la generación a cero, salvo en
 * la célula central del retículo, que tendrá valor de uno.
*/
void Lattice::InitialConfiguration() {
  cells_[size_ / 2]->setState(1);
}

/**
 * @brief Método para dar acceso a la lectura de las células en una posición dada
*/
const Cell& Lattice::getCell(const Position& position) const {
  return *cells_[position];
}

/**
 * @brief Método para asignar el tipo de borde
*/
void Lattice::setBorderType(Border border) {
  border_type_ = border;
}

/**
 * @brief Método para que el autómata evolucione
*/
void Lattice::nextGeneration() {
  Cell** next_state_lattice = new Cell*[size_];
  for (int i = 0; i < size_; i++) {
    next_state_lattice[i] = new Cell(*cells_[i]);
    next_state_lattice[i]->setState(cells_[i]->nextState(*this));
  }
  for (int i = 0; i < size_; i++) {
    cells_[i]->setState(next_state_lattice[i]->getState());
  }
  for (int i = 0; i < size_; i++) {
    delete next_state_lattice[i];
  }
  delete next_state_lattice;
}

/**
 * @brief Sobrecarga del operador de insercción en flujo
*/
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.getSize(); i++) {
    os << (lattice.cells_[i]->getState() == 1 ? 'X' : ' ');
  }
  return os;
}

/**
 * @brief Función para leer la configuración inicial mediante un archivo
*/
void Lattice::initFile(std::string file) {
  std::ifstream infile(file);
    if (!infile.is_open()) {
      std::cerr << "No se ha podido abrir el archivo" << std::endl;
    }
    int contador{0}, valor;
    while (infile >> valor && contador < getSize()) {
      cells_[contador]->setState(valor);
      contador++;
    }
    infile.close();
}