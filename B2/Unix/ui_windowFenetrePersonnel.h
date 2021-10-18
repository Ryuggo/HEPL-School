/********************************************************************************
** Form generated from reading UI file 'windowFenetrePersonnel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWFENETREPERSONNEL_H
#define UI_WINDOWFENETREPERSONNEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowFenetrePersonnel
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineE1;
    QLineEdit *lineE2;
    QLineEdit *lineE3;
    QLineEdit *lineE4;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QPushButton *BoutonTerminer;
    QCheckBox *checkBox1;
    QCheckBox *checkBox2;
    QCheckBox *checkBox3;
    QCheckBox *checkBox4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *windowFenetrePersonnel)
    {
        if (windowFenetrePersonnel->objectName().isEmpty())
            windowFenetrePersonnel->setObjectName(QString::fromUtf8("windowFenetrePersonnel"));
        windowFenetrePersonnel->resize(315, 193);
        centralWidget = new QWidget(windowFenetrePersonnel);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 271, 21));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        lineE1 = new QLineEdit(centralWidget);
        lineE1->setObjectName(QString::fromUtf8("lineE1"));
        lineE1->setGeometry(QRect(20, 60, 113, 20));
        lineE1->setReadOnly(true);
        lineE2 = new QLineEdit(centralWidget);
        lineE2->setObjectName(QString::fromUtf8("lineE2"));
        lineE2->setGeometry(QRect(170, 60, 113, 20));
        lineE2->setReadOnly(true);
        lineE3 = new QLineEdit(centralWidget);
        lineE3->setObjectName(QString::fromUtf8("lineE3"));
        lineE3->setGeometry(QRect(20, 110, 113, 20));
        lineE3->setReadOnly(true);
        lineE4 = new QLineEdit(centralWidget);
        lineE4->setObjectName(QString::fromUtf8("lineE4"));
        lineE4->setGeometry(QRect(170, 110, 113, 20));
        lineE4->setReadOnly(true);
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(20, 40, 111, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label1->setFont(font1);
        label2 = new QLabel(centralWidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(170, 40, 111, 16));
        label2->setFont(font1);
        label3 = new QLabel(centralWidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(20, 90, 111, 20));
        label3->setFont(font1);
        label4 = new QLabel(centralWidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(170, 90, 111, 16));
        label4->setFont(font1);
        BoutonTerminer = new QPushButton(centralWidget);
        BoutonTerminer->setObjectName(QString::fromUtf8("BoutonTerminer"));
        BoutonTerminer->setGeometry(QRect(230, 140, 75, 23));
        checkBox1 = new QCheckBox(centralWidget);
        checkBox1->setObjectName(QString::fromUtf8("checkBox1"));
        checkBox1->setGeometry(QRect(140, 60, 20, 20));
        checkBox2 = new QCheckBox(centralWidget);
        checkBox2->setObjectName(QString::fromUtf8("checkBox2"));
        checkBox2->setGeometry(QRect(290, 60, 20, 20));
        checkBox3 = new QCheckBox(centralWidget);
        checkBox3->setObjectName(QString::fromUtf8("checkBox3"));
        checkBox3->setGeometry(QRect(140, 110, 20, 20));
        checkBox4 = new QCheckBox(centralWidget);
        checkBox4->setObjectName(QString::fromUtf8("checkBox4"));
        checkBox4->setGeometry(QRect(290, 110, 20, 20));
        windowFenetrePersonnel->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(windowFenetrePersonnel);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        windowFenetrePersonnel->setStatusBar(statusBar);

        retranslateUi(windowFenetrePersonnel);

        QMetaObject::connectSlotsByName(windowFenetrePersonnel);
    } // setupUi

    void retranslateUi(QMainWindow *windowFenetrePersonnel)
    {
        windowFenetrePersonnel->setWindowTitle(QApplication::translate("windowFenetrePersonnel", "windowFenetrePersonnel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("windowFenetrePersonnel", "***:", 0, QApplication::UnicodeUTF8));
        label1->setText(QApplication::translate("windowFenetrePersonnel", "Etape 1: ", 0, QApplication::UnicodeUTF8));
        label2->setText(QApplication::translate("windowFenetrePersonnel", "Etape 2 :", 0, QApplication::UnicodeUTF8));
        label3->setText(QApplication::translate("windowFenetrePersonnel", "Etape 3 :", 0, QApplication::UnicodeUTF8));
        label4->setText(QApplication::translate("windowFenetrePersonnel", "Etape 4 :", 0, QApplication::UnicodeUTF8));
        BoutonTerminer->setText(QApplication::translate("windowFenetrePersonnel", "Terminer", 0, QApplication::UnicodeUTF8));
        checkBox1->setText(QString());
        checkBox2->setText(QString());
        checkBox3->setText(QString());
        checkBox4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class windowFenetrePersonnel: public Ui_windowFenetrePersonnel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWFENETREPERSONNEL_H
