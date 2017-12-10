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
    QWidget *tab;
    QTableView *ScheduleView;
    QPushButton *addMissionBtn;
    QPushButton *deleteMissionBtn;
    QPushButton *updateMissionBtn;
    QPushButton *updateAllBtn;
    QWidget *tab_2;
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
        tabWidget->setGeometry(QRect(0, 10, 671, 321));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        ScheduleView = new QTableView(tab);
        ScheduleView->setObjectName(QStringLiteral("ScheduleView"));
        ScheduleView->setGeometry(QRect(0, 40, 651, 231));
        addMissionBtn = new QPushButton(tab);
        addMissionBtn->setObjectName(QStringLiteral("addMissionBtn"));
        addMissionBtn->setGeometry(QRect(300, 10, 75, 23));
        deleteMissionBtn = new QPushButton(tab);
        deleteMissionBtn->setObjectName(QStringLiteral("deleteMissionBtn"));
        deleteMissionBtn->setGeometry(QRect(560, 10, 75, 23));
        updateMissionBtn = new QPushButton(tab);
        updateMissionBtn->setObjectName(QStringLiteral("updateMissionBtn"));
        updateMissionBtn->setGeometry(QRect(390, 10, 75, 23));
        updateAllBtn = new QPushButton(tab);
        updateAllBtn->setObjectName(QStringLiteral("updateAllBtn"));
        updateAllBtn->setGeometry(QRect(470, 10, 75, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        addMissionBtn->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", Q_NULLPTR));
        deleteMissionBtn->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        updateMissionBtn->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260", Q_NULLPTR));
        updateAllBtn->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\345\205\250\351\203\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
