#include "reseaux.h"


int Create_Socket(int domain, int type, int protocol)
{
	int handleSocket = socket(domain, type, protocol);
	if(handleSocket == -1)
	{
		printf("Erreur de creation de la socket %d\n", errno);
		exit(1);
	}
	printf("socket n°: %d\n", handleSocket);
	return handleSocket;
}

sockaddr_in Infos_Host()
{
	struct sockaddr_in adresse;
	properties prop;

	prop = Load_Properties(FILENAME);

	struct hostent *infosHost = gethostbyname(prop.machine);
	if( infosHost == 0)
	{
		printf("Erreur d'acquisition d'infos sur le host %d\n", errno);
		exit(1);
	}

	memset(&adresse, 0, sizeof(struct sockaddr_in));
	adresse.sin_family = AF_INET;
	adresse.sin_port = htons(prop.port);
	memcpy(&adresse.sin_addr, infosHost->h_addr, infosHost->h_length);

	return adresse;
}

void Bind_Socket(int handleSocket, const struct sockaddr *adress, int size)
{
	int reussite = bind(handleSocket, adress, size);
	if(reussite == -1)
	{
		printf("Erreur sur le bind de la socket %d\n", errno);
		exit(1);
	}
}


void Listen_Server(int handleSocket, int nbConnection)
{
	int reussite = listen(handleSocket, nbConnection);
	if(reussite == -1)
	{
		printf("Erreur sur l'ecoute %d\n", errno);
		close(handleSocket);
		exit(1);
	}
}

int Accept_Server(int handleSocket, struct sockaddr *adress, int size)
{
	int hSocketService;
	//unsigned int t = size;
	hSocketService = accept(handleSocket, adress, (unsigned int*)&size);
	if(hSocketService == -1)
	{
		printf("Erreur sur l'acceptation %d\n", errno);
		close(handleSocket);
		exit(1);
	}
	return hSocketService;
}


void Connect_Client(int handleSocket, struct sockaddr *adress, int size)
{
	int reussite = connect(handleSocket, adress, size);
	if(reussite == -1)
	{
		printf("Erreur de connexion %d\n", errno);
		close(handleSocket);
		exit(1);
	}
}


void Send_Message(int handleCible, const void* message, int taillemessage, int flagUrg)
{
	int reussite = send(handleCible, message, taillemessage, flagUrg);
	if(reussite == -1)
	{
		printf("Erreur sur le send %d\n", errno);
		exit(1);
	}
}

void Receive_Message(int handleSource, void* message, int taillemessage, int flagUrgdest)
{
	int reussite = recv(handleSource, message, taillemessage, flagUrgdest);
	if(reussite == -1)
	{
		printf("Erreur sur le receive %d\n", errno);
		exit(1);
	}
	printf("message recu: %s\n", (char*)message);
}


properties Load_Properties(const char* nomFichier)
{
	properties prop;
	FILE *fp;

	fp = fopen(nomFichier, "r+t");
	if(fp == NULL)
	{
		fp = fopen(nomFichier, "w+t");

		char hostname[200];
		gethostname(hostname, 200);

		prop.machine = (char*)malloc(strlen(hostname));
		strcpy(prop.machine, hostname);
		prop.port = 50000;
		prop.nbServer = 5;

		fprintf(fp, "Host=");
		fprintf(fp, prop.machine, sizeof(prop.machine));
		fprintf(fp, ";\rPort=50000;\rServeurs=5;");
	}
	else
	{
		fseek(fp, 0, SEEK_END);
		int size = ftell(fp);
		rewind(fp);

		char txt[200];
		fread(txt, size, 1, fp);
		char* res = Read_Lines(1, txt);
		char* res1 = Read_Lines(2, txt);

		prop.machine = (char*)malloc(strlen(res));
		strcpy(prop.machine, res);

		prop.port = atoi(res1);
	}
	fclose(fp);

	return prop;
}

char* Read_Lines(int line, char* txt)
{
	char prop[200];
	char l;
	int i = 0, j = 0;
	while(i < line)
	{
		l = *txt;
		if(l == ':')
		{
			i++;
			txt++;
		}
		else
		{
			txt++;
		}
	}
	i = 0;
	while(i < 1)
	{
		l = *txt;
		if(l == ';')
		{
			i++;
		}
		else
		{
			prop[j] = *txt;
			j++;
			txt++;
		}
	}
	prop[j] = '\0';

char* ret = (char*)malloc(sizeof(prop));
strcpy(ret, prop);

	return ret;
}