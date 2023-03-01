#include "mainwindow.h"
#include "startmenuwidget.h"
#include <QPushButton>
#include "dockwidget.h"
#include <QDockWidget>
#include <QSizePolicy>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),start_menu{new StartMenuWidget()}
{
    //setSizePolicy(QSizePolicy::Policy::Fixed,QSizePolicy::Policy::Fixed);
    setAnimated(false);
    setCentralWidget(start_menu);
    setWindowIcon(QIcon("AMOGUS.png"));
    connect(start_menu->start_game_button,&QPushButton::pressed,this,[=]{
        start_menu->gif->stop();
        game_widget = new GameWidget;
        setCentralWidget(game_widget);
        dock_menu = new QDockWidget();
        dock_menu->setFeatures(QDockWidget::NoDockWidgetFeatures);
        //std::cerr<<game_widget->width();
        DockWidget* dock_widget = new DockWidget(kCellPixelSize * kMatSize);
        dock_menu->setWidget(dock_widget);
        addDockWidget(Qt::BottomDockWidgetArea,dock_menu);
    });
    connect(start_menu->exit_button,&QPushButton::pressed,this,[this]{close();});

}

