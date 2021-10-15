#ifndef DESSIN_H
#define DESSIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "WindowSDL.h"
#include "Liste.h"
#include "Pile.h"
#include "Iterateur.h"
#include "Figure.h"
#include "Pixel.h"
#include "Ligne.h"
#include "Rectangle.h"
#include "DessinException.h"

class Dessin {
	private:
		Couleur fond;
		Liste<Couleur> palette;
		Pile<Figure*> figures;
		
	public:
	//Constructeur par Défaut
		Dessin();
	//Constructeur d'Initialisation
		Dessin(const Couleur&);
	//Constructeur de Copie
		Dessin(const Dessin&);
	//Destructeur
		virtual ~Dessin();
		
	//Setters
		void setFond(const Couleur& c) { fond = c; };
		
	//Getters
		Couleur getFond() const { return fond; };
		
	//Autres
		Couleur* ajouteCouleur(const Couleur& c);
		void ajouteFigure(Figure *pf, const char* nomCouleur);
		void Dessine();
		void undo();
		void affichePalette();
		void afficheFigures();
		
		void VerifName();
		
		void Save(const char*);
		void Load(const char*);
		
	//Opérateurs
//		friend ostream& operator<<(ostream&, const Dessin&);
};
#endif
