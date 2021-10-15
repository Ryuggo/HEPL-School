#ifndef BOUTON_H
#define BOUTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "Point.h"
#include "WindowSDL.h"

class Bouton {
	protected:
		Point X1, X2;
		char* nom;
		bool selected;
		
	public:		
	//Constructeur par défaut
		Bouton();
	//Constructeur d'initialisation
		Bouton(const char*, Point, Point);
	//Constructeur de copie
		Bouton(const Bouton&);
	//Destructeur
		virtual ~Bouton();
		
	//Setters
		void setX1(const Point&);
		void setX2(const Point&);
		void setNom(const char*);
		virtual void setSelected(bool);
		
	//Getters
		const Point& getX1() const { return X1; };
		const Point& getX2() const { return X2; };
		const char* getNom() const { return nom; };
		bool getSelected() const { return selected; };
		
	//Autres
		bool clic(int, int);
		
	//Opérateurs
		Bouton& operator=(const Bouton&);
		
		friend ostream& operator<<(ostream&, const Bouton&);
};
#endif
