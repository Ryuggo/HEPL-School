/************************************************/
/* Auteur : FRANCOIS Hugo             			*/
/* Groupe : 2104                               	*/
/* Application : Dossier LC20_2, puissance 4	*/
/*    joueur contre ordinateur qui peut gagner	*/
/*												*/
/* Date de la dernière m-à-j : 16/03/2019		*/
/************************************************/
#include <stdio.h>
#include <stdlib.h>

#define LIG 6
#define COL 7

void Affiche(char *);
void Jouer(char *, char, char *);
void Bot(char *, char, char *);
void Verif(char *, char, short, short, char *, short *);
void Vider(char *);

void main()
{
	char tab[LIG][COL] = {' '};
	char Joueur, Win;
	short Reboot = 1;

    Affiche(&tab[0][0]);

    do{
        Win = '0';
        Joueur = '1';
        Vider(&tab[0][0]);

        Affiche(&tab[0][0]);

//Fait jouer les joueurs jusqu'à ce qu'il y ait un gagnant
        while(Win == '0')
        {
            Jouer(&tab[0][0], Joueur, &Win);
            Joueur++;

            if(Win == '0')
            {
                Bot(&tab[0][0], Joueur, &Win);
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
            Vider(&tab[0][0]);
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
void Affiche(char *pTab)
{
    short i, j;

    system("cls");

    for(i = 0; i < LIG; i++)
    {
        printf("\n");
        for(j = 0; j < COL; j++)
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
/*                                              */
/*  process: Le joueur place un pion 			*/
/*                                              */
/*  output: /                                   */
/************************************************/
void Jouer(char *pTab, char Joueur, char *Win)
{
    short i, Case, Libre = 0;
    char CaseValid;
    short Vide = 10;

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

        for(i = 5; i >= 0; i--)
        {
            if(*(pTab+(i*COL)+Case) == ' ')
            {
                *(pTab+(i*COL)+Case) = Joueur;

                Verif(pTab, Joueur, i, Case, Win, &Vide);

                Libre = 1;
                i = -1;
            }

            if(i == 0)
            {
                printf("Vous ne pouvez pas mettre de pion dans cette colonne, choisissez-en une autre\n");
            }
        }
    }
    Affiche(pTab);
}

/************************************************/
/*  input: Un pointeur sur le tableau des noms  */
/*      Le numéro du joueur                     */
/*      Une booléen pour la victoire            */
/*                                              */
/*  process: L'ordinateur place un pion 		*/
/*                                              */
/*  output: /                                   */
/************************************************/
void Bot(char *pTab, char Joueur, char *Win)
{
	short i, Case;
	short j, k;
	short Suite = -1, tmp;

    for(Case = 0; Case < COL; Case++)
    {
//Vérifie le nombre de possibilités par colonne
    	for(i = LIG-1; i >= 0; i--)
        {
            if(*(pTab+(i*COL)+Case) == ' ')
            {
            	tmp = 0;
//Pose un pion temporaire dans la case libre de la colonne actuelle
            	*(pTab+(i*COL)+Case) = '3';

            	Verif(pTab, Joueur, i, Case, Win, &tmp);

            	*(pTab+(i*COL)+Case) = ' ';
//Actualise la position de la case avec le plus de possibilités
            	if(tmp > Suite)
            	{
            		j = i;
            		k = Case;
            		Suite = tmp;
            	}
                i = -1;
            }
        }
    }
    *(pTab+(j*COL)+k) = Joueur;
    Affiche(pTab);
}

/************************************************/
/*  input: Un pointeur sur le tableau des noms  */
/*      Le numéro du joueur                     */
/*      La valeur de la ligne et de la colonne  */
/*      Une booléen pour la victoire            */
/*      Une variable temporaire pour le bot     */
/*                                              */
/*  process: Vérifier si le pion forme un 		*/
/*		alignement 								*/
/*                                              */
/*  output: /                                   */
/************************************************/
void Verif(char *pTab, char Joueur, short i, short Case, char *Win, short *pTmp)
{
    short j, k, Suite;

//Verification verticale
    for(j = i, Suite = 0; j < LIG && Suite < 4; j++)
    {
        if(*(pTab+(j*COL)+Case) == Joueur)
        {
            Suite++;
        }
        else
        {
        	if(*(pTab+(j*COL)+Case) == '3')
        	{
        		Suite++;
        	}
        	else
        	{
          		Suite = 0;
          		j = LIG;
        	}
        }

        if(Suite == 4)
        {
            *Win = Joueur;
        }
    }
    if(Suite > *pTmp)
    {
    	*pTmp = Suite;
    }

//Vérification horizontale
	for(k = Case-3, Suite = 0; k < COL; k++)
    {
        if(k < 0)
        {
            k = 0;
        }
        if(*(pTab+(i*COL)+k) == Joueur)
        {
            Suite++;
        }
        else
        {
        	if(*(pTab+(i*COL)+k) == '3')
        	{
        		Suite++;
        	}
        	else
        	{
        		if(Suite > *pTmp)
			    {
			    	*pTmp = Suite;
			    }
          		Suite = 0;
        	}
        }

        if(Suite == 4)
        {
            *Win = Joueur;
        }
    }
    if(Suite > *pTmp)
    {
    	*pTmp = Suite;
    }

//Vérifications diagonales
//Haut-gauche à Bas-droite
    for(j = i, k = Case; 0 < j && 0 < k; j--, k--) ;

    for(Suite = 0; j < LIG && k < COL; j++, k++)
    {
        if(*(pTab+(j*COL)+k) == Joueur)
        {
            Suite++;
        }
        else
        {
            if(*(pTab+(j*COL)+k) == '3')
        	{
        		Suite++;
        	}
        	else
        	{
        		if(Suite > *pTmp)
			    {
			    	*pTmp = Suite;
			    }
          		Suite = 0;
        	}
        }

        if(Suite == 4)
        {
            *Win = Joueur;
    		printf("Obl 1\n");
        }
    }
    if(Suite > *pTmp)
    {
    	*pTmp = Suite;
    }
//Bas-gauche à Haut-droite
    for(j = i, k = Case; j < LIG-1 && 0 < k; j++, k--) ;

    for(Suite = 0; 0 < j && k < COL; j--, k++)
    {
        if(*(pTab+(j*COL)+k) == Joueur)
        {
            Suite++;
        }
        else
        {
            if(*(pTab+(j*COL)+k) == '3')
        	{
        		Suite++;
        	}
        	else
        	{
        		if(Suite > *pTmp)
			    {
			    	*pTmp = Suite;
			    }
          		Suite = 0;
        	}
        }

        if(Suite == 4)
        {
            *Win = Joueur;
            printf("Obl 2\n");
        }
    }
    if(Suite > *pTmp)
    {
    	*pTmp = Suite;
    }

//Vérification si le tableau est rempli
    for(Case = 0, i = 0; Case < COL; Case++)
    {
        if(*(pTab+Case) != ' ')
        {
            i++;
        }

        if(i == COL && *Win == '0')
        {
            *Win = '3';
        }
    }
}

/************************************************/
/*  input: Un pointeur sur le tableau           */
/*                                              */
/*  process: Vider le tableau                   */
/*                                              */
/*  output: /                                   */
/************************************************/
void Vider(char *pTab)
{
    short i, j;

    fflush(stdin);

    for(i = 0; i < LIG; i++)
    {
        for(j = 0; j < COL; j++)
        {
            *pTab = ' ';
            pTab++;
        }
    }
}
