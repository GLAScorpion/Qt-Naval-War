#if !defined(BOAT_H)
#define BOAT_H

#include "coordinates.h"
#include <vector>
#include <string>
#include <memory>

class BoatPart;
class GameGrid;
class Boat{
    public:
        BoatPart* at(int i){return boat_parts_[i].get();}
        virtual bool action (Coord target, GameGrid* attacker, GameGrid* defender) = 0;
        int dimension(){return boat_parts_.size();};
        std::string symbol(){return symbol_;}
        void setCenter(Coord center){center_ = center;}
        void setVertical(bool vert = true){is_vertical_ = vert;}
        bool isVertical(){return is_vertical_;}
        Coord center(){return center_;}
        virtual void heal();
        bool isBroken();
    protected:
        Boat(int size);
    private:
        bool is_vertical_ = false;
        Coord center_;
        std::string symbol_;
        std::vector<std::unique_ptr<BoatPart>> boat_parts_;
};

#endif // BOAT_H
