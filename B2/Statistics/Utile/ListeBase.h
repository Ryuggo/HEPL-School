#ifndef LISTEBASE_H
#define LISTEBASE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include <iostream>

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
	//Constructeurs
		ListeBase();
		ListeBase(const ListeBase<T>&);
		virtual ~ListeBase();
		
	//Setters
		
	//Getters
		int Size() const;
		T getElement(int) const;
		Cellule<T>* getPtete() const { return pTete; };
		
	//Autres
		bool estVide() const;
		void Affiche() const;
		virtual T* insere(const T&) = 0;
		
	//Opérateurs
		ListeBase<T>& operator=(const ListeBase<T>&);
};
#endif
