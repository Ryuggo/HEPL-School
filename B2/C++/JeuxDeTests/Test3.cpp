#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Couleur.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();
void Essai6();
void Essai7();
void Essai8();

int main(int argc,char* argv[])
{
  int choix;
  bool fini = false;
  
  while(!fini)
  {
    if (argc == 2) { choix = atoi(argv[1]); fini = true; }
    else choix = Menu();
    switch(choix)
    {
      case 1 : Essai1(); break;
      case 2 : Essai2(); break;
      case 3 : Essai3(); break;
      case 4 : Essai4(); break;
//      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

//******************************************************************************************************
int Menu()
{
  cout << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TESTS 3 -------------------------------------------------------------------" << endl;
  cout << "--------------------------------------------------------------------------------------" << endl;
  cout << " 1. Tests de l'operateur = de la classe Couleur" << endl;
  cout << " 2. Tests de l'operateur (+ Couleur) de la classe Couleur" << endl;
  cout << " 3. Tests des operateurs (+ int) de la classe Couleur" << endl;
  cout << " 4. Tests de l'operateur (- int) de la classe Couleur" << endl;
  cout << " 5. Tests de l'operateur [] de Couleur" << endl;
  cout << " 6. Tests des operateurs << et >> de la classe Couleur" << endl;
  cout << " 7. Tests des operateurs ++ de la classe Couleur" << endl;
  cout << " 8. Tests des operateurs -- de la classe Couleur" << endl;
  cout << " 9. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
//*** Tests des operateurs = de la classe Joueur ********************************************************
//*******************************************************************************************************
void Essai1()
{ 
  cout << "********************************************************************" << endl;
  cout << "(1) ***** Test de l'operateur d'affectation de Couleur *************" << endl;
  cout << "********************************************************************" << endl;
  {
    Couleur c;
    {
      Couleur c1(112,141,35,"Olive");
      cout << "c1 : "; c1.Affiche();

      cout << endl << ">>>>> c = c1;" << endl;
      c = c1;
      cout << ">>>>> Destruction de c1" << endl << endl;
    }
    cout << "c : "; c.Affiche();

    cout << endl << ">>>>> c = Couleur(145,23,230);" << endl;
    c = Couleur(145,23,230);
    cout << "c : "; c.Affiche();
  }
}

//*******************************************************************************************************
//*** Tests de l'operateur (+ Couleur) de la classe Couleur *********************************************
//*******************************************************************************************************
void Essai2()
{
  cout << endl << "************************************************************************" << endl;
  cout <<         "(2) ***** Tests de l'operateur (+ Couleur) de la classe Couleur ********" << endl;
  cout <<         "************************************************************************" << endl;
  {
    Couleur c1(Couleur::ROUGE),c2(Couleur::BLEU),c3(134,12,0);
    cout << "c1 (avant) : "; c1.Affiche();
    cout << "c2 (avant) : "; c2.Affiche();
    cout << "c3 (avant) : "; c3.Affiche();
    cout << endl;

    Couleur c;
    cout << ">>>>> c = c1 + c2;" << endl;
    c = c1 + c2;
    cout << "c : "; c.Affiche();
    cout << endl;

    cout << ">>>>> c = c + c3;" << endl;
    c = c + c3;
    cout << "c : "; c.Affiche();
    cout << endl;

    cout << ">>>>> c = c3 + Couleur(50,12,60);" << endl;
    c = c3 + Couleur(50,12,60);
    cout << "c : "; c.Affiche();
    cout << endl;

    cout << ">>>>> c = Couleur::ROUGE + Couleur(112,141,35,\"Olive\");" << endl;
    c = Couleur::ROUGE + Couleur(112,141,35,"Olive");
    cout << "c : "; c.Affiche();
    cout << endl;

    cout << "c1 (apres) : "; c1.Affiche();
    cout << "c2 (apres) : "; c2.Affiche();
    cout << "c3 (apres) : "; c3.Affiche();
  }
}

//*******************************************************************************************************
//*** Tests des operateurs (+ int) de la classe Couleur *************************************************
//*******************************************************************************************************
void Essai3()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(3.1) ***** Test de l'operateur (Couleur + int) ********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Couleur c1(150,131,236,"Lavande");
    cout << "c1 (avant) : "; c1.Affiche();
    cout << endl;

    Couleur c2;
    cout << ">>>>> c2 = c1 + 10;" << endl;
    c2 = c1 + 10;
    cout << "c2 : "; c2.Affiche();
    cout << endl;

    cout << ">>>>> c2 = c2 + 20;" << endl;
    c2 = c2 + 20;
    cout << "c2 : "; c2.Affiche();
    cout << endl;

    cout << "c1 (apres) : "; c1.Affiche(); // c1 ne doit pas etre modifie !!!!
  }

  cout << endl << "********************************************************************" << endl;
  cout <<         "(3.2) ***** Test de l'operateur (int + Couleur) ********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Couleur c1(248,152,85,"Saumon");
    cout << "c1 (avant) : "; c1.Affiche();
    cout << endl;

    Couleur c2;
    cout << ">>>>> c2 = 15 + c1;" << endl;
    c2 = 15 + c1;
    cout << "c2 : "; c2.Affiche();
    cout << endl;

    cout << ">>>>> c2 = 5 + c2;" << endl;
    c2 = 5 + c2;
    cout << "c2 : "; c2.Affiche();
    cout << endl;

    cout << "c1 (apres) : "; c1.Affiche(); // c1 ne doit pas etre modifie !!!!
  }
}

//*******************************************************************************************************
//*** Tests de l'operateur (- int) de la classe Couleur *************************************************
//*******************************************************************************************************
void Essai4()
{
  cout << endl << "********************************************************************" << endl;
  cout <<         "(4) ***** Test de l'operateur (Couleur - int) **********************" << endl;
  cout <<         "********************************************************************" << endl;
  {
    Couleur c1(244,102,27,"Carotte");
    cout << "c1 (avant) : "; c1.Affiche();
    cout << endl;

    Couleur c2;
    cout << ">>>>> c2 = c1 - 20;" << endl;
    c2 = c1 - 20;
    cout << "c2 : "; c2.Affiche();
    cout << endl;

    cout << ">>>>> c2 = c2 - 10;" << endl;
    c2 = c2 - 10;
    cout << "c2 : "; c2.Affiche();
    cout << endl;

    cout << "c1 (apres) : "; c1.Affiche(); // c1 ne doit pas etre modifie !!!!
  }
}

////*******************************************************************************************************
////*** Tests des operateurs < > et == de la classe Couleur ***********************************************
////*******************************************************************************************************
//void Essai5()
//{
//  cout << endl << "********************************************************************" << endl;
//  cout <<         "(5) ***** Tests de l'operateur [] de Couleur ***********************" << endl;
//  cout <<         "********************************************************************" << endl;
//  Couleur c1(109,7,26,"Bordeaux");
//  cout << "c1 = "; c1.Affiche();
//  cout << "c1 (rouge) = " << c1["rouge"] << endl;
//  cout << "c1 (vert) = " << c1["vert"] << endl;
//  cout << "c1 (bleu) = " << c1["bleu"] << endl;
//  cout << "--> on modifie les composantes de c1" << endl;
//  c1["rouge"] = 10;
//  c1["vert"] = 20;
//  c1["bleu"] = 30;
//  cout << "c1 = "; c1.Affiche();
//  cout << endl;
//}

//*******************************************************************************************************
//*** Tests des operateurs << et >> de la classe Couleur ************************************************
//*******************************************************************************************************
void Essai6()
{
  cout << "**************************************************************************" << endl;
  cout << "(6) ********* Tests des operateurs << et >> de Couleur *******************" << endl;
  cout << "**************************************************************************" << endl;
  Couleur c1(127,0,255,"Violet");
  cout << "c1 = " << c1 << endl;
  cout << "Nouvelle valeur pour c1 = ";
  cin >> c1;
  cout << c1 << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs ++ de la classe Couleur ******************************************************
//*******************************************************************************************************
void Essai7()
{
  Couleur c(150,131,236,"Lavande");
  cout << "**********************************************************************" << endl;
  cout << "(7.1) ***** Test de l'operateur de pre-incrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "c   : " << c << endl;
  cout << "++c : " << ++c << endl;  // Si tout va bien, c est incremente avant d'etre affiche !
  cout << "c   : " << c << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(7.2) ***** Test de l'operateur de post-incrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "c   : " << c << endl;
  cout << "c++ : " << c++ << endl;  // Si tout va bien, c est incremente apres avoir ete affiche !
  cout << "c   : " << c << endl << endl;
}

//*******************************************************************************************************
//*** Tests des operateurs -- de la classe Couleur ******************************************************
//*******************************************************************************************************
void Essai8()
{
  Couleur c(253,108,158,"Rose");
  cout << "**********************************************************************" << endl;
  cout << "(8.1) ***** Test de l'operateur de pre-decrementation ****************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "c   : " << c << endl;
  cout << "--c : " << --c << endl;  // Si tout va bien, c est decremente avant d'etre affiche !
  cout << "c   : " << c << endl << endl;

  cout << "**********************************************************************" << endl;
  cout << "(8.2) ***** Test de l'operateur de post-decrementation ***************" << endl;
  cout << "**********************************************************************" << endl;
  cout << "c   : " << c << endl;
  cout << "c-- : " << c-- << endl;  // Si tout va bien, c est decremente apres avoir ete affiche !
  cout << "c   : " << c << endl << endl;
}

