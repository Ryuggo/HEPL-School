#include "DataSource.h"

/*====================		Constructeur par Défaut				====================*/

DataSource::DataSource() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut DataSource");
#endif
	setNom(NULL);
	setSujet(NULL);
	setEffTotal(0);
	setType('N');
}


/*====================		Constructeur de Copie				====================*/

DataSource::DataSource(const DataSource& old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie DataSource");
#endif
	setNom(old.Nom);
	setSujet(old.Sujet);
	setEffTotal(old.EffTotal);
	setType(old.Type);
}


/*====================				Destructeur					====================*/

DataSource::~DataSource() {
#ifdef DEV
	TraceConstructeur("Destructeur DataSource");
#endif
	if(Nom)
		delete[] Nom;
	if(Sujet)
		delete[] Sujet;
}


/*====================				Setters						====================*/

void DataSource::setNom(const char* nomTmp) {
	if(Nom != NULL)
		delete Nom;
	
	if(nomTmp != NULL) {
		Nom = new char[strlen(nomTmp)];
		strcpy(Nom, nomTmp);
	} else
		Nom = NULL;
}

void DataSource::setSujet(const char* sujetTmp) {
	if(Sujet != NULL)
		delete Sujet;
	
	if(sujetTmp != NULL) {
		Sujet = new char[strlen(sujetTmp)];
		strcpy(Sujet, sujetTmp);
	} else
		Sujet = NULL;
}
