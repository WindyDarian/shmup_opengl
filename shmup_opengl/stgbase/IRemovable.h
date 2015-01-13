//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
namespace stgbase{
    //
    // Interface class, inherit it to let a ItemManager know 
    // a object of this class can be removed from the ItemManager
    // with its removing flag
    //
    class IRemovable{
    public:
        virtual ~IRemovable(){}
        virtual bool isRemoving() = 0;
    };
}