#if !defined(GAMEGRID_H)
#define GAMEGRID_H

#include "coordinates.h"
#include <vector>
#include <memory>
class BoatPart;
class Boat;
constexpr int kGridSize = 12;
class GameGrid{
    public:
        GameGrid();
        void deleteBoat(BoatPart* part);
        bool validBoatCoordinates(Coord begin, Coord end);
        BoatPart* getBoatPart(Coord pos);
        bool setBoat(Coord begin, Coord end, Boat* boat);
        bool move(Coord origin, Coord dest);
    private:
        BoatPart* grid[kGridSize][kGridSize];
        //std::vector<std::unique_ptr<Boat>> boats_;
};

#endif // GAMEGRID_H
