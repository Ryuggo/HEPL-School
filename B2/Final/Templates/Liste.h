#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "ListeBase.h"

template<class T> class Liste :
 public ListeBase<T> {
 	using ListeBase<T>::pTete;
 	
	private:
	
	public:
	//Const par défaut
		Liste();
	//Const d'init
		
	//Const de copie
		Liste(const Liste<T>&);
	//Destructeur
		~Liste();
		
	//Setters
		
	//Getters
		
	//Autres
		T* insere(const T&);
		
	//Opérateurs
};
#endif
