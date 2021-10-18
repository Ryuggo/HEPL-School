#ifndef WINDOWFENETREPERSONNEL_H
#define WINDOWFENETREPERSONNEL_H

#include <QMainWindow>

namespace Ui {
class windowFenetrePersonnel;
}

class windowFenetrePersonnel : public QMainWindow
{
    Q_OBJECT

public:
    explicit windowFenetrePersonnel(QWidget *parent = 0);
    ~windowFenetrePersonnel();
    void setE1(const char * T);
    void setE2(const char * T);
    void setE3(const char * T);
    void setE4(const char * T);
    void setNomC(const char * T);
    void setCheck(int i,bool b);
    
private slots:
    void on_BoutonTerminer_clicked();


private:
    Ui::windowFenetrePersonnel *ui;
};

#endif // WINDOWFENETREPERSONNEL_H
