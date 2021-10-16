#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "outils.h"

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Le nombre max de caractères             */
/*                                              */
/*  process: Encoder tous les caractères        */
/*                                              */
/*  output: /                                   */
/************************************************/
void LireChaine(char *pTab, short max)
{
    short i = 0;

    fflush(stdin);
    do{
        *(pTab+i) = getchar();
        i++;
    }while(i < (max) && *(pTab+i-1) != '\n');
    *(pTab+i-1) = '\0';
}

/************************************************/
/*  input: Un pointeur de nombre short          */
/*      Le nombre max de caractères             */
/*                                              */
/*  process: Encoder des nombres entiers        */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireShort(short *nbre, short max)
{
    short i = 0, error = 0;
    char tab[max];

    fflush(stdin);
    do{
        tab[i] = getchar();
        if(('0' <= tab[i] && tab[i] <= '9') || tab[i] == '-')
        {
            i++;
            do{
                tab[i] = getchar();
                if(('0' <= tab[i] && tab[i] <= '9') || tab[i] == '\n')
                    i++;
                else
                    error = 1;
            }while(i < (max) && tab[i-1] != '\n');
        }
        else
            error = 1;
    }while(i < (max) && tab[i-1] != '\n');
    tab[i-1] = '\0';

    if(error != 0)
    {
        error = Error(&tab[0]);
    }
    ConvertShort(&tab[0], nbre);

    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Le nombre max de caractères             */
/*                                              */
/*  process: Encoder des nom sans chiffre       */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireLettres(char *pTab, short max)
{
    short i = 0, error = 0;

    fflush(stdin);
    do{
        *(pTab+i) = getchar();
        if(('a' <= *(pTab+i) && *(pTab+i) <= 'z') || ('A' <= *(pTab+i) && *(pTab+i) <= 'Z') || *(pTab+i) == '\n')
            i++;
        else
            error = 1;
    }while(i < (max) && *(pTab+i-1) != '\n');
    *(pTab+i-1) = '\0';

    if(error != 0)
    {
        error = Error(pTab);
    }
    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Le nombre max de caractères             */
/*                                              */
/*  process: Encoder des nom propres            */
/*          Mettre des majuscules au début      */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireNomPropre(char *pTab, short max)
{
    short i = 0, error = 0;

    fflush(stdin);
    do{
        *(pTab+i) = getchar();
        if(('a' <= *(pTab+i) && *(pTab+i) <= 'z') || ('A' <= *(pTab+i) && *(pTab+i) <= 'Z') || *(pTab+i) == ' ' || *(pTab+i) == '-' || *(pTab+i) == '\n')
            i++;
        else
            error = 1;
    }while(i < (max) && *(pTab+i-1) != '\n');
    *(pTab+i-1) = '\0';

    *pTab = toupper(*pTab);
    for(i = 1; *(pTab+i) != '\0'; i++)
    {
        *(pTab+i) = tolower(*(pTab+i));

        if(*(pTab+i) == ' ' || *(pTab+i) == '-')
        {
            if(*(pTab+i+1) == '\0' || *(pTab+i+1) == ' ' || *(pTab+i+1) == '-')
            {
                *(pTab+i) = '\0';
            }
            else
            {
                i++;
                *(pTab+i) = toupper(*(pTab+i));
            }
        }
    }

    if(error != 0)
    {
        error = Error(pTab);
    }
    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Les 3 nombre pour la date (j, m, a)     */
/*                                              */
/*  process: Encoder une date au un bon format  */
/*          jj/mm/aaaa                          */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireDate(char *pTab, short *jour, short *mois, short *annee)
{
    short i = 0, j = 1, error = 0;

    while(i < 6 && error == 0)
    {
        while(i != 2 && i != 5 && error == 0)
        {
            if('0' <= *(pTab+i) && *(pTab+i) <= '9')
                i++;
            else
                error = j;
        }
        while(i != 3 && i != 6 && error == 0)
        {
            if(*(pTab+i) == '/')
                    i++;
            else
                error = 3;
        }
        j++;
    }
    while(*(pTab+i-1) != '\0' && error == 0)
    {
        if(('0' <= *(pTab+i) && *(pTab+i) <= '9') || *(pTab+i) == '\0')
            i++;
        else
            error = 4;
    }

    if(error == 0)
    {
        ConvertShort(pTab, jour);
        ConvertShort(pTab+3, mois);
        ConvertShort(pTab+6, annee);

        error = VerifDate(*jour, *mois, *annee);
    }
    else
    {
        if(error == 1)
        {
            printf("Date invalide, probleme avec les jours\n");
            *jour = 0;
            *mois = 0;
            *annee = 0;
            *pTab = '\0';
        }
        else
        {
            if(error == 2)
            {
                printf("Date invalide, probleme avec les mois\n");
                *pTab = '\0';
            }
            else
            {
                if(error == 3)
                {
                    printf("Date invalide, probleme avec les separations : '/'\n");
                    *pTab = '\0';
                }
                else
                {
                    if(error == 4)
                    {
                        printf("Date invalide, probleme avec les annees\n");
                        *pTab = '\0';
                    }
                }
            }
        }
    }
    return error;
}

/************************************************/
/*  input: Les 3 nombres pour la date (j, m, a) */
/*                                              */
/*  process: Vérifier si la date est valide par */
/*      rapport à celle d'aujourd'hui           */
/*                                              */
/*  output: /                                   */
/************************************************/
short VerifDate(short jour, short mois, short annee)
{
    short error = 0;
    short calendrier[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    time_t secondes;
    struct tm date;

    time(&secondes);
    date=*localtime(&secondes);

    if(mois == 2)   //Année bissextile ?
    {
        if((annee % 4 == 0) && (annee % 100 != 0 || annee % 400 == 00))
            calendrier[2] = 29;
    }

    if((0 < jour && jour <= calendrier[(mois)-1]) && (0 < mois && mois <= 12))
    {
        if(annee > 1900+date.tm_year)
        {
            printf("L'annee depasse l'annee actuelle\n");
            error = 1;
        }
        else
        {
           if(annee == 1900+date.tm_year && mois > date.tm_mon+1)
           {
                printf("Le mois depasse le mois actuel\n");
                error = 1;
           }
            else
            {
                if(annee == 1900+date.tm_year && mois == date.tm_mon+1 && jour > date.tm_yday)
                {
                    printf("Le jour depasse la date actuelle\n");
                    error = 1;
                }
            }
        }
    }
    else
    {
        printf("Le jour encode n'est pas valide \n");
        error = 1;
    }
    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Le nombre max de caractères             */
/*                                              */
/*  process: Encoder un mail au bon format      */
/*          ___@___.___com                      */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireMail(char *pTab, short max)
{
    short i, error = 2;

    for(i = 0; *(pTab+i) != '\0' && *(pTab+i-1) != '@' && i < max; i++)
    {
        if(*(pTab+i) == '@')
            error--;
    }
    while(*(pTab+i) != '\0' && *(pTab+i-1) != '.' && i < max && error == 1)
    {
        if(*(pTab+i) == '.')
            error--;
        if(*(pTab+i) == '@')
            error = 3;
        i++;
    }

    if(error == 1)
    {
        printf("Mail invalide, il manque le '.'\n");
        *pTab = '\0';
    }
    else
    {
        if(error == 2)
        {
            printf("Mail invalide, il manque le '@'\n");
            *pTab = '\0';
        }
        else
        {
            if(error == 3)
            {
                printf("Mail invalide, il y a trop de '@'\n");
                *pTab = '\0';
            }
        }
    }
    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Le nombre max de caractères             */
/*                                              */
/*  process: Encoder un numéro de téléphone     */
/*          xxx/xx.xx.xxx                       */
/*          xx/xxx.xx.xx                        */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireTelephone(char *pTab, short max)
{
    short i = 0, error = 0;

//xxx/xx.xx.xxx  
    while(i < 4 && error == 0)
    {
        while(i != 3 && error == 0)
        {
            if(('0' <= *(pTab+i) && *(pTab+i) <= '9'))
                i++;
            else
                error = 1;
        }
        while(i != 4 && error == 0)
        {
            if(*(pTab+i) == '/')
                    i++;
            else
                error = 2;
        }
    }
    while(i < 12 && error == 0)
    {
        while(i != 6 && i != 9 && i < 12 && error == 0)
        {
            if(('0' <= *(pTab+i) && *(pTab+i) <= '9') || *(pTab+i) == '\0')
                i++;
            else
                error = 1;
        }
        while(i != 7 && i != 10 && i < 12 && error == 0)
        {
            if(*(pTab+i) == '.')
                    i++;
            else
                error = 3;
        }
    }

//xx/xxx.xx.xx
    if(error != 0)
    {
        error = 0;

        while(i < 3 && error == 0)
        {
            while(i != 2 && error == 0)
            {
                if(('0' <= *(pTab+i) && *(pTab+i) <= '9'))
                    i++;
                else
                    error = 1;
            }
            while(i != 3 && error == 0)
            {
                if(*(pTab+i) == '/')
                        i++;
                else
                    error = 2;
            }
        }
        while(i < 12 && error == 0)
        {
            while(i != 6 && i != 9 && i < 12 && error == 0)
            {
                if(('0' <= *(pTab+i) && *(pTab+i) <= '9') || *(pTab+i) == '\0')
                    i++;
                else
                    error = 1;
            }
            while(i != 7 && i != 10 && i < 12 && error == 0)
            {
                if(*(pTab+i) == '.')
                        i++;
                else
                    error = 3;
            }
        }
    }

    if(error == 1)
    {
        printf("Telephone invalide, probleme avec les chiffres\n");
        *pTab = '\0';
    }
    else
    {
        if(error == 2)
        {
            printf("Telephone invalide, probleme avec le '/'\n");
            *pTab = '\0';
        }
        else
        {
            if(error == 3)
            {
                printf("Telephone invalide, probleme avec le(s) '.'\n");
                *pTab = '\0';
            }
        }
    }
    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Les 2 nombre pour l'heure (h, min)      */
/*                                              */
/*  process: Encoder une heure au un bon format */
/*          hh:mm                               */
/*          Vérifier si l'heure est valide      */
/*                                              */
/*  output: /                                   */
/************************************************/
short LireHeure(char *pTab, short *heure, short *minute, short *seconde)
{
    short i = 0, error = 0, sec = 0;

    do{
        while(i != 2 && i != 5 && error == 0)
        {
            if('0' <= *(pTab+i) && *(pTab+i) <= '9')
                i++;
            else
                error = 1;
        }

        if(*(pTab+i) != '\0' && error == 0)
        {
            while(i != 3 && i != 6 && error == 0)
            {
                if(*(pTab+i) == ':')
                        i++;
                else
                    error = 2;
            }
        }
        else
        {
            if(i == 5)
                sec = 1;
        }
    }while(*(pTab+i) != '\0' && error == 0);

    if(error == 0)
    {
        printf("sec %hd\n", sec);
        ConvertShort(pTab, heure);
        if(*heure > 23)
            error = 3;
        if(error == 0)
        {
            ConvertShort(pTab+3, minute);
            if(*minute > 59)
                error = 4;
            if(sec == 0 && error == 0)
            {
                ConvertShort(pTab+6, seconde);
                if(*seconde > 59)
                    error = 5;
            }
            else
                *seconde = 0;
        }
    }
    else
    {
        if(error == 1)
        {
            printf("Heure invalide, probleme avec les chiffres\n");
            *pTab = '\0';
        }
        else
        {
            if(error == 2)
            {
                printf("Heure invalide, probleme avec les separation ':'\n");
                *pTab = '\0';
            }
        }
    }
    if(error == 3)
    {
        printf("Heure invalide, nombre d'heures trop grand\n");
        *heure = 0;
        *minute = 0;
        *seconde = 0;
    }
    else
    {
        if(error == 4)
        {
            printf("Heure invalide, nombre de minutes trop grand\n");
            *heure = 0;
            *minute = 0;
            *seconde = 0;
        }
        else
        {
            if(error == 5)
            {
                printf("Heure invalide, nombre de secondes trop grand\n");
                *heure = 0;
                *minute = 0;
                *seconde = 0;
            }
        }
    }
    return error;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*                                              */
/*  process: Sauvegarder ou supprimer la chaine */
/*      sans caractères invalides               */
/*                                              */
/*  output: /                                   */
/************************************************/
short Error(char *pTab)
{
    short choix;

    fflush(stdin);

    printf("\nCaractere(s) invalide(s) encode(s)\n");
    printf("Voici l'entree avec le(s) caractere(s) invalide(s) en moins : %s\n", pTab);

    printf("Voulez-vous conserver les changements?\n");
    do{
        printf("0. Oui\t1. Non\n");
        scanf("%hd", &choix);
    }while(choix < 0 || 1 < choix);
    switch(choix)
    {
    case 0:
        break;
    case 1:
        *pTab = '\0';
        break;
    default:
        printf("Choix invalide, suppression des changements\n");
        *pTab = '\0';
        break;
    }
    return choix;
}

/************************************************/
/*  input: Un pointeur de tableau char          */
/*      Le short pour stocker une valeur entière*/
/*                                              */
/*  process: Convertir des char en short        */
/*                                              */
/*  output: /                                   */
/************************************************/
void ConvertShort(char *pTab, short *nbre)
{
    short i = 0;
    int tmp;

    if(*pTab == '-')
        i = 1;

    for(tmp = 0; *(pTab+i) != '\0' && ('0' <= *(pTab+i) && *(pTab+i) <= '9'); i++)
    {
        tmp = tmp*10+(*(pTab+i)-48);
    }
    *nbre = tmp;
    if(*pTab == '-')
        *nbre *= -1;
}
