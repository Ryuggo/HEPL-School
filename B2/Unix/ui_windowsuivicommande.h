/********************************************************************************
** Form generated from reading UI file 'windowsuivicommande.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSUIVICOMMANDE_H
#define UI_WINDOWSUIVICOMMANDE_H

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

class Ui_WindowSuiviCommande
{
public:
    QWidget *centralWidget;
    QLineEdit *lineE1;
    QLineEdit *lineE2;
    QLineEdit *lineE3;
    QLineEdit *lineE4;
    QCheckBox *checkBoxE1;
    QCheckBox *checkBoxE2;
    QCheckBox *checkBoxE3;
    QCheckBox *checkBoxE4;
    QLabel *label;
    QLabel *labelLivraison;
    QCheckBox *checkBoxLivraison;
    QPushButton *ButtonTerminer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowSuiviCommande)
    {
        if (WindowSuiviCommande->objectName().isEmpty())
            WindowSuiviCommande->setObjectName(QString::fromUtf8("WindowSuiviCommande"));
        WindowSuiviCommande->resize(195, 234);
        centralWidget = new QWidget(WindowSuiviCommande);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineE1 = new QLineEdit(centralWidget);
        lineE1->setObjectName(QString::fromUtf8("lineE1"));
        lineE1->setGeometry(QRect(20, 40, 120, 20));
        lineE1->setReadOnly(true);
        lineE2 = new QLineEdit(centralWidget);
        lineE2->setObjectName(QString::fromUtf8("lineE2"));
        lineE2->setGeometry(QRect(20, 70, 120, 20));
        lineE2->setReadOnly(true);
        lineE3 = new QLineEdit(centralWidget);
        lineE3->setObjectName(QString::fromUtf8("lineE3"));
        lineE3->setGeometry(QRect(20, 100, 120, 20));
        lineE3->setReadOnly(true);
        lineE4 = new QLineEdit(centralWidget);
        lineE4->setObjectName(QString::fromUtf8("lineE4"));
        lineE4->setGeometry(QRect(20, 130, 120, 20));
        lineE4->setReadOnly(true);
        checkBoxE1 = new QCheckBox(centralWidget);
        checkBoxE1->setObjectName(QString::fromUtf8("checkBoxE1"));
        checkBoxE1->setGeometry(QRect(160, 40, 20, 20));
        checkBoxE2 = new QCheckBox(centralWidget);
        checkBoxE2->setObjectName(QString::fromUtf8("checkBoxE2"));
        checkBoxE2->setGeometry(QRect(160, 70, 20, 20));
        checkBoxE3 = new QCheckBox(centralWidget);
        checkBoxE3->setObjectName(QString::fromUtf8("checkBoxE3"));
        checkBoxE3->setGeometry(QRect(160, 100, 20, 20));
        checkBoxE4 = new QCheckBox(centralWidget);
        checkBoxE4->setObjectName(QString::fromUtf8("checkBoxE4"));
        checkBoxE4->setGeometry(QRect(160, 130, 20, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 150, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        labelLivraison = new QLabel(centralWidget);
        labelLivraison->setObjectName(QString::fromUtf8("labelLivraison"));
        labelLivraison->setGeometry(QRect(20, 160, 170, 13));
        QFont font1;
        font1.setPointSize(12);
        labelLivraison->setFont(font1);
        checkBoxLivraison = new QCheckBox(centralWidget);
        checkBoxLivraison->setObjectName(QString::fromUtf8("checkBoxLivraison"));
        checkBoxLivraison->setGeometry(QRect(160, 160, 20, 20));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(100, 190, 75, 23));
        WindowSuiviCommande->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(WindowSuiviCommande);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WindowSuiviCommande->setStatusBar(statusBar);

        retranslateUi(WindowSuiviCommande);

        QMetaObject::connectSlotsByName(WindowSuiviCommande);
    } // setupUi

    void retranslateUi(QMainWindow *WindowSuiviCommande)
    {
        WindowSuiviCommande->setWindowTitle(QApplication::translate("WindowSuiviCommande", "Suivi", 0, QApplication::UnicodeUTF8));
        checkBoxE1->setText(QString());
        checkBoxE2->setText(QString());
        checkBoxE3->setText(QString());
        checkBoxE4->setText(QString());
        label->setText(QApplication::translate("WindowSuiviCommande", "Etape :", 0, QApplication::UnicodeUTF8));
        labelLivraison->setText(QApplication::translate("WindowSuiviCommande", "Livraison ", 0, QApplication::UnicodeUTF8));
        checkBoxLivraison->setText(QString());
        ButtonTerminer->setText(QApplication::translate("WindowSuiviCommande", "Terminer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowSuiviCommande: public Ui_WindowSuiviCommande {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSUIVICOMMANDE_H
