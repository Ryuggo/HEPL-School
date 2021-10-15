#include "Iterateur.h"

/*====================			Constructeur par Défaut			====================*/

// ...


///*====================		Constructeur d'Initialisation		====================*/

// ...


///*====================			Constructeur de Copie			====================*/

// ...


/*====================				Destructeur					====================*/

// ...


/*====================				Setters						====================*/

// ...


/*====================				Getters						====================*/

// ...


/*====================				Autres						====================*/

template <class T>
void Iterateur<T>::last() {
	iter = listebase.pTete;
	
	if(iter != NULL)
		while(iter->suivant != NULL)
			iter = iter->suivant;
}

template <class T>
bool Iterateur<T>::end() {
	if(iter == NULL)
		return true;
	return false;
}

template <class T>
T Iterateur<T>::remove() {
	Cellule<T> *tmp, *del;
	
	del = iter;
	if(iter == listebase.pTete) {
		iter = iter->suivant;
		iter->avant = NULL;
		listebase.pTete = iter;
	} else {
		tmp = iter->avant;
		tmp->suivant = iter->suivant;
		iter = iter->suivant;
		iter->avant = tmp;
	}
	
	return del->valeur;
}


/*====================				Opérateurs					====================*/

template <class T>
bool Iterateur<T>::operator++() {
	if(iter != NULL) {
		iter = iter->suivant;
		return true;
	}
	
	return false;
}

template <class T>
bool Iterateur<T>::operator--() {
	if(iter != NULL) {
		iter = iter->avant;
		return true;
	}
	
	return false;
}


/*====================				Templates					====================*/

template class Iterateur<int>;
#include "Couleur.h"
template class Iterateur<Couleur>;
#include "Figure.h"
template class Iterateur<Figure*>;
#include "BoutonCouleur.h"
template class Iterateur<Bouton>;
template class Iterateur<BoutonCouleur>;
