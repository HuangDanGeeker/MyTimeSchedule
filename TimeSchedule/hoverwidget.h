#ifndef HOVERWIDGET_H
#define HOVERWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <mainwindow.h>
#include <QMenu>
#include <QAction>
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
private:
    Ui::HoverWidget *ui;
    QPoint relativePoint;
    MainWindow *mainWindow;
    QMenu menue;
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
