#ifndef DATASOURCESERIEDISCRETE_H
#define DATASOURCESERIEDISCRETE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Data1D.h"
#include "DataSource.h"

class DataSourceSerieDiscrete:
 public DataSource {
	private:
		Liste<Data1D>* L;
	
	public:
	//Constructeurs
		DataSourceSerieDiscrete();
		~DataSourceSerieDiscrete();
		
	//Setters
		void setL(Liste<Data1D>* e) { L = e; };
		
	//Getters
		Liste<Data1D>* getL() const { return L; };
};
#endif
