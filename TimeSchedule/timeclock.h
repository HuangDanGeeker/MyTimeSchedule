#ifndef TIMECLOCK_H
#define TIMECLOCK_H

#include <QObject>
#include <datastructs.h>
#include <QTimer>
#include <mainwindow.h>
#include <QList>
#include <QTime>
#include <dataaccessobject.h>
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

private slots:
    void MissionUpdate(PMISSION mission);
    void MissionUpdateAll(QList<MISSION> missions);
    void MissionDelete(int rowNum);
    void checkInform();

};

#endif // TIMECLOCK_H
