#include "windowFenetrePersonnel.h"
#include <QApplication>
#include "Fichier.ini"

int idMsg;
MESSAGE	M;
int	Ligne;
char	Personnel[20];
windowFenetrePersonnel* w;

int main(int argc, char *argv[])
{
if (argc != 3)
	{ printf("Trop ou trop peu d'argument(s)\n");
	exit(1);
	}
Ligne = atoi(argv[2]);
strcpy(Personnel,argv[1]);

// Recuperation de la file de messages

if ((idMsg = msgget(KEY,0)) == -1)
{
	perror("Erreur de connection a la file du serveur (mainFenetrePersonnel)");
	exit(1);
}

// identification 

M.Type = 1;
M.Requete = NEWPERSONNEL;
M.idPid = getpid();
strcpy(M.arg.Selection.S1,Personnel);

//transmission des données

if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
{
	perror("Erreur lors de l'envoi mainAdministrateur");
	exit(1);
}

//
QApplication a(argc, argv);
w = new windowFenetrePersonnel;
w->show();

return a.exec();
}
