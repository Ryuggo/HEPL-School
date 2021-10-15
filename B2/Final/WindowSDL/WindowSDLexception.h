#ifndef WINDOW_SDL_EXCEPTION_H
#define WINDOW_SDL_EXCEPTION_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class WindowSDLexception
{
  private :
    char* message;

  public:
    WindowSDLexception();
    WindowSDLexception(const char* m);
    WindowSDLexception(const WindowSDLexception &e);
    ~WindowSDLexception();

    void  setMessage(const char* m);
    char* getMessage() const;
};

#endif
