#include "Player_right.hpp"
#include <SDL2/SDL_mixer.h>


Player_right::Player_right()
{
    setTexture("assets/hero.png");
    tex_attacking1 = TextureManager::LoadTexture("assets/hero.png");
    tex_attacking2 = TextureManager::LoadTexture("assets/hero.png");

    setSrc(0, 50, 120, 120);
    setDest(800, 410);

}

int Player_right::updater()
{
    int a;
    Get_keyboard_inputs();
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    
    if(attack == 1)
    {
        a=10;
        switch(animate_type)
        {
            case 1:
                if(jump_frame_count1 >=0)
                {
                    animate_1();
                    if(jump_frame_count1 == 10)
                    {   
                        jump_frame_count1 = -1;
                        attack = 0;
                        a=10;
                    }
                    else
                        a=0;
                        
                    break;
                }
                
            case 2:
                if(jump_frame_count2 >= 0)
                {
                    animate_2();
                    if(jump_frame_count2 == 10)
                    {
                        jump_frame_count2 = -1;
                        attack = 0;
                        a=15;
                    }
                    else
                        a=0;
                        
                    break;
                }
                else{
                    a=0;
                    break;
                }
        }
    }
    else
        a=0;
        return a;
}

void Player_right::Get_keyboard_inputs()
{
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if(currentKeyStates[SDL_SCANCODE_1])
        {
            animate_type = 1;
            attack = 1;
            jump_frame_count1 = 0;
        }

        if(currentKeyStates[SDL_SCANCODE_2])
        {
            animate_type = 2;
            attack = 1;
            jump_frame_count2 = 0;           
        }
}

void Player_right::animate_1()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 3;
    src_rect.x = player[current_frame][0];
    src_rect.w = player[current_frame][1];
    src_rect.h = player[current_frame][2];    
    src_rect.y = 33;

    dest_rect.w = 200;
    dest_rect.h = 240;
    dest_rect.x = 560;
    dest_rect.y = 400;

    jump_frame_count1++;
    
}

void Player_right::animate_2()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 3;
    src_rect.x = player[current_frame][0];
    src_rect.w = player[current_frame][1];
    src_rect.h = player[current_frame][2];    
    src_rect.y = 33;

    dest_rect.w = 200;
    dest_rect.h = 240;
    dest_rect.x = 560;
    dest_rect.y = 400;

    jump_frame_count2++;
}

void Player_right::renderr()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Error: " << Mix_GetError() << std::endl;
    }
    Mix_Chunk *a = Mix_LoadWAV("assets/1.wav");
    Mix_Chunk* b = Mix_LoadWAV("assets/2.wav");
    if(attack == 1)
    {
        switch(animate_type)
        {
            case 1:
                Mix_PlayChannel(-1, a, 0);
                SDL_RenderCopy(Game::renderer, tex_attacking1, &src_rect, &dest_rect);
                
                break;
            
            case 2:
                Mix_PlayChannel(-1, b, 0);
                SDL_RenderCopy(Game::renderer, tex_attacking2, &src_rect, &dest_rect);
                
                break;
        }
    }
    else
    {
        //setSrc(0, 65, 30, 30);
        setSrc(0, 35, 30, 30);
        //setDest(600, 800);
        SDL_RenderCopy(Game::renderer, objTexture, &src_rect, &dest_rect);
    }       
}