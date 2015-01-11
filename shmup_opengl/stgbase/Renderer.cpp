#include "Renderer.h"
using namespace stgbase;

//
// Draw a texture with specific position and size
//
void Renderer::drawTex(GLuint texture, glm::vec2& position, glm::vec2& size)
{
    drawTex(texture, position, size, 1.0f, COLOR_WHITE);
}

//
// Draw a texture with specific position, size, scale and color
//
void Renderer::drawTex(GLuint texture, glm::vec2& position, glm::vec2& size, float scale, glm::vec4& color)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4f(color[0], color[1], color[2], color[3]);

    glm::vec2 fsize = size;
    if (scale != 1.0f)
    {
        fsize *= scale;
    }

    glBindTexture(GL_TEXTURE_2D, texture);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2f(position[0], position[1]);
    glTexCoord2f(0, 1); glVertex2f(position[0], position[1] + fsize[1]);
    glTexCoord2f(1, 1); glVertex2f(position[0] + fsize[0], position[1] + fsize[1]);
    glTexCoord2f(1, 0); glVertex2f(position[0] + fsize[0], position[1]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

//
// Draw a texture with specific center position, size, scale, color and rotation (in rad)
//
static void drawTexCentered(GLuint texture, glm::vec2& position, glm::vec2& size, float scale, glm::vec4& color, float rotation)
{

}