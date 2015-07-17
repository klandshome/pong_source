/*Andy Melkonian*/


#include "SDL.h"
#include "SDL_image.h"
//#include <string>
#include "constants.h"
#include "paddle.h"
#include "functions.h"
#include "globals.h"


Paddle::Paddle()
{
	//initialize the offsets
	boxP.x = (SCREEN_WIDTH - PADDLE_WIDTH) / 2;		//the position where the box starts; CENTER IT
	boxP.y = 650;
	
	//set the dimensions
	boxP.w = PADDLE_WIDTH;
	boxP.h = PADDLE_HEIGHT;

	//initialize the velocity
	xVel = 0;
	yVel = 0;
}

void Paddle::handle_input()
{
	if (event.type == SDL_KEYDOWN)	//if key was pressed
	{
		switch (event.key.keysym.sym)	//adjust velocity
		{
			case SDLK_LEFT : xVel -= PADDLE_WIDTH / 2;
				break;
			case SDLK_RIGHT : xVel += PADDLE_WIDTH / 2;
				break;
		}
	}
	else if (event.type == SDL_KEYUP)	//if key was released
	{
		switch (event.key.keysym.sym)	//adjust velocity
		{
			case SDLK_LEFT : xVel += PADDLE_WIDTH / 2;	//opposite of keydown
				break;
			case SDLK_RIGHT : xVel -= PADDLE_WIDTH / 2;
				break;
		}
	}
}

void Paddle::move()
{
	boxP.x += xVel;	//move paddle left or right
	//if the paddle went too far to the left or right or has collided with the wall
	if ((boxP.x < 0) || (boxP.x + PADDLE_WIDTH > SCREEN_WIDTH))
	{
		//boxP.x = (SCREEN_WIDTH - PADDLE_WIDTH);	//move back
		boxP.x -= xVel;	//not my favourite way becase paddle does not go "all the way" to the wall (figure out better method..)
	}
}

void Paddle::show()
{
	apply_surface(boxP.x, boxP.y, paddle, screen);
}

SDL_Rect Paddle::getBoxP()
{
	return boxP;
}

int Paddle::getXvel()
{
	return xVel;
}
	
int Paddle::getYvel() 
{
	return yVel;
}