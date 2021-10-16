#ifndef LISTE_H
#define LISTE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "ListeBase.h"

template<class T> class Liste :
 public ListeBase<T> {
 	using ListeBase<T>::pTete;
 	
	private:
	
	public:
	//Constructeurs
		Liste();
		Liste(const Liste<T>&);
		~Liste();
		
	//Autres
		T* insere(const T&);
};
#endif
