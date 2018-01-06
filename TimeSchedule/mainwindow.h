#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <qdebug.h>
#include <datastructs.h>
#include <QTime>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow * getUI();
private:
    Ui::MainWindow *ui;
    void initScheduleCalendar();
    void initBtn();
    void closeEvent(QCloseEvent *e);
    MISSION getScheduleItem(int rowNum);
    int currentRowNum;
public:
    void initProperties();
    void setTabWidgetIndex(int n);
    void setInformWidgetText(QString title, QString remarks);
signals:
    void MissionUpdate(PMISSION mission);
    void MissionUpdateAll(QList<MISSION> missions);
    void MissionDelete(int rowNum);
    void AbortTerminate();
    void SetTerminateTime(QTime);
    void PauseTerminateTime();
public slots:
    void addMission();
    void addMission(PMISSION mission);
    void addMission(QString title, QString remarks, QString startDate, QString endDate, QString infromTime, QString achievePercence);
    void deleteMission();
    void updateMission();
    void updateMission(PMISSION mission);
    void updateAllMission();
    void abortTerminateSlot();
    void setTerminateTimeSlot(QTime);
    void pauseTerminateTimeSlot();


};

#endif // MAINWINDOW_H
