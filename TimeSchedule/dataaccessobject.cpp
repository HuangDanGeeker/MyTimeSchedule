#include "dataaccessobject.h"
#include <QMessageBox>

DataAccessObject::DataAccessObject(QObject *parent) : QObject(parent)
{
    file = new QFile(fileName);
}

void DataAccessObject::appendData(QString data){
    QTextStream stream(file);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(NULL, "warning","file open failed", QMessageBox::Yes, QMessageBox::Yes);

        return;
    }
    stream<<data;
//    QMessageBox::information(NULL, "inform", "add schedule data success");
}

void DataAccessObject::appendData(QStringList dataList){
    QTextStream stream(file);
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(NULL, "warning","file open failed");
        return;
    }
    for(int i = 0; i < dataList.size(); i++){
        stream<<dataList[i];
    }
//    QMessageBox::information(NULL, "inform", "add schedule data success");
}

void DataAccessObject::deleteAllData(){
    file->remove();
//    QMessageBox::information(NULL, "inform", "delete schedule data success");
    file->open(QIODevice::WriteOnly);
}

QList<MISSION> DataAccessObject::loadMissions(){

    QList<MISSION> missionList;
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(NULL, "warnig","file open failed");
        return missionList;
    }
    QTextStream stream(file);
    MISSION mission;
    QStringList MissionParts;
    while(!stream.atEnd()){
        MissionParts =  stream.readLine().split(" ");
        mission.title = MissionParts[0];
        mission.remarks = MissionParts[1];
        mission.startDate = MissionParts[2];
        mission.endDate = MissionParts[3];
        mission.infromTime = MissionParts[4];
        mission.achievePercence = "0";
        missionList.append(mission);
    }
//    QMessageBox::information(NULL, "inform", "load schedule data success");
    return missionList;
}


void DataAccessObject::save(QStringList dataList){
    file->remove();
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(NULL, "warning", "file open failed");
        return;
    }
    QTextStream stream(file);
    for(int i = 0; i < dataList.size(); i++){
        stream<<dataList[i];
    }
}

void DataAccessObject::save(QList<MISSION> dataList){
    QStringList dataStringList;
    QString data = "";
    MISSION mission;
    for(int i = 0; i < dataList.size(); i++){
        mission = dataList[i];
        data = mission.title + " " + mission.remarks +" " + mission.startDate +" "+mission.endDate+" "+mission.infromTime+" "+ mission.achievePercence+"\n";
        dataStringList<<data;
    }
    save(dataStringList);
}
