#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <processbardelegate.h>
#include <dateeditdelegate.h>
#include <timeeditdelegate.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("TimeSchedule");
    this->setFixedSize(this->size());
    initScheduleCalendar();

    connect(ui->addMissionBtn, SIGNAL(clicked(bool)), this, SLOT(addMission()));
    connect(ui->deleteMissionBtn, SIGNAL(clicked(bool)), this, SLOT(deleteMission()));
    connect(ui->updateMissionBtn, SIGNAL(clicked(bool)), this, SLOT(updateMission()));
    connect(ui->updateAllBtn, SIGNAL(clicked(bool)), this, SLOT(updateAllMission()));
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
    model->setItem(0, 5, new QStandardItem("12"));
    ProcessBarDelegate * processBar = new ProcessBarDelegate(this);
    ui->ScheduleView->setItemDelegateForColumn(5, processBar);

    model->setItem(0,2, new QStandardItem("2012-12-12"));
    model->setItem(0,3, new QStandardItem("2012-12-12"));
    DateEditDelegate * dateEdit = new DateEditDelegate(this);
    ui->ScheduleView->setItemDelegateForColumn(2, dateEdit);
    ui->ScheduleView->setItemDelegateForColumn(3, dateEdit);

    model->setItem(0, 4, new QStandardItem("12:12:12"));
    TimeEditDelegate * timeEdit = new TimeEditDelegate(this);
    ui->ScheduleView->setItemDelegateForColumn(4, timeEdit);


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
    PMISSION missions = (PMISSION)malloc(sizeof(MISSION) * rowCount);
    for(int i = 0; i < rowCount-1; i++ ){
        missions[i] = getScheduleItem(i);
    }
    emit MissionUpdateAll(missions, rowCount);

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
