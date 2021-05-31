#include <iostream>
#include "Sprite.h"

void Sprite::birdMoveUp(){
    y = y+0.2;
}
void Sprite::birdFalling(){
    y = y-0.001;
}
void Sprite::pipeMove(){
    x = x-0.002;
}

bool Sprite::hitGroundDetection(){
    //std::cout<<"checking if hit ground..."<<std::endl;
    if(y <= -0.45){
        return false;
      //  exit(0);
    }
    return true;
}

//topPipes.push_back(new Sprite("topPipe.png",randomXpositionGen(), 1.6, 1.5, 2));
bool Sprite::hitTopPipe(Sprite* tempBird)const{
/*
    std::cout<<"x:"<<this->x<<std::endl;
    std::cout<<"y:"<<this->y<<std::endl;
    std::cout<<"temp->x:"<<tempBird->x<<std::endl;
    std::cout<<"temp>y:"<<tempBird->y<<std::endl;*/
    if((tempBird->x >= (this->x)+0.25) && (tempBird->x <= (this->x)+1) && (tempBird->y >= (this->y)-1.12)) {
        return true;
      //  std::cout<<"OH NO"<<std::endl;
    }

    //std::cout<<"no pipe hit"<<std::endl;
    return false;
}


//this->x, this->y = PIPE LOCATIONS
//tempBird->x, tempBird->y = bird
bool Sprite::hitBottomPipe(Sprite* tempBird1) const{

 /*   std::cout<<"x:"<<this->x<<std::endl;
    std::cout<<"y:"<<this->y<<std::endl;
    std::cout<<"temp->x:"<<tempBird1->x<<std::endl;
    std::cout<<"temp>y:"<<tempBird1->y<<std::endl;*/
    if((tempBird1->x >= (this->x)+0.25) && (tempBird1->x <= (this->x)+1) && (tempBird1->y <= (this->y)-0.55)) {
        return true;
      //  std::cout<<"OH NO"<<std::endl;
    }
    return false;    
}

