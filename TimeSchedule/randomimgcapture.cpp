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

    this->timer = new QTimer();
    this->camera = new QCamera();
    this->imageCapture = new QCameraImageCapture(camera);

    this->imageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    this->camera->setCaptureMode(QCamera::CaptureStillImage);

    connect(this->imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(capture(int, QImage)));
    connect(this->timer, SIGNAL(timeout()), this, SLOT(startCapture()));
    timer->start(60000 * 60);
}

RandomImgCapture::~RandomImgCapture()
{
    delete ui;
}


void RandomImgCapture::save(){
    const QPixmap *pixmap = ui->imageLabel->pixmap();
    qDebug()<<"capture saved :"<<pixmap->save("./CapturedImgs/"+QDate::currentDate().toString("yy_MM_dd_")+QTime::currentTime().toString("hhmmss")+".jpg", "JPG");
    this->hide();
}

void RandomImgCapture::notSave(){
    this->hide();
}


void RandomImgCapture::capture(int id, QImage image){

    qDebug()<<"the captured iamge id : " << id;
    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    this->show();
    this->camera->stop();
}


void RandomImgCapture::startCapture(){
    this->camera->start();
    this->imageCapture->capture();
    flag++;
    this->timer->setInterval(60000 * 60 * this->fibonacci[flag]);

}
