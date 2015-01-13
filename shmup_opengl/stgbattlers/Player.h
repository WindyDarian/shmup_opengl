//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include "../stgcombat/Battler.h"
#include "../stgcombat/IPlayer.h"
#include "../stgcombat/GameWorld.h"

namespace stgbattlers
{
    //
    //  A specific type of enemy
    //
    class Player:
        public stgcombat::Battler, public stgcombat::IPlayer
    {
    public:
        Player(glm::vec2& position, int faction, stgcombat::GameWorld* world);
        void update(float elapsedTime);
        void shoot();
        void playerInput();

    private:
        float max_speed_ = 1024.0f;
        stgcombat::GameWorld* world_;
        float shoot_cooldown_ = 0.125f;
        float cooldown_remain_ = 0.0f;
        float hp_regen = 25.0f;
        GLuint bullet_tex_;
    };
}

