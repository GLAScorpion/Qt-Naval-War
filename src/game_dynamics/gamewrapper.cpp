#include "../../include/game_dynamics/gamewrapper.h"
#include "../../include/GUI/setupdockwidget.h"
#include "../../include/GUI/gamewidget.h"
#include "../../include/GUI/mainwindow.h"
#include "../../include/game_dynamics/boatpart.h"
#include "../../include/game_dynamics/boat.h"
#include "../../include/game_dynamics/battleship.h"
#include "../../include/game_dynamics/sonar.h"
#include "../../include/game_dynamics/support.h"
#include <QObject>
#include <exception>
#include <iostream>

GameWrapper::GameWrapper(MainWindow* main_window,QObject *parent)
:QObject(parent),main_window{main_window}
{
    connect(main_window->dock_widget->dock_boat_buttons[Last], &QPushButton::pressed, main_window, &MainWindow::battleship_set);
    connect(main_window->dock_widget->dock_boat_buttons[Middle], &QPushButton::pressed, main_window, &MainWindow::support_set);
    connect(main_window->dock_widget->dock_boat_buttons[First], &QPushButton::pressed, main_window, &MainWindow::sonar_set);
    connect(main_window->dock_widget->control_buttons[Middle],&QPushButton::pressed,main_window,&MainWindow::rotate);
    connect(main_window->dock_widget->control_buttons[Last],&QPushButton::pressed,this,&GameWrapper::next_button_setup);
    connect_matrix(true);
}

void GameWrapper::connect_matrix(bool force){
    for (size_t i = 0; i < kGridSize; i++)
    {
        for (size_t j = 0; j < kGridSize; j++)
        {
            if(force){
                connect(main_window->game_widget->getButton(i,j),&HoverPushButton::pressed_key_r,main_window->game_widget,&GameWidget::rotate);
                connect(main_window->game_widget->getButton(i,j),&HoverPushButton::pressed_key_d,this,&GameWrapper::delete_boat);
                connect(main_window->game_widget->getButton(i,j), &HoverPushButton::pressed, this, &GameWrapper::set_boat);
            }
            if(!main_window->game_widget->getButton(i,j)->icon_changable() or force){
                main_window->game_widget->setIconCell(i,j);
                main_window->game_widget->getButton(i,j)->set_icon_changable(true);
                connect(main_window->game_widget->getButton(i,j),&HoverPushButton::onEnter,main_window->game_widget, &GameWidget::hover_enter);
                connect(main_window->game_widget->getButton(i,j),&HoverPushButton::onLeave,main_window->game_widget, &GameWidget::hover_leave);
            }
        }
        
    }
    
}

void GameWrapper::disconnect_all(){
    main_window->game_widget->setPreview(false);
    disconnect(main_window->dock_widget->dock_boat_buttons[Last], &QPushButton::pressed, main_window, &MainWindow::battleship_set);
    disconnect(main_window->dock_widget->dock_boat_buttons[Middle], &QPushButton::pressed, main_window, &MainWindow::support_set);
    disconnect(main_window->dock_widget->dock_boat_buttons[First], &QPushButton::pressed, main_window, &MainWindow::sonar_set);
    disconnect(main_window->dock_widget->control_buttons[Middle],&QPushButton::pressed,main_window,&MainWindow::rotate);
    disconnect(main_window->dock_widget->control_buttons[Last],&QPushButton::pressed,this,&GameWrapper::next_button_setup);
    for (size_t i = 0; i < kGridSize; i++)
    {
        for (size_t j = 0; j < kGridSize; j++)
        {
            main_window->game_widget->setIconCell(i,j);
            main_window->game_widget->getButton(i,j)->set_icon_changable(false);
            disconnect(main_window->game_widget->getButton(i,j),&HoverPushButton::pressed_key_r,main_window->game_widget,&GameWidget::rotate);
            disconnect(main_window->game_widget->getButton(i,j),&HoverPushButton::pressed_key_d,this,&GameWrapper::delete_boat);
            disconnect(main_window->game_widget->getButton(i,j),&HoverPushButton::pressed, this, &GameWrapper::set_boat);
            disconnect(main_window->game_widget->getButton(i,j),&HoverPushButton::onEnter,main_window->game_widget, &GameWidget::hover_enter);
            disconnect(main_window->game_widget->getButton(i,j),&HoverPushButton::onLeave,main_window->game_widget, &GameWidget::hover_leave);
        }
    }
}

void GameWrapper::delete_boat(int i, int j){
    main_window->dock_widget->setCommLabel();
    if(!grids_[current_player_].getBoatPart(Coord(i,j))){
        main_window->dock_widget->setCommLabel(kSetupString + " Not a boat. Retry");
        return;
    }
    Boat* boat = grids_[current_player_].getBoatPart(Coord(i,j))->masterBoat();
    bool vert = boat->isVertical();
    std::vector<Coord> coords = grids_[current_player_].deleteBoat(i,j);
    int fixed_val, index, size;
    if(vert){
        fixed_val = coords[0].j();
        index = coords[0].i();
        size = coords[1].i() - coords[0].i() + 1;
    }else{
        fixed_val = coords[0].i();
        index = coords[0].j();
        size = coords[1].j() - coords[0].j() + 1;
    }
    for(int i = 0; i < size; i++){
        if(vert){
            main_window->game_widget->setIconCell(index + i,fixed_val);
            connect(main_window->game_widget->getButton(index + i,fixed_val),&HoverPushButton::onEnter,main_window->game_widget, &GameWidget::hover_enter);
            connect(main_window->game_widget->getButton(index + i,fixed_val),&HoverPushButton::onLeave,main_window->game_widget, &GameWidget::hover_leave);
        }else{
            main_window->game_widget->setIconCell(fixed_val,index + i);
            connect(main_window->game_widget->getButton(fixed_val,index + i),&HoverPushButton::onEnter,main_window->game_widget, &GameWidget::hover_enter);
            connect(main_window->game_widget->getButton(fixed_val,index + i),&HoverPushButton::onLeave,main_window->game_widget, &GameWidget::hover_leave);
        }
    }
    if(size < 0 or size > 5)throw std::invalid_argument("Unknown boat");
    main_window->dock_widget->setLabelValue(main_window->dock_widget->getLabelValue(size/2) + 1,size/2);
    main_window->game_widget->hover_enter(i,j);
}

void GameWrapper::set_boat(int i, int j){
    if(!main_window->game_widget->boat_height_hover or !main_window->game_widget->boat_width_hover) return;
    main_window->dock_widget->setCommLabel();
    int boat_index = main_window->game_widget->boat_height_hover + main_window->game_widget->boat_width_hover - 2;
    if(main_window->dock_widget->getLabelValue(boat_index) == 0){
        main_window->dock_widget->setCommLabel(kSetupString + " No more boats of this type. Retry");
        return;
    }
    Boat* boat;
    switch (boat_index)
    {
    case 0:
        boat = new Sonar();
        break;
    case 1:
        boat = new Support();
        break;
    case 2:
        boat = new Battleship();
        break;
    default:
        throw std::invalid_argument("Unknown boat");
        break;
    }
    Coord begin(i - main_window->game_widget->boat_height_hover + 1, j - main_window->game_widget->boat_width_hover + 1);
    Coord end(i + main_window->game_widget->boat_height_hover - 1, j + main_window->game_widget->boat_width_hover - 1);
    if(!grids_[current_player_].setBoat(begin,end,boat)){
        main_window->dock_widget->setCommLabel(kSetupString + " Can't place it here. Retry");
        return;
    }
    for(int k = 0; k < main_window->game_widget->boat_height_hover; k++){
        for(int q = 0; q < main_window->game_widget->boat_width_hover; q++){
            if(i+k < kMatSize && j+q < kMatSize){
                disconnect(main_window->game_widget->getButton(i+k,j+q), &HoverPushButton::onEnter, main_window->game_widget, &GameWidget::hover_enter);
                disconnect(main_window->game_widget->getButton(i+k,j+q), &HoverPushButton::onLeave, main_window->game_widget, &GameWidget::hover_leave);
                main_window->game_widget->getButton(i+k,j+q)->set_icon_changable(false);
            }
            if(i+k < kMatSize && j-q >= 0){
                disconnect(main_window->game_widget->getButton(i+k,j-q), &HoverPushButton::onEnter, main_window->game_widget, &GameWidget::hover_enter);
                disconnect(main_window->game_widget->getButton(i+k,j-q), &HoverPushButton::onLeave, main_window->game_widget, &GameWidget::hover_leave);
                main_window->game_widget->getButton(i+k,j-q)->set_icon_changable(false);
            }
            if(i-k >= 0 && j+q < kMatSize){
                disconnect(main_window->game_widget->getButton(i-k,j+q), &HoverPushButton::onEnter, main_window->game_widget, &GameWidget::hover_enter);
                disconnect(main_window->game_widget->getButton(i-k,j+q), &HoverPushButton::onLeave, main_window->game_widget, &GameWidget::hover_leave);
                main_window->game_widget->getButton(i-k,j+q)->set_icon_changable(false);
            }
            if(i-k >= 0 && j-q >= 0){
                disconnect(main_window->game_widget->getButton(i-k,j-q), &HoverPushButton::onEnter, main_window->game_widget, &GameWidget::hover_enter);
                disconnect(main_window->game_widget->getButton(i-k,j-q), &HoverPushButton::onLeave, main_window->game_widget, &GameWidget::hover_leave);
                main_window->game_widget->getButton(i-k,j-q)->set_icon_changable(false);
            } 
        }
    }
    main_window->dock_widget->setLabelValue(main_window->dock_widget->getLabelValue(boat_index) - 1,boat_index);
}

void GameWrapper::next_button_setup(){
    for(int i = 0; i < 3; i++){
        if(main_window->dock_widget->getLabelValue(i) != 0){
            main_window->dock_widget->setCommLabel(kSetupString + " Place all boats first, please");
            return;
        }
    }
    current_player_++;
    main_window->game_widget->checkDummy();
    if(current_player_ == 2){
        current_player_ = 0; 
        game_mode_prep();
        return;
    }
    main_window->dock_widget->setCommLabel();
    connect_matrix();
    main_window->dock_widget->setLabelValue(2,First);
    main_window->dock_widget->setLabelValue(3,Middle);
    main_window->dock_widget->setLabelValue(3,Last);
}

void GameWrapper::game_mode_prep(){
    disconnect_all();
    game_dock_widget = new GameDockWidget(kCellPixelSize * kMatSize + kMatSize);
    main_window->dock_menu->setWidget(game_dock_widget);
    game_dock_widget->setCommLabel(kGameString + QString('0' + current_player_));
    connect(game_dock_widget->buttons_[First],&QPushButton::pressed,this,&GameWrapper::switch_grid);
    connect(main_window->game_widget->buttons, &QButtonGroup::idPressed,this,&GameWrapper::bt_select);
    connect(game_dock_widget->buttons_[Middle], &QPushButton::pressed, this,&GameWrapper::next_button_game_mode);
    for(int i = 0; i < 3; i++) game_dock_widget->setLabelValue(grids_[current_player_].getBoatNum(i),i);
    load_grid();
}

void GameWrapper::load_grid(){
    for (size_t i = 0; i < kGridSize; i++)
    {
        for (size_t j = 0; j < kGridSize; j++)
        {
            main_window->game_widget->setLabelCell(i,j);
            if(displayDefense){
                if(grids_[current_player_].getBoatPart(Coord(i,j))){
                    QIcon icon = QIcon(QString::fromStdString(grids_[current_player_].getBoatPart(Coord(i,j))->symbol()));
                    main_window->game_widget->setIconCell(i,j,icon);
                }else{
                    main_window->game_widget->setIconCell(i,j);
                }
                //main_window->game_widget->getButton(i,j)->setIconSize(QSize(40,40));
            }else{
                main_window->game_widget->setIconCell(i,j);
                switch (grids_[current_player_].getAttackGridCell(i,j))
                {
                case AttackGridStatus::Detection :
                    main_window->game_widget->setLabelCell(i,j,"Y");
                    break;
                case AttackGridStatus::Hit:
                    main_window->game_widget->setLabelCell(i,j,"X");
                    break;
                case AttackGridStatus::Miss:
                    main_window->game_widget->setLabelCell(i,j,"O");
                    break;
                default:
                    break;
                }
            }
        }
        
    }
    
}

void GameWrapper::switch_grid(){
    displayDefense = !displayDefense;
    main_window->game_widget->checkDummy();
    load_grid();
}

void GameWrapper::bt_select(int id){
    game_dock_widget->setCommLabel(kGameString + QString('0' + current_player_));
    int i = id / kMatSize;
    int j = id % kMatSize;
    if(i < 0 or j < 0) return;
    player_boat_select[boat_choice] = Coord(i,j);
}

void GameWrapper::next_button_game_mode(){
    if(!boat_choice){
        main_window->game_widget->checkDummy();
        if(!grids_[current_player_].getBoatPart(player_boat_select[0])){
            game_dock_widget->setCommLabel(kGameString + QString('0' + current_player_) + ". Choose an actual boat, terun");
            return;
        }else{
            boat_choice = true;
        }
    }else{
        main_window->game_widget->checkDummy();
        if(grids_[current_player_].getBoatPart(player_boat_select[0])->masterBoat()->action(player_boat_select[1],&grids_[current_player_],&grids_[(current_player_ + 1)%2])){
            boat_choice = false;
            current_player_ = (current_player_ + 1)%2;
            displayDefense = true;
            load_grid();
        }else{
            game_dock_widget->setCommLabel(kGameString + QString('0' + current_player_) + ". Choose a valid destination, terun");
            return;
        }
    }
}