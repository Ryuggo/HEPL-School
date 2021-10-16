.SILENT:
UTILE=./Utile

GRAPH1D=./Graph/Graph1DDiscret
GRAPH1C=./Graph/Graph1DContinu
GRAPH2D=./Graph/Graph2D
#GRAPH = $(GRAPH1D) 

OBJS= Data1D.o Data2D.o EtudeStatDescriptive.o EtudeStat1D.o EtudeStat2D.o\
	 DataSource.o DataSourceSerieDiscrete.o DataSourceSerieContinue.o\
	DataSourceSerie2D.o ListeBase.o Liste.o ListeTriee.o Echantillon.o BaseException.o \
	graphstat1ddiscrete.o moc_graphstat1ddiscrete.o graphstat1dcontinue.o moc_graphstat1dcontinue.o \
	graphstat2d.o moc_graphstat2d.o 

QTLIB= -L/usr/lib/64 -L/usr/X11/lib/64 -L/opt/Qt4.8/lib -lQtGui -L/opt/Qt4.8/lib -L/usr/lib/64 \
	-L/usr/X11/lib/64 -lQtCore -lpthread -lrt 

QTINCLUDE=-I /opt/Qt4.8/mkspecs/solaris-g++-64 -I . -I /opt/Qt4.8/include/QtCore \
	-I /opt/Qt4.8/include/QtGui -I/opt/Qt4.8/include -I /usr/include: -I usr/X11/include 

GCC=g++ -m64 -Wall -I $(UTILE) $(QTINCLUDE) -I $(GRAPH1D) -I$(GRAPH1C) -I$(GRAPH2D) 

QTGCC=$(GCC) -D_XOPEN_SOURCE=600 -D__EXTENSIONS__ -O2 -Wall -W -D_REENTRANT -DQT_NO_DEBUG \
	-DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED

Applic:	Applic.cpp $(OBJS)
	echo Creation de Applic
	$(GCC) -o Applic Applic.cpp $(OBJS) $(QTLIB) -Wl,-R,/usr/local/Trolltech/Qt-4.8.6/lib

EtudeStatDescriptive.o:	$(UTILE)/EtudeStatDescriptive.cpp $(UTILE)/EtudeStatDescriptive.h
	echo Creation de EtudeStatDescriptive.o
	$(GCC) $(UTILE)/EtudeStatDescriptive.cpp -c
	
BaseException.o:	$(UTILE)/BaseException.cpp $(UTILE)/BaseException.h
	echo Creation de BaseException.o
	$(GCC) $(UTILE)/BaseException.cpp -c
	
EtudeStat1D.o:	$(UTILE)/EtudeStat1D.cpp $(UTILE)/EtudeStat1D.h
	echo Creation de EtudeStat1D.o
	$(GCC) $(UTILE)/EtudeStat1D.cpp -c
		
EtudeStat2D.o:	$(UTILE)/EtudeStat2D.cpp $(UTILE)/EtudeStat2D.h
	echo Creation de EtudeStat2D.o
	$(GCC) $(UTILE)/EtudeStat2D.cpp -c
	
Echantillon.o:	$(UTILE)/Echantillon.cpp $(UTILE)/Echantillon.h
	echo Creation de Echantillon.o
	$(GCC) $(UTILE)/Echantillon.cpp -c

Data1D.o:	$(UTILE)/Data1D.cpp $(UTILE)/Data1D.h
	echo Creation de Data1D.o
	$(GCC) $(UTILE)/Data1D.cpp -c
		
Data2D.o:	$(UTILE)/Data2D.cpp $(UTILE)/Data2D.h
	echo Creation de Data2D.o
	$(GCC) $(UTILE)/Data2D.cpp -c
	
DataSource.o:	$(UTILE)/DataSource.cpp $(UTILE)/DataSource.h
	echo Creation de DataSource.o
	$(GCC) $(UTILE)/DataSource.cpp -c

DataSourceSerieDiscrete.o:	$(UTILE)/DataSourceSerieDiscrete.cpp $(UTILE)/DataSourceSerieDiscrete.h
	echo Creation de DataSourceSerieDiscrete.o
	$(GCC) $(UTILE)/DataSourceSerieDiscrete.cpp -c

DataSourceSerieContinue.o:	$(UTILE)/DataSourceSerieContinue.cpp $(UTILE)/DataSourceSerieContinue.h
	echo Creation de DataSourceSerieContinue.o
	$(GCC) $(UTILE)/DataSourceSerieContinue.cpp -c
	
DataSourceSerie2D.o:	$(UTILE)/DataSourceSerie2D.cpp $(UTILE)/DataSourceSerie2D.h
	echo Creation de DataSourceSerie2D.o
	$(GCC) $(UTILE)/DataSourceSerie2D.cpp -c
		
Liste.o:	$(UTILE)/Liste.cpp $(UTILE)/Liste.h
	echo Creation de Liste.o
	$(GCC) $(UTILE)/Liste.cpp -c
	
ListeBase.o:	$(UTILE)/ListeBase.cpp $(UTILE)/ListeBase.h
	echo Creation de ListeBase.o
	$(GCC) $(UTILE)/ListeBase.cpp -c

ListeTriee.o:	$(UTILE)/ListeTriee.cpp $(UTILE)/ListeTriee.h
	echo Creation de ListeTriee.o
	$(GCC) $(UTILE)/ListeTriee.cpp -c
	
# creation des .o relatifs aux graphiques
graphstat1ddiscrete.o: $(GRAPH1D)/graphstat1ddiscrete.cpp
	echo creation de graphstat1ddiscrete.o
	$(QTGCC)  $(GRAPH1D)/graphstat1ddiscrete.cpp -c

moc_graphstat1ddiscrete.o: $(GRAPH1D)/moc_graphstat1ddiscrete.cpp
	echo creation de moc_graphstat1ddiscrete.o
	$(QTGCC)   $(GRAPH1D)/moc_graphstat1ddiscrete.cpp -c
	
graphstat1dcontinue.o: $(GRAPH1C)/graphstat1dcontinue.cpp
	echo creation de graphstat1dcontinue.o
	$(QTGCC)  $(GRAPH1C)/graphstat1dcontinue.cpp -c

moc_graphstat1dcontinue.o: $(GRAPH1C)/moc_graphstat1dcontinue.cpp
	echo creation de moc_graphstat1dcontinue.o
	$(QTGCC)   $(GRAPH1C)/moc_graphstat1dcontinue.cpp -c

graphstat2d.o: $(GRAPH2D)/graphstat2d.cpp $(GRAPH2D)/graphstat2d.h
	echo creation de graphstat2d.o
	$(QTGCC)   $(GRAPH2D)/graphstat2d.cpp -c

moc_graphstat2d.o: $(GRAPH2D)/moc_graphstat2d.cpp
	echo creation de moc_graphstat2d.o
	$(QTGCC) $(GRAPH2D)/moc_graphstat2d.cpp -c



