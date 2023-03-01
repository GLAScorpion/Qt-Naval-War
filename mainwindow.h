#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <vector>
#include "startmenuwidget.h"
#include "gamewidget.h"
#include "dockwidget.h"
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
    
};
#endif // MAINWINDOW_H
