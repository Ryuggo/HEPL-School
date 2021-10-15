#ifndef LIGNE_H
#define LIGNE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "WindowSDL.h"
#include "Figure.h"
#include "Liste.h"
#include "Iterateur.h"

class Ligne:
 public Figure {
	private:
		Point extremite;
		
	public:
	//Constructeur par Défaut
		Ligne();
	//Constructeur d'Initialisation
		Ligne(const char*, Point, Point, const Couleur*);
	//Constructeur de Copie
		Ligne(const Ligne&);
	//Destructeur
		~Ligne();
		
	//Setters
		void setId(const char* idTmp);
		void setExtremite(const Point&);
		
	//Getters
		const char* getId() const;
		const Point& getExtremite() const { return extremite; };
		
	//Autres
		void Dessine() const;
		
		void Save(ofstream&) const;
		void Load(ifstream&, Liste<Couleur>&);
		
	//Opérateurs
		friend ostream& operator<<(ostream&, const Ligne&);
};
#endif
