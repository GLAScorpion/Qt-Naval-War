#if !defined(SUPPORT_H)
#define SUPPORT_H

#include "coordinates.h"
#include "boat.h"

constexpr int kSupportDim = 3;
class Support : public Boat{
    public:
        bool action (Coord target, GameGrid* attacker, GameGrid* defender) override{
            
        }
        void heal() override{};
        Support():Boat(kSupportDim){}

};

#endif // SUPPORT_H
