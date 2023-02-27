#include "hoverpushbutton.h"

void HoverPushButton::enterEvent(QEvent* event){
    emit onEnter();
    QPushButton::QWidget::enterEvent(event);
}

void HoverPushButton::leaveEvent(QEvent* event){
    emit onLeave();
    QPushButton::QWidget::leaveEvent(event);
}