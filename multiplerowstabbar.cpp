#include <QVBoxLayout>
#include <QTabBar>
#include <QIcon>
#include <QStackedLayout>
#include "customtabbar.h"
#include "multiplerowstabbar.h"

MultipleRowsTabBar::MultipleRowsTabBar(int rows, QWidget *parent) : QWidget(parent)
{
    if(rows <= 0)
        return;

    QVBoxLayout *mainLay = new QVBoxLayout(this);
    for(auto i = 0; i < rows; i++)
    {
        QHBoxLayout *tabLay = new QHBoxLayout;
        CustomTabBar *tb = new CustomTabBar(this);
        connect(tb, &CustomTabBar::tabBarClicked, this, &MultipleRowsTabBar::currentChange);
        connect(tb, &CustomTabBar::currentByWheelChanged, this, &MultipleRowsTabBar::currentChange);
        connect(tb, &CustomTabBar::currentByKeyChanged, this, &MultipleRowsTabBar::currentChangeByKey);
        tabLay->addWidget(tb);
        _tabs.append(tb);
        mainLay->addLayout(tabLay);
    }

    _stack = new QStackedLayout;
    mainLay->addLayout(_stack);
}

void MultipleRowsTabBar::resetTabs()
{
    for(QTabBar *b : _tabs)
	{
		b->setStyleSheet(_inactiveStyleSheet);
        b->setCurrentIndex(0);
	}
}

void MultipleRowsTabBar::addTab(int row, const QIcon &icon, const QString &text, QWidget *widget)
{
    if(_tabs.size() <= row || row < 0)
        return;

    CustomTabBar *tb = _tabs.at(row);
    if(!icon.isNull())
        tb->addTab(icon, text);
    else
        tb->addTab(text);

    if(widget != nullptr)
        _stack->addWidget(widget);
}

void MultipleRowsTabBar::addTab(int row, const QString &text, QWidget *widget)
{
    addTab(row, QIcon(), text, widget);
}

void MultipleRowsTabBar::addWidget(QWidget *widget)
{
    _stack->addWidget(widget);
}

void MultipleRowsTabBar::setCurrentTab(int row, int index)
{
    if(_tabs.size() <= row)
        return;

    resetTabs();
    currentTabChange(_tabs.at(row), index);
}

void MultipleRowsTabBar::currentTabChange(CustomTabBar *bar, int index)
{
    if(index < 0 || index >= bar->count())
        return;

    bar->setCurrentIndex(index);
	bar->setStyleSheet(_activeStyleSheet);
    changeStack(getStackIndex(_tabs.indexOf(bar), index));
}

int MultipleRowsTabBar::getStackIndex(int row, int index)
{
    int cntTabs = 0;
    for(auto i = 0; i < row; i++)
        cntTabs += _tabs.at(i)->count();

    return cntTabs + index;
}

void MultipleRowsTabBar::changeStack(int index)
{
    if(index < 0 || index >= _stack->count())
        return;

    _stack->setCurrentIndex(index);
}

void MultipleRowsTabBar::currentChange(int index)
{
    resetTabs();
    CustomTabBar *t = dynamic_cast<CustomTabBar *>(sender());
    currentTabChange(t, index);
}

void MultipleRowsTabBar::currentChangeByKey(int key)
{
    int currentTabRow = _tabs.indexOf(dynamic_cast<CustomTabBar *>(sender()));

    if(currentTabRow < 0)
        return;

    switch(key)
    {
        case Qt::Key_Up:
        {
            if(currentTabRow > 0)
            {
                resetTabs();
                CustomTabBar *bar = _tabs.at(currentTabRow-1);
                bar->setFocus();
                currentTabChange(bar, 0);
            }
            break;
        }
        case Qt::Key_Down:
        {
            if(currentTabRow < _tabs.size()-1)
            {
                resetTabs();
                CustomTabBar *bar = _tabs.at(currentTabRow+1);
                bar->setFocus();
                currentTabChange(bar, 0);
            }
            break;
        }
        default:{}
    }
}

void MultipleRowsTabBar::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    int maximumWidth = 0;
	
    for(CustomTabBar *b : _tabs)
        if(maximumWidth < b->width())
            maximumWidth = b->width();

    for(CustomTabBar *b : _tabs)
        b->setMinimumWidth(maximumWidth);
}
