/*Andy Melkonian*/


#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "SDL.h"
#include "SDL_image.h"
#include <string>

//SURFACE LOADING AND BLITTING FUNCTIONS
SDL_Surface * load_image(std::string filename); 

void apply_surface(int x, int y, SDL_Surface * source, SDL_Surface * destination, SDL_Rect * clip = NULL);	

bool check_collision(SDL_Rect A, SDL_Rect B);	//collision checking

bool init();	

bool load_files();

void clean_up();


#endif