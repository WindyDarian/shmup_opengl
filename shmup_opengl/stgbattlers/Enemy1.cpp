#include "Enemy1.h"
#include "../stgbase/DataManager.h"
#include "../stgbase/Renderer.h"
#include "../stgbullets/DirectBullet.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtx/vector_angle.hpp>
using namespace stgbattlers;

Enemy1::Enemy1(glm::vec2& position, int faction, stgcombat::GameWorld* world, float direction)
    :stgcombat::Battler(stgbase::DataManager::getTexture("res/enemy1.png"),
    position,
    128.0f,
    faction,
    0.5f,
    COLOR_WHITE,
    500)
{
    this->world_ = world;
    this->move(direction, max_speed_);
    this->bullet_tex_ = stgbase::DataManager::getTexture("res/bullet3.png");
}

void Enemy1::update(float elapsedTime) {
    if (this->cooldown_remain_>0)
        cooldown_remain_ -= elapsedTime;
    Battler::update(elapsedTime);
    shoot();

    //  Destroy if gone too far
    if (position[0]> 1380 || position[0]<-100 || position[1]> 820 || position[1]<-100)
    {
        this->beginToDie();
    }
}

void Enemy1::shoot(){
    if (cooldown_remain_ <= 0) {
        auto pi = glm::pi<float>();

        if (CombatObject* player = dynamic_cast<CombatObject*>(world_->player.get()))
        {
            // aim at player
            auto dir = glm::normalize(player->position - position);

            if (dir.y > 0)
                current_rotation_ = glm::orientedAngle(glm::vec2(1, 0), dir);
            else current_rotation_ = pi / 2;

        }
        else
            current_rotation_ = pi / 2;
        current_rotation_ += pi / 7;
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            3, faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 256, 10));
        current_rotation_ += pi / 7;
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            3, faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 256, 10));
        current_rotation_ -= pi / 7 * 2;
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            3, faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 256, 10));
        current_rotation_ -= pi / 7;
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            3, faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 256, 10));
        current_rotation_ -= pi / 7;
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            3, faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 256, 10));

        cooldown_remain_ += shoot_cooldown_;
    }
}

