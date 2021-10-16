#include "DataSourceSerieContinue.h"

/*====================		Constructeur par Défaut				====================*/

DataSourceSerieContinue::DataSourceSerieContinue(): DataSource() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut DataSourceSerieContinue");
#endif
	L = NULL;
	setDebut(0);
	setIntervalle(0);
}


/*====================				Destructeur					====================*/

DataSourceSerieContinue::~DataSourceSerieContinue() {
#ifdef DEV
	TraceConstructeur("Destructeur DataSourceSerieContinue");
#endif
	if(L)
		delete L;
}
