#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "outils.h"
#include "jeu.h"
#define MAX 50

/************************************************/
/*  input: La structure Liste pour les jeux     */
/*		Le nombre de jeux encodés				*/
/*                                              */
/*  process: Ajoute un jeu à la liste           */
/*                                              */
/*  output: /                                   */
/************************************************/
void AddGame(Liste *pListe, short *jeu, short *jeuBase)                 //FONCTIONNE 100%
{
    short error;
    char tab[MAX];
    Jeu game;
    FILE *fp;

    system("cls");

    if(*jeu < NBRE_JEU)
    {
        fp = fopen("jeux.dat", "r+b");
        if(fp != NULL) //Si existe
        {
            printf("Ajout d'un jeu\n");

            do{
                printf("\nNom : \t\t\t\t");
                error = LireNomPropre(game.Nom, NOM);
            }while(error != 0);

            do{
                printf("\nInterieur\n");
                printf("0. Non\t 1. Oui \t\t");
                fflush(stdin);
                scanf("%hd", &game.Interieur);
            }while(game.Interieur < 0 || 1 < game.Interieur);

            do{
                printf("\nExterieur\n");
                printf("0. Non\t 1. Oui \t\t");
                fflush(stdin);
                scanf("%hd", &game.Exterieur);
            }while(game.Exterieur < 0 || 2 < game.Exterieur);

            do{
                printf("\nAge minimum : \t\t\t");
                fflush(stdin);
                scanf("%hd", &game.AgeMin);
                if(game.AgeMin <= 0 || 100 < game.AgeMin)
                    printf("L'age est trop grand ou trop petit\n");
            }while(game.AgeMin <= 0 || 100 < game.AgeMin);

            do{
                printf("\nAge maximum : \t\t\t");
                fflush(stdin);
                scanf("%hd", &game.AgeMax);
                if(game.AgeMax < 0 || 100 < game.AgeMax)
                    printf("L'age est trop grand ou trop petit\n");
                if(game.AgeMin > game.AgeMax)
                    printf("L'age maximum depasse l'age minimum\n");
            }while((game.AgeMax < 0 || 100 < game.AgeMax) || game.AgeMin > game.AgeMax);

            do{
                printf("\nNombre minimum de joueurs : \t");
                fflush(stdin);
                scanf("%hd", &game.NbJoueurMin);
                if(game.NbJoueurMin < 0 || 100 < game.NbJoueurMin)
                    printf("Le nombre de joueurs est trop grand ou trop petit\n");
            }while(game.NbJoueurMin < 0 || 100 < game.NbJoueurMin);

            do{
                printf("\nNombre maximum de joueurs : \t");
                fflush(stdin);
                scanf("%hd", &game.NbJoueurMax);
                if(game.NbJoueurMax < 0 || 100 < game.NbJoueurMax)
                    printf("Le nombre de joueurs est trop grand ou trop petit\n");
                if(game.NbJoueurMin > game.NbJoueurMax)
                    printf("Le nombre de joueurs maximum depasse le nombre de joueurs minimum\n");
            }while((game.NbJoueurMax < 0 || 100 < game.NbJoueurMax) || game.NbJoueurMin > game.NbJoueurMax);

            do{
                printf("\nDate d'achat xx/xx/xxxx : \t");
                LireChaine(&tab[0], DATE);
                error = LireDate(&tab[0], &game.DateAchat.jour, &game.DateAchat.mois, &game.DateAchat.annee);
            }while(error != 0);

            do{
                printf("\nDuree de la garantie : \t\t");
                fflush(stdin);
                scanf("%hd", &game.DureeGarantie);
                if(game.DureeGarantie < 0 || 10 < game.DureeGarantie)
                    printf("La duree de garantie est trop grande ou trop petite\n");
            }while(game.DureeGarantie < 0 || 10 < game.DureeGarantie);

            (pListe+(*jeu))->IdJeu *= -1;
            game.IdJeu = (pListe+(*jeu))->IdJeu;
            strcpy((pListe+(*jeu))->Nom, game.Nom);

            fseek(fp, ((pListe+(*jeu))->IdJeu-1)*sizeof(Jeu), SEEK_SET);
            fwrite(&game, sizeof(Jeu), 1, fp);
            fclose(fp);

            *jeu += 1;
            *jeuBase += 1;
            TriGames(pListe, jeu);
        }
        else
            printf("Ouverture de fichier impossible\n");
    }
    else
    {
        printf("La limite de jeux est atteinte\n");
        fflush(stdin);
        printf("Appuyez sur 'enter' pour revenir en arriere\n");
        getchar();
    }
}

/************************************************/
/*  input: La structure Liste pour les jeux     */
/*		Le nombre de jeux encodés				*/
/*                                              */
/*  process: Supprime un jeu de la liste        */
/*                                              */
/*  output: /                                   */
/************************************************/
void RemoveGame(Liste *pListe, short *jeu, short *jeuBase)              //FONCTIONNE 100%
{
    short i, j, nbre;
    char tab[NOM];
    FILE *fp;

    do{
        do{
            ListGame(pListe, *jeu);
            printf("Entrez 1. pour voir tous les jeux\n");
            printf("Entrez 2. pour voir les jeux dont la garantie est active\n");
            printf("Entrez '0' pour sauvegarder et revenir en arriere\n");
            printf("\n");
            printf("Entrez le nom du jeu a supprimer\n");
            LireChaine(&tab[0], NOM);

            if(tab[0] == '1')
            {
                pListe->Tri = 0;
                TriGames(pListe, jeu);
            }
            else
            {
                if(tab[0] == '2')
                {
                    pListe->Tri = 1;
                    TriGames(pListe, jeu);
                }
            }

            if(tab[0] != '0' && tab[0] != '1' && tab[0] != '2') //Si nom entré, vérifie si existe
            {
                for(i = 0, j = 1; i < *jeu && j != 0; i++)
                {
                    j = strcmp(tab ,(pListe+i)->Nom);
                }

                if(i == *jeu && j != 0)
                {
                    printf("Le nom du jeu n'est pas correct\n");
                    fflush(stdin);
                    printf("Appuyez sur 'enter' pour recommencer\n");
                    getchar();
                }
            }
        }while(tab[0] != '0' && j != 0);

        if(tab[0] != '0')
        {
            fp = fopen("jeux.dat", "r+b");
            if(fp != NULL) //Si existe
            {
                i--;
                nbre = ((pListe+i)->IdJeu) - 1;
                (pListe+i)->IdJeu *= -1;

                fseek(fp, nbre*sizeof(Jeu), SEEK_SET);
                fwrite(&(pListe+i)->IdJeu, sizeof(long), 1, fp);
                fclose(fp);

                *jeu -= 1;
                *jeuBase -= 1;
                TriGames(pListe, jeu);
            }
            else
                printf("Ouverture de fichier impossible\n");
        }
    }while(tab[0] != '0' && *jeu > 0);
}

/************************************************/
/*  input: La structure Liste pour les jeux     */
/*		Le nombre de jeux encodés				*/
/*                                              */
/*  process: Affiche la Liste de jeux           */
/*                                              */
/*  output: /                                   */
/************************************************/
void ListGame(Liste *pListe, short jeu)                                //FONCTIONNE 100%
{
    short i;

    system("cls");

    printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
    printf("|   \t    \t    \t    \t  \t  \t|\n");

    if(pListe->Tri == 1 || pListe->Tri == -1)
    {
        printf("\t  Jeux avec une garantie active\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
    }
    else
    {
        printf("\t  \t  Tous les jeux\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
    }

    if(jeu > 0)
    {
        for(i = 0; i < jeu; i++)
        {
            printf("    \t    %hd. %s (%hd)\n", i+1, (pListe+i)->Nom, (pListe+i)->IdJeu);
            printf("|   \t    \t    \t    \t  \t  \t|\n");
        }
    }
    else
    {
        printf("\tAucun jeu a afficher pour le moment\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
    }

    printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");
}

/************************************************/
/*  input: La structure Liste pour les jeux     */
/*		Le nombre de jeux encodés				*/
/*                                              */
/*  process: Trie les jeux de la liste          */
/*                                              */
/*  output: /                                   */
/************************************************/
void TriGames(Liste *pListe, short *jeu)                                //FONCTIONNE 100%
{
    short i, j, k, jeuBase;
    long nbre;
    char tmp[MAX];
    Jeu game;
    FILE *fp;

    *jeu = 0;
    for(i = 0; i < NBRE_JEU; i++)
    {
        if((pListe+i)->IdJeu > 0)
            *jeu += 1;
    }
//Tri de base (mettre les jeux effacés à la fin)
    for(i = 0; i < NBRE_JEU; i++)
    {
        for(j = 0, k = 1; j < NBRE_JEU-(i+1); j++, k++)
        {
            if((pListe+j)->IdJeu < (pListe+k)->IdJeu)
            {
                nbre = (pListe+j)->IdJeu;
                (pListe+j)->IdJeu = (pListe+k)->IdJeu;
                (pListe+k)->IdJeu = nbre;
                strcpy(tmp, (pListe+j)->Nom);
                strcpy((pListe+j)->Nom, (pListe+k)->Nom);
                strcpy((pListe+k)->Nom, tmp);
            }
        }
    }
//Si tri sans garantie, réinitialisation
    if(pListe->Tri == 0)
    {
        for(j = 0; j < *jeu; j++)
            (pListe+j)->Tri = 0;
    }
//Tri avec la garantie
    if(pListe->Tri == 1)
    {
        jeuBase = *jeu;
        *jeu = 0;

        fp = fopen("jeux.dat", "rb");
        if(fp != NULL) //Si existe
        {
            for(j = 0; j < jeuBase; j++)
            {
                k = (pListe+j)->IdJeu;
                k--;

                fseek(fp, (short)k*sizeof(Jeu), SEEK_SET);
                fread(&game, sizeof(Jeu), 1, fp);
//Si la garantie est toujours valide / Date de la garantie > Date actuelle
                if(VerifDate(game.DateAchat.jour, game.DateAchat.mois, (game.DateAchat.annee + game.DureeGarantie)) != 0)
                {
                    (pListe+j)->Tri = 1;
                    *jeu += 1;
                }
                else
                {
                    (pListe+j)->Tri *= -1;
                }
            }
            for(i = 0; i < *jeu; i++)
            {
                for(j = 0, k = 1; j < *jeu-(i+1); j++, k++)
                {
                    if((pListe+j)->Tri < (pListe+k)->Tri)
                    {
                        nbre = (pListe+j)->IdJeu;
                        (pListe+j)->IdJeu = (pListe+k)->IdJeu;
                        (pListe+k)->IdJeu = nbre;
                        strcpy(tmp, (pListe+j)->Nom);
                        strcpy((pListe+j)->Nom, (pListe+k)->Nom);
                        strcpy((pListe+k)->Nom, tmp);
                        nbre = (pListe+j)->Tri;
                        (pListe+j)->Tri = (pListe+k)->Tri;
                        (pListe+k)->Tri = nbre;
                    }
                }
            }
            fclose(fp);
        }
        else
            printf("Ouverture de fichier impossible\n");
    }
//Tri par nom
    for(i = 0; i < *jeu; i++)
    {
        for(j = 0, k = 1; j < *jeu-(i+1); j++, k++)
        {
            if((pListe+j)->IdJeu > 0)
            if((pListe+j)->IdJeu > 0)
            {
                if(strcmp((pListe+j)->Nom, (pListe+k)->Nom) > 0)
                {
                    nbre = (pListe+j)->IdJeu;
                    (pListe+j)->IdJeu = (pListe+k)->IdJeu;
                    (pListe+k)->IdJeu = nbre;
                    strcpy(tmp, (pListe+j)->Nom);
                    strcpy((pListe+j)->Nom, (pListe+k)->Nom);
                    strcpy((pListe+k)->Nom, tmp);
                    nbre = (pListe+j)->Tri;
                    (pListe+j)->Tri = (pListe+k)->Tri;
                    (pListe+k)->Tri = nbre;
                }
            }
        }
    }
}
