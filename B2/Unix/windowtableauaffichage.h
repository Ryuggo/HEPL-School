#ifndef WINDOWTABLEAUAFFICHAGE_H
#define WINDOWTABLEAUAFFICHAGE_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class WindowTableauAffichage;
}

class WindowTableauAffichage : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowTableauAffichage(QWidget *parent = 0);
    ~WindowTableauAffichage();
#include "FctUtilesAffichage.h"
private:
    Ui::WindowTableauAffichage *ui;
    
    QLineEdit*		lineCommande[6];
    QLineEdit*		linePersonnel[6];
    QLabel*			labelEtat[6];
};

#endif // WINDOWTABLEAUAFFICHAGE_H
