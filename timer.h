/*Andy Melkonian*/


#ifndef TIMER_H
#define TIMER_H

class Timer
{
private:
	int startTicks;	//the clock time when the timer started
	int pausedTicks;	//the ticks stored when timer was paused
	//timer status
	bool paused;
	bool started;
public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	int get_ticks(); //get timer's times
	//checks the status of timer
	bool is_started();
	bool is_paused();
};

#endif