#if !defined(BOAT_H)
#define BOAT_H

#include <vector>
#include <string>
#include <memory>

class BoatPart;
class GameGrid;
class Boat{
    public:
        BoatPart* operator[](int i){return boat_parts_[i].get();}
        virtual bool action (int i, int j, GameGrid* attacker, GameGrid* defender) = 0;
        int dimension(){return boat_parts_.size();};
        std::string symbol(){return symbol_;}
    protected:
        Boat(int size);
    private:

        std::string symbol_;
        std::vector<std::unique_ptr<BoatPart>> boat_parts_;
};

#endif // BOAT_H
