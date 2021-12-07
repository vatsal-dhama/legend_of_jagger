#include "Player_right.hpp"

Player_right::Player_right()
{
    setTexture("assets/right.png");
    tex_attacking1 = TextureManager::LoadTexture("assets/r_attack1.png");
    tex_attacking2 = TextureManager::LoadTexture("assets/r_attack2.png");

    setSrc(0, 0, 120, 120);
    setDest(800, 400);

}

void Player_right::updater()
{
    keyboard_handlerr();
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    
    if(attack == 1)
    {
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
                    }
                        
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
                    }
                        
                    break;
                }
        }
    }
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
    if(attack == 1)
    {
        switch(animate_type)
        {
            case RUN_LEFTr:
                SDL_RenderCopy(Game::renderer, tex_attacking1, &src_rect, &dest_rect);
                break;
            
            case IDLEr:
                SDL_RenderCopy(Game::renderer, tex_attacking2, &src_rect, &dest_rect);
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