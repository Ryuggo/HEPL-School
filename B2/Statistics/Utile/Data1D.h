#ifndef DATA1D_H
#define DATA1D_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

class Data1D {
	private:
		float Val;
		int Eff;
	
	public:
	//Constructeurs
		Data1D();
		Data1D(float);
		
	//Setters
		void setVal(float e) { Val = e; };
		void setEff(int e) { Eff = e; };
		
	//Getters
		float getVal() const { return Val; };
		int getEff() const { return Eff; };
		
	//Opérateurs
		friend ostream& operator<<(ostream&, Data1D&);
		bool operator<(Data1D&);
		bool operator>(Data1D&);
		bool operator<=(Data1D&);
		bool operator>=(Data1D&);
		bool operator==(Data1D&);
		bool operator!=(Data1D&);
};
#endif
