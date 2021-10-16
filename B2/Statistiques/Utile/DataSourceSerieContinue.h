#ifndef DATASOURCESERIECONTINUE_H
#define DATASOURCESERIECONTINUE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Data1D.h"
#include "DataSource.h"

class DataSourceSerieContinue:
 public DataSource {
	private:
		Liste<Data1D>* L;
		float Debut;
		float Intervalle;
	
	public:
	//Constructeurs
		DataSourceSerieContinue();
		~DataSourceSerieContinue();
		
	//Setters
		void setL(Liste<Data1D>* e) { L = e; };
		void setDebut(float e) { Debut = e; };
		void setIntervalle(float e) { Intervalle = e; };
		
	//Getters
		Liste<Data1D>* getL() const { return L; };
		float getDebut() const { return Debut; };
		float getIntervalle() const { return Intervalle; };
};
#endif
