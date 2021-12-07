#include "game.hpp"
#include "TexHandler.hpp"
#include "Element.hpp"
#include "movablemap.hpp"

//important variables
Element* playerTex;
movablemap* map1;

Game::Game()
{

}
Game::~Game()
{

}
void Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
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
    
    
    map1 = new movablemap("/Users/vatsal007/Documents/dungeon1.png",renderer,0,0);
    playerTex = new Element("/Users/vatsal007/Documents/chaljaPlease/assets/hero.png",renderer,0,0,map1);
    
}
void Game::update()
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
void Game::handleEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            isRunning = false;
        }
        
    }
//    switch (event.type)
//    {
//        case SDL_QUIT:
//        {isRunning = false;
//            break;}
//        default:
//        {break;}
//    }
//    const Uint8* state = SDL_GetKeyboardState(NULL);
//    if(state[SDL_SCANCODE_UP]){
//        cout<<"up"<<endl;
//    }
//    else if (state[SDL_SCANCODE_DOWN]){
//        cout<<"down"<<endl;
//    }
    
}
void Game::render()
{
    //clear the renderer stuff from before
    SDL_RenderClear(renderer);
    //print the contents of the updated backbuffer once a frame
    map1->Render();
    playerTex->Render();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
bool Game::running()
{
    return isRunning;
}

