#ifndef WINDOW_SDL_H
#define WINDOW_SDL_H

#include <SDL/SDL.h>
#include <pthread.h>
#include "WindowSDLexception.h"
#include "WindowSDLimage.h"
#include "WindowSDLclick.h"

class WindowSDL
{
  private:
    static SDL_Surface      *screen;
    static int              width;
    static int              height;
    static pthread_t        threadEventSDL;
    static char             alive;
    static void*            FctThreadEventSDL(void *p);

    // Gestion du Click
    static WindowSDLclick   click;
    static char             clicked;
    static pthread_mutex_t  mutexClick;
    static pthread_cond_t   condClick;

  public:
    static void open(int w,int h) throw (WindowSDLexception);
    static char isAlive();
    static void close() throw (WindowSDLexception);
    static int  getWidth() throw (WindowSDLexception);
    static int  getHeight() throw (WindowSDLexception);

    // Primitives de dessin basiques
    static void setBackground(int R,int G,int B) throw (WindowSDLexception);
    static void drawPixel(int R,int G,int B,int x,int y) throw (WindowSDLexception);
    static void drawLine(int R,int G,int B,int x1,int y1, int x2,int y2) throw (WindowSDLexception);
    static void drawRectangle(int R,int G,int B,int x,int y,int w,int h) throw (WindowSDLexception);
    static void fillRectangle(int R,int G,int B,int x,int y,int w,int h) throw (WindowSDLexception);
    static void drawImage(const WindowSDLimage& image,int x,int y) throw (WindowSDLexception);

    // I/O avec les fichiers bitmap (*.bmp)
    static void exportToBMP(const char* nomFichier) throw (WindowSDLexception);
    static void importFromBMP(const char* nomFichier) throw (WindowSDLexception);

    // Interractions avec la fenetre
    static WindowSDLclick waitClick() throw (WindowSDLexception);
};

#endif


