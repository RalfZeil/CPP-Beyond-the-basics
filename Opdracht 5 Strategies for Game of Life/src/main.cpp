#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
#include "Grid.h"
#include "ConwaysGameOfLife.h"
#include "Highlife.h"
#include "RalfsDumbRules.h"

void PopulateGrid(Grid* _grid) 
{
    std::vector<std::vector<int>>& matrix = _grid->GetMatrix();

    for (auto& row : matrix)
    {
        for (int& elem : row)
        {
            elem = rand() % 2;
        }
    }
}

void RenderGrid(Grid* _grid)
{
    system("CLS");

    std::vector<std::vector<int>>& matrix = _grid->GetMatrix();

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (auto& row : matrix)
    {
        for (auto& elem : row)
        {
            if (elem == 1)
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);  // Set the color to green for 1's
                std::cout << elem << " ";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);  // Set the color to red for 0's
                std::cout << elem << " ";
            }
        }
        std::cout << std::endl;
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

int main()
{
    int renderIntervalInMiliSeconds = 250;

    // Enter your strategy in make_unqiue<HERE>
    // Options are ConwaysGameOfLife, Highlife or RalfsDumbRules
    Grid* grid = new Grid(25, 25, std::make_unique<RalfsDumbRules>());

    PopulateGrid(grid);

    while (true) 
    {
        grid->CalculateWithStrategy(grid);
        RenderGrid(grid);
        std::this_thread::sleep_for(std::chrono::milliseconds(renderIntervalInMiliSeconds));
    }

    delete grid;
}