#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include "GrilleSDL.h"
#include "Ressources.h"

// Dimensions de la grille de jeu
#define NB_LIGNES   12
#define NB_COLONNES 19

// Nombre de cases maximum par piece
#define NB_CASES    4

// Macros utilisees dans le tableau tab
#define VIDE        0
#define BRIQUE      1
#define DIAMANT     2

int tab[NB_LIGNES][NB_COLONNES]
={ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

typedef struct {
  int ligne;
  int colonne;
} CASE;

typedef struct {
  CASE cases[NB_CASES];
  int  nbCases;
  int  couleur;
} PIECE;

PIECE pieces[12] = { 0,0,0,1,1,0,1,1,4,0,       // carre 4
                     0,0,1,0,2,0,2,1,4,0,       // L 4
                     0,1,1,1,2,0,2,1,4,0,       // J 4
                     0,0,0,1,1,1,1,2,4,0,       // Z 4
                     0,1,0,2,1,0,1,1,4,0,       // S 4
                     0,0,0,1,0,2,1,1,4,0,       // T 4
                     0,0,0,1,0,2,0,3,4,0,       // I 4
                     0,0,0,1,0,2,0,0,3,0,       // I 3
                     0,1,1,0,1,1,0,0,3,0,       // J 3
                     0,0,1,0,1,1,0,0,3,0,       // L 3
                     0,0,0,1,0,0,0,0,2,0,       // I 2
                     0,0,0,0,0,0,0,0,1,0 };     // carre 1

int  CompareCases(CASE case1,CASE case2);
void TriCases(CASE *vecteur,int indiceDebut,int indiceFin);

struct sigaction A;

// Etape 1 : ThreadDefileMessage
char* message;		// pointeur vers le message à faire défiler
int tailleMessage;	// longueur du message
int indiceCourant;	// indice du premier caractère à afficher dans la zone graphique

pthread_mutex_t mutDefileMessage;

void* threadDefileMessage(void*);
void setMessage(const char*, bool);
void HandlerALRM(int);


// Etape 2 : ThreadPiece
PIECE pieceEnCours;
CASE casesInserees[NB_CASES]; // cases insérées par le joueur
int nbCasesInserees; // nombre de cases actuellement insérées par le joueur

pthread_cond_t condCasesInserees;
pthread_mutex_t mutCasesInserees;

void* threadPiece(void*);
void RotationPiece(PIECE*);
void OriginPiece(CASE*, int);


// Etape 3 : ThreadEvent
void* threadEvent(void*);


// Etape 4 : ThreadScore
int score;
bool MAJScore;

pthread_cond_t condScore;
pthread_mutex_t mutScore;

void* threadScore(void*);


// Etape 5 : ThreadCases
CASE CaseParam;
pthread_key_t cleCases;

int lignesCompletes[NB_CASES];
int nbLignesCompletes;
int colonnesCompletes[NB_CASES];
int nbColonnesCompletes;
int carresComplets[NB_CASES];
int nbCarresComplets;
int nbAnalyses;

pthread_t tabThreadCase[14][10];
pthread_mutex_t mutAnalyse;

void* threadCase(void*);
void initCleCases();
void HandlerUSR1(int);


// Etape 6 : ThreadNettoyeur
int combos;
bool MAJCombos;

pthread_cond_t condAnalyse;

void* threadNettoyeur(void*);


// Etape 7 : Synchronisation Générale du Traitement
bool traitementEnCours;

pthread_cond_t condTraitement;
pthread_mutex_t mutTraitement;


// Etape 8 : Synchronisation du Thread Principal
bool quit = false;
int cheat = 12;
int style = 0;

bool TabFit(int, int);
void destructeur(void*);


///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc,char* argv[]) {
	EVENT_GRILLE_SDL event;

	srand((unsigned)time(NULL));
	struct timespec time;
   time.tv_sec = 2;
 	time.tv_nsec = 0;

// Ouverture de la fenetre graphique
	printf("(MAIN %d) Ouverture de la fenetre graphique\n",pthread_self());
	fflush(stdout);
	if (OuvertureFenetreGraphique() < 0) {
		printf("Erreur de OuvrirGrilleSDL\n");
		fflush(stdout);
		exit(1);
	}
  
printf("Mutex Init\n\n");
	pthread_mutex_init(&mutDefileMessage, NULL);
	pthread_mutex_init(&mutCasesInserees, NULL);
	pthread_mutex_init(&mutScore, NULL);
	pthread_mutex_init(&mutAnalyse, NULL);
  
  
printf("Etape 1\n\n");
// Armement du signal SIGALRM pour tous les threads
	A.sa_handler = HandlerALRM;
	A.sa_flags = 0;
	sigemptyset(&A.sa_mask);
	sigaction(SIGALRM, &A, NULL);
	
// Thread DefileMessge
	pthread_t tidDefileMessage;
	pthread_create(&tidDefileMessage, NULL, threadDefileMessage, NULL);

// Masquage du signal SIGALRM pour le thread principal/ main
	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask, SIGALRM);
	sigprocmask(SIG_SETMASK, &mask, NULL);
	
	
	setMessage("Bienvenue dans Blockudoku", true);
	
	
// Etape 3 avant la 2 -> Permet d'activer la triche avant que ça commence
printf("Etape 3\n\n");
	pthread_t tidEvent;
	pthread_create(&tidEvent, NULL, threadEvent, NULL);
	DessineVoyant(8, 10, BLEU);
	
	nanosleep(&time, NULL);
	if(style != 1)
		style = -1;
	
	
printf("Etape 2\n\n");
	pthread_t tidPiece;
	pthread_create(&tidPiece, NULL, threadPiece, NULL);
	
	
	
printf("Etape 4\n\n");
	pthread_t tidScore;
	pthread_create(&tidScore, NULL, threadScore, NULL);
	
	
	
printf("Etape 5\n\n");
// Armement du signal SIGUSR1 pour tous les threads
	A.sa_handler = HandlerUSR1;
	A.sa_flags = 0;
	sigemptyset(&A.sa_mask);
	sigaction(SIGUSR1, &A, NULL);
	
	
// Thread Cases
	pthread_key_create(&cleCases, destructeur);
	
	CASE* caseTmp = NULL;
	for(int L = 0; L < 9; L++)
		for(int C = 0; C < 9; C++) {
			caseTmp = new CASE;
			
			caseTmp->ligne = L;
			caseTmp->colonne = C;
			
			pthread_create(&tabThreadCase[L][C], NULL, threadCase, (CASE*)caseTmp);
		}
	
// Masquage du signal SIGUSR1 pour le thread principal/ main
	sigaddset(&mask, SIGUSR1);
	sigprocmask(SIG_SETMASK, &mask, NULL);
	
	
	
printf("Etape 6\n\n");
pthread_mutex_lock(&mutScore);					/* --- LOCK --- */
	combos = 0;
pthread_mutex_unlock(&mutScore);					/* --- UNLOCK --- */
	pthread_t tidNettoyeur;
	pthread_create(&tidNettoyeur, NULL, threadNettoyeur, NULL);
	
	
	
printf("Etape 8\n\n");
	pthread_join(tidPiece, NULL);
	DessineVoyant(8, 10, ROUGE);
	pthread_cancel(tidEvent);
	for(int L = 0; L < 9; L++)
		for(int C = 0; C < 9; C++)
			pthread_cancel(tabThreadCase[L][C]);
	
	
printf("Waiting to stop\n\n");
	if(!quit)
		do {
			event = ReadEvent();
		}while(event.type != CROIX);
	printf("(MAIN %d) Fermeture de la fenetre graphique...",pthread_self());
	fflush(stdout);
	FermetureFenetreGraphique();
	printf("OK\n");
	
	pthread_cancel(tidDefileMessage);

	exit(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
int CompareCases(CASE case1,CASE case2) {
  if (case1.ligne < case2.ligne) return -1;
  if (case1.ligne > case2.ligne) return +1;
  if (case1.colonne < case2.colonne) return -1;
  if (case1.colonne > case2.colonne) return +1;
  return 0;
}

void TriCases(CASE *vecteur,int indiceDebut,int indiceFin)
{ // trie les cases de vecteur entre les indices indiceDebut et indiceFin compris
  // selon le critere impose par la fonction CompareCases()
  // Exemple : pour trier un vecteur v de 4 cases, il faut appeler TriCases(v,0,3); 
  int  i,iMin;
  CASE tmp;

  if (indiceDebut >= indiceFin) return;

  // Recherche du minimum
  iMin = indiceDebut;
  for (i=indiceDebut ; i<=indiceFin ; i++)
    if (CompareCases(vecteur[i],vecteur[iMin]) < 0) iMin = i;

  // On place le minimum a l'indiceDebut par permutation
  tmp = vecteur[indiceDebut];
  vecteur[indiceDebut] = vecteur[iMin];
  vecteur[iMin] = tmp;

  // Tri du reste du vecteur par recursivite
  TriCases(vecteur,indiceDebut+1,indiceFin); 
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 1

void* threadDefileMessage(void* f) {
	pthread_cleanup_push((void(*)(void*))free, message);
	
	
	struct timespec time;
   time.tv_sec = 0;
 	time.tv_nsec = 400000000;
	
	
pthread_mutex_lock(&mutDefileMessage);			/* --- LOCK --- */
	int j = 2, k = -1;
	char buffer[40];
	strcpy(buffer, message);
	int taille = tailleMessage, taille2 = tailleMessage;
	int indiceC2 = indiceCourant;
pthread_mutex_unlock(&mutDefileMessage);		/* --- UNLOCK --- */
	char buffer2[40];
	strcpy(buffer2, buffer);
	int indiceC = 0;

	for(int i = 1; i < 18; i++)
		DessineLettre(10, i, ' ');
 	
//Looping Messages
 	while(1) {
		for(int i = 0; j+i < 18 && -1 < j && indiceC+i-1 < taille; i++)
			DessineLettre(10, j+i, buffer[indiceC+i]);
		for(int i = 0; k+i < 18 && -1 < k && indiceC2+i-1 < taille2; i++)
			DessineLettre(10, k+i, buffer2[indiceC2+i]);
		
		
		if(j == 1) {
			if(indiceC < taille)
				indiceC++;
			else
				j = -1;
		} else
			j--;
		if(k == 1) {
			if(indiceC2 < taille2)
				indiceC2++;
			else
				k = -1;
		} else
			k--;
		
		
		if(taille2 - indiceC2 == 9) {
			indiceC = 0;
			j = 17;
		}
		if(taille - indiceC == 9) {
			indiceC2 = 0;
			k = 17;
		}
		

// Update Messages
pthread_mutex_lock(&mutDefileMessage);			/* --- LOCK --- */
		if(j == -1) {
			for(int i = 0; i < 40; i++)
				buffer[i] = '\0';
			strcpy(buffer, message);
			taille = tailleMessage;
		}
		if(k == -1) {
			for(int i = 0; i < 40; i++)
				buffer2[i] = '\0';
			strcpy(buffer2, message);
			taille2 = tailleMessage;
		}
pthread_mutex_unlock(&mutDefileMessage);		/* --- UNLOCK --- */
		
	 	nanosleep(&time, NULL);
 	}
	pthread_cleanup_pop(1);
	pthread_exit(NULL);
}

//////////////////////////////////////////////////
void setMessage(const char *texte,bool signalOn) {
	char buffer[40];
	strcpy(buffer, texte);
	
	
pthread_mutex_lock(&mutDefileMessage);			/* --- LOCK --- */
	
//	indiceCourant = 0;
	tailleMessage = strlen(buffer);
	int i = tailleMessage;
	if(i < 17) {
		buffer[i] = ' ';
		buffer[i+1] = '\0';
		tailleMessage = i+1;
	}
	
	if(message != NULL)
		delete message;
	message = new char[tailleMessage];
	strcpy(message, buffer);
	
pthread_mutex_unlock(&mutDefileMessage);		/* --- UNLOCK --- */
	
	if(signalOn == true)
		alarm(10);
}

//////////////////////////////////////////////////
void HandlerALRM(int) {
	setMessage("Jeu en cours", false);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 2

void* threadPiece(void*) {
	bool pieceOK;
	bool fit;
	srand(time(NULL));
	CASE caseTmp[NB_CASES];
	
	while(1) {
		DessineVoyant(8, 10, VERT);
		
// Select Random Piece
pthread_mutex_lock(&mutCasesInserees);			/* --- LOCK --- */
		
		pieceEnCours = pieces[rand()%cheat];
		if(style != 1)
			pieceEnCours.couleur = (rand() % 3) + 400000;
		else
			pieceEnCours.couleur = (rand() % 5) + 400020;
		
		RotationPiece(&pieceEnCours);
		
		for(int i = 0; i < pieceEnCours.nbCases; i++)
			DessineDiamant(3+pieceEnCours.cases[i].ligne, 14+pieceEnCours.cases[i].colonne, pieceEnCours.couleur);
		
pthread_mutex_unlock(&mutCasesInserees);		/* --- UNLOCK --- */
		
		
		
//Check if the piece can fit
		fit = false;
		for(int l = 0; l < 9 && !fit; l++)
			for(int c = 0; c < 9 && !fit; c++)  
				fit = TabFit(l, c);
		if(!fit) {
			setMessage("Game Over", false);
			pthread_exit(NULL);
		}
		
		
		
		do {
// Wait for Player's Clicks
pthread_mutex_lock(&mutCasesInserees);			/* --- LOCK --- */
			nbCasesInserees = 0;
			
			while(nbCasesInserees < pieceEnCours.nbCases)
				pthread_cond_wait(&condCasesInserees, &mutCasesInserees);
			
			if(quit)
				pthread_exit(NULL);
			
// To origin + Sort
			for(int i = 0; i < nbCasesInserees; i++)
				caseTmp[i] = casesInserees[i];
			OriginPiece(caseTmp, nbCasesInserees);
			TriCases(caseTmp, 0, nbCasesInserees-1);
			
			
// Is shape matching ?
			pieceOK = true;
			for(int i = 0; i < nbCasesInserees; i++)
				if(CompareCases(pieceEnCours.cases[i], caseTmp[i]) != 0)
					pieceOK = false;
			
			
//// YES
			if(pieceOK) {
pthread_mutex_lock(&mutTraitement);				/* --- LOCK --- */
				traitementEnCours = true;
				DessineVoyant(8, 10, BLEU);
pthread_mutex_unlock(&mutTraitement);			/* --- UNLOCK --- */
				
				for(int i = 0; i < nbCasesInserees; i++) {
					tab[casesInserees[i].ligne][casesInserees[i].colonne] = BRIQUE;
					
					if(style != 1)
						DessineBrique(casesInserees[i].ligne, casesInserees[i].colonne, false);
					else
						DessineDiamant(casesInserees[i].ligne, casesInserees[i].colonne, (pieceEnCours.couleur)+20);


// Check if Goal
					pthread_kill(tabThreadCase[casesInserees[i].ligne][casesInserees[i].colonne], SIGUSR1);
				}
				
pthread_mutex_lock(&mutScore);					/* --- LOCK --- */
				MAJScore = true;
				score += nbCasesInserees;
				pthread_cond_signal(&condScore);
pthread_mutex_unlock(&mutScore);					/* --- UNLOCK --- */
				
				
// Wait for Thread to work first
pthread_mutex_lock(&mutTraitement);				/* --- LOCK --- */
				while(traitementEnCours)
					pthread_cond_wait(&condTraitement, &mutTraitement);
pthread_mutex_unlock(&mutTraitement);			/* --- UNLOCK --- */
			}
			else
			{
//// NO
				
				for(int i = 0; i < nbCasesInserees; i++) {
					tab[casesInserees[i].ligne][casesInserees[i].colonne] = VIDE;
					EffaceCarre(casesInserees[i].ligne, casesInserees[i].colonne);
				}
			}
pthread_mutex_unlock(&mutCasesInserees);		/* --- UNLOCK --- */
		} while(!pieceOK);
		
		
// Reset pieceEnCours area
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++)
				EffaceCarre(3+i, 14+j);
	}
	pthread_exit(NULL);
}

//////////////////////////////////////////////////
void RotationPiece(PIECE * pPiece) {
	srand(time(NULL));
	int tmp, rotation = rand() % 4;
	
	
// Rotation
	for(int i = 0; i < rotation; i++) {
		for(int j = 0; j < pPiece->nbCases; j++) {
			tmp = pPiece->cases[j].ligne;
			pPiece->cases[j].ligne = pPiece->cases[j].colonne;
			pPiece->cases[j].ligne *= -1;
			pPiece->cases[j].colonne = tmp;
		}
	}
	
	
// Positives coord
	OriginPiece(pPiece->cases, pPiece->nbCases);
	
	
// Sorting cases
	TriCases(pPiece->cases, 0, pPiece->nbCases-1);
}

//////////////////////////////////////////////////
void OriginPiece(CASE* pCase, int max) {
	int lmin = 10, cmin = 10;
	
	for(int i = 0; i < max; i++) {
		if(pCase[i].ligne < lmin)
			lmin = pCase[i].ligne;
		if(pCase[i].colonne < cmin)
			cmin = pCase[i].colonne;
	}
	for(int i = 0; i < max; i++) {
		pCase[i].ligne -= lmin;
		pCase[i].colonne -= cmin;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 3

void* threadEvent(void*) {
	struct timespec time;
   time.tv_sec = 0;
 	time.tv_nsec = 400000000;
 	
 	
	EVENT_GRILLE_SDL event;
	
	do {
		event = ReadEvent();
		
pthread_mutex_lock(&mutCasesInserees);			/* --- LOCK --- */
pthread_mutex_lock(&mutTraitement);				/* --- LOCK --- */
		if(traitementEnCours == false) {
			if(event.type == CLIC_GAUCHE) {
				if(event.ligne < 9 && event.colonne < 9) {
					if(tab[event.ligne][event.colonne] == VIDE) {
						tab[event.ligne][event.colonne] = DIAMANT;
						DessineDiamant(event.ligne, event.colonne, pieceEnCours.couleur);
				
						casesInserees[nbCasesInserees].ligne = event.ligne;
						casesInserees[nbCasesInserees].colonne = event.colonne;
						nbCasesInserees++;
				
						pthread_cond_signal(&condCasesInserees);
					} else {
						DessineVoyant(8, 10, ROUGE);
						nanosleep(&time, NULL);
						DessineVoyant(8, 10, VERT);
					}
				} else if(event.ligne == 8 && event.colonne == 10) {
					if(cheat == 12) {
						cheat = 1;
						printf("Cheat Enabled\n");
					} else {
						cheat = 12;
						printf("Cheat Disabled\n");
					}
				} else {
					DessineVoyant(8, 10, ROUGE);
					nanosleep(&time, NULL);
					DessineVoyant(8, 10, VERT);
				}
			} else if(event.type == CLIC_DROIT) {
				if(event.ligne == 8 && event.colonne == 10 && style == 0) {
					style = 1;
					printf("Diamant Personnalise\n");
				} else {
					for(int i = 0; i < nbCasesInserees; i++) {
						tab[casesInserees[i].ligne][casesInserees[i].colonne] = VIDE;
						EffaceCarre(casesInserees[i].ligne, casesInserees[i].colonne);
					}
					nbCasesInserees = 0;
				}
			} else if(event.type == CROIX) {
				quit = true;
				nbCasesInserees = pieceEnCours.nbCases;
				pthread_cond_signal(&condCasesInserees);
			}
		} else {
			DessineVoyant(8, 10, ROUGE);
			nanosleep(&time, NULL);
			DessineVoyant(8, 10, BLEU);
		}
pthread_mutex_unlock(&mutTraitement);			/* --- UNLOCK --- */
pthread_mutex_unlock(&mutCasesInserees);		/* --- UNLOCK --- */
	} while(event.type != CROIX);
	pthread_exit(NULL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 4

void* threadScore(void*) {
pthread_mutex_lock(&mutScore);					/* --- LOCK --- */
	MAJScore = false;
	MAJCombos = false;
	score = 0;
	
	while(!MAJScore && !MAJCombos) {
		DessineChiffre(1, 14, (score/1000)%10);
		DessineChiffre(1, 15, (score/100)%10);
		DessineChiffre(1, 16, (score/10)%10);
		DessineChiffre(1, 17, score%10);
		
		
		DessineChiffre(8, 14, (combos/1000)%10);
		DessineChiffre(8, 15, (combos/100)%10);
		DessineChiffre(8, 16, (combos/10)%10);
		DessineChiffre(8, 17, combos%10);


		pthread_cond_wait(&condScore, &mutScore);
		
		MAJScore = false;
		MAJCombos = false;
	}
pthread_mutex_unlock(&mutScore);					/* --- UNLOCK --- */
	pthread_exit(NULL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 5

void* threadCase(void* caseParam) {
	CASE* caseTmp = (CASE*)caseParam;
	pthread_setspecific(cleCases, caseTmp);
	
	while(1)
		pause();

	pthread_exit(NULL);
}

//////////////////////////////////////////////////
void HandlerUSR1(int i) {
	CASE* caseTmp = (CASE*)pthread_getspecific(cleCases);
	int L = caseTmp->ligne;
	int C = caseTmp->colonne;
	
	bool isPresent = false, isFull = true;

	
pthread_mutex_lock(&mutAnalyse);					/* --- LOCK --- */
// Ligne
	for(int i = 0; i < nbLignesCompletes && isPresent == false; i++)
		if(L == lignesCompletes[i])
			isPresent = true;
	
	if(isPresent == false) {
		for(int i = 0; i < 9 && isFull == true; i++)
			if(tab[L][i] != BRIQUE)
				isFull = false;
		
		if(isFull == true) {
			lignesCompletes[nbLignesCompletes] = L;
			nbLignesCompletes++;
			for(int i = 0; i < 9 && isFull == true; i++)
				DessineBrique(L, i, true);
		}
	}
	
	
// Colonne
	isPresent = false;
	isFull = true;
	
	for(int i = 0; i < nbColonnesCompletes && isPresent == false; i++)
		if(C == colonnesCompletes[i])
			isPresent = true;
	
	if(isPresent == false) {
		for(int i = 0; i < 9 && isFull == true; i++)
			if(tab[i][C] != BRIQUE)
				isFull = false;
		
		if(isFull == true) {
			colonnesCompletes[nbColonnesCompletes] = C;
			nbColonnesCompletes++;
			for(int i = 0; i < 9 && isFull == true; i++)
				DessineBrique(i, C, true);
		}
	}
	
	
// Carré
	isPresent = false;
	isFull = true;
	int numCarre = C / 3 + ((L / 3) * 3);
	int lTmp = L / 3, cTmp = C / 3;
	lTmp *= 3;
	cTmp *= 3;
	
	for(int i = 0; i < nbCarresComplets && isPresent == false; i++)
		if(numCarre == carresComplets[i])
			isPresent = true;
	
	if(isPresent == false) {
		for(int i = lTmp; i < lTmp+3 && isFull == true; i++)
			for(int j = cTmp; j < cTmp+3 && isFull == true; j++)
				if(tab[i][j] != BRIQUE)
					isFull = false;
		
		if(isFull == true) {
			carresComplets[nbCarresComplets] = numCarre;
			nbCarresComplets++;
			for(int i = lTmp; i < lTmp+3 && isFull == true; i++)
				for(int j = cTmp; j < cTmp+3 && isFull == true; j++)
					DessineBrique(i, j, true);
		}
	}
	
	
	nbAnalyses++;
	pthread_cond_signal(&condAnalyse);
pthread_mutex_unlock(&mutAnalyse);				/* --- UNLOCK --- */
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 6

void* threadNettoyeur(void*) {
	int combosTmp = 0;
	
	
	struct timespec time;
   time.tv_sec = 2;
 	time.tv_nsec = 0;
 	
 	
	while(1) {
pthread_mutex_lock(&mutAnalyse);					/* --- LOCK --- */
		while(nbAnalyses < pieceEnCours.nbCases)
			pthread_cond_wait(&condAnalyse, &mutAnalyse);
		
		
		if(0 < nbLignesCompletes || 0 < nbColonnesCompletes || 0 < nbCarresComplets) {
			nanosleep(&time, NULL);
pthread_mutex_lock(&mutScore);					/* --- LOCK --- */
//Lignes
			for(int j = 0; j < nbLignesCompletes; j++) {
				for(int i = 0; i < 9; i++) {
						tab[lignesCompletes[j]][i] = VIDE;
						EffaceCarre(lignesCompletes[j], i);
				}
				combos++;
			}
			nbLignesCompletes = 0;

//Colonnes
			for(int j = 0; j < nbColonnesCompletes; j++) {
				for(int i = 0; i < 9; i++) {
						tab[i][colonnesCompletes[j]] = VIDE;
						EffaceCarre(i, colonnesCompletes[j]);
				}
				combos++;
			}
			nbColonnesCompletes = 0;

//Carrés
			for(int k = 0; k < nbCarresComplets; k++) {
				int lCarre = carresComplets[k] / 3;
				int cCarre = carresComplets[k] % 3;
				lCarre *= 3;
				cCarre *= 3;
				for(int i = 0; i < 3; i++)
					for(int j = 0; j < 3; j++) {
						tab[lCarre+i][cCarre+j] = VIDE;
						EffaceCarre(lCarre+i, cCarre+j);
					}
				combos++;
			}
			nbCarresComplets = 0;
		}
		nbAnalyses = 0;
pthread_mutex_unlock(&mutAnalyse);				/* --- UNLOCK --- */
		
		
// Combos
		combosTmp = combos - combosTmp;
		switch(combosTmp) {
			case 1:
				score += 10;
				setMessage("Simple Combo", true);
				break;
			case 2:
				score += 25;
				setMessage("Double Combo", true);
				break;
			case 3:
				score += 40;
				setMessage("Triple Combo", true);
				break;
			case 4:
				score += 55;
				setMessage("Quadruple Combo", true);
				break;
			default:
				break;
		}
		MAJCombos = true;
		combosTmp = combos;
		pthread_cond_signal(&condScore);
pthread_mutex_unlock(&mutScore);					/* --- UNLOCK --- */
		

pthread_mutex_lock(&mutTraitement);				/* --- LOCK --- */
		traitementEnCours = false;
		DessineVoyant(8, 10, VERT);
		pthread_cond_signal(&condTraitement);
pthread_mutex_unlock(&mutTraitement);			/* --- UNLOCK --- */
	}
	pthread_exit(NULL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

// Etape 8

bool TabFit(int tabL, int tabC) {
	bool fit = true;

	for(int i = 0; i < pieceEnCours.nbCases; i++) {
		if(tab[tabL+pieceEnCours.cases[i].ligne][tabC+pieceEnCours.cases[i].colonne] != VIDE)
			fit = false;
		if(8 < tabL+pieceEnCours.cases[i].ligne)
			fit = false;
		if(8 < tabC+pieceEnCours.cases[i].colonne)
			fit = false;
	}
	return fit;
}

//////////////////////////////////////////////////
void destructeur(void* p) {
	free(p);
}
