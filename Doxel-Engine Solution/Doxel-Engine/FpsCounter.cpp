#include "FpsCounter.h"
#include "SimpleErrors.h"
#include <GLFW\glfw3.h>


FpsCounter::FpsCounter()
{

}

FpsCounter::~FpsCounter()
{

}
void FpsCounter::start()
{
	m_lastTime = glfwGetTime();
}

double FpsCounter::end()
{
	m_currentTime = glfwGetTime();
	m_numFrames++;

	if (m_currentTime - m_lastTime >= 1.0)
	{
		double MsPerFrame = 1000.0 / (double)m_numFrames;
		m_lastMilliPerFrame = MsPerFrame;
		m_numFrames = 0;
		m_lastTime = glfwGetTime();
		
	}
	return m_lastMilliPerFrame;
}
