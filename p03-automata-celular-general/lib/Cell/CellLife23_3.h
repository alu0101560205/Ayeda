#include "CellLife.h"

class CellLife23_3 : public CellLife {
  CellLife23_3(const State& state, Position* position) : CellLife(state, position) {}
  void nextState(Lattice&);
};