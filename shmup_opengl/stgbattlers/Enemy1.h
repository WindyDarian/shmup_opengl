//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include "../stgcombat/Battler.h"
#include "../stgcombat/GameWorld.h"

namespace stgbattlers
{
    //
    //  A specific type of enemy
    //
    class Enemy1:
        public stgcombat::Battler
    {
    public:
        Enemy1(glm::vec2& position, int faction, stgcombat::GameWorld* world, float direction);
        void update(float elapsedTime);
        void shoot();

    private:
        float max_speed_ = 128.0f;
        stgcombat::GameWorld* world_;
        float shoot_cooldown_ = 0.75f;
        float cooldown_remain_ = 1.0f;
        float current_rotation_ = (float)glm::radians(90.0f);
        GLuint bullet_tex_;
    };
}

