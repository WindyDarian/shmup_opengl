//  Author: Windy Darian
//  Date Created: Jan 13, 2015

#pragma once
#include <memory>
#include "../stgbase/ItemManager.h"
#include "Battler.h"
#include "Bullet.h"
#include "IPlayer.h"

namespace stgcombat{
    //
    //  Where the game logic happens
    //
    class GameWorld :
        public IUpdatable, public IDrawable
    {
    public:
        GameWorld();
        virtual ~GameWorld(){};
        void update(float elapsedTime);
        void draw(float elapsedTime);
        bool getIsVisible() { return true; }
        bool getIsActive() { return true; }
        void addBattler(stgcombat::Battler* battler);
        void addBullet(stgcombat::Bullet* bullet);


        //  Manages all battlers in the game world
        stgbase::ItemManager<stgcombat::Battler> battlers;
        //  Manages all battlers in the game world
        stgbase::ItemManager<stgcombat::Bullet> bullets;
        //  The current player of this game world
        std::shared_ptr<IPlayer> player;

    };
}
