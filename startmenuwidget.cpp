#include "startmenuwidget.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QMovie>

StartMenuWidget::StartMenuWidget(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout* main_layout = new QVBoxLayout;
    setLayout(main_layout);
    QFrame* image_frame = new QFrame;
    QLabel* image_label = new QLabel;
    QPixmap pix = QPixmap("119.jpg");
    image_label->setPixmap(pix);
    QVBoxLayout* image_layout = new QVBoxLayout;
    image_layout->addWidget(image_label);
    image_frame->setLayout(image_layout);
    main_layout->addWidget(image_frame);
    start_game_button = new QPushButton;
    gif = new QMovie("blobhang.gif");
    connect(gif, &QMovie::frameChanged, [=]{start_game_button->setIcon(gif->currentPixmap()); });
    gif->start();
    start_game_button->setIcon(QIcon(gif->currentPixmap()));
    start_game_button->setIconSize(QSize(100,100));
    start_game_button->setText("START GAME");
    main_layout->addWidget(start_game_button);
    exit_button = new QPushButton(QIcon("pGAY.png"),"Escile");
    exit_button->setIconSize(QSize(100,100));
    main_layout->addWidget(exit_button);
    main_layout->setSizeConstraint(QLayout::SetFixedSize);
}


