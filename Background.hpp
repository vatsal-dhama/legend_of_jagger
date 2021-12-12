#pragma once

#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "constants.hpp"
#include <vector>

class Background: public GameObject
{
    public:

        Background();
        ~Background();

        void update();
        void render();
        void animate();

    private:
        SDL_Texture *Animating_B = NULL;
        SDL_Surface *tempSurface = NULL;
        SDL_Texture *tex = NULL;

        int current_frame = 0;
        int animation_fps = 10;

        int background[4][3] = 
        {
            {0, 1000, 400},
            {1000, 1000, 400},
            {2000, 1000, 400},
            {3000, 1000, 400}
        };
 
};