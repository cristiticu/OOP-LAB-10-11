/********************************************************************************
** Form generated from reading UI file 'MainQWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINQWIDGET_H
#define UI_MAINQWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainQWidgetClass
{
public:

    void setupUi(QWidget *MainQWidgetClass)
    {
        if (MainQWidgetClass->objectName().isEmpty())
            MainQWidgetClass->setObjectName("MainQWidgetClass");
        MainQWidgetClass->resize(600, 400);

        retranslateUi(MainQWidgetClass);

        QMetaObject::connectSlotsByName(MainQWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainQWidgetClass)
    {
        MainQWidgetClass->setWindowTitle(QCoreApplication::translate("MainQWidgetClass", "MainQWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainQWidgetClass: public Ui_MainQWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINQWIDGET_H
