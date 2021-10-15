#ifndef LISTEBASE_H
#define LISTEBASE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"

template<class Iterateurb>
	class Iterateur;

template<class T> struct Cellule {
	T valeur;
	Cellule<T>* suivant;
	Cellule<T>* avant;
};

template<class T> class ListeBase {
	friend class Iterateur<T>;

	protected:
		Cellule<T>* pTete;
	
	public:
	//Const par défaut
		ListeBase();
	//Const d'init
		
	//Const de copie
		ListeBase(const ListeBase<T>&);
	//Destructeur
		virtual ~ListeBase();
		
	//Setters
		
	//Getters
		int getNombreElements() const;
		
	//Autres
		bool estVide() const;
		void Affiche() const;
		virtual T* insere(const T&) = 0;
		
	//Opérateurs
//		ListeBase<T>& operator=(const ListeBase<T>&);
};
#endif
