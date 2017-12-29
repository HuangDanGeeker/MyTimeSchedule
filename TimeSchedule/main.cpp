#include "mainwindow.h"
#include <QApplication>
#include <hoverwidget.h>
#include <timeclock.h>
#include <randomimgcapture.h>
#include <dataaccessobject.h>
#include <QSettings>

#define REG_RUN "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
//实现开机启动功能 执行一次即可
//    QString application_name = "TimeSchedule";
//    QSettings *settings = new QSettings(REG_RUN, QSettings::NativeFormat);
//    QString application_path = QApplication::applicationFilePath();
//    settings->setValue(application_name, application_path.replace("/", "\\"));


    a.setWindowIcon(QIcon(":/imgs/res/imgs/icon.ico"));
    RandomImgCapture capture;
    MainWindow mainWindow;
    TimeClock timeClock(&mainWindow, 0);
    mainWindow.initProperties();
    HoverWidget h;
    h.setMainWindow(&mainWindow);
    h.setTimeClock(&timeClock);
    h.setImgCapture(&capture);
    h.show();

    mainWindow.updateAllMission();
    return a.exec();
}
