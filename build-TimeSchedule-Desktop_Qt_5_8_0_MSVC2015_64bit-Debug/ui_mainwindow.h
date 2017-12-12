/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *ScheduleTab;
    QTableView *ScheduleView;
    QPushButton *addMissionBtn;
    QPushButton *deleteMissionBtn;
    QPushButton *updateMissionBtn;
    QPushButton *updateAllBtn;
    QWidget *RecordTab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(670, 368);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, 10, 671, 321));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        ScheduleTab = new QWidget();
        ScheduleTab->setObjectName(QStringLiteral("ScheduleTab"));
        ScheduleView = new QTableView(ScheduleTab);
        ScheduleView->setObjectName(QStringLiteral("ScheduleView"));
        ScheduleView->setGeometry(QRect(0, 40, 651, 231));
        addMissionBtn = new QPushButton(ScheduleTab);
        addMissionBtn->setObjectName(QStringLiteral("addMissionBtn"));
        addMissionBtn->setGeometry(QRect(440, 0, 31, 23));
        deleteMissionBtn = new QPushButton(ScheduleTab);
        deleteMissionBtn->setObjectName(QStringLiteral("deleteMissionBtn"));
        deleteMissionBtn->setGeometry(QRect(590, 0, 31, 23));
        updateMissionBtn = new QPushButton(ScheduleTab);
        updateMissionBtn->setObjectName(QStringLiteral("updateMissionBtn"));
        updateMissionBtn->setGeometry(QRect(490, 0, 31, 23));
        updateAllBtn = new QPushButton(ScheduleTab);
        updateAllBtn->setObjectName(QStringLiteral("updateAllBtn"));
        updateAllBtn->setGeometry(QRect(540, 0, 31, 23));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imgs/res/innerIcons/Internet History.png"), QSize(), QIcon::Active, QIcon::On);
        tabWidget->addTab(ScheduleTab, icon, QString());
        RecordTab = new QWidget();
        RecordTab->setObjectName(QStringLiteral("RecordTab"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imgs/res/innerIcons/Universal Binary.png"), QSize(), QIcon::Active, QIcon::On);
        tabWidget->addTab(RecordTab, icon1, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 670, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        addMissionBtn->setText(QString());
        deleteMissionBtn->setText(QString());
        updateMissionBtn->setText(QString());
        updateAllBtn->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(ScheduleTab), QApplication::translate("MainWindow", "Schedule", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(RecordTab), QApplication::translate("MainWindow", "Record", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
