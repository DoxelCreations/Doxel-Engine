/*

FILE DESCRIPTION

This is a test file to test the engine features, and demonstrate a simple use of them.

*/


#include "Window.h"
#include "SimpleErrors.h"

const int WINDOW_WITDH = 1200; // the window's width
const int WINDOW_HEIGHT = 900; // the window's height


int main()
{

	if (!glfwInit()) // Initialize glfw and check for errors.
	{
		Debug_Log("glfw failed to init");
	}

	Window m_window; // Create a window.
	m_window.init(WINDOW_WITDH, WINDOW_HEIGHT, "Test Window"); // Initialize the window.

	while (!m_window.shouldWindowClose()) // The game loop.
	{
		if (glfwGetKey(m_window.getWindowHandler(), GLFW_KEY_ESCAPE)) // Get input.
		{
			m_window.setWindowClose(); // Close the window if you press the escape button.
		}
		Debug_Log(m_window.getFramesPerSecond()); // Log the fps.

		m_window.update(); // Update the window.
	}


	return 0;
}