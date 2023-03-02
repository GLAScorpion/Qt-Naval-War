#include "dockwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSize>
DockWidget::DockWidget(int w, QWidget *parent)
:QWidget(parent)
{
    QHBoxLayout* dock_layout = new QHBoxLayout();
    dock_boat_buttons[0] = new QPushButton("Battleship");
    dock_boat_buttons[1] = new QPushButton("Support");
    dock_boat_buttons[2] = new QPushButton("Sonar");
    boat_button_group = new QButtonGroup;
    QHBoxLayout* boat_buttons_layout = new QHBoxLayout();
    foreach (QPushButton* b , dock_boat_buttons) {
        b->setStyleSheet("QPushButton{background-color:white;color:black} QPushButton::checked,QPushButton::hover{background-color:gray}");
        b->setCheckable(true);
        boat_buttons_layout->addWidget(b);
        boat_button_group->addButton(b);
    }
    boat_button_group->setExclusive(true);
    QVBoxLayout* control_buttons_layout = new QVBoxLayout();
    control_buttons[0] = new QPushButton("Delete");
    control_buttons[1] = new QPushButton("Rotate");
    control_buttons[2] = new QPushButton("Next");
    foreach (QPushButton* b, control_buttons) control_buttons_layout->addWidget(b);
    //boat_buttons_layout->setSizeConstraint(QLayout::SetFixedSize);
    //control_buttons_layout->setSizeConstraint(QLayout::SetFixedSize);
    dock_layout->addLayout(boat_buttons_layout);
    dock_layout->addLayout(control_buttons_layout);
    setLayout(dock_layout);
    setFixedSize(w,dock_layout->minimumSize().height());
}
