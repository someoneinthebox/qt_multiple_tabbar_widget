#ifndef CUSTOMTABBAR_H
#define CUSTOMTABBAR_H

#include <QTabBar>

/*!
 * \brief The CustomTabBar class
 * A custom QTabBar that allows signal mouse wheel event and up and down arrow keys
 */
class CustomTabBar : public QTabBar
{
    Q_OBJECT

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);

public:
    explicit CustomTabBar(QWidget *parent) : QTabBar(parent){ setUsesScrollButtons(false); }
    ~CustomTabBar(){}

signals:
    void currentByWheelChanged(int index);
    void currentByKeyChanged(int key);
};

#endif // CUSTOMTABBAR_H
