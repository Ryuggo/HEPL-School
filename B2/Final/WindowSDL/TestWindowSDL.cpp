#include <iostream>
using namespace std;

#include "WindowSDL.h"

//************************************************************************************************
int main(int argc,char* argv[])
{
  cout << "Hello WindowSDL !" << endl;

  WindowSDL::open(800,600);

  WindowSDL::setBackground(0,128,200);
  WindowSDL::drawPixel(255,255,255,118,234);
  WindowSDL::drawLine(255,0,0,450,50,750,400);
  WindowSDL::fillRectangle(255,255,0,330,350,100,150);

  WindowSDLimage im;
  im.importFromBMP("boat.bmp");
  cout << "Largeur image = " << im.getWidth() << endl;
  cout << "Hauteur image = " << im.getHeight() << endl;
  WindowSDL::drawImage(im,50,80);

  cout << "Cliquez pour quitter..." << endl;
  WindowSDLclick clic = WindowSDL::waitClick();
  if (clic.getX() == -1) cout << "Clic sur la croix..." << endl;
  else cout << "Clic en (" << clic.getX() << "," << clic.getY() << ")" << endl;

  WindowSDL::close();

  return 0;
}


