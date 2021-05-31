#pragma once

#include "TexRect.h"

//child of textRect bcs we dont want to mess with that
class Sprite: public TexRect{

public:
    Sprite(const char* filename, float x, float y, float w, float h): TexRect(filename, x, y, w, h){
    }

    void draw(float z = 0) {
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glEnable(GL_TEXTURE_2D);

        glBegin(GL_QUADS);
        glColor4f(1, 1, 1, 1);
        glTexCoord2f(0, 0);
        glVertex3f(x, y - h, z);

        glTexCoord2f(0, 1);
        glVertex3f(x, y, z);

        glTexCoord2f(1, 1);
        glVertex3f(x+w, y, z);

        glTexCoord2f(1, 0);
        glVertex3f(x+w, y - h, z);

        glEnd();

        glDisable(GL_TEXTURE_2D);
    }


    void birdMoveUp();
    void birdFalling();

    void pipeMove();

    bool hitGroundDetection();

    bool hitBottomPipe(Sprite* tempBird1) const;
    bool hitTopPipe(Sprite* tempBird) const;

    ~Sprite(){

    }
};