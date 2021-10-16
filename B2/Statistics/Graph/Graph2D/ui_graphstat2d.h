/********************************************************************************
** Form generated from reading UI file 'graphstat2d.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHSTAT2D_H
#define UI_GRAPHSTAT2D_H

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

class Ui_GraphStat2D
{
public:
    QWidget *centralWidget;
    QLabel *labelEquation;
    QLineEdit *lineEquation;
    QPushButton *ButtonTracer;
    QPushButton *ButtonAnnuler;
    QPushButton *ButtonSelectionner;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphStat2D)
    {
        if (GraphStat2D->objectName().isEmpty())
            GraphStat2D->setObjectName(QString::fromUtf8("GraphStat2D"));
        GraphStat2D->resize(500, 500);
        centralWidget = new QWidget(GraphStat2D);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelEquation = new QLabel(centralWidget);
        labelEquation->setObjectName(QString::fromUtf8("labelEquation"));
        labelEquation->setGeometry(QRect(30, 400, 70, 20));
        lineEquation = new QLineEdit(centralWidget);
        lineEquation->setObjectName(QString::fromUtf8("lineEquation"));
        lineEquation->setGeometry(QRect(140, 400, 330, 20));
        lineEquation->setReadOnly(true);
        ButtonTracer = new QPushButton(centralWidget);
        ButtonTracer->setObjectName(QString::fromUtf8("ButtonTracer"));
        ButtonTracer->setGeometry(QRect(30, 440, 120, 25));
        ButtonAnnuler = new QPushButton(centralWidget);
        ButtonAnnuler->setObjectName(QString::fromUtf8("ButtonAnnuler"));
        ButtonAnnuler->setGeometry(QRect(370, 440, 100, 25));
        ButtonSelectionner = new QPushButton(centralWidget);
        ButtonSelectionner->setObjectName(QString::fromUtf8("ButtonSelectionner"));
        ButtonSelectionner->setGeometry(QRect(250, 440, 100, 25));
        GraphStat2D->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphStat2D);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 21));
        GraphStat2D->setMenuBar(menuBar);
        statusBar = new QStatusBar(GraphStat2D);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GraphStat2D->setStatusBar(statusBar);

        retranslateUi(GraphStat2D);

        QMetaObject::connectSlotsByName(GraphStat2D);
    } // setupUi

    void retranslateUi(QMainWindow *GraphStat2D)
    {
        GraphStat2D->setWindowTitle(QApplication::translate("GraphStat2D", "GraphStat2D", 0, QApplication::UnicodeUTF8));
        labelEquation->setText(QApplication::translate("GraphStat2D", "Equation :", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ButtonTracer->setToolTip(QApplication::translate("GraphStat2D", "<html><head/><body><p>Ctrl-T</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ButtonTracer->setText(QApplication::translate("GraphStat2D", "Tracer la droite", 0, QApplication::UnicodeUTF8));
        ButtonTracer->setShortcut(QApplication::translate("GraphStat2D", "Ctrl+T", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ButtonAnnuler->setToolTip(QApplication::translate("GraphStat2D", "<html><head/><body><p>Ctrl-Z</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ButtonAnnuler->setText(QApplication::translate("GraphStat2D", "Annuler", 0, QApplication::UnicodeUTF8));
        ButtonAnnuler->setShortcut(QApplication::translate("GraphStat2D", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ButtonSelectionner->setToolTip(QApplication::translate("GraphStat2D", "<html><head/><body><p>Ctrl-S</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ButtonSelectionner->setText(QApplication::translate("GraphStat2D", "Selectionner", 0, QApplication::UnicodeUTF8));
        ButtonSelectionner->setShortcut(QApplication::translate("GraphStat2D", "Ctrl+S", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GraphStat2D: public Ui_GraphStat2D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHSTAT2D_H
