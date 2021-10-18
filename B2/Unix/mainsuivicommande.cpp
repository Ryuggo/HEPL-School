#include "windowsuivicommande.h"
#include <QApplication>
#include <QTextCodec>
#include "Fichier.ini"

int idMsg;
MESSAGE	M;
char 		Commande[20];

int main(int argc, char *argv[])
{
if (argc != 2)
	{ printf("Trop ou trop peu d'argument(s)\n");
	exit(1);
	}
QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

strcpy(Commande,argv[1]);

// Recuperation de la file de messages
if ((idMsg = msgget(KEY,0)) == -1)
{
	perror("Erreur de connection a la file du serveur (mainAdministrateur)");
	exit(1);
}

QApplication a(argc, argv);
WindowSuiviCommande w;
w.show();

return a.exec();
}
