#if !defined(COORDINATES_H)
#define COORDINATES_H
//constexpr int kValidCoord = 11;
class Coord{

    public:
        Coord(int i, int j):i_{i},j_{j}{}
        //ROWS
        int i(){return i_;}
        //COLUMNS
        int j(){return j_;}
        void set_i(int i){i_ = i;}
        void set_j(int j){j_ = j;}
    private:
        int i_;//ROWS
        int j_;//COLUMNS
};

#endif // COORDINATES_H
