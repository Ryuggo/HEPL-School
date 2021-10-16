#include "EtudeStat2D.h"

#include <QApplication>
#include "graphstat2d.h"
extern QApplication* a;

/*====================		Constructeur par Défaut				====================*/

EtudeStat2D::EtudeStat2D() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut EtudeStat2D");
#endif
	setData(NULL);
	setMoyenneVal1(0);
	setMoyenneVal2(0);
	setCoeffA(0);
	setCoeffB(0);
}


/*====================		Constructeur d'Initialisation		====================*/

EtudeStat2D::EtudeStat2D(char* fichier, int col1, int col2) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation EtudeStat2D");
#endif
	float moy, i, tmp1, tmp2, tmp3, tmp4;
	float coeff1, coeff2;

	Echantillon e(fichier, col1, col2);
	setData(&e);
	
	Liste<Data2D>* l;
	DataSourceSerie2D* d = dynamic_cast<DataSourceSerie2D*> (getE()->getSource2D());
	if(d)
		l = d->getL();
	else
		exit(0);


// CALCULS

// Moyennes
	for(i = 0, moy = 0; i < l->Size(); i++)
		moy += l->getElement(i).getVal1();
	setMoyenneVal1(moy / l->Size());
	
	for(i = 0, moy = 0; i < l->Size(); i++)
		moy += l->getElement(i).getVal2();
	setMoyenneVal2(moy / l->Size());
	
// Coefficients A
	for(i = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0; i < l->Size(); i++) {
		tmp1 += l->getElement(i).getVal1() * l->getElement(i).getVal2();
		tmp2 += l->getElement(i).getVal1();
		tmp3 += l->getElement(i).getVal2();
		tmp4 += pow(l->getElement(i).getVal1(), 2);
	}
	coeff1 = tmp1 - ((tmp2 * tmp3) / l->Size());
	coeff2 = tmp4 - (pow(tmp2, 2) / l->Size());
	
	setCoeffA(coeff1 / coeff2);
	
// Coefficient B
	setCoeffB(getMoyenneVal2() - (getCoeffA() * getMoyenneVal1()));
	
	
	Affiche();
}


/*====================				Destructeur					====================*/

EtudeStat2D::~EtudeStat2D() {
#ifdef DEV
	TraceConstructeur("Destructeur EtudeStat2D");
#endif
	if(Data)
		delete Data;
}


/*====================				Autres						====================*/

void EtudeStat2D::Affiche() {
	int choice = 0;
	float val;
	
	DataSourceSerie2D* data = getE()->getSource2D();
	
	Liste<Data2D>* l;
	DataSourceSerie2D* d = dynamic_cast<DataSourceSerie2D*> (getE()->getSource2D());
	if(d)
		l = d->getL();
	else
		exit(0);
	
	
	cout << endl << "Etude Statistique:" << endl;
	cout << "------------------" << endl << endl;
	
	cout << "Nom : \t\t  " << data->getNom() << endl;
	cout << "Sujet de l'etude  " << data->getSujet() << "  --  " << data->getSujet2() << endl;
	cout << "Effectif Total :  " << l->Size() << endl;
	cout << "Type :\t\t  " << data->getType() << "\t" << data->getType2() << endl;
	cout << endl << endl;
	
	cout << "Valeurs : " << endl;
	cout << "---------";
	l->Affiche();
	cout << endl;
	
	cout << "   Moyenne Val1 : " << getMoyenneVal1() << endl;
	cout << "   Moyenne Val2 : " << getMoyenneVal2() << endl;
	cout << endl << endl;
	
	cout << "Corrélation :" << endl;
	cout << "   Coefficient a : " << getCoeffA() << endl;
	cout << "   Coefficient b : " << getCoeffB() << endl << endl;
	
	GraphStat2D w(this);
	w.show();
	a->exec();
	
	do{
		fflush(stdin);
		cout << "		1 : Prévision pour : " << data->getSujet() << endl;
		cout << "		2 : Prévision pour : " << data->getSujet2() << endl;
		cout << "		3 : Sortie " << endl;
		cin >> choice;
		
		switch(choice) {
		case 1:
			cout << "Entrer la valeur pour " << data->getSujet() << " : ";
			cin >> val;
			val = getCoeffA() * val + getCoeffB();
			cout << "La valeur prevue : " << val << endl << endl;
			break;
		case 2:
			cout << "Entrer la valeur pour " << data->getSujet2() << " : ";
			cin >> val;
			val = (val - getCoeffB()) / getCoeffA();
			cout << "La valeur prevue : " << val << endl << endl;
			break;
		case 3:
			cout << "Fin" << endl;
			break;
		default:
			choice = 0;
		}
		
	} while(choice != 3);
}
