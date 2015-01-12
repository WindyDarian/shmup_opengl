//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include <GL/glut.h>
#include "GameRunner.h"
#include "IUpdatable.h"
#include "IDrawable.h"
#include "IRemovable.h"

namespace stgbase{
    //
    //  That's... a scene, abstract
    //  could be a game stage or a menu
    //  here I only use it as a stage though
    //
    class Scene
    {
    public:
        Scene(GameRunner* runner);
        virtual ~Scene(){};

        virtual void update(float elapsedTime) = 0;
        virtual void draw(float elapsedTime);
        virtual bool getIsVisible();
        virtual bool getIsActive();
        virtual void open(float elapsedTime);
        virtual void close(float elapsedTime);
        GLuint background_tex = 0;
        GameRunner* const runner;

    protected:
        bool is_visible = false;
        bool is_active = false;
    };
}
