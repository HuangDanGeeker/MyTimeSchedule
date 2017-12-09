#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
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
    horizentalHeaderList <<"title"<<"remarks"<<"startDate"<<"endDate"<<"process";
    model->setHorizontalHeaderLabels(horizentalHeaderList);

    ui->ScheduleView->setModel(model);

}

void MainWindow::closeEvent(QCloseEvent *e){
    e->ignore();
    this->hide();
}
