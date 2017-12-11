#include "timeclock.h"
#include <qdebug.h>
TimeClock::TimeClock(MainWindow *mainWindow, QObject * parent) : QObject(parent)
{
    setMainWindow(mainWindow);
    connect(mainWindow, SIGNAL(MissionUpdate(PMISSION)), this, SLOT(MissionUpdate(PMISSION)));
    connect(mainWindow, SIGNAL(MissionUpdate(int rowNum, PMISSION mission)), this, SLOT(MissionUpdate(int rowNum, PMISSION mission)));
    connect(mainWindow, SIGNAL(MissionUpdateAll(MISSION missions[], int len)), this, SLOT(MissionUpdateAll(MISSION missions[], int len)));
    connect(mainWindow, SIGNAL(MissionDelete(int rowNum)), this, SLOT(MissionDelete(int rowNum)));
    int currentMins = QTime::currentTime().toString("mm").toInt();
    int sleepMins = 15 - (currentMins % 15);
    int currentSecs = QTime::currentTime().toString("ss").toInt();
    timer.setInterval((sleepMins*60 - currentSecs)*1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(checkInform()));
    timer.setInterval(60000 * 10);
}


void TimeClock::setMainWindow(MainWindow *mainWindow){
    this->mainWindow = mainWindow;
}


void TimeClock::MissionUpdate(PMISSION mission){
    qDebug()<<"Mission update pMission";
}

void TimeClock::MissionUpdate(int rowNum, PMISSION mission){
    qDebug()<<"MissionUpdate(int rowNum, PMISSION mission)";
}

void TimeClock::MissionUpdateAll(MISSION missions[], int len){
    qDebug()<<"MissionUpdateAll(MISSION missions[], int len)";
}

void TimeClock::MissionDelete(int rowNum){
    qDebug()<<"MissionDelete(int rowNum)";
}


void TimeClock::checkInform(){

}
