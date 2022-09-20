#include "reseaux.h"

int main(void)
{
	int ip;
	struct sockaddr_in adresse;
	properties prop;
	struct in_addr adresseIP;

	char msgClient[MAXSTRING] = "bonjour petite peruche";


	ip = Create_Socket(AF_INET, SOCK_STREAM, 0);

	adresse = Infos_Host();
	adresseIP = adresse.sin_addr;

	Connect_Client(ip, (struct sockaddr*)&adresse, sizeof(struct sockaddr_in));

	Send_Message(ip, msgClient, MAXSTRING, 0);


	return EXIT_SUCCESS;
}
