#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include"Game.hpp"


class Scoreboard
{
	public:
		//Initializes variables
		Scoreboard();
		//Deallocates memory
		~Scoreboard();

		
		bool loadMedia(int s1,int s2);
		
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor,TTF_Font *font );

		//Deallocates texture
		void free();
		
		//Renders texture at given point
		void render( int x, int y, int s,SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
		void render1( int x, int y,int s1, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
		
		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

	TTF_Font *gFont = TTF_OpenFont( "assets/hii.otf", 44);;
    TTF_Font *gFont1 = TTF_OpenFont("assets/hii.otf",44);
		//Image dimensions
		int mWidth;
		int mHeight;
};