/********************************************************************************
** Form generated from reading UI file 'windowadministrateur.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWADMINISTRATEUR_H
#define UI_WINDOWADMINISTRATEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowAdministrateur
{
public:
    QWidget *centralWidget;
    QLabel *labelCommande;
    QLabel *PersonnelPresent;
    QLabel *labelSelection;
    QLabel *labelNouvelleCommande;
    QLabel *labelNom;
    QLabel *labelEtape;
    QLineEdit *lineSelectionCommande;
    QLineEdit *lineSelectionPersonnel;
    QLineEdit *lineNomCommande;
    QPushButton *ButtonAccepterCommande;
    QPushButton *ButtonAnnulerCommande;
    QPushButton *ButtonAccepteSelection;
    QPushButton *ButtonAnnulerSelection;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *ButtonTerminer;
    QPushButton *ButtonCommande1;
    QPushButton *ButtonPersonnel1;
    QPushButton *ButtonCommande3;
    QPushButton *ButtonCommande2;
    QPushButton *ButtonCommande4;
    QPushButton *ButtonPersonnel4;
    QPushButton *ButtonPersonnel3;
    QPushButton *ButtonPersonnel2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WindowAdministrateur)
    {
        if (WindowAdministrateur->objectName().isEmpty())
            WindowAdministrateur->setObjectName(QString::fromUtf8("WindowAdministrateur"));
        WindowAdministrateur->resize(700, 450);
        centralWidget = new QWidget(WindowAdministrateur);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelCommande = new QLabel(centralWidget);
        labelCommande->setObjectName(QString::fromUtf8("labelCommande"));
        labelCommande->setGeometry(QRect(20, 10, 120, 20));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelCommande->setFont(font);
        PersonnelPresent = new QLabel(centralWidget);
        PersonnelPresent->setObjectName(QString::fromUtf8("PersonnelPresent"));
        PersonnelPresent->setGeometry(QRect(450, 10, 200, 20));
        PersonnelPresent->setFont(font);
        labelSelection = new QLabel(centralWidget);
        labelSelection->setObjectName(QString::fromUtf8("labelSelection"));
        labelSelection->setGeometry(QRect(20, 170, 180, 20));
        labelSelection->setFont(font);
        labelNouvelleCommande = new QLabel(centralWidget);
        labelNouvelleCommande->setObjectName(QString::fromUtf8("labelNouvelleCommande"));
        labelNouvelleCommande->setGeometry(QRect(20, 260, 250, 20));
        labelNouvelleCommande->setFont(font);
        labelNom = new QLabel(centralWidget);
        labelNom->setObjectName(QString::fromUtf8("labelNom"));
        labelNom->setGeometry(QRect(20, 290, 60, 20));
        labelEtape = new QLabel(centralWidget);
        labelEtape->setObjectName(QString::fromUtf8("labelEtape"));
        labelEtape->setGeometry(QRect(20, 320, 81, 16));
        lineSelectionCommande = new QLineEdit(centralWidget);
        lineSelectionCommande->setObjectName(QString::fromUtf8("lineSelectionCommande"));
        lineSelectionCommande->setGeometry(QRect(20, 200, 120, 20));
        lineSelectionCommande->setReadOnly(true);
        lineSelectionPersonnel = new QLineEdit(centralWidget);
        lineSelectionPersonnel->setObjectName(QString::fromUtf8("lineSelectionPersonnel"));
        lineSelectionPersonnel->setGeometry(QRect(200, 200, 120, 20));
        lineSelectionPersonnel->setReadOnly(true);
        lineNomCommande = new QLineEdit(centralWidget);
        lineNomCommande->setObjectName(QString::fromUtf8("lineNomCommande"));
        lineNomCommande->setGeometry(QRect(200, 290, 120, 20));
        ButtonAccepterCommande = new QPushButton(centralWidget);
        ButtonAccepterCommande->setObjectName(QString::fromUtf8("ButtonAccepterCommande"));
        ButtonAccepterCommande->setGeometry(QRect(600, 340, 80, 20));
        ButtonAnnulerCommande = new QPushButton(centralWidget);
        ButtonAnnulerCommande->setObjectName(QString::fromUtf8("ButtonAnnulerCommande"));
        ButtonAnnulerCommande->setGeometry(QRect(600, 370, 80, 20));
        ButtonAccepteSelection = new QPushButton(centralWidget);
        ButtonAccepteSelection->setObjectName(QString::fromUtf8("ButtonAccepteSelection"));
        ButtonAccepteSelection->setGeometry(QRect(40, 230, 80, 20));
        ButtonAnnulerSelection = new QPushButton(centralWidget);
        ButtonAnnulerSelection->setObjectName(QString::fromUtf8("ButtonAnnulerSelection"));
        ButtonAnnulerSelection->setGeometry(QRect(220, 230, 80, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 340, 21, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 370, 21, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(260, 340, 21, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 370, 21, 20));
        ButtonTerminer = new QPushButton(centralWidget);
        ButtonTerminer->setObjectName(QString::fromUtf8("ButtonTerminer"));
        ButtonTerminer->setGeometry(QRect(600, 400, 80, 20));
        ButtonCommande1 = new QPushButton(centralWidget);
        ButtonCommande1->setObjectName(QString::fromUtf8("ButtonCommande1"));
        ButtonCommande1->setGeometry(QRect(145, 48, 30, 20));
        ButtonPersonnel1 = new QPushButton(centralWidget);
        ButtonPersonnel1->setObjectName(QString::fromUtf8("ButtonPersonnel1"));
        ButtonPersonnel1->setGeometry(QRect(335, 50, 30, 20));
        ButtonCommande3 = new QPushButton(centralWidget);
        ButtonCommande3->setObjectName(QString::fromUtf8("ButtonCommande3"));
        ButtonCommande3->setGeometry(QRect(145, 108, 30, 20));
        ButtonCommande2 = new QPushButton(centralWidget);
        ButtonCommande2->setObjectName(QString::fromUtf8("ButtonCommande2"));
        ButtonCommande2->setGeometry(QRect(145, 78, 30, 20));
        ButtonCommande4 = new QPushButton(centralWidget);
        ButtonCommande4->setObjectName(QString::fromUtf8("ButtonCommande4"));
        ButtonCommande4->setGeometry(QRect(145, 138, 30, 20));
        ButtonPersonnel4 = new QPushButton(centralWidget);
        ButtonPersonnel4->setObjectName(QString::fromUtf8("ButtonPersonnel4"));
        ButtonPersonnel4->setGeometry(QRect(335, 138, 30, 20));
        ButtonPersonnel3 = new QPushButton(centralWidget);
        ButtonPersonnel3->setObjectName(QString::fromUtf8("ButtonPersonnel3"));
        ButtonPersonnel3->setGeometry(QRect(335, 108, 30, 20));
        ButtonPersonnel2 = new QPushButton(centralWidget);
        ButtonPersonnel2->setObjectName(QString::fromUtf8("ButtonPersonnel2"));
        ButtonPersonnel2->setGeometry(QRect(335, 78, 30, 20));
        WindowAdministrateur->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WindowAdministrateur);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        WindowAdministrateur->setMenuBar(menuBar);
        statusBar = new QStatusBar(WindowAdministrateur);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WindowAdministrateur->setStatusBar(statusBar);

        retranslateUi(WindowAdministrateur);

        QMetaObject::connectSlotsByName(WindowAdministrateur);
    } // setupUi

    void retranslateUi(QMainWindow *WindowAdministrateur)
    {
        WindowAdministrateur->setWindowTitle(QApplication::translate("WindowAdministrateur", "Administrateur.", 0, QApplication::UnicodeUTF8));
        labelCommande->setText(QApplication::translate("WindowAdministrateur", "Commandes:", 0, QApplication::UnicodeUTF8));
        PersonnelPresent->setText(QApplication::translate("WindowAdministrateur", "Personnels pr\303\251sents:", 0, QApplication::UnicodeUTF8));
        labelSelection->setText(QApplication::translate("WindowAdministrateur", "S\303\251lection:", 0, QApplication::UnicodeUTF8));
        labelNouvelleCommande->setText(QApplication::translate("WindowAdministrateur", "Nouvelle Commande:", 0, QApplication::UnicodeUTF8));
        labelNom->setText(QApplication::translate("WindowAdministrateur", "Nom:", 0, QApplication::UnicodeUTF8));
        labelEtape->setText(QApplication::translate("WindowAdministrateur", "Etape(s):", 0, QApplication::UnicodeUTF8));
        ButtonAccepterCommande->setText(QApplication::translate("WindowAdministrateur", "Accepter", 0, QApplication::UnicodeUTF8));
        ButtonAnnulerCommande->setText(QApplication::translate("WindowAdministrateur", "Annuler", 0, QApplication::UnicodeUTF8));
        ButtonAccepteSelection->setText(QApplication::translate("WindowAdministrateur", "Accepter", 0, QApplication::UnicodeUTF8));
        ButtonAnnulerSelection->setText(QApplication::translate("WindowAdministrateur", "Annuler", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WindowAdministrateur", "1:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WindowAdministrateur", "3:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WindowAdministrateur", "2:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("WindowAdministrateur", "4:", 0, QApplication::UnicodeUTF8));
        ButtonTerminer->setText(QApplication::translate("WindowAdministrateur", "Terminer", 0, QApplication::UnicodeUTF8));
        ButtonCommande1->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonPersonnel1->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonCommande3->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonCommande2->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonCommande4->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonPersonnel4->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonPersonnel3->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
        ButtonPersonnel2->setText(QApplication::translate("WindowAdministrateur", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WindowAdministrateur: public Ui_WindowAdministrateur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWADMINISTRATEUR_H
