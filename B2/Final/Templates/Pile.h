#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "ListeBase.h"

template<class T> class Pile :
 public ListeBase<T> {
 	using ListeBase<T>::pTete;
 	
	private:
	
	public:
	//Const par défaut
		Pile();
	//Const d'init
		
	//Const de copie
		Pile(const Pile<T>&);
	//Destructeur
		~Pile();
		
	//Setters
		
	//Getters
		
	//Autres
		T* insere(const T&);
		void push(const T& val) { insere(val); };
		T top() { return pTete->valeur; };
		T pop();
		
	//Opérateurs
};
#endif
