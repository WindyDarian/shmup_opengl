// Author: Windy Darian
// Date Created: Jan 10, 2015

#include "GameRunner.h"
#include <iostream>
using namespace stgbase;


//used to wrap a pointer to member function renderCallback()
GameRunner* gameRunnerRenderCallbackObj = nullptr;
GLuint tex;

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

    //temp
    //create test checker image
    tex = DataManager::reloadTexture("res/player.png");
    //tex = loadPNG2("res/player.png");



    //upload to GPU texture
    std::cout << tex << std::endl;




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


    //clear and draw quad with texture (could be in display callback)
    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0); glVertex2i(100, 100);
    glTexCoord2i(0, 1); glVertex2i(100, 500);
    glTexCoord2i(1, 1); glVertex2i(500, 500);
    glTexCoord2i(1, 0); glVertex2i(500, 100);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
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
