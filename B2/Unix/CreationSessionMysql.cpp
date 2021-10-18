#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <time.h>
#include <string.h>

MYSQL			*Connexion;
MYSQL_RES	*Resultat;
MYSQL_ROW	Ligne;
int main(int argc,char *argv[])
{

Connexion = mysql_init(NULL);
mysql_real_connect(Connexion,"localhost","student","PassStudent","PourStudent",0,0,0);
if (mysql_query(Connexion,"drop table Dossier2020;"))
	{ 
	printf("Err de drop : %s\n",mysql_error(Connexion));
	exit(1);
	}

if (mysql_query(Connexion,"create table Dossier2020 (id INT(4) auto_increment primary key,\
	NomCommande varchar(12),C1 varchar(12),T1 INT(4),C2 varchar(12),T2 INT(4),C3 varchar(12),T3 INT(4),\
 C4 varchar(12),T4 INT(4),AEffectuer INT(4),ALivre INT(4));"))
	{ 
	printf("Err de create : %s\n",mysql_error(Connexion));
	exit(1);
	}
	
if (mysql_query(Connexion,"insert into Dossier2020 values (NULL,'Commande1','Etape 1',6,\
	'Etape 2',4,'Etape 3',6,'',0,1,1);"))
	{ 
	printf("Err de insert : %s\n",mysql_error(Connexion));
	exit(1);
	}
	
if (mysql_query(Connexion,"insert into Dossier2020 values (NULL,'Commande2','Et 1',3,\
	'Et 2',4,'',0,'',0,1,1);"))
	{ 
	printf("Err de insert : %s\n",mysql_error(Connexion));
	exit(1);
	}

if (mysql_query(Connexion,"insert into Dossier2020 values (NULL,'Commande3','Et 1',1,\
	'Et 2',1,'Et3',4,'Et4',5,1,1);"))
	{ 
	printf("Err de insert : %s\n",mysql_error(Connexion));
	exit(1);
	}
exit(0);
}
