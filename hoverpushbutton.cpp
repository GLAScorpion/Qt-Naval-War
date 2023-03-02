#include "hoverpushbutton.h"
#include <QKeyEvent>
void HoverPushButton::enterEvent(QEvent* event){
    emit onEnter(i, j);
    QPushButton::QWidget::enterEvent(event);
}

void HoverPushButton::leaveEvent(QEvent* event){
    emit onLeave(i, j);
    QPushButton::QWidget::leaveEvent(event);
}

void HoverPushButton::keyPressEvent(QKeyEvent *event){
    switch (event->key())
    {
    case Qt::Key_R:
        emit pressed_R_key(i,j);
        break;
    default:
        QPushButton::keyPressEvent(event);
        break;
    }
}

void HoverPushButton::mousePressEvent(QMouseEvent *event){
    emit pressed(i,j);
    QPushButton::QWidget::mousePressEvent(event);
}