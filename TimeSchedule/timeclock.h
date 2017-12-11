#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include <QObject>
#include <datastructs.h>
#include <QTimer>
#include <mainwindow.h>
#include <QTime>
class TimeClock : public QObject
{
    Q_OBJECT
public:
    explicit TimeClock(MainWindow *mainWindow, QObject * parent = 0);

private:
    QTimer timer;
    QList<MISSION> misssions;
    MainWindow * mainWindow;
    void setMainWindow(MainWindow *);

private slots:
    void MissionUpdate(PMISSION mission);
    void MissionUpdate(int rowNum, PMISSION mission);
    void MissionUpdateAll(MISSION missions[], int len);
    void MissionDelete(int rowNum);
    void checkInform();
};

#endif // TIMECLOCK_H
