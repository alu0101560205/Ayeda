#include "Cell.h"

class CellLife : public Cell {
  public:
    CellLife(const State& state, Position* position) : Cell(state, position) {}
    virtual void nextState(Lattice&) = 0;
  protected:
    int getNeighbors(Position* pos, Lattice& lattice);
};