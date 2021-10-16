#ifndef _JEU_H_
#define _JEU_H_

#include "outils.h"

#define NBRE_JEU 50
#define NOM 25
#define DATE 11

typedef struct jeu{
    long IdJeu;
    char Nom[NOM];
    short Interieur;
    short Exterieur;
    short AgeMin;
    short AgeMax;
    short NbJoueurMin;
    short NbJoueurMax;
    Date DateAchat;
    short DureeGarantie;
}Jeu;

typedef struct liste{
    long IdJeu;
    char Nom[NOM];
    char Prenom[NOM];
    short Tri;
}Liste;

void AddGame(Liste *, short *, short *);
void RemoveGame(Liste *, short *, short *);
void ListGame(Liste *, short);
void TriGames(Liste *, short *);

#endif // _JEU_H_
