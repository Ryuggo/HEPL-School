#include "WindowSDL.h"

#include <iostream>
using namespace std;

#include <signal.h>

/////////////////////////////////////////////////////////////////////////////////////////
char          WindowSDL::alive = 0;
SDL_Surface*  WindowSDL::screen = NULL;
int           WindowSDL::width = 800;
int           WindowSDL::height = 600;
pthread_t     WindowSDL::threadEventSDL = 0;

WindowSDLclick   WindowSDL::click;
char             WindowSDL::clicked = 0;
pthread_mutex_t  WindowSDL::mutexClick;
pthread_cond_t   WindowSDL::condClick;

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::open(int w,int h) throw (WindowSDLexception)
{
  if (alive)
    throw WindowSDLexception("WindowSDL deja ouverte !!!");

  // Initialisation du Module Video
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    throw WindowSDLexception("Erreur de SDL_Init");
  
  // Definition de la fenetre
  if ((screen = SDL_SetVideoMode(w,h,32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    throw WindowSDLexception("Erreur de SDL_SetVideoMode");

  // Titre de la Fenetre
  SDL_WM_SetCaption("WindowSDL",NULL);

  atexit(SDL_Quit); // Pour quitter proprement la SDL lors de l'exit

  pthread_mutex_init(&mutexClick,NULL);
  pthread_cond_init(&condClick,NULL);
  if (pthread_create(&threadEventSDL,NULL,FctThreadEventSDL,(void*)NULL) != 0)
    throw WindowSDLexception("Erreur de creation du threadEventSDL");

  width = w;
  height = h;
  alive = 1; 
}

/////////////////////////////////////////////////////////////////////////////////////////
char WindowSDL::isAlive()
{
  return alive;
}

/////////////////////////////////////////////////////////////////////////////////////////
int WindowSDL::getWidth() throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  return width;
}

/////////////////////////////////////////////////////////////////////////////////////////
int WindowSDL::getHeight() throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  return height;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::close() throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");
  alive = 0;
  screen = NULL;
  pthread_cancel(threadEventSDL);
  threadEventSDL = 0;
  SDL_Quit();
}

/////////////////////////////////////////////////////////////////////////////////////////
void* WindowSDL::FctThreadEventSDL(void *p)
{
  SDL_Event event;
  sigset_t mask;

  sigfillset(&mask);
  sigprocmask(SIG_SETMASK,&mask,NULL);

  while(1)
  { 
    SDL_WaitEvent(&event); 

    if(event.type == SDL_QUIT)
    {
      pthread_mutex_lock(&mutexClick);
      click.setX(-1);
      click.setY(-1);
      clicked = 1;
      pthread_mutex_unlock(&mutexClick);
      pthread_cond_signal(&condClick);
    }

    if (event.type == SDL_MOUSEBUTTONUP)
    {
      if (event.button.button == SDL_BUTTON_LEFT)
      {
        pthread_mutex_lock(&mutexClick);
        click.setX(event.button.x);
        click.setY(event.button.y);
        clicked = 1;
        pthread_mutex_unlock(&mutexClick);
        pthread_cond_signal(&condClick);
      }
    }

  }

  pthread_exit(NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::setBackground(int R,int G,int B) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  if (R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
    throw WindowSDLexception("Couleur invalide !!!");

  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = width;
  rect.h = height;
 
  if (SDL_FillRect(screen,&rect,SDL_MapRGB((screen)->format,R,G,B)) < 0)
    throw WindowSDLexception("Erreur de SDL_FillRect");
  
  SDL_UpdateRect(screen,rect.x,rect.y,rect.w,rect.h);

  return;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::fillRectangle(int R,int G,int B,int x,int y,int w,int h) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  SDL_Rect rect;

  if (R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
    throw WindowSDLexception("Couleur invalide !!!");

  if (w >= 0)
  {
    rect.x = x;
    rect.w = w;
  }
  else 
  {
    rect.x = x + w + 1;
    rect.w = -w;
  }
  if (h >= 0)
  {
    rect.y = y;
    rect.h = h;
  }
  else 
  {
    rect.y = y + h + 1;
    rect.h = -h;
  }

  if (SDL_FillRect(screen,&rect,SDL_MapRGB((screen)->format,R,G,B)) < 0)
    throw WindowSDLexception("Erreur de SDL_FillRect");
  
  SDL_UpdateRect(screen,rect.x,rect.y,rect.w,rect.h);

  return;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawPixel(int R,int G,int B,int x,int y) throw (WindowSDLexception)
{
  if (x<0 || x>=width || y<0 || y>=height)
    return; 

  fillRectangle(R,G,B,x,y,1,1);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawLine(int R,int G,int B,int x1,int y1, int x2,int y2) throw (WindowSDLexception)
{ // Bresenham
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  int x,y;
  int Dx,Dy;
  int xincr,yincr;
  int erreur;
  int i;

  Dx = abs(x2-x1);
  Dy = abs(y2-y1);
  if(x1<x2) xincr = 1;
  else xincr = -1;
  if(y1<y2) yincr = 1;
  else yincr = -1;

  x = x1;
  y = y1;
  if(Dx>Dy)
  {
    erreur = Dx/2;
    for(i=0;i<Dx;i++)
    {
      x += xincr;
      erreur += Dy;
      if(erreur>Dx)
      {
        erreur -= Dx;
        y += yincr;
      }
      drawPixel(R,G,B,x,y);
    }
  }
  else
  {
    erreur = Dy/2;
    for(i=0;i<Dy;i++)
    {
      y += yincr;
      erreur += Dx;
      if(erreur>Dy)
      {
        erreur -= Dy;
        x += xincr;
      }
      drawPixel(R,G,B,x,y);
    }
  }
  drawPixel(R,G,B,x1,y1);
  drawPixel(R,G,B,x2,y2);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawRectangle(int R,int G,int B,int x,int y,int w,int h) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  drawLine(R,G,B,x,y,x+w,y);
  drawLine(R,G,B,x+w,y,x+w,y+h);
  drawLine(R,G,B,x+w,y+h,x,y+h);
  drawLine(R,G,B,x,y+h,x,y);
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::drawImage(const WindowSDLimage& image,int x,int y) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  if ((x < 0) || (y < 0) || (x+image.getWidth() > width) || (y+image.getHeight() > height))
    throw WindowSDLexception("Image sort de la fenetre !!!");

  if (image.surface == NULL)
    throw WindowSDLexception("Image non definie !!!");

  // On blit la surface au bon endroit
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;

  if (SDL_BlitSurface(image.surface,NULL,screen,&rect) < 0) // Friend ??? TO DO
      throw WindowSDLexception("Erreur de SDL_BlitSurface");

  SDL_UpdateRect(screen,rect.x,rect.y,image.getWidth(),image.getHeight());
  return;
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::exportToBMP(const char* nomFichier) throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  if (SDL_SaveBMP(screen,nomFichier) < 0)
    throw WindowSDLexception("Erreur de SDL_SaveBMP");
}

/////////////////////////////////////////////////////////////////////////////////////////
void WindowSDL::importFromBMP(const char* nomFichier) throw (WindowSDLexception)
{
  SDL_Surface* loadedImage = NULL; 

  if((loadedImage = SDL_LoadBMP(nomFichier)) == NULL)
    throw WindowSDLexception("Erreur de SDL_LoadBMP");

  if (alive) close();
  open(loadedImage->w,loadedImage->h);

  // On blit la surface loadee dans la fenetre
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;

  if (SDL_BlitSurface(loadedImage,NULL,screen,&rect) < 0)
      throw WindowSDLexception("Erreur de SDL_BlitSurface");

  SDL_UpdateRect(screen,rect.x,rect.y,loadedImage->w,loadedImage->h);
}

/////////////////////////////////////////////////////////////////////////////////////////
WindowSDLclick WindowSDL::waitClick() throw (WindowSDLexception)
{
  if (!alive)
    throw WindowSDLexception("WindowSDL non ouverte !!!");

  WindowSDLclick c;

  pthread_mutex_lock(&mutexClick);
  clicked = 0;
  while (!clicked)
    pthread_cond_wait(&condClick,&mutexClick);
  if (!alive)
  {
    pthread_mutex_unlock(&mutexClick); 
    throw WindowSDLexception("WindowSDL non ouverte !!!");
  }
  c = click;
  pthread_mutex_unlock(&mutexClick);

  return c;
}



