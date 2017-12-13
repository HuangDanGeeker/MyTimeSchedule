#include "mainwindow.h"
#include <QApplication>
#include <hoverwidget.h>
#include <timeclock.h>
#include <randomimgcapture.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/imgs/res/imgs/icon.ico"));
    RandomImgCapture capture;
    MainWindow mainWindow;
    TimeClock timeClock(&mainWindow, 0);
    HoverWidget h;
    h.setMainWindow(&mainWindow);
    h.setTimeClock(&timeClock);
    h.setImgCapture(&capture);
    h.show();

    return a.exec();
}
