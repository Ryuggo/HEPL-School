.SILENT:

CC = g++ -m64
OBJS = WindowSDL.o WindowSDLexception.o WindowSDLimage.o WindowSDLclick.o
PROGRAMS = TestWindowSDL

ALL: $(PROGRAMS)

TestWindowSDL:	TestWindowSDL.cpp $(OBJS)
	echo Creation de TestWindowSDL...
	$(CC) TestWindowSDL.cpp -o TestWindowSDL $(OBJS) -lpthread -lSDL

WindowSDL.o:	WindowSDL.cpp WindowSDL.h
		echo Creation de WindowSDL.o ...
		$(CC) -c WindowSDL.cpp

WindowSDLexception.o:	WindowSDLexception.cpp WindowSDLexception.h
		echo Creation de WindowSDLexception.o ...
		$(CC) -c WindowSDLexception.cpp

WindowSDLclick.o:	WindowSDLclick.cpp WindowSDLclick.h
		echo Creation de WindowSDLclick.o ...
		$(CC) -c WindowSDLclick.cpp

WindowSDLimage.o:	WindowSDLimage.cpp WindowSDLimage.h
		echo Creation de WindowSDLimage.o ...
		$(CC) -c WindowSDLimage.cpp

clean:
	@rm -f $(OBJS) core

clobber:	clean
	@rm -f tags $(PROGRAMS)
