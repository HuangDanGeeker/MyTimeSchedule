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

void HoverWidget::exit(){
    this->close();
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
    showOrHideMainWndwAction->setText("show/hide MainWindow");
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
