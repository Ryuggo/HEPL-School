#include "DataSourceSerieDiscrete.h"

/*====================		Constructeur par Défaut				====================*/

DataSourceSerieDiscrete::DataSourceSerieDiscrete(): DataSource() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut DataSourceSerieDiscrete");
#endif
	L = NULL;
}


/*====================				Destructeur					====================*/

DataSourceSerieDiscrete::~DataSourceSerieDiscrete() {
#ifdef DEV
	TraceConstructeur("Destructeur DataSourceSerieDiscrete");
#endif
	if(L)
		delete L;
}
