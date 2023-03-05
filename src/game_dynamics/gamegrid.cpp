#include "../../include/game_dynamics/gamegrid.h"
#include "../../include/game_dynamics/coordinates.h"
#include "../../include/game_dynamics/boat.h"
#include "../../include/game_dynamics/boatpart.h"
#include <iostream>

GameGrid::GameGrid(){
    for (size_t i = 0; i < kGridSize; i++)
    {
        for (size_t j = 0; j < kGridSize; j++)
        {
            grid[i][j] = nullptr;
            attack_grid_[i][j] = (int)AttackGridStatus::Water;
        }   
    }
}

std::vector<Coord> GameGrid::deleteBoat(BoatPart* part){
    Boat* boat = part->masterBoat();
    Coord origin = boat->center();
    int range = boat->dimension()/2;
    std::vector<Coord> output;
    for(int i = 0; i < (1 + range);i++){

        if(boat->isVertical()){
            grid[origin.i() + i][origin.j()] = nullptr;
            grid[origin.i() - i][origin.j()] = nullptr;
        }else{
            grid[origin.i()][origin.j() + i] = nullptr;
            grid[origin.i()][origin.j() - i] = nullptr;
        }
    }
    if(boat->isVertical()) {
        output.push_back(Coord(origin.i() - range, origin.j()));
        output.push_back(Coord(origin.i() + range, origin.j()));
    }else{
        output.push_back(Coord(origin.i(), origin.j() - range));
        output.push_back(Coord(origin.i(), origin.j() + range));
    }
    //std::cerr<<output[0].i()<<" "<<output[0].j()<<" "<<output[1].i()<<" "<<output[1].j()<<std::endl;
    delete boat;
    return output;
}

bool GameGrid::validBoatCoordinates(Coord begin, Coord end){
    if(begin.i() < 0 or begin.j() < 0 or end.i() < 0 or end.j() < 0)return false;
    bool isVertical = begin.i() != end.i();
    int fixed_val, index, size;
    if(isVertical){
        fixed_val = begin.j();
        index = begin.i();
        size = end.i() - begin.i() + 1;
    }else{
        fixed_val = begin.i();
        index = begin.j();
        size = end.j() - begin.j() + 1;
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
    int radius = boat->dimension()/2;
    Coord begin;
    Coord end;
    if(boat->isVertical()){
        begin = Coord(dest.i() - radius,dest.j());
        end = Coord(dest.i() + radius,dest.j());
    }else{
        begin = Coord(dest.i(),dest.j() - radius);
        end = Coord(dest.i(),dest.j() + radius);
    }
    if(!validBoatCoordinates(begin,end)) return false;
    for(int i = 0; i < (1 + radius);i++){
        if(boat->isVertical()){
            grid[origin.i() + i][origin.j()] = nullptr;
            grid[origin.i() - i][origin.j()] = nullptr;
        }else{
            grid[origin.i()][origin.j() + i] = nullptr;
            grid[origin.i()][origin.j() - i] = nullptr;
        }
    }
    return setBoat(begin , end, boat);
}

std::string GameGrid::print(){
    std::string out;
    for(int i = 0; i < kGridSize;i++){
        for(int j = 0; j < kGridSize; j++){
            if(grid[i][j]) out += 'X';
            else out += 'w';
        }
        out += '\n';
    }
    return out;
}