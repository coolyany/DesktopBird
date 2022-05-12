/********************************************************************************
** Form generated from reading UI file 'MainScene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSceneClass
{
public:
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainSceneClass)
    {
        if (MainSceneClass->objectName().isEmpty())
            MainSceneClass->setObjectName(QString::fromUtf8("MainSceneClass"));
        MainSceneClass->resize(595, 349);
        centralWidget = new QWidget(MainSceneClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainSceneClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainSceneClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainSceneClass->setStatusBar(statusBar);

        retranslateUi(MainSceneClass);

        QMetaObject::connectSlotsByName(MainSceneClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainSceneClass)
    {
        MainSceneClass->setWindowTitle(QCoreApplication::translate("MainSceneClass", "MainScene", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSceneClass: public Ui_MainSceneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
