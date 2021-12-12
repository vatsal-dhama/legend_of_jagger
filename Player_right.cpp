#include "Player_right.hpp"
#include<SDL_mixer.h>


Player_right::Player_right()
{
    setTexture("C:\\IIITB\\Second year- first sem\\Cpp\\Project\\Rahul and anshul\\assets\\right.png");
    tex_attacking1 = TextureManager::LoadTexture("C:\\IIITB\\Second year- first sem\\Cpp\\Project\\Rahul and anshul\\assets\\r_attack1.png");
    tex_attacking2 = TextureManager::LoadTexture("C:\\IIITB\\Second year- first sem\\Cpp\\Project\\Rahul and anshul\\assets\\r_attack2.png");

    setSrc(0, 0, 120, 120);
    setDest(800, 400);

}

int Player_right::updater()
{
    int a;
    keyboard_handlerr();
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    
    if(attack == 1)
    {
        a=10;
        switch(animate_type)
        {
            case RUN_LEFTr:
                if(jump_frame_count1 >=0)
                {
                    animate_idler();
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
                
            case IDLEr:
                if(jump_frame_count2 >= 0)
                {
                    animate_runr();
                    if(jump_frame_count2 == 10)
                    {
                        jump_frame_count2 = -1;
                        attack = 0;
                        a=10;
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

void Player_right::keyboard_handlerr()
{
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        if(currentKeyStates[SDL_SCANCODE_1])
        {
            animate_type = RUN_LEFTr;
            attack = 1;
            jump_frame_count1 = 0;
        }

        if(currentKeyStates[SDL_SCANCODE_2])
        {
            animate_type = IDLEr;
            attack = 1;
            jump_frame_count2 = 0;           
        }
}

void Player_right::animate_idler()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 5;
    src_rect.x = player_idle[current_frame][0];
    src_rect.w = player_idle[current_frame][1];
    src_rect.h = player_idle[current_frame][2];    
    src_rect.y = 0;

    dest_rect.w = 200;
    dest_rect.h = 240;
    dest_rect.x = 800;
    dest_rect.y = 400;

    jump_frame_count1++;
    
}

void Player_right::animate_runr()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 5;
    src_rect.x = player_idle[current_frame][0];
    src_rect.w = player_idle[current_frame][1];
    src_rect.h = player_idle[current_frame][2];    
    src_rect.y = 0;

    dest_rect.w = 200;
    dest_rect.h = 240;
    dest_rect.x = 800;
    dest_rect.y = 400;

    jump_frame_count2++;
}

void Player_right::renderr()
{
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Error: " << Mix_GetError() << std::endl;
    }
    Mix_Chunk *a = Mix_LoadWAV("C:\\IIITB\\Second year- first sem\\Cpp\\Project\\Rahul and anshul\\assets\\1.wav");
    Mix_Chunk* b = Mix_LoadWAV("C:\\IIITB\\Second year- first sem\\Cpp\\Project\\Rahul and anshul\\assets\\2.wav");
    if(attack == 1)
    {
        switch(animate_type)
        {
            case RUN_LEFTr:
                SDL_RenderCopy(Game::renderer, tex_attacking1, &src_rect, &dest_rect);
                Mix_PlayChannel(-1, a, 0);
                break;
            
            case IDLEr:
                SDL_RenderCopy(Game::renderer, tex_attacking2, &src_rect, &dest_rect);
                Mix_PlayChannel(-1, b, 0);
                break;
        }
    }
    else
    {
        setSrc(0, 0, 120, 120);
        setDest(800, 400);
        SDL_RenderCopy(Game::renderer, objTexture, &src_rect, &dest_rect);
    }
    

    cout << attack << endl;
        
}