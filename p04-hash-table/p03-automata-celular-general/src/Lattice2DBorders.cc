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
  expandMatrix();
  // Reemplazamos el tablero actual con la nueva generación
  board_ = next_gen;
}

/**
 * @brief Método para expandir la matriz en caso de que haya una
 * célula viva en el borde del tablero.
*/
void Lattice2DNoBorder::expandMatrix() {
  int counter{0}; // Modificación
  bool exp_arriba{false}, exp_abajo{false}, exp_izq{false}, exp_der{false};
  for (int i = 0; i < rows_; i++) { // Valoramos si expandir columnas
    if (board_[i][0]->getState() == 1 || board_[i][1]->getState() == 1) { // Lateral inzquierdo de la matriz
      exp_izq = true;
      counter++;
    } else if (board_[i][cols_ - 1]->getState() == 1 || board_[i][cols_ - 2]->getState() == 1) { // Lateral derecho de la matriz
      exp_der = true;
      counter++;
    }
  }
  for (int j = 0; j < cols_; j++) { // Valoramos si expandir filas
    if (board_[0][j]->getState() == 1 || board_[1][j]->getState() == 1) { // Borde superior
      exp_arriba = true;
      counter++;
    } else if (board_[rows_ - 1][j]->getState() == 1 || board_[rows_ - 2][j]->getState() == 1) { // Borde inferior
      exp_abajo = true;
      counter++;
    }
  }
  for (int count{1}; count <= counter; count++) { // Modificación
    // Agregamos filas y/o columnas
    if (exp_arriba) { // Agregar fila arriba
      std::vector<Cell*> new_row1(cols_, nullptr);
      board_.emplace(board_.begin(), new_row1); // Agregamos fila 
      rows_++; // Incrementar el número de filas
      neg_rows_++;
      for (int i = 0; i < cols_; i++) {
        board_[0][i] = new Cell({-neg_rows_, i - neg_cols_});
      }
    }
    if (exp_abajo) {
      std::vector<Cell*> new_row2(cols_, nullptr); // Creamos nueva fila
      board_.push_back(new_row2);
      rows_++;
      for (int i = 0; i < cols_; i++) {
        board_[rows_ - 1][i] = new Cell({((rows_ - 1) - neg_rows_), i - neg_cols_});
      }
    }
    if (exp_der) {
      for (int i = 0; i < rows_; i++) {
          board_[i].push_back(new Cell({i - neg_rows_, (cols_ - 1) - neg_cols_})); // Agrega una nueva célula al final de cada fila
      }
      ++cols_;
    }
    if (exp_izq) {
      ++cols_;
      neg_cols_++;
      for (int i = 0; i < rows_; i++) {
          board_[i].emplace(board_[i].begin(), new Cell({i - neg_rows_, -neg_cols_})); // Inserta una nueva célula al principio de cada fila
      }
    }
  }
}