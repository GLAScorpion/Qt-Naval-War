#if !defined(GAMEGRID_H)
#define GAMEGRID_H

#include "coordinates.h"
#include <vector>
#include <memory>
class BoatPart;
class Boat;
constexpr int kGridSize = 12;

enum class AttackGridStatus{
    Water = 0 , Hit , Miss, Detection
};
class GameGrid{
    public:
        GameGrid();
        std::vector<Coord> deleteBoat(BoatPart* part);
        std::vector<Coord> deleteBoat(int i, int j){return deleteBoat(grid[i][j]);}
        bool validBoatCoordinates(Coord begin, Coord end);
        BoatPart* getBoatPart(Coord pos);
        bool setBoat(Coord begin, Coord end, Boat* boat);
        bool move(Coord origin, Coord dest);
        void setAttackGridCell(Coord pos, AttackGridStatus status){attack_grid_[pos.i()][pos.j()] = (int)status;}
        std::string print();
    private:
        BoatPart* grid[kGridSize][kGridSize];
        int attack_grid_[kGridSize][kGridSize];
        //std::vector<std::unique_ptr<Boat>> boats_;
};

#endif // GAMEGRID_H
