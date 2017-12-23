#include "timeclock.h"
#include <qdebug.h>
#include <Windows.h>
TimeClock::TimeClock(MainWindow *mainWindow, QObject * parent) : QObject(parent)
{
    setMainWindow(mainWindow);

    connect(mainWindow, SIGNAL(MissionUpdate(PMISSION)), this, SLOT(MissionUpdate(PMISSION)));
    connect(mainWindow, SIGNAL(MissionUpdateAll(QList<MISSION>)), this, SLOT(MissionUpdateAll(QList<MISSION>)));
    connect(mainWindow, SIGNAL(MissionDelete(int)), this, SLOT(MissionDelete(int)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(checkInform()));

    timer.start(60000 * 10);


}

void TimeClock::setMainWindow(MainWindow *mainWindow){
    this->mainWindow = mainWindow;
}


void TimeClock::MissionUpdate(PMISSION mission){
    qDebug()<<"Mission update pMission";
    MISSION m = *mission;
    this->missions.append(m);
}


void TimeClock::MissionUpdateAll(QList<MISSION> missions){
    qDebug()<<"MissionUpdateAll(MISSION missions[])";
    this->missions.clear();
    for(int i = 0; i < missions.size(); i++){
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
    int minutes = (currentMins / 10) * 10;
    QString currentTime = currentHours + ":"+QString("%1").arg(minutes,2,10,QLatin1Char('0'));

    for(int i = 0; i < this->missions.size(); i++){
        if(QString::compare(missions[i].startDate, QDate::currentDate().toString(Qt::ISODate)) <= 0|| 0 == QString::compare(missions[i].startDate, "")){
            if(QString::compare(missions[i].endDate, QDate::currentDate().toString(Qt::ISODate)) >= 0|| 0 == QString::compare(missions[i].endDate, "")){
                if(QString::compare(currentTime, missions[i].infromTime) == 0){
                    qDebug()<<"infrom at time";
                    if(this->mainWindow->isHidden())
                        this->mainWindow->show();
                    else{
                        this->mainWindow->hide();
                        Sleep(800);
                        this->mainWindow->show();
                    }
                }
            }
        }
    }

}
