#include "CellACE.h"

class CellACE30 : public CellACE {
  public:
    CellACE30 (const State& state, Position* position) : CellACE(state, position) {}
    virtual void nextState (const Lattice& lattice);
};