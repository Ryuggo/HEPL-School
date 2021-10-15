#include "Dessin.h"

/*====================		Constructeur par Défaut				====================*/

Dessin::Dessin() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Dessin");
#endif
}


/*====================		Constructeur d'Initialisation		====================*/

Dessin::Dessin(const Couleur& f) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Dessin");
#endif
	setFond(f);
}


/*====================		Constructeur de Copie				====================*/

Dessin::Dessin(const Dessin& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Dessin");
#endif
}


/*====================				Destructeur					====================*/

Dessin::~Dessin() {
#ifdef DEV
	TraceConstructeur("Destructeur Dessin");
#endif
}


/*====================				Setters						====================*/

//...


/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/

Couleur* Dessin::ajouteCouleur(const Couleur& c) {
	Iterateur<Couleur> it(palette);
	Couleur coul;
	short i = 0;
	
	for(it.reset(); !it.end() && i == 0; it++) {
		coul = (Couleur)it;
		if(strcmp(c.getNom(), coul.getNom()) == 0)
    		i++;
    }

	if(i == 0)
		return palette.insere(c);
	else
		throw DessinException("La couleur existe déjà", c.getNom());
		
	return NULL;
}

void Dessin::ajouteFigure(Figure *pf, const char* nomCouleur) {
	Iterateur<Couleur> it(palette);
	Couleur coul;
	short i = 0;
	
	for(it.reset(); !it.end() && i == 0; it++) {
		coul = (Couleur)it;
		if(strcmp(nomCouleur, coul.getNom()) == 0)
    		i++;
    }
    it--;
	
	if(i != 0) {
		figures.push(pf);
		
		pf->setCouleur(&coul);
	} else
		throw DessinException("La couleur n'existe pas", nomCouleur);
}

void Dessin::Dessine() {
	Figure* f;
	Iterateur<Figure*> it(figures);
	int i = figures.getNombreElements();
	
	for(it.last(); /*itStart != it &&*/ !it.end() && 0 < i; it--, i--) {
		f = (Figure*)it;
		f->Dessine();
	}
}

void Dessin::undo() {
	Rectangle fondTmp("R99", Point(0, 40), 840, 600, true, &fond);
	if(figures.estVide() != true) {
		figures.pop();
		fondTmp.Dessine();
	}
}

void Dessin::affichePalette() {
	cout << "Nombre d'éléments : " << palette.getNombreElements() << endl;
	palette.Affiche();
}

void Dessin::afficheFigures() {
	Figure* f;
	Iterateur<Figure*> it(figures);
	
	cout << "Nombre d'éléments : " << figures.getNombreElements() << endl;
	
	for(it.reset(); !it.end(); it++) {
		f = (Figure*)it;
		f->Affiche();
	}
}

void Dessin::Save(const char* nom) {
	Iterateur<Couleur> itc(palette);
	Couleur c;
	Iterateur<Figure*> itf(figures);
	Iterateur<Figure*> itStart(figures);
	Figure* f;
	char idf[1];
	
	ofstream file(nom, ios::out);
	
// Couleur de Fond
	fond.Save(file);

// Liste de Couleurs
	int size = palette.getNombreElements();
	file.write((char*)&size, sizeof(int));
	
	for(itc.reset(); !itc.end(); itc++) {
		c = (Couleur)itc;
		c.Save(file);
	}

// Pile de Figures
	size = figures.getNombreElements();
	file.write((char*)&size, sizeof(int));
	
	itStart.reset();
	
	for(itf.last(); itStart != itf && !itf.end(); itf--) {
		f = (Figure*)itf;
		
		Pixel* pp = dynamic_cast<Pixel*>(f);
		if(pp != NULL)
			file.write((char*)"P", sizeof(char));
		Ligne* pl = dynamic_cast<Ligne*>(f);
		if(pl != NULL)
			file.write((char*)"L", sizeof(char));
		Rectangle* pr = dynamic_cast<Rectangle*>(f);
		if(pr != NULL)
			file.write((char*)"R", sizeof(char));
		
//		strcpy(idf, f->getId());
//		file.write((char*)idf, sizeof(char));
		
		f->Save(file);
	}
	f = (Figure*)itf;
	strcpy(idf, f->getId());
	file.write((char*)idf, sizeof(char));
	f->Save(file);
	
//	for(itf.reset(); !itf.end(); itf++) {
//		f = (Figure*)itf;
//		
//		strcpy(idf, f->getId());
//		file.write((char*)idf, sizeof(char));
//		
//		f->Save(file);
//	}
	file.close();
}

void Dessin::Load(const char* nom) {
	Iterateur<Couleur> itc(palette);
	Couleur c;
	const Couleur *ctmp = new Couleur();
	int size, i;
	char idf[1];
	
	Pixel p;
	Ligne l;
	Rectangle r;
	
	ifstream file(nom, ios::in);
	
// Couleur de Fond
	fond.Load(file);

// Liste de Couleurs
	file.read((char*)&size, sizeof(int));
	
	for(i = 0; i < size; i++) {
		c.Load(file);
		ajouteCouleur(c);
		c.setNom("");
	}

// Pile de Figures
	file.read((char*)&size, sizeof(int));
	
	for(i = 0; i < size; i++) {
		file.read((char*)idf, sizeof(char));
		switch(idf[0]) {
			case 'P' :
				p.Load(file, palette);
				
				ctmp = p.getCouleur();
				ajouteFigure(new Pixel(p.getId(), p.getPosition(), NULL), ctmp->getNom());
				break;
			case 'L' :
				l.Load(file, palette);
				
				ctmp = l.getCouleur();
				ajouteFigure(new Ligne(l.getId(), l.getPosition(), l.getExtremite(), NULL), ctmp->getNom());
				break;
			case 'R' :
				r.Load(file, palette);
				
				ctmp = r.getCouleur();
				ajouteFigure(new Rectangle(r.getId(), r.getPosition(), r.getDimX(), r.getDimY(), r.isRempli(), NULL), ctmp->getNom());
				break;
		}
	}
	file.close();
}


/*====================				Opérateurs						====================*/


