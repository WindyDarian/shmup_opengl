//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#include "StgRunner.h"


StgRunner::StgRunner()
    :GameRunner()
{}

//
//  create the game along with its title and level 
//
void StgRunner::started()
{
    title_scene_ = new stgscenes::TitleScene(this);
    battle_scene_ = new stgscenes::BattleScene(this);
    scene_manager.add(title_scene_);
    scene_manager.add(battle_scene_);
    title_scene_->open();
}

//
//  Activate the game level
//
void StgRunner::startBattle()
{
    title_scene_->close();
    battle_scene_->open();
}

//
//  Update game logic, called every frame
//  elapsedTime is the time since last update() was called, in seconds
//
void StgRunner::update(float elapsedTime)
{
    //  If player choose to restart game after death.
    if (battle_scene_->isRemoving())
    {
        battle_scene_ = new stgscenes::BattleScene(this);
        scene_manager.add(battle_scene_);
        battle_scene_->open();
    }

    scene_manager.update(elapsedTime);
    GameRunner::update(elapsedTime);
}

//
//  Draw the game scene, called every frame
//  elapsedTime is the time since last draw() was called, in seconds
//
void StgRunner::draw(float elapsedTime)
{
    scene_manager.draw(elapsedTime);
    GameRunner::draw(elapsedTime);
}








