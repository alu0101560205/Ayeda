#include "FactoryCell.h"

class FactoryCellLife51_346 : public FactoryCell {
  Cell* createCell(const State& state, Position* position) {
    return new CellLife51_346(state, position);
  }
};