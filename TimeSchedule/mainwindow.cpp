#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <processbardelegate.h>
#include <dateeditdelegate.h>
#include <timeeditdelegate.h>
#include <dataaccessobject.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TimeSchedule");
    this->setFixedSize(this->size());
    initScheduleCalendar();
    initBtn();
    connect(ui->addMissionBtn, SIGNAL(clicked(bool)), this, SLOT(addMission()));
    connect(ui->deleteMissionBtn, SIGNAL(clicked(bool)), this, SLOT(deleteMission()));
    connect(ui->updateMissionBtn, SIGNAL(clicked(bool)), this, SLOT(updateMission()));
    connect(ui->updateAllBtn, SIGNAL(clicked(bool)), this, SLOT(updateAllMission()));
    connect(ui->AbortTerminateBtn, SIGNAL(clicked(bool)), this, SLOT(abortTerminateSlot()));
    connect(ui->terminateTimeEdit, SIGNAL(timeChanged(QTime)), this, SLOT(setTerminateTimeSlot(QTime)));
    connect(ui->PauseTerminateBtn, SIGNAL(clicked(bool)), this, SLOT(pauseTerminateTimeSlot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initScheduleCalendar(){

    QStandardItemModel *model = new QStandardItemModel();
    QStringList horizentalHeaderList;
    horizentalHeaderList <<"title"<<"remarks"<<"startDate"<<"endDate"<<"inform time"<<"process";
    model->setHorizontalHeaderLabels(horizentalHeaderList);

    ui->ScheduleView->setModel(model);
    ui->ScheduleView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ProcessBarDelegate * processBar = new ProcessBarDelegate(this);
    ui->ScheduleView->setItemDelegateForColumn(5, processBar);

    DateEditDelegate * dateEdit = new DateEditDelegate(this);
    ui->ScheduleView->setItemDelegateForColumn(2, dateEdit);
    ui->ScheduleView->setItemDelegateForColumn(3, dateEdit);


    TimeEditDelegate * timeEdit = new TimeEditDelegate(this);
    ui->ScheduleView->setItemDelegateForColumn(4, timeEdit);

    DataAccessObject dao;
    QList<MISSION> missions = dao.loadMissions();
    int achievePercent, now2endDays, start2endDays;
    QDate startDate, endDate;
    QDate currentDate = QDate::currentDate();
    for(int i = 0; i < missions.size(); i++){
        model->setItem(i, 0, new QStandardItem(missions[i].title));
        model->setItem(i, 1, new QStandardItem(missions[i].remarks));
        model->setItem(i, 2, new QStandardItem(missions[i].startDate));
        model->setItem(i, 3, new QStandardItem(missions[i].endDate));
        model->setItem(i, 4, new QStandardItem(missions[i].infromTime));

        startDate = QDate::fromString(missions[i].startDate, "yyyy-MM-dd");
        endDate = QDate::fromString(missions[i].endDate, "yyyy-MM-dd");
        now2endDays = currentDate.daysTo(endDate);
        start2endDays = startDate.daysTo(endDate);
        achievePercent = 100 - (int) now2endDays * 100 / start2endDays;

        model->setItem(i, 5, new QStandardItem(QString::number(achievePercent)));


    }

}



void MainWindow::initBtn(){
    QPixmap icon(tr(":/imgs/res/innerIcons/Add Green Button.png"));
    ui->addMissionBtn->setIcon(icon);
    ui->addMissionBtn->setFixedSize(icon.size());
    ui->addMissionBtn->setToolTip("add a mission");

    icon.load(":/imgs/res/innerIcons/Clear Green Button.png");
    ui->updateMissionBtn->setIcon(icon);
    ui->updateMissionBtn->setFixedSize(icon.size());
    ui->updateMissionBtn->setToolTip("update a added mission");

    icon.load(":/imgs/res/innerIcons/Minus Red Button.png");
    ui->deleteMissionBtn->setIcon(icon);
    ui->deleteMissionBtn->setFixedSize(icon.size());
    ui->deleteMissionBtn->setToolTip("delete the selected missions");

    icon.load(":/imgs/res/innerIcons/Play All.png");
    ui->updateAllBtn->setIcon(icon);
    ui->updateAllBtn->setFixedSize(icon.size());
    ui->updateAllBtn->setToolTip("update all missions");
}

void MainWindow::initProperties(){

    QTime time = ui->terminateTimeEdit->time();
    emit SetTerminateTime(time);
}

void MainWindow::closeEvent(QCloseEvent *e){
    e->ignore();
    this->hide();
}

MISSION MainWindow::getScheduleItem(int rowNum){
    QStandardItemModel * model = (QStandardItemModel *)ui->ScheduleView->model();
    MISSION mission;
    mission.title = model->data(model->index(rowNum, 0)).toString();
    mission.remarks = model->data(model->index(rowNum, 1)).toString();
    mission.startDate = model->data(model->index(rowNum, 2)).toString();
    mission.endDate = model->data(model->index(rowNum, 3)).toString();
    mission.infromTime = model->data(model->index(rowNum, 4)).toString();
    mission.achievePercence = model->data(model->index(rowNum, 5)).toString();

    return mission;
}

void MainWindow::addMission(){
    qDebug()<<"add Missin";
    qDebug()<<ui->ScheduleView->model()->rowCount();
    int rowCount = ui->ScheduleView->model()->rowCount();
    currentRowNum = rowCount;
    QStandardItemModel * model = (QStandardItemModel *)ui->ScheduleView->model();
    model->setItem(rowCount, 0, new QStandardItem(""));
    model->setItem(rowCount, 1, new QStandardItem(""));
    model->setItem(rowCount, 2, new QStandardItem(""));
    model->setItem(rowCount, 3, new QStandardItem(""));
    model->setItem(rowCount, 4, new QStandardItem(""));
    model->setItem(rowCount, 5, new QStandardItem(""));
    qDebug()<<"add success";

}



void MainWindow::addMission(QString title, QString remarks, QString startDate, QString endDate, QString infromTime, QString achievePercence){
    qDebug()<<"add Missin parametered";
    qDebug()<<ui->ScheduleView->model()->rowCount();
    int rowNum = ui->ScheduleView->model()->rowCount();
    currentRowNum = rowNum;
    QStandardItemModel * model = (QStandardItemModel *)ui->ScheduleView->model();
    model->setItem(rowNum, 0, new QStandardItem(title));
    model->setItem(rowNum, 1, new QStandardItem(remarks));
    model->setItem(rowNum, 2, new QStandardItem(startDate));
    model->setItem(rowNum, 3, new QStandardItem(endDate));
    model->setItem(rowNum, 4, new QStandardItem(infromTime));
    model->setItem(rowNum, 5, new QStandardItem(achievePercence));
    qDebug()<<"add success parametered";

    updateMission();
}

void MainWindow::addMission(PMISSION mission){
    addMission(mission->title, mission->remarks, mission->startDate, mission->endDate, mission->infromTime, mission->achievePercence);
}

void MainWindow::deleteMission(){
    qDebug()<<"delete Missin";
    qDebug()<< ui->ScheduleView->currentIndex().row();
    int rowNum = ui->ScheduleView->currentIndex().row();;
    ui->ScheduleView->model()->removeRow(rowNum);
    qDebug()<<"delete mission success";
    emit MissionDelete(rowNum);
}




void MainWindow::updateAllMission(){
    qDebug()<<"update all mission";
    QStandardItemModel * model = (QStandardItemModel*) ui->ScheduleView->model();
    int rowCount = model->rowCount();

    QList<MISSION> missions;
    for(int i = 0; i < rowCount; i++){
        missions << getScheduleItem(i);
    }
    emit MissionUpdateAll(missions);

}

void MainWindow::abortTerminateSlot(){
    emit AbortTerminate();
}
void MainWindow::setTerminateTimeSlot(QTime time){
    emit SetTerminateTime(time);
}
void MainWindow::pauseTerminateTimeSlot(){
    QTime time = ui->terminateTimeEdit->time().addSecs(15 * 60);
    emit SetTerminateTime(time);
}

void MainWindow::updateMission(){
    MISSION mission;

    mission = getScheduleItem(currentRowNum);
    updateMission(&mission);
}

void MainWindow::updateMission(PMISSION mission){
    qDebug()<<"updateMission pMission";
    emit MissionUpdate(mission);
}
