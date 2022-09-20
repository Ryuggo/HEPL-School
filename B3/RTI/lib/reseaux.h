#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>

#include <sys/types.h>
#include <sys/socket.h>
//#include <sys/stat.h>
//#include <fcntl.h>
#include <errno.h>

//#include <fstream>
#include <unistd.h>
//#include <iostream>

#define MAXSTRING 100

#define FILENAME "properties.txt"


typedef struct properties {
	char* machine = NULL;
	int port;
	int nbServer;
} properties;


int Create_Socket(int domain, int type, int protocol);
sockaddr_in Infos_Host();
void Bind_Socket(int handleSocket, const struct sockaddr *adress, int size);

void Listen_Server(int handleSocket, int nbConnection);
int Accept_Server(int handleSocket, struct sockaddr *adress, int size);

void Connect_Client(int handleSocket, struct sockaddr *adress, int size);

void Send_Message(int handleCible, const void* message, int taillemessage, int flagUrg);
void Receive_Message(int handleSource, void* message, int taillemessage, int flagUrgdest);

properties Load_Properties(const char* nomFichier);
char* Read_Lines(int line, char* txt);