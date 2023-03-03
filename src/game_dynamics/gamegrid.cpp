#include "../../include/game_dynamics/gamegrid.h"
#include "../../include/game_dynamics/coordinates.h"
GameGrid::GameGrid(){
    for (size_t i = 0; i < kGridSize; i++)
    {
        for (size_t j = 0; j < kGridSize; j++)
        {
            grid[i][j] = nullptr;
        }
        
    }
    
}
bool GameGrid::validBoatCoordinates(Coord begin, Coord end){
    bool isVertical = begin.i() != end.i();
    int fixed_val, index, size;
    if(isVertical){
        fixed_val = begin.j();
        index = begin.i();
        size = end.i() - begin.i();
    }else{
        fixed_val = begin.i();
        index = begin.j();
        size = end.j() - begin.j();
    }
    for(int i = 0; i < size; i++){
        if(index + i >= kGridSize) return false;
        if(isVertical){
            if( grid[index + i][fixed_val] != nullptr ) return false;
        }else{
            if( grid[fixed_val][index + i] != nullptr) return false;
        }
    }
    return true;
}