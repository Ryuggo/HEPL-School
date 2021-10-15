#include "Figure.h"

int Figure::compteur = 0;


/*====================		Constructeur par Défaut				====================*/

Figure::Figure() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Figure");
#endif
	Point position;
	couleur = NULL;
	
	Figure::compteur++;
}


/*====================		Constructeur d'Initialisation		====================*/

Figure::Figure(const char* idTmp, Point pos) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Figure (Id + Position)");
#endif
	strcpy(id, idTmp);
	setPosition(pos);
	couleur = NULL;
	
	Figure::compteur++;
}

Figure::Figure(const char* idTmp, Point pos, const Couleur* coul) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Figure (Id + Position + Couleur)");
#endif
	strcpy(id, idTmp);
	setPosition(pos);
	couleur = NULL;
	setCouleur(coul);
	
	Figure::compteur++;
}


/*====================		Constructeur de Copie				====================*/

Figure::Figure(const Figure& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Figure");
#endif
	setPosition(old.position);
	couleur = NULL;
	setCouleur(old.couleur);
	
	Figure::compteur++;
}


/*====================				Destructeur					====================*/

Figure::~Figure() {
#ifdef DEV
	TraceConstructeur("Destructeur Figure");
#endif
	if(couleur != NULL)
		delete couleur;
	
	Figure::compteur--;
}


/*====================				Setters						====================*/

void Figure::setPosition(const Point& pos) {
	position.setX(pos.getX());
	position.setY(pos.getY());
}

void Figure::setCouleur(const Couleur* coul) {
	if(couleur != NULL)
		delete couleur;
	
	if(coul != NULL) {
		couleur = new Couleur;
		couleur->setRouge(coul->getRouge());
		couleur->setVert(coul->getVert());
		couleur->setBleu(coul->getBleu());
		couleur->setNom(coul->getNom());
	} else
		couleur = NULL;
}


/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/
void Figure::Affiche() const {
	cout << "Id :\t\t" << id << endl;
	cout << "Position :\t[" << position.getX() << " , " << position.getY() << "]" << endl;
	if(couleur != NULL) {
		cout << "Couleur :\t(";
		cout << couleur->getRouge() << ", ";
		cout << couleur->getVert() << ", ";
		cout << couleur->getBleu() << ")";
		if(couleur->getNom() == NULL)
			cout << "\t=> Pas de nom" << endl;
		else
			cout << "\t=> " << couleur->getNom() << endl;
	} else
		cout << "Couleur:\tInexistante" << endl;
}
