#include "mainwindow.h"
#include <QApplication>
#include <hoverwidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/imgs/res/imgs/icon.ico"));
    MainWindow w;
//    w.show();

    HoverWidget h;
    h.setMainWindow(&w);
    h.show();
    return a.exec();
}
