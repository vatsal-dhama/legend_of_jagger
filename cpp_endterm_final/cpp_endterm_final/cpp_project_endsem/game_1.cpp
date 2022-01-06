#ifndef game_1tag
#define game_1tag
#include "game_1.hpp"
#include "TexHandler.hpp"
#include "Element.hpp"
#include "movablemap.hpp"
#include<SDL2/SDL_mixer.h>
//important variables
Element* playerTex;
movablemap* map1;

Game_1::Game_1()
{

}
Game_1::~Game_1()
{

}
void Game_1::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flag = 0; //unless the bool is true then it is not fullscreen
    if (fullscreen)
    {
        flag = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Error: " << Mix_GetError() << std::endl;
    }
    Mix_Music* bgm = Mix_LoadMUS("assets/player.mp3");
    Mix_PlayMusic(bgm, -1);
    
    
    map1 = new movablemap("assets/world_map.png",renderer,0,0);
    playerTex = new Element("assets/hero.png",renderer,0,0,map1);
    
}
void Game_1::update()
{
   
    playerTex->Update("");
    map1->Update("");
    
        
        const Uint8* state = SDL_GetKeyboardState(NULL);
       if(state[SDL_SCANCODE_UP]){
           playerTex->Update("up");
           map1->Update("up");
       }
       else if (state[SDL_SCANCODE_DOWN]){
           playerTex->Update("down");
           map1->Update("down");
       }
       else if (state[SDL_SCANCODE_RIGHT]){
           playerTex->Update("right");
           map1->Update("right");
       }
       else if (state[SDL_SCANCODE_LEFT]){
           playerTex->Update("left");
           map1->Update("left");
       }
    
}
void Game_1::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        
    }
    
}
void Game_1::render()
{
    //clear the renderer stuff from before
    SDL_RenderClear(renderer);
    //print the contents of the updated backbuffer once a frame
    map1->Render();
    playerTex->Render();
    SDL_RenderPresent(renderer);
}
void Game_1::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
bool Game_1::running()
{
    return isRunning;
}

#endif