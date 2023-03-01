#include "hoverpushbutton.h"

void HoverPushButton::enterEvent(QEvent* event){
    emit onEnter(i, j);
    QPushButton::QWidget::enterEvent(event);
}

void HoverPushButton::leaveEvent(QEvent* event){
    emit onLeave(i, j);
    QPushButton::QWidget::leaveEvent(event);
}