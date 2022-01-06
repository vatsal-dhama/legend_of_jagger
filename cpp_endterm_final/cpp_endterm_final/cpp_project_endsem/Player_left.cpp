#include "Player_left.hpp"

Player_left::Player_left(const char *texture,int segment)
{
    setTexture(texture);

    if(segment == 1)
    {
        tex_attackingl1 = TextureManager::LoadTexture("assets/forest.png");
    }
    else if(segment == 2)
    {
        tex_attackingl1 = TextureManager::LoadTexture("assets/desert.png");
    }
    else if(segment == 3)
    {
        tex_attackingl1 = TextureManager::LoadTexture("assets/dark.png");
    }
    
    setSrc(0, 50, 120, 120);
    setDest(150, 400);
}

int Player_left::update(int a)
{
    int b=0;
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    
    if(a)
    {          
        attackL1 = 1;
        jump_frame_count = 0;
        b=1;
    }

    if(attackL1 == 1)
    {
        if(jump_frame_count >=0)
        {
            animate();

            if(jump_frame_count == 10)
            {   
                jump_frame_count = -1;
                attackL1 = 0;
                b=0;    
            }
        }
    }
    return b;

}

void Player_left::animate()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 3;
    src_rect.x = player[current_frame][0];
    src_rect.w = player[current_frame][1];
    src_rect.h = player[current_frame][2]; 
    src_rect.y = 150;

    dest_rect.w = 200;
    dest_rect.h = 240;
    dest_rect.x = 540;
    dest_rect.y = 400;

    jump_frame_count++;
}

void Player_left::render()
{
    if(attackL1 == 1)
    {
        SDL_RenderCopy(Game::renderer, tex_attackingl1, &src_rect, &dest_rect);
    }
    else
    {
        setSrc(65, 65, 60, 30);
        SDL_RenderCopy(Game::renderer, objTexture, &src_rect, &dest_rect);
    }
}