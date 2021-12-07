#include "Player_left.hpp"

Player_left::Player_left()
{
    setTexture("assets/left.png");

    setSrc(0, 0, 120, 120);
    setDest(150, 400);
}

void Player_left::update()
{
    Check_keyboard_imput();
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    
    if(attackL1 == 1)
    {
        switch(animate_type)
        {
            case RUN_LEFT:
                animate_idle();
                attackL1 = 1;
                break;

            case IDLE:
                animate_run();
                break;
        }
    }

}

void Player_left::Check_keyboard_imput()
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if(currentKeyStates[SDL_SCANCODE_A])
    {
        animate_type = RUN_LEFT;
        attackL1 = 1;
    }

    if(currentKeyStates[SDL_SCANCODE_B])
    {
        last_direction = animate_type = RUN_RIGHT;
    }
}

void Player_left::animate_idle()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 5;
    src_rect.x = player_idle[current_frame][0];
    src_rect.y = 0;
    dest_rect.w = src_rect.w = player_idle[current_frame][1];
    dest_rect.h = src_rect.h = player_idle[current_frame][2];
}

void Player_left::animate_run()
{
    current_frame = (SDL_GetTicks() * animation_fps / 1000) % 16;

    src_rect.x = player_running[current_frame][0];
    src_rect.y = 0;
    dest_rect.w = src_rect.w = player_running[current_frame][1];
    dest_rect.h = src_rect.h = player_running[current_frame][2];
}

void Player_left::render()
{
    if(attackL1 == 1)
    {
        switch(animate_type)
        {
            case RUN_LEFT:
                SDL_RenderCopyEx(Game::renderer, tex_attacking1, &src_rect, &dest_rect, 0, NULL, SDL_FLIP_HORIZONTAL);
                break;
        }
    }
    else
        SDL_RenderCopy(Game::renderer, objTexture, &src_rect, &dest_rect);
}