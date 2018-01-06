#include "hoverwidget.h"
#include "ui_hoverwidget.h"
#include <QPixmap>
#include <QDebug>
#include <QDir>
#include <QDesktopWidget>
HoverWidget::HoverWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HoverWidget)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint | Qt::Tool);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    desktopWidth = desktopWidget->width();
    desktopHeight = desktopWidget->height();

    QImage image;
    image.load("E:\\QtLearn\\TimeSchedule\\TimeSchedule\\res\\imgs\\haimian.jpg");

    ui->label->setPixmap(QPixmap::fromImage(image.scaled(desktopWidth*0.07, desktopHeight*0.07, Qt::KeepAspectRatio)));
    ui->label->resize(image.size());


    initCountDownBar();

    ui->label->show();



    //图标右上角悬浮
    QDesktopWidget* desktop=QApplication::desktop();//获取屏幕尺寸

    move((desktop->width() *0.85),desktop->height() *0.03 - 50);//移到右上角

    createMenue();
}

HoverWidget::~HoverWidget()
{
    delete ui;
}

void HoverWidget::initCountDownBar(){
    ui->CountDownBar->setGeometry(ui->label->x(), ui->label->y()+110, ui->CountDownBar->width()-65, ui->CountDownBar->height());
    int totalDays = QDate(2018,1,1).daysTo(QDate(2018,3,10));
    int leftDays = QDate::currentDate().daysTo(QDate(2018,3,10));
    int value = (leftDays * 100 / totalDays);
    ui->CountDownBar->setValue(value);

    //设置tooltip 失败
//    QString toolTipText = QString::number(value)+"% left";
    ui->CountDownBar->setToolTip("ssssssssss");
    if(value < 10){
        ui->CountDownBar->setStyleSheet("QProgressBar::chunk { background-color: #d9534f }");
    }else if(value <= 40){
        ui->CountDownBar->setStyleSheet("QProgressBar::chunk { background-color: #f0ad4e }");
    }else if(value <= 60){
        ui->CountDownBar->setStyleSheet("QProgressBar::chunk { background-color: #337ab7 }");
    }else if(value <= 80){
        ui->CountDownBar->setStyleSheet("QProgressBar::chunk { background-color: #5bc0de }");
    }else{
        ui->CountDownBar->setStyleSheet("QProgressBar::chunk { background-color: #5cb85c }");
    }
}

void HoverWidget::exit(){
    this->close();
    this->mainWindow->close();
    this->imgCapture->close();
}

//将主界面显示或隐藏
void HoverWidget::displayMainWindow(){
    this->mainWindow->isHidden() ? this->mainWindow->show() : this->mainWindow->hide();
}


void HoverWidget::mouseMoveEvent(QMouseEvent *event){
    this->move(relativePoint + event->globalPos());
    if(this->pos().x() >= desktopWidth - 20){
        this->move(desktopWidth/2, this->pos().y());
    }
    if(this->pos().y() >= desktopHeight - 20){
        this->move(this->pos().x(), desktopHeight/2);
    }
}

void HoverWidget::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        relativePoint = this->pos() - event->globalPos();
    }else if(event->button() == Qt::RightButton){

    }
}
void HoverWidget::mouseDoubleClickEvent(QMouseEvent *event){
    displayMainWindow();
}

void HoverWidget::contextMenuEvent(QContextMenuEvent *event){
    menue.move(event->globalPos());
    menue.show();
    event->accept();
}

void HoverWidget::createMenue(){

    QAction *showOrHideMainWndwAction = new QAction(this);
    showOrHideMainWndwAction->setText("MainWindow");
    QAction *exitAction = new QAction(this);
    exitAction->setText("exit");

    connect(showOrHideMainWndwAction, SIGNAL(triggered(bool)), this, SLOT(displayMainWindow()));

    connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(exit()));

    menue.addAction(showOrHideMainWndwAction);
    menue.addAction(exitAction);


}

void HoverWidget::setMainWindow(MainWindow *mainWindow){
    this->mainWindow = mainWindow;
}
void HoverWidget::setTimeClock(TimeClock *timeClock){
    this->timeClock = timeClock;
}
void HoverWidget::setImgCapture(RandomImgCapture *imgCapture){
    this->imgCapture = imgCapture;
}
