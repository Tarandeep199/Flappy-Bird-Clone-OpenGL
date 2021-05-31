#ifndef App_h
#define App_h

#include <vector>
#include "GlutApp.h"
#include "Rect.h"
#include "Circle.h"
#include "TexRect.h"
#include "Sprite.h"


class App: public GlutApp {

    Rect* bg;
    Sprite* gameOverText;
    Sprite* bg2;
    Sprite* bird;
    Sprite* ground;
    std::vector<Sprite*> topPipes;
    std::vector<Sprite*> bottomPipes;
    
    bool playerAlive ;



public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw() const;
    
    void keyDown(unsigned char key, float x, float y);

    void idle();
    

    ~App();
};

#endif
