
#include"Scoreboard.hpp"


Scoreboard gTextTexture;
Scoreboard bTexture;
Scoreboard recTexture;
Scoreboard head1;
Scoreboard head2;

void close();
Scoreboard::Scoreboard()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Scoreboard::~Scoreboard()
{
	//Deallocate
	free();
}



bool Scoreboard::loadFromRenderedText( std::string textureText, SDL_Color textColor,TTF_Font *font)
{
	//Get rid of preexisting texture
	free();

	//Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
	if( textSurface == NULL )
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( Game::renderer, textSurface );
		if( mTexture == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}
		

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	
	//Return success
	return mTexture != NULL;
}

void Scoreboard::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Scoreboard::render( int x, int y, int s,SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( Game::renderer, mTexture, clip, &renderQuad, angle, center, flip );
	

    SDL_Rect rect;
    rect.x = 10;
    rect.y = 50;
    rect.w = 150;
    rect.h = 50;

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &rect);

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

   
	SDL_Rect rect1;
    rect1.x = 10;
    rect1.y = 50;
    rect1.w = s;
    rect1.h = 50;

    SDL_SetRenderDrawColor(Game::renderer, 0, 255,0, 255);
    SDL_RenderFillRect(Game::renderer, &rect1);

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	SDL_Rect rect2;
    rect2.x = 10+s;
    rect2.y = 50;
    rect2.w = 160-(10+s);
    rect2.h = 50;

    SDL_SetRenderDrawColor(Game::renderer, 255, 0,0, 255);
    SDL_RenderFillRect(Game::renderer, &rect2);

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

    
}
void Scoreboard::render1( int x, int y, int s1,SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( Game::renderer, mTexture, clip, &renderQuad, angle, center, flip );
	
    if(y<100){
    SDL_Rect rect;
    rect.x = 1055;
    rect.y = 50;
    rect.w = 150;
    rect.h = 50;

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(Game::renderer, &rect);

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

   
	SDL_Rect rect1;
    rect1.x = 1055;
    rect1.y = 50;
    rect1.w = s1;
    rect1.h = 50;

    SDL_SetRenderDrawColor(Game::renderer, 0, 255,0, 255);
    SDL_RenderFillRect(Game::renderer, &rect1);

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	SDL_Rect rect2;
    rect2.x = 1055+s1;
    rect2.y = 50;
    rect2.w = 1205-(1055+s1);
    rect2.h = 50;

    SDL_SetRenderDrawColor(Game::renderer, 255, 0,0, 255);
    SDL_RenderFillRect(Game::renderer, &rect2);

    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
	}
	

    //SDL_RenderPresent(Game::renderer);
}

int Scoreboard::getWidth()
{
	return mWidth;
}

int Scoreboard::getHeight()
{
	return mHeight;
}


bool Scoreboard::loadMedia(int s1,int s2)
{
	//Loading success flag
	bool success = true;
	//Open the font
	if( gFont == NULL || gFont1 == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 0, 0, 255 };
		SDL_Color textColor1 = { 210,150,30 };
		SDL_Color textColor2 ={255,0,0};
		if( !gTextTexture.loadFromRenderedText( "Enemy ", textColor,gFont ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
		if( !bTexture.loadFromRenderedText( "Hero ", textColor1,gFont1 ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
		if( !head1.loadFromRenderedText( "press 1 for light attack", textColor2,gFont1 )){
			printf( "Failed to render text texture!\n" );
			success = false;

		}
		if( !head2.loadFromRenderedText( "press 2 for heavy attack", textColor2,gFont1 )){
			printf( "Failed to render text texture!\n" );
			success = false;

		}
		
		gTextTexture.render(0,0,s1);
		bTexture.render1(1055,0,s2);
		head1.render1(800,150,0);
		head2.render1(800,200,0);
		//SDL_RenderPresent( Game::renderer );
	}

	return success;
}

void close()
{
	//Free loaded images
	gTextTexture.free();
	bTexture.free();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

