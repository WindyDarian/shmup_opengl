//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include "../stgcombat/Bullet.h"

namespace stgbullets{
    //
    //  The most common bullet with a constant speed
    //
    class DirectBullet:
        public stgcombat::Bullet
    {
    public:
        DirectBullet(GLuint texture, glm::vec2& position, float boundingRadius,
            int faction, float scale, glm::vec4& color, float damage,
            float direction, float speed, float lifeTime);

    };
}

