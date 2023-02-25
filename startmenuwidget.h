#ifndef STARTMENUWIDGET_H
#define STARTMENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMovie>
class StartMenuWidget : public QWidget
{
    Q_OBJECT
public:
    StartMenuWidget(QWidget *parent = nullptr);
    QPushButton *start_game_button = nullptr;
    QPushButton *exit_button = nullptr;
    QMovie* gif;
};

#endif // STARTMENUWIDGET_H
