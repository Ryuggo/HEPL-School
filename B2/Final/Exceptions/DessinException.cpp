#include "DessinException.h"


/*====================			Constructeur par Défaut			====================*/


/*====================		Constructeur d'Initialisation		====================*/

DessinException::DessinException(const char* msgTmp, const char* n): BaseException(msgTmp) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation DessinException");
#endif
	setNom(n);
}


/*====================			Constructeur de Copie			====================*/

DessinException::DessinException(const DessinException& old): BaseException(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie DessinException");
#endif
	nom = NULL;
	setNom(old.getNom());
}


/*====================				Destructeur					====================*/

DessinException::~DessinException() {
#ifdef DEV
	TraceConstructeur("Destructeur DessinException");
#endif
}

/*====================				Setters						====================*/

void DessinException::setNom(const char* nomTmp) {
	if(nom != NULL)
		delete nom;
	
	if(nomTmp != NULL) {
		nom = new char[strlen(nomTmp)+1];
		strcpy(nom, nomTmp);
	} else
		nom = NULL;
}


/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/

//...


/*====================				Opérateurs					====================*/

