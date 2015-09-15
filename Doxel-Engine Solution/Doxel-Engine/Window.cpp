/* 

FILE DESCRIPTION

This is the Window class c++ implantation.

*/

#include "Window.h"
#include "SimpleErrors.h"


Window::Window()
{
	//  Empty
}

Window::~Window()
{
	// Empty
}
/*

This function initialize the window.

Input:
	- int width - the width of the wanted window.
	- int height - the height of the wanted window.
	- char* title - the title of the wanted window, the default value is "Doxel Engine".	
	
Output:
	- bool - will return true when the window was created, otherwise will return false.

*/


bool Window::init(int width, int height, char* title /* =  DEFAULT_TITLE*/)
{
	if (isInitialized())
	{
		Debug_Log("Window is already initialized.");
		return false;
	}

	m_width = width;
	m_height = height;
	m_title = title;

	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

	if (isInitialized())
	{
		glfwMakeContextCurrent(m_window); ///< set the current window to have context
		Debug_Log("Window " << m_title << " has been initialized.");
		m_fpsCounter.start();
		return true;
	}

	else
	{
		Debug_Log("Window " << m_title << " has failed to initialize.");
		glfwTerminate();
		return false;
	}

	
}
/*

This function destroys the window.
Should be called when the window is no longer needed.

*/
void Window::destroy()
{
	glfwDestroyWindow(m_window);
	Debug_Log("Window " << m_title << " has been destoryed.");
	glfwTerminate(); ///< if there is more then 1 window, remove this line but make sure you terminate glfw somewhere else.
}

/*

This function updates the window.
Should be called at the end of every game loop cycle.

*/
void Window::update()
{
	m_currentTimePerFrame = m_fpsCounter.end(); ///< set tpf to its value.
	glfwSwapBuffers(m_window); ///< swap the buffers for the next frame
	glfwPollEvents(); ///< poll current events for the input manager
}
/*

This function set the window to close.
Should be called when you want to close the window.

*/
void Window::setWindowClose()
{
	glfwSetWindowShouldClose(m_window, GL_TRUE); ///< set the Window state to should close.
	Debug_Log("Window is set to close.");
}
/*

This function checks if the window needs to close.

Output:
	- bool - will return true if the window should close, otherwise will return false.

*/
bool Window::shouldWindowClose()
{
	if (glfwWindowShouldClose(m_window))
	{
		return true;
	}
	else
	{
		return false;
	}
}