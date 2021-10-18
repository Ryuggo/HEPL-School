#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>
#include<time.h>
#include <signal.h>
#include <mysql.h>

#include "Fichier.ini"
#include "Ecran.h"

int idMsg;
int idShm;
int 	CptCommandeEnCours = 0;
int 	CptCommandeTransmise = 0;
int idSem;
int process;

struct sembuf Sem;

int nbrSuiviCommande = 0;

MESSAGE	M;

TABSERVEUR*	s;
void AfficheTab();
int idFils;
MYSQL			*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;
char sauvcommande[50];

void Enleverfile(int);

int main(int argc,char* argv[])
{
int	rc,i,bol=0;
char requete[100],tmp[200];
int TetePipe[2];

struct sigaction Act;

Act.sa_handler = Enleverfile;
sigemptyset(&Act.sa_mask);
Act.sa_flags = 0;
sigaction(SIGINT,&Act,NULL);

if((idSem = semget(KEY,1,IPC_CREAT|IPC_EXCL|0600))==-1)
{//seconde et + exécution du serveur
	if((idSem = semget(KEY,1,0))==-1)
	{
		perror("Erreur lors de la création du sémaphore");
		exit(1);
	}
}
else
{//Juste après la création du sémaphore, donc ici première exécution du serveur
	if(semctl(idSem,0,SETVAL,0))
	{
		perror("Erreur d'initialisation du sémaphore");
	}
}

s = (TABSERVEUR*)malloc(sizeof(TABSERVEUR));
// Creation des ressources
if ((idMsg = msgget(KEY,IPC_CREAT|IPC_EXCL|0600)) == -1)
   { if ((idMsg = msgget(KEY,0)) == -1)
     exit(1);
   }

if((idShm = shmget(KEY,sizeof(TABSERVEUR),IPC_CREAT | IPC_EXCL | 0600))==-1)
{//seconde exécution ou +
	Trace("Déjà créé, donc reconnection...\n");
	if((idShm = shmget(KEY,0,0))==-1)
	{
		Trace("Erreur de connection\n");
		exit(1);
	}
	else
	{
		if((s = (TABSERVEUR*)shmat(idShm,NULL,0)) == (TABSERVEUR*)-1)
		{
			perror("Erreur de rattachement à la mémoire partagée");
			exit(1);
		}
		//Création serveur2
		if(s->Serveur2 == 0)
		{
			s->Serveur2 = getpid();
			if(kill(s->Serveur1,0) == -1)
			{//mort
				process = 2;
			}
			else
			{
				process = 1;
			}
		}
		else
		{//si déjà deux serv
			//Si Serv 2 existe déjà
			if(kill(s->Serveur1,0) == -1)
			{//1 est mort => nouveau serv a la place
				s->Serveur1 = getpid();
				if(kill(s->Serveur2,0) == -1)
				{
					process = 1;
				}
				else
				{
					process = 2;
				}
			}
			else
			{
				//Si Serv 1 existe déjà
				if(kill(s->Serveur2,0) == -1)
				{
					s->Serveur2 = getpid();
					process = 1;
				}
				else
				{
					Trace("Trop de serveur...");
					exit(1);
				}
			}
		}
	}
}
else
{//premiere exécution
	if((s = (TABSERVEUR*)shmat(idShm,NULL,0)) == (TABSERVEUR*)-1)
	{
		perror("Erreur de connection à la mémoire partagée");
		exit(1);
	}
	s->Serveur1 = getpid();
	process = 1;//1 pour serveur1
}

Sem.sem_num = 0;
Sem.sem_flg = SEM_UNDO;//quand prog s'arrete on remet le sem à 0 (annule toute les modif faite sur le semaphore dans le processus quand il s arrete)

if(s->Serveur1 == getpid())
{
	if(process==1)
	{
		Sem.sem_op = 1;
		if(semop(idSem, &Sem,1) != 0)
		{
			printf("Erreur SemOp1");
			exit(1);
		}
	}
	else
	{
		Sem.sem_op = 0;//wait
		if(semop(idSem,&Sem,1)!=0)
		{
			printf("Erreur SemOp2");
			exit(1);
		}
	}
}
else
{
	if(process==2)
	{
		Sem.sem_op = 1;
		if(semop(idSem, &Sem,1) != 0)
		{
			printf("Erreur SemOp3");
			exit(1);
		}
	}
	else
	{
		Sem.sem_op = 0;
		if(semop(idSem,&Sem,1)!=0)
		{
			printf("Erreur SemOp4");
			exit(1);
		}
	}
}
//remettre en attente les futurs serv
Sem.sem_op = 1;
if(semop(idSem,&Sem,1))
{
	printf("Erreur lors SemOp5");
	exit(1);
}
//Creation du pipe
if(pipe(TetePipe)==-1)
{
	printf("Erreur de pipe()...");
	exit(1);
}
// Creation des processus FacturationTransfert
if((idFils = fork())==-1)
{
	printf("Erreur de fork serveur fils");
}
else
{
	if(idFils == 0)//On est dans le fils serveur(donc le deuxieme)
	{
		if(close(TetePipe[0])!=0)
		{
			printf("Erreur de close du cote lecture");
			exit(1);
		}
//		if(close(TetePipe[1])==0)
//		{
//			printf("Erreur de close du cote ecriture");
//			exit(1);
//		}
		while(1)
		{
			//recois message de travail terminé
			if ((rc = msgrcv(idMsg,&M,TAILLECOMPLET,2,0)) == -1)
			{
				Trace("Err de msgrcv()");
				exit(1);
			}
			if(write(TetePipe[1],M.arg.Selection.S2,20) != 20)
			{
				printf("Erreur d'écriture dans le pipe");
				exit(1);
			}
		}
	}
	else//on est dans le pere serveur(donc le premier)
	{
		s->ServIntermediaire = idFils;	
	}
}

if((idFils = fork())==-1)
{
	printf("Erreur de fork facturation fils");
}
else
{
	if(idFils == 0)
	{
		tmp[0] = (char)TetePipe[0]+48;
		tmp[1] = '\0';
		execlp("FacturationTransfert","FacturationTransfert",tmp,(char*)NULL);
	}
}
// connexion a la base Dossier2020d
Connexion = mysql_init(NULL);

if (!mysql_real_connect(Connexion,"localhost","student","PassStudent","PourStudent",0,0,0))
	{ 
	Trace("Err de connexion  : %s\n",mysql_error(Connexion));
	exit(1);
	}

AfficheTab();
	   
while(1)
{
if ((rc = msgrcv(idMsg,&M,TAILLECOMPLET,1,0)) == -1)
   {
   Trace("Err de msgrcv()");
   exit(1);
   }
switch(M.Requete)
	{
	case NEWAFFICHAGE:
		Trace("Message NEWAFFICHAGE");

		break;
		
	case NEWADMIN:
		Trace("Message NEWADMIN %d",rc);
		s->Administrateur1 = M.idPid;
		if (mysql_query(Connexion,"select * from Dossier2020 where AEffectuer = 1;"))
		{ 
			printf("Err de insert : %s\n",mysql_error(Connexion));
			exit(1);
		}
		
		Resultat = mysql_store_result(Connexion);
		
		for(i=0,bol=0;i<4 && bol==0;i++)
		{
			if((Ligne = mysql_fetch_row(Resultat))==NULL)
			{
				bol=1;
			}
			else
			{
				M.arg.N = atoi(Ligne[0]);
				strcpy(M.arg.C.NomC,Ligne[1]);
		
				M.Type = s->Administrateur1;
				M.idPid = getpid();
				M.Requete = NEWCOMMANDE;
				
				strcpy(M.arg.C.E[0],Ligne[2]);
				strcpy(M.arg.C.E[1],Ligne[4]);
				strcpy(M.arg.C.E[2],Ligne[6]);
				strcpy(M.arg.C.E[3],Ligne[8]);
				M.arg.C.T[0]=atoi(Ligne[3]);
				M.arg.C.T[1]=atoi(Ligne[5]);
				M.arg.C.T[2]=atoi(Ligne[7]);
				M.arg.C.T[3]=atoi(Ligne[9]);
				
				if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
				{
					perror("Erreur lors de l'envoi NewPersonnel");
					exit(1);
				}
	
				sleep(1);
				kill(s->Administrateur1,SIGUSR1);
			}
		}
		break;
		
	case NEWPERSONNEL:
	
		Trace("Message NEWPERSONNEL (%s) %d ",M.arg.Selection.S1,sizeof(M));
		for(i=0,bol=0;i<4 && bol == 0;i++)
		{
			if(s->Tab[i].idPid == 0)
			{
				s->Tab[i].idPid = M.idPid;
				strcpy(s->Tab[i].Nom,M.arg.Selection.S1);
				bol = 1;
			}
		}
		if(bol==0)
		{
			perror("Trop de personnel,impossible d'en rajouter un");
		}
		else
		{
			//je fais M parce que c'est le même que celui qu'on reçoit( ca évite de répéter)
			M.idPid = getpid();
			M.Type = s->Administrateur1;
			
			if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
			{
				perror("Erreur lors de l'envoi NewPersonnel");
				exit(1);
			}
			
			kill(s->Administrateur1,SIGUSR1); 
		}
			
		break;
	case AJOUTCOMMANDE:
		Trace("Reception AJOUTCOMMANDE");
		strcpy(requete,"select NomCommande from Dossier2020 where NomCommande='");
		strcat(requete,M.arg.C.NomC);
		strcat(requete,"';");
		if (mysql_query(Connexion,requete))
		{ 
			printf("Err de select ajout commande : %s\n",mysql_error(Connexion));
			exit(1);
		}
		
		Resultat = mysql_store_result(Connexion);
		for(i=1,bol=0;(Ligne=mysql_fetch_row(Resultat))!=NULL && bol == 0;i++)
		{
			if(strcmp(Ligne[0],M.arg.C.NomC)==0)
			{
				bol=1;
				Trace("Commande déjà existante");
			}
		}
		if(bol == 1)
		{
			printf("Erreur, commande déjà existante");
		}
		else
		{
			strcpy(requete,"insert into Dossier2020 values (NULL,'");
			strcat(requete,M.arg.C.NomC);
			strcat(requete,"','");
		
			if(M.arg.C.E[0] != NULL)
			{
				strcat(requete,M.arg.C.E[0]);
			}
		
			strcat(requete,"',");
		
			if(M.arg.C.T[0] != -1)
			{
				tmp[0] = (char)(M.arg.C.T[0]+48);
				tmp[1] = '\0';
				strcat(requete,tmp);
			}
			else
			{
				strcat(requete,"0");
			}
		
			strcat(requete,",'");
		
			if(M.arg.C.E[1] != NULL)
			{
				strcat(requete,M.arg.C.E[1]);
			}
		
			strcat(requete,"',");
		
			if(M.arg.C.T[1] != -1)
			{
				tmp[0] = (char)(M.arg.C.T[1]+48);
				tmp[1] = '\0';
				strcat(requete,tmp);
			}
			else
			{
				strcat(requete,"0");
			}
		
			strcat(requete,",'");
		
			if(M.arg.C.E[2] != NULL)
			{
				strcat(requete,M.arg.C.E[2]);
			}
		
			strcat(requete,"',");
		
			if(M.arg.C.T[2] != -1)
			{
				tmp[0] = (char)(M.arg.C.T[2]+48);
				tmp[1] = '\0';
				strcat(requete,tmp);
			}
			else
			{
				strcat(requete,"0");
			}
		
			strcat(requete,",'");
		
			if(M.arg.C.E[3] != NULL)
			{
				strcat(requete,M.arg.C.E[3]);
			}
		
			strcat(requete,"',");
		
			if(M.arg.C.T[3] != -1)
			{
				tmp[0] = (char)(M.arg.C.T[3]+48);
				tmp[1] = '\0';
				strcat(requete,tmp);
			}
			else
			{
				strcat(requete,"0");
			}
		
			strcat(requete,",1,1);");
		
			if (mysql_query(Connexion,requete))
			{ 
				printf("Err de insert : %s\n",mysql_error(Connexion));
				exit(1);
			}
		
			M.idPid = getpid();
			M.Type = s->Administrateur1;
			M.Requete = NUMEROCOMMANDE;
		
			if (mysql_query(Connexion,"select max(id) from Dossier2020;"))
			{ 
				printf("Err de select : %s\n",mysql_error(Connexion));
				exit(1);
			}
		
			Resultat = mysql_store_result(Connexion);
			Ligne = mysql_fetch_row(Resultat);
		
			strcpy(M.arg.Selection.S1,Ligne[0]);
			
			if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
			{
				perror("Erreur lors de l'envoi NewPersonnel");
				exit(1);
			}
		
			CptCommandeTransmise++;
			sleep(1);
			kill(s->Administrateur1,SIGUSR1);
		}
		break;
		
	case TRANSMISSIONCOMMANDE:
		Trace("Message TRANSMISSIONCOMMANDE");
		Trace("Employe : %s",M.arg.Selection.S2);
		Trace("Commande : %s",M.arg.C.NomC);
		strcpy(requete,"select * from Dossier2020 where NomCommande = ");
		strcat(requete,"'");
		strcat(requete,M.arg.C.NomC);
		strcat(requete,"';");
		
		if (mysql_query(Connexion,requete))
		{ 
			printf("Err de select * : %s\n",mysql_error(Connexion));
			exit(1);
		}
		
		Resultat = mysql_store_result(Connexion);
		
		if((Ligne = mysql_fetch_row(Resultat))==NULL)
		{
			bol=1;
		}
		else
		{
			M.arg.N = atoi(Ligne[0]);
			strcpy(M.arg.C.NomC,Ligne[1]);
			
			for(i=0,bol=-1;i<4 && bol == -1;i++)
			{
				if(strcmp(s->Tab[i].Nom,M.arg.Selection.S2) == 0)
				{
					bol = i;
				}
			}
			if(bol != -1)
			{
				M.Type = s->Tab[bol].idPid;
				M.idPid = getpid();
			}
			
			strcpy(M.arg.C.E[0],Ligne[2]);
			strcpy(M.arg.C.E[1],Ligne[4]);
			strcpy(M.arg.C.E[2],Ligne[6]);
			strcpy(M.arg.C.E[3],Ligne[8]);
			M.arg.C.T[0]=atoi(Ligne[3]);
			M.arg.C.T[1]=atoi(Ligne[5]);
			M.arg.C.T[2]=atoi(Ligne[7]);
			M.arg.C.T[3]=atoi(Ligne[9]);
			
			if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
			{
				perror("Erreur lors de l'envoi TransmissionCommande");
				exit(1);
			}
			CptCommandeTransmise--;
//			sleep(1);
			kill(s->Tab[bol].idPid,SIGUSR1);
		}
		
		break;
		
//	case NEWCOMMANDE:
//		Trace("Message NEWCOMMANDE %d ",rc);
//		break;
//		
//	case NUMEROCOMMANDE:
//		Trace("Message NUMEROCOMMANDE %d ",rc);
//		
//		break;
	
	case SUIVICOMMANDE:			
		Trace("Message SUIVICOMMANDE");
		Trace("%d",M.idPid);
		if(nbrSuiviCommande <= 4)
		{
//			if(M.idPid != getpid())
//			{
//				i=0;
				while(i<4)
				{
				
					if(s->Suivi[i].idPid == 0)
					{
						strcpy(s->Suivi[i].Nom,M.arg.C.NomC);
						s->Suivi[i].idPid = M.idPid;
						i = 4;
						nbrSuiviCommande++;
					}
					else
					{
						i++;
					}
				}
//			}
			strcpy(requete,"select * from Dossier2020 where NomCommande =");
			strcat(requete,"'");
			strcat(requete,M.arg.C.NomC);
			strcat(requete,"';");
			Trace("%s",requete);
			if (mysql_query(Connexion,requete))
			{ 
				printf("Err de select * : %s\n",mysql_error(Connexion));
				exit(1);
			}
			Resultat = mysql_store_result(Connexion);
			if((Ligne = mysql_fetch_row(Resultat))==NULL)
			{
				printf("Erreur de select*");
			}
			else
			{
				M.Requete = SUIVICOMMANDE;
				M.Type = M.idPid;
				Trace("%d",M.Type);
				M.idPid = getpid();
				strcpy(M.arg.C.NomC,Ligne[1]);
			
				strcpy(M.arg.C.E[0],Ligne[2]);
				strcpy(M.arg.C.E[1],Ligne[4]);
				strcpy(M.arg.C.E[2],Ligne[6]);
				strcpy(M.arg.C.E[3],Ligne[8]);
				
				M.arg.C.T[0]=atoi(Ligne[3]);
				M.arg.C.T[1]=atoi(Ligne[5]);
				M.arg.C.T[2]=atoi(Ligne[7]);
				M.arg.C.T[3]=atoi(Ligne[9]);
			
				if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
				{
					perror("Erreur lors de l'envoi SuiviCommande");
					exit(1);
				}
				Trace("%d",atoi(Ligne[11]));
				if((atoi(Ligne[11])) == 0)
				{
					M.arg.N = 0;
				}
				else
				{
					M.arg.N = 1;
				}
				M.Requete = COMMANDELIVREE;
				//le type est dejà dedans
				//pareil pour le pid
				if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
				{
					perror("Erreur lors de l'envoi SuiviCommande");
					exit(1);
				}
	//			sleep(1);
			}
		}
		else
		{
			printf("Plus de places pour la fenêtre suivi commande");
		}
		
		break;
	
	case FINSUIVICOMMANDE:			
		Trace("Message FINSUIVICOMMANDE");
		
		for(i=0,bol=0;i<4 && bol==0;i++)
		{
			if(s->Suivi[i].idPid == M.idPid)
			{
				bol =1;
			}
		}
		i--;
		if(bol==1)
		{
			s->Suivi[i].idPid = 0;
			nbrSuiviCommande--;
		}
		
		break;
	
	case ETAPEEFFECTUEE:			
		Trace("Message ETAPEEFFECTUEE");
		
		i = (int)M.arg.Selection.S1[0] - 48;
		tmp[0] = (char)i + 48;
		tmp[1] = '\0';
		strcpy(requete,"update Dossier2020 set T");
		strcat(requete,tmp);
		strcat(requete,"= 0 where NomCommande ='");
		strcat(requete,M.arg.Selection.S2);
		strcat(requete,"';");
		Trace("%s",requete);
		if (mysql_query(Connexion,requete))
		{ 
			printf("Err de update : %s\n",mysql_error(Connexion));
			exit(1);
		}
		
		//Renvois d'un message vers le serv pour faire suivicommande et qu'elle s'update en temps réel //Etape effectuée
//		M.Type = 1;
//		M.idPid = getpid();
//		M.Requete = SUIVICOMMANDE;
//		
//		if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
//		{
//			perror("Erreur lors de l'envoi SuiviCommande EtapeEffectuée");
//			exit(1);
//		}
		
		break;
	
	case COMMANDELIVREE:			
		Trace("Message COMMANDELIVREE");
		if(M.idPid != getpid())
		{
			strcpy(requete,"update Dossier2020 set ALivre = 0 where NomCommande = '");
			strcat(requete,M.arg.Selection.S2);
			strcat(requete,"';");
			if (mysql_query(Connexion,requete))
			{ 
				printf("Err de update : %s\n",mysql_error(Connexion));
				exit(1);
			}
		}
		//Renvois d'un message vers le serv pour faire suivicommande et qu'elle s'update en temps réel //Commande livrée
//		M.Type = 1;
//		M.idPid = getpid();
//		M.Requete = SUIVICOMMANDE;
//		
//		if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
//		{
//			perror("Erreur lors de l'envoi SuiviCommande CommandeLivrée");
//			exit(1);
//		}
		
		break;
		
	case EVOLUTIONTRAVAIL:
		Trace("Message EVOLUTIONTRAVAIL");
		
		break;
		
	case TRAVAILTERMINER:
		Trace("Message TRAVAILTERMINER");
		strcpy(sauvcommande,M.arg.Selection.S2);
		strcpy(requete,"update Dossier2020 set AEffectuer = 0 where NomCommande = '");
		strcat(requete,M.arg.Selection.S2);
		strcat(requete,"';");
		
		if (mysql_query(Connexion,requete))
		{ 
			printf("Err de update : %s\n",mysql_error(Connexion));
			exit(1);
		}
		//selection toutes les commandes encore à faire
		strcpy(requete,"Select NomCommande from Dossier2020 where AEffectuer = 1;");
		if(mysql_query(Connexion,requete))
		{
			printf("Erreur de select pour les commandes dans la base de donnée");
		}
		Resultat = mysql_store_result(Connexion);
		for(i=1;(Ligne=mysql_fetch_row(Resultat))!=NULL && i < 4;i++)
		{
		}
		//recherche dans la base de donnée une potentielle nouvelle commande à faire
		if(i == 4)
		{
			//copie le nom de la commande 
			strcpy(M.arg.Selection.S2,Ligne[0]);
		}
		else
		{
			strcpy(M.arg.Selection.S2,"");
		}
		
		//Recherche du personnel qui a finit son travail pour le remettre dans admin
		
		for(i=0,bol = 0;i< 4 && bol==0;i++)
		{
			if(M.idPid == s->Tab[i].idPid)
			{
				strcpy(M.arg.Selection.S1,s->Tab[i].Nom);
				bol=1;
			}
		}
		
		M.Requete = TRAVAILTERMINER;
		M.idPid = getpid();
		M.Type = s->Administrateur1;
		
		if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
		{
			perror("Erreur lors de l'envoi TravailTerminer");
			exit(1);
		}
		
		sleep(1);
		CptCommandeEnCours--;
		kill(s->Administrateur1,SIGUSR1);
		
		
		//Envois du message pour serv intermédiare et pour facturation transfert
		M.idPid = getpid();
		M.Type = 2;
		strcpy(M.arg.Selection.S2,sauvcommande);
		
		if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
		{
			perror("Erreur lors de l'envoi FacturationTransfert");
			exit(1);
		}
		
		break;
		
	case SUPPRESSIONTRAVAIL:
		Trace("Message SUPPRESSIONTRAVAIL");
		
		break;
	
	case FINPERSONNEL:
		Trace("Message FINPERSONNEL");
	
		for(i=0,bol=0;i<4 && bol==0;i++)
		{
			if(s->Tab[i].idPid == M.idPid)
			{
				bol =1;
			}
		}
		i--;
		if(bol==1)
		{
			s->Tab[i].idPid = 0;
		}
		else
		{
			printf("Erreur !");
		}
		if(strcmp(M.arg.Selection.S1,"Unfinished")==0)
		{
			strcpy(M.arg.Selection.S2,M.arg.Selection.S2);//Ne sert à rien mais m'aide pour la relecture
			CptCommandeTransmise++;
		}
		else
		{
			strcpy(M.arg.Selection.S2,"");
		}
		
		M.Type = s->Administrateur1;
		M.Requete = FINPERSONNEL;
		M.idPid = getpid();
		strcpy(M.arg.Selection.S1,s->Tab[i].Nom);
		
		if(msgsnd(idMsg,&M,sizeof(M) - sizeof(long),0) == -1)
		{
			perror("Erreur lors de l'envoi FinPersonnel");
			exit(1);
		}
		
		kill(s->Administrateur1,SIGUSR1);
		
		break;
	
	}

AfficheTab();
}

// Fin du processus Serveur1
}

void AfficheTab()
{
int i = 0;
printf("\tpid du Serveur1 :         %d\n",s->Serveur1);
printf("\tpid du Serveur2 :         %d\n",s->Serveur2);
printf("\tpid du ServIntermediaire :%d\n",s->ServIntermediaire);
printf("\tpid du Administrateur1 :  %d\n",s->Administrateur1);
printf("\tpid du ServiceCommande :  %d\n",s->ServiceCommande);
printf("\tpid du Affichage :        %d\n",s->Affichage[0]);
printf("\tTab Utilisateurs:\n");
while (i < NBMAX) 
   { 
   if (s->Tab[i].idPid != 0) 
		{
		printf("\t(i : %d)",i); 
		printf("\t%5d -%s- \n",
		s->Tab[i].idPid,s->Tab[i].Nom);
		}
   i++;
   }
printf("\tTab Suivi:\n");
i = 0;
while (i < NBMAX) 
   { 
   if (s->Suivi[i].idPid != 0) 
		{
		printf("\t(i : %d)",i); 
		printf("\t%5d -%s- \n",
		s->Suivi[i].idPid,s->Suivi[i].Nom);
		}
   i++;
   }
return ;
}

void Enleverfile(int sig)
{
	if(msgctl(idMsg,IPC_RMID,0))
	{
		perror("Erreur de suppression de file");
		exit(1);
	}
	if(shmctl(idShm,IPC_RMID,0))
	{
		perror("Erreur de suppression de mémoire partagée");
		exit(1);
	}
	if(semctl(idSem,1,IPC_RMID,0))
	{
		perror("Erreur de suppression des sémaphore");
		exit(1);
	}
}

