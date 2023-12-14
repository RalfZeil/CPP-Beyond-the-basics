#pragma once
#include "Strategy.h"

class ConwaysGameOfLife : public Strategy
{
public:
    void CalculateGrid(Grid* _grid) override;
};

