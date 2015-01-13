//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include "../stgcombat/Battler.h"
#include "../stgcombat/GameWorld.h"

namespace stgbattlers
{
    //
    //  The boss
    //
    class Boss:
        public stgcombat::Battler
    {
    public:
        Boss(glm::vec2& position, int faction, stgcombat::GameWorld* world);
        void update(float elapsedTime);

    private:
        void action();

        float max_speed_ = 128.0f;
        stgcombat::GameWorld* world_;
        float shoot_cooldown_ = 0.17f;
        float cooldown_remain_ = 7.0f;
        float current_rotation_ = -(float)glm::radians(90.0f);
        GLuint bullet_tex_;
        GLuint bullet2_tex_;
        int stance_ = 0;
        float stance_change_time_ = 5.0f;
        float current_stance_time_ = -4.0f;
        float current_direction_ = 0.0f;
    };
}

