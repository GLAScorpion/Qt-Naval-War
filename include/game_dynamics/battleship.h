#if !defined(BATTLESHIP_H)
#define BATTLESHIP_H

#include "coordinates.h"
#include "boat.h"
#include "gamegrid.h"
#include "boatpart.h"

constexpr int kBattleshipDim = 5;
const std::string kBrokenBattleship = "battleship_damaged.jpg";
const std::string kCompleteBattleship = "battleship.jpg";

class Battleship : public Boat{
    public:
        bool action (Coord target, GameGrid* attacker, GameGrid* defender) override{
            BoatPart* enemy_boat = defender->getBoatPart(target);
            if(!enemy_boat){
                attacker->setAttackGridCell(target,AttackGridStatus::Miss);
                return true;
            }
            enemy_boat->setArmor(false);
            attacker->setAttackGridCell(target,AttackGridStatus::Hit);
            if (enemy_boat->masterBoat()->isBroken()) defender->deleteBoat(enemy_boat);
            return true;
        }
        Battleship():Boat(kBattleshipDim,kBrokenBattleship,kCompleteBattleship){};
    private:

};

#endif // BATTLESHIP_H
