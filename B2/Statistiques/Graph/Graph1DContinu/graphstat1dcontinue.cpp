#include "graphstat1dcontinue.h"
#include "ui_graphstat1dcontinue.h"
#include <QPainter>
#include "EtudeStat1D.h"

GraphStat1DContinue::GraphStat1DContinue(const EtudeStat1D& E1,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphStat1DContinue)
{
    ui->setupUi(this);
this->p = dynamic_cast<DataSourceSerieContinue*>((E1.getE())->getSource());
L = new Liste<Data1D>(*(p->getL()));
cout << "dans le graphique" << endl;
L->Affiche();
char	Buff[10];
sprintf(Buff,"%6.1f",E1.getMoyenne());
ui->lineMoyenne->setText(Buff);
sprintf(Buff,"%6.1f",E1.getEcartType());
ui->lineEcartType->setText(Buff);
sprintf(Buff,"%6d",E1.getE()->getSource()->getEffTotal());   
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

GraphStat1DContinue::~GraphStat1DContinue()
{
    delete ui;
}

void GraphStat1DContinue::paintEvent(QPaintEvent *event)
{
	int 	Taille = L->Size();
	float	Intervalle = p->getIntervalle();

	float Debut = p->getDebut();
	int	EffMin = L->getElement(0).getEff(), EffMax = 	L->getElement(0).getEff();
	int	i = 1,NbIntervalle = 1;
	while (i<= Taille - 1)
		{ if (L->getElement(i).getEff() < EffMin ) EffMin = L->getElement(i).getEff();
		  if (L->getElement(i).getEff() > EffMax ) EffMax = L->getElement(i).getEff();
		  if (L->getElement(i).getVal() >= Debut + (NbIntervalle+1) * Intervalle) 
		     { NbIntervalle++;
		       continue;
		     }
		  NbIntervalle++;
		  i++;
		}

   QPainter painter(this);
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
// Tracer l'histogramme
i = 0;
int j = 0;
    while (j<NbIntervalle)
    { 
    if (L->getElement(i).getVal() > Debut + (j+1) * Intervalle) {j++;continue;}
    painter.drawLine(50 + j * 400 / NbIntervalle ,190 -L->getElement(i).getEff()*170/	EffMax,50 + j * 400 / NbIntervalle ,193); 
    painter.drawLine(50 + j * 400 / NbIntervalle ,190 -L->getElement(i).getEff()*170/	EffMax,50 + (j + 1) * 400 / NbIntervalle ,190 -L->getElement(i).getEff()*170/	EffMax); 
    
    j++;
    if (L->getElement(i).getVal() > Debut + (j+1) * Intervalle) {j++;continue;}
    painter.drawLine(50 + j * 400 / NbIntervalle ,190 -L->getElement(i).getEff()*170/	EffMax,50 + j * 400 / NbIntervalle ,193); 
    i++;
    }
    
// Tracer l'histogramme cumule 
	 Debut = p->getDebut();
	 int EffTotal = p->getEffTotal();
	 int 	D1 = 0,D2 = L->getElement(0).getEff();
i=1; j = 1;
    while (j<NbIntervalle)
    {
    
    painter.drawLine(50 + j * 400 / NbIntervalle ,440 -D2*170/	EffTotal,50 + j * 400 / NbIntervalle ,443); 
    painter.drawLine(50 + 400 * (j-1) / NbIntervalle,440 -D1*170/EffTotal ,50 + 400 * j/NbIntervalle,440 -D2*170/EffTotal );
    D1 = D2;
    
    
    if (L->getElement(i).getVal() < Debut + (j+1) * Intervalle) {D2 += L->getElement(i).getEff();
      i++;j++;continue;}
    j++;
    }
     painter.drawLine(50 + 400 * (j-1) / NbIntervalle,440 -D1*170/EffTotal ,50 + 400 * j/NbIntervalle,440 -D2*170/EffTotal );
    painter.drawLine(50 + j * 400 / NbIntervalle ,440 -D2*170/	EffTotal,50 + j * 400 / NbIntervalle ,443); 

// Ecriture des valeurs 
	
	Debut = p->getDebut();
	char	Buff[10];
	i = 0;
	while (i <= NbIntervalle + 1)
	{	sprintf(Buff,"%6.1f",Debut); 
		painter.drawText(30 + i * 400 / NbIntervalle ,220,Buff);
		painter.drawText(30 + i * 400 / NbIntervalle,470,Buff);
		Debut += Intervalle;
		i++;
	}

	sprintf(Buff,"%3d",EffMax);
	painter.drawText(5 ,20,Buff); 
	sprintf(Buff,"%3d",EffTotal);	
	painter.drawText(5 ,258,Buff); 

}

