#pragma once

#include "Game.hpp"
#include "GameObject.hpp"
#include "constants.hpp"
#include "TextureManager.hpp"

enum animation_type
{
    IDLE,
    RUN_RIGHT,
    RUN_LEFT,
    JUMP_IDLE,
    JUMP_LEFT,
    JUMP_RIGHT
};

class Player_left: public GameObject
{
    public:
        Player_left();
        ~Player_left();

        void update();
        void Check_keyboard_imput();
        void animate_idle();
        void animate_run();
        void animate_jump();
        void render();

    private:
        SDL_Texture *tex_attacking1 = NULL;
        SDL_Texture *tex_attacking2 = NULL;

        int last_direction = RUN_RIGHT;
        int last_jump_direction = RUN_RIGHT;
        int jump_frame_count = -1;
        int attackL1 =0;

        int animate_type = -1;
        
        int current_frame = 0;
        int animation_fps = 20;

        int player_running[16][3] = 
        {
            {0, 138, 155},
            {138, 128, 146},
            {266, 119, 148},
            {385, 119, 155},
            {504, 121, 162},
            {625, 124, 157},
            {749, 133, 145},
            {882, 140, 149},
            {1022, 134, 154},
            {1156, 128, 150},
            {1284, 123, 150},
            {1407, 122, 155},
            {1529, 126, 162},
            {1655, 126, 161},
            {1781, 140, 149},
            {1921, 144, 150}
        };

        int player_idle[5][3]
        {
            {0,   98,  155},
            {98,  98,  152},
            {196, 98,  149},
            {294, 100, 143},
            {394, 97,  138}
        };     

        int player_jump[8][3]
        {
            {0, 77, 79},
            {77, 77, 107},
            {154, 82, 109},
            {236, 80, 103},
            {316, 81, 77},
            {397, 76, 98},
            {473, 88, 107},
            {561, 86, 104}
        };
};