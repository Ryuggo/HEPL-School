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
}


/*====================				Destructeur					====================*/

template <class T>
ListeBase<T>::~ListeBase() {
#ifdef DEV
	TraceConstructeur("Destructeur ListeBase");
#endif
	if(pTete != NULL)
		delete pTete;
}


/*====================				Setters						====================*/

// ...


/*====================				Getters						====================*/

template <class T>
int ListeBase<T>::getNombreElements() const {
	Cellule<T>* tmp = NULL;
	int i = 0;

	if(pTete == NULL)
		return 0;
	else {
		tmp = pTete;
		
		while(tmp != NULL) {
			i++;
			
			tmp = tmp->suivant;
		}
		return i;
	}
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

	if(pTete == NULL)
		cout << endl << "Liste :" << endl << "  vide" << endl;
	else {
		cout << endl << "Liste :" << endl << "  " << pTete->valeur;
		tmp = pTete->suivant;
		
		while(tmp != NULL) {
			cout << "  " << tmp->valeur;
			
			tmp = tmp->suivant;
		}
		cout << endl;
	}
}


/*====================				Opérateurs					====================*/

//template <class T>
//ListeBase<T>& ListeBase<T>::operator=(const ListeBase<T>& copy) {
////	for(int x = 0; x < getLargeur(); x++)
////		delete[] tab[x];
////	delete[] tab;
////	
////	setLargeur(newTab.getLargeur());
////	setHauteur(newTab.getHauteur());
////	
////	tab = new T*[largeur];
////	for(int x = 0; x < largeur; x++)
////		tab[x] = new T[hauteur];
////	
////	for(int x = 0; x < largeur; x++)
////		for(int y = 0; y < hauteur; y++)	
////			setValeur(x, y, newTab.getValeur(x, y));
//	
//	return *this;
//}


/*====================				Templates					====================*/

template class ListeBase<int>;
#include "Couleur.h"
template class ListeBase<Couleur>;
#include "Figure.h"
template class ListeBase<Figure*>;
#include "BoutonCouleur.h"
template class ListeBase<Bouton>;
template class ListeBase<BoutonCouleur>;
