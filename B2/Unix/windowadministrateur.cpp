#include "windowadministrateur.h"
#include "ui_windowadministrateur.h"
#include <QMessageBox>
#include "Fichier.ini"
#include "Ecran.h"
#include <signal.h>

extern int idMsg;
extern MESSAGE	M;
extern WindowAdministrateur *w;

void HNouvelUtilisateur(int);

WindowAdministrateur::WindowAdministrateur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowAdministrateur)
{
ui->setupUi(this);
move(10,175);

  // Armement des signaux
struct sigaction Act;
  
Act.sa_handler = HNouvelUtilisateur;
sigemptyset(&Act.sa_mask);
Act.sa_flags = 0;
sigaction(SIGUSR1,&Act,NULL);
    
int i = 0;
while (i < 4)
	{ 
	lineCommande[i] = new QLineEdit(this);
	lineCommande[i]->setGeometry(QRect(20,50 + i * 30,120,20));
	lineCommande[i]->setReadOnly(true);
	lineDisponible[i] = new QLineEdit(this);
	lineDisponible[i]->setGeometry(QRect(200,50 + i * 30,120,20));
	lineDisponible[i]->setReadOnly(true);
	i++;
	}
      
i = 0;
while (i < 4)
	{
	linePersonnel[i] = new QLineEdit(this);
	linePersonnel[i]->setGeometry(QRect(450,50 + i * 30,120,20));
	linePersonnel[i]->setReadOnly(true);      
	i++;
	}
    
lineCommandeN[0] = new QLineEdit(this);
lineCommandeN[0]->setGeometry(QRect(40,345 ,120,20));
lineCommandeT[0] = new QLineEdit(this);
lineCommandeT[0]->setGeometry(QRect(170,345 ,40,20));
lineCommandeN[1] = new QLineEdit(this);
lineCommandeN[1]->setGeometry(QRect(280,345 ,120,20));
lineCommandeT[1] = new QLineEdit(this);
lineCommandeT[1]->setGeometry(QRect(410,345 ,40,20));
lineCommandeN[2] = new QLineEdit(this);
lineCommandeN[2]->setGeometry(QRect(40,375,120,20));
lineCommandeT[2] = new QLineEdit(this);
lineCommandeT[2]->setGeometry(QRect(170,375 ,40,20));
lineCommandeN[3] = new QLineEdit(this);
lineCommandeN[3]->setGeometry(QRect(280,375 ,120,20));
lineCommandeT[3] = new QLineEdit(this);
lineCommandeT[3]->setGeometry(QRect(410,375,40,20));
}

#include "FctUtilesAdministrateur.cpp"

WindowAdministrateur::~WindowAdministrateur()
{
    delete ui;
}

void WindowAdministrateur::on_ButtonAccepteSelection_clicked()
{
Trace("Dans on_ButtonAccepteSelection_clicked");
if (!getSelectionCommande()) return;
if (!getSelectionPersonnel()) return;
Trace("Lu --%s--%s-- (%d)\n",getSelectionCommande(),
	getSelectionPersonnel(),idMsg);
// transmission de la commande

strcpy(M.arg.C.NomC,getSelectionCommande());
Trace("Commande avant : %s",getSelectionCommande());
strcpy(M.arg.Selection.S2,getSelectionPersonnel());
Trace("Personnel avant : %s",getSelectionPersonnel());
M.Type = 1;
M.idPid = getpid();
M.Requete = TRANSMISSIONCOMMANDE;

if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
{
	perror("Erreur lors de l'envoi windowadministrateur (bouton accepter commande)");
	exit(1);
}

setSelectionCommande("");
setSelectionPersonnel("");

}

void WindowAdministrateur::on_ButtonAnnulerSelection_clicked()
{
int i,bol=1;
Trace("Dans on_ButtonAnnulerSelection_clicked");
if(getSelectionCommande() != NULL)
{
	for(i=0;i<4 && bol==1;i++)
	{
		if(getCommande(i) == NULL)
		{
			setCommande(i, getSelectionCommande());
			setSelectionCommande("");
			bol = 0;
		}
	}
}
bol=1;
if(getSelectionPersonnel() != NULL)
{
	for(i=0;i<4 && bol==1;i++)
	{
		if(getDisponible(i) == NULL)
		{
			setDisponible(i, getSelectionPersonnel());
			setSelectionPersonnel("");
			bol = 0;
		}
	}
}

return;

}

void WindowAdministrateur::on_ButtonAccepterCommande_clicked()
{
	Trace("Dans on_ButtonAccepterCommande_clicked");
	int i,bol=1;
	strcpy(M.arg.C.NomC,getNomCommande());
	if(getNomCommande() == NULL)
	{
		Trace("Nom de commande requis");
		exit(1);
	}
	
	if(getCommandeN(0) != NULL)
	{
		strcpy(M.arg.C.E[0],getCommandeN(0));
	}
	if(getCommandeN(1) != NULL)
	{
		strcpy(M.arg.C.E[1],getCommandeN(1));
	}
	if(getCommandeN(2) != NULL)
	{
		strcpy(M.arg.C.E[2],getCommandeN(2));
	}
	if(getCommandeN(3) != NULL)
	{
		strcpy(M.arg.C.E[3],getCommandeN(3));
	}
	
	M.arg.C.T[0] = getCommandeT(0);
	M.arg.C.T[1] = getCommandeT(1);
	M.arg.C.T[2] = getCommandeT(2);
	M.arg.C.T[3] = getCommandeT(3);
	M.Type = 1;
	M.idPid = getpid();
	M.Requete = AJOUTCOMMANDE;
	
	if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
	{
		perror("Erreur lors de l'envoi AccepterCommande");
		exit(1);
	}
	
	for(i=0,bol=1;i<4 && bol==1;i++)
	{
		if(w->getCommande(i) == NULL)
		{
			w->setCommande(i, M.arg.C.NomC);
			bol = 0;
		}
	}
	
return;
}

void WindowAdministrateur::on_ButtonAnnulerCommande_clicked()
{
printf("Dans on_ButtonAnnulerCommande_clicked\n ");
}

void WindowAdministrateur::on_ButtonTerminer_clicked()
{
printf("Dans on_ButtonAnnulerCommande_clicked\n ");
exit(0);
}

void WindowAdministrateur::on_ButtonCommande1_clicked()
{
Trace("Dans on_ButtonCommande1_clicked");
if (getSelectionCommande())
	{
	MessageInformation("Avertissement","Il y a déjà une commande");
	return;
	}
setSelectionCommande(getCommande(0));
setCommande(0,"");
}

void WindowAdministrateur::on_ButtonCommande2_clicked()
{
Trace("Dans on_ButtonCommande2_clicked");
if (getSelectionCommande())
	{
	MessageInformation("Avertissement","Il y a déjà une commande");
	return;
	}
setSelectionCommande(getCommande(1));
setCommande(1,"");
}

void WindowAdministrateur::on_ButtonCommande3_clicked()
{
Trace("Dans on_ButtonCommande3_clicked");
if (getSelectionCommande())
	{
	MessageInformation("Avertissement","Il y a déjà une commande");
	}

setSelectionCommande(getCommande(2));
setCommande(2,"");
}

void WindowAdministrateur::on_ButtonCommande4_clicked()
{
Trace("Dans on_ButtonCommande4_clicked");
if (getSelectionCommande())
	{
	MessageInformation("Avertissement","Il y a déjà une commande");
	return;
	}
setSelectionCommande(getCommande(3));
setCommande(3,"");
}

void WindowAdministrateur::on_ButtonPersonnel1_clicked()
{
Trace("Dans on_ButtonPersonnel1_clicked");
if (getSelectionPersonnel())
	{
	MessageInformation("Avertissement","Il y a  déjà un personnel.");
	return;
	}
setSelectionPersonnel(getDisponible(0));
setDisponible(0,"");
}

void WindowAdministrateur::on_ButtonPersonnel2_clicked()
{
Trace("Dans on_ButtonPersonnel2_clicked");
if (getSelectionPersonnel())
	{
	MessageInformation("Avertissement","Il y a  déjà un personnel.");
	return;
	}
setSelectionPersonnel(getDisponible(1));
setDisponible(1,"");
}

void WindowAdministrateur::on_ButtonPersonnel3_clicked()
{
Trace("Dans on_ButtonPersonnel3_clicked");
if (getSelectionPersonnel())
	{
	MessageInformation("Avertissement","Il y a  déjà un personnel.");
	return;
	}
setSelectionPersonnel(getDisponible(2));
setDisponible(2,"");
}

void WindowAdministrateur::on_ButtonPersonnel4_clicked()
{
Trace("Dans on_ButtonPersonnel4_clicked");
if (getSelectionPersonnel())
	{
	MessageInformation("Avertissement","Il y a  déjà un personnel.");
	return;
	}
setSelectionPersonnel(getDisponible(3));
setDisponible(3,"");
}



void HNouvelUtilisateur(int Sig)
{
Trace("Reception d'un signal (%d)",Sig);
char	Buff[80];
int i,bol=1;

while (1 )
   { 
//   reception d'un message
    if(msgrcv(idMsg,&M,sizeof(M) - sizeof(long),getpid(),0)==-1)
    {
    	perror("Erreur lors de la réception du message (WindowAdministrateur)");
    	exit(1);
    }
   
	switch(M.Requete)
	{
	case NEWPERSONNEL:
		Trace("reception NEWPERSONNEL --%s--\n",M.arg.Selection.S1);
		
		for(i=0,bol=1;i<4 && bol==1;i++)
		{
			if(w->getPersonnel(i) == NULL)
			{
				w->setPersonnel(i, M.arg.Selection.S1);
				bol = 0;
			}
		}
		
		bol=1;
		
		for(i=0,bol=1;i<4 && bol==1;i++)
		{
			if(w->getDisponible(i) == NULL)
			{
				w->setDisponible(i, M.arg.Selection.S1);
				bol = 0;
			}
		}
		return;
		break;

	case TRAVAILTERMINER:
		Trace("reception TRAVAILTERMINER --%s--\n",M.arg.Selection.S1);
		bol=1;
		
		for(i=0,bol=1;i<4 && bol==1;i++)
		{
			if(w->getDisponible(i) == NULL)
			{
				w->setDisponible(i, M.arg.Selection.S1); 
				bol = 0;
			}
		}
		
		for(i=0,bol=1;i<4 && bol==1;i++)
		{
			if(w->getCommande(i) == NULL)
			{
				if(M.arg.Selection.S1 != NULL)
				{
					w->setCommande(i, M.arg.Selection.S2);
				}
				bol = 0;
			}
		}
		
		return;
		break;
		
	case NEWCOMMANDE:
		Trace("reception NEWCOMMANDE --%s--\n",M.arg.Selection.S1);
		for(i=0,bol=1;i<4 && bol==1;i++)
		{
			if(w->getCommande(i) == NULL)
			{
				w->setCommande(i, M.arg.C.NomC);
				bol = 0;
			}
		}
		return;
		break;
		
	case NUMEROCOMMANDE:
		Trace("Reception NUMEROCOMMANDE");
		sprintf(Buff,"Commande enregistrée sous le numéro %s",M.arg.Selection.S1);
		QMessageBox::information(w,"Avertissement",Buff); 
		//Suivi commande
		return;
		break;
	case FINPERSONNEL:
		Trace("Reception FINPERSONNEL");
		for(i=0,bol=0;i<4 && bol==0;i++)
		{
			if(w->getPersonnel(i) != NULL && strcmp(w->getPersonnel(i),M.arg.Selection.S1)==0)
			{
				bol = 1;
			}
		}
		i--;
		if(bol==1)
		{
			w->setPersonnel(i,"");
		}
		for(i=0,bol=0;i<4 && bol==0;i++)
		{
			if(w->getDisponible(i)!= NULL && (strcmp(w->getDisponible(i),M.arg.Selection.S1)==0))
			{
				bol = 1;
			}
		}
		i--;
		if(bol==1)
		{
			w->setDisponible(i,"");
		}
		else
		{
			if(w->getSelectionPersonnel() != NULL)
			{
				if(strcmp(w->getSelectionPersonnel(),M.arg.Selection.S1)==0)
				{
					w->setSelectionPersonnel("");
				}
			}
		}
		if(strcmp(M.arg.Selection.S2,"")==0)//Unfinished S1
		{
			//rien à faire
		}
		else
		{
			for(i=0,bol=0;i<4 && bol==0;i++)
			{
				if(w->getCommande(i) == NULL)
				{
					bol = 1;
				}
			}
			i--;
			if(bol==1)
			{
				w->setCommande(i,M.arg.Selection.S2);
			}
		}
		
		
		return;
		break;
		
	}
	}

return;
}
