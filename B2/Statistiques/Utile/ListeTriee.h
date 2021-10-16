#ifndef LISTETRIEE_H
#define LISTETRIEE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "ListeBase.h"

template<class T> class ListeTriee :
 public ListeBase<T> {
 	using ListeBase<T>::pTete;
 	
	private:
	
	public:
	//Constructeurs
		ListeTriee();
		ListeTriee(const ListeTriee<T>&);
		~ListeTriee();
		
	//Autres
		T* insere(const T&);
};
#endif
