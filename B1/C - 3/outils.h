#ifndef _OUTILS_H_
#define _OUTILS_H_

#define DATE 11
#define HEURE 6
#define HEURESEC 9

typedef struct date{
    short jour;
    short mois;
    short annee;
}Date;

typedef struct heure{
    short heure;
    short minute;
    short seconde;
}Heure;

void LireChaine(char *, short);
short LireShort(short *, short);
short LireNomPropre(char *, short);
short LireDate(char *, short *, short *, short *);
short VerifDate(short, short, short);
short LireMail(char *, short);
short LireTelephone(char *, short);
short LireHeure(char *, short *, short *, short *);

short Error(char *);
void ConvertShort(char *, short *);

#endif // _OUTILS_H_
