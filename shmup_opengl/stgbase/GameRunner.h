//  Author: Windy Darian
//  Date Created: Jan 10, 2015
#pragma once

#include <GL/freeglut.h>
#include <GL/GL.h>
#include <glm/glm.hpp>
#include "DataManager.h"
#include "Renderer.h"
#include "ItemManager.h"

namespace stgbase{

    //
    //  The main game class.
    //
    class GameRunner
    {
        //  used to wrap a pointer to member function idleCallback and displayCallback()
        friend void gameGlutIdleCallback();
        friend void gameGlutDisplayCallback();
        
    public:
        GameRunner();
        ~GameRunner();
        void setWindowSize(int width, int height);
        void setMaxFps(float max_fps); 
        void setViewSize(float width, float height);
        glm::vec2 getViewSize() { return view_size_; }
        virtual void start();

    protected:
        virtual void update(float elapsedTime);
        virtual void draw(float elapsedTime);

    private:
        int window_width_ = 1280;
        int window_height_ = 720;
        // Don't limit frame rate if max_fps_ <= 0.
        float max_fps_ = 60.0f;
        //  in milliseconds
        float min_idle_time_ = 0;
        glm::vec2 view_size_;

        //  the previous time value (in millseconds) when last glutGet(GLUT_ELAPSED_TIME) 
        //   in idleCallback() and displayCallback was called
        int prev_update_time_ = 0;
        int prev_draw_time_ = 0;


        void idleCallback();
        void displayCallback();
    };

    void gameGlutIdleCallback();
    void gameGlutDisplayCallback();

}

