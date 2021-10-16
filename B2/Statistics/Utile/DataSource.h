#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "Liste.h"
#include "ListeTriee.h"

class DataSource {
	protected:
		char* Nom;
		char* Sujet;
		int EffTotal;
		char Type;
	
	public:
	//Constructeurs
		DataSource();
		DataSource(const DataSource&);
		virtual ~DataSource();
		
	//Setters
		void setNom(const char*);
		void setSujet(const char*);
		void setEffTotal(int e) { EffTotal = e; };
		void setType(char e) { Type = e; };
		
	//Getters
		const char* getNom() const { return Nom; };
		const char* getSujet() const { return Sujet; };
		int getEffTotal() const { return EffTotal; };
		char getType() const { return Type; };
};
#endif
