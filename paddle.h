/*Andy Melkonian*/


#ifndef PADDLE_H
#define PADDLE_H

class Paddle
{
private:
	SDL_Rect boxP;	//collision box of paddle; remember that SDL_Rect is a struct with a height, width, and x/y coordinates
	int xVel, yVel;	//velocity of paddle
public:
	Paddle();
	void handle_input();	//check key press and change paddle velocity
	void move();			//move paddle
	void show();
	SDL_Rect getBoxP();
	int getXvel();
	int getYvel();
};

#endif