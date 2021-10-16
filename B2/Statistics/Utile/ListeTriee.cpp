#include "ListeTriee.h"

/*====================			Constructeur par Défaut			====================*/

template <class T>
ListeTriee<T>::ListeTriee(): ListeBase<T>() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut ListeTriee");
#endif
}


/*====================			Constructeur de Copie			====================*/

template <class T>
ListeTriee<T>::ListeTriee(const ListeTriee<T>& old): ListeBase<T>(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie ListeTriee");
#endif
}


/*====================				Destructeur					====================*/

template <class T>
ListeTriee<T>::~ListeTriee() {
#ifdef DEV
	TraceConstructeur("Destructeur ListeTriee");
#endif
}


/*====================				Autres						====================*/

template <class T>
T* ListeTriee<T>::insere(const T& val) {
	T val2 = val;
	Cellule<T>* tmpVal = new Cellule<T>;
	tmpVal->valeur = val;
	
	Cellule<T>* tmp = pTete;
	Cellule<T>* tmpPrec = NULL;

	if(pTete == NULL) {
		tmpVal->avant = NULL;
		tmpVal->suivant = NULL;
		pTete = tmpVal;
		
		cout << endl << "Création de ListeTriee" << endl;
	} else {
		while(tmp != NULL && tmp->valeur < val2) {
			tmpPrec = tmp;
			tmp = tmp->suivant;
		}
		tmpVal->suivant = tmp;
		
		if(tmpPrec == NULL) {
			pTete = tmpVal;
			tmpVal->avant = NULL;
		} else {
			tmpPrec->suivant = tmpVal;
			tmpVal->avant = tmpPrec;
		}
	}
	return &tmpVal->valeur;
}


/*====================				Templates					====================*/

template class ListeTriee<int>;
template class ListeTriee<float>;
#include "Data1D.h"
template class ListeTriee<Data1D>;
#include "Data2D.h"
template class ListeTriee<Data2D>;
