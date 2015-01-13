//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#include "CombatObject.h"
#include "../stgbase/Renderer.h"
#include <glm/gtx/rotate_vector.hpp>
using namespace stgcombat;

//
//  Check if two CombatObject is collided
//
bool CombatObject::isCollided(CombatObject& a, CombatObject& b)
{
    auto r_sum = a.bounding_radius + b.bounding_radius;
    return distance(a.position, b.position) <= r_sum;
}

//
//  Create a game object
//
CombatObject::CombatObject(GLuint texture, glm::vec2& position,
    float bounding_radius, int faction, float scale, glm::vec4& color)
    : texture(texture), position(position), positionl(position), bounding_radius(bounding_radius),
    faction(faction), scale(scale), color(color){}

//
//  Create a game object
//
CombatObject::CombatObject(GLuint texture, glm::vec2& position,
    float bounding_radius, int faction, float scale,
    glm::vec4& color, float direction, float rotation, float speed):
    CombatObject(texture, position, bounding_radius, faction, scale, color)
{
    this->rotation = rotation;
    this->speed = speed;
    this->setDirection(direction);
}

//
//  Update the object, change position according to speed
//
void CombatObject::update(float elapsedTime)
{
    positionl = position;
    if (speed != 0.0f)
    {
        glm::vec2 offset = this->direction_vec_;
        offset *= speed*elapsedTime;
        this->position = this->position + offset;
    }
}

//
//  Draw the object
//
void CombatObject::draw(float elapsedTime)
{
    if (texture != 0)
    {
        if (rotation == 0.0f)
        {
            stgbase::Renderer::drawTexCentered(texture, position, texSize, scale,
                color);
        }
        else
        {
            stgbase::Renderer::drawTexCentered(texture, position, texSize, scale,
                color, rotation);
        }
    }
}

//
//  Flag the object to be removed
//
void CombatObject::remove()
{
    is_being_removed_ = true;
}

//
//  Begin to die
//  But there is no death animation at the moment (or won't be any)
//  so it is the same as remove()
//
void CombatObject::beginToDie()
{
    is_dying = true;
    is_being_removed_ = true;
}

//
//  Set the movement direction for the object
//  as well as updating direction_vec_ 
//
void CombatObject::setDirection(float direction)
{
    this->direction_ = direction;

    glm::vec2 origin(1.0f, 0.0f);
    this->direction_vec_ = glm::rotate(origin, direction);
}