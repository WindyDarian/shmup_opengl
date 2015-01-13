//  Author: Windy Darian
//  Date Created: Jan 10, 2015
#pragma once
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <glm/glm.hpp>
#include <string>


static auto COLOR_WHITE = glm::vec4(1, 1, 1, 1);

namespace stgbase{
    //
    //  This is a static class to initialize and control opengl context
    //
    class Renderer
    {
    public:
        static void drawTex(GLuint texture, glm::vec2& position, glm::vec2& size);
        static void drawTex(GLuint texture, glm::vec2& position, glm::vec2& size, float scale, glm::vec4& color);
        static void drawTexCentered(GLuint texture, glm::vec2& pos, glm::vec2& size);
        static void drawTexCentered(GLuint texture, glm::vec2& pos, glm::vec2& size, float scale, glm::vec4& color);
        static void drawTexCentered(GLuint texture, glm::vec2& pos, glm::vec2& size, float scale, glm::vec4& color, float rotation);
        static void drawString(std::string msg, glm::vec2& pos, glm::vec4& color);
    };

}

