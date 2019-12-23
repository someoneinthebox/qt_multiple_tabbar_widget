#ifndef MULTIPLEROWSTABBAR_H
#define MULTIPLEROWSTABBAR_H

#include <QWidget>

class CustomTabBar;
class QStackedLayout;
/*!
 * \brief The MultipleRowsTabBar class
 * Multiple QTabBar Widget
 */
class MultipleRowsTabBar : public QWidget
{
    Q_OBJECT

    QStackedLayout *_stack = nullptr;
    QVector<CustomTabBar *> _tabs;

    /*!
     * \brief resetTabs
     * Reset selected tabs
     */
    void resetTabs();
    /*!
     * \brief currentTabChange
     * Change tab in selected bar
     */
    void currentTabChange(CustomTabBar *bar, int index);
    /*!
     * \brief changeStack
     * Change widget in QStackLayout
     */
    void changeStack(int index);
    /*!
     * \brief getStackIndex
     * Get index for QStackLayout
     */
    int getStackIndex(int row, int index);

protected:
    /*!
     * \brief showEvent
     * Sets max width for each bar to remove first empty tab
     */
    void showEvent(QShowEvent *event);

public:
    /*!
     * \brief MultipleRowsTabBar
     * MultipleRowsTabBar constructor. Rows - bars num
     */
    explicit MultipleRowsTabBar(int rows, QWidget *parent = 0);
    ~MultipleRowsTabBar(){}
    /*!
     * \brief addTab
	 * Adding new tab in row with (optional) some widget
     */
    void addTab(int row, const QIcon &icon, const QString &text, QWidget *widget = nullptr);
    /*!
     * \brief addTab
	 * Adding new tab in row with (optional) some widget
     */
    void addTab(int row, const QString &text, QWidget *widget = nullptr);
    /*!
     * \brief addWidget
     * Adding widget in QStackLayout
     */
    void addWidget(QWidget *widget);
    void setCurrentTab(int row, int index);

private slots:
    /*!
     * \brief currentChange
     * OnClick reaction and other keyboard events
     */
    void currentChange(int index);
    /*!
     * \brief currentChangeByKey
     * Up and Down arrow keys event handler
     */
    void currentChangeByKey(int key);
};

#endif // MULTIPLEROWSTABBAR_H
