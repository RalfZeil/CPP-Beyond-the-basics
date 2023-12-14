#pragma once
#include "Grid.h"

class Grid;

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual void CalculateGrid(Grid* _grid) = 0;
};

