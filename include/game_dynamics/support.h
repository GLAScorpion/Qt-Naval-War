#if !defined(SUPPORT_H)
#define SUPPORT_H
#include "boat.h"
constexpr int kSupportDim = 3;
class Support : public Boat{
    public:
        bool action (int i, int j, GameGrid* attacker, GameGrid* defender) override;
        Support():Boat(kSupportDim){}

};

#endif // SUPPORT_H
