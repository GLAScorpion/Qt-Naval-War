#include "../../include/game_dynamics/gamegrid.h"
GameGrid::GameGrid(){
    for (size_t i = 0; i < kGridSize; i++)
    {
        for (size_t j = 0; j < kGridSize; j++)
        {
            grid[i][j] = nullptr;
        }
        
    }
    
}