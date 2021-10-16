#include "graphstat2d.h"
#include "ui_graphstat2d.h"

GraphStat2D::GraphStat2D(const EtudeStat2D* E1,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphStat2D)
{
   ui->setupUi(this);
   Pt = true;
   TracerLigne = false;
   EtudeLocal = (EtudeStat2D*)E1;

   this->p = dynamic_cast<DataSourceSerie2D*>((E1->getE())->getSource2D());

	L = new Liste<Data2D>(*(p->getL()));
	L->Affiche();

	// Déterminer MinX, MinY, MaxX, MaxY dans les Data2D de L
	// ...
	int i = 0;
	
	MinX = L->getElement(i).getVal1();
	
	MinY = L->getElement(i).getVal2();
	MaxY = L->getElement(i).getVal2();
	
	while(i < L->Size()) {
		if(MinY > L->getElement(i).getVal2())
			MinY = L->getElement(i).getVal2();
		if(MaxY < L->getElement(i).getVal2())
			MaxY = L->getElement(i).getVal2();
		
		i++;
	}
	MaxX = L->getElement(i-1).getVal1();
}

GraphStat2D::~GraphStat2D()
{
    delete ui;
}

void GraphStat2D::on_ButtonTracer_clicked()
{
    printf("on_ButtonTracer_clicked\n");fflush(stdout);
    
    p->setL(L);
    EtudeLocal->setCoeffA();		// Calcul des coefficients de la droite
    EtudeLocal->setCoeffB();

    char	Buff[80];
    if (EtudeLocal->getCoeffB() > 0)
       sprintf(Buff,"%8.2f x + %8.2f",EtudeLocal->getCoeffA(),EtudeLocal->getCoeffB());
    else sprintf(Buff,"%8.2f x - %8.2f",EtudeLocal->getCoeffA(),-EtudeLocal->getCoeffB());
    ui->lineEquation->setText(Buff);
    TracerLigne = true;		// Pour dessiner la droite
    this->update();
}

void GraphStat2D::on_ButtonSelectionner_clicked()
{
	printf("on_ButtonSelectionner_clicked\n");fflush(stdout);
	
	// Déterminer les coordonnées des coins du rectangle de sélexion et créer 2 variables Data2D à partir d'elles
	// ...
	Data2D p1, p2;
	if(PointDepart.x() && PointArrivee.x() && PointDepart.y() && PointArrivee.y()) {
		p1.setVal1(PointDepart.x());
		p1.setVal2(PointDepart.y());
		p2.setVal1(PointArrivee.x());
		p2.setVal2(PointArrivee.y());
	}
 
 
 	// Ensuite, passer en revue la liste L et vérifier pour chaque donnée Data2D si elle est comprise
 	// dans le rectangle de sélexion. Si oui, la retirer de la liste L et l'ajouter à la liste LUndo
 	// ...
 	L = new Liste<Data2D>(*(p->getL()));
   Cellule<Data2D> *pPrec = NULL, *pCur = L->getPtete();
 	
	int x, y;
	
	while(pCur->suivant != NULL) {
		x = 80 + (pCur->valeur.getVal1() - MinX) * 340 / (MaxX - MinX)  - 3;
		y = 320 - (pCur->valeur.getVal2() - MinY) * 280 / (MaxY - MinY) + 3;
		
		if(p1.getVal1() <= x && x <= p2.getVal1())
			if(p1.getVal2() <= y && y <= p2.getVal2()) {
				LUndo.insere(pCur->valeur);
				
				if(pPrec)
					pPrec->suivant = pCur->suivant;
				if(pCur->suivant)
					(pCur->suivant)->avant = pPrec;
				delete pCur;
			}
			
		pPrec = pCur;
		pCur = pCur->suivant;
	}
 	
	
	PointDepart = PointArrivee;
	TracerLigne = false;			// pour ne pas tracer l'ancienne droite
	ui->lineEquation->clear();
	this->update();

     p->setL(L);
}

void GraphStat2D::on_ButtonAnnuler_clicked()
{
     printf("on_ButtonAnnuler_clicked\n");fflush(stdout);
     
     // Retirer le dernier élément ajouté à LUndo et le remettre dans L
     // ...
     Cellule<Data2D> *pCur;
     
     LUndo.Affiche();
     pCur = LUndo.getPtete();
     
     if(pCur != NULL && pCur->valeur.getVal1() != 0 && pCur->valeur.getVal2() != 0) {
	  		while(pCur->suivant != NULL)
	  			pCur = pCur->suivant;
	  		
	  		L->insere(pCur->valeur);
	  		if(pCur->avant)
	  			(pCur->avant)->suivant = NULL;
	  		
	  		if(pCur == LUndo.getPtete()) {
	  		cout << "TESt" << endl;
	  			pCur->suivant = NULL;
	  			pCur->valeur.setVal1(0);
	  			pCur->valeur.setVal2(0);
	  			pCur = NULL;
	  		} else
     			delete pCur;
     }
     LUndo.Affiche();


     TracerLigne = false;
     ui->lineEquation->clear();
     this->update();
}

void GraphStat2D::paintEvent(QPaintEvent *)
{
QPainter painter(this);
    painter.drawLine(50, 20, 50, 360);
    painter.drawLine(50, 360, 460, 360);
    
    char 	Buff[10];
	sprintf(Buff,"%-8.2f",MinY);
	painter.drawText(10 ,324,Buff);	//320 + 3
	sprintf(Buff,"%-8.2f",MaxY);
	painter.drawText(10 ,45,Buff);	//40 + 3
	sprintf(Buff,"%-8.2f",MinX);
	painter.drawText(63 ,380,Buff);	//320 + 3
	sprintf(Buff,"%-8.2f",MaxX);
	painter.drawText(394 ,380,Buff);	//40 + 3

	int i = 0;
	while (i < L->Size())
	{
		painter.drawText(80 + (this->L->getElement(i).getVal1() - MinX) * 340 / (MaxX - MinX)  - 3, 320 - (this->L->getElement(i).getVal2() - MinY) * 280 / (MaxY - MinY) +3,"x");
	   i++;
	}
	     
    if (Pt)
       painter.drawText(PointDepart.x()-3,PointDepart.y()+3,"x");
    painter.drawRect(PointDepart.x(),PointDepart.y(),PointArrivee.x()-PointDepart.x(),PointArrivee.y()-PointDepart.y());
	if (TracerLigne)
		{
		float X1=MinX,Y1,X2=MaxX,Y2;
		Y1 = X1 * EtudeLocal->getCoeffA() + EtudeLocal->getCoeffB();
		Y2 = X2 * EtudeLocal->getCoeffA() + EtudeLocal->getCoeffB();
		painter.drawLine(80   - 3,320 - (Y1 - MinY) * 280 / (MaxY - MinY) +3,
	    80 +  340 - 3, 320 - (Y2 - MinY) * 280 / (MaxY - MinY) +3);
		}
}

void GraphStat2D::mouseReleaseEvent(QMouseEvent * e)
{
   PointArrivee = e->pos();
   Pt =false ;
   this->update();
}

void GraphStat2D::mousePressEvent(QMouseEvent * e)
{
	PointDepart = e->pos();
	PointArrivee = e->pos();
   Pt =  true;
  	this->update();
}

