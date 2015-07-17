/*Andy Melkonian*/


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
//#include <string>
#include "constants.h"
#include "functions.h"
#include "globals.h"



//SURFACE LOADING AND BLITTING FUNCTIONS
SDL_Surface * load_image(std::string filename)  //loads image and returns ptr to optimized version of loaded image
{
	SDL_Surface * loadedImage = NULL;	//temp storage for image that's loaded
	SDL_Surface * optimizedImage = NULL;//Optimized image to be used

	loadedImage = IMG_Load(filename.c_str()); //c_str gets C string equivalent; returned as a pointer to an array of characters
	if (loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormat(loadedImage); 
		SDL_FreeSurface(loadedImage);

		if (optimizedImage != NULL)
		{
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB(optimizedImage->format, 0xFF, 0xFF, 0xFF));//1st arg is surface to set color key to, 2nd puts flags (makes sure to use color key when blitting), 3rd is the color to use
			/*OR  Map the color key like this below (same functionality as above)
			Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF );		//removes white around images (make white around the ball transparent); 0xFF, 0xFF, 0xFF is RGB pixel value for color white
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );*/
		}
	}
	return optimizedImage;
}

//surface blitting function; About BLITTING: When you blit, you copy the pixels from one surface onto another.
void apply_surface(int x, int y, SDL_Surface * source, SDL_Surface * destination, SDL_Rect * clip)	//coordinates of where you want to blit surface, the surface (source) you are blitting, AND the surface blitting to (destination)
{	
	//make temp rectangle to hold offsets
	SDL_Rect offset;	//SDL_rect is a data type that represents a rectangle
	//give offests to rectangle
	offset.x = x;
	offset.y = y;	

	//begin the blitting
	SDL_BlitSurface(source, clip, destination, &offset);//1st is surface using (source), 3rd is surface blit to (destination), 4th holds offests to where on destination the source is going to be applied 
}

bool check_collision(SDL_Rect A, SDL_Rect B)	//collision checking
{
	//sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//calculate sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//calculate side of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	if (bottomA <= topB)	//if any of the sides from A are outside of B
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}

	return true;	//if none of the sides from A are outside B
}

bool init()	
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)	//function to initialize ALL SDL subsystems
	{
		return false;
	}

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);//set up screen; the 4th arg creates screen surface in system memory
	if (screen == NULL)
	{
		return false;
	}

	if (TTF_Init() == -1) //Initialize SDL_ttf for true type fonts
	{ 
		return false; 
	}

	SDL_WM_SetCaption("Pong", NULL);

	return true; //if everything initialized fine
}

bool load_files()
{
	background = load_image("galaxy.png");
	if (background == NULL)					//if problem loading
	{
		return false;
	}
	font = TTF_OpenFont( "Action_Man_Bold.ttf", 28 );	//Open the font
	if (font == NULL) 
	{ 
		return false; 
	}
	ball = load_image("ball.png");
	if (ball == NULL)	
	{
		return false;
	}
	paddle = load_image("paddle.png");
	if (paddle == NULL)	
	{
		return false;
	}

	return true;	
}

void clean_up()
{
	SDL_FreeSurface(background);
	SDL_FreeSurface(text);
	SDL_FreeSurface(ball);
    SDL_FreeSurface(paddle);
	
	TTF_CloseFont(font); //open font must be closed after done

	TTF_Quit();		//quit SDL_ttf
	SDL_Quit();	
}