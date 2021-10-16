#ifndef DATASOURCESERIE2D_H
#define DATASOURCESERIE2D_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Data2D.h"
#include "DataSource.h"

class DataSourceSerie2D:
	public DataSource {
	private:
		Liste<Data2D>* L;
		char* Sujet2;
		char Type2;
	
	public:
	// Constructeurs
		DataSourceSerie2D();
		DataSourceSerie2D(const DataSourceSerie2D&);
		~DataSourceSerie2D();
		
	//Setters
		void setL(Liste<Data2D>* e) { L = e; };
		void setSujet2(const char*);
		void setType2(char e) { Type2 = e; };
		
	//Getters
		Liste<Data2D>* getL() const { return L; };
		const char* getSujet2() const { return Sujet2; };
		char getType2() const { return Type2; };
};
#endif
