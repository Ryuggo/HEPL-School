#include "Couleur.h"

int Couleur::compteur = 0;

const Couleur Couleur::ROUGE(255, 0, 0, "Rouge");
const Couleur Couleur::VERT(0, 255, 0, "Vert");
const Couleur Couleur::BLEU(0, 0, 255, "Bleu");


/*====================		Constructeur par Défaut				====================*/

Couleur::Couleur()
{
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Couleur");
#endif
	setRouge(0);
	setVert(0);
	setBleu(0);
	nom = NULL;
	
	setClair(0);
	setFonce(0);
	
	Couleur::compteur++;
}


/*====================		Constructeur d'Initialisation		====================*/

Couleur::Couleur(int r, int g, int b, const char* nomTmp)
{
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Couleur (r g b + nom)");
#endif
	setRouge(r);
	setVert(g);
	setBleu(b);
	
	nom = NULL;
	setNom(nomTmp);
	
	setClair(0);
	setFonce(0);
	
	Couleur::compteur++;
}

Couleur::Couleur(int r, int g, int b)
{
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Couleur (r g b)");
#endif
	setRouge(r);
	setVert(g);
	setBleu(b);
	nom = NULL;
	
	setClair(0);
	setFonce(0);
	
	Couleur::compteur++;
}


/*====================			Constructeur de Copie			====================*/

Couleur::Couleur(const Couleur& old)
{
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Couleur");
#endif
	setRouge(old.rouge);
	setVert(old.vert);
	setBleu(old.bleu);
	nom = NULL;
	setNom(old.getNom());
	
	setClair(old.getClair());
	setFonce(old.getFonce());
	
	Couleur::compteur++;
}


/*====================				Destructeur					====================*/

Couleur::~Couleur()
{
#ifdef DEV
	TraceConstructeur("Destructeur Couleur");
#endif
	if(nom != NULL)
		delete nom;
	
	Couleur::compteur--;
}


/*====================				Setters						====================*/

void Couleur::setRouge(int r) {
	if(r < 0)
		 throw InvalidColorException("Composante rouge trop petite", r);
	if(255 < r)
		 throw InvalidColorException("Composante rouge trop grande", r);

	rouge = r;
}

void Couleur::setVert(int g) {
	if(g < 0)
		 throw InvalidColorException("Composante verte trop petite", g);
	if(255 < g)
		 throw InvalidColorException("Composante verte trop grande", g);

	vert = g;
}

void Couleur::setBleu(int b) {
	if(b < 0)
		 throw InvalidColorException("Composante bleue trop petite", b);
	if(255 < b)
		 throw InvalidColorException("Composante bleue trop grande", b);

	bleu = b;
}

void Couleur::setNom(const char* nomTmp) {
	if(nom != NULL)
		delete nom;
	
	if(nomTmp != NULL) {
		nom = new char[strlen(nomTmp)+1];
		strcpy(nom, nomTmp);
	} else
		nom = NULL;
}


/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/

void Couleur::Affiche() const {
	cout << "( " << rouge << ", " << vert << ", " << bleu << " ) =>\t";

	if(nom != NULL) {
		cout << "Nom :\t" << nom;
		if(clair != 0)
			cout << " Clair(" << clair << ")";
		if(fonce != 0)
			cout << " Fonce(" << fonce << ")";
		cout << endl;
	} else
		cout << "Nom :\tInexistant" << endl;
}

void Couleur::CoulVerif255() {
	if(getRouge() > 255)
		setRouge(255);
	if(getVert() > 255)
		setVert(255);
	if(getBleu() > 255)
		setBleu(255);
}

void Couleur::CoulVerif0() {
	if(getRouge() < 0)
		setRouge(0);
	if(getVert() < 0)
		setVert(0);
	if(getBleu() < 0)
		setBleu(0);
}

void Couleur::Save(ofstream& file) const {
	int size;
	if(nom != NULL)
		size = strlen(nom);
	else
		size = 0;

	file.write((char*)&size, sizeof(int));
	if(nom != NULL)
		file.write((char*)nom, size);
	
	file.write((char*)&rouge, sizeof(int));
	file.write((char*)&vert, sizeof(int));
	file.write((char*)&bleu, sizeof(int));
}

void Couleur::Load(ifstream& file) {
	int size;
	
	file.read((char*)&size, sizeof(int));
	if(size != 0) {
		nom = new char[size+1];
		file.read((char*)nom, size);
	} else
		setNom(NULL);
	
	file.read((char*)&rouge, sizeof(int));
	file.read((char*)&vert, sizeof(int));
	file.read((char*)&bleu, sizeof(int));
}


/*====================				Opérateurs						====================*/

Couleur& Couleur::operator=(const Couleur& newC) {
	setRouge(newC.rouge);
	setVert(newC.vert);
	setBleu(newC.bleu);
	setNom(newC.getNom());
	
	setClair(newC.getClair());
	setFonce(newC.getFonce());
	
	return *this;
}

Couleur Couleur::operator+(const Couleur& c) {
	char nomTmp[50] = {"\0"};
	
	setRouge((getRouge() + c.rouge) / 2);
	setVert((getVert() + c.vert) / 2);
	setBleu((getBleu() + c.bleu) / 2);
	
	if(getNom() == NULL || c.getNom() == NULL)
		setNom("Mélange Inconnu");
	else {
		strcat(nomTmp, "Mélange de ");
		strcat(nomTmp, getNom());
		strcat(nomTmp, " et de ");
		strcat(nomTmp, c.nom);
		
		setNom(nomTmp);
	}
	
	return *this;
}

Couleur Couleur::operator+(int i) const {
	Couleur coul(*this);
	
	coul.setRouge(coul.getRouge() + i);
	coul.setVert(coul.getVert() + i);
	coul.setBleu(coul.getBleu() + i);
	
	coul.CoulVerif255();
	
	coul.setClair(coul.getClair() + i);

	return coul;
}

Couleur Couleur::operator-(int i){
	Couleur coul(*this);
	
	coul.setRouge(coul.getRouge() - i);
	coul.setVert(coul.getVert() - i);
	coul.setBleu(coul.getBleu() - i);
	
	coul.CoulVerif0();
	
	coul.setFonce(coul.getFonce() + i);

	return coul;
}

Couleur Couleur::operator[](const char* tmp){
	Couleur coul(*this);
	int i;
	
	sscanf(tmp, "%d", &i);
	
	if(strcmp(tmp, "rouge") == 0)
		coul.setRouge(i);

	return coul;
}

ostream& operator<<(ostream& output, const Couleur& c){
	output << "[" << c.getRouge() << "," << c.getVert() << "," << c.getBleu();
	if(c.nom != NULL)
		output << " (" << c.getNom() << ")]" << endl;
	else
		output << " (Aucun Nom)]" << endl;

	return output;
}

istream& operator>>(istream& input, Couleur& c){
	input >> c.rouge >> c.vert >> c.bleu >> c.nom;
	
	return input;
}

Couleur& Couleur::operator++() {
	setRouge(getRouge() + 10);
	setVert(getVert() + 10);
	setBleu(getBleu() + 10);
	
	CoulVerif255();
	
	return *this;
}

Couleur Couleur::operator++(int) {
	Couleur coul(*this);
	++(*this);
	
	return coul;
}

Couleur& Couleur::operator--() {
	setRouge(getRouge() - 10);
	setVert(getVert() - 10);
	setBleu(getBleu() - 10);
	
	CoulVerif0();
	
	return *this;
}

Couleur Couleur::operator--(int) {
	Couleur coul(*this);
	--(*this);
	
	return coul;
}
