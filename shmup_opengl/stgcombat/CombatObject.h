//  Author: Windy Darian
//  Date Created: Jan 11, 2015
#pragma once
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <glm/glm.hpp>
#include "../stgbase/IUpdatable.h"
#include "../stgbase/IDrawable.h"
#include "../stgbase/IRemovable.h"
#include <iostream>

namespace stgcombat{
    //
    //  The main objects (player, enemy, bullets) in game
    //
    class CombatObject:
        public stgbase::IUpdatable,
        public stgbase::IDrawable,
        public stgbase::IRemovable
    {
    public:
        static bool isCollided(CombatObject& a, CombatObject& b);

        CombatObject(GLuint texture, glm::vec2& position,
            float bounding_radius, int faction, float scale, glm::vec4& color);
        CombatObject(GLuint texture, glm::vec2& position,
            float bounding_radius, int faction, float scale,
            glm::vec4& color, float direction, float rotation, float speed);
        ~CombatObject() { /*std::cout << "I am dead!" << std::endl;*/ };
        virtual void update(float elapsedTime);
        virtual void draw(float elapsedTime);

        virtual bool getIsActive() { return true; }
        virtual bool getIsVisible() { return true; }
        virtual bool isRemoving(){ return is_being_removed_; }
        
        virtual void remove();
        virtual void beginToDie();

        void setDirection(float direction);
        float getDirection(){return direction_;}
        glm::vec2 getDirectionVec(){ return direction_vec_; }

        GLuint texture;
        glm::vec2 texSize = glm::vec2(256.0f, 256.0f);
        glm::vec2 position;
        //  potision at last update(), but not used yet
        glm::vec2 positionl;
        float bounding_radius = 0;
        float scale = 1.0f;
        glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        int faction = 0;
        float rotation = 0;

        float speed = 0;
        bool is_dying = false;

    private:
        bool is_being_removed_ = false;
        float direction_;
        //  A normalized vector pointing to moving direction
        glm::vec2 direction_vec_;
    };

}

