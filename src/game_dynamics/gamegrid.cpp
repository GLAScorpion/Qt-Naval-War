#include "../../include/game_dynamics/gamegrid.h"
#include "../../include/game_dynamics/coordinates.h"
#include "../../include/game_dynamics/boat.h"
#include "../../include/game_dynamics/boatpart.h"
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

BoatPart* GameGrid::getBoatPart(Coord pos){
    if(pos.i() >= kGridSize or pos.i() < 0) return nullptr;
    if(pos.j() >= kGridSize or pos.j() < 0) return nullptr;
    return grid[pos.i()][pos.j()];
}

bool GameGrid::setBoat(Coord begin, Coord end, Boat* boat){
    if(!validBoatCoordinates(begin,end)) return false;
    boat->setVertical(begin.i() != end.i());
    int fixed_val, index, size;
    if(boat->isVertical()){
        fixed_val = begin.j();
        index = begin.i();
        size = end.i() - begin.i();
    }else{
        fixed_val = begin.i();
        index = begin.j();
        size = end.j() - begin.j();
    }
    for (size_t i = 0; i < boat->dimension(); i++)
    {
        if(boat->isVertical()){
            grid[index + i][fixed_val] = boat->at(i);
            if(i == boat->dimension()/2) boat->setCenter(Coord(index + i, fixed_val));
        }else{
            grid[fixed_val][index + i] = boat->at(i);
            if(i == boat->dimension()/2) boat->setCenter(Coord(fixed_val, index + i));
        }
    }
    return true;
}

bool GameGrid::move(Coord origin, Coord dest){
    Boat* boat = grid[origin.i()][origin.j()]->masterBoat();
}