#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "outils.h"
#include "joueur.h"
#define MAX 50

/************************************************/
/*  input: La structure Index pour les joueurs  */
/*      Le nombre de joueurs encodés            */
/*                                              */
/*  process: Ajoute un joueur à l'index         */
/*                                              */
/*  output: /                                   */
/************************************************/
void AddPlayer(Index *pIndex, short *joueur)            //FONCTIONNE 100%   //Ajouter une commande pour annuler l'ajout
{
    short stop, error = 0;
    char tab[MAX];
    Joueur player;
    FILE *fp;

    system("cls");

    if(*joueur < NBRE_JOUEUR)
    {
        fp = fopen("joueurs.dat", "r+b");
        if(fp != NULL) //Si existe
        {
            printf("Ajout d'un joueur\n");
            printf("(Entrez 0 pour annuler l'ajout PAS ENCORE FAIT)\n");                //TO DO

            do{
                printf("\nNom : \t\t\t\t");
                error = LireNomPropre(player.Nom, NOM);
            }while(error != 0);

            do{
                printf("\nPrenom : \t\t\t");
                error = LireNomPropre(player.Prenom, NOM);
            }while(error != 0);

            do{
                printf("\nDate de naissance jj/mm/aaaa : \t");
                LireChaine(&tab[0], DATE);
                error = LireDate(&tab[0], &player.DateNaissance.jour, &player.DateNaissance.mois, &player.DateNaissance.annee);
            }while(error != 0);

            printf("\nAdresse : \t\t\t");
            LireChaine(player.Adresse, ADRESSE);

            do{
                printf("\nCode postal : \t\t\t");
                error = LireShort(player.CodePostal, POSTAL);
            }while(error != 0);

            do{
                printf("\nVille : \t\t\t");
                error = LireNomPropre(player.Ville, VILLE);
            }while(error != 0);

            do{
                printf("\nPays : \t\t\t\t");
                error = LireNomPropre(player.Pays, PAYS);
            }while(error != 0);

            do{
                printf("\nTelephone xxx/xx.xx.xx\n");
                printf("Ou xx/xxx.xx.xx \t\t");
                LireChaine(player.Telephone, GSM);
                error = LireTelephone(player.Telephone, GSM);
            }while(error != 0);

            do{
                printf("\nMail ___@___.___ : \t\t");
                LireChaine(player.AdMail, MAIL);
                error = LireMail(player.AdMail, MAIL);
            }while(error != 0);

            (pIndex+(*joueur))->IdJoueur *= -1;
            player.IdJoueur = (pIndex+(*joueur))->IdJoueur;
            strcpy((pIndex+(*joueur))->Nom, player.Nom);
            strcpy((pIndex+(*joueur))->Prenom, player.Prenom);

            fseek(fp, ((pIndex+(*joueur))->IdJoueur-1)*sizeof(Joueur), SEEK_SET);
            fwrite(&player, sizeof(Joueur), 1, fp);
            fclose(fp);

            *joueur += 1;
            TriPlayers(pIndex, *joueur);
        }
        else
            printf("Ouverture de fichier impossible\n");
    }
    else
    {
        printf("La limite de joueurs est atteinte\n");
        fflush(stdin);
        printf("Appuyez sur 'enter' pour revenir en arriere\n");
        getchar();
    }
}

/************************************************/
/*  input: La structure Index pour les joueurs  */
/*      Le nombre de joueurs encodés            */
/*                                              */
/*  process: Modifie un joueur de l'index       */
/*                                              */
/*  output: /                                   */
/************************************************/
void EditPlayer(Index *pIndex, short joueur)            //FONCTIONNE 100%
{
    short i, j, error, nbre;
    char tab[MAX];
    Joueur player;
    FILE *fp;

    if(joueur > 0)
    {
        do{
            ListPlayer(pIndex, joueur);     //Affiche la base des infos de tous les joueurs
            do{
                printf("Entrez le numero du joueur a modifier : \n");
                printf("Entrez '0' pour revenir en arriere\n");
                scanf("%hd", &i);
            }while(i < 0 || joueur < i);
            i--;

            if(i != -1)
            {
                fp = fopen("joueurs.dat", "rb");    //Cherche le joueur choisi dans le dossier
                if(fp != NULL) //Si existe
                {
                    nbre = ((pIndex+i)->IdJoueur) - 1;

                    fseek(fp, nbre*sizeof(Joueur), SEEK_SET);
                    fread(&player, sizeof(Joueur), 1, fp);
                    fclose(fp);

                    do{
                        system("cls");
                        printf("Modification d'un joueur\n");
                        PlayerDetails(player);     //Affiche toutes les infos sur le joueur choisi

                        do{
                            printf("\n\nEntrez le numero de la categorie a modifier : \n");
                            printf("Entrez '0' pour sauvegarder et revenir en arriere\n");
                            scanf("%hd", &j);
                        }while(j < 0 || 9 < j);

                        switch(j)
                        {
                        case 1:
                            do{
                                printf("\nNom : \t\t\t\t");
                                error = LireNomPropre(player.Nom, NOM);
                            }while(error != 0);

                            strcpy((pIndex+i)->Nom, player.Nom);    //Mettre à jour dans l'index
                            break;
                        case 2:
                            do{
                                printf("\nPrenom : \t\t\t");
                                error = LireNomPropre(player.Prenom, NOM);
                            }while(error != 0);

                            strcpy((pIndex+i)->Prenom, player.Prenom);      //Mettre à jour dans l'index
                            break;
                        case 3:
                            do{
                                printf("\nDate de naissance jj/mm/aaaa : \t");
                                LireChaine(&tab[0], DATE);
                                error = LireDate(&tab[0], &player.DateNaissance.jour, &player.DateNaissance.mois, &player.DateNaissance.annee);
                            }while(error != 0);
                            break;
                        case 4:
                            printf("\nAdresse : \t\t\t");
                            LireChaine(player.Adresse, ADRESSE);
                            break;
                        case 5:
                            do{
                                printf("\nCode postal : \t\t\t");
                                error = LireShort(player.CodePostal, POSTAL);
                            }while(error != 0);
                        case 6:
                            do{
                                printf("\nVille : \t\t\t");
                                error = LireNomPropre(player.Ville, VILLE);
                            }while(error != 0);
                            break;
                        case 7:
                            do{
                                printf("\nPays : \t\t\t\t");
                                error = LireNomPropre(player.Pays, PAYS);
                            }while(error != 0);
                            break;
                        case 8:
                            do{
                                printf("\nTelephone xxx/xx.xx.xx\n");
                                printf("Ou xx/xxx.xx.xx \t\t");
                                LireChaine(player.Telephone, GSM);
                                error = LireTelephone(player.Telephone, GSM);
                            }while(error != 0);
                            break;
                        case 9:
                            do{
                                printf("\nMail ___@___.___ : \t\t");
                                LireChaine(player.AdMail, MAIL);
                                error = LireMail(player.AdMail, MAIL);
                            }while(error != 0);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Mauvais choix, veuillez re-choisir\n");
                        }
                    }while(j != 0);

                    fp = fopen("joueurs.dat", "r+b");       //Mettre à jour le fichier
                    if(fp != NULL) //Si existe
                    {
                        fseek(fp, nbre*sizeof(Joueur), SEEK_SET);
                        fwrite(&player, sizeof(Joueur), 1, fp);
                        fclose(fp);
                    }
                    else
                        printf("Ouverture de fichier impossible\n");

                    TriPlayers(pIndex, joueur);
                    i = 0;
                }
                else
                    printf("Ouverture de fichier impossible\n");
            }
        }while(i != -1);
    }
    else
    {
        printf("Aucun joueur a modifier pour le moment\n");
        fflush(stdin);
        printf("Appuyez sur 'enter' pour revenir en arriere\n");
        getchar();
    }
}

/************************************************/
/*  input: La structure Index pour les joueurs  */
/*      Le nombre de joueurs encodés            */
/*                                              */
/*  process: Supprime un joueur de l'index      */
/*                                              */
/*  output: /                                   */
/************************************************/
void RemovePlayer(Index *pIndex, short *joueur)         //FONCTIONNE 100%
{
    short i, j, nbre;
    FILE *fp;

    if(*joueur > 0)
    {
        do{
            ListPlayer(pIndex, *joueur);
            do{
                printf("Entrez le numero du joueur a supprimer : \n");
                printf("Entrez '0' pour sauvegarder et revenir en arriere\n");
                scanf("%hd", &i);
            }while(i < 0 || *joueur < i);
            i--;

            if(i != -1)
            {
                do{
                    printf("Etes-vous sur de vouloir supprimer le joueur %s %s et les parties qui lui sont liees?\n", (pIndex+i)->Nom, (pIndex+i)->Prenom);
                    printf("1. Oui\t0. Non\n");
                    scanf("%hd", &j);
                }while(j < 0 || 1 < j);

                if(j == 1)
                {
                    fp = fopen("joueurs.dat", "r+b");
                    if(fp != NULL) //Si existe
                    {
                        nbre = ((pIndex+i)->IdJoueur) - 1;      //Stock l'id du joueur pour le modifier dans le fichier
                        (pIndex+i)->IdJoueur *= -1;     //Change l'id dans l'index pour ne plus le voir

                        fseek(fp, nbre*sizeof(Joueur), SEEK_SET);
                        fwrite(&(pIndex+i)->IdJoueur, sizeof(long), 1, fp);
                        fclose(fp);

                        *joueur -= 1;
                        TriPlayers(pIndex, *joueur);
                    }
                    else
                        printf("Ouverture de fichier impossible\n");
                }
            }
        }while(i != -1 && *joueur > 0);
    }
    else
    {
        printf("Aucun joueur a supprimer pour le moment\n");
        fflush(stdin);
        printf("Appuyez sur 'enter' pour revenir en arriere\n");
        getchar();
    }
}

/************************************************/
/*  input: La structure Index pour les joueurs  */
/*      Le nombre de joueurs encodés            */
/*                                              */
/*  process: Affiche l'index de joueurs         */
/*                                              */
/*  output: /                                   */
/************************************************/
void ListPlayer(Index *pIndex, short joueur)            //FONCTIONNE 100%
{
    short i;

    system("cls");

    if(joueur > 0)
    {
        printf("/ * - * - * - * - * - * - * - * - * - * - * - * \\\n");
        printf("|   \t    \t    \t    \t  \t  \t|\n");
        for(i = 0; i < joueur; i++)
        {
            printf("    \t    %hd. %s %s (%hd)\n", i+1, (pIndex+i)->Nom, (pIndex+i)->Prenom, (pIndex+i)->IdJoueur);
            printf("|   \t    \t    \t    \t  \t  \t|\n");
        }
        printf("\\ * - * - * - * - * - * - * - * - * - * - * - * /\n");
    }
    else
    {
        printf("Aucun joueur a afficher pour le moment\n");
    }
}

/************************************************/
/*  input: La structure Index pour les joueurs  */
/*      Le nombre de joueurs encodés            */
/*                                              */
/*  process: Trie les joueurs de l'index        */
/*                                              */
/*  output: /                                   */
/************************************************/
void TriPlayers(Index *pIndex, short joueur)            //FONCTIONNE 100%
{
    short i, j, k;
    long nbre;
    char tmp[MAX];
//Tri de base (mettre les joueurs effacés à la fin)
    for(i = 0; i < NBRE_JOUEUR; i++)
    {
        for(j = 0, k = 1; j < NBRE_JOUEUR-(i+1); j++, k++)
        {
            if((pIndex+j)->IdJoueur < (pIndex+k)->IdJoueur)
            {
                nbre = (pIndex+j)->IdJoueur;
                (pIndex+j)->IdJoueur = (pIndex+k)->IdJoueur;
                (pIndex+k)->IdJoueur = nbre;
                strcpy(tmp, (pIndex+j)->Nom);
                strcpy((pIndex+j)->Nom, (pIndex+k)->Nom);
                strcpy((pIndex+k)->Nom, tmp);
                strcpy(tmp, (pIndex+j)->Prenom);
                strcpy((pIndex+j)->Prenom, (pIndex+k)->Prenom);
                strcpy((pIndex+k)->Prenom, tmp);
            }
        }
    }
//Tri pas nom
    for(i = 0; i < joueur; i++)
    {
        for(j = 0, k = 1; j < joueur-(i+1); j++, k++)
        {
            if((pIndex+j)->IdJoueur > 0)
            {
                if(strcmp((pIndex+j)->Nom, (pIndex+k)->Nom) > 0)
                {
                    nbre = (pIndex+j)->IdJoueur;
                    (pIndex+j)->IdJoueur = (pIndex+k)->IdJoueur;
                    (pIndex+k)->IdJoueur = nbre;
                    strcpy(tmp, (pIndex+j)->Nom);
                    strcpy((pIndex+j)->Nom, (pIndex+k)->Nom);
                    strcpy((pIndex+k)->Nom, tmp);
                    strcpy(tmp, (pIndex+j)->Prenom);
                    strcpy((pIndex+j)->Prenom, (pIndex+k)->Prenom);
                    strcpy((pIndex+k)->Prenom, tmp);
                }
            }
        }
    }
}

/************************************************/
/*  input: La structure Index pour les joueurs  */
/*                                              */
/*  process: Affiche les détails d'un joueur    */
/*                                              */
/*  output: /                                   */
/************************************************/
void PlayerDetails(Joueur player)                 //FONCTIONNE 100%
{
    printf("\n1. Nom : \t\t%s", player.Nom);
    printf("\n2. Prenom : \t\t%s", player.Prenom);
    printf("\n3. Date de naissance : \t%hd/%hd/%hd", player.DateNaissance.jour, player.DateNaissance.mois, player.DateNaissance.annee);
    printf("\n4. Adresse : \t\t%s", player.Adresse);
    printf("\n5. Code postal : \t%hd", player.CodePostal);
    printf("\n6. Ville : \t\t%s", player.Ville);
    printf("\n7. Pays : \t\t%s", player.Pays);
    printf("\n8. Telephone : \t\t%s", player.Telephone);
    printf("\n9. Adresse mail : \t%s", player.AdMail);
}
