#ifndef FIGURE_H
#define FIGURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "WindowSDL.h"
#include "Ecran.h"
#include "Point.h"
#include "Couleur.h"
#include "BaseException.h"

class Figure {
	protected:
		char id[5];
		Point position;
		Couleur* couleur;
		static int compteur;
		
	public:
	//Constructeur par Défaut
		Figure();
	//Constructeur d'Initialisation
		Figure(const char*, Point);
		Figure(const char*, Point, const Couleur*);
	//Constructeur de Copie
		Figure(const Figure&);
	//Destructeur
		virtual ~Figure();
		
	//Setters
		virtual void setId(const char* idTmp) = 0;		//Force les enfants à avoir une méthode portant le même nom
		void setPosition(const Point&);
		void setCouleur(const Couleur*);
		
	//Getters
		virtual const char* getId() const = 0;
		const Point& getPosition() const { return position; };
		const Couleur* getCouleur() const { return couleur; };
		static const int getCompteur() { return Figure::compteur; };
		
	//Autres
		void Affiche() const;
		virtual void Dessine() const = 0;
		
		virtual void Save(ofstream&) const = 0;
};
#endif
