#ifndef INVALIDCOLOREXCEPTION_H
#define INVALIDCOLOREXCEPTION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "Ecran.h"
#include "BaseException.h"

class InvalidColorException: public BaseException {
	private:
		int valeur;
		
	public:
	//Constructeur par défaut
	//Constructeur d'initialisation
		InvalidColorException(const char*, int);
	//Constructeur de copie
		InvalidColorException(const InvalidColorException&);
	//Destructeur
		virtual ~InvalidColorException();		//Va chercher les destructeurs de toutes les filles avant la mère
		
	//Setters
		void setValeur(int v) { valeur = v; };
		
	//Getters
		int getValeur() const { return valeur; };
		
	//Autres
		const void Affiche() const { cout << getMsg() << " (" << getValeur() << ")" << endl; };
		
	//Opérateurs
		
};
#endif
