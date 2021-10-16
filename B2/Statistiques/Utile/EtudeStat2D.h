#ifndef ETUDESTAT2D_H
#define ETUDESTAT2D_H

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

class EtudeStat2D {
	private:
		Echantillon* Data;
		float MoyenneVal1;
		float MoyenneVal2;
		float CoeffA;
		float CoeffB;
	
	public:
	//Const par défaut
		EtudeStat2D();
		EtudeStat2D(char*, int, int);
		~EtudeStat2D();
		
	//Setters
		void setData(Echantillon* e) { Data = e; };
		void setMoyenneVal1(float e) { MoyenneVal1 = e; };
		void setMoyenneVal2(float e) { MoyenneVal2 = e; };
		void setCoeffA() {  };
		void setCoeffB() {  };
		void setCoeffA(float e) { CoeffA = e; };
		void setCoeffB(float e) { CoeffB = e; };
		
	//Getters
		Echantillon* getE() const { return Data; };
		float getMoyenneVal1() const { return MoyenneVal1; };
		float getMoyenneVal2() const { return MoyenneVal2; };
		float getCoeffA() const { return CoeffA; };
		float getCoeffB() const { return CoeffB; };
		
	//Autres
		void Affiche();
};
#endif
