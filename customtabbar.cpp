#include <QKeyEvent>
#include "customtabbar.h"

void CustomTabBar::wheelEvent(QWheelEvent *event)
{
    QTabBar::wheelEvent(event);
    emit currentByWheelChanged(currentIndex());
}

void CustomTabBar::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up: emit currentByKeyChanged(event->key());
            break;
        case Qt::Key_Down: emit currentByKeyChanged(event->key());
            break;
        default:
        {
            QTabBar::keyPressEvent(event);
            emit currentByWheelChanged(currentIndex());
        }
    }
}
