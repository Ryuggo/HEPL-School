#include <stdlib.h>
#include <iostream>
using namespace std;

#include "WindowSDL.h"
#include "Bouton.h"
#include "BoutonCouleur.h"
#include "ToolBar.h"
#include "Dessin.h"
#include "Pixel.h"
#include "Ligne.h"
#include "Rectangle.h"

void InitGUI(ToolBar &toolbar);

int main()
{
  ToolBar toolbar;
  InitGUI(toolbar);

  Dessin* dessin = new Dessin();
  toolbar.ajouteCouleur(dessin->ajouteCouleur(Couleur::ROUGE));  // pour l'instant...
  toolbar.ajouteCouleur(dessin->ajouteCouleur(Couleur::VERT));   // pour l'instant...
  toolbar.ajouteCouleur(dessin->ajouteCouleur(Couleur::BLEU));   // pour l'instant...

  const char* figure = NULL;   // outil de dessin selectionne
  Couleur*    couleur = NULL;  // couleur selectionnee

  while (true)
  {
    WindowSDLclick clic = WindowSDL::waitClick();
    if (clic.getX() == -1) break;

    const char* nomBouton = toolbar.clic(clic.getX(),clic.getY());
    if (nomBouton) // clic sur un bouton
    {
      cout << "Bouton clique = " << nomBouton << endl;

      // Bouton Undo
      if (strcmp(nomBouton,"B_UNDO") == 0)
      {
        dessin->undo();
        dessin->Dessine();
      }

      // Bouton Menu
      // ... a faire

      continue;
    }
    // Clic dans la zone de dessin
    figure = toolbar.getFigureSelectionnee();
    if (figure == NULL)  { cout << "Vous devez selectionner un outil de dessin !" << endl; continue; }
    couleur = toolbar.getCouleurSelectionnee();
    if (couleur == NULL) { cout << "Vous devez selectionner une couleur !" << endl; continue; }
    
    if(clic.getY() >= 40) {
		if (strcmp(figure,"B_PIXEL") == 0)
		{
		  cout << "Dessin d'un PIXEL ok" << endl;
		  dessin->ajouteFigure(new Pixel("P1",Point(clic.getX(),clic.getY()),NULL),couleur->getNom());
		  dessin->Dessine();
		}

		if (strcmp(figure,"B_LIGNE") == 0)
		{
		  cout << "Dessin d'une ligne... cliquez sur l'extremite !" << endl;
		  WindowSDLclick clic2 = WindowSDL::waitClick();
		  if(clic2.getY() >= 40) {
			  dessin->ajouteFigure(new Ligne("L1",Point(clic.getX(),clic.getY()),Point(clic2.getX(),clic2.getY()),NULL),couleur->getNom());
			  dessin->Dessine();
			  cout << "Dessin d'une LIGNE ok" << endl;
		  } else
			  cout << "Vous ne pouvez pas dessiner dans le Menu" << endl;
		}

		if (strcmp(figure,"B_RECTANGLE_CREUX") == 0)
		{
		  cout << "Dessin d'un rectangle creux... cliquez sur l'autre coin !" << endl;
		  WindowSDLclick clic2 = WindowSDL::waitClick();
		  if(clic2.getY() >= 40) {
			  int largeur = clic2.getX() - clic.getX();
			  int hauteur = clic2.getY() - clic.getY();
			  dessin->ajouteFigure(new Rectangle("R1",Point(clic.getX(),clic.getY()),largeur,hauteur,false,NULL),couleur->getNom());
			  dessin->Dessine();
			  cout << "Dessin d'un RECTANGLE CREUX ok" << endl;
		  } else
			  cout << "Vous ne pouvez pas dessiner dans le Menu" << endl;
		}

		if (strcmp(figure,"B_RECTANGLE_PLEIN") == 0)
		{
		  cout << "Dessin d'un rectangle plein... cliquez sur l'autre coin !" << endl;
		  WindowSDLclick clic2 = WindowSDL::waitClick();
		  if(clic2.getY() >= 40) {
			  int largeur = clic2.getX() - clic.getX();
			  int hauteur = clic2.getY() - clic.getY();
			  dessin->ajouteFigure(new Rectangle("R1",Point(clic.getX(),clic.getY()),largeur,hauteur,true,NULL),couleur->getNom());
			  dessin->Dessine();
			  cout << "Dessin d'un RECTANGLE PLEIN ok" << endl;
		  } else
			  cout << "Vous ne pouvez pas dessiner dans le Menu" << endl;
		}
	} else
		cout << "Vous ne pouvez pas dessiner dans le Menu" << endl;
  }

  cout << "Fin de l'application..." << endl;
  WindowSDL::close();

  return 0;
}

void InitGUI(ToolBar &toolbar)
{
  WindowSDL::open(840,600);
  WindowSDL::importFromBMP("../WindowSDL/imageFond.bmp");

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
}

