//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#include "Battler.h"
using namespace stgcombat;

Battler::Battler(GLuint texture, glm::vec2& position, float bounding_radius,
    int faction, float scale, glm::vec4& color, float maxHP)
    :CombatObject(texture, position, bounding_radius, faction, scale, color)
{
    max_hp_ = maxHP;
    hp_ = maxHP;
}

//
//  If out of hitpoints, it dies
//
void Battler::update(float elapsedTime)
{
    CombatObject::update(elapsedTime);
    if (hp_ <= 0)
        this->beginToDie();
}

void Battler::setMaxHp(float max_hp)
{
    this->max_hp_ = max_hp;
    if (hp_ > max_hp) hp_ = max_hp;
}

void Battler::setHp(float hp)
{
    if (hp < 0)
        this->hp_ = 0;
    else if (hp <= max_hp_)
        this->hp_ = hp;
    else this->hp_ = max_hp_;
}

void Battler::takeDamage(float damage, std::shared_ptr<CombatObject> source)
{
    this->setHp(hp_ - damage);
}

//
//  move to a specific direction with a speed
//
void Battler::move(float direction, float speed)
{
    this->setDirection(direction);
    this->speed = speed;
}

void Battler::stop()
{
    this->speed = 0;
}