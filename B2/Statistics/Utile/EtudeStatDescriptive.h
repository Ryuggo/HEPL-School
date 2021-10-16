#ifndef ETUDESTATDESCRIPTIVE_H
#define ETUDESTATDESCRIPTIVE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
using namespace std;
#include "EtudeStat1D.h"
#include "EtudeStat2D.h"
#include "BaseException.h"

class EtudeStatDescriptive {
	private:
	
	public:
	//Constructeurs
		EtudeStatDescriptive(int argc, char* argv[]);
		~EtudeStatDescriptive();
};
#endif
