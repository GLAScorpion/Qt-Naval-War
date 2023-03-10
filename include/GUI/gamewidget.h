#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include "hoverpushbutton.h"
constexpr int kMatSize = 12;
constexpr int kCellPixelSize = 50;
class GameWidget : public QWidget
{
    Q_OBJECT
public:
    void checkDummy(){dummy_bt_->setChecked(true);}
    explicit GameWidget(QWidget *parent = nullptr);
    HoverPushButton* getCheckedButton(){return dynamic_cast<HoverPushButton*>(buttons->checkedButton());}
    HoverPushButton* getButton(int i, int j){return matrix[i][j];}
    void setPreview(bool state){preview_mode = state;}
    void setIconCell(int i, int j, QIcon icon = QIcon());
    void setLabelCell(int i, int j, QString str = "");
    QIcon boat_icon_hover;
    int boat_height_hover;
    int boat_width_hover;
    QButtonGroup* buttons;
private:
    QPushButton* dummy_bt_;
    bool preview_mode = true;
    HoverPushButton* matrix[kMatSize][kMatSize];
signals:
public slots:
    void hover_enter(int i, int j);
    void hover_leave(int i, int j);
    void rotate();
};

#endif // GAMEWIDGET_H
