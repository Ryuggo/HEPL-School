#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "Ecran.h"

class BaseException {
	protected:
		char* msg;
		
	public:
	//Constructeur par défaut
	//Constructeur d'initialisation
		BaseException(const char*);
	//Constructeur de copie
		BaseException(const BaseException&);
	//Destructeur
		virtual ~BaseException();		//Va chercher les destructeurs de toutes les filles avant la mère
		
	//Setters
		void setMsg(const char*);
		
	//Getters
		virtual const char* getMsg() const;
		
	//Autres
		
	//Opérateurs
		
};
#endif
