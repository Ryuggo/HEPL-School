#include "EtudeStatDescriptive.h"

/*====================		Constructeur d'Initialisation		====================*/

EtudeStatDescriptive::EtudeStatDescriptive(int argc, char* argv[]) {
#ifdef DEV
	TraceConstructeur("Constructeur d'Initialisation EtudeStatDescriptive");
#endif
	if(argc == 2)
		EtudeStat1D E(argv[1], 0);
	else {
		if(argc == 3)
			EtudeStat1D E(argv[1], atoi(argv[2]));
		else {
			if(argc == 4)
				EtudeStat2D E(argv[1], atoi(argv[2]), atoi(argv[3]));
			else
				throw BaseException("Mauvais Paramètres");
		}
	}
}


/*====================				Destructeur					====================*/

EtudeStatDescriptive::~EtudeStatDescriptive() {
#ifdef DEV
	TraceConstructeur("Destructeur EtudeStatDescriptive");
#endif
}
