/*Andy Melkonian*/


#include "SDL.h"
#include "SDL_image.h"
//#include <string>

#include "constants.h"
#include "globals.h"

#include "ball.h"
#include "paddle.h"
#include "timer.h"

#include "functions.h"


int main(int argc, char* arg[])	//must use the arguments listed for SDL
{
	bool quit = false;			//quit program flag
	
	Ball playerBall;			//the ball object
	Paddle playerPaddle;		//the paddle object 
	Timer fps;					//Timer for frame rate regulator

	if (init() == false)		//initialize SDL and all subsystem (font, image, etc..)
	{
		return 1;
	}
	
	if (load_files() == false)	//load
	{
		return 1;
	}

	//the actual GAME LOOP
	while (quit == false)		//user did not X out the window
	{
		fps.start();			//start frame timer
		while (SDL_PollEvent(&event))	//whenever an event happens, it is placed on the event queue; SDL_PollEvent starts grabbing events and places it in the event structure created at the top
		{
			playerBall.handle_input();		//handle events for ball
			playerPaddle.handle_input();	//handle events for paddle
				
			if (event.type == SDL_QUIT)	//if the type of event was a quit; when user Xs out windows, the vent type will be SDL_QUIT
			{
				quit = true; //quit the program
			}
		}
		
		//movements	
		playerBall.move();
		playerPaddle.move();
		
		//the actual COLLISION test; If the ball hits paddle
		if (check_collision(playerBall.getBoxB(), playerPaddle.getBoxP()) == true)
		{   
           //Bounce ball back
		//	playerBall.setXvel(1 * playerBall.getXvel());  //crude code; not actual physics but works; research angles from Trigonometry (sine, cosine, tangents..)
			playerBall.setYvel(-1 * playerBall.getYvel());	//works better than above; still not "physics" (need friction, angles, math, etc..)	
		}
		
		text = TTF_RenderText_Solid(font, "Press the SPACE key to randomize the ball", textColor); //the font type, the text message to render, and the color
		apply_surface(0, 0, background, screen);		//background
		apply_surface((SCREEN_WIDTH - text->w) / 2, 0, text, screen);	//blit the text surface; pixels right, pixels down (the origin (0,0) starts in the top left corner unlike the NORMAL coord system; this time it is centered HORIZONTALLY
		playerBall.show();	//show ball on screen
		playerPaddle.show(); //show paddle on screen

		//if the ball goes PAST the paddle
		if (playerBall.getBoxB().y > playerPaddle.getBoxP().y)
        {
			SDL_Color messageColor = {220, 20, 60};	// crimson red
			text = TTF_RenderText_Solid(font, "DO NOT LET THE BALL PASS THE PADDLE!", messageColor);
			if (text!= NULL)
            {
				apply_surface ((SCREEN_WIDTH - text->w) / 2, (SCREEN_HEIGHT - text->h) / 2, text, screen);	//center the message on the screen
				text = NULL;	//point surface to NULL
			}
		}
		
		//update the screen; SHOW IMAGE ON SCREEN
		if(SDL_Flip(screen) == -1)	//even though we have APPLIED the surface, the screen is still BLANK; if error it will return -1
		{
		return 1;
		}
	
		//cap frame rate to 30 fps
		if (fps.get_ticks() < 1000 / FRAMES_PER_SECOND)	//check to see if frame timer is less than FPS time permitted
		{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.get_ticks());	//if it is less, SDL_DELAY() the remaining time
		}
	}	//game loop ends
	
	clean_up();	//prevent memory leaks and quit SDL
	
	return 0;
}