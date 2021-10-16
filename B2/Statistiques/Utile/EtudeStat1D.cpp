#include "EtudeStat1D.h"

#include "graphstat1dcontinue.h"
#include "graphstat1ddiscrete.h"
extern QApplication* a;

/*====================		Constructeur par Défaut				====================*/

EtudeStat1D::EtudeStat1D() {
#ifdef DEV
	TraceConstructeur("Constructeur par défaut EtudeStat1D");
#endif
	setData(NULL);
	setMoyenne(0);
	setMediane(0);
	setMode(0, 0);
	setMode(0, 1);
	setMode(0, 2);
	setMode(0, 3);
	setEcartType(0);
	setVariation(0);
	setMin(0);
	setMax(0);
}


/*====================		Constructeur d'Initialisation		====================*/

EtudeStat1D::EtudeStat1D(char* fichier, int col) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation EtudeStat1D");
#endif
	float moy = 0, ecart = 0, modeTmp[4] = {0, 0, 0, 0};
	int i, j, effTmp = 0, modeNb = 0;

	Echantillon e(fichier, col);
	setData(&e);
	
	
	Liste<Data1D> *l;
	DataSourceSerieContinue* dc;
	DataSourceSerieDiscrete* dd;

	dc = dynamic_cast<DataSourceSerieContinue*> (getData()->getSource());
	if(dc)
		l = dc->getL();
	else {
		dd = dynamic_cast<DataSourceSerieDiscrete*> (getData()->getSource());
		if(dd)
			l = dd->getL();
		else
			exit(0);
	}
	
	DataSource* data = getData()->getSource();
	float eff = data->getEffTotal();


// CALCULS

// Moyenne
	for(i = 0; i < l->Size(); i++)
		moy += l->getElement(i).getVal() * l->getElement(i).getEff();
	setMoyenne(moy / eff);
	
// Mediane
	i = 0;
	j = 0;
	while(1) {
		j += l->getElement(i).getEff();
		if(eff/2 <= j)
			break;
		else
			i++;
	}
	
	if((int)eff % 2 == 1)	// Impair
		setMediane(l->getElement(i-1).getVal());
	else {
//		if(dd) {
			float med1 = l->getElement(i-1).getVal();
			float med2 = l->getElement(i).getVal();
			setMediane((med1 + med2) / 2);
//		} else {

//		}
	}

// Mode
	for(i = 0; i < l->Size(); i++) {
		if(effTmp < l->getElement(i).getEff()) {
			effTmp = l->getElement(i).getEff();
			modeTmp[0] = l->getElement(i).getVal();
			modeTmp[1] = 0;
			modeTmp[2] = 0;
			modeNb = 1;
		} else
			if(effTmp == l->getElement(i).getEff() && modeNb < 3) {
				modeTmp[modeNb] = l->getElement(i).getVal();
				modeNb++;
			}
	}
	modeTmp[4] = 0;
	for(i = 0; i < 3; i++)
		setMode(modeTmp[i], i);

// Ecart Type
	for(i = 0; i < l->Size(); i++)
		ecart += pow((l->getElement(i).getVal() - getMoyenne()), 2) * l->getElement(i).getEff();
	setEcartType(sqrt(ecart / eff));

// Coef de Variation
	setVariation((getEcartType() / getMoyenne()) * 100);

//Valeur Min & Max
	setMin(l->getElement(0).getVal());
	setMax(l->getElement(l->Size() - 1).getVal());
	
	
	Affiche();
}


/*====================				Destructeur					====================*/

EtudeStat1D::~EtudeStat1D() {
#ifdef DEV
	TraceConstructeur("Destructeur EtudeStat1D");
#endif
	if(Data)
		delete Data;
}


/*====================				Autres						====================*/

void EtudeStat1D::Affiche() {
	Liste<Data1D>* l;
	DataSourceSerieContinue* dc;
	DataSourceSerieDiscrete* dd;

	dc = dynamic_cast<DataSourceSerieContinue*> (getData()->getSource());
	if(dc)
		l = dc->getL();
	else {
		dd = dynamic_cast<DataSourceSerieDiscrete*> (getData()->getSource());
		if(dd)
			l = dd->getL();
		else
			exit(0);
	}
	DataSource* data = getData()->getSource();
	
	cout << "Nom : " << data->getNom() << endl;
	cout << "Sujet de l'etude : " << data->getSujet() << endl;
	cout << "Type : " << data->getType() << endl;
	cout << endl << endl;
	
	cout << "Donnees : " << endl;
	cout << "---------";
	l->Affiche();
	
	cout << "Effectif total : " << data->getEffTotal() << endl;
	cout << "   Moyenne : " << getMoyenne() << endl;
	cout << "   Mediane : " << getMediane() << endl;
	cout << "   Mode :\t" << getMode(0) << " : " << getMode(1) << " : " << getMode(2) << endl;
	cout << "   Ecart type : " << getEcartType() << endl;
	cout << "   Coefficient de variation : " << getCV() << "%" << endl << endl;
	
	if(dc) {
		cout << "Controle de qualite :" << endl;
		cout << "\t  Valeur min : " << getMin() << endl;
		cout << "\t  Valeur max : " << getMax() << endl << endl;
		
		GraphStat1DContinue w(*this);
		w.show();
		a->exec();
	} else {
		GraphStat1DDiscrete w(*this);
		w.show();
		a->exec();
	}
}
