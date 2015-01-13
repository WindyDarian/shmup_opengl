// Author: Windy Darian
// Date Created: Jan 10, 2015

#include "StgRunner.h"
#include<iostream>



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    //  Initialize the Game
    StgRunner game;
    game.setWindowSize(1280, 720);
    game.start();

    return 0;
}

