#ifndef HOVERWIDGET_H
#define HOVERWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <mainwindow.h>
#include <QMenu>
#include <QAction>
#include <timeclock.h>
#include <randomimgcapture.h>
namespace Ui {
class HoverWidget;
}

class HoverWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HoverWidget(QWidget *parent = 0);
    ~HoverWidget();
    void setMainWindow(MainWindow *mainWindow);
    void setTimeClock(TimeClock *timeClock);
    void setImgCapture(RandomImgCapture *);
    int desktopWidth;
    int desktopHeight;
private:
    Ui::HoverWidget *ui;
    QPoint relativePoint;
    MainWindow *mainWindow;
    TimeClock *timeClock;
    RandomImgCapture * imgCapture;
    QApplication *application;
    QMenu menue;
    void initCountDownBar();
private slots:
    void exit();
    void displayMainWindow();
protected:
    //event
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
    //
    void createMenue();
};

#endif // HOVERWIDGET_H
