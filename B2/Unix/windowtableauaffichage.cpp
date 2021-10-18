#include "windowtableauaffichage.h"
#include "ui_windowtableauaffichage.h"

#include "Fichier.ini"
#include "Ecran.h"

extern int Colonne;
extern int idMsg;
extern MESSAGE	M;
extern WindowTableauAffichage* w;

void HNouvelCommande(int);

WindowTableauAffichage::WindowTableauAffichage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowTableauAffichage)
{
    ui->setupUi(this);
    move(Colonne,0);
    int i = 0;
    while (i < 3)
    { lineCommande[i] = new QLineEdit(this);
      lineCommande[i]->setGeometry(QRect(40,20 + i * 30,100,20));
      lineCommande[i]->setReadOnly(true);
      lineCommande[i + 3] = new QLineEdit(this);
      lineCommande[i + 3]->setGeometry(QRect(380,20 + i * 30,100,20));
      lineCommande[i + 3]->setReadOnly(true);
      
      linePersonnel[i] = new QLineEdit(this);
      linePersonnel[i]->setGeometry(QRect(150,20 + i * 30,100,20));
      linePersonnel[i]->setReadOnly(true);
      linePersonnel[i + 3] = new QLineEdit(this);
      linePersonnel[i + 3]->setGeometry(QRect(490,20 + i * 30,100,20));
      linePersonnel[i + 3]->setReadOnly(true);
      
      labelEtat[i] = new QLabel(this);
      labelEtat[i]->setGeometry(QRect(260,20 + i * 30,80,20));
		labelEtat[i + 3] = new QLabel(this);
      labelEtat[i + 3]->setGeometry(QRect(600,20 + i * 30,80,20));
      i++;
    }
// Armement des signaux
    struct sigaction Action;
   
}

WindowTableauAffichage::~WindowTableauAffichage()
{
    delete ui;
}
#include "FctUtilesAffichage.cpp"


void HNouvelCommande(int Sig)
{
Trace("Reception d'une nouvelle commande (%d)",Sig);

//	switch(M.Requete)
//		{
//		case NEWCOMMANDE:
//		Trace("Reception NEWCOMMANDE");
//		
//		break;
//		
//	case TRAVAILTERMINER:
//		Trace("Reception TRAVAILTERMINER");
//			
//	case EVOLUTIONTRAVAIL:
//		Trace("Reception EVOLUTIONTRAVAIL --%s--",M.Selection2);
//		
//		break;
//	case SUPPRESSIONTRAVAIL:
//		Trace("Reception SUPPRESSIONTRAVAIL --%s--",M.Selection2);
//		
//		break;
//		}
	
}
