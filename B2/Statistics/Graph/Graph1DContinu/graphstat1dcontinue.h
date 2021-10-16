#ifndef GRAPHSTAT1DCONTINUE_H
#define GRAPHSTAT1DCONTINUE_H
#include "EtudeStat1D.h"
#include <QMainWindow>

namespace Ui {
class GraphStat1DContinue;
}

class GraphStat1DContinue : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphStat1DContinue(const EtudeStat1D&, QWidget *parent = 0);
    ~GraphStat1DContinue();
    //void paintEvent();
    void paintEvent(QPaintEvent *event);

private:
    Ui::GraphStat1DContinue *ui;
    Liste<Data1D>* L ;
    DataSourceSerieContinue* p;
};

#endif // GRAPHSTAT1DCONTINUE_H
