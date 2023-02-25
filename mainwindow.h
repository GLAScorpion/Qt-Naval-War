#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "startmenuwidget.h"
#include "gamewidget.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


private:
    GameWidget* game_widget;
    StartMenuWidget* start_menu;
};
#endif // MAINWINDOW_H
