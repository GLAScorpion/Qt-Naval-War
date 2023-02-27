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
public:
    HoverPushButton(int i, int j):QPushButton(),i{i},j{j}{setMouseTracking(true);}

    //~HoverPushButton();
protected:
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);
public: Q_SIGNALS:
    void onEnter();
    void onLeave();
};

#endif