#pragma once

#include "Game.hpp"
#include "GameObject.hpp"
#include "constants.hpp"
#include "TextureManager.hpp"


class Player_left: public GameObject
{
    public:
        Player_left(const char *texture,int segment);
        ~Player_left();

        int update(int );
        
        void animate();
        
        void render();

    private:
        SDL_Texture *tex_attackingl1 = NULL;

        int jump_frame_count = -1;
        int attackL1 =0;

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