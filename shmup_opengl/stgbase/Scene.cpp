//  Author: Windy Darian
//  Date Created: Jan 13, 2015

#include "Scene.h"
#include "Renderer.h"

using namespace stgbase;

Scene::Scene(GameRunner* runner) :runner(runner)
{}

//
//  Draw scene background
//
void Scene::draw(float elapsedTime)
{
    if (background_tex != 0)
    {
        Renderer::drawTex(background_tex, glm::vec2(0, 0), runner->getViewSize());
    }
}

bool Scene::getIsVisible()
{
    return this->is_visible;
}

bool Scene::getIsActive()
{
    return this->is_active;
}

void Scene::open()
{
    this->is_active = true;
    this->is_visible = true;
}

void Scene::close()
{
    this->is_active = false;
    this->is_visible = false;
}