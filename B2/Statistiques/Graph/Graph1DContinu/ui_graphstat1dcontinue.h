/********************************************************************************
** Form generated from reading UI file 'graphstat1dcontinue.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHSTAT1DCONTINUE_H
#define UI_GRAPHSTAT1DCONTINUE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphStat1DContinue
{
public:
    QWidget *centralWidget;
    QLabel *labelHistogramme;
    QLabel *labelHistogrammeCumule;
    QLabel *labelMoyenne;
    QLineEdit *lineMoyenne;
    QLabel *labelEcartType;
    QLineEdit *lineEcartType;
    QLabel *labelMediane;
    QLineEdit *lineMediane;
    QLabel *labelMode;
    QLineEdit *lineMode;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphStat1DContinue)
    {
        if (GraphStat1DContinue->objectName().isEmpty())
            GraphStat1DContinue->setObjectName(QString::fromUtf8("GraphStat1DContinue"));
        GraphStat1DContinue->resize(500, 570);
        centralWidget = new QWidget(GraphStat1DContinue);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelHistogramme = new QLabel(centralWidget);
        labelHistogramme->setObjectName(QString::fromUtf8("labelHistogramme"));
        labelHistogramme->setGeometry(QRect(20, 250, 460, 15));
        labelHistogramme->setAlignment(Qt::AlignCenter);
        labelHistogrammeCumule = new QLabel(centralWidget);
        labelHistogrammeCumule->setObjectName(QString::fromUtf8("labelHistogrammeCumule"));
        labelHistogrammeCumule->setGeometry(QRect(20, 475, 460, 15));
        labelHistogrammeCumule->setAlignment(Qt::AlignCenter);
        labelMoyenne = new QLabel(centralWidget);
        labelMoyenne->setObjectName(QString::fromUtf8("labelMoyenne"));
        labelMoyenne->setGeometry(QRect(20, 500, 80, 16));
        lineMoyenne = new QLineEdit(centralWidget);
        lineMoyenne->setObjectName(QString::fromUtf8("lineMoyenne"));
        lineMoyenne->setGeometry(QRect(100, 500, 100, 20));
        lineMoyenne->setReadOnly(true);
        labelEcartType = new QLabel(centralWidget);
        labelEcartType->setObjectName(QString::fromUtf8("labelEcartType"));
        labelEcartType->setGeometry(QRect(220, 500, 80, 16));
        lineEcartType = new QLineEdit(centralWidget);
        lineEcartType->setObjectName(QString::fromUtf8("lineEcartType"));
        lineEcartType->setGeometry(QRect(300, 500, 100, 20));
        lineEcartType->setReadOnly(true);
        labelMediane = new QLabel(centralWidget);
        labelMediane->setObjectName(QString::fromUtf8("labelMediane"));
        labelMediane->setGeometry(QRect(20, 530, 80, 16));
        lineMediane = new QLineEdit(centralWidget);
        lineMediane->setObjectName(QString::fromUtf8("lineMediane"));
        lineMediane->setGeometry(QRect(100, 530, 100, 20));
        lineMediane->setReadOnly(true);
        labelMode = new QLabel(centralWidget);
        labelMode->setObjectName(QString::fromUtf8("labelMode"));
        labelMode->setGeometry(QRect(220, 530, 80, 16));
        lineMode = new QLineEdit(centralWidget);
        lineMode->setObjectName(QString::fromUtf8("lineMode"));
        lineMode->setGeometry(QRect(300, 530, 100, 20));
        lineMode->setReadOnly(true);
        GraphStat1DContinue->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphStat1DContinue);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 21));
        GraphStat1DContinue->setMenuBar(menuBar);
        statusBar = new QStatusBar(GraphStat1DContinue);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GraphStat1DContinue->setStatusBar(statusBar);

        retranslateUi(GraphStat1DContinue);

        QMetaObject::connectSlotsByName(GraphStat1DContinue);
    } // setupUi

    void retranslateUi(QMainWindow *GraphStat1DContinue)
    {
        GraphStat1DContinue->setWindowTitle(QApplication::translate("GraphStat1DContinue", "GraphStat1DContinue", 0, QApplication::UnicodeUTF8));
        labelHistogramme->setText(QApplication::translate("GraphStat1DContinue", "Histogramme", 0, QApplication::UnicodeUTF8));
        labelHistogrammeCumule->setText(QApplication::translate("GraphStat1DContinue", "Histogramme cumule", 0, QApplication::UnicodeUTF8));
        labelMoyenne->setText(QApplication::translate("GraphStat1DContinue", "Moyenne :", 0, QApplication::UnicodeUTF8));
        labelEcartType->setText(QApplication::translate("GraphStat1DContinue", "Ecart type :", 0, QApplication::UnicodeUTF8));
        labelMediane->setText(QApplication::translate("GraphStat1DContinue", "Mediane :", 0, QApplication::UnicodeUTF8));
        labelMode->setText(QApplication::translate("GraphStat1DContinue", "Mode :", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GraphStat1DContinue: public Ui_GraphStat1DContinue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHSTAT1DCONTINUE_H
