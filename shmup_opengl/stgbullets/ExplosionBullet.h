//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "../stgcombat/Bullet.h"
#include "../stgcombat/GameWorld.h"

#include <iostream>

namespace stgbullets{
    //
    //  A bullet that can explode
    //
    class ExplosionBullet:
        public stgcombat::Bullet
    {
    public:
        ExplosionBullet(glm::vec2& position,
            int faction,
            float direction, stgcombat::GameWorld* world);

        void beginToDie();

        //for test
        ~ExplosionBullet(){ std::cout << "bullet destroyed" << std::endl; }

    private:
        stgcombat::GameWorld* world_ = nullptr;
        float current_rotation_ = 0;
        GLuint child_bullet_tex_;
    };
}

