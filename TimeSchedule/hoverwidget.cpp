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
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    int imageWidth = desktopWidget->width()*0.07;
    int imageheight = desktopWidget->height()*0.07;

    QImage image;
    image.load("E:\\QtLearn\\TimeSchedule\\TimeSchedule\\res\\imgs\\haimian.jpg");

    ui->label->setPixmap(QPixmap::fromImage(image.scaled(imageWidth, imageheight, Qt::KeepAspectRatio)));
    ui->label->resize(image.size());

    ui->label->show();

    createMenue();
}

HoverWidget::~HoverWidget()
{
    delete ui;
}


void HoverWidget::mouseMoveEvent(QMouseEvent *event){
    this->move(relativePoint + event->globalPos());

}

void HoverWidget::mousePressEvent(QMouseEvent * event){
    if(event->button() == Qt::LeftButton){
        relativePoint = this->pos() - event->globalPos();
    }else if(event->button() == Qt::RightButton){
//        menue.exec(event->globalPos());
//            menue.exec(this->pos() - event->globalPos());
            qDebug()<<this->pos().x() <<" " <<this->pos().y();
            qDebug()<<event->pos().x();
            qDebug()<<event->globalPos().x();

//        menue.show();
    }
}
void HoverWidget::mouseDoubleClickEvent(QMouseEvent *event){
    this->mainWindow->isHidden() ? this->mainWindow->show() : this->mainWindow->hide();

}

void HoverWidget::contextMenuEvent(QContextMenuEvent *event){
//    menue.exec(event->pos());
//    menue.show();
//    event->accept();
}

void HoverWidget::createMenue(){

    QAction *showOrHideMainWndwAction = new QAction(this);
    showOrHideMainWndwAction->setText("show/hide MainWindow");
    QAction *exitAction = new QAction(this);
    exitAction->setText("exit");

    connect(showOrHideMainWndwAction, SIGNAL(toggled(bool)), this, SLOT());
    connect(exitAction, SIGNAL(toggled(bool)), this, SLOT());

    menue.addAction(showOrHideMainWndwAction);
    menue.addAction(exitAction);


}

void HoverWidget::setMainWindow(MainWindow *mainWindow){
    this->mainWindow = mainWindow;
}
