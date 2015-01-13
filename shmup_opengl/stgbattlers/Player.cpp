//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#include "Player.h"
#include "../stgbase/input_state.h"
#include "../stgbase/DataManager.h"
#include "../stgbase/Renderer.h"
#include "../stgbullets/DirectBullet.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtx/vector_angle.hpp>
using namespace stgbattlers;

Player::Player(glm::vec2& position, int faction, stgcombat::GameWorld* world)
    :stgcombat::Battler(stgbase::DataManager::getTexture("res/player.png"),
    position,
    6.0f,
    faction,
    0.5f,
    COLOR_WHITE,
    1000)
{
    this->world_ = world;
    this->bullet_tex_ = stgbase::DataManager::getTexture("res/bullet1.png");
}

void Player::update(float elapsedTime) {
    if (this->cooldown_remain_>0)
        cooldown_remain_ -= elapsedTime;
    Battler::update(elapsedTime);

    
    if (this->position.x<0)
    {
        this->position.x = 0;
    }
    if (this->position.x>1280)
    {
        this->position.x = 1280;
    }
    if (this->position.y < 0)
    {
        this->position.y = 0;
    }
    if (this->position.y > 720)
    {
        this->position.y = 720;
    }

    this->setHp(this->getHp() + this->hp_regen * elapsedTime);
}

void Player::shoot(){
    if (cooldown_remain_ <= 0) {
        auto pi = glm::pi<float>();
        world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position,
            15, faction, 0.5f, COLOR_WHITE, 97, -pi/2, 1280, 1));
        cooldown_remain_ += shoot_cooldown_;
    }
}

void Player::playerInput(){
    if (!this->isRemoving()) {
        glm::vec2 moveDirection(0, 0);

        if (stgbase::specialInputState[GLUT_KEY_LEFT] || stgbase::keyState['a'])
        {
            moveDirection[0] -= 1;
        }
        if (stgbase::specialInputState[GLUT_KEY_RIGHT] || stgbase::keyState['d'])
        {
            moveDirection[0] += 1;
        }
        if (stgbase::specialInputState[GLUT_KEY_UP] || stgbase::keyState['w'])
        {
            moveDirection[1] -= 1;
        }
        if (stgbase::specialInputState[GLUT_KEY_DOWN] || stgbase::keyState['s'])
        {
            moveDirection[1] += 1;
        }

        if (moveDirection.x == 0 && moveDirection.y == 0)
            stop();
        else {
            moveDirection = glm::normalize(moveDirection);
            glm::vec2 xaxis(1, 0);
            move(glm::orientedAngle(xaxis, moveDirection), max_speed_);
        }

        if (stgbase::keyState['\r'] || stgbase::keyState[' '] || stgbase::keyState['z'])
            shoot();
            
    }
}
