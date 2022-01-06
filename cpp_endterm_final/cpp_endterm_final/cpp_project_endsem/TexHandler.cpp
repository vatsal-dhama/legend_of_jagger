//
//  TexHandler.cpp
//  chaljaPlease
//
//  Created by vatsal dhama on 20/11/21.
//

#include "TexHandler.hpp"
#include <SDL2/SDL.h>
SDL_Texture* TexHandler::GetTex(const char *s, SDL_Renderer *renderer){
    
    SDL_Surface* surf = IMG_Load(s);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer,surf);
    SDL_FreeSurface(surf);
    return tex;
}
void TexHandler::directDraw( SDL_Renderer *renderer, SDL_Texture* tex,SDL_Rect *src, SDL_Rect *dest){
    
    SDL_RenderCopy(renderer, tex, src, dest);
}
