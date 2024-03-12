/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Algoritmos y Estructuras de Datos Avanzada
  *
  * @file lattice.cc
  * @author Estela Fernández Trujillo alu0101560205@ull.edu.es
  * @date Feb 26 2024
  */

#include "../lib/lattice.h"

/**
 * @brief Constructor de la clase Lattice que crea las células
 * en memoria dinámica
*/
Lattice::Lattice(int row, int col, const Border& border) : rows_(row), cols_(col), type_of_border_(border) {
  // Inicializamos el tablero con punteros nulos
  board_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    board_[i].resize(cols_);
    // for (int j = 0; j < cols_; j++) {
    //   board_[i][j] = nullptr;
    // }
  }
  // Creamos las células en memoria dinámica y las agregamos al tablero
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      Position pos(i, j); // Posición de la célula en el tablero
      State state = 0; // Estado inicial a muerta
      board_[i][j] = new Cell(pos, state); // Creamos la nueva célula y la agregamos al tablero
    }
  }
}

/**
 * @brief Constructor para inicializar el tablero desde un fichero que
 * contenga el número de filas (M) y columnas (N), seguido de las M cadenas
 * de N caracteres donde ' ' indica muerta y 'X' viva. 
*/
Lattice::Lattice(const char* filename, const Border& border) {
  type_of_border_ = border;
  std::ifstream file(filename); // Abrimos el archivo
  if (!file.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo");
  }
  // Leemos las dimensiones del tablero
  int rows{0}, cols{0};
  file >> rows >> cols;
  if (rows <= 0 || cols <= 0) { // Si las dimensiones son inválidas
    throw std::runtime_error("Dimensiones del tablero no válidas");
  }
  // Redimensionamos el tablero con las dimensiones especificadas
  rows_ = rows;
  cols_ = cols;
  board_.resize(rows_);
  for (int i = 0; i < rows_; i++) {
    board_[i].resize(cols_);
  }
  // Leemos los estados de las células del archivo
  char cellState;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      file >> cellState;
      if (cellState == 'X') {
        board_[i][j] = new Cell({i, j}, 1); // Nueva célula viva en la posición (i,j)
      } else if (cellState == '.') {
        board_[i][j] = new Cell({i, j}, 0); // Nueva cálula muerta en la posición (i,j)
      }
    }
  }
  file.close(); // Cerramos el archivo
}


/**
 * @brief Destructor de la clase Lattice
*/
Lattice::~Lattice() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      delete board_[i][j];
    }
  }
}

/**
 * @brief Método para saber el número de células vivas en el 
 * tablero en la generación actual
*/
std::size_t Lattice::Population() const {
  std::size_t population{0}; // Inicializamos la población a cero
  // Iteramos sobre las células del tablero
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (this[0][Position(i,j)].getState() == 1) { // Verificamos si la célula está viva
        population++; // Incrementamos población
      }
    }
  }
  return population; // Devolvemos el número total de células vivas
}

/**
 * @brief Sobrecarga del operador []
*/
Cell& Lattice::operator[](const Position& pos) {
  int row = pos.first; // Primer elemento del std::pair
  int col = pos.second; // Segundo elemento del std::pair
  return *board_[row][col]; // Devolvemos la célula en la posición especificada
}

/**
 * @brief Método para que el autómata evolucione
*/
void Lattice::nextGeneration() {
  // Calculamos el estado siguiente para cada célula en el tablero
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      // std::cout << "Mat " << this[0][Position(i, j)] << " "; 
        this[0][Position(i, j)].nextState(*this);
        //std::cout << "He llegado a después del nextstate\n";
    }
    // std::cout << "\n";
  }
  // Actualizamos el estado del tablero actual con el estado siguiente
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this[0][Position(i, j)].updateState();
    }
  }
  if (getBorder() == Border::noBorder) {
    std::cout << "Filas antes de expandir: " << getRows() << " columnas: " << getCols() << std::endl;
    this->expandMatrix();
    std::cout << "Filas después de expandir: " << getRows() << " columnas: " << getCols() << std::endl;
  }
}

/**
 * @brief Método para expandir la matriz en caso de que haya una
 * célula viva en el borde del tablero.
*/
void Lattice::expandMatrix() {
  bool exp_arriba{false}, exp_abajo{false}, exp_izq{false}, exp_der{false};
  for (int i = 0; i < rows_; i++) { // Valoramos si expandir columnas
    if (board_[i][0]->getState() == 1) { // Lateral inzquierdo de la matriz
      exp_izq = true;
    } else if (board_[i][cols_ - 1]->getState() == 1) { // Lateral derecho de la matriz
      exp_der = true;
    }
  }
  for (int j = 0; j < cols_; j++) { // Valoramos si expandir filas
    if (board_[0][j]->getState() == 1) { // Borde superior
      exp_arriba = true;
    } else if (board_[rows_ - 1][j]->getState() == 1) { // Borde inferior
      exp_abajo = true;
    }
  }
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

/**
 * @brief Sobrecraga del operador de salida para Lattice
*/
std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.getRows(); i++) {
    for (int j = 0; j < lattice.getCols(); j++) {
      if (lattice[{i, j}].getState() == 1) {
        os << 'X';
      } else {
        os << '.';
      }
    }
    os << std::endl;
  }
  return os;
}

/**
 * @brief Función para rellenar el tablero desde terminal cuando no
 * se le pasa un fichero. El tablero se inicializará a vacío y se colocarán
 * solo las células que se deseen vivas
*/
void Lattice::RellenarTablero() {
  while (true) {
    int fila, columna;
    std::cout << "Inserte una posición (si es negativa se detiene el bucle), mediante fila y y columna (i, j): ";
    std::cin >> fila >> columna;
    if (fila < 0 || columna < 0 || fila >= getCols() || fila >= getCols()) {
      break;
    }
    std::cout << "En la posición (" << fila << ", " << columna << ") se colocará una célula viva\n";
    this[0][Position(fila, columna)].setState(1);
  }
}