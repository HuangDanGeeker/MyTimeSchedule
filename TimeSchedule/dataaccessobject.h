#ifndef DATAACCESSOBJECT_H
#define DATAACCESSOBJECT_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <datastructs.h>
#include <QApplication>
class DataAccessObject : public QObject
{
    Q_OBJECT
public:
    explicit DataAccessObject(QObject *parent = 0);
    QString fileName = QApplication::applicationDirPath()+"/schedule.data";
    QFile *file;
    void appendData(QString);
    void appendData(QStringList);
    void deleteAllData();
    void save(QStringList);
    void save(QList<MISSION>);
    QList<MISSION> loadMissions();
signals:

public slots:
};

#endif // DATAACCESSOBJECT_H
