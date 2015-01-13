//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#include "Enemy2.h"
#include "../stgbase/DataManager.h"
#include "../stgbase/Renderer.h"
#include "../stgbullets/DirectBullet.h"
#include <glm/gtc/constants.hpp>
using namespace stgbattlers;

Enemy2::Enemy2(glm::vec2& position, int faction, stgcombat::GameWorld* world, float direction)
    :stgcombat::Battler(stgbase::DataManager::getTexture("res/enemy2.png"),
    position,
    64.0f,
    faction,
    0.5f,
    COLOR_WHITE,
    300)
{
    this->world_ = world;
    this->move(direction, max_speed_);
    this->bullet_tex_ = stgbase::DataManager::getTexture("res/bullet4.png");
}

void Enemy2::update(float elapsedTime) {
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

void Enemy2::shoot(){
    if (cooldown_remain_ <= 0) {
        auto pi = glm::pi<float>();
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            2.5, faction, 0.4f, COLOR_WHITE, 334, current_rotation_, 300, 10));
        current_rotation_ += pi / 7;
        cooldown_remain_ += shoot_cooldown_;
    }
}

