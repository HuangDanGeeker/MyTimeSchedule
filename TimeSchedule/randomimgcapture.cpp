#include "randomimgcapture.h"
#include "ui_randomimgcapture.h"
#include <QDate>
#include <QTime>

RandomImgCapture::RandomImgCapture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RandomImgCapture)
{
    ui->setupUi(this);
    ui->imageLabel->setScaledContents(true);
    this->hide();
    connect(ui->saveBtn, SIGNAL(clicked(bool)),this, SLOT(save()));
    connect(ui->notSaveBtn, SIGNAL(clicked(bool)),this, SLOT(notSave()));

    this->captureTimer = new QTimer();
    this->autoSaveTimer = new QTimer();
    this->camera = new QCamera();
    this->imageCapture = new QCameraImageCapture(camera);

    this->imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    this->camera->setCaptureMode(QCamera::CaptureStillImage);

    connect(this->imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(capture(int, QImage)));
    connect(this->captureTimer, SIGNAL(timeout()), this, SLOT(startCapture()));
    connect(this->autoSaveTimer, SIGNAL(timeout()), this, SLOT(autoSave()));
    captureTimer->start(60000 * 60);

    isSaved = false;

    appPath = QApplication::applicationDirPath();
    appPath = appPath.replace("/", "\\");
}

RandomImgCapture::~RandomImgCapture()
{
    delete ui;
}


void RandomImgCapture::save(){
    const QPixmap *pixmap = ui->imageLabel->pixmap();
    qDebug()<<appPath+"/CapturedImgs/"+QDate::currentDate().toString("yy_MM_dd_")+QTime::currentTime().toString("hhmmss")+".jpg";
    qDebug()<<"capture saved :"<<pixmap->save(appPath+"/CapturedImgs/"+QDate::currentDate().toString("yy_MM_dd_")+QTime::currentTime().toString("hhmmss")+".jpg", "JPG");
    this->hide();
    autoSaveTimer->stop();
}

void RandomImgCapture::notSave(){
    this->hide();
}


void RandomImgCapture::capture(int id, QImage image){

    qDebug()<<"the captured iamge id : " << id;
    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    this->show();
    this->camera->stop();
    autoSaveTimer->start(3 * 60000);
}


void RandomImgCapture::startCapture(){
    this->camera->start();
    this->imageCapture->capture();
    flag++;
    this->captureTimer->setInterval(60000 * 60 * this->fibonacci[flag]);

}

void RandomImgCapture::autoSave(){
    const QPixmap *pixmap = ui->imageLabel->pixmap();
    qDebug()<<appPath+"/CapturedImgs/"+QDate::currentDate().toString("yy_MM_dd_")+QTime::currentTime().toString("hhmmss")+".jpg";
    qDebug()<<"capture saved :"<<pixmap->save(appPath+"/CapturedImgs/"+QDate::currentDate().toString("yy_MM_dd_")+QTime::currentTime().toString("hhmmss")+".jpg", "JPG");
    this->hide();
    autoSaveTimer->stop();
}
