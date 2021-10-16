#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "outils.h"
#include "partie.h"
#include "joueur.h"
#include "jeu.h"
#define MAX 50

void AddPartie(Index *pIndex, Liste *pListe, short joueur, short jeu, short *nbrePartie)    //FONCTIONNE 100%
{
    short error = 0;
    long posJeu, posJoueur;
    char tab[MAX];
    PartieJouee partie;
    FILE *fp;

    fp = fopen("partiesjouees.dat", "r+b");
    if(fp != NULL) //Si existe
    {
//Sélection jeu
        do{
            ListGame(pListe, jeu);

            printf("Entrez l'id du jeu utilise\n");
            printf("Entrez '0' pour revenir en arriere\n");
            scanf("%ld", &posJeu);
        }while(posJeu < 0 || jeu < posJeu);

        if(posJeu != 0)
        {
            posJeu--;
            partie.IdJeu = (pListe+posJeu)->IdJeu;
//Date
            do{
                system("cls");

                printf("Jeu selectionne :\t%s\n", (pListe+posJeu)->Nom);
                printf("\n");

                printf("Date de la partie (jj/mm/aaaa) : ");
                LireChaine(&tab[0], DATE);
                error = LireDate(&tab[0], &partie.DatePartie.jour, &partie.DatePartie.mois, &partie.DatePartie.annee);
            }while(error != 0);

            do{
                system("cls");

                printf("Jeu selectionne :\t%s\n", (pListe+posJeu)->Nom);
                printf("Date de la partie :\t%hd/%hd/%hd\n", partie.DatePartie.jour, partie.DatePartie.mois, partie.DatePartie.annee);
                printf("\n");

                printf("Heure de la partie (hh:mm) : ");
                LireChaine(&tab[0], HEURE);
                error = LireHeure(&tab[0], &partie.HeurePartie.heure, &partie.HeurePartie.minute, &partie.HeurePartie.seconde);
            }while(error != 0);
//Joueur(s) participant(s)
            posJoueur = -1;
            do{
                ListPlayer(pIndex, joueur);

                printf("Jeu selectionne :\t%s\n", (pListe+posJeu)->Nom);
                printf("Date de la partie :\t%hd/%hd/%hd\n", partie.DatePartie.jour, partie.DatePartie.mois, partie.DatePartie.annee);
                printf("Heure de la partie :\t%hd:%hd\n", partie.HeurePartie.heure, partie.HeurePartie.minute);
                printf("\n");

                if(posJoueur == -1)
                {
                    printf("Entrez l'id du/d'un des joueur(s) ayant participe\n");
                    printf("Entrez '0' pour annuler l'enregistrement\n");
                    scanf("%ld", &posJoueur);
                    if(posJoueur == 0)
                        posJoueur = -1;
                }
                else
                {
                    printf("Entrez l'id d'un autre joueur ayant participe\n");
                    printf("Entrez '0' pour terminer la selection\n");
                    scanf("%ld", &posJoueur);
                }
//Points gagnés
                if(0 < posJoueur && posJoueur <= joueur)
                {
                    partie.IdJoueur = (pIndex+posJoueur-1)->IdJoueur;

                    error = VerifCloneDate(&partie, *nbrePartie);

                    if(error == 0)
                    {
                        do{
                            printf("Combien de points a-t-il eu ?\t");
                            scanf("%hd", &partie.Points);

                            if(partie.Points < 0)
                                printf("Le score ne peut pas etre inferieur a 0\n");
                        }while(partie.Points < 0);

                        fseek(fp, (*nbrePartie)*sizeof(PartieJouee), SEEK_SET);
                        fwrite(&partie, sizeof(PartieJouee), 1, fp);
                        *nbrePartie += 1;
                    }
                }
            }while(posJoueur < -1 || 0 < posJoueur);
        }
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");
}

void ListPartie(short nbreJoueur, short nbreJeu, short nbrePartie)  //FONCTIONNE 100%
{
    short i;
    PartieJouee partie[nbrePartie];
    Joueur player[nbreJoueur];
    Jeu game[nbreJeu];
    FILE *fp;

    system("cls");

    fp = fopen("partiesjouees.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_SET);
        for(i = 0; i < nbrePartie; i++)
        {
            fread(&partie[i], sizeof(PartieJouee), 1, fp);
        }
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");

    fp = fopen("jeux.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_SET);
        for(i = 0; i < nbreJeu; i++)
        {
            fread(&game[i], sizeof(Jeu), 1, fp);
        }
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");

    fp = fopen("joueurs.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_SET);
        for(i = 0; i < nbreJoueur; i++)
        {
            fread(&player[i], sizeof(Joueur), 1, fp);
        }
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");

    printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
    printf("|   \t    \t    \t    \t  \t  \t|\n");
    for(i = 0; i < nbrePartie; i++)
    {
        printf("\t    %hd. %s\n", i+1, (game+(partie[i].IdJeu-1))->Nom);
        printf("|   \t    %hd/%hd/%hd\t", (partie+i)->DatePartie.jour, (partie+i)->DatePartie.mois, (partie+i)->DatePartie.annee);
        printf("%hd:%hd\t  \t  \t|\n", (partie+i)->HeurePartie.heure, (partie+i)->HeurePartie.minute);
        printf("\t    %s %s  \t| Score : %hd\n", (player+(partie[i].IdJoueur-1))->Nom, (player+(partie[i].IdJoueur-1))->Prenom, partie[i].Points);
        printf("|   \t    \t    \t    \t  \t  \t|\n");
    }
    printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");

    fflush(stdin);
    printf("Appuyez sur 'enter' pour revenir en arriere\n");
    getchar();
}

short VerifCloneDate(PartieJouee *partie, short nbrePartie)
{
    short i, error = 0, errorTmp = 0;
    PartieJouee partieTmp;
    FILE *fp;

    fp = fopen("partiesjouees.dat", "rb");
    if(fp != NULL) //Si existe
    {
        fseek(fp, 0, SEEK_SET);
        for(i = 0; i < nbrePartie; errorTmp = 0, i++)
        {
            fread(&partieTmp, sizeof(PartieJouee), 1, fp);

            if(partieTmp.IdJoueur == partie->IdJoueur)
            {
                errorTmp++;
            }
            if(partieTmp.DatePartie.jour == partie->DatePartie.jour && partieTmp.DatePartie.mois == partie->DatePartie.mois && partieTmp.DatePartie.annee == partie->DatePartie.annee)
                errorTmp++;
            if(partieTmp.HeurePartie.heure == partie->HeurePartie.heure && partieTmp.HeurePartie.minute == partie->HeurePartie.minute)
                errorTmp++;

            if(errorTmp == 3)
            {
                error = 1;
                i = nbrePartie;
                printf("Une partie avec ce joueur s'est deja deroulee a ce moment la\n");

                fflush(stdin);
                printf("Appuyez sur 'enter' pour recommencer\n");
                getchar();
            }
        }
        fclose(fp);
    }
    else
        printf("Ouverture de fichier impossible\n");

    return error;
}
