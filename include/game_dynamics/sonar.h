#if !defined(SONAR_H)
#define SONAR_H

#include "coordinates.h"
#include "boat.h"
#include "gamegrid.h"
#include "boatpart.h"

constexpr int kSonarDim = 1;
constexpr int kSonarRange = 5;
const std::string kBrokenSonar = "radar_damaged.jpg";
const std::string kCompleteSonar = "radar.jpg";
class Sonar : public Boat{
    public:
        bool action (Coord target, GameGrid* attacker, GameGrid* defender) override{
            if(!attacker->move(center(),target)) return false;
            target.i_mm();
            target.j_mm();
            target.i_mm();
            target.j_mm();
            int save_j = target.j();
            for(int i = 0; i < kSonarRange; i++ ){
                for(int j = 0; j < kSonarRange; j++){
                    BoatPart* target_ptr = attacker->getBoatPart(target);
                    if(target_ptr){
                        if(target_ptr->armor()){
                            attacker->setAttackGridCell(target,AttackGridStatus::Detection);
                        }else{
                            attacker->setAttackGridCell(target,AttackGridStatus::Hit);
                        }
                    }else{
                        attacker->setAttackGridCell(target,AttackGridStatus::Water);
                    }
                    target.j_pp();
                }
                target.set_j(save_j);
                target.i_pp();
            }
            return true;
        }
        Sonar():Boat(kSonarDim,kBrokenSonar,kCompleteSonar){}
};

#endif // SONAR_H
