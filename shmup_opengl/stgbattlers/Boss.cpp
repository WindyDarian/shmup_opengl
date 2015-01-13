#include "Boss.h"
#include "../stgbase/DataManager.h"
#include "../stgbase/Renderer.h"
#include "../stgbullets/DirectBullet.h"
#include "../stgbullets/ExplosionBullet.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtx/vector_angle.hpp>
using namespace stgbattlers;

Boss::Boss(glm::vec2& position, int faction, stgcombat::GameWorld* world)
    :stgcombat::Battler(stgbase::DataManager::getTexture("res/boss.png"),
    position,
    80.0f,
    faction,
    1.0f,
    COLOR_WHITE,
    15000)
{
    this->world_ = world;
    this->move(glm::pi<float>()/2, 50.0f);

    bullet_tex_ = DataManager::getTexture("res/bullet2.png");
    bullet2_tex_ = DataManager::getTexture("res/bullet3.png");
}

void Boss::update(float elapsedTime) {
    if (this->cooldown_remain_>0)
        cooldown_remain_ -= elapsedTime;
    Battler::update(elapsedTime);

    // boss battle logic
    action();
    current_stance_time_ += elapsedTime;
    if (current_stance_time_>stance_change_time_)
    {
        current_stance_time_ -= stance_change_time_;
        stance_++;
        stance_ %= 4;
    }

    if (stance_ == 3)
    {
        if (this->position[0]>1000)
            this->current_direction_ = glm::pi<float>();
        else if (this->position[0]<280)
            this->current_direction_ = 0;
    }
}

void Boss::action(){
    if (cooldown_remain_ <= 0) {
        auto pi = glm::pi<float>();
        switch (stance_) {
        case 0:
            this->stop();

            break;
        case 1:
            shoot_cooldown_ = 0.125f;
            world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position + glm::vec2(0,64),
                15, faction, 0.5f, COLOR_WHITE, 128, pi / 2, 1280, 1));
            world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position + glm::vec2(64, 64),
                15, faction, 0.5f, COLOR_WHITE, 128, pi / 2, 1280, 1));
            world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position + glm::vec2(-64, 64),
                15, faction, 0.5f, COLOR_WHITE, 128, pi / 2, 1280, 1));
            world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position + glm::vec2(32, 64),
                15, faction, 0.5f, COLOR_WHITE, 128, pi / 2, 1280, 1));
            world_->addBullet(new stgbullets::DirectBullet(bullet_tex_, position + glm::vec2(-32, 64),
                15, faction, 0.5f, COLOR_WHITE, 128, pi / 2, 1280, 1));
            this->move(-pi / 2, 25.0f);

            break;
        case 2:

            shoot_cooldown_ = 0.2f;

            if (CombatObject* player = dynamic_cast<CombatObject*>(world_->player.get()))
            {
                // aim at player
                auto dir = glm::normalize(player->position - position);
                float rot;
                if (glm::length2(dir) > 0)
                     rot = glm::orientedAngle(glm::vec2(1, 0), dir);
                else rot = pi / 2;

                world_->addBullet(new stgbullets::DirectBullet(bullet2_tex_, position, 3,
                    faction, 0.1f, COLOR_WHITE, 334, rot, 384, 7));
            }

            current_rotation_ -= pi / 7;
            world_->addBullet(new stgbullets::DirectBullet(bullet2_tex_, position, 3,
                faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 384, 7));

            current_rotation_ -= pi / 7;
            world_->addBullet(new stgbullets::DirectBullet(bullet2_tex_, position, 3,
                faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 384, 7));

            current_rotation_ += pi / 7 * 2;
            world_->addBullet(new stgbullets::DirectBullet(bullet2_tex_, position, 3,
                faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 384, 7));

            current_rotation_ += pi / 7;
            world_->addBullet(new stgbullets::DirectBullet(bullet2_tex_, position, 3,
                faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 384, 7));
            
            current_rotation_ += pi / 7;
            world_->addBullet(new stgbullets::DirectBullet(bullet2_tex_, position, 3,
                faction, 0.1f, COLOR_WHITE, 334, current_rotation_, 384, 7));

            this->move(pi / 2, 25.0f);

            break;
        case 3:
            shoot_cooldown_ = 1.0f;
            this->move(this->current_direction_, 256.0f);
            world_->addBullet(new stgbullets::ExplosionBullet(this->position + glm::vec2(0, -32),
                faction, pi / 2, this->world_));
            break;
        }
        cooldown_remain_ += shoot_cooldown_;
    }
}

