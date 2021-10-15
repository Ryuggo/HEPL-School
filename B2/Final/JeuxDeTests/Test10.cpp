#include <stdlib.h>
#include <iostream>
using namespace std;

#include "WindowSDL.h"
#include "Bouton.h"
#include "BoutonCouleur.h"
#include "ToolBar.h"

int main()
{
  WindowSDL::open(840,600);
  WindowSDL::importFromBMP("../WindowSDL/imageFond.bmp");

  ToolBar toolbar;
  toolbar.ajouteBoutonFigure(Bouton("B_PIXEL",Point(0,0),Point(39,39)));
  toolbar.ajouteBoutonFigure(Bouton("B_LIGNE",Point(40,0),Point(79,39)));
  toolbar.ajouteBoutonFigure(Bouton("B_RECTANGLE_CREUX",Point(80,0),Point(119,39)));
  toolbar.ajouteBoutonFigure(Bouton("B_RECTANGLE_PLEIN",Point(120,0),Point(159,39)));

  toolbar.setBoutonUndo(Bouton("B_UNDO",Point(200,0),Point(239,39)));
  toolbar.setBoutonMenu(Bouton("B_MENU",Point(240,0),Point(279,39)));

  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR1",Point(320,0),Point(359,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR2",Point(360,0),Point(399,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR3",Point(400,0),Point(439,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR4",Point(440,0),Point(479,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR5",Point(480,0),Point(519,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR6",Point(520,0),Point(559,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR7",Point(560,0),Point(599,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR8",Point(600,0),Point(639,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR9",Point(640,0),Point(679,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR10",Point(680,0),Point(719,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR11",Point(720,0),Point(759,39)));
  toolbar.ajouteBoutonCouleur(BoutonCouleur("B_COULEUR12",Point(760,0),Point(799,39)));
  
  Couleur C1(Couleur::ROUGE), C2(Couleur::VERT), C3(Couleur::BLEU), C4(0,255,255);

  toolbar.ajouteCouleur(&C1);
  toolbar.ajouteCouleur(&C2);
  toolbar.ajouteCouleur(&C3);
  toolbar.ajouteCouleur(&C4);

toolbar.afficheFigures();
toolbar.afficheCouleur();

  cout << "Le BoutonCouleur B_COULEUR2 est associe a la couleur : " << *(toolbar.getNomCouleur("B_COULEUR2")) << endl;

  while (true)
  {
    WindowSDLclick clic = WindowSDL::waitClick();
    if (clic.getX() == -1) break;
    const char* nomBouton = toolbar.clic(clic.getX(),clic.getY());
    if (nomBouton) cout << "Bouton clique = " << nomBouton << endl;
    else cout << "Clic dans la zone de dessin..." << endl; 
  }

  cout << "Clic sur la croix..." << endl;
  WindowSDL::close();

  return 0;
}

