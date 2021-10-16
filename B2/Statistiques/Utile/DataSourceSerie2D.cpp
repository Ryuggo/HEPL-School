#include "DataSourceSerie2D.h"

/*====================		Constructeur par Défaut				====================*/

DataSourceSerie2D::DataSourceSerie2D(): DataSource() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut DataSourceSerie2D");
#endif
	Sujet2 = NULL;
	setType2(0);
}


/*====================		Constructeur de Copie				====================*/

DataSourceSerie2D::DataSourceSerie2D(const DataSourceSerie2D& old): DataSource(old) {
#ifdef DEV
	TraceConstructeur("Constructeur de Copie DataSourceSerie2D");
#endif
	setSujet2(old.Sujet2);
	setType2(old.Type2);
}


/*====================				Destructeur					====================*/

DataSourceSerie2D::~DataSourceSerie2D() {
#ifdef DEV
	TraceConstructeur("Destructeur DataSourceSerie2D");
#endif
	if(Sujet2)
		delete[] Sujet2;
}


/*====================				Setters						====================*/

void DataSourceSerie2D::setSujet2(const char* sujetTmp) {
	if(Sujet2 != NULL)
		delete Sujet2;
	
	if(sujetTmp != NULL) {
		Sujet2 = new char[strlen(sujetTmp)+1];
		strcpy(Sujet2, sujetTmp);
	} else
		Sujet2 = NULL;
}
