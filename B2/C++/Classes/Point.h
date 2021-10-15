#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"

class Point {
	private:
		int x, y;
		static int compteur;
		
	public:
	//Constructeur par Défaut
		Point();
	//Constructeur d'Initialisation
		Point(int, int);
	//Constructeur de Copie
		Point(const Point&);
	//Destructeur
		~Point();
		
	//Setters
		void setX(int xTmp) { x = xTmp; };
		void setY(int yTmp) { y = yTmp; };
		
	//Getters
		int getX() const { return x; };
		int getY() const { return y; };
		static const int getCompteur() { return Point::compteur; };
		
	//Autres
		void Affiche() const;
		
		void Save(ofstream&) const;
		void Load(ifstream&);
		
	//Opérateurs
		friend ostream& operator<<(ostream&, const Point&);
};
#endif
