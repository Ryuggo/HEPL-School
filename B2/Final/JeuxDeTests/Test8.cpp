#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Dessin.h"
#include "Pixel.h"
#include "Ligne.h"
#include "Rectangle.h"
#include "WindowSDL.h"

#include <math.h>
#include <unistd.h>

int main()
{
try{
  // Creation du dessin
  Dessin d(Couleur(0,0,0,"Noir"));
  
  // Ajout de couleurs à la palette
  d.ajouteCouleur(Couleur(255,255,0,"Jaune"));
  d.ajouteCouleur(Couleur(150,131,236,"Lavande"));
  d.ajouteCouleur(Couleur(248,152,85,"Saumon"));
  d.ajouteCouleur(Couleur(0,255,255,"Cyan"));
  d.ajouteCouleur(Couleur(112,141,35,"Olive"));
  d.ajouteCouleur(Couleur::ROUGE);
  d.ajouteCouleur(Couleur::BLEU);

  // Ajout de figures
  d.ajouteFigure(new Rectangle("R1",Point(20,20),400,300,true,NULL),"Lavande");
  d.ajouteFigure(new Rectangle("R2",Point(50,50),400,300,true,NULL),"Saumon");
  d.ajouteFigure(new Rectangle("R3",Point(80,80),400,300,true,NULL),"Jaune");
  d.ajouteFigure(new Rectangle("R7",Point(80,80),400,300,false,NULL),"Bleu");
  d.ajouteFigure(new Rectangle("R4",Point(110,110),400,300,true,NULL),"Olive");
  d.ajouteFigure(new Rectangle("R5",Point(140,140),400,300,true,NULL),"Lavande");
  d.ajouteFigure(new Rectangle("R8",Point(140,140),400,300,false,NULL),"Rouge");
  d.ajouteFigure(new Rectangle("R6",Point(170,170),400,300,true,NULL),"Cyan");
  d.ajouteFigure(new Rectangle("R9",Point(200,200),340,240,false,NULL),"Rouge");

  d.ajouteFigure(new Ligne("L1",Point(20,20),Point(170,170),NULL),"Rouge");  
  d.ajouteFigure(new Ligne("L2",Point(420,20),Point(570,170),NULL),"Rouge");
  d.ajouteFigure(new Ligne("L3",Point(20,320),Point(170,470),NULL),"Rouge");

  int nbPoints = 30;
  for (int i=0 ; i<nbPoints ; i++)
  {
    char id[4];
    sprintf(id,"L%d",4+i);
    float delta = (2.0*3.1416)/(float)nbPoints;
    int x1 = 370 + 70 * cos(i*delta);
    int y1 = 320 + 70 * sin(i*delta);
    int x2 = 370 + 70 * cos((i+1)*delta);
    int y2 = 320 + 70 * sin((i+1)*delta);
    d.ajouteFigure(new Ligne(id,Point(x1,y1),Point(x2,y2),NULL),"Bleu");
  }

  nbPoints = 30;
  for (int i=0 ; i<nbPoints ; i++)
  {
    char id[4];
    sprintf(id,"P%d",1+i);
    float delta = (2.0*3.1416)/(float)nbPoints;
    int x = 370 + 50 * cos(i*delta);
    int y = 320 + 50 * sin(i*delta);
    d.ajouteFigure(new Pixel(id,Point(x,y),NULL),"Rouge");
  }

  // Dessin dans la fenetre graphique
  WindowSDL::open(800,600);
  WindowSDL::setBackground(d.getFond().getRouge(),d.getFond().getVert(),d.getFond().getBleu());
  d.Dessine();

  d.affichePalette();
  d.afficheFigures();

  // undo plusieurs fois
  for(int i=0 ; i<10 ; i++)
  {
    cout << "Cliquez pour faire un undo..." << endl;
    WindowSDL::waitClick();

    d.undo();
    
    WindowSDL::setBackground(d.getFond().getRouge(),d.getFond().getVert(),d.getFond().getBleu());
    d.Dessine();
  }

  // Temporisation
  cout << "Cliquez pour quitter..." << endl;
  WindowSDL::waitClick();
  WindowSDL::close();
}
catch(WindowSDLexception f) {
	cerr << "ERREUR : " << f.getMessage() << endl;
}
catch(DessinException e) {
	e.Affiche();
}
catch(...) { }

  return 0;
}

