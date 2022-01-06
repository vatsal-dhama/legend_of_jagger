#pragma once

#include "Game.hpp"
#include "GameObject.hpp"
#include "constants.hpp"
#include "TextureManager.hpp"

class Player_right: public GameObject
{
    public:
        Player_right();
        ~Player_right();

        int updater();
        void Get_keyboard_inputs();
        void animate_1();
        void animate_2();

        void renderr();

    private:
        SDL_Texture *tex_attacking1 = NULL;
        SDL_Texture *tex_attacking2 = NULL;

        int jump_frame_count1 = -1;
        int jump_frame_count2 = -1;
        
        int attack = 0;

        int animate_type = -1;
        
        int current_frame = 0;
        int animation_fps = 10;


        int player[3][3]
        {
            {0,   30,  30},
            {30,  30,  30},
            {60, 30,  30}
        };     


};