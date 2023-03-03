#if !defined(BATTLESHIP_H)
#define BATTLESHIP_H

#include "boat.h"
constexpr int kBattleshipDim = 5;
class Battleship : public Boat{
    public:
        bool action (int i, int j, GameGrid* attacker, GameGrid* defender) override;
        Battleship():Boat(kBattleshipDim){};
    private:

};

#endif // BATTLESHIP_H
