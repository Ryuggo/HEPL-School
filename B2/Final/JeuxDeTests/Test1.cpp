#include <stdlib.h>
#include <iostream>
using namespace std;
 #include "Couleur.h"

// Quelques conseils avant de commencer...
// * N'oubliez pas de tracer (cout << ...) tous les constructeurs et le destructeur !!! Ca, c'est pas un conseil,
//   c'est obligatoire :-)
// * N'essayez pas de compiler ce programme entierement immediatement. Mettez tout en commentaires
//   sauf le point (1) et creez votre classe (dans ce fichier pour commencer) afin de compiler et tester 
//   le point (1). Une fois que cela fonctionne, decommentez le point (2) et modifier votre classe en 
//   consequence. Vous developpez, compilez et testez donc etape par etape. N'attendez pas d'avoir encode 
//   300 lignes pour compiler...
// * Une fois que tout le programme compile et fonctionne correctement, creez le .h contenant la declaration
//   de la classe, le .cxx contenant la definition des methodes, et ensuite le makefile permettant de compiler
//   le tout grace a la commande make 

// pour débuter, votre classe doit se trouver ici...
// class Couleur
// {
//   ...
// };

int main()
{
  cout << endl << "(1) ***** Test constructeur par defaut + Affiche *******************************************" << endl;
  {
    Couleur couleur;
    couleur.Affiche();
  } // La presence des accolades assure que le destructeur de Joueur sera appele --> a tracer !

  cout << endl << "(2) ***** Test des setters et getters ******************************************************" << endl;
  {
    Couleur couleur;
    couleur.setRouge(255);
    couleur.setVert(255);
    couleur.setBleu(0);
    couleur.setNom("jaune");
    couleur.Affiche();
    cout << "Rouge = " << couleur.getRouge() << endl;
    cout << "Vert = " << couleur.getVert() << endl;
    cout << "Bleu = " << couleur.getBleu() << endl;
    cout << "Nom = " << couleur.getNom() << endl;
  }

  cout << endl << "(3) ***** Test du constructeur d'initialisation complet ************************************" << endl;
  {
    Couleur couleur(0,128,255,"Bleu Mercenier");
    couleur.Affiche();
  }

  cout << endl << "(4) ***** Test du constructeur d'initialisation partiel ************************************" << endl;
  {
    Couleur couleur(30,250,5);
    couleur.Affiche();
    couleur.setNom("Vert grenouille");
    couleur.Affiche();
  }


  cout << endl << "(5) ***** Test du constructeur de copie ****************************************************" << endl;
  {
    Couleur couleur1(255,0,0,"rouge");
    cout << "couleur1 (AVANT) :" << endl;
    couleur1.Affiche();
    {   
      Couleur couleur2(couleur1);
      cout << "couleur2 :" << endl;
      couleur2.Affiche();
      cout << "--> on modifie la copie" << endl;
      couleur2.setBleu(255);
      couleur2.setNom("violet");
      couleur2.Affiche();
      cout << "--> on detruit la copie" << endl;
    } // de nouveau, les {} assurent que couleur2 sera detruit avant la suite
    cout << "couleur1 (APRES) :" << endl;
    couleur1.Affiche();
  }

  cout << endl << "(6) ***** Test d'allocation dynamique ******************************************************" << endl;
  {
    Couleur *p = new Couleur();
    p->Affiche();
    delete p;
    p = new Couleur(0,128,64);
    p->setNom("Vert cacadoie");
    p->Affiche();
    delete p;
  }

  return 0;
}


