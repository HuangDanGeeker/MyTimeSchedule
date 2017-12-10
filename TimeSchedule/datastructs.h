#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <QString>
typedef struct Mission{
    QString title;
    QString remarks;
    QString startDate;
    QString endDate;
    QString infromTime;
    QString achievePercence;
}MISSION, *PMISSION;

#endif // DATASTRUCTS_H
