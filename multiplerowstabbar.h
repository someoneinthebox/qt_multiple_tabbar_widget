#ifndef MULTIPLEROWSTABBAR_H
#define MULTIPLEROWSTABBAR_H

#include <QWidget>

class CustomTabBar;
class QStackedLayout;
class QVBoxLayout;
class QFrame;
/*!
 * \brief The MultipleRowsTabBar class
 * Multiple QTabBar Widget
 */
class MultipleRowsTabBar : public QWidget
{
    Q_OBJECT

	QFrame *_tabsFrame = nullptr;
	QVBoxLayout *_mainLay = nullptr;	
    QStackedLayout *_stack = nullptr;
    QVector<CustomTabBar *> _tabs;
	
	QString _activeStyleSheet = "QTabBar::tab { "
								"background-color: palette(button);"
                                "border: 1px solid #C4C4C3; "
                                "padding: 3px; } "
                                "QTabBar::tab:hover, QTabBar::tab:selected { "
                                "background-color: palette(light); } "
                                "QTabBar::tab:selected { border-bottom: none; }";
    QString _inactiveStyleSheet = "QTabBar::tab, QTabBar::tab:selected { "
                                  "background-color: palette(button);"
                                  "border: 1px solid #C4C4C3; "
                                  "padding: 3px; } "
                                  "QTabBar::tab:hover { "
                                  "background-color: palette(light); }";		

    QString _tabsFrameStyleSheet = "QFrame#multipleTabBarFrame { "
                                   "border-left: 1px solid #C4C4C3;"
                                   "border-right: 1px solid #C4C4C3;"
                                   "border-bottom: 1px solid #C4C4C3;"
                                   "border-top: none; }";							  

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
    /*!
     * \brief rowToDownLayout
     * Change tabbar order if bar at top in layout
     */
    void rowToDownLayout(CustomTabBar *bar);	

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
    void setCustomActiveStyleSheet(const QString &sheet) { _activeStyleSheet = sheet; }
    void setCustomInActiveStyleSheet(const QString &sheet) { _inactiveStyleSheet = sheet; }
    void setCustomFrameStyleSheet(const QString &sheet) { _tabsFrameStyleSheet = sheet; }	

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
