#include "Ligne.h"

/*====================		Constructeur par Défaut				====================*/

Ligne::Ligne(): Figure() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Ligne");
#endif
	strcpy(id, "L000");
	Point extremite;
}


/*====================		Constructeur d'Initialisation		====================*/

Ligne::Ligne(const char* idTmp, Point pos, Point extr, const Couleur* coul): Figure(idTmp, pos, coul) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Ligne (Id + Position + Couleur)");
#endif
	setExtremite(extr);
}


/*====================		Constructeur de Copie				====================*/

Ligne::Ligne(const Ligne& old): Figure(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Ligne");
#endif
	setId(old.id);
	setExtremite(old.extremite);
}


/*====================				Destructeur					====================*/

Ligne::~Ligne() {
#ifdef DEV
	TraceConstructeur("Destructeur Ligne");
#endif
}


/*====================				Setters						====================*/

void Ligne::setId(const char* idTmp) {
	if(*idTmp != 'L')
		throw BaseException("Id ne commence pas par 'L'");
	
	if(*(idTmp+1) == '\0')
		throw BaseException("Id trop court");
	if(strlen(idTmp) > 4)
		throw BaseException("Id trop long");
	
	for(short i = 1; i < 2 && *(idTmp+i) != '\0'; i++)
		if(*(idTmp+i) < '0' || '9' < *(idTmp+i))
			throw BaseException("Id possède un autre caractère qu'un chiffre");
	
	strcpy(id, idTmp);
}

void Ligne::setExtremite(const Point& extr) {
	extremite.setX(extr.getX());
	extremite.setY(extr.getY());
}


/*====================				Getters						====================*/

const char* Ligne::getId() const {
	if(id[0] != 'L')
		throw BaseException("Id ne commence pas par 'L'");
	
	if(id[1] == '\0')
		throw BaseException("Id trop court");
	if(strlen(id) > 4)
		throw BaseException("Id trop long");
	
	for(short i = 1; i < 2 && id[i] != '\0'; i++)
		if(id[i] < '0' || '9' < id[i])
			throw BaseException("Id possède un autre caractère qu'un chiffre");
	
	 return id;
}


/*====================				Autres						====================*/

void Ligne::Dessine() const {
	WindowSDL::drawLine(couleur->getRouge(), couleur->getVert(), couleur->getBleu(), position.getX(), position.getY(), extremite.getX(), extremite.getY());
}

void Ligne::Save(ofstream& file) const{
	int size = strlen(id);
	
	file.write((char*)&size, sizeof(int));
	file.write((char*)id, size);
	
	position.Save(file);
	extremite.Save(file);
	
	size = strlen(couleur->getNom()) + 1;
	char* nom = new char[size];
	strcpy(nom, couleur->getNom());
	
	file.write((char*)&size, sizeof(int));
	file.write((char*)nom, size);
}

void Ligne::Load(ifstream& file, Liste<Couleur>& palette) {
	Iterateur<Couleur> it(palette);
	Couleur c;
	int size, i;

	file.read((char*)&size, sizeof(int));
	file.read((char*)id, size);
	if(size < 5)
		id[size] = '\0';
	
	position.Load(file);
	extremite.Load(file);
	
	file.read((char*)&size, sizeof(int));
	char* nomc = new char[size];
	file.read((char*)nomc, size);
	
	for(i = 0, it.reset(); !it.end() && i == 0; it++) {
		c = (Couleur)it;
		if(strcmp(nomc, c.getNom()) == 0) {
			setCouleur(&c);
			i++;
		}
    }
}


/*====================				Opérateurs						====================*/

ostream& operator<<(ostream& output, const Ligne& lig) {
	cout << lig.getId() << " [LIGNE : ";
	cout << "Position(" << lig.position.getX() << ", " << lig.position.getY() << "), ";
	cout << "Extremite(" << lig.extremite.getX() << ", " << lig.extremite.getY() << "), ";
	cout << "Couleur(";
	if(lig.couleur != NULL) {
		cout << lig.couleur->getRouge() << ", ";
		cout << lig.couleur->getVert() << ", ";
		cout << lig.couleur->getBleu() << ", ";
		if(lig.couleur->getNom() == NULL)
			cout << "Nom Inconnu";
		else
			cout << lig.couleur->getNom();
	} else
		cout << "Aucune Couleur";
	cout << ")]" << endl;
	
	return output;
}
