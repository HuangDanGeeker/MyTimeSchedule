#ifndef RANDOMIMGCAPTURE_H
#define RANDOMIMGCAPTURE_H

#include <QDialog>
#include <QCamera>
#include <QCameraImageCapture>
#include <QDebug>
#include <qdialog.h>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
namespace Ui {
class RandomImgCapture;
}

class RandomImgCapture : public QDialog
{
    Q_OBJECT

public:
    explicit RandomImgCapture(QWidget *parent = 0);
    ~RandomImgCapture();

private:
    Ui::RandomImgCapture *ui;
    QCamera *camera;
    QTimer *captureTimer;
    QTimer *autoSaveTimer;
    QCameraImageCapture * imageCapture;
    int flag = 0;
    int fibonacci[12] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    bool isSaved;
private slots:
    void save();
    void notSave();
    void capture(int, QImage);
    void startCapture();
    void autoSave();
};

#endif // RANDOMIMGCAPTURE_H
