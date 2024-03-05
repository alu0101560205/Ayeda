#include "CellLife.h"

class CellLife51_346 : public CellLife {
  CellLife51_346(const State& state, Position* position) : CellLife(state, position) {}
  void nextState(Lattice&);
};