#include "GrilleSDL.h"

////////////////////////////////////////////////////////////////////////////////////////
///// Structures et fonctions opaques //////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
  char        occupe;
  int         code;
  SDL_Surface *surface;
  int         largeur;     // largeur en pixels du sprite
  int         hauteur;     // hauteur en pixels du sprite
} SPRITE;

typedef struct
{
  SDL_Surface *ecran;
  SDL_Surface *fond;
  int         nbLignes;
  int         nbColonnes;
  int         tailleCarre;
  SPRITE      sprites[60];     // Maximum 60 sprites
  pthread_t   threadEventSDL;
  int         enVie;

  EVENT_GRILLE_SDL  event;
  pthread_mutex_t   mutexW;    // Mutex de gestion des evenements SDL
  pthread_mutex_t   mutexR;    // Mutex de gestion des evenements SDL

  pthread_mutex_t   mutexG;    // Acces concurrent a l'ecran
} GRILLE_SDL;

SDL_Surface* ChargeImage(const char *fichier);
SDL_Surface* ChargeImageAFondTransparent(const char *fichier,int Rf,int Gf,int Bf);
void* FctThreadEventSDL(void *);

GRILLE_SDL maGrille;

/////////////////////////////////////////////////////////////////////////////////////////
int OuvrirGrilleSDL(int nbLignes,int nbColonnes,int tailleCarre,const char* titreFenetre)
{
  int i;

  maGrille.ecran = NULL;
  maGrille.fond  = NULL;
  maGrille.nbLignes = nbLignes;
  maGrille.nbColonnes = nbColonnes;
  maGrille.tailleCarre = tailleCarre;
  maGrille.enVie = 0;

  // Initialisation du Module Video
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    return -1;
  
  // Definition de la fenetre
  if ((maGrille.ecran = SDL_SetVideoMode((nbColonnes*tailleCarre),(nbLignes*tailleCarre),32,SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return -2;

  // Titre de la Fenetre
  SDL_WM_SetCaption(titreFenetre, NULL);

  atexit(SDL_Quit); // Pour quitter proprement la SDL lors de l'exit 

  // Initialisation du vecteur de sprites
  for (i=0 ; i<60 ; i++)
  {
    maGrille.sprites[i].occupe = 0;
    maGrille.sprites[i].code = -1;
    maGrille.sprites[i].surface = NULL;
    maGrille.sprites[i].largeur = 0;
    maGrille.sprites[i].hauteur = 0;
  }

  // Initialisation des mutex
  pthread_mutex_init(&(maGrille.mutexW),NULL);
  pthread_mutex_init(&(maGrille.mutexR),NULL);
  pthread_mutex_init(&(maGrille.mutexG),NULL);

  // Mise en place d'un fond noir par defaut
  maGrille.enVie = 1;
  if (DessineCouleurFond(0,0,0) < 0)
  {
    maGrille.enVie = 0;
    return -3;
  }
  maGrille.enVie = 0;

  // Creation du threadEventSDL
  pthread_mutex_lock(&(maGrille.mutexR));
  if (pthread_create(&(maGrille.threadEventSDL),NULL,(void*(*)(void*))FctThreadEventSDL,(void*)NULL) != 0)
    return -4;

  maGrille.enVie = 1;

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int FermerGrilleSDL()
{
  int i;

  pthread_mutex_lock(&(maGrille.mutexG));

  // Liberation memoire pour les differents sprites
  for (i=0 ; i<60 ; i++)
    if (maGrille.sprites[i].occupe) SDL_FreeSurface(maGrille.sprites[i].surface);
  
  // Liberation memoire pour l'image de fond
  if (maGrille.fond != NULL) SDL_FreeSurface(maGrille.fond);

  maGrille.enVie = 0;
  pthread_cancel(maGrille.threadEventSDL);
  //pthread_join(maGrille.threadEventSDL,NULL);

  SDL_Quit();

  pthread_mutex_unlock(&(maGrille.mutexG));

  pthread_mutex_destroy(&(maGrille.mutexW));
  pthread_mutex_destroy(&(maGrille.mutexR));
  pthread_mutex_destroy(&(maGrille.mutexG));

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int DessineCouleurFond(int R,int G,int B)
{
  SDL_Rect offset,rect;

  if (R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
    return -1;

  pthread_mutex_lock(&(maGrille.mutexG));

  if (!maGrille.enVie)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -2;
  }

  // on alloue l'image de fond
  maGrille.fond = SDL_CreateRGBSurface(0,(maGrille.nbColonnes*maGrille.tailleCarre),(maGrille.nbLignes*maGrille.tailleCarre),32,0,0,0,0);

  if (maGrille.fond == NULL)
    return -3;
   
  // on peint l'image de fond avec la couleur voulue
  rect.x = 0;
  rect.y = 0;
  rect.w = maGrille.nbColonnes*maGrille.tailleCarre;
  rect.h = maGrille.nbLignes*maGrille.tailleCarre;

  if (SDL_FillRect(maGrille.fond,&rect,SDL_MapRGB((maGrille.fond)->format,R,G,B)) < 0)
    return -4;
   
  // On dessine l'image de fond sur l'ecran
  offset.x = 0;
  offset.y = 0;
  if (SDL_BlitSurface(maGrille.fond,NULL,maGrille.ecran,&offset) < 0)
    return -5;

  if (SDL_Flip(maGrille.ecran) < 0)
    return -6;
  
  pthread_mutex_unlock(&(maGrille.mutexG));
  
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int DessineImageFond(const char* nomFichier)
{
  SDL_Surface *image = NULL;
  SDL_Rect    offset;

  pthread_mutex_lock(&(maGrille.mutexG));

  if (!maGrille.enVie)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -1;
  }

  // On alloue l'image de fond
  maGrille.fond = SDL_CreateRGBSurface(0,(maGrille.nbColonnes*maGrille.tailleCarre),(maGrille.nbLignes*maGrille.tailleCarre),32,0,0,0,0);

  if (maGrille.fond == NULL)
    return -2;
   
  // On peint l'image de fond avec l'image chargee du fichier
  if ((image = ChargeImage(nomFichier)) == NULL)
    return -3;
    
  offset.x = 0;
  offset.y = 0;
  if (SDL_BlitSurface(image,NULL,maGrille.fond,&offset) < 0)
    return -4;
   
  // On dessine l'image de fond sur l'ecran
  offset.x = 0;
  offset.y = 0;
  if (SDL_BlitSurface(maGrille.fond,NULL,maGrille.ecran,&offset) < 0)
    return -5;

  if (SDL_Flip(maGrille.ecran) < 0)
    return -6;
  
  pthread_mutex_unlock(&(maGrille.mutexG));
  
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int DessineCarre(int L,int C,int R,int G,int B)
{
  SDL_Rect rect;

  if (L<0 || L>=maGrille.nbLignes || C<0 || C>=maGrille.nbColonnes)
    return -1;

  if (R<0 || R>255 || G<0 || G>255 || B<0 || B>255)
    return -2;

  rect.x = C*maGrille.tailleCarre;
  rect.y = L*maGrille.tailleCarre;
  rect.w = maGrille.tailleCarre;
  rect.h = maGrille.tailleCarre;
 
  pthread_mutex_lock(&(maGrille.mutexG));
  if (maGrille.enVie)
  {
    if (SDL_FillRect(maGrille.ecran,&rect,SDL_MapRGB((maGrille.ecran)->format,R,G,B)) < 0)
      return -3;
  
    SDL_UpdateRect(maGrille.ecran,rect.x,rect.y,rect.w,rect.h);
  }
  pthread_mutex_unlock(&(maGrille.mutexG));

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int EffaceCarre(int L,int C)
{
  SDL_Rect rect,offset;

  if (L<0 || L>=maGrille.nbLignes || C<0 || C>=maGrille.nbColonnes)
    return -1;

  rect.x = C*maGrille.tailleCarre;
  rect.y = L*maGrille.tailleCarre;
  rect.w = maGrille.tailleCarre;
  rect.h = maGrille.tailleCarre;

  offset.x = C * maGrille.tailleCarre;
  offset.y = L * maGrille.tailleCarre;
 
  pthread_mutex_lock(&(maGrille.mutexG));
  if (maGrille.enVie)
  {
    if (SDL_BlitSurface(maGrille.fond,&rect,maGrille.ecran,&offset) < 0)
      return -2;

    SDL_UpdateRect(maGrille.ecran,rect.x,rect.y,rect.w,rect.h);
  }
  pthread_mutex_unlock(&(maGrille.mutexG));

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int AjouteSprite(int code,const char* nomFichier)
{
  char trouve=0;
  int i=0;

  pthread_mutex_lock(&(maGrille.mutexG));

  if (!maGrille.enVie)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -1;
  }

  // Recherche de code dans vecteur pour voir si deja present
  while (i<60 && !trouve)
  {
    if (maGrille.sprites[i].occupe && (maGrille.sprites[i].code == code)) trouve = 1;
    else i++; 
  }

  if (!trouve)
  {
    // Recherche d'une case libre dans le vecteur
    i = 0;
    trouve = 0;
    while (i<60 && !trouve)
    {
      if (maGrille.sprites[i].occupe) i++;
      else trouve = 1; 
    }

    if (!trouve)
    {
      pthread_mutex_unlock(&(maGrille.mutexG));
      return -2;
    }
  }
  else
  {
    // On libere la memoire pour l'ancienne image
    SDL_FreeSurface(maGrille.sprites[i].surface);
    maGrille.sprites[i].surface = NULL;    
  }

  // Case trouvee dans le vecteur, on charge l'image
  if ((maGrille.sprites[i].surface = ChargeImage(nomFichier)) == NULL)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -3;
  }
  
  // Verification de sa taille par rapport à la grille
  if (((maGrille.sprites[i].surface->w % maGrille.tailleCarre) != 0) || ((maGrille.sprites[i].surface->h % maGrille.tailleCarre) != 0))
  {
    SDL_FreeSurface(maGrille.sprites[i].surface);
    maGrille.sprites[i].surface = NULL;
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -4;
  }

  // Taille correcte, on termine l'assignation dans le vecteur
  maGrille.sprites[i].occupe = 1;
  maGrille.sprites[i].code = code;
  maGrille.sprites[i].largeur = maGrille.sprites[i].surface->w;
  maGrille.sprites[i].hauteur = maGrille.sprites[i].surface->h;

  pthread_mutex_unlock(&(maGrille.mutexG));
  
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int AjouteSpriteAFondTransparent(int code,const char* nomFichier,int Rf,int Gf,int Bf)
{
  char trouve=0;
  int i=0;

  pthread_mutex_lock(&(maGrille.mutexG));

  if (!maGrille.enVie)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -1;
  }

  // Recherche de code dans vecteur pour voir si deja present
  while (i<60 && !trouve)
  {
    if (maGrille.sprites[i].occupe && (maGrille.sprites[i].code == code)) trouve = 1;
    else i++; 
  }

  if (!trouve)
  {
    // Recherche d'une case libre dans le vecteur
    i = 0;
    trouve = 0;
    while (i<60 && !trouve)
    {
      if (maGrille.sprites[i].occupe) i++;
      else trouve = 1; 
    }

    if (!trouve) 
    {
      pthread_mutex_unlock(&(maGrille.mutexG));
      return -2;
    }
  }
  else
  {
    // On libere la memoire pour l'ancienne image
    SDL_FreeSurface(maGrille.sprites[i].surface);
    maGrille.sprites[i].surface = NULL;    
  }

  // Case trouvee dans le vecteur, on charge l'image
  if ((maGrille.sprites[i].surface = ChargeImageAFondTransparent(nomFichier,Rf,Gf,Bf)) == NULL)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -3;
  }
  
  // Verification de sa taille par rapport à la grille
  if (((maGrille.sprites[i].surface->w % maGrille.tailleCarre) != 0) || ((maGrille.sprites[i].surface->h % maGrille.tailleCarre) != 0))
  {
    SDL_FreeSurface(maGrille.sprites[i].surface);
    maGrille.sprites[i].surface = NULL;
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -4;
  }

  // Taille correcte, on termine l'assignation dans le vecteur
  maGrille.sprites[i].occupe = 1;
  maGrille.sprites[i].code = code;
  maGrille.sprites[i].largeur = maGrille.sprites[i].surface->w;
  maGrille.sprites[i].hauteur = maGrille.sprites[i].surface->h;

  pthread_mutex_unlock(&(maGrille.mutexG));
  
  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
int DessineSprite(int L,int C,int code)
{
  SDL_Rect rect;
  int i;
  char trouve;

  if (L<0 || L>=maGrille.nbLignes || C<0 || C>=maGrille.nbColonnes)
    return -1;

  pthread_mutex_lock(&(maGrille.mutexG));

  if (!maGrille.enVie)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -2;
  }

  // Recherche du code dans le vecteur de sprites
  i = 0;
  trouve = 0;
  while (i<60 && !trouve)
  {
    if (maGrille.sprites[i].occupe && (maGrille.sprites[i].code == code)) trouve = 1;
    else i++;
  }
  if (!trouve)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -3;
  }

  // On blit la surface au bon endroit
  rect.x = C * maGrille.tailleCarre;
  rect.y = L * maGrille.tailleCarre;

  if (SDL_BlitSurface(maGrille.sprites[i].surface,NULL,maGrille.ecran,&rect) < 0)
  {
    pthread_mutex_unlock(&(maGrille.mutexG));
    return -4;
  }

  SDL_UpdateRect(maGrille.ecran,rect.x,rect.y,maGrille.sprites[i].largeur,maGrille.sprites[i].hauteur);

  pthread_mutex_unlock(&(maGrille.mutexG));

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
SDL_Surface* ChargeImage(const char *fichier) 
{
  // Surface tampon qui nous servira pour charger l'image 
  SDL_Surface* loadedImage = NULL; 

  // L'image optimisee qu'on va utiliser 
  SDL_Surface* optimizedImage = NULL;

  // Chargement de l'image
  loadedImage = SDL_LoadBMP(fichier);

  // Si le chargement se passe bien
  if(loadedImage != NULL) 
  { 
    // Création de l'image optimisée 
    optimizedImage = SDL_DisplayFormat(loadedImage); 
		
    // Libération de l'ancienne image
    SDL_FreeSurface(loadedImage); 
  }
	
  // On retourne l'image optimisée 
  return optimizedImage; 
}

/////////////////////////////////////////////////////////////////////////////////////////
SDL_Surface* ChargeImageAFondTransparent(const char *fichier,int Rf,int Gf,int Bf) 
{
  // Surface tampon qui nous servira pour charger l'image 
  SDL_Surface* loadedImage = NULL; 

  // L'image optimisee qu'on va utiliser 
  SDL_Surface* optimizedImage = NULL;

  // Chargement de l'image
  loadedImage = SDL_LoadBMP(fichier);

  // Si le chargement se passe bien
  if(loadedImage != NULL) 
  { 
    // Création de l'image optimisée 
    optimizedImage = SDL_DisplayFormat(loadedImage); 
		
    // Libération de l'ancienne image
    SDL_FreeSurface(loadedImage); 

    //Si l'image optimisée créée est bonne
    if(optimizedImage != NULL)
    {
      Uint32 colorkey = SDL_MapRGB(optimizedImage->format,Rf,Gf,Bf);

      //On met tous les pixels de couleur (Rf,Gf,Bf) transparents
      SDL_SetColorKey(optimizedImage,SDL_RLEACCEL | SDL_SRCCOLORKEY,colorkey);
    }
  }
	
  // On retourne l'image optimisée 
  return optimizedImage; 
}

/////////////////////////////////////////////////////////////////////////////////////////
EVENT_GRILLE_SDL ReadEvent()
{
  EVENT_GRILLE_SDL event;

  pthread_mutex_lock(&(maGrille.mutexR));
  event = maGrille.event;
  pthread_mutex_unlock(&(maGrille.mutexW));
  
  return event;
}

/////////////////////////////////////////////////////////////////////////////////////////
void* FctThreadEventSDL(void *p)
{
  SDL_Event event;
  sigset_t mask;

  sigfillset(&mask);
  sigprocmask(SIG_SETMASK,&mask,NULL);

  struct timespec temps;
  temps.tv_sec = 0;
  temps.tv_nsec = 10000000;

  while(maGrille.enVie)
  {
    // Tant qu'il y a un event
    while(SDL_PollEvent(&event))
    {
      //printf("Event\n"); fflush(stdout);

      // Clic sur le X de la fenêtre
      if(event.type == SDL_QUIT)
      {
        // Croix de fermeture de la fenetre
        pthread_mutex_lock(&(maGrille.mutexW));
        maGrille.event.type = CROIX;
        pthread_mutex_unlock(&(maGrille.mutexR));
      }

      if(event.type == SDL_KEYDOWN)
      {
        pthread_mutex_lock(&(maGrille.mutexW));
        maGrille.event.type = CLAVIER;

        switch(event.key.keysym.sym)
        {
          case SDLK_UP : // Touche HAUT
                         maGrille.event.touche = KEY_UP;
                         break;

          case SDLK_DOWN : // Touche BAS
                           maGrille.event.touche = KEY_DOWN;
                           break;

          case SDLK_LEFT : // Touche GAUCHE
                           maGrille.event.touche = KEY_LEFT;
                           break;

          case SDLK_RIGHT : // Touche DROITE
                            maGrille.event.touche = KEY_RIGHT;
                            break;

          case SDLK_SPACE : // Touche ESPACE enfoncee
                            maGrille.event.touche = KEY_SPACE;
                            break;

          default : // Autre touche enfoncee
                    maGrille.event.touche = event.key.keysym.sym;
        }
        pthread_mutex_unlock(&(maGrille.mutexR));
      }

      if (event.type == SDL_MOUSEBUTTONDOWN)
      {
        pthread_mutex_lock(&(maGrille.mutexW));
        if (event.button.button == SDL_BUTTON_RIGHT)
        {
          // Souris Bouton droit
          maGrille.event.type    = CLIC_DROIT;
          maGrille.event.ligne   = event.button.y / maGrille.tailleCarre;
          maGrille.event.colonne = event.button.x / maGrille.tailleCarre;
        }
        if (event.button.button == SDL_BUTTON_LEFT)
        {
          // Souris Bouton gauche
          maGrille.event.type    = CLIC_GAUCHE;
          maGrille.event.ligne   = event.button.y / maGrille.tailleCarre;
          maGrille.event.colonne = event.button.x / maGrille.tailleCarre;
        }
        pthread_mutex_unlock(&(maGrille.mutexR));
      }
    }

    nanosleep(&temps,NULL); // Pour eviter la boucle infinie...
  }  

  pthread_exit(NULL);
}
