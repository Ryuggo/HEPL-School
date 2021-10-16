#include "graphstat1ddiscrete.h"
#include "ui_graphstat1ddiscrete.h"
#include <QPainter>
#include "EtudeStat1D.h"
#include <string.h>

//GraphStat1DDiscrete::GraphStat1DDiscrete( EtudeStat1D& E1, QWidget *parent) :
GraphStat1DDiscrete::GraphStat1DDiscrete(const EtudeStat1D& E1, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphStat1DDiscrete)
{
    ui->setupUi(this);
    QPainter painter(this);
cout << endl << "dans GraphStat1DDiscrete merce" << endl;
DataSourceSerieDiscrete* p = dynamic_cast<DataSourceSerieDiscrete*>((E1.getE())->getSource());
L = new Liste<Data1D>(*(p->getL()));    //-------------------

char	Buff[10];

sprintf(Buff,"%6.1f",E1.getMoyenne());
ui->lineMoyenne->setText(Buff);
sprintf(Buff,"%6.1f",E1.getEcartType());
ui->lineEcartType->setText(Buff);
//sprintf(Buff,"%6.1f",E1.getE()->getSource()->getEffTotal());   
sprintf(Buff,"%6.1f",E1.getMediane());   
ui->lineMediane->setText(Buff);
float	M[3] = {0, 0, 0};
int i = 0;
memcpy(M,E1.getMode(),40);

char BMode[20];
BMode[0] = '\0';

while (M[i])
{ 
sprintf(Buff,"%6.1f  ",M[i]);cout << "----" << Buff << endl;
strcat(BMode,Buff);
i++;
}

ui->lineMode->setText(BMode);
}

GraphStat1DDiscrete::~GraphStat1DDiscrete()
{
    delete ui;
}

void GraphStat1DDiscrete::paintEvent(QPaintEvent *event)
//void GraphStat1DContinue::paintEvent()
{    
	QPainter painter(this);
// Etendue
	int 	Taille = L->Size();
	float Etendue = L->getElement(L->Size() - 1).getVal() - L->getElement(0).getVal();
	int	EffMin = L->getElement(0).getEff(), EffMax = 	L->getElement(Taille - 1).getEff();
	
	for (int i = 1;i< Taille - 1; i++)
		{ if (L->getElement(i).getEff() < EffMin ) EffMin = L->getElement(i).getEff();
		  if (L->getElement(i).getEff() > EffMax ) EffMax = L->getElement(i).getEff();
		}

	int EcartY = 170 / EffMax;
	int EcartX = 400 / Etendue;

// Tracer l'histogramme
	for (int i = 0;i< Taille; i++)
		painter.drawRect(
50 + EcartX * (L->getElement(i).getVal() - L->getElement(0).getVal()) ,
		    190 -L->getElement(i).getEff() * EcartY,5,L->getElement(i).getEff() * EcartY );

// Tracer l'histogramme cumule
	int Hauteur = 0;
	int 	EffCumule = 0;
	for (int i = 0;i< Taille; i++)
		EffCumule += L->getElement(i).getEff();
	
	for (int i = 0;i< Taille; i++)
	{	Hauteur += L->getElement(i).getEff();
	painter.drawRect(50 + EcartX * (L->getElement(i).getVal() - L->getElement(0).getVal()) ,
		    440 - Hauteur * 180 / EffCumule,5,Hauteur * 180 / EffCumule );
	}
		
// Ecriture des valeurs 
	char	Buff[10];
	for (int i = 0;i < Taille;i++)
	{	sprintf(Buff,"%6.1f",L->getElement(i).getVal());
		painter.drawText(30 + EcartX * (L->getElement(i).getVal() - L->getElement(0).getVal()),220,Buff);  // --------------
		painter.drawText(30 + EcartX * (L->getElement(i).getVal() - L->getElement(0).getVal()),470,Buff);
//		painter.drawText(30 + EcartX * i,470,Buff);
	
	}
// Tracer la mediane
    painter.setPen(Qt::red);
    painter.drawLine(35,350 , 480, 350 );
// Tracer des axes
 	painter.setPen(Qt::black);
 	painter.drawLine(35,18 , 35, 190 );
	painter.drawLine(35,190 , 480, 190 );
	painter.drawLine(35,258 , 35, 440 );
	painter.drawLine(35,440 , 480, 440 );
	painter.drawLine(32, 20, 38, 20);
   painter.drawLine(32,260 , 38, 260 );
   
}
