#include "Pile.h"

/*====================			Constructeur par Défaut			====================*/

template <class T>
Pile<T>::Pile(): ListeBase<T>() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Pile");
#endif
}


/*====================		Constructeur d'Initialisation		====================*/

// ...


/*====================			Constructeur de Copie			====================*/

template <class T>
Pile<T>::Pile(const Pile<T>& old): ListeBase<T>(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Pile");
#endif
	Cellule<T> *tmp, *tmpOld;
	Cellule<T>* tmpVal;
	
	tmpOld = old.pTete;
	
	pTete = new Cellule<T>;
	pTete->valeur = old.pTete->valeur;
	
	tmpVal = pTete;
	tmp = tmpVal;
	
	tmpOld = tmpOld->suivant;
	
	while(tmpOld != NULL) {
		tmpVal = new Cellule<T>;
		tmpVal->valeur = tmpOld->valeur;
		tmpVal->suivant = NULL;
		
		tmpVal->avant = tmp;
		tmp->suivant = tmpVal;
		tmp = tmpVal;
		
		tmpOld = tmpOld->suivant;
	}
}


/*====================				Destructeur					====================*/

template <class T>
Pile<T>::~Pile() {
#ifdef DEV
	TraceConstructeur("Destructeur Pile");
#endif
}


/*====================				Setters						====================*/

// ...


/*====================				Getters						====================*/

// ...


/*====================				Autres						====================*/

template <class T>
T* Pile<T>::insere(const T& val) {
	Cellule<T>* tmp, *tmp2;
	
	tmp = new Cellule<T>;
	tmp->valeur = val;
	tmp->avant = NULL;
	
	if(pTete == NULL) {
		tmp->suivant = NULL;
	
		pTete = tmp;
		cout << endl << "Création de Pile" << endl;
		cout << "Pile :   " << pTete->valeur;
	} else {
		tmp->suivant = pTete;
		pTete->avant = tmp;
		tmp2 = tmp->suivant;
		tmp2->avant = tmp;
	
		pTete = tmp;
		cout << "Pile+ :  " << pTete->valeur;
	}
	return &pTete->valeur;
}

template <class T>
T Pile<T>::pop() {
	T valeur = pTete->valeur;
	Cellule<T>* tmp;
	
	tmp = pTete;
	pTete = pTete->suivant;
	
	delete tmp;

	return valeur;
}


/*====================				Opérateurs					====================*/

// ...


/*====================				Templates					====================*/

template class Pile<int>;
#include "Couleur.h"
template class Pile<Couleur>;
#include "Figure.h"
template class Pile<Figure*>;
