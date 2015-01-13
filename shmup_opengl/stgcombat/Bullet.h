//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
#include "CombatObject.h"

namespace stgcombat{
    class Bullet :
        public CombatObject
    {
    public:
        Bullet(GLuint texture, glm::vec2& position, float boundingRadius,
            int faction, float scale, glm::vec4& color, float damage, float direction, float speed, float lifeTime);
        virtual ~Bullet() {}

        void update(float elapsedTime);

        float damage = 1;
        float life_time = 3;
        float existed_time = 0;
    };
}

