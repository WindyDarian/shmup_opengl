//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include <memory>
#include <string>
#include <GL/glut.h>
#include "../stgbase/Scene.h"


namespace stgscenes{
    //
    //  The title "menu" of the game
    //
    class TitleScene:
        public stgbase::Scene
    {
    public:
        TitleScene(GameRunner* runner);

        void update(float elapsedTime);
        void draw(float elapsedTime);
        void newEnemy();
        bool isRemoving();

    private:
        std::string message_;

    };
}
