#ifndef STARTMENUWIDGET_H
#define STARTMENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMovie>
#include <vector>
class StartMenuWidget : public QWidget
{
    Q_OBJECT
public:
    StartMenuWidget(QWidget *parent = nullptr);
    QPushButton *start_game_button = nullptr;
    QPushButton *exit_button = nullptr;
    std::vector<QMovie*> gifs_;

};

#endif // STARTMENUWIDGET_H
