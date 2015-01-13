//  Author: Windy Darian
//  Date Created: Jan 13, 2015

#include "BattleScene.h"
#include <glm/gtc/constants.hpp>
#include "../stgbase/Renderer.h"
#include "../stgbattlers/Player.h"
#include "../stgbattlers/Enemy1.h"
#include "../stgbattlers/Enemy2.h"
#include "../stgbattlers/Boss.h"
#include "../stgbase/DataManager.h"
#include "../stgbase/input_state.h"
#include <glm/gtc/random.hpp>

using namespace stgscenes;

BattleScene::BattleScene(GameRunner* runner) 
    :stgbase::Scene(runner)
{
    Scene::background_tex = DataManager::getTexture("res/background.png");
    //  Initialize the game
    world_ = std::make_unique<stgcombat::GameWorld>();
    this->player_icon_ = DataManager::getTexture("res/head.png");
    
    world_->addBattler(new stgbattlers::Player(glm::vec2(640, 600), 1, world_.get()));
    this->player_ = world_->battlers.getLastAddedMember();
    world_->player = std::dynamic_pointer_cast<stgcombat::IPlayer>(world_->battlers.getLastAddedMember());
    world_->addBattler(new stgbattlers::Enemy1(glm::vec2(1330, 0), 2, world_.get(), glm::pi<float>() * 4 / 5));

}

//
//  update level logic
//
void BattleScene::update(float elapsedTime)
{
    stgbase::Scene::update(elapsedTime);
    total_time_ += elapsedTime;
    world_->update(elapsedTime);


    if (total_time_<20)
    {
        //刷怪
        if (total_time_ <= 5)
        {

        }
        else if (total_time_ <= 10)
        {
            respawn_time_ = 2.0f;
        }
        else if (total_time_ <= 15)
        {
            respawn_time_ = 1.5f;
        }
        else if (total_time_ <= 20)
        {
            respawn_time_ = 0.9f;
        }
        current_respawn_ += elapsedTime;
        if (current_respawn_>respawn_time_)
        {
            current_respawn_ -= respawn_time_;
            newEnemy();
        }
    }
    else if (boss_ == nullptr)
    {
        world_->addBattler(new stgbattlers::Boss(glm::vec2(640, -110), 2, world_.get()));
        boss_ = world_->battlers.getLastAddedMember();
    }
}


//
//  Draw UI
//
void BattleScene::draw(float elapsedTime)
{
    stgbase::Scene::draw(elapsedTime);


    world_->draw(elapsedTime);

    if (player_ != nullptr)
    {
        //  player hp bar
        stgbase::Renderer::drawTex(player_icon_, glm::vec2(0, 570), glm::vec2(165, 150));
        stgbase::Renderer::drawTex(0, glm::vec2(150, 686), glm::vec2(720 * (player_->getHp()/player_->getMaxHp()), 24),
            1,glm::vec4(78/255.0f,207/255.0f,40/255.0f,1.0f));
    }
    if (boss_ != nullptr)
    {
        //  boss hp bar
        stgbase::Renderer::drawTex(0, glm::vec2(150, 10), glm::vec2(720 * (boss_->getHp() / boss_->getMaxHp()), 34),
            1, glm::vec4(207 / 255.0f, 46 / 255.0f, 90 / 255.0f, 1.0f));
    }
    
    if (player_ != nullptr && player_->isRemoving())
    {
        stgbase::Renderer::drawString(fail_, glm::vec2(601, 351), glm::vec4(0, 0, 0, 1));
        stgbase::Renderer::drawString(fail_, glm::vec2(600, 350), glm::vec4(1, 1, 1, 1));
        if (stgbase::keyState[27])
        {
            this->is_restarting_ = true;
        }
    }
    else if (boss_ != nullptr && boss_->isRemoving())
    {
        stgbase::Renderer::drawString(win_, glm::vec2(601, 351), glm::vec4(0, 0, 0, 1));
        stgbase::Renderer::drawString(win_, glm::vec2(600, 350), glm::vec4(1, 1, 1, 1));
    }
    
}


//
//  add random enemies
//
void BattleScene::newEnemy()
{
    int t;
    if (total_time_ <= 10)
        t = (int)glm::linearRand(0.0f,3.0f) % 3;
    else t = (int)glm::linearRand(0.0f, 6.0f) % 6;

    auto pi = glm::pi<float>();
    auto rand1 = glm::linearRand(0.0f, 1.0f);
    auto rand2 = glm::linearRand(0.0f, 1.0f);
    switch (t)
    {
    case 0:
        world_->addBattler(new stgbattlers::Enemy1(glm::vec2(1330, rand1 * 720 / 2), 2, world_.get(), pi * 0.8));
        break;
    case 1:
        world_->addBattler(new stgbattlers::Enemy1(glm::vec2(-50, rand1 * 720 / 2), 2, world_.get(), pi * 0.2));
        break;
    case 2:
        world_->addBattler(new stgbattlers::Enemy1(glm::vec2(rand1*1280, -50), 2, world_.get(), pi * rand2));
        break;
    case 3:
        world_->addBattler(new stgbattlers::Enemy2(glm::vec2(1330, rand1 * 720 / 2), 2, world_.get(), pi * 0.8));
        break;
    case 4:
        world_->addBattler(new stgbattlers::Enemy2(glm::vec2(-50, rand1 * 720 / 2), 2, world_.get(), pi * 0.2));
        break;
    case 5:
        world_->addBattler(new stgbattlers::Enemy2(glm::vec2(rand1 * 1280, -50), 2, world_.get(), pi * rand2));
        break;
    }
}

bool BattleScene::isRemoving()
{
    return is_restarting_;
}
