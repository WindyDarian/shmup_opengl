//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include "stgbase/GameRunner.h"
#include "stgbase/Scene.h"
#include "stgscenes/TitleScene.h"
#include "stgscenes/BattleScene.h"

//
//  The game.
//
class StgRunner:
    public GameRunner
{
public:
    StgRunner();
    //void start();
    void startBattle();

protected:
    void started();
    void update(float elapsedTime);
    void draw(float elapsedTime);

private:
    stgscenes::TitleScene* title_scene_;
    stgscenes::BattleScene* battle_scene_;
    ItemManager<stgbase::Scene> scene_manager;
};

