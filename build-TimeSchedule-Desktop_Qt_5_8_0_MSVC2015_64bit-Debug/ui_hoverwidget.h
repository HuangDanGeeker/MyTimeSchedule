/********************************************************************************
** Form generated from reading UI file 'hoverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOVERWIDGET_H
#define UI_HOVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HoverWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *HoverWidget)
    {
        if (HoverWidget->objectName().isEmpty())
            HoverWidget->setObjectName(QStringLiteral("HoverWidget"));
        HoverWidget->resize(400, 300);
        label = new QLabel(HoverWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 90, 271, 131));

        retranslateUi(HoverWidget);

        QMetaObject::connectSlotsByName(HoverWidget);
    } // setupUi

    void retranslateUi(QWidget *HoverWidget)
    {
        HoverWidget->setWindowTitle(QApplication::translate("HoverWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("HoverWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HoverWidget: public Ui_HoverWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOVERWIDGET_H
