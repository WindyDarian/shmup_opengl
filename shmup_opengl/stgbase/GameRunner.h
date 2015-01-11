//  Author: Windy Darian
//  Date Created: Jan 10, 2015
#pragma once

#include <GL/freeglut.h>
#include <GL/GL.h>
#include "DataManager.h"
#include "Renderer.h"

namespace stgbase{

    //
    //  The main game class.
    //
    class GameRunner
    {
        //used to wrap a pointer to member function renderCallback()
        friend void gameRunnerRenderCallback();   
        
    public:
        GameRunner(int argc, char** argv);
        ~GameRunner();
    protected:
        void update(float elapsedTime);
        void draw(float elapsedTime);

    private:
        int windowWidth_ = 1280;
        int windowHeight_ = 720;

        void renderCallback();
    };

    void gameRunnerRenderCallback();
}

