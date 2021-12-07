#ifndef gamehpp
#define gamehpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

class Game
{
public:
    Game();
    ~Game();

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
