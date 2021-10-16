/************************************************/
/* Auteur : FRANCOIS Hugo                       */
/* Groupe : 2104                                */
/* Application : Laboratoire de bases de données*/
/*          Gestion de jeux                     */
/*                                              */
/* Date de la dernière m-à-j : 07/05/2019       */
/************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "joueur.h"
#include "jeu.h"
#include "partie.h"

#define NBRE_JOUEUR 30
#define NBRE_JEU 50

void InitFiles();
void InitIndex(Index *, Liste *, short *, short *, short *, short *);

void MenuJoueur(Index *, short *);
void MenuJeu(Liste *, short *, short *);
void MenuPartie(Index *, Liste *, short, short, short *);

int main()
{
    short joueur = 0, jeu = 0, jeuBase = 0, partie = 0, choix = 0;
    Index index[NBRE_JOUEUR];
    Liste liste[NBRE_JEU];

    if(choix == 0)
    {
        InitFiles();
        InitIndex(index, liste, &joueur, &jeu, &jeuBase, &partie);
    }

    do{
        system("cls");

        printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  1. Menu joueur\t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  2. Menu jeu   \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  3. Parties jouees \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  0. Quitter    \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");

        do{
            scanf("%hd", &choix);
            printf("Nombre incorrect, veuillez recommencer\n");
        }while(choix < 0 || 3 < choix);

        switch(choix)
        {
            case 1:
                MenuJoueur(&index[0], &joueur);
				break;
			case 2:
			    MenuJeu(&liste[0], &jeu, &jeuBase);
				break;
            case 3:
                MenuPartie(&index[0], &liste[0], joueur, jeu, &partie);
                break;
            case 0:
                system("cls");
                exit(0);
                break;
            default:
                printf("Mauvais choix, veuillez re-choisir\n");
        }
    }while(choix != 0);

    return 0;
}

/************************************************/
/*  input: /                                    */
/*                                              */
/*  process: Afficher le menu des joueurs       */
/*                                              */
/*  output: /                                   */
/************************************************/
void MenuJoueur(Index *pIndex, short *joueur)
{
    short choix;

    do{
        system("cls");

        printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  1. Ajouter un joueur (%hd places)   \t|\n", NBRE_JOUEUR-*joueur);
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  2. Modifier un joueur \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  3. Retirer un joueur  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  4. Lister les joueurs \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  0. Retour     \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");

        do{
            fflush(stdin);
            scanf("%hd", &choix);
            printf("Nombre incorrect, veuillez recommencer\n");
        }while(choix < 0 || 4 < choix);

        switch(choix)
        {
            case 1:
                AddPlayer(pIndex, joueur);
				break;
			case 2:
			    EditPlayer(pIndex, *joueur);
				break;
			case 3:
			    RemovePlayer(pIndex, joueur);
				break;
			case 4:
			    ListPlayer(pIndex, *joueur);
			    fflush(stdin);
                printf("Appuyez sur 'enter' pour revenir en arriere\n");
                getchar();
				break;
            case 0:
                break;
			default:
                printf("Mauvais choix, veuillez re-choisir\n");
        }
    }while(choix != 0);
}

/************************************************/
/*  input: /                                    */
/*                                              */
/*  process: Afficher le menu des jeux          */
/*                                              */
/*  output: /                                   */
/************************************************/
void MenuJeu(Liste *pListe, short *jeu, short *jeuBase)
{
    short choix, i;

    do{
        system("cls");

        printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  1. Ajouter un jeu (%hd places)   \t|\n", NBRE_JEU-*jeuBase);
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  2. Retirer un jeu \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  3. Lister les jeux\t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  0. Retour     \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");

        do{
            scanf("%hd", &choix);
            printf("Nombre incorrect, veuillez recommencer\n");
        }while(choix < 0 || 3 < choix);

        switch(choix)
        {
            case 1:
                AddGame(pListe, jeu, jeuBase);
				break;
			case 2:
			    RemoveGame(pListe, jeu, jeuBase);
				break;
			case 3:
                do{
    			    ListGame(pListe, *jeu);
                    printf("Entrez 1. pour voir tous les jeux\n");
                    printf("Entrez 2. pour voir les jeux dont la garantie est active\n");
                    printf("Appuyez sur '0' pour revenir en arriere\n");
                    scanf("%hd", &i);

                    if(i == 1)
                        pListe->Tri = 0;
                    else
                    {
                        if(i == 2)
                            pListe->Tri = 1;
                    }

                    TriGames(pListe, jeu);
                }while(i != 0);
				break;
            case 0:
                break;
			default:
                printf("Mauvais choix, veuillez re-choisir\n");
        }
    }while(choix != 0);
}

/************************************************/
/*  input: /                                    */
/*                                              */
/*  process: Afficher le menu des parties       */
/*                                              */
/*  output: /                                   */
/************************************************/
void MenuPartie(Index *pIndex, Liste *pListe, short joueur, short jeu, short *partie)
{
    short choix;

    do{
        system("cls");

        printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  1. Nouvelle partie\t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  2. Liste des parties  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("|   \t  0. Retour     \t  \t  \t|\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");

        do{
            scanf("%hd", &choix);
            printf("Nombre incorrect, veuillez recommencer\n");
        }while(choix < 0 || 2 < choix);

        switch(choix)
        {
            case 1:
                AddPartie(pIndex, pListe, joueur, jeu, partie);
				break;
			case 2:
			    ListPartie(joueur, jeu, *partie);
				break;
            case 0:
                break;
			default:
                printf("Mauvais choix, veuillez re-choisir\n");
        }
    }while(choix != 0);
}

/************************************************/
/*  input: /                                    */
/*                                              */
/*  process: Initialiser les fichiers           */
/*                                              */
/*  output: /                                   */
/************************************************/
void InitFiles()
{
    short i, nbre;
    Joueur player;
    Jeu game;
    PartieJouee partie;
    FILE *fp;

    player.IdJoueur = 0;

    fp = fopen("joueurs.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek (fp, 0, SEEK_END);
        nbre = ftell(fp) / sizeof(Joueur);

        fseek(fp, 0, SEEK_SET);
        if(nbre == 0)
        {
            for(i = 0; i < NBRE_JOUEUR; i++)
            {
                player.IdJoueur -= 1;
                fwrite(&player, sizeof(Joueur), 1, fp);
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Ouverture de fichier impossible\n");
        fp = fopen("joueurs.dat", "wb");

        for(i = 0; i < NBRE_JOUEUR; i++)
        {
            player.IdJoueur -= 1;
            fwrite(&player, sizeof(Joueur), 1, fp);
        }
        fclose(fp);
    }
    game.IdJeu = 0;

    fp = fopen("jeux.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek (fp, 0, SEEK_END);
        nbre = ftell(fp) / sizeof(Jeu);

        fseek(fp, 0, SEEK_SET);
        if(nbre == 0)
        {
            for(i = 0; i < NBRE_JEU; i++)
            {
                game.IdJeu -= 1;
                fwrite(&game, sizeof(Jeu), 1, fp);
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Ouverture de fichier impossible\n");
        fp = fopen("jeux.dat", "wb");

        for(i = 0; i < NBRE_JEU; i++)
        {
            game.IdJeu -= 1;
            fwrite(&game, sizeof(Jeu), 1, fp);
        }
        fclose(fp);
    }
    partie.IdJoueur = 0;

    fp = fopen("partiesjouees.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek (fp, 0, SEEK_END);
        nbre = ftell(fp) / sizeof(PartieJouee);

        fseek(fp, 0, SEEK_SET);
        if(nbre == 0)
        {
            for(i = 0; i < NBRE_JOUEUR; i++)
                fwrite(&partie, sizeof(PartieJouee), 1, fp);
        }
        fclose(fp);
    }
    else
    {
        printf("Ouverture de fichier impossible\n");
        fp = fopen("partiesjouees.dat", "wb");

        for(i = 0; i < NBRE_JOUEUR; i++)
            fwrite(&partie, sizeof(PartieJouee), 1, fp);
        fclose(fp);
    }
}

/************************************************/
/*  input: Un pointeur de structure de joueurs  */
/*      Un pointeur de structure de jeux        */
/*      2 short pour stocker une valeur entière */
/*                                              */
/*  process: Initialiser l'index des fichiers   */
/*                                              */
/*  output: /                                   */
/************************************************/
void InitIndex(Index *pIndex, Liste *pListe, short *joueur, short *jeu, short *jeuBase, short *partie)
{
    long i;
    Joueur player;
    Jeu game;
    FILE *fp;

    fp = fopen("joueurs.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_SET);
        for(i = 0; i < NBRE_JOUEUR; i++, pIndex++)
        {
            fread(&player, sizeof(Joueur), 1, fp);
            pIndex->IdJoueur = player.IdJoueur;
            strcpy(pIndex->Nom, player.Nom);
            strcpy(pIndex->Prenom, player.Prenom);
            if(player.IdJoueur > 0)
                *joueur += 1;
        }
        pIndex -= i;
        TriPlayers(pIndex, *joueur);
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");

    fp = fopen("jeux.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_SET);
        for(i = 0; i < NBRE_JEU; i++, pListe++)
        {
            fread(&game, sizeof(Jeu), 1, fp);
            pListe->IdJeu = game.IdJeu;
            strcpy(pListe->Nom, game.Nom);
            pListe->Tri = 0;
            if(game.IdJeu > 0)
                *jeuBase += 1;
        }
        pListe -= i;
        TriGames(pListe, jeu);
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");

    fp = fopen("partiesjouees.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_END);
        i = ftell(fp);
        *partie = (short)(i/sizeof(PartieJouee));
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");
}
