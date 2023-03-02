#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "startmenuwidget.h"
#include "gamewidget.h"
#include "dockwidget.h"
#include <QMainWindow>
#include <QDockWidget>
#include <vector>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


private:
    GameWidget* game_widget;
    StartMenuWidget* start_menu;
    QDockWidget* dock_menu;
    DockWidget* dock_widget;

public slots:
    void battleship_set();
    void support_set();
    void sonar_set();
    void game_prep();
    void rotate();
};
#endif // MAINWINDOW_H
