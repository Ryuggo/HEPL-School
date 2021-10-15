#include "Pixel.h"

/*====================		Constructeur par Défaut				====================*/

Pixel::Pixel(): Figure() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Pixel");
#endif
	strcpy(id, "P000");
}


/*====================		Constructeur d'Initialisation		====================*/

Pixel::Pixel(const char* idTmp, Point pos): Figure(idTmp, pos) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Pixel (Id + Position)");
#endif
}

Pixel::Pixel(const char* idTmp, Point pos, const Couleur* coul): Figure(idTmp, pos, coul) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Pixel (Id + Position + Couleur)");
#endif
}


/*====================		Constructeur de Copie				====================*/

Pixel::Pixel(const Pixel& old): Figure(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Pixel");
#endif
	setId(old.id);
}


/*====================				Destructeur					====================*/

Pixel::~Pixel() {
#ifdef DEV
	TraceConstructeur("Destructeur Pixel");
#endif
}


/*====================				Setters						====================*/

void Pixel::setId(const char* idTmp) {
	if(*idTmp != 'P')
		throw BaseException("Id ne commence pas par 'P'");
	
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

const char* Pixel::getId() const {
	if(id[0] != 'P')
		throw BaseException("Id ne commence pas par 'P'");
	
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

void Pixel::Dessine() const {
	WindowSDL::drawPixel(couleur->getRouge(), couleur->getVert(), couleur->getBleu(), position.getX(), position.getY());
}

void Pixel::Save(ofstream& file) const {
	int size = strlen(id);
	
	file.write((char*)&size, sizeof(int));
	file.write((char*)&id, size);
	
	position.Save(file);
	
	size = strlen(couleur->getNom()) + 1;
	char* nomc = new char[size];
	strcpy(nomc, couleur->getNom());
	
	file.write((char*)&size, sizeof(int));
	file.write((char*)nomc, size);
}

void Pixel::Load(ifstream& file, Liste<Couleur>& palette) {
	Iterateur<Couleur> it(palette);
	Couleur c;
	int size, i;

	file.read((char*)&size, sizeof(int));
	file.read((char*)&id, size);
	if(size < 5)
		id[size] = '\0';
	
	position.Load(file);
	
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

ostream& operator<<(ostream& output, const Pixel& pix) {
	cout << pix.getId() << " [PIXEL : ";
	cout << "Position(" << pix.position.getX() << ", " << pix.position.getY() << "), ";
	cout << "Couleur(";
	if(pix.couleur != NULL) {
		cout << pix.couleur->getRouge() << ", ";
		cout << pix.couleur->getVert() << ", ";
		cout << pix.couleur->getBleu() << ", ";
		if(pix.couleur->getNom() == NULL)
			cout << "Nom Inconnu";
		else
			cout << pix.couleur->getNom();
	} else
		cout << "Aucune Couleur";
	cout << ")]" << endl;
	
	return output;
}
