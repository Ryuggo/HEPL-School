#include "Liste.h"

/*====================			Constructeur par Défaut			====================*/

template <class T>
Liste<T>::Liste(): ListeBase<T>() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Liste");
#endif
}


/*====================			Constructeur de Copie			====================*/

template <class T>
Liste<T>::Liste(const Liste<T>& old): ListeBase<T>(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Liste");
#endif
}


/*====================				Destructeur					====================*/

template <class T>
Liste<T>::~Liste() {
#ifdef DEV
	TraceConstructeur("Destructeur Liste");
#endif
}


/*====================				Autres						====================*/

template <class T>
T* Liste<T>::insere(const T& val) {
	Cellule<T>* tmpVal = new Cellule<T>;
	tmpVal->valeur = val;
	
	Cellule<T>* tmp = pTete;

	if(pTete == NULL) {
		tmpVal->avant = NULL;
		tmpVal->suivant = NULL;
		pTete = tmpVal;
		
		cout << endl << "Création de Liste" << endl;
	} else {
		while(tmp->suivant != NULL)
			tmp = tmp->suivant;
		
		tmpVal->avant = tmp;
		tmpVal->suivant = NULL;
		
		tmp->suivant = tmpVal;
	}
	return &tmpVal->valeur;
}


/*====================				Templates					====================*/

template class Liste<int>;
template class Liste<float>;
#include "Data1D.h"
template class Liste<Data1D>;
#include "Data2D.h"
template class Liste<Data2D>;
