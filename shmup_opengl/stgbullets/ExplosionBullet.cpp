//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#include "ExplosionBullet.h"
#include "../stgbase/DataManager.h"
#include "../stgbase/Renderer.h"
#include "DirectBullet.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/random.hpp>
using namespace stgbullets;


ExplosionBullet::ExplosionBullet(glm::vec2& position,
    int faction, float direction, stgcombat::GameWorld* world) :
    stgcombat::Bullet(stgbase::DataManager::getTexture("res/bullet5.png"),
    position, 15.0f, faction, 0.5f,
    COLOR_WHITE,  1, direction, 64, 6)
{
    this->world_ = world;
    child_bullet_tex_ = stgbase::DataManager::getTexture("res/bullet4.png");
    current_rotation_ = glm::linearRand<float>(0, glm::pi<float>() * 2);
}

void ExplosionBullet::beginToDie()
{
    auto pi = glm::pi<float>();
    if (world_ != nullptr)
        if (CombatObject* player = dynamic_cast<CombatObject*>(world_->player.get()))
        {
        // aim at player
        auto dir = glm::normalize(player->position - position);

        if (glm::length2(dir) > 0)
            current_rotation_ = glm::orientedAngle(glm::vec2(1, 0), dir);
        else current_rotation_ = pi / 2;

        }
    for (int i = 0; i < 10; i++)
    {
        world_->addBullet(new stgbullets::DirectBullet(child_bullet_tex_, position,
            3, faction, 0.5f, COLOR_WHITE, 334, current_rotation_, 768, 3.5f));
        current_rotation_ += pi / 5;
    }
    stgcombat::Bullet::beginToDie();
}

