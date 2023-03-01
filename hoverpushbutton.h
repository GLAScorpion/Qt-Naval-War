#ifndef HOVERPUSHBUTTON_H
#define HOVERPUSHBUTTON_H
#include <QPushButton>
#include <QWidget>
class HoverPushButton : public QPushButton
{
    Q_OBJECT
private:
    const int i;
    const int j;
    bool change_icon;
public:
    HoverPushButton(int i, int j):QPushButton(), i{i}, j{j}, change_icon{true}{setMouseTracking(true);}
    bool icon_changable() const {return change_icon;}
    void set_icon_changable(bool change){change_icon = change;}

    //~HoverPushButton();
protected:
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
public: Q_SIGNALS:
    void onEnter(int i, int j);
    void onLeave(int i, int j);
    void pressed(int i, int j);
};

#endif