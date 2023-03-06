#if !defined(BOATPART_H)
#define BOATPART_H
#include "boat.h"
class BoatPart{
    public:
        BoatPart():armor_{true}{}
        void setMaster(Boat* boat){master_boat_ = boat;}
        bool armor(){return armor_;}
        void setArmor(bool armor){armor_ = armor;}
        Boat* masterBoat(){return master_boat_;}
        std::string& symbol(){
            return master_boat_->symbol(armor_);
        }
    private:
        bool armor_;
        Boat* master_boat_;
        int i;
        int j;
};


#endif // BOATPART_H
