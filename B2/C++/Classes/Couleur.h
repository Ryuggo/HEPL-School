#ifndef COULEUR_H
#define COULEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Ecran.h"
#include "InvalidColorException.h"

class Couleur {
	private:
		int rouge, vert, bleu;
		char* nom;
		static int compteur;
		int clair, fonce;
		
	public:
		static const Couleur ROUGE, VERT, BLEU;
		
	//Constructeur par défaut
		Couleur();
	//Constructeur d'initialisation
		Couleur(int, int, int, const char*);
		Couleur(int, int, int);
	//Constructeur de copie
		Couleur(const Couleur&);
	//Destructeur
		~Couleur();
		
	//Setters
		void setRouge(int r);
		void setVert(int g);
		void setBleu(int b);
		void setNom(const char*);
		
		void setClair(int c) { clair = c; };
		void setFonce(int f) { fonce = f; };
		
	//Getters
		int getRouge() const { return rouge; };
		int getVert() const { return vert; };
		int getBleu() const { return bleu; };
		const char* getNom() const { return nom; };
		
		static const int getCompteur() { return Couleur::compteur; };
		
		int getClair() const { return clair; };
		int getFonce() const { return fonce; };
		
	//Autres
		void Affiche() const;
		void CoulVerif255();
		void CoulVerif0();
		
		void Save(ofstream&) const;
		void Load(ifstream&);
		
	//Opérateurs
		Couleur& operator=(const Couleur&);
		
		Couleur operator+(const Couleur&);
		friend Couleur operator+(const Couleur& c2, Couleur c1) { return (c1 + c2); };

		Couleur operator+(int) const;
		friend Couleur operator+(int i, const Couleur& c1) { return (c1 + i); };
		
		Couleur operator-(int);
		
		Couleur operator[](const char*);
//		friend Couleur operator=(const Couleur& c1, int i) { return (c1[i]); };

		friend ostream& operator<<(ostream&, const Couleur&);
		friend istream& operator>>(istream&, Couleur&);
		
		Couleur& operator++();
		Couleur operator++(int);
		Couleur& operator--();
		Couleur operator--(int);
};
#endif
