.SILENT:

all : Serveur Administrateur FenetrePersonnel SuiviCommande FacturationTransfert CreationSessionMysql

Ecran.o : /export/home/student/Ecran/Ecran.cpp /export/home/student/Ecran/Ecran.h
	echo Création de Ecran.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c /export/home/student/Ecran/Ecran.cpp -D SUN
	
Serveur : Ecran.o Serveur.cpp 
	echo Creation de Serveur
	g++ -m64 -Wall -I /export/home/student/Ecran -o Serveur Serveur.cpp \
-I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient\
   -lthread -lsocket -lnsl -lm  -I /export/home/student/Ecran Ecran.o
   
mainAdministrateur.o : mainAdministrateur.cpp 
	echo Creation de mainAdministrateur.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/export/home/student/Ecran -I. -I. -I/usr/include -I/usr/X11/include -o mainAdministrateur.o mainAdministrateur.cpp
	
windowadministrateur.o : windowadministrateur.cpp
	echo Creation de windowadministrateur.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I /export/home/student/Ecran -I. -I. -I/usr/include -I/usr/X11/include -o windowadministrateur.o windowadministrateur.cpp	

moc_windowadministrateur.o : moc_windowadministrateur.cpp
	echo Creation de moc_windowadministrateur.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I. -I. -I/usr/include -I/usr/X11/include -o moc_windowadministrateur.o moc_windowadministrateur.cpp
	
Administrateur : mainAdministrateur.o windowadministrateur.o Ecran.o moc_windowadministrateur.o
	echo Creation de Administrateur
	g++ -m64 -Wall -I /export/home/student/Ecran -Wl,-R,/opt/Qt4.8/lib -o Administrateur mainAdministrateur.o  windowadministrateur.o Ecran.o  moc_windowadministrateur.o    -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

mainFenetrePersonnel.o : mainFenetrePersonnel.cpp 
	echo Creation de mainFenetrePersonnel.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/export/home/student/Ecran -I. -I. -I/usr/include -I/usr/X11/include -o mainFenetrePersonnel.o mainFenetrePersonnel.cpp

windowFenetrePersonnel.o : windowFenetrePersonnel.cpp windowFenetrePersonnel.h
	echo Creation de windowFenetrePersonnel.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I /export/home/student/Ecran -I. -I. -I/usr/include -I/usr/X11/include -o windowFenetrePersonnel.o windowFenetrePersonnel.cpp

moc_windowFenetrePersonnel.o: moc_windowFenetrePersonnel.cpp
	echo Creation de moc_windowFenetrePersonnel.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I. -I. -I/usr/include -I/usr/X11/include -o moc_windowFenetrePersonnel.o moc_windowFenetrePersonnel.cpp

FenetrePersonnel : mainFenetrePersonnel.o  windowFenetrePersonnel.o Ecran.o  moc_windowFenetrePersonnel.o 
	echo Creation de FenetrePersonnel
	g++ -m64 -Wall -I /export/home/student/Ecran -Wl,-R,/opt/Qt4.8/lib -o FenetrePersonnel mainFenetrePersonnel.o  windowFenetrePersonnel.o Ecran.o  moc_windowFenetrePersonnel.o    -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

mainsuivicommande.o : mainsuivicommande.cpp
	echo Creation de mainsuivicommande.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I/export/home/student/Ecran -I. -I. -I/usr/include -I/usr/X11/include -o mainsuivicommande.o mainsuivicommande.cpp

windowsuivicommande.o : windowsuivicommande.cpp windowsuivicommande.h
	echo Creation de windowsuivicommande.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I /export/home/student/Ecran -I. -I. -I/usr/include -I/usr/X11/include -o windowsuivicommande.o windowsuivicommande.cpp

moc_windowsuivicommande.o : moc_windowsuivicommande.cpp
	echo Creation de moc_windowFenetrePersonnel.o
	g++ -m64 -Wall -I /export/home/student/Ecran -c -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -I/opt/Qt4.8/mkspecs/solaris-g++-64 -I. -I/opt/Qt4.8/include/QtCore -I/opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I. -I. -I. -I/usr/include -I/usr/X11/include -o moc_windowsuivicommande.o moc_windowsuivicommande.cpp

SuiviCommande : mainsuivicommande.o  windowsuivicommande.o Ecran.o  moc_windowsuivicommande.o
	echo Creation de SuiviCommande
	g++ -m64 -Wall -I /export/home/student/Ecran -Wl,-R,/opt/Qt4.8/lib -o SuiviCommande mainsuivicommande.o  windowsuivicommande.o Ecran.o  moc_windowsuivicommande.o    -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 -L/usr/X11/lib/64 -lQtCore -lpthread -lrt

FacturationTransfert : FacturationTransfert.cpp
	echo Creation de FacturationTransfert
	g++ -m64 -Wall -I /export/home/student/Ecran -o FacturationTransfert FacturationTransfert.cpp Ecran.o

CreationSessionMysql : CreationSessionMysql.cpp Ecran.o
	echo creation de CreationSessionMysql
	g++ -o CreationSessionMysql CreationSessionMysql.cpp Ecran.o -m64 -I /usr/mysql/5.6/include -L/usr/mysql/5.6/lib/amd64 -R/usr/mysql/5.6/lib/amd64 -lmysqlclient   -lthread -lsocket -lnsl -lm 


