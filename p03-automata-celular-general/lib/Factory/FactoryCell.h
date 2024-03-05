#ifndef FACTORYCELL_H
#define FACTORYCELL_H
#include "Cell.h"

class FactoryCell {
  public:
    virtual Cell* createCell(Position* position, const State& state) const = 0;
};

#endif //FACTORYCELL_H