//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#include "DirectBullet.h"
using namespace stgbullets;


DirectBullet::DirectBullet(GLuint texture, glm::vec2& position, float boundingRadius,
    int faction, float scale, glm::vec4& color, float damage,
    float direction, float speed, float lifeTime) : stgcombat::Bullet(texture,
    position, boundingRadius, faction, scale,
    color,  damage, direction, speed, lifeTime)
{}

