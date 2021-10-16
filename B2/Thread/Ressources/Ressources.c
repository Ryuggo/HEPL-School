#include "Ressources.h"
#include "GrilleSDL.h"

// Macros pour les sprites
#define S_VOYANT_BLEU              200001
#define S_VOYANT_VERT              200002
#define S_VOYANT_ROUGE             200003

#define S_BRIQUE                   200005
#define S_BRIQUE_FUSION            200006

#define S_DIAMANT_ROUGE            200011
#define S_DIAMANT_VERT             200012
#define S_DIAMANT_VIOLET           200013

#define S_DIAMANT_CHARLET          200020
#define S_DIAMANT_MERCENIER        200021
#define S_DIAMANT_SAGOT            200022
#define S_DIAMANT_VILVENS          200023
#define S_DIAMANT_WAGNER           200024

#define S_CHARLET          		  200040
#define S_MERCENIER       			  200041
#define S_SAGOT           			  200042
#define S_VILVENS        			  200043
#define S_WAGNER          			  200044

#define S_CHIFFRE_0                300030
#define S_CHIFFRE_1                300031
#define S_CHIFFRE_2                300032
#define S_CHIFFRE_3                300033
#define S_CHIFFRE_4                300034
#define S_CHIFFRE_5                300035
#define S_CHIFFRE_6                300036
#define S_CHIFFRE_7                300037
#define S_CHIFFRE_8                300038
#define S_CHIFFRE_9                300039

#define S_LETTRE_A                 400001
#define S_LETTRE_B                 400002
#define S_LETTRE_C                 400003
#define S_LETTRE_D                 400004
#define S_LETTRE_E                 400005
#define S_LETTRE_F                 400006
#define S_LETTRE_G                 400007
#define S_LETTRE_H                 400008
#define S_LETTRE_I                 400009
#define S_LETTRE_J                 400010
#define S_LETTRE_K                 400011
#define S_LETTRE_L                 400012
#define S_LETTRE_M                 400013
#define S_LETTRE_N                 400014
#define S_LETTRE_O                 400015
#define S_LETTRE_P                 400016
#define S_LETTRE_Q                 400017
#define S_LETTRE_R                 400018
#define S_LETTRE_S                 400019
#define S_LETTRE_T                 400020
#define S_LETTRE_U                 400021
#define S_LETTRE_V                 400022
#define S_LETTRE_W                 400023
#define S_LETTRE_X                 400024
#define S_LETTRE_Y                 400025
#define S_LETTRE_Z                 400026
#define S_LETTRE_ESPACE            400027

void ChargementImages()
{
  // Definition de l'image de fond
  DessineImageFond("./images/FondEcran.bmp");

  // Sprites Chiffres
  AjouteSpriteAFondTransparent(S_CHIFFRE_0,"./images/chiffres/Zero.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_1,"./images/chiffres/Un.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_2,"./images/chiffres/Deux.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_3,"./images/chiffres/Trois.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_4,"./images/chiffres/Quatre.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_5,"./images/chiffres/Cinq.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_6,"./images/chiffres/Six.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_7,"./images/chiffres/Sept.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_8,"./images/chiffres/Huit.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_CHIFFRE_9,"./images/chiffres/Neuf.bmp",255,255,255);  

  // Sprites Lettres
  AjouteSpriteAFondTransparent(S_LETTRE_A,"./images/lettres/A.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_B,"./images/lettres/B.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_C,"./images/lettres/C.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_D,"./images/lettres/D.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_E,"./images/lettres/E.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_F,"./images/lettres/F.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_G,"./images/lettres/G.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_H,"./images/lettres/H.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_I,"./images/lettres/I.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_J,"./images/lettres/J.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_K,"./images/lettres/K.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_L,"./images/lettres/L.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_M,"./images/lettres/M.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_N,"./images/lettres/N.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_O,"./images/lettres/O.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_P,"./images/lettres/P.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_Q,"./images/lettres/Q.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_R,"./images/lettres/R.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_S,"./images/lettres/S.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_T,"./images/lettres/T.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_U,"./images/lettres/U.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_V,"./images/lettres/V.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_W,"./images/lettres/W.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_X,"./images/lettres/X.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_Y,"./images/lettres/Y.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_Z,"./images/lettres/Z.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_LETTRE_ESPACE,"./images/lettres/Espace.bmp",255,255,255);

  // Sprites Voyants
  AjouteSprite(S_VOYANT_VERT,"./images/VoyantVert40.bmp");
  AjouteSprite(S_VOYANT_BLEU,"./images/VoyantBleu40.bmp");
  AjouteSprite(S_VOYANT_ROUGE,"./images/VoyantRouge40.bmp");

  // Sprites Briques
  AjouteSpriteAFondTransparent(S_BRIQUE,"./images/Brique40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_BRIQUE_FUSION,"./images/Fusion40.bmp",255,255,255);

  // Sprites Chiffres
  AjouteSpriteAFondTransparent(S_DIAMANT_ROUGE,"./images/diamants/diamantRouge40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_DIAMANT_VERT,"./images/diamants/diamantVert40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_DIAMANT_VIOLET,"./images/diamants/diamantViolet40.bmp",255,255,255);
  
  
  AjouteSpriteAFondTransparent(S_DIAMANT_CHARLET,"./images/Profs/Diam_Charlet40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_DIAMANT_MERCENIER,"./images/Profs/Diam_Mercenier40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_DIAMANT_SAGOT,"./images/Profs/Diam_Sagot40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_DIAMANT_VILVENS,"./images/Profs/Diam_Vilvens40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_DIAMANT_WAGNER,"./images/Profs/Diam_Wagner40.bmp",255,255,255);
  
  
  AjouteSpriteAFondTransparent(S_CHARLET,"./images/Profs/Charlet40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_MERCENIER,"./images/Profs/Mercenier40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_SAGOT,"./images/Profs/Sagot40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_VILVENS,"./images/Profs/Vilvens40.bmp",255,255,255);
  AjouteSpriteAFondTransparent(S_WAGNER,"./images/Profs/Wagner40.bmp",255,255,255);
}

// Fonctions Ressources
int OuvertureFenetreGraphique()
{
  if (OuvrirGrilleSDL(12,19,40,"!!! BLOCKUDOKU !!!","./images/iconeFenetre256.bmp") < 0)
    return -1;
 
  ChargementImages();
  return 0;
}

int FermetureFenetreGraphique()
{
  FermerGrilleSDL();
  return 0;
}

void DessineVoyant(int l,int c,int couleur)
{
  switch(couleur)
  {
    case ROUGE : DessineSprite(l,c,S_VOYANT_ROUGE); break;
    case VERT  : DessineSprite(l,c,S_VOYANT_VERT); break;
    case BLEU  : DessineSprite(l,c,S_VOYANT_BLEU); break;
    default    : DessineSprite(l,c,S_VOYANT_BLEU); break;    
  }
}

void DessineDiamant(int l,int c,int couleur)
{
  switch(couleur)
  {
    case ROUGE  : DessineSprite(l,c,S_DIAMANT_ROUGE); break;
    case VERT   : DessineSprite(l,c,S_DIAMANT_VERT); break;
    case VIOLET : DessineSprite(l,c,S_DIAMANT_VIOLET); break;
    
    case D_CHARLET : DessineSprite(l,c,S_DIAMANT_CHARLET); break;
    case D_MERCENIER : DessineSprite(l,c,S_DIAMANT_MERCENIER); break;
    case D_SAGOT : DessineSprite(l,c,S_DIAMANT_SAGOT); break;
    case D_VILVENS : DessineSprite(l,c,S_DIAMANT_VILVENS); break;
    case D_WAGNER : DessineSprite(l,c,S_DIAMANT_WAGNER); break;
    
    case CHARLET : DessineSprite(l,c,S_CHARLET); break;
    case MERCENIER : DessineSprite(l,c,S_MERCENIER); break;
    case SAGOT : DessineSprite(l,c,S_SAGOT); break;
    case VILVENS : DessineSprite(l,c,S_VILVENS); break;
    case WAGNER : DessineSprite(l,c,S_WAGNER); break;
    default    :  DessineSprite(l,c,S_DIAMANT_ROUGE); break; 
  }
}

void DessineBrique(int l,int c,bool fusion)
{
  if (fusion) DessineSprite(l,c,S_BRIQUE_FUSION);
  else DessineSprite(l,c,S_BRIQUE);
}

void DessineChiffre(int l,int c,int val)
{
  switch(val)
  {
    case 0 : DessineSprite(l,c,S_CHIFFRE_0); break;
    case 1 : DessineSprite(l,c,S_CHIFFRE_1); break;
    case 2 : DessineSprite(l,c,S_CHIFFRE_2); break;
    case 3 : DessineSprite(l,c,S_CHIFFRE_3); break;
    case 4 : DessineSprite(l,c,S_CHIFFRE_4); break;
    case 5 : DessineSprite(l,c,S_CHIFFRE_5); break;
    case 6 : DessineSprite(l,c,S_CHIFFRE_6); break;
    case 7 : DessineSprite(l,c,S_CHIFFRE_7); break;
    case 8 : DessineSprite(l,c,S_CHIFFRE_8); break;
    case 9 : DessineSprite(l,c,S_CHIFFRE_9); break;
    default : DessineSprite(l,c,S_CHIFFRE_0); break;    
  }
}

void DessineLettre(int L,int C,char c)
{
  c = toupper(c);
  switch(c)
  {
    case 'A' : DessineSprite(L,C,S_LETTRE_A); break;
    case 'B' : DessineSprite(L,C,S_LETTRE_B); break;
    case 'C' : DessineSprite(L,C,S_LETTRE_C); break;
    case 'D' : DessineSprite(L,C,S_LETTRE_D); break;
    case 'E' : DessineSprite(L,C,S_LETTRE_E); break;
    case 'F' : DessineSprite(L,C,S_LETTRE_F); break;
    case 'G' : DessineSprite(L,C,S_LETTRE_G); break;
    case 'H' : DessineSprite(L,C,S_LETTRE_H); break;
    case 'I' : DessineSprite(L,C,S_LETTRE_I); break;
    case 'J' : DessineSprite(L,C,S_LETTRE_J); break;
    case 'K' : DessineSprite(L,C,S_LETTRE_K); break;
    case 'L' : DessineSprite(L,C,S_LETTRE_L); break;
    case 'M' : DessineSprite(L,C,S_LETTRE_M); break;
    case 'N' : DessineSprite(L,C,S_LETTRE_N); break;
    case 'O' : DessineSprite(L,C,S_LETTRE_O); break;
    case 'P' : DessineSprite(L,C,S_LETTRE_P); break;
    case 'Q' : DessineSprite(L,C,S_LETTRE_Q); break;
    case 'R' : DessineSprite(L,C,S_LETTRE_R); break;
    case 'S' : DessineSprite(L,C,S_LETTRE_S); break;
    case 'T' : DessineSprite(L,C,S_LETTRE_T); break;
    case 'U' : DessineSprite(L,C,S_LETTRE_U); break;
    case 'V' : DessineSprite(L,C,S_LETTRE_V); break;
    case 'W' : DessineSprite(L,C,S_LETTRE_W); break;
    case 'X' : DessineSprite(L,C,S_LETTRE_X); break;
    case 'Y' : DessineSprite(L,C,S_LETTRE_Y); break;
    case 'Z' : DessineSprite(L,C,S_LETTRE_Z); break;
    case ' ' : DessineSprite(L,C,S_LETTRE_ESPACE); break;
    case '0' : DessineSprite(L,C,S_CHIFFRE_0); break;
    case '1' : DessineSprite(L,C,S_CHIFFRE_1); break;
    case '2' : DessineSprite(L,C,S_CHIFFRE_2); break;
    case '3' : DessineSprite(L,C,S_CHIFFRE_3); break;
    case '4' : DessineSprite(L,C,S_CHIFFRE_4); break;
    case '5' : DessineSprite(L,C,S_CHIFFRE_5); break;
    case '6' : DessineSprite(L,C,S_CHIFFRE_6); break;
    case '7' : DessineSprite(L,C,S_CHIFFRE_7); break;
    case '8' : DessineSprite(L,C,S_CHIFFRE_8); break;
    case '9' : DessineSprite(L,C,S_CHIFFRE_9); break;
    default :  DessineSprite(L,C,S_LETTRE_ESPACE); break;
  }
}

