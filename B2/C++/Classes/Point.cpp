#include "Point.h"

int Point::compteur = 0;


/*====================		Constructeur par Défaut				====================*/

Point::Point()
{
#ifdef DEV
	TraceConstructeur("Constructeur par défaut Point");
#endif
	setX(0);
	setY(0);
	
	Point::compteur++;
}


/*====================		Constructeur d'Initialisation		====================*/

Point::Point(int xTmp, int yTmp)
{
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation Point");
#endif
	setX(xTmp);
	setY(yTmp);
	
	Point::compteur++;
}


/*====================			Constructeur de Copie			====================*/

Point::Point(const Point& old)
{
#ifdef DEV
	TraceConstructeur("Constructeur de Copie Point");
#endif
	setX(old.x);
	setY(old.y);
	
	Point::compteur++;
}


/*====================				Destructeur					====================*/

Point::~Point()
{
#ifdef DEV
	TraceConstructeur("Destructeur Point");
#endif
	Point::compteur--;
}


/*====================				Setters						====================*/

//..


/*====================				Getters						====================*/

//..


/*====================				Autres						====================*/

void Point::Affiche() const {
	cout << "Coordonnées :\t[" << x << " , " << y << "]" << endl;
}

void Point::Save(ofstream& file) const {
	file.write((char*)&x, sizeof(int));
	file.write((char*)&y, sizeof(int));
}

void Point::Load(ifstream& file) {
	file.read((char*)&x, sizeof(int));
	file.read((char*)&y, sizeof(int));
}


/*====================				Opérateurs					====================*/

ostream& operator<<(ostream& output, const Point& p){
	output << "(" << p.x << ", " << p.y << ")";

	return output;
}

//static const int getCompteur() { return Point::compteur; }
