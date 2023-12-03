#pragma once
#include <vector>

class Grid
{
private:
	int width = 25;
	int height = 25;

	std::vector<std::vector<int>> matrix;

public:
	Grid(int width, int height);
};

