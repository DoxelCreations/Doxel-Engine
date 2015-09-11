#include "Window.h"
#include "SimpleErrors.h"
Window::Window()
{
	//  empty
}
Window::~Window()
{
	// empty
}

bool Window::init(int width, int height, char* title /* = default*/)
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

void Window::destroy()
{
	glfwDestroyWindow(m_window);
	Debug_Log("Window " << m_title << " has been destoryed.");
	glfwTerminate(); ///< if there is more then 1 window, remove this line but make sure you terminate glfw somewhere else.
}


void Window::update()
{
	m_currentTimePerFrame = m_fpsCounter.end();
	glfwSwapBuffers(m_window); ///< swap the buffers for the next frame
	glfwPollEvents(); ///< poll current events for the input manager
}

void Window::setWindowClose()
{
	glfwSetWindowShouldClose(m_window, GL_TRUE);
	Debug_Log("Window is set to close.");
}

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