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
	/*

	This function start the fps counter.
	should be called when you want to start tracking the fps

	*/
	void start(); 
	/*

	This function check the current fps and returns it.

	Output:
	- double - returns how much time it took each frame to render in avrage in the last second.

	*/
	double end(); 

private:
	double m_currentTime, m_lastTime, m_lastMilliPerFrame;
	int m_numFrames = 0;
};
