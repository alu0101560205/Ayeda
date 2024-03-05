#include "FactoryCell.h"

class FactoryCellLife23_3 : public FactoryCell {
  public:
    Cell* createCell(const State& state, Position* position) {
      return new CellLife23_3(state, position);
    }
};