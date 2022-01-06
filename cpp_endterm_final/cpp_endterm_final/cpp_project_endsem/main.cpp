#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game_1.hpp"
#include "Game.hpp"
using namespace std;
Game_1* game_1 = NULL;
int main(int argc, char* argv[])
{
    game_1 = new Game_1();
    
        const int FPS = 30;
        const int delay = 1000 / FPS; //time per frame
        unsigned int st;
        unsigned int timeperframe;
        game_1->init("LOJ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
        while (game_1->running())
        {
            
            st = SDL_GetTicks();
            game_1->handleEvents();
            game_1->update();
            game_1->render();
            timeperframe = SDL_GetTicks() - st;
            if (timeperframe < delay)
            {
                SDL_Delay(delay - timeperframe);
            }
        }
    
        game_1->clean();
    
        return 0;
}

// #include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include "Game.hpp"
// #include <iostream>
// using namespace std;

// Game *game = NULL;

// int main(void)
// {
//     const int fps = 60;
//     const int frame_delay = 1000 / fps;

//     Uint32 frame_start;
//     int frame_time;

//     game = new Game();
//     game->init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false,"assets/dark.png",3);

//     while(game->running())
//     {
//         frame_start = SDL_GetTicks();

//         SDL_RenderClear(Game::renderer);

//         game->handleEvents();
//         game->update();
//         game->render();

//         frame_time = SDL_GetTicks() - frame_start;

//         if(frame_delay > frame_time)
//         {
//             SDL_Delay(frame_delay - frame_time);
//         }
//     }

//     game->clean();

//     return 0;
// }



// sudo apt-get purge --auto-remove libsdl2-dev also for ttf and image
// apt-get install libsdl2-image-dev
// libsdl2-mixer-dev