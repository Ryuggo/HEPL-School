#include "Data1D.h"

/*====================		Constructeur par Défaut				====================*/

Data1D::Data1D() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Data1D");
#endif
	setVal(0);
	setEff(0);
}


/*====================		Constructeur d'Initialisation		====================*/

Data1D::Data1D(float v) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Data1D");
#endif
	setVal(v);
	setEff(1);
}


/*====================				Opérateurs						====================*/

ostream& operator<<(ostream& out, Data1D& data) {
	out << data.Val << "\t: " << data.Eff;
	return out;
}

bool Data1D::operator<(Data1D& data) {
	if(Val < data.getVal()) return true;
	else return false;
}

bool Data1D::operator>(Data1D& data) {
	if(Val > data.getVal()) return true;
	else return false;
}

bool Data1D::operator<=(Data1D& data) {
	if(Val <= data.getVal()) return true;
	else return false;
}

bool Data1D::operator>=(Data1D& data) {
	if(Val >= data.getVal()) return true;
	else return false;
}

bool Data1D::operator==(Data1D& data) {
	if(Val == data.getVal()) return true;
	else return false;
}

bool Data1D::operator!=(Data1D& data) {
	if(Val != data.getVal()) return true;
	else return false;
}
