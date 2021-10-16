/************************************************/
/* Auteur : FRANCOIS Hugo             			*/
/* Groupe : 2104                               	*/
/* Application : Dossier LC10, tri d'un vecteur	*/
/*    de caracteres au moyen de la méthode du	*/
/*    "heap sort"                               */
/*												*/
/* Date de la dernière m-à-j : 25/02/2019		*/
/************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define COL_MAX 20
#define LIG_MAX 50

void Ajout(char *, short);
void Majuscule(char *, short);
void Affiche(char *, short, short);
void Tri(char *, short, short);
void Paterner(char *, short, short, short);

int main()
{
	short Choix = 0;
	char tab[LIG_MAX][COL_MAX];
	short i = 0;

//Menu principal pour sélectionner une action
	while(Choix != 4)
	{
		printf("Veuillez choisir une option\n");
		printf("===================================\n");
        printf("MENU\n");
        printf("1.\tAjouter un prenom\n");
        printf("2.\tAfficher le tableau\n");
        printf("3.\tTrier le tableau\n");
        printf("4.\tQuitter\n");
        printf("===================================\n");
		scanf("%hd", &Choix);
		switch(Choix)
		{
			case 1:
			    printf("\n");
                if(i < LIG_MAX)
                {
                    Ajout(&tab[i][0], COL_MAX);
                    Majuscule(&tab[i][0], COL_MAX);
                    i++;
                }
                else
                {
                    printf("Le tableau est rempli");
                }
                printf("\n\n\n\n");
				break;
			case 2:
			    printf("\n");
                Affiche(&tab[0][0], i, COL_MAX);
                printf("\n\n\n\n");
				break;
			case 3:
			    printf("\n");
                Tri(&tab[0][0], i, COL_MAX);
                printf("\n\n\n\n");
				break;
			case 4:
				break;
			default:
				system("cls");
                printf("Mauvais choix, veuillez re-choisir");
                printf("\n\n\n");
		}
	}

	return 0;
}

/************************************************/
/*	input: Un pointeur sur le tableau des noms	*/
/*		Le nombre maximum de colonnes			*/
/*												*/
/*	process: Ajouter un prénom					*/
/*												*/
/*	output: /									*/
/************************************************/
void Ajout(char *pTab, short Col)
{
	short j = 0;

    printf("Entrez un prenom :\n");

    fflush(stdin);
    *pTab = getchar();
    while(j < (Col - 1) && *pTab != '\n')
    {
    	pTab++;
        *pTab = getchar();
        j++;
    }
    *pTab = '\0';
}

/************************************************/
/*	input: Un pointeur sur le tableau des noms	*/
/*		Le nombre maximum de colonnes			*/
/*												*/
/*	process: Mettre la première lettre en 		*/
/*		majuscule et les autres en minuscule	*/
/*												*/
/*	output: /									*/
/************************************************/
void Majuscule(char *pTab, short Col)
{
	short j = 0;

	*pTab = toupper(*pTab);

	while(j < (Col - 1) && *pTab != '\0')
	{
		pTab++;
        *pTab = tolower(*pTab);
        j++;

        if(*pTab == ' ')
        {
        	pTab++;
            if(*pTab != '\0')
            {
                *pTab = toupper(*pTab);
            }
       		j++;
        }
        else
        {
	        if(*pTab == '-')
	        {
	        	pTab++;
	        	if(*pTab != '\0')
                {
                    *pTab = toupper(*pTab);
                }
	       		j++;
	        }
        }
	}
}

/************************************************/
/*	input: Un pointeur sur le tableau des noms	*/
/*		Le nombre maximum de colonnes			*/
/*												*/
/*	process: Afficher le tableau				*/
/*												*/
/*	output: /									*/
/************************************************/
void Affiche(char *pTab, short i, short Col)
{
	short j;

	printf("Liste des prenoms :\n\n");

	for(j = 0; j < i; j++)
	{
        printf("%hd. %s\n", j+1, pTab);

        pTab += Col;
	}
}

/************************************************/
/*	input: Un pointeur sur le tableau des noms	*/
/*		Le nombre maximum de colonnes			*/
/*		Le nombre maximum de lignes				*/
/*												*/
/*	process: Trier le tableau des noms			*/
/*												*/
/*	output: /									*/
/************************************************/
void Tri(char *pTab, short Lig, short Col)
{
    short i;
    char tmp[Col];
    *tmp = '\0';

    fflush(stdin);

//Phase 1
    for(i = Lig/2 - 1; i >= 0; i--)
    {
        Paterner(pTab, i, Lig, Col);
    }

//Phase 2
    for(i = Lig-1; i > 0; i--)
    {
    	strcpy(tmp, pTab);
    	strcpy(pTab, pTab+(i*Col));
    	strcpy(pTab+(i*Col), tmp);

        Paterner(pTab, 0, i, Col);
    }

    printf("Tableau trie\n");
}

/************************************************/
/*	input: Un pointeur sur le tableau des noms	*/
/*		Le nombre maximum de colonnes			*/
/*		Le nombre maximum de lignes				*/
/*												*/
/*	process: Trier le tableau des noms			*/
/*												*/
/*	output: /									*/
/************************************************/
void Paterner(char *pTab, short i, short Lig, short Col)
{
//i = Père ; j = Fils
    short j = (i*2) + 1;
    char tmp[Col];
    *tmp = '\0';

    while(j < Lig)
    {
//Si fils 1 < fils 2 => On passe à fils 2
        if(j < Lig-1 && 0 > strcmp(pTab+(j*Col), pTab+((j*Col)+Col)))
        {
            j++;
        }

        if(0 > strcmp(pTab+(i*Col), pTab+(j*Col)))
        {
	    	strcpy(tmp, pTab+(i*Col));
	    	strcpy(pTab+(i*Col), pTab+(j*Col));
	    	strcpy(pTab+(j*Col), tmp);

            i = j;
            j = (i*2)+1;
        }
        else
        {
            j = Lig;
        }
    }
}
