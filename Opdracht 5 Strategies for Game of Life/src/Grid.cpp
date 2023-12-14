#include "Grid.h"

Grid::Grid(int width, int height, std::unique_ptr<Strategy> strategy) :
	width(width), height(height), matrix(width, std::vector<int>(height)), strategy(std::move(strategy))
{}

std::vector<std::vector<int>>& Grid::GetMatrix()
{
	return matrix;
}

std::vector<int> Grid::GetNeighbouringValues(int x, int y) const
{
	return std::vector<int>();
}

void Grid::CalculateWithStrategy(Grid* grid)
{
	strategy->CalculateGrid(grid);
}
