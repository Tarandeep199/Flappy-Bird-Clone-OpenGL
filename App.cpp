#include <iostream>
#include <stdlib.h>  
#include "App.h"



float randomXpositionGen(){
    return rand()%5+1;
}
float randomXpositionGen1(){
    return rand()%4+2;
}



App::App(int argc, char** argv, int width, int height, const char* title): GlutApp(argc, argv, width, height, title){
    bg = new Rect(-1,1,2,2,0.53,0.81,0.92);
    bg2 = new Sprite("background.png", -1,1,2,2);
    
    for(int i = 0; i <= 2; i++){
        topPipes.push_back(new Sprite("topPipe.png",randomXpositionGen(), 1.6, 1.5, 2));
    }
    for(int i = 0; i <= 2; i++){
        bottomPipes.push_back(new Sprite("pipe.png",randomXpositionGen(), 0.7, 1.5, 1.8));
    }

    bird = new Sprite("player.png",-0.8, 0.4, .3, .3);
    ground = new Sprite("ground.png",-1.3,-0.67, 10, .5);
    gameOverText = new Sprite("gameover.png", -1,1,2,2);
    playerAlive = true;

}   

void App::draw() const {
    bg2->draw();
    if (playerAlive) bird->draw();

    if(playerAlive){
    for(auto i = topPipes.begin(); i != topPipes.end(); i++){
            (*i)->draw();
        }
            
    for(auto i = bottomPipes.begin(); i != bottomPipes.end(); i++){
            (*i)->draw();
        }
    ground->draw();

    }
    if (playerAlive==false) gameOverText->draw();

}



void App::keyDown(unsigned char key, float x, float y){

    if (key == 27){
        exit(0);
    }
    else if (key == ' '){
        bird->birdMoveUp();
    }
    redraw();
}





void App::idle(){
    bird->birdFalling();
    playerAlive = bird->hitGroundDetection();
    
    if(playerAlive){
        for(auto i = bottomPipes.begin(); i != bottomPipes.end(); i++){
            (*i)->pipeMove();
            if((*i)->hitBottomPipe(bird)){
                playerAlive=false;
                redraw();
                std::cout<<"HIT BOTTOM"<<std::endl;
            }
        } 
        for(auto i = topPipes.begin(); i != topPipes.end(); i++){
            (*i)->pipeMove();
            if((*i)->hitTopPipe(bird)){
                playerAlive=false;
                redraw();
                std::cout<<"HIT TOP"<<std::endl;
            }
        }
    }

    ground->pipeMove();
    redraw();
}




App::~App(){ 
    for(auto i = topPipes.begin(); i != topPipes.end(); i++){
        delete *i;
    }
    for(auto i = bottomPipes.begin(); i != bottomPipes.end(); i++){
       delete *i;
    }
    delete bird;
    delete ground;
    delete bg2;
    delete bg;

    std::cout << "Exiting..." << std::endl;
}
