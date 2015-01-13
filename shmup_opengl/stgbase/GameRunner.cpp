// Author: Windy Darian
// Date Created: Jan 10, 2015

#include "GameRunner.h"
#include "input_state.h"


using namespace stgbase;



//used to wrap a pointer to member function renderCallback()
GameRunner* callbackGameRunnerObj = nullptr;


//
//  Initialize and run the game
//
GameRunner::GameRunner() :view_size_(1280.0f,720.0f)
{
    setMaxFps(-1);
}


GameRunner::~GameRunner()
{
    if (::callbackGameRunnerObj == this)
        ::callbackGameRunnerObj = nullptr;
}

void GameRunner::setWindowSize(int width, int height)
{
    this->window_width_ = width;
    this->window_height_ = height;
}

void GameRunner::setViewSize(float width, float height)
{
    this->view_size_ = glm::vec2(width, height);
}

//
//  set max frame rate
//
void GameRunner::setMaxFps(float max_fps)
{
    this->max_fps_ = max_fps;
    if (max_fps <= 0)
        min_idle_time_ = 0;
    else
        min_idle_time_ = 1000.0f / max_fps;
}


//
//  That's where the game start
//
void GameRunner::start()
{
    //  Initialize GL context
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(this->window_width_, this->window_height_);
    glutCreateWindow("卧槽");

    //  Initialize 2-D projection
    glMatrixMode(GL_PROJECTION);
    //glOrtho(0, this->view_size_[0], 0, this->view_size_[1], -1, 1);  //Y-up
    // Although I prefer to use Y-up coordinate for 2-D now, I'll just use window coordinate atm
    glOrtho(0, this->view_size_[0], this->view_size_[1], 0, -1, 1);   //Y-down
    glMatrixMode(GL_MODELVIEW);

    ::callbackGameRunnerObj = this;
    glutIdleFunc(gameGlutIdleCallback);
    glutDisplayFunc(gameGlutDisplayCallback);
    glutKeyboardFunc(stgGlutKeyboardCallback);
    glutKeyboardUpFunc(stgGlutKeyboardUpCallback);
    glutMouseFunc(stgGlutMouseCallback);
    glutSpecialFunc(stgGlutSpecialInputCallback);
    glutSpecialUpFunc(stgGlutSpecialInputUpCallback);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);



    started();

    glutMainLoop();

}

//
//  Update game logic, called every frame
//  elapsedTime is the time since last update() was called, in seconds
//
void GameRunner::update(float elapsedTime)
{
}

//
//  Draw the game scene, called every frame
//  elapsedTime is the time since last draw() was called, in seconds
//
void GameRunner::draw(float elapsedTime)
{
}

//
//  The callback function for display, calls update()
//
void GameRunner::idleCallback()
{
    auto currentTime = glutGet(GLUT_ELAPSED_TIME);
    auto elapsedTime = static_cast<float>(currentTime - this->prev_update_time_)*0.001f;
    this->prev_update_time_ = currentTime;

    this->update(elapsedTime);

    //call display.
    if (currentTime - this->prev_draw_time_ >= this->min_idle_time_)
        glutPostRedisplay();
}

//
//  The callback function for display, calls draw()
//
void GameRunner::displayCallback()
{
    auto currentTime = glutGet(GLUT_ELAPSED_TIME);
    auto elapsedTime = static_cast<float>(currentTime - this->prev_draw_time_)*0.001f;
    this->prev_draw_time_ = currentTime;
    
    glClear(GL_COLOR_BUFFER_BIT);

    this->draw(elapsedTime);


    glutSwapBuffers();
}

void stgbase::gameGlutDisplayCallback()
{
    if (::callbackGameRunnerObj != nullptr)
        ::callbackGameRunnerObj->displayCallback();
}

void stgbase::gameGlutIdleCallback()
{
    if (::callbackGameRunnerObj != nullptr)
        ::callbackGameRunnerObj->idleCallback();
}
