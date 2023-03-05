#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "startmenuwidget.h"
#include "gamewidget.h"
#include "setupdockwidget.h"
#include <QMainWindow>
#include <QDockWidget>
#include <vector>

class GameWrapper;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    GameWidget* game_widget;
    StartMenuWidget* start_menu;
    SetupDockWidget* dock_widget;

private:
    GameWrapper* game_wrapper;
    QDockWidget* dock_menu;

public slots:
    void battleship_set();
    void support_set();
    void sonar_set();
    void game_prep();
    void rotate();
    void delete_boat();
};
#endif // MAINWINDOW_H
