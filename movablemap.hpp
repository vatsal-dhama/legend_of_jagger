//
//  movablemap.hpp
//  chaljaPlease
//
//  Created by vatsal dhama on 22/11/21.
//

#ifndef movablemap_hpp
#define movablemap_hpp

#include "game.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
class movablemap
{
public:
    movablemap(const char*  s, SDL_Renderer * r, int x, int y);
    ~movablemap();
    void Update(string s);
    void Render();
    int srcx,srcy,destx,desty;
    
private:
    SDL_Renderer* renderer;
    SDL_Texture* tex;
    SDL_Rect srcR, destR;
    int x, y;
    
        

    
};

#endif /* movablemap_hpp */
