#include "FactoryCell.h"

class FactoryCellACE30 : public FactoryCell {
  public:
    Cell* createCell (const State& state, Position* position) const {
      return new CellACE30(state, position);
    }
};