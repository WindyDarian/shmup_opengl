//  Author: Windy Darian
//  Date Created: Jan 13, 2015
#include "input_state.h"

unsigned char stgbase::keyState[255];
unsigned char stgbase::mouseState[3];
unsigned char stgbase::specialInputState[255];

void stgbase::stgGlutKeyboardCallback(unsigned char key, int x, int y)
{
    keyState[key] = BUTTON_DOWN;
}

void stgbase::stgGlutKeyboardUpCallback(unsigned char key, int x, int y)
{
    keyState[key] = BUTTON_UP;
}

void stgbase::stgGlutMouseCallback(int button, int button_state, int x, int y)
{
#define state ( (button_state == GLUT_DOWN) ? BUTTON_DOWN : BUTTON_UP ) // shortens later code

    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        mouseState[MOUSE_LEFT] = state;
        break;
    case GLUT_MIDDLE_BUTTON:
        mouseState[MOUSE_MIDDLE] = state;
        break;
    case GLUT_RIGHT_BUTTON:
        mouseState[MOUSE_RIGHT] = state;
        break;
    }

#undef state // make sure the defined "state" code above is only used in this function
}


void stgbase::stgGlutSpecialInputCallback(int key, int x, int y)
{
    specialInputState[key] = BUTTON_DOWN;
}

void stgbase::stgGlutSpecialInputUpCallback(int key, int x, int y)
{
    specialInputState[key] = BUTTON_UP;
}