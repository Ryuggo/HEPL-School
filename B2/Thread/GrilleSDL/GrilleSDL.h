// ***** Librairie GrilleSDL *****
// Librairie permettant d'ouvrir et gerer une fenetre graphique. La fenetre graphique est geree comme une grille
// ayant un certain nombre de lignes et de colonnes. Chaque case de cette grille peut contenir un carre de couleur
// ou un sprite provenant d'un fichier bmp. Cette librairie est basee sur SDL.

// Wagner Jean-Marc
// Janvier 2012

// Remarque : Merci à C. Pirotte pour ses suggestions et D. Mercenier pour son aide au debbugage :)
// *******************************

#ifndef GRILLE_SDL_H
#define GRILLE_SDL_H

#include <SDL/SDL.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>

typedef struct
{
  int  type;
  int  ligne;   // utilise en cas de type CLIC_GAUCHE ou CLIC_DROIT
  int  colonne; // utilise en cas de type CLIC_GAUCHE ou CLIC_DROIT
  char touche;  // utilise en cas de type CLAVIER
} EVENT_GRILLE_SDL;

// Types d'evenements (valeurs possibles de type)
#define CROIX       1
#define CLAVIER     2
#define CLIC_GAUCHE 3
#define CLIC_DROIT  4

// Pour les evenements de type CLAVIER, codes des touches speciales (valeurs possibles de touche)
#define KEY_SPACE   32
#define KEY_DOWN    50
#define KEY_UP      51
#define KEY_LEFT    52
#define KEY_RIGHT   53

int OuvrirGrilleSDL(int nbLignes,int nbColonnes,int tailleCarre,const char* titreFenetre,const char* iconeFenetre);
// nbLignes,nbColonnes = dimensions de la grille
// tailleCarre = dimension en pixels de chaque case de la grille
int FermerGrilleSDL();
int setTitreGrilleSDL(const char* titre);
int DessineCouleurFond(int R,int G,int B);          // RGB compris entre 0 et 255
int DessineImageFond(const char* nomFichier);
int DessineCarre(int L,int C,int R,int G,int B);    // RGB compris entre 0 et 255
int EffaceCarre(int L,int C);                       // Restitue l'image (ou la couleur) de fond
int AjouteSprite(int code,const char* nomFichier);  
// code represente la valeur entier utilisee pour identifier un sprite, et sera utilise dans la fonction
// DessineSprite
// La largeur et la hauteur du sprite doivent etre un multiple de tailleCarre
int AjouteSpriteAFondTransparent(int code,const char* nomFichier,int Rf,int Gf,int Bf);
// (Rf,Gf,Bf) represente la couleur qui sera affichee de maniere transparente, laissant apparaitre le fond
int DessineSprite(int L,int C,int code);
EVENT_GRILLE_SDL ReadEvent();
// Fonction bloquante permettant de lire un evenement clavier, clic souris ou croix de la fenetre

#endif
