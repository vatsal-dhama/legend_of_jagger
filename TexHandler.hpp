//
//  TexHandler.hpp
//  chaljaPlease
//
//  Created by vatsal dhama on 20/11/21.
//
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef TexHandler_hpp
#define TexHandler_hpp

#include <stdio.h>

class TexHandler{
    public :
    static SDL_Texture* GetTex(const char* s, SDL_Renderer* renderer);
    static void directDraw(SDL_Renderer* renderer, SDL_Texture* tex,SDL_Rect* src, SDL_Rect* dest);
    private :
};

#endif /* TexHandler_hpp */
