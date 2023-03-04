#if !defined(GAMEWRAPPER_H)
#define GAMEWRAPPER_H

#include "../../include/game_dynamics/gamegrid.h"
#include <vector>
#include <QObject>

class Coord;
class MainWindow;

class GameWrapper : public QObject{
    Q_OBJECT

    public:
        GameWrapper(MainWindow* main_window, QObject *parent = nullptr);
    private:
        void connect_matrix();
        MainWindow* main_window;
        std::vector<GameGrid> grids_{2};
        int current_player_ = 0;

    signals:
        void delete_boat_sig(int i, int j);
        void set_boat_sig(int i, int j);
    public slots:
        void delete_boat(int i, int j);
        void set_boat(int i, int j);
};

#endif // GAMEWRAPPER_H
