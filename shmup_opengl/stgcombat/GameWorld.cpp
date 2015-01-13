
//  Author: Windy Darian
//  Date Created: Jan 13, 2015

#include "GameWorld.h"
using namespace stgcombat;

GameWorld::GameWorld()
{}

//
//  check collision between game objects and update them
//
void GameWorld::update(float elapsedTime)
{
    if (player != nullptr)
        player->playerInput();
    
    
    //  check between every battlers and bullets for collision.
    //  TODO: This should be optimized using methods such as a quad-tree
    //    (But not necessery for this small game prototype)

    
    for (auto battler : battlers.getMemberList())
    {
        for (auto bullet : bullets.getMemberList())
        {
            if ((!bullet->is_dying) &&
                battler->faction != bullet->faction &&
                stgcombat::CombatObject::isCollided(*battler, *bullet))
            {
                battler->takeDamage(bullet->damage, bullet);
                bullet->beginToDie();
            }
        }
    }
    

    bullets.update(elapsedTime);
    battlers.update(elapsedTime);
}

//
//  draw bullets and battles of the game world
//
void GameWorld::draw(float elapsedTime){
    bullets.draw(elapsedTime);
    battlers.draw(elapsedTime);
}

void GameWorld::addBattler(stgcombat::Battler* battler)
{
    battlers.add(battler);
}

void GameWorld::addBullet(stgcombat::Bullet* bullet)
{
    bullets.add(bullet);
}