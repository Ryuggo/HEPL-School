/********************************************************************************
** Form generated from reading UI file 'windowtableauaffichage.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWTABLEAUAFFICHAGE_H
#define UI_WINDOWTABLEAUAFFICHAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowTableauAffichage
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowTableauAffichage)
    {
        if (WindowTableauAffichage->objectName().isEmpty())
            WindowTableauAffichage->setObjectName(QString::fromUtf8("WindowTableauAffichage"));
        WindowTableauAffichage->resize(700, 120);
        centralWidget = new QWidget(WindowTableauAffichage);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 20, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 20, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 20, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 20, 20, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(360, 50, 20, 20));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(360, 80, 20, 20));
        WindowTableauAffichage->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WindowTableauAffichage);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        WindowTableauAffichage->setMenuBar(menuBar);
        statusBar = new QStatusBar(WindowTableauAffichage);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WindowTableauAffichage->setStatusBar(statusBar);

        retranslateUi(WindowTableauAffichage);

        QMetaObject::connectSlotsByName(WindowTableauAffichage);
    } // setupUi

    void retranslateUi(QMainWindow *WindowTableauAffichage)
    {
        WindowTableauAffichage->setWindowTitle(QApplication::translate("WindowTableauAffichage", "Planning de la journ\303\251e.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowTableauAffichage", "1:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowTableauAffichage", "2:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WindowTableauAffichage", "3:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WindowTableauAffichage", "4:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("WindowTableauAffichage", "5:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("WindowTableauAffichage", "6:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowTableauAffichage: public Ui_WindowTableauAffichage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWTABLEAUAFFICHAGE_H
