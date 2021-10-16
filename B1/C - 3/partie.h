#ifndef _PARTIE_H_
#define _PARTIE_H_

#include "joueur.h"
#include "jeu.h"
#include "outils.h"

typedef struct Jouer_Partie{
    long IdJoueur;
    long IdJeu;
    Date DatePartie;
    Heure HeurePartie;
    short Points;
}PartieJouee;

void AddPartie(Index *, Liste *, short, short, short *);
void ListPartie(short, short, short);
short VerifCloneDate(PartieJouee *, short);

#endif // _PARTIE_H_

