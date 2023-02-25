#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
constexpr int kMatSize = 12;
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = nullptr);
private:
    QPushButton* matrix[kMatSize][kMatSize];
    QButtonGroup* buttons;
signals:

};

#endif // GAMEWIDGET_H
