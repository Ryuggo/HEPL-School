#include "InvalidColorException.h"


/*====================			Constructeur par Défaut			====================*/


/*====================		Constructeur d'Initialisation		====================*/

InvalidColorException::InvalidColorException(const char* msgTmp, int v): BaseException(msgTmp) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation InvalidColorException");
#endif
	setValeur(v);
}


/*====================			Constructeur de Copie			====================*/

InvalidColorException::InvalidColorException(const InvalidColorException& old): BaseException(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie InvalidColorException");
#endif
	setValeur(old.getValeur());
}


/*====================				Destructeur					====================*/

InvalidColorException::~InvalidColorException() {
#ifdef DEV
	TraceConstructeur("Destructeur InvalidColorException");
#endif
}

/*====================				Setters						====================*/

//...


/*====================				Getters						====================*/

//...


/*====================				Autres						====================*/

//...


/*====================				Opérateurs					====================*/

