#include "ListeBase.h"

/*====================			Constructeur par Défaut			====================*/

template <class T>
ListeBase<T>::ListeBase() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut ListeBase");
#endif
	pTete = NULL;
}


/*====================		Constructeur d'Initialisation		====================*/

// ...


/*====================			Constructeur de Copie			====================*/

template <class T>
ListeBase<T>::ListeBase(const ListeBase<T>& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie ListeBase");
#endif
	Cellule<T> *tmp, *tmpOld, *prec;
	
	tmpOld = old.pTete;
	
	pTete = new Cellule<T>;
	pTete->valeur = old.pTete->valeur;
	
	tmpOld->avant = NULL;
	tmpOld = tmpOld->suivant;
	
	tmp = pTete;
	prec = tmp;
	
	while(tmpOld != NULL) {
		tmp = new Cellule<T>;
		tmp->valeur = tmpOld->valeur;
		tmp->suivant = NULL;
		
		prec->suivant = tmp;
		prec = tmp;
		
		tmpOld->avant = tmp;
		tmpOld = tmpOld->suivant;
	}
}


/*====================				Destructeur					====================*/

template <class T>
ListeBase<T>::~ListeBase() {
#ifdef DEV
	TraceConstructeur("Destructeur ListeBase");
#endif
	Cellule<T>* tmp = pTete;
	Cellule<T>* tmp2 = NULL;
	
	pTete = NULL;
	while(tmp != NULL) {
		tmp2 = tmp;
		tmp = tmp->suivant;
		delete tmp2;
	}
}


/*====================				Setters						====================*/

// ...


/*====================				Getters						====================*/

template <class T>
int ListeBase<T>::Size() const {
	Cellule<T>* tmp = pTete;
	int i = 0;

	while(tmp != NULL) {
		tmp = tmp->suivant;
		i++;
	}
	return i;
}

template <class T>
T  ListeBase<T>::getElement(int n) const {
	Cellule<T>* tmp = pTete;
	
//	if(pTete == NULL)
//		return 0;
//	else
		for(int i = 0; i < n; i++)
			tmp = tmp->suivant;
	
	return tmp->valeur;
}


/*====================				Autres						====================*/

template <class T>
bool ListeBase<T>::estVide() const {
	if(pTete == NULL)
		return true;
	else
		return false;
}

template <class T>
void ListeBase<T>::Affiche() const {
	Cellule<T>* tmp = NULL;

	if(pTete == NULL) {
		cout << endl << "Liste :" << endl << "  vide" << endl;
	} else {
		cout << endl << "Liste :" << endl << "  " << pTete->valeur << endl;
		tmp = pTete->suivant;
		
		while(tmp != NULL) {
			cout << "  " << tmp->valeur << endl;
			
			tmp = tmp->suivant;
		}
		cout << endl;
	}
}


/*====================				Opérateurs					====================*/

template <class T>
ListeBase<T>& ListeBase<T>::operator=(const ListeBase<T>& copy) {
	Cellule<T> *tmp, *tmpOld, *prec;
	
	tmpOld = copy.pTete;
	
	pTete = new Cellule<T>;
	pTete->valeur = copy.pTete->valeur;
	
	tmpOld->avant = NULL;
	tmpOld = tmpOld->suivant;
	
	tmp = pTete;
	prec = tmp;
	
	while(tmpOld != NULL) {
		tmp = new Cellule<T>;
		tmp->valeur = tmpOld->valeur;
		tmp->suivant = NULL;
		
		prec->suivant = tmp;
		prec = tmp;
		
		tmpOld->avant = tmp;
		tmpOld = tmpOld->suivant;
	}
	return *this;
}


/*====================				Templates					====================*/

template class ListeBase<int>;
template class ListeBase<float>;
#include "Data1D.h"
template class ListeBase<Data1D>;
#include "Data2D.h"
template class ListeBase<Data2D>;
