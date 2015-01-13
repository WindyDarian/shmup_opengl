//
//  Date Created: Jan 13, 2015
//
//  Used to record input state
//
#pragma once

#include <GL/glut.h>

#define BUTTON_UP   0
#define BUTTON_DOWN 1

#define MOUSE_LEFT   0
#define MOUSE_MIDDLE 1
#define MOUSE_RIGHT  2

namespace stgbase{

    extern unsigned char keyState[255];
    extern unsigned char mouseState[3];
    extern unsigned char specialInputState[255];

    void stgGlutKeyboardCallback(unsigned char key, int x, int y);

    void stgGlutKeyboardUpCallback(unsigned char key, int x, int y);

    void stgGlutMouseCallback(int button, int button_state, int x, int y);

    void stgGlutSpecialInputCallback(int key, int x, int y);

    void stgGlutSpecialInputUpCallback(int key, int x, int y);
}