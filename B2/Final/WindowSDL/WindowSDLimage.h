#ifndef WINDOW_SDL_IMAGE_H
#define WINDOW_SDL_IMAGE_H

#include <SDL/SDL.h>
#include "WindowSDLexception.h"

class WindowSDL;

class WindowSDLimage
{
  private :
    SDL_Surface   *surface;

    SDL_Surface*  loadSurfaceFromBMP(const char *nomfichier) throw (WindowSDLexception);
    SDL_Surface*  copieSurface(SDL_Surface *surf);
    
  public:
    WindowSDLimage(void); // par defaut, une image 100x100 noire
    WindowSDLimage(int w,int h) throw (WindowSDLexception);
    WindowSDLimage(const char* nomFichier) throw (WindowSDLexception);
    WindowSDLimage(const WindowSDLimage &c);
    ~WindowSDLimage();

    int  getWidth() const;    // Largeur en pixels de l'image
    int  getHeight() const;   // Hauteur en pixels de l'image

    void importFromBMP(const char* nomFichier) throw (WindowSDLexception);
    void exportToBMP(const char* nf) throw (WindowSDLexception);

    void getPixel(int x,int y,int* pR,int* pG,int* pB) throw (WindowSDLexception);
    void setPixel(int x,int y,int r,int g,int b) throw (WindowSDLexception);

    WindowSDLimage& operator=(const WindowSDLimage& i);

    friend class WindowSDL;
};

#endif
