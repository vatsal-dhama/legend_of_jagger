#pragma once

#include "Game.hpp"
#include <vector>

class GameObject
{
    public:
        void setTexture(const char *texturesheet);
        void setSrc(int x, int y, int w, int h);
        void setDest(int x, int y);
        
    protected:
        int xpos, ypos, width, height;
        SDL_Texture *objTexture;
        SDL_Rect src_rect, dest_rect;   
};