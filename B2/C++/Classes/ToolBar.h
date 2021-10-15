#ifndef ToolBar_H
#define ToolBar_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "BoutonCouleur.h"
#include "Liste.h"
#include "Iterateur.h"

class ToolBar {
	private:
		Liste<Bouton> boutonsFigure;
		Liste<BoutonCouleur> boutonsCouleur;
		Bouton boutonUndo;
		Bouton boutonMenu;
		int compteurBc;
		
	public:
	//Constructeur par défaut
		ToolBar();
	//Constructeur d'initialisation
		
	//Constructeur de copie
		ToolBar(const ToolBar&);
	//Destructeur
		~ToolBar();
		
	//Setters
		void setBoutonUndo(const Bouton& b) { boutonUndo = b; };
		void setBoutonMenu(const Bouton& b) { boutonMenu = b; };
		
	//Getters
		Couleur* getNomCouleur(const char*);
		Couleur* getCouleurSelectionnee();
		const char* getFigureSelectionnee();
		
	//Autres
		void afficheFigures() { boutonsFigure.Affiche(); };
		void afficheCouleur() { boutonsCouleur.Affiche(); };
		
		void ajouteBoutonFigure(const Bouton& b) { boutonsFigure.insere(b); };
		void ajouteBoutonCouleur(const BoutonCouleur& b) { boutonsCouleur.insere(b); };

		void ajouteCouleur(Couleur*);
		
		const char* clic(int, int);
		
	//Opérateurs
};
#endif
