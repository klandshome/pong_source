/*Andy Melkonian*/


#ifndef BALL_H
#define BALL_H

class Ball
{
private:
	SDL_Rect boxB;	//collision box of ball; remember that SDL_Rect is a struct with a height, width, and x/y coordinates
	int xVel, yVel;	//velocity of ball
public:
	Ball();
	void handle_input();	//check key press and change ball velocity
	void move();			//move ball
	void show();
//	void reset();			//reset the ball
	SDL_Rect getBoxB();
	int getXvel();
	int getYvel();
	void setXvel(const int & xV);
	void setYvel(const int & yV);
};

#endif