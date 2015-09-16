/*

FILE DESCRIPTION

This is a header file to the FpsCounter class.

Please note that the window class already has an implantation of the FpsCounter class.

*/

#pragma once


class FpsCounter
{
public:
	FpsCounter();
	~FpsCounter();

	void start(); // call start before the game loop.
	double end(); // at the end of every frame call end, it will return how many milliseconds past per frame.

private:
	double m_currentTime, m_lastTime, m_lastMilliPerFrame;
	int m_numFrames = 0;
};
