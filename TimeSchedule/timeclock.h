#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include <QObject>
#include <datastructs.h>
#include <QTimer>
#include <mainwindow.h>
#include <QList>
#include <QTime>
#include <dataaccessobject.h>
#include <QProcess>
class TimeClock : public QObject
{
    Q_OBJECT
public:
    explicit TimeClock(MainWindow *mainWindow, QObject * parent = 0);
    ~TimeClock(){
        DataAccessObject dao;
        dao.deleteAllData();
        dao.save(missions);
    }
private:
    QTimer timer;
    QList<MISSION> missions;
    MainWindow * mainWindow;
    void setMainWindow(MainWindow *);
    bool isTerminate;
    QTime terminateTime;
    QProcess *process;
private slots:
    void MissionUpdate(PMISSION mission);
    void MissionUpdateAll(QList<MISSION> missions);
    void MissionDelete(int rowNum);
    void checkInform();
    void SetTerminateTime(QTime);
    void AbortTerminate();

};

#endif // TIMECLOCK_H
