#include "BaseException.h"


/*====================			Constructeur par Défaut			====================*/


/*====================		Constructeur d'Initialisation		====================*/

BaseException::BaseException(const char* msgTmp) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation BaseException");
#endif
	msg = NULL;
	setMsg(msgTmp);
}


/*====================			Constructeur de Copie			====================*/

BaseException::BaseException(const BaseException& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie BaseException");
#endif
	msg = NULL;
	setMsg(old.getMsg());
}


/*====================				Destructeur					====================*/

BaseException::~BaseException() {
#ifdef DEV
	TraceConstructeur("Destructeur BaseException");
#endif
	if(msg != NULL)
		delete msg;
}

/*====================				Setters						====================*/

void BaseException::setMsg(const char* msgTmp) {
	if(msg != NULL)
		delete msg;
	
	if(msgTmp != NULL)
	{
		msg = new char[strlen(msgTmp)+1];
		strcpy(msg, msgTmp);
	}
	else
		msg = NULL;
}


/*====================				Getters						====================*/

const char* BaseException::getMsg() const {
	return msg;
}


/*====================				Autres						====================*/


/*====================				Opérateurs					====================*/

