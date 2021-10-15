#ifndef PIXEL_H
#define PIXEL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "WindowSDL.h"
#include "Figure.h"
#include "Liste.h"
#include "Iterateur.h"

class Pixel:
 public Figure {
	private:
		
	public:
	//Constructeur par Défaut
		Pixel();
	//Constructeur d'Initialisation
		Pixel(const char*, Point);
		Pixel(const char*, Point, const Couleur*);
	//Constructeur de Copie
		Pixel(const Pixel&);
	//Destructeur
		~Pixel();
		
	//Setters
		void setId(const char* idTmp);
		
	//Getters
		const char* getId() const;
		
	//Autres
		void Affiche() const;
		void Dessine() const;
		
		void Save(ofstream&) const;
		void Load(ifstream&, Liste<Couleur>&);
		
	//Opérateurs
		friend ostream& operator<<(ostream&, const Pixel&);
};
#endif
