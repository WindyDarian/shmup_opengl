//  Author: Windy Darian
//  Date Created: Jan 13, 2015

#include "TitleScene.h"
#include "../StgRunner.h"
#include <glm/gtc/constants.hpp>
#include "../stgbase/Renderer.h"

#include "../stgbase/input_state.h"
#include <glm/gtc/random.hpp>

using namespace stgscenes;

TitleScene::TitleScene(GameRunner* runner)
    :stgbase::Scene(runner)
{
    Scene::background_tex = DataManager::getTexture("res/background.png");
    message_ = std::string() + 
        "    Use [arrow keys] and [Space] to play.\n" +
        "\n" +
        "    Take Off!\n" +
        "\n" +
        "\n" +
        "\n" +
        "              Press [Space] to continue";
}

//
//  update level logic
//
void TitleScene::update(float elapsedTime)
{
    stgbase::Scene::update(elapsedTime);

    if (stgbase::keyState[' '] || stgbase::keyState['\r'])
        if (auto stg_runner = dynamic_cast<StgRunner*>(runner))
            stg_runner->startBattle();

}


//
//  Draw UI
//
void TitleScene::draw(float elapsedTime)
{
    stgbase::Scene::draw(elapsedTime);
    stgbase::Renderer::drawString(message_, glm::vec2(300, 301), glm::vec4(0, 0, 0, 1));
    stgbase::Renderer::drawString(message_, glm::vec2(300, 300), glm::vec4(1, 1, 1, 1));
}


bool TitleScene::isRemoving()
{
    return false;
}
