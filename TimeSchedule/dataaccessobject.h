#ifndef DATAACCESSOBJECT_H
#define DATAACCESSOBJECT_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <datastructs.h>
class DataAccessObject : public QObject
{
    Q_OBJECT
public:
    explicit DataAccessObject(QObject *parent = 0);
    QString fileName = "schedule.data";
    QFile *file;
    void appendData(QString);
    void appendData(QStringList);
    void deleteAllData();
    QList<MISSION> loadMissions();
signals:

public slots:
};

#endif // DATAACCESSOBJECT_H
