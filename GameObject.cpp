#include "GameObject.hpp"
#include "TextureManager.hpp"

void GameObject::setTexture(const char *texturesheet)
{
    objTexture = TextureManager::LoadTexture(texturesheet);
}

void GameObject::setSrc(int x, int y, int w, int h)
{
    src_rect.x = x;
    src_rect.y = y;
    src_rect.w = w;
    src_rect.h = h;
}

void GameObject::setDest(int x, int y)
{
    xpos = x;  
    ypos = y;  

    dest_rect.x = x;
    dest_rect.y = y;
    dest_rect.w = src_rect.w*2;
    dest_rect.h = src_rect.h*2;
}




