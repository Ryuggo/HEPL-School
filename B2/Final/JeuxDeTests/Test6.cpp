#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Liste.h"
#include "Pile.h"
#include "Iterateur.h"

#include "Couleur.h"

using namespace std;

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
      case 5 : Essai5(); break;
      case 6 : Essai6(); break;
      case 7 : Essai7(); break;
      case 8 : Essai8(); break;
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 6 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test du template Liste avec des entiers" << endl;
  cout << " 2. Test du template Liste avec des objets de la classe Couleur" << endl;
  cout << " 3. Test du template Pile avec des entiers" << endl;
  cout << " 4. Test du template Pile avec des objets de la classe Couleur" << endl;
  cout << " 5. Test de l'iterateur avec une Liste d'entiers" << endl;
  cout << " 6. Test de l'iterateur avec une Liste de Couleurs" << endl;
  cout << " 7. Test de l'iterateur avec une Pile d'entiers" << endl;
  cout << " 8. Test de l'iterateur avec une Pile de Couleurs" << endl;
  cout << " 9. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*******************************************************************************************************
void Essai1()
{
  cout << "----- 1. Test du template Liste avec des entiers --------------------------------------------" << endl;
  cout << "----- 1.1 Creation et gestion d'une Liste ---------------------------------------------------" << endl;

  Liste<int> liste;
  liste.Affiche();                                       // --> ()
  cout << endl;

  cout << "Liste Vide ? " << liste.estVide() << endl;
  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  int *pI = liste.insere(5);
  liste.insere(-1);
  liste.insere(0);
  cout << "Liste Vide ? " << liste.estVide() << endl;
  liste.Affiche();                                       // --> (3 -2 5 -1 0)
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl;
  cout << "On modifie le 3eme element :" << endl;
  *pI = 100;
  liste.Affiche();

  cout << "----- 1.2 Test du constructeur de copie -----------------------------------------------------" << endl;
  {
    Liste<int> liste2(liste);
    cout << "----> Voici la copie :" << endl;
    liste2.Affiche();
    cout << "----> On insere 50 dans la copie :" << endl; 
    liste2.insere(50);
    liste2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;

  cout << "----- 1.3 Test de l'operateur = -------------------------------------------------------------" << endl;
  {
    Liste<int> liste3;
    liste3 = liste;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    liste3.Affiche();
    cout << "----> On insere 50 dans la nouvelle liste :" << endl; 
    liste3.insere(50);
    liste3.Affiche();
    cout << "----> Destruction de la nouvelle liste..." << endl;
  }
  cout << endl << "Et revoici la liste de depart : " << endl;
  liste.Affiche();
  cout << endl;
}

////*********************************************************************************************
void Essai2()
{
  cout << "----- 2. Test du template Liste avec des objets de la classe Couleur --------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Couleur> liste;
  liste.Affiche();                                    
  cout << endl;

  cout << "On insere (127,0,255,\"Violet\")..." << endl;
  liste.insere(Couleur(127,0,255,"Violet"));
  liste.Affiche();

  cout << "On insere le Rouge..." << endl;
  liste.insere(Couleur::ROUGE);
  liste.Affiche();

  cout << "On insere (25,67,45)..." << endl;
  Couleur *ptr = new Couleur(25,67,45);
  Couleur *pC = liste.insere(*ptr);
  delete ptr;
  liste.Affiche();
  cout << "La liste contient " << liste.getNombreElements() << " elements." << endl << endl;

  cout << "On modifie le dernier element de la liste :" << endl;
  pC->setRouge(255);
  liste.Affiche();

  cout << endl;
}

////*******************************************************************************************************
void Essai3()
{
  cout << "----- 3. Test du template Pile avec des entiers ------------------------" << endl;
  cout << "----- 3.1 Creation et gestion d'une Pile ------------------------------" << endl;
  Pile<int> pile;
  pile.Affiche();                                       // --> ()
  cout << endl;

  cout << "Pile Vide ? " << pile.estVide() << endl;
  cout << "On empile 3,-2,5,-1 et 0..." << endl;
  pile.push(3);   // ne fait qu'appeler la methode insere
  pile.insere(-2);
  pile.push(5);
  pile.push(-1);
  pile.push(0);
  cout << "Pile Vide ? " << pile.estVide() << endl;
  pile.Affiche();                                       // --> (0 -1 5 -2 3)
  cout << "La pile contient " << pile.getNombreElements() << " elements." << endl << endl;

  cout << "Top = " << pile.top() << endl << endl;
  
  cout << "On depile..." << endl;
  int val = pile.pop();
  cout << "Valeur depilee = " << val << endl;
  cout << "Re-voici la pile : " << endl;
  pile.Affiche();
  cout << endl << endl;

  cout << "----- 3.2 Test du constructeur de copie ----------------------------------" << endl;
  {
    Pile<int> pile2(pile);
    cout << "----> Voici la copie :" << endl;
    pile2.Affiche();
    cout << "----> On insere 4 dans la copie :" << endl; 
    pile2.push(4);
    pile2.Affiche();
    cout << "----> Destruction de la copie..." << endl;
  }
  cout << endl << "Et revoici la pile de depart : " << endl;
  pile.Affiche();
  cout << endl;

  cout << "----- 3.3 Test de l'operateur = -------------------------------------------" << endl;
  {
    Pile<int> pile3;
    pile3 = pile;
    cout << "----> Voici le resultat de l'operateur = :" << endl;
    pile3.Affiche();
    cout << "----> On insere 6 dans la nouvelle pile :" << endl; 
    pile3.insere(6);
    pile3.Affiche();
    cout << "----> Destruction de la nouvelle pile..." << endl;
  }
  cout << endl << "Et revoici la pile de depart : " << endl;
  pile.Affiche();
  cout << endl;
}

////*******************************************************************************************************
void Essai4()
{
  cout << "----- 4. Test du template Pile avec des Couleurs ------------------------------------------" << endl;
  cout << "Creation d'une Pile..." << endl;
  Pile<Couleur> pile;

  pile.Affiche();                                       
  cout << endl;
  cout << "Pile Vide ? " << pile.estVide() << endl;

  cout << "On empile quelques couleurs..." << endl;
  pile.push(Couleur(127,0,255,"Violet"));
  pile.push(Couleur::ROUGE);
  pile.push(Couleur(255,255,255,"Blanc"));
  pile.push(Couleur(88,41,0,"Marron"));
  pile.push(Couleur(0,0,0));

  pile.Affiche();                                       
  cout << endl;
  cout << "Pile Vide ? " << pile.estVide() << endl;
  cout << "La pile contient " << pile.getNombreElements() << " elements." << endl << endl;

  cout << "Top = " << pile.top() << endl << endl;
  
  cout << "On depile..." << endl;
  Couleur val = pile.pop();
  cout << "Valeur depilee = " << val << endl;
  cout << "Re-voici la pile : " << endl;
  pile.Affiche();
  cout << endl << endl;
}

////*******************************************************************************************************
void Essai5()
{
  cout << "----- 5. Test de l'iterateur avec une Liste d'entiers ------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<int> liste;
  Iterateur<int> it(liste);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  liste.insere(3);
  liste.insere(-2);
  liste.insere(5);
  liste.insere(-1);
  liste.insere(0);

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On affiche en sens inverse grace a l'iterateur..." << endl;
  for (it.last() ; !it.end() ; it--)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (5 --> 20)..." << endl;
  it.reset();  // on est sur 3
  it++;        // on est sur -2
  it++;        // on est sur 5;
  *(&it) = 20;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 4eme element de la liste (-1)..." << endl;
  it++;        // on est sur -1
  int valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

////*******************************************************************************************************
void Essai6()
{
  cout << "----- 6. Test de l'iterateur avec une Liste de Couleur --------------------------------------" << endl;
  cout << "Creation  d'une Liste..." << endl;
  Liste<Couleur> liste;
  Iterateur<Couleur> it(liste);

  cout << "On insere quelques couleurs..." << endl;
  liste.insere(Couleur(128,128,128,"Gris"));
  liste.insere(Couleur::VERT);
  liste.insere(Couleur(248,152,85,"Saumon"));

  cout << "On affiche grace a l'iterateur..." << endl;
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Couleur)it << endl;
  cout << endl;

  cout << "On affiche en sens inverse grace a l'iterateur..." << endl;
  for (it.last() ; !it.end() ; it--)
    cout << " " << (Couleur)it << endl;
  cout << endl;

  cout << "On modifie le 3eme element de la liste (\"Saumon\" --> BLEU)..." << endl;
  it.reset();  // on est sur Gris
  it++;        // on est sur VERT
  it++;        // on est sur Saumon
  *(&it) = Couleur::BLEU;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;

  cout << "On supprime le 1er element de la liste (\"Gris\")..." << endl;
  it.reset();        // on est sur Gris
  Couleur valeurRetiree = it.remove();
  cout << "Valeur retiree = " << valeurRetiree << endl;
  cout << "On re-affiche la liste..." << endl;
  liste.Affiche();
  cout << endl;
}

////*******************************************************************************************************
void Essai7()
{
  cout << "----- 7. Test de l'iterateur avec une Pile d'entiers ------------------------" << endl;
  cout << "Creation  d'une Pile..." << endl;
  Pile<int> pile;
  Iterateur<int> it(pile);

  cout << "On insere 3,-2,5,-1 et 0..." << endl;
  pile.push(3);
  pile.push(-2);
  pile.push(5);
  pile.push(-1);
  pile.push(0);

  cout << "On affiche grace a l'iterateur..." << endl; // --> (0 -1 5 -2 3)
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (int)it << endl;
  cout << endl;

  cout << "On affiche en sens inverse grace a l'iterateur..." << endl;
  for (it.last() ; !it.end() ; it--)
    cout << " " << (int)it << endl;
  cout << endl;
}

////*******************************************************************************************************
void Essai8()
{
  cout << "----- 8. Test de l'iterateur avec une Pile de Couleurs -------------------------------" << endl;
  cout << "Creation  d'une Pile..." << endl;
  Pile<Couleur> pile;
  Iterateur<Couleur> it(pile);

  cout << "On insere quelques couleurs..." << endl;
  pile.push(Couleur(127,0,255,"Violet"));
  pile.push(Couleur::ROUGE);
  pile.push(Couleur(255,255,255,"Blanc"));
  pile.push(Couleur(88,41,0,"Marron"));
  pile.push(Couleur(0,0,0));

  cout << "On affiche grace a l'iterateur..." << endl; 
  for (it.reset() ; !it.end() ; it++)
    cout << " " << (Couleur)it << endl;
  cout << endl;

  cout << "On affiche en sens inverse grace a l'iterateur..." << endl; 
  for (it.last() ; !it.end() ; it--)
    cout << " " << (Couleur)it << endl;
  cout << endl;
}

