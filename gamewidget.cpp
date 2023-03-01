#include "gamewidget.h"
#include "hoverpushbutton.h"
#include <QGridLayout>
GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent},buttons{new QButtonGroup}
{
    QGridLayout* grid_layout = new QGridLayout;
    for(size_t i = 0; i < kMatSize; i++){
        for(size_t j = 0; j < kMatSize; j++){
            matrix[i][j] = new HoverPushButton(i,j);
            matrix[i][j]->setStyleSheet("QPushButton{background-color:blue;border: 0.5px solid black} QPushButton::checked,QPushButton::hover{background-color:rgb(66, 126, 245)}");
            //matrix[i][j]->setIcon(QIcon("nuke.png"));
            matrix[i][j]->setCheckable(true);
            matrix[i][j]->setIconSize(QSize(50,50));
            matrix[i][j]->setFixedSize(QSize(50,50));
            buttons->addButton(matrix[i][j]);
            grid_layout->addWidget(matrix[i][j],i,j,Qt::AlignCenter);
            connect(matrix[i][j],&HoverPushButton::onEnter,this,[=]{
                for(int k = 0; k < boat_higth_hover; k++){
                    for(int q = 0; q < boat_width_hover; q++){
                        if(i+k < kMatSize && j+q < kMatSize && matrix[i+k][j+q]->icon_changable()) matrix[i+k][j+q]->setIcon(boat_icon_hover);
                        if(i+k < kMatSize && j-q >= 0 && matrix[i+k][j-q]->icon_changable()) matrix[i+k][j-q]->setIcon(boat_icon_hover);
                        if(i-k >= 0 && j+q < kMatSize && matrix[i-k][j+q]->icon_changable()) matrix[i-k][j+q]->setIcon(boat_icon_hover);
                        if(i-k >= 0 && j-q >= 0 && matrix[i-k][j-q]->icon_changable()) matrix[i-k][j-q]->setIcon(boat_icon_hover); 
                    }
                }
            });
            connect(matrix[i][j],&HoverPushButton::onLeave,this,[=]{
                for(int k = 0; k < boat_higth_hover; k++){
                    for(int q = 0; q < boat_width_hover; q++){
                        if(i+k < kMatSize && j+q < kMatSize && matrix[i+k][j+q]->icon_changable()) matrix[i+k][j+q]->setIcon(QIcon());
                        if(i+k < kMatSize && j-q >= 0 && matrix[i+k][j-q]->icon_changable()) matrix[i+k][j-q]->setIcon(QIcon());
                        if(i-k >= 0 && j+q < kMatSize && matrix[i-k][j+q]->icon_changable()) matrix[i-k][j+q]->setIcon(QIcon());
                        if(i-k >= 0 && j-q >= 0 && matrix[i-k][j-q]->icon_changable()) matrix[i-k][j-q]->setIcon(QIcon()); 
                    }
                }
            });
            connect(matrix[i][j], &HoverPushButton::pressed, this, [=]{
                for(int k = 0; k < boat_higth_hover; k++){
                    for(int q = 0; q < boat_width_hover; q++){
                        if(i+k < kMatSize && j+q < kMatSize){
                            disconnect(matrix[i+k][j+q], &HoverPushButton::onEnter, 0, 0);
                            disconnect(matrix[i+k][j+q], &HoverPushButton::onLeave, 0, 0);
                            matrix[i+k][j+q]->set_icon_changable(false);
                        }
                        if(i+k < kMatSize && j-q >= 0){
                            disconnect(matrix[i+k][j-q], &HoverPushButton::onEnter, 0, 0);
                            disconnect(matrix[i+k][j-q], &HoverPushButton::onLeave, 0, 0);
                            matrix[i+k][j-q]->set_icon_changable(false);
                        }
                        if(i-k >= 0 && j+q < kMatSize){
                            disconnect(matrix[i-k][j+q], &HoverPushButton::onLeave, 0, 0);
                            disconnect(matrix[i-k][j+q], &HoverPushButton::onEnter, 0, 0);
                            matrix[i-k][j+q]->set_icon_changable(false);
                        }
                        if(i-k >= 0 && j-q >= 0){
                            disconnect(matrix[i-k][j-q], &HoverPushButton::onEnter, 0, 0);
                            disconnect(matrix[i-k][j-q], &HoverPushButton::onLeave, 0, 0);
                            matrix[i-k][j-q]->set_icon_changable(false);
                        } 
                    }
                }
            });
        }
    }
    buttons->setExclusive(true);
    grid_layout->setHorizontalSpacing(0);
    grid_layout->setVerticalSpacing(0);
    grid_layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(grid_layout);
}
