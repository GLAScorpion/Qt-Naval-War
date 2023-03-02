#include "mainwindow.h"
#include "startmenuwidget.h"
#include <QPushButton>
#include "dockwidget.h"
#include <QDockWidget>
#include <QSizePolicy>
#include "hoverpushbutton.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),start_menu{new StartMenuWidget()}
{
    //setSizePolicy(QSizePolicy::Policy::Fixed,QSizePolicy::Policy::Fixed);
    setCentralWidget(start_menu);
    setWindowIcon(QIcon("AMOGUS.png"));
    connect(start_menu->start_game_button,&QPushButton::pressed,this, &MainWindow::game_prep);
    connect(start_menu->exit_button,&QPushButton::pressed,this,[this]{close();});

}

void MainWindow::battleship_set(){
    game_widget->boat_icon_hover = QIcon("nuke.png");
    game_widget->boat_higth_hover = 1;
    game_widget->boat_width_hover = 3;
}

void MainWindow::support_set(){
    game_widget->boat_icon_hover = QIcon("AMOGUS.png");
    game_widget->boat_higth_hover = 1;
    game_widget->boat_width_hover = 2;
}

void MainWindow::sonar_set(){
    game_widget->boat_icon_hover = QIcon("119.jpg");
    game_widget->boat_higth_hover = 1;
    game_widget->boat_width_hover = 1;
}

void MainWindow::game_prep(){
    start_menu->gif->stop();
    game_widget = new GameWidget;
    setCentralWidget(game_widget);
    dock_menu = new QDockWidget();
    dock_menu->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dock_widget = new DockWidget(kCellPixelSize * kMatSize);
    game_widget->setRotateButton(dock_widget->control_buttons[Rotate]);
    dock_widget->control_buttons[Rotate]->setShortcut(Qt::Key_R);
    dock_menu->setWidget(dock_widget);
    addDockWidget(Qt::BottomDockWidgetArea,dock_menu);
    connect(dock_widget->dock_boat_buttons[Battleship], &QPushButton::pressed, this, &MainWindow::battleship_set);
    connect(dock_widget->dock_boat_buttons[Support], &QPushButton::pressed, this, &MainWindow::support_set);
    connect(dock_widget->dock_boat_buttons[Sonar], &QPushButton::pressed, this, &MainWindow::sonar_set);
}