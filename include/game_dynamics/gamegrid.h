#if !defined(GAMEGRID_H)
#define GAMEGRID_H
class boat_part;
constexpr int kGridSize = 12;
class GameGrid{
    public:
    private:
        boat_part* grid[kGridSize][kGridSize];
};

#endif // GAMEGRID_H
