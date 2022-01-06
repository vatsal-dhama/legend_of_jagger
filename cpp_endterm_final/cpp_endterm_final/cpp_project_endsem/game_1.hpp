#ifndef game_1hpp
#define game_1hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

class Game_1
{
public:
    Game_1();
    ~Game_1();

    void init(const char* c, int xpos, int ypos, int h, int w, bool fullscreen);

    void update();
    void handleEvents();
    void render();
    void clean();
    bool running();

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // !1
