/*

FILE DESCRIPTION

This is a test file to test the engine features, and demonstrate a simple use of them.

*/


#include "Window.h"
#include "SimpleErrors.h"
#include "InputManager.h"
#include "Vertex.h"

const int WINDOW_WITDH = 1920; // the window's width
const int WINDOW_HEIGHT = 1200; // the window's height


int main()
{


	if (!glfwInit()) // Initialize glfw and check for errors.
	{
		Debug_Log("glfw failed to init");
	}

	Window m_window; // Create a window.
	m_window.init(WINDOW_WITDH, WINDOW_HEIGHT); // Initialize the window.

	InputManager m_inputManager;
	m_inputManager.init(m_window.getWindowHandler());

	Vertex

	while (!m_window.shouldWindowClose()) // The game loop.
	{
		m_inputManager.update();

		if(m_inputManager.isKeyDown(KEYS::ESC)) // Check if pressed escape.
		{	
			m_window.setWindowClose(); // Close the window if you press the escape button.
		}

		Debug_Log(m_window.getFramesPerSecond()); // Log the fps.

		m_window.update(); // Update the window.
	}


	return 0;
}