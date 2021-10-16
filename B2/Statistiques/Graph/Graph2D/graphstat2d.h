#ifndef GRAPHSTAT2D_H
#define GRAPHSTAT2D_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "EtudeStat2D.h"

namespace Ui {
class GraphStat2D;
}

class GraphStat2D : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphStat2D(const EtudeStat2D*,QWidget *parent = 0);
    ~GraphStat2D();
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void on_ButtonTracer_clicked();
    void on_ButtonSelectionner_clicked();
    void on_ButtonAnnuler_clicked();

private:
    Ui::GraphStat2D 		*ui;
    QPoint      			PointDepart,
    		      			PointArrivee;
    bool        			Pt,
                			TracerLigne;
    float       			MinX,MinY,
                			MaxX,MaxY;
                
    Liste<Data2D>* 	L ;
    Liste<Data2D> 	LUndo ;
    DataSourceSerie2D* 	p;
    EtudeStat2D*			EtudeLocal;

};

#endif // GRAPHSTAT2D_H
