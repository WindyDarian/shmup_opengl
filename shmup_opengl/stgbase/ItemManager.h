//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
#include <list>
#include <memory>
#include "IUpdatable.h"
#include "IDrawable.h"
#include "IRemovable.h"

namespace stgbase{
    //
    //  The ItemManager class store a list of objects
    //  It will run update() and draw() of the member objects if called
    //
    template <class T>
    class ItemManager :
        public IUpdatable, public IDrawable
    {
    public:
        ItemManager();
        virtual void update(float elapsedTime);
        virtual void draw(float elapsedTime);
        virtual bool getIsVisible() { return true; }
        virtual bool getIsActive() { return true; }
        void add(T* item);
        int count();
        std::list<std::shared_ptr<T>>& getMemberList();
        std::shared_ptr<T> getLastAddedMember();

    private:
        std::list<std::shared_ptr<T>> member_list_;
        std::list<std::shared_ptr<T>> removing_list_;
        std::list<std::shared_ptr<T>> adding_list_;
        std::shared_ptr<T> last_added_member_;
        bool isItemRemoving(T* item);
    };
}


using namespace stgbase;

template<class T>
ItemManager<T>::ItemManager()
{
}


//
//  Call update() for every IUpdatable member of the ItemMananger
//
template<class T>
void ItemManager<T>::update(float elapsedTime)
{
    //  append adding list to member list 
    for (auto itemptr : this->adding_list_)
    {
        this->member_list_.push_back(itemptr);
    }
    this->adding_list_.clear();

    for (auto itemptr : this->member_list_)
    {

        if (isItemRemoving(itemptr.get()))
        {
            removing_list_.push_back(itemptr);
            continue;
        }


        if (IUpdatable* t = dynamic_cast<IUpdatable*>(itemptr.get()))
        {
            if (t->getIsActive())
                t->update(elapsedTime);
        }
    }

    // remove objects from member list
    for (auto itemptr : this->removing_list_)
    {
        this->member_list_.remove(itemptr);
    }
    this->removing_list_.clear();
}

//
//  Call draw() for every IDrawable member of the ItemMananger
//
template<class T>
void ItemManager<T>::draw(float elapsedTime)
{
    for (auto itemptr : this->member_list_)
    {
        if (IDrawable* t = dynamic_cast<IDrawable*>(itemptr.get())) //&& ((IUpdatable)o).getIsActived())
        {
            if (t->getIsVisible())
                t->draw(elapsedTime);
        }
    }
}


//
//  Add an item for this ItemManager
//
template<class T>
void ItemManager<T>::add(T* item)
{

    auto ptr = std::shared_ptr<T>(item);
    this->adding_list_.push_back(ptr);
    this->last_added_member_ = ptr;
}

//
//  Count the amount of members owned by this ItemManager
//
template<class T>
int ItemManager<T>::count()
{
    return this->member_list_.size() + this->adding_list_.size() + this->removing_list_.size();
}

//
//  Returns a reference of its member list
//
template<class T>
std::list<std::shared_ptr<T>>& ItemManager<T>::getMemberList()
{
    return this->member_list_;
}

template<class T>
std::shared_ptr<T> ItemManager<T>::getLastAddedMember()
{
    return this->last_added_member_;
}



template<class T>
bool ItemManager<T>::isItemRemoving(T* item)
{
    if (IRemovable* t = dynamic_cast<IRemovable*>(item)) {
        return t->isRemoving();
    }
    else return false;
}
