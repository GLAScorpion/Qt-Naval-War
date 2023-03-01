#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include "hoverpushbutton.h"
constexpr int kMatSize = 12;
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
    QIcon boat_icon_hover;
    int boat_higth_hover;
    int boat_width_hover;
private:
    HoverPushButton* matrix[kMatSize][kMatSize];
    QButtonGroup* buttons;
signals:

};

#endif // GAMEWIDGET_H
