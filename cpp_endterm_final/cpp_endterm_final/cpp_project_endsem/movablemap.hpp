//
//  movablemap.hpp
//  chaljaPlease
//
//  Created by vatsal dhama on 22/11/21.
//

#ifndef movablemap_hpp
#define movablemap_hpp

#include "game_1.hpp"
#include "Game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
class movablemap
{
public:
    movablemap(const char*  s, SDL_Renderer * r, int x, int y);
    ~movablemap();
    void Update(string s);
    void battlecry(const char *texture,int segment);
    void Render();
    int srcx,srcy,destx,desty;
    
private:
    SDL_Renderer* renderer;
    SDL_Texture* tex;
    SDL_Rect srcR, destR;
    int x, y;
    
        

    
};

#endif /* movablemap_hpp */
