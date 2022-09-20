#include "reseaux.h"

int main(void)
{
	int ip, hSocketService;
	struct sockaddr_in adresse;
	properties prop;

	char msgClient[MAXSTRING];


	ip = Create_Socket(AF_INET, SOCK_STREAM, 0);

	adresse = Infos_Host();

	Bind_Socket(ip, (struct sockaddr*)&adresse, sizeof(struct sockaddr_in));

	Listen_Server(ip, SOMAXCONN);

	hSocketService = Accept_Server(ip, (struct sockaddr*)&adresse, sizeof(struct sockaddr_in));

	Receive_Message(hSocketService, msgClient, MAXSTRING, 0);


	return EXIT_SUCCESS;
}
