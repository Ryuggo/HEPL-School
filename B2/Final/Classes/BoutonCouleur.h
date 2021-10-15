#ifndef BOUTONCOULEUR_H
#define BOUTONCOULEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "Bouton.h"
#include "Couleur.h"

class BoutonCouleur:
 public Bouton {
	private:
		Couleur* couleur;
		
	public:		
	//Constructeur par défaut
		BoutonCouleur();
	//Constructeur d'initialisation
		BoutonCouleur(const char*, Point, Point);
	//Constructeur de copie
		BoutonCouleur(const BoutonCouleur&);
	//Destructeur
		~BoutonCouleur();
		
	//Setters
		void setCouleur(Couleur*);
		void setSelected(bool);
		
	//Getters
		Couleur* getCouleur() const { return couleur; };
		
	//Autres
		
	//Opérateurs
		BoutonCouleur& operator=(const BoutonCouleur&);
		
		friend ostream& operator<<(ostream&, const BoutonCouleur&);
};
#endif
