//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
namespace stgcombat{
    //
    // Interface class, let a GameWorld know this can 
    // serve as a player
    //
    class IPlayer{
    public:
        virtual ~IPlayer(){}
        virtual void playerInput() = 0;
    };
}