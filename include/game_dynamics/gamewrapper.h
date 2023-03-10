#if !defined(GAMEWRAPPER_H)
#define GAMEWRAPPER_H

#include "../../include/game_dynamics/gamegrid.h"
#include "../../include/GUI/gamedockwidget.h"
#include "coordinates.h"
#include <vector>
#include <QObject>

class MainWindow;

class GameWrapper : public QObject{
    Q_OBJECT

    public:
        GameWrapper(MainWindow* main_window, QObject *parent = nullptr);
        void load_grid();
    private:
        void connect_matrix(bool force = false);
        void disconnect_all();
        //void game_mode_connect();
        MainWindow* main_window;
        std::vector<GameGrid> grids_{2};
        int current_player_ = 0;
        GameDockWidget* game_dock_widget;
        bool displayDefense = true;
        std::vector<Coord >player_boat_select{2};
        bool boat_choice = false;

    signals:
        void setup_phase_ended();
    public slots:
        void delete_boat(int i, int j);
        void set_boat(int i, int j);
        void next_button_setup();
        void game_mode_prep();
        void switch_grid();
        void bt_select(int id);
        void next_button_game_mode();

};

#endif // GAMEWRAPPER_H
