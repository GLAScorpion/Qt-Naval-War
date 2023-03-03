#include "../../include/game_dynamics/boat.h"
#include "../../include/game_dynamics/boatpart.h"
#include <memory>

Boat::Boat(int size){
    for(int i = 0; i < size; i++) boat_parts_.push_back(std::unique_ptr<BoatPart>{new BoatPart});
}