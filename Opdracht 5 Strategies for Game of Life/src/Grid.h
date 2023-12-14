#pragma once
#include <vector>
#include <memory>
#include "Strategy.h"

class Strategy;

class Grid
{
private:
	std::vector<std::vector<int>> matrix;
	std::unique_ptr<Strategy> strategy;

public:
	int width = 25;
	int height = 25;

	Grid(int width, int height, std::unique_ptr<Strategy> strategy);
	std::vector<std::vector<int>>& GetMatrix();
	std::vector<int> GetNeighbouringValues(int x, int y) const;
	void CalculateWithStrategy(Grid* grid);
};

