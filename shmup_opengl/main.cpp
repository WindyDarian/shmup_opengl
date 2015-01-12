// Author: Windy Darian
// Date Created: Jan 10, 2015

#include "stgbase/GameRunner.h"
#include<iostream>



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    //  Initialize the Game
    stgbase::GameRunner game;
    game.setWindowSize(1280, 720);
    //game.setMaxFps(30);
    game.start();

    return 0;
}

