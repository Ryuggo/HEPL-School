#include "windowFenetrePersonnel.h"
#include "ui_windowFenetrePersonnel.h"
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "Fichier.ini"
#include "Ecran.h"

extern int Ligne;
extern char	Personnel[20];
extern int idMsg;
extern MESSAGE	M;
extern windowFenetrePersonnel* w;

void HandlerSigusr1(int);
void HandlerAlarme(int);
void EnvoyerSignal(int);

int verif=0;

char sauv[50];//Sert a sauvegarder le nom de la commande

windowFenetrePersonnel::windowFenetrePersonnel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::windowFenetrePersonnel)
{
// armement des signaux
struct sigaction Action;
  
Action.sa_handler = HandlerSigusr1;
sigemptyset(&Action.sa_mask);
Action.sa_flags = 0;
sigaction(SIGUSR1,&Action,NULL);

Action.sa_handler = HandlerAlarme;
sigemptyset(&Action.sa_mask);
Action.sa_flags = 0;
sigaction(SIGALRM,&Action,NULL);

Action.sa_handler = EnvoyerSignal;
sigemptyset(&Action.sa_mask);
Action.sa_flags = 0;
sigaction(SIGUSR2,&Action,NULL);

ui->setupUi(this);
this->move(Ligne,650);
this->setWindowTitle(Personnel);

}

windowFenetrePersonnel::~windowFenetrePersonnel()
{
delete ui;
}

void windowFenetrePersonnel::on_BoutonTerminer_clicked()
{
Trace("Terminer\n");
// signaler la fin de ce personnel
				
	M.Type = 1;
	M.Requete = FINPERSONNEL;
	M.idPid = getpid();
	if(verif == 0)
	{
		strcpy(M.arg.Selection.S1,"Unfinished");
	}
	else
	{
		strcpy(M.arg.Selection.S1,"");
	}
	
	strcpy(M.arg.Selection.S2,sauv);				
				
	if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
	{
		perror("Erreur lors de l'envoi windowFenetrePersonnel(FINPERSONNEL)");
		exit(1);
	}

exit(0);
}

#include "fctUtileFenetre.cpp"
int i,Pos;


void HandlerSigusr1(int Sig)
{
	verif=0;
	Trace("Reception d'un signal SIGUSER1 (%d)",Sig);
	i = 0;
	w->setCheck(0,FALSE);
	w->setCheck(1,FALSE);
	w->setCheck(2,FALSE);
	w->setCheck(3,FALSE);

	if(msgrcv(idMsg,&M,sizeof(M)-sizeof(long),getpid(),0)==-1)
	{
		perror("Erreur lors de la réception du message (WindowFenetrePersonnel)");
		exit(1);
	}
	
	strcpy(sauv,M.arg.C.NomC);
	
	w->setNomC(sauv);
	w->setE1(M.arg.C.E[0]);
	if(M.arg.C.T[0] == 0 && (strcmp(M.arg.C.E[0],"") != 0))
	{
		w->setCheck(i,TRUE);
		i++;
	}
	w->setE2(M.arg.C.E[1]);
	if(M.arg.C.T[1] == 0 && (strcmp(M.arg.C.E[1],"") != 0))
	{
		w->setCheck(i,TRUE);
		i++;
	}
	w->setE3(M.arg.C.E[2]);
	if(M.arg.C.T[2] == 0 && (strcmp(M.arg.C.E[2],"") != 0))
	{
		w->setCheck(i,TRUE);
		i++;
	}
	w->setE4(M.arg.C.E[3]);
	if(M.arg.C.T[3] == 0 && (strcmp(M.arg.C.E[3],"") != 0))
	{
		w->setCheck(i,TRUE);
		i++;
	}
	
	
	if(strcmp(M.arg.C.E[i],"") != 0)
	{
		alarm(M.arg.C.T[i]);
	}
	
return;
}

void HandlerAlarme(int Sig)
{
	char tmp[10];
	w->setCheck(i,TRUE);
	i++;
	Trace("Reception d'un SIGALRM (%d) %deme etape",Sig,i);
	// signaler que l'etape est terminee
	
	M.Type = 1;
	M.Requete = ETAPEEFFECTUEE;
	M.idPid = getpid();
	strcpy(M.arg.Selection.S2,sauv);
	tmp[0] = (char)i + 48;
	tmp[1] = '\0';
	
	strcpy(M.arg.Selection.S1,tmp);

	if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
	{
		perror("Erreur lors de l'envoi windowFenetrePersonnel(ETAPEEFFECTUEE)");
		exit(1);
	}

	if(M.arg.C.T[i] == 0 && strcmp(M.arg.C.E[i],"") == 0)
	{
		kill(getpid(),SIGUSR2);
	}
	else
	{
		alarm(M.arg.C.T[i]);
	}

return;
}

void EnvoyerSignal(int Sig)
{
	Trace("Reception d'un SIGUSR2 (%d)",Sig,i);
	M.Type = 1;
	M.Requete = TRAVAILTERMINER;
	M.idPid = getpid();
	strcpy(M.arg.Selection.S2,sauv);
	verif=1;
	if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
	{
		perror("Erreur lors de l'envoi TRAVAILTERMINER");
		exit(1);
	}
}
