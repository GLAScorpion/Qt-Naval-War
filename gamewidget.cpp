#include "gamewidget.h"
#include "hoverpushbutton.h"
#include <QGridLayout>
GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent},buttons{new QButtonGroup}
{
    
    QGridLayout* grid_layout = new QGridLayout;
    for(int i = 0; i < kMatSize; i++){
        for(int j = 0; j < kMatSize; j++){
            matrix[i][j] = new HoverPushButton(i,j);
            matrix[i][j]->setStyleSheet("QPushButton{background-color:blue;border: 0.5px solid black} QPushButton::checked,QPushButton::hover{background-color:rgb(66, 126, 245)}");
            //matrix[i][j]->setIcon(QIcon("nuke.png"));
            matrix[i][j]->setCheckable(true);
            matrix[i][j]->setIconSize(QSize(kCellPixelSize,kCellPixelSize));
            matrix[i][j]->setFixedSize(QSize(kCellPixelSize,kCellPixelSize));
            buttons->addButton(matrix[i][j]);
            grid_layout->addWidget(matrix[i][j],i,j,Qt::AlignCenter);
            connect(matrix[i][j],&HoverPushButton::onEnter,this, &GameWidget::hover_enter);
            connect(matrix[i][j],&HoverPushButton::onLeave,this, &GameWidget::hover_leave);
            connect(matrix[i][j], &HoverPushButton::pressed, this, &GameWidget::boat_set);
        }
    }
    buttons->setExclusive(true);
    grid_layout->setHorizontalSpacing(0);
    grid_layout->setVerticalSpacing(0);
    grid_layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(grid_layout);
}

void GameWidget::setRotateButton(QPushButton* button){
    rotate_button = button;
    connect(rotate_button,&QPushButton::pressed,this,[=]{
        if(track_i != -1) {
            int tmp_i = track_i;
            hover_leave(track_i,track_j);
            track_i = tmp_i;
        }
        int tmp = boat_higth_hover;
        boat_higth_hover = boat_width_hover;
        boat_width_hover = tmp;
        if(track_i != -1) hover_enter(track_i,track_j);
    });
}

void GameWidget::hover_enter(int i, int j){
    track_i = i;
    track_j = j;
    for(int k = 0; k < boat_higth_hover; k++){
        for(int q = 0; q < boat_width_hover; q++){
            if(i+k < kMatSize && j+q < kMatSize && matrix[i+k][j+q]->icon_changable()) matrix[i+k][j+q]->setIcon(boat_icon_hover);
            if(i+k < kMatSize && j-q >= 0 && matrix[i+k][j-q]->icon_changable()) matrix[i+k][j-q]->setIcon(boat_icon_hover);
            if(i-k >= 0 && j+q < kMatSize && matrix[i-k][j+q]->icon_changable()) matrix[i-k][j+q]->setIcon(boat_icon_hover);
            if(i-k >= 0 && j-q >= 0 && matrix[i-k][j-q]->icon_changable()) matrix[i-k][j-q]->setIcon(boat_icon_hover); 
        }
    }
}

void GameWidget::hover_leave(int i, int j){
    track_i = -1;
    int height = boat_higth_hover;
    int width = boat_width_hover;
    for(int k = 0; k < height; k++){
        for(int q = 0; q < width; q++){
            if(i+k < kMatSize && j+q < kMatSize && matrix[i+k][j+q]->icon_changable()) matrix[i+k][j+q]->setIcon(QIcon());
            if(i+k < kMatSize && j-q >= 0 && matrix[i+k][j-q]->icon_changable()) matrix[i+k][j-q]->setIcon(QIcon());
            if(i-k >= 0 && j+q < kMatSize && matrix[i-k][j+q]->icon_changable()) matrix[i-k][j+q]->setIcon(QIcon());
            if(i-k >= 0 && j-q >= 0 && matrix[i-k][j-q]->icon_changable()) matrix[i-k][j-q]->setIcon(QIcon()); 
        }
    }
}

//doesn't work because of parameters i, j cannot be passed with a pressed signal
void GameWidget::boat_set(int i, int j){
    for(int k = 0; k < boat_higth_hover; k++){
        for(int q = 0; q < boat_width_hover; q++){
            if(i+k < kMatSize && j+q < kMatSize){
                disconnect(matrix[i+k][j+q], &HoverPushButton::onEnter, this, &GameWidget::hover_enter);
                disconnect(matrix[i+k][j+q], &HoverPushButton::onLeave, this, &GameWidget::hover_leave);
                disconnect(matrix[i+k][j+q], &HoverPushButton::pressed, this, &GameWidget::boat_set);
                matrix[i+k][j+q]->set_icon_changable(false);
            }
            if(i+k < kMatSize && j-q >= 0){
                disconnect(matrix[i+k][j-q], &HoverPushButton::onEnter, this, &GameWidget::hover_enter);
                disconnect(matrix[i+k][j-q], &HoverPushButton::onLeave, this, &GameWidget::hover_leave);
                disconnect(matrix[i+k][j-q], &HoverPushButton::pressed, this, &GameWidget::boat_set);
                matrix[i+k][j-q]->set_icon_changable(false);
            }
            if(i-k >= 0 && j+q < kMatSize){
                disconnect(matrix[i-k][j+q], &HoverPushButton::onEnter, this, &GameWidget::hover_enter);
                disconnect(matrix[i-k][j+q], &HoverPushButton::onLeave, this, &GameWidget::hover_leave);
                disconnect(matrix[i-k][j+q], &HoverPushButton::pressed, this, &GameWidget::boat_set);
                matrix[i-k][j+q]->set_icon_changable(false);
            }
            if(i-k >= 0 && j-q >= 0){
                disconnect(matrix[i-k][j-q], &HoverPushButton::onEnter, this, &GameWidget::hover_enter);
                disconnect(matrix[i-k][j-q], &HoverPushButton::onLeave, this, &GameWidget::hover_leave);
                disconnect(matrix[i-k][j-q], &HoverPushButton::pressed, this, &GameWidget::boat_set);
                matrix[i-k][j-q]->set_icon_changable(false);
            } 
        }
    }
}