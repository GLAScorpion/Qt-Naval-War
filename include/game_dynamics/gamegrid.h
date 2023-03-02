#if !defined(GAMEGRID_H)
#define GAMEGRID_H
#include <vector>
#include <memory>
class BoatPart;
class Boat;
constexpr int kGridSize = 12;
class GameGrid{
    public:
        GameGrid();
        void deleteBoat(BoatPart* part);
    private:
        BoatPart* grid[kGridSize][kGridSize];
        //std::vector<std::unique_ptr<Boat>> boats_;
};

#endif // GAMEGRID_H
