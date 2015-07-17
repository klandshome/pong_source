/*Andy Melkonian*/


#include "SDL.h"
#include "globals.h"

//surfaces are declared NULL here
SDL_Surface * background = NULL;
SDL_Surface * text = NULL;
SDL_Surface * ball = NULL;
SDL_Surface * paddle = NULL;
SDL_Surface * screen = NULL;

//event struct
SDL_Event event; 

//font pointed to NULL
TTF_Font * font = NULL;
//The color of the font 
SDL_Color textColor = {255, 255, 255};	//RGB white