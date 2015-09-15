/*

FILE DESCRIPTION

This is a C++ code file counting FPS.

*/

#include "FpsCounter.h"
#include "SimpleErrors.h"
#include <GLFW\glfw3.h>


FpsCounter::FpsCounter()
{
	// Empty
}

FpsCounter::~FpsCounter()
{
	// Empty
}
/*

This function start the fps counter.
should be called when you want to start tracking the fps

*/
void FpsCounter::start()
{
	m_lastTime = glfwGetTime();
}
/*

This function check the current fps and returns it.

Output:
	- double - returns how much time it took each frame to render in avrage in the last second.

*/
double FpsCounter::end()
{
	m_currentTime = glfwGetTime();
	m_numFrames++;

	if (m_currentTime - m_lastTime >= 1.0)
	{
		double MsPerFrame = 1000.0 / (double)m_numFrames; // milliseconds per seconds / number of frame per second = milliseconds per frame
		m_lastMilliPerFrame = MsPerFrame;
		m_numFrames = 0;
		m_lastTime = glfwGetTime();
		
	}
	return m_lastMilliPerFrame;
}
