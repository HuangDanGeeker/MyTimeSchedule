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

//    model->setItem(0,2, new QStandardItem("2012-12-12"));
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
