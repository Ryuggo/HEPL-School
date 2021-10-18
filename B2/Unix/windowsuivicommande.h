#ifndef WINDOWSUIVICOMMANDE_H
#define WINDOWSUIVICOMMANDE_H

#include <QMainWindow>

namespace Ui {
class WindowSuiviCommande;
}

class WindowSuiviCommande : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowSuiviCommande(QWidget *parent = 0);
    ~WindowSuiviCommande();
	void setCheck(int ,bool);
	void setE1(int,const char *);
private slots:
    void on_ButtonTerminer_clicked();

private:
    Ui::WindowSuiviCommande *ui;
};

#endif // WINDOWSUIVICOMMANDE_H
