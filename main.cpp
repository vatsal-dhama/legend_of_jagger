#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include "Game.hpp"
#include <iostream>

using namespace std;

Game *game = NULL;

int main(int argc, char* args[])
{
    
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048) < 0)
    {
        std::cout << "Error: " << Mix_GetError() << std::endl;
    }
    Mix_Music* bgm = Mix_LoadMUS("C:\\IIITB\\Second year- first sem\\Cpp\\Project\\Rahul and anshul\\assets\\boss1.mp3");
    
    const int fps = 60;
    const int frame_delay = 1000 / fps;

    Uint32 frame_start;
    int frame_time;

    game = new Game();
    game->init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);
    Mix_PlayMusic(bgm, -1);
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
    Mix_FreeMusic(bgm);
    bgm = nullptr;
    

    return 0;
}