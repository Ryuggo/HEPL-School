#include "Data2D.h"

/*====================		Constructeur par Défaut				====================*/

Data2D::Data2D() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Data2D");
#endif
	setVal1(0);
	setVal2(0);
}


/*====================		Constructeur d'Initialisation		====================*/

Data2D::Data2D(float v1, float v2) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Data2D");
#endif
	setVal1(v2);
	setVal2(v1);
}


/*====================				Opérateurs						====================*/

ostream& operator<<(ostream& out, Data2D& data) {
	out << data.Val1 << " - " << data.Val2;
	return out;
}

bool Data2D::operator<(Data2D& data) {
	if(Val1 < data.getVal1()) return true;
	else return false;
}

bool Data2D::operator>(Data2D& data) {
	if(Val1 > data.getVal1()) return true;
	else return false;
}

bool Data2D::operator<=(Data2D& data) {
	if(Val1 <= data.getVal1()) return true;
	else return false;
}

bool Data2D::operator>=(Data2D& data) {
	if(Val1 >= data.getVal1()) return true;
	else return false;
}

bool Data2D::operator==(Data2D& data) {
	if(Val1 == data.getVal1()) return true;
	else return false;
}

bool Data2D::operator!=(Data2D& data) {
	if(Val1 != data.getVal1()) return true;
	else return false;
}
