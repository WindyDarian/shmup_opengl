//  Author: Windy Darian
//  Date Created: Jan 10, 2015
#pragma once
#include <GL/freeglut.h>
#include <GL/GL.h>



namespace stgbase{
    //
    //  This is a static class to initialize and control opengl context
    //
    class Renderer
    {
    public:
        static void initialize2D(int width, int height);
        static void drawImage(GLuint texture, int x, int y, int width, int height);
        static void drawImage(GLuint texture, int x, int y, int width, int height, );
        static void drawImage(GLuint texture, int x, int y, int width, int height, )
        static void drawImageCentered(GLuint texture, int x, int y, int width, int height, )
        static void drawImageCentered(GLuint texture, int x, int y, int width, int height, )
        static void drawImageCentered(GLuint texture, int x, int y, int width, int height, )
    };

}

