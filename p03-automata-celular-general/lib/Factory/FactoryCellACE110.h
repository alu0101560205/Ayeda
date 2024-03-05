#include "FactoryCell.h"

class FactoryCell110 : public FactoryCell {
  public:
    Cell* createCell(const State& state, Position* position) {
      return new CellACE110(state, position);
    }
};