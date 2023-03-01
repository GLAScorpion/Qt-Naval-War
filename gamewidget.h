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
public slots:
    void hover_enter(int i, int j);
    void hover_leave(int i, int j);
    void boat_set(int i, int j);
};

#endif // GAMEWIDGET_H
