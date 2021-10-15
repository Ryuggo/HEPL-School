#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

#include "Pixel.h"
#include "Ligne.h"
#include "Rectangle.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();
void Essai4();
void Essai5();

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
      case 5 : Essai5(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 5 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test de setId() de Pixel, Ligne et Rectangle" << endl;
  cout << " 2. Test des constructeurs de Pixel, Ligne et Rectangle" << endl;
  cout << " 3. Test des setXXX() de la classe Couleur" << endl;
  cout << " 4. Test des constructeurs de la classe Couleur" << endl;
  cout << " 5. Gestion de plusieurs exceptions simultanement" << endl;
  cout << " 6. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//**********************************************************************************************
// ATTENTION !!!!
// Les methodes de vos classes NE doivent PAS contenir de TRY{...} CATCH{...} mais
// uniquement des THROW !!! Donc, votre classe lance une exception (une erreur) mais
// ce n'est pas elle qui la traite. C'est l'application qui utilise votre classe
// qui doit traiter les exceptions. C'est donc uniquement dans le main (ou les fonctions appelees)
// que l'on trouve des try...catch 
//**********************************************************************************************
void Essai1()
{

  cout << "----- 1. Test de setId() de Pixel, Ligne et Rectangle -------------------------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  try
  {
    Figure *pf;
    int n = rand()%3;
    switch(n)
    {
      case 0 : pf = new Pixel();
               cout << "Creation d'un Pixel par defaut..." << endl;
               break;

      case 1 : pf = new Ligne();
               cout << "Creation d'une Ligne par defaut..." << endl;
               break;

      case 2 : pf = new Rectangle();
               cout << "Creation d'un Rectangle par defaut..." << endl;
               break;
    }

    char txt[80];
    cout << "Encodez son identifiant : "; cin.getline(txt,80);
    pf->setId(txt);  // !!!
    cout << "Identifiant encode = " << pf->getId() << endl << endl;
  }
  catch(BaseException e) {
  	cerr << "ERREUR : " << e.getMsg() << endl;
  }
  catch(...)
  { }
  
  cout << endl;
}

//**********************************************************************************************
void Essai2()
{

  cout << "----- 2. Test des constructeurs de Pixel, Ligne et Rectangle ------------------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee

  try
  {
    char txt[80];
    cout << "Creation d'un Pixel..." << endl;
    cout << "Encodez son identifiant : "; cin.getline(txt,80);
    Pixel p(txt,Point(100,130),&Couleur::ROUGE);
    cout << "Pixel cree : " << p << endl << endl;

    cout << "Creation d'une Ligne..." << endl;
    cout << "Encodez son identifiant : "; cin.getline(txt,80);
    Ligne l(txt,Point(100,130),Point(200,150),&Couleur::BLEU);
    cout << "Ligne creee : " << l << endl << endl;

    cout << "Creation d'un Rectangle..." << endl;
    cout << "Encodez son identifiant : "; cin.getline(txt,80);
    Rectangle r(txt,Point(100,130),100,70,true,&Couleur::VERT);
    cout << "Rectangle cree : " << r << endl << endl;
  }
  catch(BaseException e) {
  	cerr << "ERREUR : " << e.getMsg() << endl;
  }
  catch(...)
  { }
  
  cout << endl;
}

//**********************************************************************************************
void Essai3()
{

  cout << "----- 3. Test des setXXX() de la classe Couleur ------------------------------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee ET la (les) composante(s) invalide(s)

  try
  {
    Couleur c;
    int val;
    cout << "Composante Rouge : "; cin >> val; cin.ignore();
    c.setRouge(val);
    cout << "Composante Verte : "; cin >> val; cin.ignore();
    c.setVert(val);
    cout << "Composante Bleue : "; cin >> val; cin.ignore();
    c.setBleu(val);
    cout << "Couleur encodee = " << c << endl << endl;
  }
  catch(InvalidColorException e) {
  	cerr << "ERREUR : " << e.getMsg() << " (" << e.getValeur() << ")" << endl;
  }
  catch(...)
  { }
  
  cout << endl;
}

//**********************************************************************************************
void Essai4()
{

  cout << "----- 4. Test des constructeurs de la classe Couleur -------------------------------" << endl;
  // A COMPLETER : Traitez l'exception susceptible d'etre lancee par le bloc de code suivant (try...catch)
  // en particulier : afficher le message de l'exception lancee ET la (les) composante(s) invalide(s)

  try
  {
    int r,v,b;
    cout << "Creation de couleurs..." << endl;
    cout << "Composante Rouge : "; cin >> r; cin.ignore();
    cout << "Composante Verte : "; cin >> v; cin.ignore();
    cout << "Composante Bleue : "; cin >> b; cin.ignore();
    Couleur c1(r,v,b);
    Couleur c2(r,v,b,"boufff");
    cout << "Couleur encodee sans nom = " << c1 << endl;
    cout << "Couleur encodee avec nom = " << c2 << endl << endl;
  }
  catch(InvalidColorException e) {
  	cerr << "ERREUR : " << e.getMsg() << " (" << e.getValeur() << ")" << endl;
  }
  catch(...)
  { }
  
  cout << endl;
}

//**********************************************************************************************/
void Essai5()
{
  cout << "----- 5. Gestion de plusieurs exceptions simultanement ------------------------------" << endl;
  // A COMPLETER : Traitez TOUTES les exceptions susceptible d'etre lancee par le bloc de code suivant (try...catch)

  try
  {
    int r,v,b;
    cout << "--> Creation d'une Couleur..." << endl;
    cout << "Composante Rouge : "; cin >> r; cin.ignore();
    cout << "Composante Verte : "; cin >> v; cin.ignore();
    cout << "Composante Bleue : "; cin >> b; cin.ignore();
    Couleur c1(r,v,b,"Ma Couleur");
    cout << "--> Creation d'une Ligne de cette couleur..." << endl;
    char txt[80];
    cout << "Encodez son identifiant : "; cin.getline(txt,80);
    Ligne l(txt,Point(100,130),Point(200,150),&c1);
    cout << "Ligne creee : " << l << endl << endl;
  }
  catch(InvalidColorException e) {
  	cerr << "ERREUR : " << e.getMsg() << " (" << e.getValeur() << ")" << endl;
  }
  catch(BaseException e) {
  	cerr << "ERREUR : " << e.getMsg() << endl;
  }
  catch(...)
  { }
}


