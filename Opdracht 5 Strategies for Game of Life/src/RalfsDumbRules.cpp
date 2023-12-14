#include "RalfsDumbRules.h"

void RalfsDumbRules::CalculateGrid(Grid* _grid)
{
    std::vector<std::vector<int>>& matrix = _grid->GetMatrix();
    std::vector<std::vector<int>> newMatrix = matrix; // Copy the matrix to hold the new state

    // Directions for the neighbors
    std::vector<int> dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
    std::vector<int> dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; ++k)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[i].size() && matrix[x][y] == 1)
                {
                    ++liveNeighbors;
                }
            }

            // Apply conway's rules
            if (matrix[i][j] == 1 && (liveNeighbors < 3 || liveNeighbors > 4))
            {
                newMatrix[i][j] = 0;
            }
            else if (matrix[i][j] == 0 && (liveNeighbors == 3 || liveNeighbors == 4))
            {
                newMatrix[i][j] = 1;
            }
        }
    }

    matrix = newMatrix;
}
