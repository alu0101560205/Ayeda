/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file Lattice2DBorders.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Mar 06 2024
  */

#include "../lib/Lattice/Lattice2DBorders.h"

/**
 * @brief Método para acceder a la célula, en reflective
*/
Cell& Lattice2DReflective::getCell(Position* pos) const {
  // Obtenemos las coordenadas de la posición
  int row = pos->operator[](0);
  int col = pos->operator[](1);

  // Manejamos los casos de reflexión en los bordes
  if (row < 0) row = 0;
  if (row >= getRows()) row = getRows() - 1;
  if (col < 0) col = 0;
  if (col >= getCols()) col = getCols() - 1;

  // Devolvemos la célula en la posición ajustada
  return *board_[row][col];
}

/**
 * @brief Siguiente generación en reflective
*/
void Lattice2DReflective::nextGeneration() {
  // Creamos una nueva matriz de células para la siguiente generación
  std::vector<std::vector<Cell*>> next_gen(getRows(), std::vector<Cell*>(getCols(), nullptr));

  // Iteramos sobre todas las células del tablero
  for (int i = 0; i < getRows(); ++i) {
    for (int j = 0; j < getCols(); ++j) {
      // Obtenemos la célula actual
      Cell& current_cell = getCell(new PositionDim<2>(i, j));
      // Calculamos el nuevo estado de la célula y lo actualizamos
      current_cell.nextState(*this);
      current_cell.updateState();
      next_gen[i][j] = &current_cell; // Asignamos la célula actualizada a la siguiente generación
    }
  }
  // Reemplazamos el tablero actual con la nueva generación
  board_ = next_gen;
}

/**
 * @brief Método getCell en NoBorder
*/
Cell& Lattice2DNoBorder::getCell(Position* pos) const {
  // Convertimos la posición a una PositionDim<2>
  PositionDim<2>* position_dim = dynamic_cast<PositionDim<2>*>(pos);
  if (!position_dim) {
    throw std::invalid_argument("Invalid position type");
  }
  // Obtenemos las coordenadas de la posición
  int row = (*position_dim)[0];
  int col = (*position_dim)[1];

  // Devolvemos la célula en la posición sin modificar
  return *board_[row][col];
}

/**
 * @brief Siguiente generación en NoBorder
*/
void Lattice2DNoBorder::nextGeneration() {
  // Creamos una nueva matriz de células para la siguiente generación
  std::vector<std::vector<Cell*>> next_gen(getRows(), std::vector<Cell*>(getCols(), nullptr));

  // Iteramos sobre todas las células del tablero
  for (int i = 0; i < getRows(); ++i) {
    for (int j = 0; j < getCols(); ++j) {
      Cell& current_cell = getCell(new PositionDim<2>(i, j));
      // Calculamos el nuevo estado de la célula y lo actualizamos
      current_cell.nextState(*this);
      current_cell.updateState();
      // Asignamos la célula actualizada a la siguiente generación
      next_gen[i][j] = &current_cell;
    }
  }
  // Reemplazamos el tablero actual con la nueva generación
  board_ = next_gen;
}