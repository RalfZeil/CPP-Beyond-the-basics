#pragma once
#include "Strategy.h"

class Highlife : public Strategy
{
public:
    void CalculateGrid(Grid* _grid) override;
};

