#include <unistd.h>
#include "windowsuivicommande.h"
#include "ui_windowsuivicommande.h"
#include "Fichier.ini"
//#include "Ecran.h"

extern int idMsg;
extern MESSAGE	M;
extern char Commande[20];

WindowSuiviCommande::WindowSuiviCommande(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowSuiviCommande)
{
    ui->setupUi(this);
    ui->label->setText(Commande);
// demande d'un suivi
//signaler au serveur qu'il existe

M.idPid = getpid();
M.Type = 1;
M.Requete = SUIVICOMMANDE;
strcpy(M.arg.C.NomC,Commande);

if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
{
	perror("Erreur lors de l'envoi windowSuiviCommande(SUIVICOMMANDE)");
	exit(1);
}

int	i;
int boucle=0;
while (boucle<2)
{
// recuperation d'un messages
if (msgrcv(idMsg,&M,sizeof(M) - sizeof(long),getpid(),0) == -1)
{
	perror("Err de msgrcv()");
	exit(1);
}

switch(M.Requete)
	{
	case SUIVICOMMANDE:
		i = 0;
		while (strlen(M.arg.C.E[i]))
			{
			setE1(i,M.arg.C.E[i]);
			if (!M.arg.C.T[i]) setCheck(i,true);
			i++;
			}
		printf("reception SUIVICOMMANDE -%s-   %d\n",M.arg.C.E[0],M.arg.C.T[0]);
		printf("reception SUIVICOMMANDE -%s-   %d\n",M.arg.C.E[1],M.arg.C.T[1]);
		printf("reception SUIVICOMMANDE -%s-   %d\n",M.arg.C.E[2],M.arg.C.T[2]);
		printf("reception SUIVICOMMANDE -%s-   %d\n",M.arg.C.E[3],M.arg.C.T[3]);
		break;

	case COMMANDELIVREE:
		if(M.arg.N == 0)
		{
			setCheck(5,true);
		}
		break;
	}
	boucle++;
}
return;	
}

WindowSuiviCommande::~WindowSuiviCommande()
{
    delete ui;
}
#include "fctUtileSuivCommande.cpp"

void WindowSuiviCommande::on_ButtonTerminer_clicked()
{
    M.Type = 1;
M.idPid = getpid();
M.Requete = FINSUIVICOMMANDE;
strcpy(M.arg.Selection.S1,Commande);
if (msgsnd(idMsg,&M,sizeof(M)-8,0) == -1)
{ 
   perror("Err. de msgsnd()");
     exit(1);
}
exit(0);
}
