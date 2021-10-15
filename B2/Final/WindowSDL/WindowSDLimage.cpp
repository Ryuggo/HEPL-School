#include "WindowSDLimage.h"

//***************************************************************************
//********** Constructeurs **************************************************
//***************************************************************************
WindowSDLimage::WindowSDLimage(void)
{
  surface = SDL_CreateRGBSurface(0,100,100,32,0,0,0,0);
}

WindowSDLimage::WindowSDLimage(int w,int h) throw (WindowSDLexception)
{
  if (w < 1 || h < 1)
    throw WindowSDLexception("Dimension(s) invalide(s) !");
    
  surface = SDL_CreateRGBSurface(0,w,h,32,0,0,0,0);
}

WindowSDLimage::WindowSDLimage(const char* nf) throw (WindowSDLexception)
{
  surface = loadSurfaceFromBMP(nf);
}

WindowSDLimage::WindowSDLimage(const WindowSDLimage &i)
{
  if (i.surface != NULL) surface = copieSurface(i.surface);
  else surface = NULL;
}

//***************************************************************************
//********** Desctructeur ***************************************************
//***************************************************************************
WindowSDLimage::~WindowSDLimage() 
{ 
  // On libere la memoire de l'image
  if (surface) SDL_FreeSurface(surface); 
}

//***************************************************************************
//********** SETTERS ********************************************************
//***************************************************************************

//***************************************************************************
//********** GETTERS ********************************************************
//***************************************************************************
int WindowSDLimage::getWidth() const { return surface->w; }
int WindowSDLimage::getHeight() const { return surface->h; }

//***************************************************************************
//********** Methodes d'instance ********************************************
//***************************************************************************
void WindowSDLimage::importFromBMP(const char* nf) throw (WindowSDLexception)
{
  SDL_Surface* tmp = loadSurfaceFromBMP(nf);
  SDL_FreeSurface(surface);
  surface = tmp;
}

void WindowSDLimage::exportToBMP(const char* nf) throw (WindowSDLexception)
{
  if (SDL_SaveBMP(surface,nf) < 0)
    throw WindowSDLexception("Erreur de SDL_SaveBMP");
}

//***************************************************************************
SDL_Surface* WindowSDLimage::loadSurfaceFromBMP(const char *nf) throw (WindowSDLexception)
{
  SDL_Surface* loadedImage = SDL_LoadBMP(nf);

  if(loadedImage == NULL)
    throw WindowSDLexception("Nom de fichier image BMP incorrect !");

  return loadedImage; 
}

//***************************************************************************
SDL_Surface* WindowSDLimage::copieSurface(SDL_Surface *surf)
{
  SDL_Surface *res;
  res = SDL_CreateRGBSurface(surf->flags, surf->w, surf->h, 
                      surf->format->BitsPerPixel, surf->format->Rmask,
                      surf->format->Gmask, surf->format->Bmask,
                      surf->format->Amask);
  if(res != NULL) 
     SDL_BlitSurface(surf, NULL, res, NULL);
  
  return res;
}

//***************************************************************************
void WindowSDLimage::getPixel(int x,int y,int* pR,int* pG,int* pB) throw (WindowSDLexception)
{
  if (pR == NULL || pG == NULL || pB == NULL)
    throw WindowSDLexception("Adresse(s) non valide !!!");

  if (x<0 || x>=surface->w || y<0 || y>=surface->h)
    throw WindowSDLexception("Coordonnee(s) pixel non valide !!!");

  Uint8 r,g,b;
  Uint32 pixel = *((Uint32*)((Uint8*)surface->pixels + y*surface->pitch + x*3));
  SDL_LockSurface(surface);
  SDL_GetRGB(pixel,surface->format,&r,&g,&b);
  SDL_UnlockSurface(surface);

  *pR = r;
  *pG = g;
  *pB = b;
}

//***************************************************************************
void WindowSDLimage::setPixel(int x,int y,int r,int g,int b) throw (WindowSDLexception)
{
  if (r<0 || r>255 || g<0 || g>255 || b<0 || b>255)
    throw WindowSDLexception("Composante(s) RGB non valide(s) !!!");

  if (x<0 || x>=surface->w || y<0 || y>=surface->h)
    throw WindowSDLexception("Coordonnee(s) pixel non valide(s) !!!");

  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = 1;
  rect.h = 1;
  SDL_LockSurface(surface);
  SDL_FillRect(surface,&rect,SDL_MapRGB((surface)->format,r,g,b));
  SDL_UnlockSurface(surface);
}

//***************************************************************************
//********** Surcharges d'operateurs ****************************************
//***************************************************************************
WindowSDLimage& WindowSDLimage::operator=(const WindowSDLimage& i)
{
  // On libere la memoire de l'image
  SDL_FreeSurface(surface); 

  // copie de l'image
  if (i.surface != NULL) surface = copieSurface(i.surface);
  else surface = NULL;  

  return *this;
}

