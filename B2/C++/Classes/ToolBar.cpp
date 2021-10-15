#include "ToolBar.h"


/*====================		Constructeur par Défaut				====================*/

ToolBar::ToolBar() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut ToolBar");
#endif
	compteurBc = 0;
//	setBoutonUndo(0);
//	setBoutonMenu(0);
}


/*====================		Constructeur d'Initialisation		====================*/

//...


/*====================			Constructeur de Copie			====================*/

ToolBar::ToolBar(const ToolBar& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie ToolBar");
#endif
	compteurBc = old.compteurBc;
//	boutonUndo(old.boutonUndo);
//	boutonMenu(old.boutonMenu);
}


/*====================				Destructeur					====================*/

ToolBar::~ToolBar() {
#ifdef DEV
	TraceConstructeur("Destructeur ToolBar");
#endif
}


/*====================				Setters						====================*/

//...


/*====================				Getters						====================*/

Couleur* ToolBar::getNomCouleur(const char* c) {
	Iterateur<BoutonCouleur> it(boutonsCouleur);
//	BoutonCouleur b;
	
	for(it.reset(); !it.end(); it++) {
//		b = (BoutonCouleur)it;
		
		if(strcmp((&it)->getNom(), c) == 0)
			return (&it)->getCouleur();
    }
	return NULL;
}

Couleur* ToolBar::getCouleurSelectionnee() {
	Iterateur<BoutonCouleur> it(boutonsCouleur);
//	BoutonCouleur b;
	
	for(it.reset(); !it.end(); it++) {
//		b = (BoutonCouleur)it;
		
		if((&it)->getSelected() == true)
			return (&it)->getCouleur();
    }
	return NULL;
}

const char* ToolBar::getFigureSelectionnee() {
	Iterateur<Bouton> it(boutonsFigure);
//	Bouton b;
	
	for(it.reset(); !it.end(); it++)
		if((&it)->getSelected() == true)
			return (&it)->getNom();
    
	return NULL;
}


/*====================				Autres						====================*/

void ToolBar::ajouteCouleur(Couleur* c) {
	Iterateur<BoutonCouleur> it(boutonsCouleur);
//	BoutonCouleur b;
	
	for(it.reset(); !it.end(); it++) {
		if((&it)->getCouleur() == NULL) {
    		(&it)->setCouleur(c);
    		compteurBc++;
    		break;
		}
    }
}

const char* ToolBar::clic(int x, int y) {
	Iterateur<Bouton> it(boutonsFigure);
	Bouton b;
	Iterateur<BoutonCouleur> itc(boutonsCouleur);
	BoutonCouleur bc;
	
	Bouton b2;
	BoutonCouleur bc2;
	int nbr = 0;
	bool found = false;
	
	if(y <= 39) {
		if(x <= 159) {
			for(it.reset(); !it.end(); it++) {
				b = (Bouton)it;
				(&it)->setSelected(false);
		
				if(b.clic(x, y) == true) {
					b2 = b;
					(&it)->setSelected(true);
					found = true;
				}
			}
		}
		
		if(found == true)
			return b2.getNom();
		
		if(160 <= x && x <= 319) {
			boutonUndo.setSelected(false);
			if(boutonUndo.clic(x, y) == true)
				return boutonUndo.getNom();
			else {
				boutonMenu.setSelected(false);
				if(boutonMenu.clic(x, y) == true)
					return boutonMenu.getNom();
			}
		}
		if(320 <= x) {
			for(itc.reset(); !itc.end() && nbr < compteurBc; itc++) {
				bc = (BoutonCouleur)itc;
				(&itc)->setSelected(false);
				nbr++;

				if(bc.clic(x, y) == true) {
					bc2 = bc;
					(&itc)->setSelected(true);
					found = true;
				}
			}
			if(found == true)
				return bc2.getNom();
		}
	}
	return NULL;
}


/*====================				Opérateurs						====================*/

//...
