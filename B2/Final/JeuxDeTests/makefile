.SILENT:

OBJ	= Couleur.o	Ecran.o Point.o		Figure.o Pixel.o Ligne.o Rectangle.o		BaseException.o InvalidColorException.o DessinException.o	ListeBase.o Liste.o Pile.o Iterateur.o		Dessin.o	Bouton.o BoutonCouleur.o ToolBar.o
OBJSDL	= WindowSDL.o WindowSDLclick.o WindowSDLexception.o WindowSDLimage.o

CLASSES = $(HOME)/Documents/Hepl-Sun-2020/C++/Classes
EXCEPT = $(HOME)/Documents/Hepl-Sun-2020/C++/Exceptions
TEMPLATES = $(HOME)/Documents/Hepl-Sun-2020/C++/Templates
WINDOWSDL = $(HOME)/Documents/Hepl-Sun-2020/C++/WindowSDL
ECRAN = $(HOME)/Ecran

GPP		= g++ -m64 -Wall -D SUN -D CPP -I $(WINDOWSDL) -I $(CLASSES) -I $(ECRAN) -I $(EXCEPT) -I $(TEMPLATES) -lSDL -lpthread #-D DEV

#-----------------------------------------------------#

All : Test1 Test2 Test3 Test4 Test5 Test6 Test7 Test8 Test9

#Clear : rm $(OBJ)
#	rm Test1
#	rm Test2
#	rm Test3
#	rm Test4
#	rm Test5
#	rm Test6
#	rm Test7
#	rm Test8
#	rm Test9
#	echo Fichier supprimer
	
#-----------------------------------------------------#

Test1 : Test1.cpp $(OBJ) $(OBJSDL)
	echo Création de Test1
	$(GPP) -o Test1 Test1.cpp $(OBJ) $(OBJSDL)
	
Test2 : Test2.cpp $(OBJ) $(OBJSDL)
	echo Création de Test2
	$(GPP) -o Test2 Test2.cpp $(OBJ) $(OBJSDL)
	
Test3 : Test3.cpp $(OBJ) $(OBJSDL)
	echo Création de Test3
	$(GPP) -o Test3 Test3.cpp $(OBJ) $(OBJSDL)
	
Test4 : Test4.cpp $(OBJ) $(OBJSDL)
	echo Création de Test4
	$(GPP) -o Test4 Test4.cpp $(OBJ) $(OBJSDL)
	
Test5 : Test5.cpp $(OBJ) $(OBJSDL)
	echo Création de Test5
	$(GPP) -o Test5 Test5.cpp $(OBJ) $(OBJSDL)
	
Test6 : Test6.cpp $(OBJ) $(OBJSDL)
	echo Création de Test6
	$(GPP) -o Test6 Test6.cpp $(OBJ) $(OBJSDL)
	
Test7 : Test7.cpp $(OBJ) $(OBJSDL)
	echo Création de Test7
	$(GPP) -o Test7 Test7.cpp $(OBJ) $(OBJSDL)
	
Test8 : Test8.cpp $(OBJ) $(OBJSDL)
	echo Création de Test8
	$(GPP) -o Test8 Test8.cpp $(OBJ) $(OBJSDL)
	
Test9 : Test9.cpp $(OBJ) $(OBJSDL)
	echo Création de Test9
	$(GPP) -o Test9 Test9.cpp $(OBJ) $(OBJSDL)
	
Test10 : Test10.cpp $(OBJ) $(OBJSDL)
	echo Création de Test10
	$(GPP) -o Test10 Test10.cpp $(OBJ) $(OBJSDL)
	
Test11 : Test11.cpp $(OBJ) $(OBJSDL)
	echo Création de Test11
	$(GPP) -o Test11 Test11.cpp $(OBJ) $(OBJSDL)
	
Test12 : Test12.cpp $(OBJ) $(OBJSDL)
	echo Création de Test12
	$(GPP) -o Test12 Test12.cpp $(OBJ) $(OBJSDL)
	
#-----------------------------------------------------#
	
Couleur.o : $(CLASSES)/Couleur.cpp $(CLASSES)/Couleur.h
	echo Création de Couleur.o
	$(GPP) -c $(CLASSES)/Couleur.cpp
	
Point.o : $(CLASSES)/Point.cpp $(CLASSES)/Point.h
	echo Création de Point.o
	$(GPP) -c $(CLASSES)/Point.cpp

#-----------------------------------------------------#

Figure.o : $(CLASSES)/Figure.cpp $(CLASSES)/Figure.h
	echo Création de Figure.o
	$(GPP) -c $(CLASSES)/Figure.cpp
	
Pixel.o : $(CLASSES)/Pixel.cpp $(CLASSES)/Pixel.h
	echo Création de Pixel.o
	$(GPP) -c $(CLASSES)/Pixel.cpp
	
Ligne.o : $(CLASSES)/Ligne.cpp $(CLASSES)/Ligne.h
	echo Création de Ligne.o
	$(GPP) -c $(CLASSES)/Ligne.cpp
	
Rectangle.o : $(CLASSES)/Rectangle.cpp $(CLASSES)/Rectangle.h
	echo Création de Rectangle.o
	$(GPP) -c $(CLASSES)/Rectangle.cpp
	
#-----------------------------------------------------#

BaseException.o : $(EXCEPT)/BaseException.cpp $(EXCEPT)/BaseException.h
	echo Création de BaseException.o
	$(GPP) -c $(EXCEPT)/BaseException.cpp
	
InvalidColorException.o : $(EXCEPT)/InvalidColorException.cpp $(EXCEPT)/InvalidColorException.h
	echo Création de InvalidColorException.o
	$(GPP) -c $(EXCEPT)/InvalidColorException.cpp
	
DessinException.o : $(EXCEPT)/DessinException.cpp $(EXCEPT)/DessinException.h
	echo Création de DessinException.o
	$(GPP) -c $(EXCEPT)/DessinException.cpp
		
#-----------------------------------------------------#
	
ListeBase.o : $(TEMPLATES)/ListeBase.cpp $(TEMPLATES)/ListeBase.h
	echo Création de ListeBase.o
	$(GPP) -c $(TEMPLATES)/ListeBase.cpp
	
Liste.o : $(TEMPLATES)/Liste.cpp $(TEMPLATES)/Liste.h
	echo Création de Liste.o
	$(GPP) -c $(TEMPLATES)/Liste.cpp
	
Pile.o : $(TEMPLATES)/Pile.cpp $(TEMPLATES)/Pile.h
	echo Création de Pile.o
	$(GPP) -c $(TEMPLATES)/Pile.cpp
	
Iterateur.o : $(TEMPLATES)/Iterateur.cpp $(TEMPLATES)/Iterateur.h
	echo Création de Iterateur.o
	$(GPP) -c $(TEMPLATES)/Iterateur.cpp
		
#-----------------------------------------------------#
	
Dessin.o : $(CLASSES)/Dessin.cpp $(CLASSES)/Dessin.h
	echo Création de Dessin.o
	$(GPP) -c $(CLASSES)/Dessin.cpp
	
#-----------------------------------------------------#
	
Bouton.o : $(CLASSES)/Bouton.cpp $(CLASSES)/Bouton.h
	echo Création de Bouton.o
	$(GPP) -c $(CLASSES)/Bouton.cpp
	
BoutonCouleur.o : $(CLASSES)/BoutonCouleur.cpp $(CLASSES)/BoutonCouleur.h
	echo Création de BoutonCouleur.o
	$(GPP) -c $(CLASSES)/BoutonCouleur.cpp
	
ToolBar.o : $(CLASSES)/ToolBar.cpp $(CLASSES)/ToolBar.h
	echo Création de ToolBar.o
	$(GPP) -c $(CLASSES)/ToolBar.cpp
	
#-----------------------------------------------------#
	
Ecran.o : $(ECRAN)/Ecran.cpp $(ECRAN)/Ecran.h
	echo Création de Ecran.o
	$(GPP) -c $(ECRAN)/Ecran.cpp
	
#-----------------------------------------------------#
	
WindowSDL.o: $(WINDOWSDL)/WindowSDL.cpp $(WINDOWSDL)/WindowSDL.h
	echo Création de WindowSDL.o
	$(GPP) -c $(WINDOWSDL)/WindowSDL.cpp

WindowSDLexception.o: $(WINDOWSDL)/WindowSDLexception.cpp $(WINDOWSDL)/WindowSDLexception.h
	echo Création de WindowSDLexception.o
	$(GPP) -c $(WINDOWSDL)/WindowSDLexception.cpp

WindowSDLclick.o: $(WINDOWSDL)/WindowSDLclick.cpp $(WINDOWSDL)/WindowSDLclick.h
	echo Création de WindowSDLclick.o
	$(GPP) -c $(WINDOWSDL)/WindowSDLclick.cpp
		
WindowSDLimage.o: $(WINDOWSDL)/WindowSDLimage.cpp $(WINDOWSDL)/WindowSDLimage.h
	echo Création de WindowSDLimage.o
	$(GPP) -c $(WINDOWSDL)/WindowSDLimage.cpp
