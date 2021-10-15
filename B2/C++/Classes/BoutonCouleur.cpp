#include "BoutonCouleur.h"


/*====================		Constructeur par Défaut				====================*/

BoutonCouleur::BoutonCouleur(): Bouton() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut BoutonCouleur");
#endif
	couleur = NULL;
}


/*====================		Constructeur d'Initialisation		====================*/

BoutonCouleur::BoutonCouleur(const char* nomTmp, Point x1, Point x2): Bouton(nomTmp, x1, x2) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation BoutonCouleur (nom + X1 + X2)");
#endif
	couleur = NULL;
}


/*====================			Constructeur de Copie			====================*/

BoutonCouleur::BoutonCouleur(const BoutonCouleur& old): Bouton(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie BoutonCouleur");
#endif
//	couleur = NULL;
//	setCouleur(old.getCouleur());
	if(old.getCouleur() != NULL)
		couleur = old.getCouleur();
	else
		couleur = NULL;
}


/*====================				Destructeur					====================*/

BoutonCouleur::~BoutonCouleur() {
#ifdef DEV
	TraceConstructeur("Destructeur BoutonCouleur");
#endif
}


/*====================				Setters						====================*/

void BoutonCouleur::setCouleur(Couleur* coul) {
	if(coul != NULL) {
		couleur = coul;
		int x1 = X1.getX();
		int y1 = X1.getY();
		int x2 = X2.getX() - x1;
		int y2 = X2.getY() - y1;
		
		WindowSDL::fillRectangle(couleur->getRouge(), couleur->getVert(), couleur->getBleu(), x1+5, y1+5, x2-10, y2-10);
	} else {
		setSelected(false);
		couleur = NULL;
	}
}

void BoutonCouleur::setSelected(bool s) {
	selected = s;
	int x1 = X1.getX();
	int y1 = X1.getY();
	int x2 = X2.getX() - x1;
	int y2 = X2.getY() - y1;

	if(s == true) {
		if(couleur != NULL)
			WindowSDL::drawRectangle(0, 255, 0, x1, y1, x2, y2);
		else
			WindowSDL::drawRectangle(195, 195, 195, x1, y1, x2, y2);
	} else
		WindowSDL::drawRectangle(127, 127, 127, x1, y1, x2, y2);
}


/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/

//...


/*====================				Opérateurs						====================*/

BoutonCouleur& BoutonCouleur::operator=(const BoutonCouleur& newC) {
	setX1(newC.getX1());
	setX2(newC.getX2());

	setNom(newC.getNom());
	
	setSelected(newC.getSelected());
		
//	setCouleur(newC.getCouleur());
	if(newC.getCouleur() != NULL)
		couleur = newC.getCouleur();
	else {
		setSelected(false);
		couleur = NULL;
	}
	
	return *this;
}

ostream& operator<<(ostream& output, const BoutonCouleur& c) {
	if(c.getNom() != NULL)
		output << c.getNom() << "\t";
	else
		output << "Aucun Nom" << "\t";
		
	output << "[" << c.X1.getX() << ", " << c.X1.getY() << " - " << c.X2.getX() << ", " << c.X2.getY() << "]" << "\t";
		
	if(c.couleur != NULL) {
		if(c.couleur->getNom() != NULL)
			output << c.couleur->getNom();
		else
			output << "Aucun Nom";
		output << " (" << c.couleur->getRouge() << ", " << c.couleur->getVert() << ", " << c.couleur->getBleu() << ")" << "\t";
	} else
		output << "(Aucune Couleur)" << "\t";
	
	if(c.getSelected() == true)
		output << "On" << endl;
	else
		output << "Off" << endl;

	return output;
}
