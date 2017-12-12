#include "timeclock.h"
#include <qdebug.h>
TimeClock::TimeClock(MainWindow *mainWindow, QObject * parent) : QObject(parent)
{
    setMainWindow(mainWindow);

    connect(mainWindow, SIGNAL(MissionUpdate(PMISSION)), this, SLOT(MissionUpdate(PMISSION)));
    connect(mainWindow, SIGNAL(MissionUpdate(int,PMISSION)), this, SLOT(MissionUpdate(int,PMISSION)));
    connect(mainWindow, SIGNAL(MissionUpdateAll(MISSION[],int)), this, SLOT(MissionUpdateAll(MISSION[],int)));
    connect(mainWindow, SIGNAL(MissionDelete(int)), this, SLOT(MissionDelete(int)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(checkInform()));

    timer.setInterval(60000 * 10);

}

void TimeClock::setMainWindow(MainWindow *mainWindow){
    this->mainWindow = mainWindow;
}


void TimeClock::MissionUpdate(PMISSION mission){
    qDebug()<<"Mission update pMission";
    MISSION m = *mission;
    this->missions.append(m);
}

void TimeClock::MissionUpdate(int rowNum, PMISSION mission){
    qDebug()<<"MissionUpdate(int rowNum, PMISSION mission)";
}

void TimeClock::MissionUpdateAll(MISSION missions[], int len){
    qDebug()<<"MissionUpdateAll(MISSION missions[], int len)";
    this->missions.clear();
    for(int i = 0; i < len; i++){
        this->missions.append(missions[i]);
    }
}

void TimeClock::MissionDelete(int rowNum){
    qDebug()<<"MissionDelete(int rowNum)";
    missions.removeAt(rowNum);
}


void TimeClock::checkInform(){
    qDebug()<<"checkInform() every time";
    QString currentHours = QTime::currentTime().toString("hh");
    int currentMins = QTime::currentTime().toString("mm").toInt();
    int minutes = currentMins % 10;
    QString currentTime = currentHours + ":"+QString::number(minutes);

    for(int i = 0; i < this->missions.size(); i++){
        if(QString::compare(missions[i].startDate, QDate::currentDate().toString(Qt::ISODate)) <= 0|| 0 == QString::compare(missions[i].startDate, "")){
            if(QString::compare(missions[i].endDate, QDate::currentDate().toString(Qt::ISODate)) >= 0|| 0 == QString::compare(missions[i].endDate, "")){
                if(QString::compare(currentTime, missions[i].infromTime) == 0){
                    qDebug()<<"infrom at time";
                }
            }
        }
    }
}
