//
//  Element.hpp
//  chaljaPlease
//
//  Created by vatsal dhama on 20/11/21.
//
#pragma once
#ifndef Element_hpp
#define Element_hpp

#include "game_1.hpp"
#include "movablemap.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>



class Element
{
public:
    Element(const char*  s, SDL_Renderer * r, int x, int y, movablemap* map);
    ~Element();
    void Update(string s);
    void Render();
    
private:
    SDL_Renderer* renderer;
    SDL_Texture* tex;
    SDL_Rect srcR, destR;
    int x, y;
    int srcx,srcy;
    movablemap* currmap;

    
};

#endif /* Element_hpp */
