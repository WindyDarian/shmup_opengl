#include "Renderer.h"
#include <glm/gtx/rotate_vector.hpp>
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
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
void Renderer::drawTexCentered(GLuint texture, glm::vec2& position, glm::vec2& size)
{
    drawTexCentered(texture, position, size, 1.0f, COLOR_WHITE, 0.0f);
}

//
// Draw a texture with specific center position, size, scale, color and rotation (in rad)
//
void Renderer::drawTexCentered(GLuint texture, glm::vec2& position, glm::vec2& size, float scale, glm::vec4& color)
{
    drawTexCentered(texture, position, size, scale, color, 0.0f);
}

//
// Draw a texture with specific center position, size, scale, color and rotation (in rad)
//
void Renderer::drawTexCentered(GLuint texture, glm::vec2& position, glm::vec2& size, float scale, glm::vec4& color, float rotation)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glColor4f(color[0], color[1], color[2], color[3]);

    glm::vec2 fsize = size;
    if (scale != 1.0f)
    {
        fsize *= scale;
    }

    auto offset1 = glm::vec2(-size[0], -size[1]) * 0.5f * scale;
    auto offset2 = glm::vec2(-size[0], size[1]) * 0.5f * scale;
    auto offset3 = glm::vec2(size[0], size[1]) * 0.5f * scale;
    auto offset4 = glm::vec2(size[0], -size[1]) * 0.5f * scale;

    if (rotation != 0.0f)
    {
        //  rotate the offset vectors
        offset1 = glm::rotate(offset1, rotation);
        offset2 = glm::rotate(offset2, rotation);
        offset3 = glm::rotate(offset3, rotation);
        offset4 = glm::rotate(offset4, rotation);
    }

    offset1 = offset1 + position;
    offset2 = offset2 + position;
    offset3 = offset3 + position;
    offset4 = offset4 + position;

    glBindTexture(GL_TEXTURE_2D, texture);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex2f(offset1[0], offset1[1]);
    glTexCoord2f(0, 1); glVertex2f(offset2[0], offset2[1]);
    glTexCoord2f(1, 1); glVertex2f(offset3[0], offset3[1]);
    glTexCoord2f(1, 0); glVertex2f(offset4[0], offset4[1]);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

void Renderer::drawString(std::string msg, glm::vec2& pos, glm::vec4& color)
{
    glRasterPos2i(pos[0], pos[1]);
    glColor4f(color[0], color[1], color[2], color[3]);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, (const unsigned char *)msg.c_str());
}
