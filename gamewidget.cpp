#include "gamewidget.h"
#include <QPushButton>
#include <QGridLayout>
GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent},buttons{new QButtonGroup}
{
    QGridLayout* grid_layout = new QGridLayout;
    for(size_t i = 0; i < kMatSize; i++){
        for(size_t j = 0; j < kMatSize; j++){
            matrix[i][j] = new QPushButton();
            matrix[i][j]->setStyleSheet("QPushButton{background-color:blue;border: 0.5px solid black} QPushButton::checked,QPushButton::hover{background-color:rgb(66, 126, 245)}");
            //matrix[i][j]->setIcon(QIcon("nuke.png"));
            matrix[i][j]->setCheckable(true);
            matrix[i][j]->setIconSize(QSize(50,50));
            matrix[i][j]->setFixedSize(QSize(50,50));
            buttons->addButton(matrix[i][j]);
            grid_layout->addWidget(matrix[i][j],i,j,Qt::AlignCenter);
        }
    }
    buttons->setExclusive(true);
    grid_layout->setHorizontalSpacing(0);
    grid_layout->setVerticalSpacing(0);
    grid_layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(grid_layout);
}
