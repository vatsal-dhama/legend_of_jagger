#pragma once 

#include "constants.hpp"
//#include <bits/stdc++.h>
using namespace std;

class Game
{
    public:
        Game();
        ~Game();

        void init(int, int, int, int, bool, const char *,int );
        
        void handleEvents();
        void update();
        bool running();
        void render();
        void clean();

        static SDL_Renderer *renderer;

        SDL_Window *getWindow() { return window; }

    private:
        int count = 0 ;
        bool isRunning;
        SDL_Window *window;
};
