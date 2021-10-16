#ifndef DATA2D_H
#define DATA2D_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;

class Data2D {
	private:
		float Val1;
		float Val2;
	
	public:
	//Const par défaut
		Data2D();
		Data2D(float, float);
		
	//Setters
		void setVal1(float v) { Val1 = v; };
		void setVal2(float v) { Val2 = v; };
		
	//Getters
		float getVal1() const { return Val1; };
		float getVal2() const { return Val2; };
		
	//Opérateurs
		friend ostream& operator<<(ostream&, Data2D&);
		bool operator<(Data2D&);
		bool operator>(Data2D&);
		bool operator<=(Data2D&);
		bool operator>=(Data2D&);
		bool operator==(Data2D&);
		bool operator!=(Data2D&);
};
#endif
