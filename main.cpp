#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.hpp"
using namespace std;
Game* game = NULL;
int main(int argc, char* argv[])
{
    game = new Game();
        const int FPS = 30;
        const int delay = 1000 / FPS; //time per frame
        unsigned int st;
        unsigned int timeperframe;
        game->init("LOJ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
        while (game->running())
        {
            st = SDL_GetTicks();
            game->handleEvents();
            game->update();
            game->render();
            timeperframe = SDL_GetTicks() - st;
            if (timeperframe < delay)
            {
                SDL_Delay(delay - timeperframe);
            }
        }
        game->clean();
        return 0;
}


