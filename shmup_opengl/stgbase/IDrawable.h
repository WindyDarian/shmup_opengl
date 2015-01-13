//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
namespace stgbase{
    //
    // Interface class, inherit it to let a ItemManager know 
    // a class will run draw() every frame
    //
    class IDrawable{
    public:
        virtual ~IDrawable(){}
        virtual void draw(float elapsedTime) = 0;
        virtual bool getIsVisible() = 0;
    };
}