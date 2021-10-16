#include <iostream>
using namespace std;
#include "BaseException.h"
//#include "Data1D.h"
#include <QApplication>
#include "EtudeStatDescriptive.h"
//#include "Echantillon.h"

QApplication* a;

int main(int argc,char* argv[]) {
	printf("Début de l'applic\n");
	a = new QApplication(argc,argv);
	
	try {
		EtudeStatDescriptive E(argc,argv);
	} catch (BaseException exc) {
		cout << "Err. " << exc.getMsg() << endl;
	}
}
