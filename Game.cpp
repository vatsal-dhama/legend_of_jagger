#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Player_left.hpp"
#include "Player_right.hpp"
#include "Background.hpp"
#include"Scoreboard.hpp"
using namespace std;

Player_left *player_left;
Player_right *player_right;
Background *B;
Scoreboard *scoreboard;
int player =150;
int ai=150;
int a=0,b=0;
SDL_Renderer *Game::renderer = NULL;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(int xpos, int ypos, int width, int height, bool fullscrean)
{
    // flag for fullscrean
    int flags = 0;
    
    if(fullscrean)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // if everything initialized 
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsystem Initialised!....." << endl;

        window = SDL_CreateWindow("Anshul", 0, 0, width, height, flags);

        if(window)
            cout << "Window Created" << endl;

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if(renderer)
        {   
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
            cout << "Renderer Created!" << endl; 
        }
        if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					
				}

        isRunning = true;
    }

    else
    {
        isRunning = false;
    }

    B = new Background();
    player_left = new Player_left();
    player_right = new Player_right();
    scoreboard = new Scoreboard();
     
}   

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::update()
{
    
    B->update();
    player_left->update();
    a=player_right->updater();
    
    player=player-a;
    scoreboard->loadMedia(player,ai);
    
}

void Game::render()
{   
    B->render();
    player_left->render();
    player_right->renderr();
    scoreboard->loadMedia(player,ai);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
   

    cout << "Game Cleaned" << endl;
}

bool Game::running()
{
    return isRunning;
}