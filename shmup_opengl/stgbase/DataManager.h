//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <SOIL.h>

namespace stgbase{
    //
    //  The class is used to manage data like textures and sounds
    //
    class DataManager
    {
        //typedef std::shared_ptr<GLuint> TexturePointer;
    public:
        static GLuint reloadTexture(std::string fileName);
        static GLuint getTexture(std::string fileName);
        static void deleteTexture(std::string fileName);
    private:
        static std::unordered_map<std::string, GLuint> textures_;
        
    };
}

