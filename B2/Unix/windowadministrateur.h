#ifndef WINDOWADMINISTRATEUR_H
#define WINDOWADMINISTRATEUR_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class WindowAdministrateur;
}

class WindowAdministrateur : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowAdministrateur(QWidget *parent = 0);
    ~WindowAdministrateur();
#include "FctUtilesAdministrateur.h"
private slots:
    void on_ButtonAccepteSelection_clicked();
    void on_ButtonAccepterCommande_clicked();
    void on_ButtonAnnulerCommande_clicked();
    void on_ButtonTerminer_clicked();
    void on_ButtonCommande1_clicked();
    void on_ButtonCommande2_clicked();
    void on_ButtonCommande3_clicked();
    void on_ButtonCommande4_clicked();
    void on_ButtonPersonnel1_clicked();
    void on_ButtonPersonnel2_clicked();
    void on_ButtonPersonnel3_clicked();
    void on_ButtonPersonnel4_clicked();
    void on_ButtonAnnulerSelection_clicked();

private:
    Ui::WindowAdministrateur *ui;
    
    QLineEdit*		lineCommande[4];
    QLineEdit*		lineDisponible[4];
    QLineEdit*		linePersonnel[4];
    QLineEdit*		lineCommandeN[4];
    QLineEdit*		lineCommandeT[4];
};

#endif // WINDOWADMINISTRATEUR_H
