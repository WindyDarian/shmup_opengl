//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
namespace stgbase{
    //
    // Interface class, inherit it to let a ItemManager know 
    // a class will run update() every frame
    //
    class IUpdatable{
    public:
        virtual ~IUpdatable(){}
        virtual void update(float elapsedTime) = 0;
        virtual bool getIsActive() = 0;
    };
}