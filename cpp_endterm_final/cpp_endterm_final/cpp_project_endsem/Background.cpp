#include "Background.hpp"

Background::Background()
{
    tempSurface = IMG_Load("assets/ggg.gif");
    tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_RenderCopy(Game::renderer, tex, NULL, NULL);

    Animating_B = TextureManager::LoadTexture("assets/spritesheet.png");

}

void Background::update()
{
    animate();
}

void Background::animate()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 4;
    src_rect.x = background[current_frame][0];
    src_rect.w = background[current_frame][1];
    src_rect.h = background[current_frame][2];    
    src_rect.y = 0;

}

void Background::render()
{
    SDL_RenderCopy(Game::renderer, Animating_B, &src_rect, NULL); 
}