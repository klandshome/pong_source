/*Andy Melkonian*/


#ifndef GLOBALS_H
#define GLOBALS_H

//header
#include "SDL.h"
#include "SDL_ttf.h"

//surfaces
extern SDL_Surface * background;	//not assigned until used (utilize my implementation in other file)
extern SDL_Surface * text;
extern SDL_Surface * ball;			//extern means that the variable is existing in my code (in this case in the .cpp file); prevents multiple copies of same var and so that the comiler does not throw error
extern SDL_Surface * paddle;
extern SDL_Surface * screen;

//event struct
extern SDL_Event event; //stores all the different events that will be handled; it is a structure data type

//font pointer
extern TTF_Font * font;
//font color
extern SDL_Color textColor;

#endif