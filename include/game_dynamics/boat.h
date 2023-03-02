#if !defined(BOAT_H)
#define BOAT_H

#include <vector>
#include <string>
#include <memory>

class BoatPart;
class GameGrid;
class Boat{
    public:
        virtual bool action (int i, int j, GameGrid* attacker, GameGrid* defender) = 0;
        int dimension(){return boat_parts_.size();};
    protected:
        Boat();
    private:

        std::string symbol_;
        std::vector<std::unique_ptr<BoatPart>> boat_parts_;
};

#endif // BOAT_H
