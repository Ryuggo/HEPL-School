#ifndef ITERATEUR_H
#define ITERATEUR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "ListeBase.h"

template<class T> class Iterateur {
	private:
		ListeBase<T>& listebase;
		Cellule<T>* iter;
	
	public:
	//Const par défaut
	
	//Const d'init
	
	//Const de copie
		Iterateur(ListeBase<T>& l) : listebase(l), iter(l.pTete) {};
	//Destructeur
		
	//Setters
		
	//Getters
		
	//Autres
		void reset() { iter = listebase.pTete; };
		void last();
		bool end();
		T remove();
		
	//Opérateurs
		bool operator++();
		bool operator++(int) { return operator++(); };
		bool operator--();
		bool operator--(int) { return operator--(); };
		
		T* operator&(void) { return &(iter->valeur); };
		
		operator T()const { return iter->valeur; };
};
#endif
