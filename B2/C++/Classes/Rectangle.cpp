#include "Rectangle.h"

/*====================		Constructeur par Défaut				====================*/

Rectangle::Rectangle(): Figure() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Rectangle");
#endif
	strcpy(id, "R000");
	setDimX(0);
	setDimY(0);
	setRempli(0);
}


/*====================		Constructeur d'Initialisation		====================*/

Rectangle::Rectangle(const char* idTmp, Point pos, int x, int y, bool r, const Couleur* coul): Figure(idTmp, pos, coul) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Rectangle (Id + Position + Couleur)");
#endif
	setDimX(x);
	setDimY(y);
	setRempli(r);
}


/*====================		Constructeur de Copie				====================*/

Rectangle::Rectangle(const Rectangle& old): Figure(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Rectangle");
#endif
	setId(old.id);
	setDimX(old.getDimX());
	setDimY(old.getDimY());
	setRempli(old.isRempli());
}


/*====================				Destructeur					====================*/

Rectangle::~Rectangle() {
#ifdef DEV
	TraceConstructeur("Destructeur Rectangle");
#endif
}


/*====================				Setters						====================*/

void Rectangle::setId(const char* idTmp) {
	if(*idTmp != 'R')
		throw BaseException("Id ne commence pas par 'R'");
	
	if(*(idTmp+1) == '\0')
		throw BaseException("Id trop court");
	if(strlen(idTmp) > 4)
		throw BaseException("Id trop long");
	
	for(short i = 1; i < 2 && *(idTmp+i) != '\0'; i++)
		if(*(idTmp+i) < '0' || '9' < *(idTmp+i))
			throw BaseException("Id possède un autre caractère qu'un chiffre");
	
	strcpy(id, idTmp);
}


/*====================				Getters						====================*/

const char* Rectangle::getId() const {
	if(id[0] != 'R')
		throw BaseException("Id ne commence pas par 'R'");
	
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

void Rectangle::Dessine() const {
	if(isRempli() == 1)
		WindowSDL::fillRectangle(couleur->getRouge(), couleur->getVert(), couleur->getBleu(), position.getX(), position.getY(), getDimX(), getDimY());
	else
		WindowSDL::drawRectangle(couleur->getRouge(), couleur->getVert(), couleur->getBleu(), position.getX(), position.getY(), getDimX(), getDimY());
}

void Rectangle::Save(ofstream& file) const {
	int size = strlen(id);
	
	file.write((char*)&size, sizeof(int));
	file.write((char*)&id, size);
	
	position.Save(file);
	
	file.write((char*)&dimX, sizeof(int));
	file.write((char*)&dimY, sizeof(int));
	file.write((char*)&rempli, sizeof(bool));
	
	size = strlen(couleur->getNom()) + 1;
	char* nom = new char[size];
	strcpy(nom, couleur->getNom());
	
	file.write((char*)&size, sizeof(int));
	file.write((char*)nom, size);
}

void Rectangle::Load(ifstream& file, Liste<Couleur>& palette) {
	Iterateur<Couleur> it(palette);
	Couleur c;
	int size, i;

	file.read((char*)&size, sizeof(int));
	file.read((char*)&id, size);
	if(size < 5)
		id[size] = '\0';
	
	position.Load(file);
	
	file.read((char*)&dimX, sizeof(int));
	file.read((char*)&dimY, sizeof(int));
	file.read((char*)&rempli, sizeof(bool));
	
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

ostream& operator<<(ostream& output, const Rectangle& rec) {
	cout << rec.getId() << " [RECTANGLE : ";
	cout << "Position(" << rec.position.getX() << ", " << rec.position.getY() << "), ";
	cout << "DimX=" << rec.getDimX() << ", DimY=" << rec.getDimY() << ", Rempli=" << rec.isRempli();
	cout << ", Couleur(";
	if(rec.couleur != NULL) {
		cout << rec.couleur->getRouge() << ", ";
		cout << rec.couleur->getVert() << ", ";
		cout << rec.couleur->getBleu() << ", ";
		if(rec.couleur->getNom() == NULL)
			cout << "Nom Inconnu";
		else
			cout << rec.couleur->getNom();
	} else
		cout << "Aucune Couleur";
	cout << ")]" << endl;
	
	return output;
}
