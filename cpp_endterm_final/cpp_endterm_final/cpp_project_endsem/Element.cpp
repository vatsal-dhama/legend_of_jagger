#include "Element.hpp"
#include "TexHandler.hpp"



Element::Element(const char* s, SDL_Renderer* r, int x1, int y1, movablemap* map){
    renderer = r;
    x = 640;
    y = 360;
    srcx = 0;
    srcy = 0;
    tex = TexHandler::GetTex(s, renderer);
    currmap = map;
}
void Element::Update(string s){
    
    
//walking animation
    if(s == "up"){
        //y = y-16;
        srcy = 96;
        if(srcx == 0){
            srcx += 32;
        }
        else if (srcx == 32){
            srcx+= 32;
        }
        else{srcx =0;}
    }
    if(s=="down"){
        //y = y+16;
        srcy = 0;
        if(srcx == 0){
            srcx += 32;
        }
        else if (srcx == 32){
            srcx+= 32;
        }
        else{srcx =0;}
    }
    if(s=="right"){
        //x = x+16;
        srcy = 64;
        if(srcx == 0){
            srcx += 32;
        }
        else if (srcx == 32){
            srcx+= 32;
        }
        else{srcx =0;}
    }
    if(s == "left"){
        //x = x-16;
        srcy = 32;
        if(srcx == 0){
            srcx += 32;
        }
        else if (srcx == 32){
            srcx+= 32;
        }
        else{srcx =0;}
    }
    SDL_Delay(40);
    srcR.h = 32;
    srcR.w = 32;
    srcR.x = srcx;
    srcR.y = srcy;
    
    destR.h = srcR.h;
    destR.w = srcR.w;
    destR.x = x;
    destR.y = y;
}
void Element::Render(){
    SDL_RenderCopy(renderer, tex, &srcR,&destR);
}
