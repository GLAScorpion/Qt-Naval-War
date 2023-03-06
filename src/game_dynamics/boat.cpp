#include "../../include/game_dynamics/boat.h"
#include "../../include/game_dynamics/boatpart.h"
#include <memory>
void Boat::heal(){
    for (size_t i = 0; i < boat_parts_.size(); i++)
    {
        boat_parts_[i]->setArmor(true);
    }
}

bool Boat::isBroken(){
    for (size_t i = 0; i < boat_parts_.size(); i++)
    {
        if(boat_parts_[i]->armor()) return false;
    }
    return true;
}

Boat::Boat(int size, std::string bSymbol, std::string cSymbol)
:symbol_broken{bSymbol},symbol_complete{cSymbol}
{
    for(int i = 0; i < size; i++) {
        boat_parts_.push_back(std::unique_ptr<BoatPart>{new BoatPart});
        boat_parts_[i]->setMaster(this);
    }
}

std::string& Boat::symbol(bool armor){
    if(armor){
        return symbol_complete;
    }else{
        return symbol_broken;
    }
}