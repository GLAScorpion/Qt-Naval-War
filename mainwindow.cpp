#include "mainwindow.h"
#include "startmenuwidget.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),start_menu{new StartMenuWidget()}
{
    setCentralWidget(start_menu);
    setWindowIcon(QIcon("AMOGUS.png"));
    connect(start_menu->start_game_button,&QPushButton::pressed,this,[=]{
        start_menu->gif->stop();
        game_widget = new GameWidget;
        setCentralWidget(game_widget);
    });
    connect(start_menu->exit_button,&QPushButton::pressed,this,[this]{close();});

}

