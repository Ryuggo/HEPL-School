#ifndef ETUDESTAT1D_H
#define ETUDESTAT1D_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <math.h>
#include <QApplication>
using namespace std;
#include "Liste.h"
#include "ListeTriee.h"
#include "Echantillon.h"

class EtudeStat1D {
	private:
		Echantillon* Data;
		float Moyenne;
		float Mediane;
		float Mode[4];
		float EcartType;
		float Variation;
		float Min;
		float Max;
	
	public:
	//Constructeurs
		EtudeStat1D();
		EtudeStat1D(char*, int);
		~EtudeStat1D();
		
	//Setters
		void setData(Echantillon* e) { Data = e; };
		void setMoyenne(float e) { Moyenne = e; };
		void setMediane(float e) { Mediane = e; };
		void setMode(float e, short i) { Mode[i] = e; };
		void setEcartType(float e) { EcartType = e; };
		void setVariation(float e) { Variation = e; };
		void setMin(float e) { Min = e; };
		void setMax(float e) { Max = e; };
		
	//Getters
		Echantillon* getData() const { return Data; };
		Echantillon* getE() const { return Data; };
		float getMoyenne() const { return Moyenne; };
		float getMediane() const { return Mediane; };
		float getMode(short i) const { return Mode[i]; };
		const float* getMode() const { return Mode; };
		float getEcartType() const { return EcartType; };
		float getVariation() const { return Variation; };
		float getMin() const { return Min; };
		float getMax() const { return Max; };
		float getEtendue() const { return Max - Min; };
		float getCV() const { return (EcartType / Moyenne) * 100; };
		
	//Autres
		void Affiche();
};
#endif
