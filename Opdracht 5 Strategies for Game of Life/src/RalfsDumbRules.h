#pragma once
#include "Strategy.h"

class RalfsDumbRules : public Strategy
{
public:
    void CalculateGrid(Grid* _grid) override;
};

