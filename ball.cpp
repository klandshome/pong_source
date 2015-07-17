/*Andy Melkonian*/


#include "SDL.h"
#include "SDL_image.h"
//#include <string>
#include "constants.h"
#include "ball.h"
#include "functions.h"
#include "globals.h"


Ball::Ball()
{
	//initialize the offsets
	boxB.x = (SCREEN_WIDTH - BALL_WIDTH) / 2;		//the position where the ball starts
	boxB.y = 30;
	
	//set the dimensions
	boxB.w = BALL_WIDTH;
	boxB.h = BALL_HEIGHT;

	//initialize the velocity
	xVel = 0;
	yVel = 0;
}

void Ball::handle_input()
{
	int leftRight; //ball left or right
  
    if (event.type == SDL_KEYDOWN)	//if key pressed
    {
        if (event.key.keysym.sym == SDLK_SPACE)		//give random velocity if space key pressed
        {
            leftRight = rand() % 2;
            if (leftRight == 0)
			{            
                xVel = rand() % 10 + 15;
                yVel = rand() % 20;
            }
            if (leftRight == 1)
			{
                xVel = (rand() % 10 + 15 * -1);
                yVel = (rand() % 20) * -1;
            }                
        }
    }
}

void Ball::move()
{
    //Move the ball left or right
    boxB.x += xVel; //left or right movement
    
    //Move the ball up or down
    boxB.y += yVel;	//up or down movement
    
    if ((boxB.x < 0) || (boxB.x + BALL_WIDTH > SCREEN_WIDTH)) //if ball went too far left or right, then BOUNCE off the walls
    {
		xVel = -1 * xVel;  //bounce back; negative velocity goes back basically..
    }
	if ((boxB.y < 0) || (boxB.y + BALL_HEIGHT > SCREEN_HEIGHT))//if ball went too far up or down, then BOUNCE off the walls 
    {
        yVel = -1 * yVel;	//bounce back
    }


}

void Ball::show()
{
	apply_surface(boxB.x, boxB.y, ball, screen);
}

/*
void Ball::reset()
{
	//initialize the offsets
	boxB.x = (SCREEN_WIDTH - BALL_WIDTH) / 2;		//the position where the ball starts
	boxB.y = 30;
	
	//set the dimensions
	boxB.w = BALL_WIDTH;
	boxB.h = BALL_HEIGHT;

	//initialize the velocity
	xVel = 0;
	yVel = 0;
}
*/

SDL_Rect Ball::getBoxB()
{
	return boxB;
}

int Ball::getXvel()
{
	return xVel;
}
	
int Ball::getYvel()
{
	return yVel;
}

void Ball::setXvel(const int & xV)
{
	xVel = xV;
}

void Ball::setYvel(const int & yV)
{
	yVel = yV;
}