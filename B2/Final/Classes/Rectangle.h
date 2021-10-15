#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "WindowSDL.h"
#include "Figure.h"
#include "Liste.h"
#include "Iterateur.h"

class Rectangle:
 public Figure {
	private:
		int dimX, dimY;
		bool rempli;
		
	public:
	//Constructeur par Défaut
		Rectangle();
	//Constructeur d'Initialisation
		Rectangle(const char*, Point, int, int, bool, const Couleur*);
	//Constructeur de Copie
		Rectangle(const Rectangle&);
	//Destructeur
		~Rectangle();
		
	//Setters
		void setId(const char* idTmp);
		void setDimX(int x) { dimX = x; };
		void setDimY(int y) { dimY = y; };
		void setRempli(bool r) { rempli = r; };
		
	//Getters
		const char* getId() const;
		int getDimX() const { return dimX; };
		int getDimY() const { return dimY; };
		bool isRempli() const { return rempli; };
		
	//Autres
		void Dessine() const;
		
		void Save(ofstream&) const;
		void Load(ifstream&, Liste<Couleur>&);
		
	//Opérateurs
		friend ostream& operator<<(ostream&, const Rectangle&);
};
#endif
