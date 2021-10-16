#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "outils.h"

#define NBRE_JOUEUR 30
#define NOM 25
#define ADRESSE 50
#define POSTAL 5
#define VILLE 25
#define PAYS 25
#define GSM 13
#define MAIL 65

typedef struct joueur{
    long IdJoueur;
    char Nom[NOM];
    char Prenom[NOM];
    Date DateNaissance;
    char Adresse[ADRESSE];
    char CodePostal[POSTAL];
    char Ville[VILLE];
    char Pays[PAYS];
    char Telephone[GSM];
    char AdMail[MAIL];
}Joueur;

typedef struct index{
    long IdJoueur;
    char Nom[NOM];
    char Prenom[NOM];
}Index;

void AddPlayer(Index *, short *);
void EditPlayer(Index *, short);
void RemovePlayer(Index *, short *);
void ListPlayer(Index *, short);
void TriPlayers(Index *, short);
void PlayerDetails(Joueur);

#endif // _JOUEUR_H_
