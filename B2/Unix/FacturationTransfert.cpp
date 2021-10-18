#include <stdio.h>
#include <unistd.h>
#include "Fichier.ini"
int idMsg;
MESSAGE	M;
#include "Ecran.h"
char Buff[255];
int TetePipe[2];

int main(int argc,char*	argv[])
{
Trace("Debut");
TetePipe[0] = atoi(argv[1]);
if ((idMsg = msgget(KEY,0)) == -1)
   { perror("Err. de msgget()");
     exit(1);
   }
while(1)
	{
//	Lecture dans le pipe
	if(read(TetePipe[0],Buff,20) < 0)
	{
		Trace("Erreur de lecture");
		exit(1);
	}
	
	sleep(10);
// signaler que la commande est livree
	M.Requete = COMMANDELIVREE;
	M.Type = 1;
	M.idPid = getpid();
	strcpy(M.arg.Selection.S2,Buff);
	Trace("%s",Buff);
	if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
	{
		perror("Erreur lors de l'envoi CommandeLivrée");
		exit(1);
	}
	
	}
exit(0);
}
