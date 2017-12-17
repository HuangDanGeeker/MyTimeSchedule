#include "dataaccessobject.h"
#include <QMessageBox>

DataAccessObject::DataAccessObject(QObject *parent) : QObject(parent)
{
    file = new QFile(fileName);
}

void DataAccessObject::appendData(QString data){
    QTextStream stream(file);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
//        QMessageBox::warning(this, "warning","file open failed", QMessageBox::Yes, QMessageBox::Yes);

        return;
    }
    stream<<data;
//    QMessageBox::information(this, "inform", "add schedule data success");
}

void DataAccessObject::appendData(QStringList dataList){
    QTextStream stream(file);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
//        QMessageBox::warning(this, "warning","file open failed");
        return;
    }
    for(int i = 0; i < dataList.size(); i++){
        stream<<dataList[i];
    }
//    QMessageBox::information(this, "inform", "add schedule data success");
}

void DataAccessObject::deleteAllData(){
    file->remove();
//    QMessageBox::information(this, "inform", "delete schedule data success");
    file->open(QIODevice::WriteOnly);
}

QList<MISSION> DataAccessObject::loadMissions(){

    QList<MISSION> missionList;
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
//        QMessageBox::warning(this, "warnig","file open failed");
        return missionList;
    }
    QTextStream stream(file);
    MISSION mission;
    QStringList MissionParts;
    while(!stream.atEnd()){
        MissionParts =  stream.readLine().split(" ");
        mission.title = MissionParts[0];
        mission.remarks = MissionParts[1];
        mission.startDate = MissionParts[3];
        mission.endDate = MissionParts[4];
        mission.infromTime = MissionParts[5];
        mission.achievePercence = MissionParts[6];
        missionList<<mission;
    }

    return missionList;
}
