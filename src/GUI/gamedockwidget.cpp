#include ".././include/GUI/gamedockwidget.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>

GameDockWidget::GameDockWidget(int w , QWidget *parent)
:QWidget(parent),comm_label_{new QLabel(kGameString)}
{
    QVBoxLayout* outer_layout = new QVBoxLayout;
    outer_layout->addWidget(comm_label_);
    QHBoxLayout* label_layout = new QHBoxLayout;
    for(int i = 0; i < 3; i++){
        QLabel* lab;
        QVBoxLayout* vert_label = new QVBoxLayout;
        switch (i)
        {
        case 0:
            lab = new QLabel("Sonars:");
            break;
        case 1:
            lab = new QLabel("Supports:");
            break;
        case 2:
            lab = new QLabel("Battleships:");
            break;
        default:
            break;
        }
        vert_label->addWidget(lab);
        labels_[i] = new QLabel();
        vert_label->addWidget(labels_[i]);
        label_layout->addLayout(vert_label);
    }
    QVBoxLayout* vert_button = new QVBoxLayout;
    buttons_[0] = new QPushButton("Switch\n Grid");
    buttons_[1] = new QPushButton("Next");
    foreach(QPushButton *b,buttons_) vert_button->addWidget(b);
    label_layout->addLayout(vert_button);
    outer_layout->addLayout(label_layout);
    setLayout(outer_layout);
    setFixedSize(w,outer_layout->minimumSize().height());
}