#include <iostream>
#include <fstream>
using namespace std;
#include <stdlib.h>

#include "Point.h"
#include "Couleur.h"
#include "Ligne.h"

int  Menu();
void Essai1();
void Essai2();
void Essai3();

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
      default : fini = true ; break;
    }
  }

  return 0;
}

int Menu()
{
  cout << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "--- JEU DE TEST 7 ---------------------------------------------------------" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << " 1. Test des methodes Save et Load de la classe Point" << endl;
  cout << " 2. Test des mathodes Save et Load de la classe Couleur" << endl;
  cout << " 3. Test des methodes Save et Load de la classe Ligne" << endl;
  cout << " 4. Quitter" << endl << endl;

  int ch;
  cout << "  Choix : ";
  cin >> ch; // Faites pas le biess !
  cin.ignore();
  return ch;
}

//*********************************************************************************************
void Essai1()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 1. Test des methodes Save et Load de la classe Point ------" << endl;
  
  Point p1(250,370);
  cout << "p1 = " << p1 << endl;
  cout << endl;

  cout << "----- Sauvegarde du point dans le fichier P.dat -----" << endl;
  ofstream fichier1("P.dat",ios::out);
  p1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement du point situe dans le fichier P.dat -----" << endl;
  ifstream fichier2("P.dat",ios::in);
  Point p2;
  p2.Load(fichier2);
  fichier2.close();
  cout << "p2 = " << p2 << endl;
  cout << endl;
}

//*********************************************************************************************
void Essai2()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 2. Test des methodes Save et Load de la classe Couleur ------" << endl;
  
  Couleur c1(112,141,35,"Olive");
  cout << "c1 = " << c1 << endl;
  cout << endl;

  cout << "----- Sauvegarde de la couleur dans le fichier C.dat -----" << endl;
  ofstream fichier1("C.dat",ios::out);
  c1.Save(fichier1);
  fichier1.close();

  cout << "----- Chargement de la couleur situee dans le fichier C.dat -----" << endl;
  ifstream fichier2("C.dat",ios::in);
  Couleur c2;
  c2.Load(fichier2);
  fichier2.close();
  cout << "c2 = " << c2 << endl;
  cout << endl;
}

//*********************************************************************************************
void Essai3()  // Attention : utilisez les flux bytes (read et write) !!!!
{
  cout << "----- 3. Test des methodes Save et Load de la classe Ligne ------" << endl;

  Ligne l1("L25",Point(30,90),Point(200,90),&Couleur::ROUGE);
  cout << "l1 : " << l1 << endl;

  cout << "----- Sauvegarde de la ligne dans le fichier L.dat -----" << endl;
  ofstream fichier1("L.dat",ios::out);
  l1.Save(fichier1);
  // Attention ! A terme, la classe Ligne ne devra pas enregistrer l'objet Couleur sur disque, 
  // mais bien son nom (identifiant unique de la couleur dans l'application finale)
  fichier1.close();

  cout << "----- Chargement de la ligne situee dans le fichier L.dat -----" << endl;
  ifstream fichier2("L.dat",ios::in);
  Ligne l2;
  l2.Load(fichier2);
  fichier2.close();
  cout << "l2 : " << l2 << endl;
  cout << endl;
}


