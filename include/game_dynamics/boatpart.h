#if !defined(BOATPART_H)
#define BOATPART_H
class Boat;
class BoatPart{
    public:
        BoatPart():armor_{true}{}
        void setMaster(Boat* boat){master_boat_ = boat;}
        bool armor(){return armor_;}
    private:
        bool armor_;
        Boat* master_boat_;
        int i;
        int j;
};


#endif // BOATPART_H
