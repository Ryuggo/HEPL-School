#include "Bouton.h"


/*====================		Constructeur par Défaut				====================*/

Bouton::Bouton() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Bouton");
#endif
	Point X1;
	Point X2;
	nom = NULL;
	selected = false;
}


/*====================		Constructeur d'Initialisation		====================*/

Bouton::Bouton(const char* nomTmp, Point x1, Point x2) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Bouton (nom + X1 + X2)");
#endif
	setX1(x1);
	setX2(x2);
	nom = NULL;
	setNom(nomTmp);
	selected = false;
}


/*====================			Constructeur de Copie			====================*/

Bouton::Bouton(const Bouton& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Bouton");
#endif
	setX1(old.X1);
	setX2(old.X2);
	nom = NULL;
	setNom(old.getNom());
	selected = old.selected;
}


/*====================				Destructeur					====================*/

Bouton::~Bouton() {
#ifdef DEV
	TraceConstructeur("Destructeur Bouton");
#endif
	if(nom != NULL)
		delete nom;
}


/*====================				Setters						====================*/

void Bouton::setNom(const char* nomTmp) {
	if(nom != NULL)
		delete nom;
	
	if(nomTmp != NULL) {
		nom = new char[strlen(nomTmp)+1];
		strcpy(nom, nomTmp);
	} else
		nom = NULL;
}

void Bouton::setX1(const Point& pos) {
	X1.setX(pos.getX());
	X1.setY(pos.getY());
}

void Bouton::setX2(const Point& pos) {
	X2.setX(pos.getX());
	X2.setY(pos.getY());
}

void Bouton::setSelected(bool s) {
	selected = s;
	int x1 = X1.getX();
	int y1 = X1.getY();
	int x2 = X2.getX() - x1;
	int y2 = X2.getY() - y1;
	
	if(s == true)
		WindowSDL::drawRectangle(0, 255, 0, x1, y1, x2, y2);
	else
		WindowSDL::drawRectangle(127, 127, 127, x1, y1, x2, y2);
}

/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/

bool Bouton::clic(int x, int y) {
	Point tmpX1, tmpX2;
	
	tmpX1 = getX1();
	tmpX2 = getX2();
	
	if(x >= tmpX1.getX() && x <= tmpX2.getX() && y >= tmpX1.getY() && y <= tmpX2.getY())
		return true;
	else
		return false;
}


/*====================				Opérateurs						====================*/

Bouton& Bouton::operator=(const Bouton& newC) {
	setX1(newC.getX1());
	setX2(newC.getX2());
	
	setNom(newC.getNom());
	
	setSelected(newC.getSelected());
	
	return *this;
}

ostream& operator<<(ostream& output, const Bouton& c) {
	if(c.getNom() != NULL)
		output << c.getNom() << "\t";
	else
		output << "Aucun Nom" << "\t";
		
	output << " [" << c.X1.getX() << ", " << c.X1.getY() << " - " << c.X2.getX() << ", " << c.X2.getY() << "]" << "\t";
	
	if(c.getSelected() == true)
		output << "On" << endl;
	else
		output << "Off" << endl;

	return output;
}
