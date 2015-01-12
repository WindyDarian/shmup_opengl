//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#include "DataManager.h"
#include <iostream>
using namespace stgbase;


std::unordered_map<std::string, GLuint> DataManager::textures_;

//
//  load a PNG using SOIL 
//
GLuint loadPNG(std::string filename)
{
    GLuint texture = SOIL_load_OGL_texture
        (
        filename.c_str(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        //SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_COMPRESS_TO_DXT //if I am about to use Y-up coordinate
        SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_COMPRESS_TO_DXT
        );
    
    //glBindTexture(GL_TEXTURE_2D, texture);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    //glBindTexture(GL_TEXTURE_2D, 0);

    return texture;
}

//
//  Load a png Texture from file and store it in textures_,
//  even if the same file has been loaded.
//
GLuint DataManager::reloadTexture(std::string fileName)
{
    auto tex = loadPNG(fileName);
    textures_[fileName] = tex;
    return tex;
}

//
//  If a texture aleady loaded then return the content 
//  if not, load the texture and return the content
//
GLuint DataManager::getTexture(std::string fileName)
{
    auto iter = textures_.find(fileName);
    if (iter == textures_.end())
        return reloadTexture(fileName);
    else return iter->second;
}

//
//  Delete a texture in memory along with the key
//
void DataManager::deleteTexture(std::string fileName)
{
    auto iter = textures_.find(fileName);
    if (iter != textures_.end())
    {
        glDeleteTextures(1, &(iter->second));
        textures_.erase(iter);
    }
}
