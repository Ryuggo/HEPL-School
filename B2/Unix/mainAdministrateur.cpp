#include "windowadministrateur.h"
#include <QApplication>
#include <QTextCodec>

#include "Fichier.ini"
#include "Ecran.h"

int idMsg;
MESSAGE	M;
WindowAdministrateur *w;

int main(int argc, char *argv[])
{
QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

// recuperation des ressources


if ((idMsg = msgget(KEY,0)) == -1)
{
	perror("Erreur de connection a la file du serveur (mainAdministrateur)");
	exit(1);
}
     

// identification de l'administrateur

M.Type = 1;
M.Requete = NEWADMIN;
M.idPid = getpid();

// Transmission du pid

if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
{
	perror("Erreur lors de l'envoi mainAdministrateur");
	exit(1);
}

//
QApplication a(argc, argv);
w = new WindowAdministrateur;
w->show();

 return a.exec();
}
