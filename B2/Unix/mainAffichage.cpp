#include "windowtableauaffichage.h"
#include <QApplication>
#include "Fichier.ini"
#include "Ecran.h"

int idMsg;
MESSAGE	M;

int	Colonne;
WindowTableauAffichage* w;

int main(int argc, char *argv[])
{
if (argc != 2) 
	{
	Trace("Trop ou trop peu d'argument(s)");
	exit(1);
	}
// recuperation des ressources
    
QApplication a(argc, argv);
w = new WindowTableauAffichage;
w->show();

return a.exec();
}
