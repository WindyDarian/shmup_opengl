//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#pragma once
#include <memory>
#include <string>
#include <GL/glut.h>
#include "../stgbase/Scene.h"
#include "../stgcombat/GameWorld.h"
#include "../stgcombat/Battler.h"
#include "../stgbase/GameRunner.h"

namespace stgscenes{
    //
    //  The only level of the game
    //
    class BattleScene:
        public stgbase::Scene
    {
    public:
        BattleScene(GameRunner* runner);

        void update(float elapsedTime);
        void draw(float elapsedTime);
        bool isRemoving();

    private:
        void newEnemy();

        std::unique_ptr<stgcombat::GameWorld> world_;
        float total_time_ = 0;
        float respawn_time_ = 4;
        float current_respawn_ = 0;
        std::shared_ptr<stgcombat::Battler> player_;
        std::shared_ptr<stgcombat::Battler> boss_;
        std::string win_ = "Fly to the Sky!\n Victory!";
        std::string fail_ = "Try again!\nPress [esc] to restart";
        bool is_restarting_ = false;
        GLuint player_icon_;
    };
}
