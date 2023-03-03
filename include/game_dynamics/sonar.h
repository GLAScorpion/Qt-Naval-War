#if !defined(SONAR_H)
#define SONAR_H
#include "boat.h"
constexpr int kSonarDim = 1;
class Sonar : public Boat{
    public:
        bool action (int i, int j, GameGrid* attacker, GameGrid* defender) override;
        Sonar():Boat(kSonarDim){}
};

#endif // SONAR_H
