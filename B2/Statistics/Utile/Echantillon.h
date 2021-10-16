#ifndef ECHANTILLON_H
#define ECHANTILLON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "DataSourceSerie2D.h"
#include "DataSource.h"
#include "DataSourceSerieContinue.h"
#include "DataSourceSerieDiscrete.h"

class Echantillon {
	private:
		DataSource* Source;
		DataSourceSerie2D* Source2D;
		
		DataSource* Load(char*, int);
		DataSourceSerie2D* Load2D(char*, int, int);
		
		char* Read(ifstream&, int);
		char* Read2D(ifstream&, int, int);
	
	public:
	//Constructeurs
		Echantillon(char*, int);
		Echantillon(char*, int, int);
		
	//Setters
		void setSource(DataSource* e) { Source = e; };
		void setSource2D(DataSourceSerie2D* e) { Source2D = e; };
		
	//Getters
		DataSource* getSource() const { return Source; };
		DataSourceSerie2D* getSource2D() const { return Source2D; };
};
#endif
