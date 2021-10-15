#include "Liste.h"

/*====================			Constructeur par Défaut			====================*/

template <class T>
Liste<T>::Liste(): ListeBase<T>() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Liste");
#endif
}


/*====================		Constructeur d'Initialisation		====================*/

// ...


/*====================			Constructeur de Copie			====================*/

template <class T>
Liste<T>::Liste(const Liste<T>& old): ListeBase<T>(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Liste");
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
		
		tmp->suivant = tmpVal;
		tmp = tmpVal;
		
		tmpOld = tmpOld->suivant;
	}
}


/*====================				Destructeur					====================*/

template <class T>
Liste<T>::~Liste() {
#ifdef DEV
	TraceConstructeur("Destructeur Liste");
#endif
}


/*====================				Setters						====================*/

// ...


/*====================				Getters						====================*/

// ...


/*====================				Autres						====================*/

template <class T>
T* Liste<T>::insere(const T& val) {
	Cellule<T>* tmp;
	Cellule<T>* tmpVal;

	if(pTete == NULL) {
		tmpVal = new Cellule<T>;
		tmpVal->valeur = val;
		tmpVal->avant = NULL;
		tmpVal->suivant = NULL;
		
		pTete = tmpVal;
		cout << endl << "Création de Liste" << endl;
		cout << "Liste :   " << pTete->valeur;
	} else {
		tmp = pTete;
		while(tmp->suivant != NULL) {
			tmp = tmp->suivant;
		}
		
		tmpVal = new Cellule<T>;
		tmpVal->valeur = val;
		tmpVal->avant = tmp;
		tmpVal->suivant = NULL;
		
		tmp->suivant = tmpVal;
		cout << "Liste+ :  " << tmpVal->valeur;
	}
	return &tmpVal->valeur;
}


/*====================				Opérateurs					====================*/

// ...


/*====================				Templates					====================*/

template class Liste<int>;
#include "Couleur.h"
template class Liste<Couleur>;
#include "BoutonCouleur.h"
template class Liste<Bouton>;
template class Liste<BoutonCouleur>;
