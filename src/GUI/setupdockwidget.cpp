#include "../../include/GUI/setupdockwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSize>
#include <iostream>

SetupDockWidget::SetupDockWidget(int w, QWidget *parent)
:QWidget(parent),comm_label_{new QLabel(kSetupString)}
{
    QHBoxLayout* dock_layout = new QHBoxLayout();
    QHBoxLayout* boat_buttons_layout = new QHBoxLayout();
    dock_boat_buttons[2] = new QPushButton("Battleship");
    dock_boat_buttons[1] = new QPushButton("Support");
    dock_boat_buttons[0] = new QPushButton("Sonar");
    boat_num_[2] = 3;
    boat_num_[1] = 3;
    boat_num_[0] = 2;
    boat_button_group = new QButtonGroup;
    for(int i = 0; i < 3; i++){
        QVBoxLayout* column = new QVBoxLayout;
        column->addWidget(dock_boat_buttons[i]);
        dock_boat_buttons[i]->setStyleSheet("QPushButton{background-color:white;color:black} QPushButton::checked,QPushButton::hover{background-color:gray}");
        dock_boat_buttons[i]->setCheckable(true);
        boat_button_group->addButton(dock_boat_buttons[i]);
        QHBoxLayout* row = new QHBoxLayout;
        row->addWidget(new QLabel("Remaining: "));
        dock_labels[i] = new QLabel;
        setLabelValue(boat_num_[i], i);
        row->addWidget(dock_labels[i]);
        column->addLayout(row);
        boat_buttons_layout->addLayout(column);
    }
    boat_button_group->setExclusive(true);
    QVBoxLayout* control_buttons_layout = new QVBoxLayout();
    control_buttons[0] = new QPushButton("Delete");
    control_buttons[1] = new QPushButton("Rotate");
    control_buttons[2] = new QPushButton("Next");
    foreach (QPushButton* b, control_buttons) control_buttons_layout->addWidget(b);
    dock_layout->addLayout(boat_buttons_layout);
    dock_layout->addLayout(control_buttons_layout);
    QVBoxLayout* outer_layout = new QVBoxLayout;
    outer_layout->addWidget(comm_label_);
    outer_layout->addLayout(dock_layout);
    setLayout(outer_layout);
    setFixedSize(w,outer_layout->minimumSize().height());
}
