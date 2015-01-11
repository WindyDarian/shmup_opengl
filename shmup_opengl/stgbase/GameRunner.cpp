// Author: Windy Darian
// Date Created: Jan 10, 2015

#include "GameRunner.h"
#include <iostream>
using namespace stgbase;


//used to wrap a pointer to member function renderCallback()
GameRunner* gameRunnerRenderCallbackObj = nullptr;
GLuint tex;
GLuint bg;

//
//  Initialize and run the game
//
GameRunner::GameRunner(int argc, char** argv)
{
    //  Create GL context
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(this->windowWidth_, this->windowHeight_);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("卧槽");

    //  Initialize 2d projection matrix
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, this->windowWidth_, 0, this->windowHeight_, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    ::gameRunnerRenderCallbackObj = this;
    glutDisplayFunc(gameRunnerRenderCallback);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    tex = DataManager::reloadTexture("res/player.png");
    bg = DataManager::reloadTexture("res/background.png");

    glutMainLoop();
}

GameRunner::~GameRunner()
{
    if (::gameRunnerRenderCallbackObj == this)
        ::gameRunnerRenderCallbackObj = nullptr;
}

//
//  Update game logic, called every frame
//
void GameRunner::update(float elapsedTime)
{

}

//
//  Draw the game scene, called every frame
//
void GameRunner::draw(float elapsedTime)
{
    Renderer::drawTex(bg, glm::vec2(0, 0), glm::vec2(this->windowWidth_, this->windowHeight_));
    Renderer::drawTex(tex, glm::vec2(100, 100), glm::vec2(128, 128), 0.5f, COLOR_WHITE);
    Renderer::drawTex(tex, glm::vec2(100, 128), glm::vec2(256, 128), 5.0f, glm::vec4(1.0f,0.2f,0.2f,1));
}

//  The callback function, 
void GameRunner::renderCallback()
{

    //this->update();

    glClear(GL_COLOR_BUFFER_BIT);

    this->draw(0.0f);


    glutSwapBuffers();
}

void stgbase::gameRunnerRenderCallback()
{
    if (::gameRunnerRenderCallbackObj != nullptr)
        ::gameRunnerRenderCallbackObj->renderCallback();
}
