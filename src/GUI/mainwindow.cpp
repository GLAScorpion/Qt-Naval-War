#include "../../include/GUI/mainwindow.h"
#include "../../include/GUI/startmenuwidget.h"
#include "../../include/GUI/setupdockwidget.h"
#include "../../include/GUI/hoverpushbutton.h"
#include "../../include/game_dynamics/gamewrapper.h"
#include <QPushButton>
#include <QDockWidget>
#include <QSizePolicy>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),start_menu{new StartMenuWidget()}
{
    setCentralWidget(start_menu);
    setWindowIcon(QIcon("AMOGUS.png"));
    connect(start_menu->start_game_button,&QPushButton::pressed,this, &MainWindow::game_prep);
    connect(start_menu->exit_button,&QPushButton::pressed,this,[this]{close();});

}

void MainWindow::battleship_set(){
    game_widget->boat_icon_hover = QIcon("battleship.jpg");
    game_widget->boat_height_hover = 1;
    game_widget->boat_width_hover = 3;
}

void MainWindow::support_set(){
    game_widget->boat_icon_hover = QIcon("support.jpg");
    game_widget->boat_height_hover = 1;
    game_widget->boat_width_hover = 2;
}

void MainWindow::sonar_set(){
    game_widget->boat_icon_hover = QIcon("radar.jpg");
    game_widget->boat_height_hover = 1;
    game_widget->boat_width_hover = 1;
}
void MainWindow::rotate(){
    
    int tmp = game_widget->boat_height_hover;
    game_widget->boat_height_hover = game_widget->boat_width_hover;
    game_widget->boat_width_hover = tmp;
}
void MainWindow::game_prep(){
    foreach(QMovie* gif, start_menu->gifs_) gif->stop();
    game_widget = new GameWidget;
    setCentralWidget(game_widget);
    dock_menu = new QDockWidget();
    dock_menu->setFeatures(QDockWidget::NoDockWidgetFeatures);
    dock_widget = new SetupDockWidget(kCellPixelSize * kMatSize + kMatSize);
    dock_menu->setWidget(dock_widget);
    addDockWidget(Qt::BottomDockWidgetArea,dock_menu);
    game_wrapper = new GameWrapper(this,nullptr);
}

void MainWindow::delete_boat(){
    HoverPushButton* button = game_widget->getCheckedButton();
    game_wrapper->delete_boat(button->i,button->j);
}