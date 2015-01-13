//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#include "Bullet.h"
using namespace stgcombat;


Bullet::Bullet(GLuint texture, glm::vec2& position, float bounding_radius,
    int faction, float scale, glm::vec4& color, float damage, float direction, float speed, float life_time)
    : CombatObject(texture, position, bounding_radius, faction, scale, color, direction, direction, speed)
{
    this->damage = damage;
    this->life_time = life_time;
}

void Bullet::update(float elapsedTime)
{
    this->existed_time += elapsedTime;
    CombatObject::update(elapsedTime);
    if (existed_time > life_time)
        this->beginToDie();
}
