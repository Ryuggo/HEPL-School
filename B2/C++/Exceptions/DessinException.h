#ifndef DESSINEXCEPTION_H
#define DESSINEXCEPTION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "Ecran.h"
#include "BaseException.h"

class DessinException: public BaseException {
	private:
		char* nom;
		
	public:
	//Constructeur par défaut
	//Constructeur d'initialisation
		DessinException(const char*, const char* n);
	//Constructeur de copie
		DessinException(const DessinException&);
	//Destructeur
		virtual ~DessinException();		//Va chercher les destructeurs de toutes les filles avant la mère
		
	//Setters
		void setNom(const char*);
		
	//Getters
		const char* getNom() const { return nom; };
		
	//Autres
		const void Affiche() const { cout << getMsg() << " (" << getNom() << ")" << endl; };
		
	//Opérateurs
		
};
#endif
