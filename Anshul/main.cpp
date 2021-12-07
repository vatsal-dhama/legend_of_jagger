#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"
#include <iostream>
using namespace std;

Game *game = NULL;

int main(void)
{
    const int fps = 60;
    const int frame_delay = 1000 / fps;

    Uint32 frame_start;
    int frame_time;

    game = new Game();
    game->init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

    while(game->running())
    {
        frame_start = SDL_GetTicks();

        SDL_RenderClear(Game::renderer);        

        game->handleEvents();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;

        if(frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    game->clean();

    return 0;
}