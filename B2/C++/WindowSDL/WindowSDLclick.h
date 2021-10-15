#ifndef WINDOW_SDL_CLICK_H
#define WINDOW_SDL_CLICK_H

class WindowSDLclick
{
  private :
    int X;
    int Y;
    
  public:
    WindowSDLclick(void);
    WindowSDLclick(int x,int y);
    WindowSDLclick(const WindowSDLclick &c);
    ~WindowSDLclick();

    void setX(int x);
    void setY(int y);

    int  getX() const;
    int  getY() const;
};

#endif
