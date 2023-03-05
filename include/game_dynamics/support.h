#if !defined(SUPPORT_H)
#define SUPPORT_H

#include "coordinates.h"
#include "boat.h"
#include "gamegrid.h"
#include "boatpart.h"

constexpr int kSupportDim = 3;
constexpr int kSupportRange = 3;
class Support : public Boat{
    public:
        bool action (Coord target, GameGrid* attacker, GameGrid* defender) override{
            if(!attacker->move(center(),target)) return false;
            target.i_mm();
            target.j_mm();
            int save_j = target.j();
            for(int i = 0; i < kSupportRange; i++ ){
                for(int j = 0; j < kSupportRange; j++){
                    BoatPart* target_ptr = attacker->getBoatPart(target);
                    if(target_ptr) target_ptr->masterBoat()->heal();
                    target.j_pp();
                }
                target.set_j(save_j);
                target.i_pp();
            }
            return true;
        }
        void heal() override{};
        Support():Boat(kSupportDim){}

};

#endif // SUPPORT_H
