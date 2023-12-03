#include "Grid.h"

Grid::Grid(int width, int height) : width(width), height(height), matrix(width, std::vector<int>(height))
{}
