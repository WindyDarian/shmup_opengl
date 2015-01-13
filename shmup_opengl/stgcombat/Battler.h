//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
#include <memory>
#include "CombatObject.h"

namespace stgcombat{
    //
    // A battler, player or enemy or boss
    //
    class Battler :
        public CombatObject
    {
    public:
        Battler(GLuint texture, glm::vec2& position, float bounding_radius,
            int faction, float scale, glm::vec4& color, float maxHP);

        void update(float elapsedTime);

        float getMaxHp() { return max_hp_; }
        void setMaxHp(float max_hp);
        float getHp() { return hp_; }
        void setHp(float hp);

        void takeDamage(float damage, std::shared_ptr<CombatObject> source);

        void move(float direction, float speed);
        void stop();

    private:
        float max_hp_ = 1.0f;
        float hp_ = 1.0f;
    };
}

