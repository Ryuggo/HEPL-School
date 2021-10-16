/************************************************/
/* Auteur : FRANCOIS Hugo                       */
/* Groupe : 2104                                */
/* Application : Dossier LC20_1, puissance 4    */
/*    joueur contre joueur                      */
/*                                              */
/* Date de la dernière m-à-j : 16/03/2019       */
/************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LIG 6
#define COL 7

void Affiche(char *, short, short);
void Jouer(char *, char, char *, short, short);
void Verif(char *, char, short, char, char *, short, short);
void Vider(char *, short, short);

void main()
{
	char tab[LIG][COL] = {' '};
	char Joueur, Win;
	short Reboot = 1;

    Affiche(&tab[0][0], LIG, COL);

    do{
        Win = '0';
        Joueur = '1';
        Vider(&tab[0][0], LIG, COL);

        Affiche(&tab[0][0], LIG, COL);

//Fait jouer les joueurs jusqu'à ce qu'il y ait un gagnant
        while(Win == '0')
        {
            Jouer(&tab[0][0], Joueur, &Win, LIG, COL);
            Joueur++;

            if(Win == '0')
            {
                Jouer(&tab[0][0], Joueur, &Win, LIG, COL);
                Joueur--;
            }
        }

        if(Win == '1')
        {
            printf("Le joueur %c a gagne\n", Win);
        }
        if(Win == '2')
        {
            printf("Le joueur %c a gagne\n", Win);
        }
        if(Win == '3')
        {
            printf("La grille est remplie, il n'y a aucun gagnant\n");
        }

//Pour recommencer une partie
        do{
            printf("Voulez-vous rejouer ?\n1. Oui\n0. Non\n");
            scanf("%hd", &Reboot);
        }while(Reboot < 0 || 1 < Reboot);

//Réinitialisation du tableau
        if(Reboot == 1)
        {
            Vider(&tab[0][0], LIG, COL);
        }
    }while(Reboot == 1);

	return 0;
}

/************************************************/
/*  input: Un pointeur sur le tableau           */
/*                                              */
/*  process: Afficher le tableau                */
/*                                              */
/*  output: /                                   */
/************************************************/
void Affiche(char *pTab, short Lig, short Col)
{
    short i, j;

    system("cls");

    for(i = 0; i < Lig; i++)
    {
        printf("\n");
        for(j = 0; j < Col; j++)
        {
            printf("\t[%c]", *pTab);
            pTab++;
        }
        printf("\n");
    }
    printf("\t===================================================\n");
    printf("\t[1]\t[2]\t[3]\t[4]\t[5]\t[6]\t[7]\n\n");
}

/************************************************/
/*  input: Un pointeur sur le tableau des noms  */
/*      Le numéro du joueur                     */
/*      Une booléen pour la victoire            */
/*      Le nombre maximum de colonnes et lignes */
/*                                              */
/*  process: Le joueur place un pion            */
/*                                              */
/*  output: /                                   */
/************************************************/
void Jouer(char *pTab, char Joueur, char *Win, short Lig, short Col)
{
    short i, Case, Libre = 0;
    char CaseValid;

    while(Libre == 0)
    {
//Choisir une colonne et vérification qu'il s'agisse juste d'un nombre entier
        do{
            printf("Joueur %c, choisissez une colonne ou mettre le pion (entre 1 et 7)\n", Joueur);
            fflush(stdin);
            scanf("%c", &CaseValid);
            Case = (short)CaseValid;
        }while(CaseValid < '1' || '7' < CaseValid);
        Case -= 49;

        for(i = Lig-1; i >= 0; i--)
        {
            if(*(pTab+(i*Col)+Case) == ' ')
            {
                *(pTab+(i*Col)+Case) = Joueur;

                Verif(pTab, Joueur, i, Case, Win, Lig, Col);

                Libre = 1;
                i = -1;
            }

            if(i == 0)
            {
                printf("Vous ne pouvez pas mettre de pion dans cette colonne, choisissez-en une autre\n");
            }
        }
    }
    Affiche(pTab, Lig, Col);
}

/************************************************/
/*  input: Un pointeur sur le tableau           */
/*      Le numéro du joueur                     */
/*      La valeur de la ligne et de la colonne  */
/*      Une booléen pour la victoire            */
/*      Le nombre maximum de colonnes et lignes */
/*                                              */
/*  process: Vérifier si le pion forme un       */
/*      alignement                              */
/*                                              */
/*  output: /                                   */
/************************************************/
void Verif(char *pTab, char Joueur, short i, char Case, char *Win, short Lig, short Col)
{
    short j, k, Suite;

//Verification verticale
    for(j = i, Suite = 0; j < Lig && Suite < 4; j++)
    {
        if(*(pTab+(j*Col)+Case) == Joueur)
        {
            Suite++;
        }
        else
        {
            Suite = 0;
            j = Lig;
        }

        if(Suite == 4)
        {
            *Win = Joueur;
        }
    }

//Vérification horizontale
    for(k = Case-3, Suite = 0; k < Col; k++)
    {
        if(k < 0)
        {
            k = 0;
        }
        if(*(pTab+(i*Col)+k) == Joueur)
        {
            Suite++;
        }
        else
        {
            Suite = 0;
        }

        if(Suite == 4)
        {
            *Win = Joueur;
        }
    }

//Vérifications diagonales
//Haut-gauche à Bas-droite
    for(j = i, k = Case; 0 < j && 0 < k; j--, k--) ;

    for(Suite = 0; j < Lig && k < Col; j++, k++)
    {
        if(*(pTab+(j*Col)+k) == Joueur)
        {
            Suite++;
        }
        else
        {
            Suite = 0;
        }

        if(Suite == 4)
        {
            *Win = Joueur;
        }
    }
//Bas-gauche à Haut-droite
    for(j = i, k = Case; j < Lig-1 && 0 < k; j++, k--) ;

    for(Suite = 0; 0 < j && k < Col; j--, k++)
    {
        if(*(pTab+(j*Col)+k) == Joueur)
        {
            Suite++;
        }
        else
        {
            Suite = 0;
        }

        if(Suite == 4)
        {
            *Win = Joueur;
        }
    }

//Vérification si le tableau est rempli
    for(Case = 0, i = 0; Case < Col; Case++)
    {
        if(*(pTab+Case) != ' ')
        {
            i++;
        }

        if(i == Col && *Win == '0')
        {
            *Win = '3';
        }
    }
}

/************************************************/
/*  input: Un pointeur sur le tableau           */
/*      Le nombre maximum de colonnes et lignes */
/*                                              */
/*  process: Vider le tableau                   */
/*                                              */
/*  output: /                                   */
/************************************************/
void Vider(char *pTab, short Lig, short Col)
{
    short i, j;

    fflush(stdin);

    for(i = 0; i < Lig; i++)
    {
        for(j = 0; j < Col; j++)
        {
            *pTab = ' ';
            pTab++;
        }
    }
}
