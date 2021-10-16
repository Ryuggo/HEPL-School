#ifndef RESSOURCES_H
#define RESSOURCES_H

// Macros pour les couleurs de fantome
#define ROUGE                     400000
#define VIOLET                    400001
#define VERT                      400002
#define BLEU                      400003

#define D_CHARLET                 400020
#define D_MERCENIER               400021
#define D_SAGOT                   400022
#define D_VILVENS                 400023
#define D_WAGNER                  400024

#define CHARLET                   400040
#define MERCENIER                 400041
#define SAGOT                     400042
#define VILVENS                   400043
#define WAGNER                    400044

int  OuvertureFenetreGraphique();
int  FermetureFenetreGraphique();

void DessineDiamant(int l,int c,int couleur);
void DessineBrique(int l,int c,bool fusion);
void DessineVoyant(int l,int c,int couleur);
void DessineChiffre(int l,int c,int val);
void DessineLettre(int L,int C,char c);


#endif
