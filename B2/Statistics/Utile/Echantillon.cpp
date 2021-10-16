#include "Echantillon.h"


/*====================		Constructeur d'Initialisation		====================*/

Echantillon::Echantillon(char* fichier, int col) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Echantillon");
#endif
	if(col < 0) {
		perror("Numero de Colonne Invalide");
		exit(0);
	}
	else
		setSource(Load(fichier, col));
}

Echantillon::Echantillon(char* fichier, int col1, int col2) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Echantillon");
#endif
	if(col1 < 0 || col2 < 0 || col2 <= col1) {
		perror("Numero de Colonne Invalide");
		exit(0);
	}
	else
		setSource2D(Load2D(fichier, col1, col2));
}


/*====================				Autres						====================*/

DataSource* Echantillon::Load(char* fichier, int col) {
	DataSource* data = NULL;
	DataSourceSerieContinue* dc = NULL;
	DataSourceSerieDiscrete* dd = NULL;
	Data1D* d = NULL;
	
	int i, j, k = 0;
	char *ligneC = NULL, *nom = NULL, *sujet = NULL, type;
	float ligneF, tmp, a;
	ListeTriee<float> lt;
	Liste<Data1D>* l = new Liste<Data1D>;
	
// Lecture de fichier
	ifstream f(fichier);
	nom = Read(f, 0);
	sujet = Read(f, col);
	type = *(Read(f, col));
	for(i = 0; true; i++) {
		ligneC = Read(f, col);
		if(!strcmp(ligneC, ""))
			break;
		ligneF = atof(ligneC);
		lt.insere(ligneF);
	} 
	f.close();
	
// Type de Données
	if(type == 'C')
		data = new DataSourceSerieContinue;
	else
		data = new DataSourceSerieDiscrete;
	
	data->setNom(nom);
	data->setSujet(sujet);
	data->setType(type);
	
	dc = dynamic_cast<DataSourceSerieContinue*> (data);
	if(dc) {
		cout << "Début de l'Intervalle : ";
		cin >> tmp;
		dc->setDebut(tmp);
		
		cout << "Taille de l'Intervalle : ";
		cin >> tmp;
		dc->setIntervalle(tmp);
	
		d = new Data1D;
		tmp = lt.getElement(0);
		d->setVal(tmp);

// Liste avec Effectifs
		for(j = 0; j < i; j++) {
			a = lt.getElement(j);
			if(dc->getDebut() <= a) {
				if((dc->getDebut() + dc->getIntervalle()) < a)
					break;
				if(tmp != a) {
					l->insere(*d);
					d = new Data1D;
					tmp = lt.getElement(j);
					d->setVal(tmp);
				}
				k++;
				d->setEff(d->getEff()+1);
			}
		}
		data->setEffTotal(k);
		
		l->insere(*d);
		dc->setL(l);
	} else {
		dd = dynamic_cast<DataSourceSerieDiscrete*> (data);
		data->setEffTotal(i);
	
		d = new Data1D;
		tmp = lt.getElement(0);
		d->setVal(tmp);

// Liste avec Effectifs
		for(j = 0; j < i; j++) {
			a = lt.getElement(j);
			if(tmp != a) {
				l->insere(*d);
				d = new Data1D;
				tmp = lt.getElement(j);
				d->setVal(tmp);
			}
			d->setEff(d->getEff()+1);
		}
		
		l->insere(*d);
		dd->setL(l);
	}
	return data;
}

DataSourceSerie2D* Echantillon::Load2D(char* fichier, int col1, int col2) {
	DataSourceSerie2D* data = new DataSourceSerie2D;
	Data2D* d = new Data2D;
	
	int i;
	char *ligneC = NULL, *nom = NULL, *sujet = NULL, *sujet2 = NULL, type, type2;
	Data2D ligneD;
	ListeTriee<Data2D> lt;
	Liste<Data2D>* l = new Liste<Data2D>;
	
// Lecture de fichier
	ifstream f(fichier);
	
	nom = Read(f, 0);
	
	sujet = Read2D(f, col1, -1);
	sujet2 = Read2D(f, -1, col2-col1-1);
	
	type = *(Read2D(f, col1, -1));
	type2 = *(Read2D(f, -1, col2-col1-1));
	
	for(i = 0; true; i++) {
		ligneC = Read2D(f, col1, -1);
		if(!strcmp(ligneC, ""))
			break;
		d->setVal1(atof(ligneC));
		
		ligneC = Read2D(f, -1, col2-col1-1);
		if(!strcmp(ligneC, ""))
			break;
		d->setVal2(atof(ligneC));
		
		lt.insere(*d);
	} 
	f.close();
	
	data->setNom(nom);
	data->setSujet(sujet);
	data->setSujet2(sujet2);
	data->setEffTotal(i);
	data->setType(type);
	data->setType2(type2);
	
	for(int j = 0; j < i; j++)
		l->insere(lt.getElement(j));
	data->setL(l);
	
	return data;
}

char* Echantillon::Read(ifstream& f, int col) {
	char tmp[200] = "", c = '\0';
	char* val;
	int i = 0, j = 0;
	
	while(c != '\n') {
		f.read(&c, sizeof(char));
		if(c == ':')
				j++;
		else {
			if(j == col) {
				tmp[i] = c;
				if(c == '.')
					tmp[i] = ',';
				if(c != '\n')
					i++;
				tmp[i] = '\0';
			}
		}
		if(f.eof())
			break;
	}
	val = new char[strlen(tmp)];
	strcpy(val, tmp);
	
	return val;
}

char* Echantillon::Read2D(ifstream& f, int col1, int col2) {
	char tmp[200] = "", c = '\0';
	char* val;
	int i = 0, j = 0;
	
	if(col1 != -1) {
		while(1) {
			f.read(&c, sizeof(char));
			if(c == ':')
				j++;
			else {
				if(j == col1) {
					tmp[i] = c;
					if(c == '.')
						tmp[i] = ',';
					if(c != '\n')
						i++;
					tmp[i] = '\0';
				}
			}
			if(f.eof() || col1 < j)
				break;
		}
	} else {
		while(c != '\n') {
			f.read(&c, sizeof(char));
			if(c == ':')
				j++;
			else {
				if(j == col2) {
					tmp[i] = c;
					if(c == '.')
						tmp[i] = ',';
					if(c != '\n')
						i++;
					tmp[i] = '\0';
				}
			}
			if(f.eof() || col2 < j)
				break;
		}
		while(1) {
			if(c == '\n')
				break;
			f.read(&c, sizeof(char));
		}
	}
	val = new char[strlen(tmp)];
	strcpy(val, tmp);
	
	return val;
}
