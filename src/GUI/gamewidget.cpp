#include "../../include/GUI/gamewidget.h"
#include "../../include/GUI/hoverpushbutton.h"
#include <QGridLayout>
GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent},buttons{new QButtonGroup}
{
    QGridLayout* grid_layout = new QGridLayout;
    for(int i = 0; i < kMatSize; i++){
        for(int j = 0; j < kMatSize; j++){
            matrix[i][j] = new HoverPushButton(i,j);
            matrix[i][j]->setStyleSheet("QPushButton{background-color:blue;border: 0.5px solid black} QPushButton::checked,QPushButton::hover{background-color:rgb(66, 126, 245)}");
            matrix[i][j]->setCheckable(true);
            matrix[i][j]->setIconSize(QSize(kCellPixelSize - 10,kCellPixelSize - 10));
            matrix[i][j]->setFixedSize(QSize(kCellPixelSize,kCellPixelSize));
            buttons->addButton(matrix[i][j], i * kMatSize + j);
            grid_layout->addWidget(matrix[i][j],i,j,Qt::AlignCenter);
        }
    }
    dummy_bt_ = new QPushButton;
    dummy_bt_->setCheckable(true);
    buttons->addButton(dummy_bt_);
    buttons->setExclusive(true);
    grid_layout->setHorizontalSpacing(0);
    grid_layout->setVerticalSpacing(0);
    grid_layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(grid_layout);
}

void GameWidget::setIconCell(int i, int j,QIcon icon){
    matrix[i][j]->setIcon(icon);
    matrix[i][j]->set_icon_changable(true);
    if(preview_mode){
        connect(matrix[i][j],&HoverPushButton::onEnter,this, &GameWidget::hover_enter);
        connect(matrix[i][j],&HoverPushButton::onLeave,this, &GameWidget::hover_leave);
    }
}

void GameWidget::setLabelCell(int i, int j, QString str){
    matrix[i][j]->setText(str);
}

void GameWidget::hover_enter(int i, int j){
    for(int k = 0; k < boat_height_hover; k++){
        for(int q = 0; q < boat_width_hover; q++){
            if(i+k < kMatSize && j+q < kMatSize && matrix[i+k][j+q]->icon_changable()) matrix[i+k][j+q]->setIcon(boat_icon_hover);
            if(i+k < kMatSize && j-q >= 0 && matrix[i+k][j-q]->icon_changable()) matrix[i+k][j-q]->setIcon(boat_icon_hover);
            if(i-k >= 0 && j+q < kMatSize && matrix[i-k][j+q]->icon_changable()) matrix[i-k][j+q]->setIcon(boat_icon_hover);
            if(i-k >= 0 && j-q >= 0 && matrix[i-k][j-q]->icon_changable()) matrix[i-k][j-q]->setIcon(boat_icon_hover); 
        }
    }
}

void GameWidget::hover_leave(int i, int j){
    for(int k = 0; k < boat_height_hover; k++){
        for(int q = 0; q < boat_width_hover; q++){
            if(i+k < kMatSize && j+q < kMatSize && matrix[i+k][j+q]->icon_changable()) matrix[i+k][j+q]->setIcon(QIcon());
            if(i+k < kMatSize && j-q >= 0 && matrix[i+k][j-q]->icon_changable()) matrix[i+k][j-q]->setIcon(QIcon());
            if(i-k >= 0 && j+q < kMatSize && matrix[i-k][j+q]->icon_changable()) matrix[i-k][j+q]->setIcon(QIcon());
            if(i-k >= 0 && j-q >= 0 && matrix[i-k][j-q]->icon_changable()) matrix[i-k][j-q]->setIcon(QIcon()); 
        }
    }
}

void GameWidget::rotate(){
    int tmp = boat_height_hover;
    boat_height_hover = boat_width_hover;
    boat_width_hover = tmp;
}

