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
	
	QString _activeStyleSheet = "QTabBar::tab { "
                                "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, "
                                "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3); "
                                "border: 1px solid #C4C4C3; "
                                "border-top-left-radius: 2px; "
                                "border-top-right-radius: 2px; "
                                "padding: 3px; } "
                                "QTabBar::tab:hover, QTabBar::tab:selected { "
                                "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                "stop: 0 #fafafa, stop: 0.4 #f4f4f4, "
                                "stop: 0.5 #e7e7e7, stop: 1.0 #fafafa); } ";
    QString _inactiveStyleSheet = "QTabBar::tab, QTabBar::tab:selected { "
                                  "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD, "
                                  "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3); "
                                  "border: 1px solid #C4C4C3; "
                                  "border-top-left-radius: 2px; "
                                  "border-top-right-radius: 2px; "
                                  "padding: 3px; } "
                                  "QTabBar::tab:hover { "
                                  "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, "
                                  "stop: 0 #fafafa, stop: 0.4 #f4f4f4, "
                                  "stop: 0.5 #e7e7e7, stop: 1.0 #fafafa); }";

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
