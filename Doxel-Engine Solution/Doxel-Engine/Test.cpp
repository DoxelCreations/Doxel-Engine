#include "Window.h"
#include "SimpleErrors.h"

const int WINDOW_WITDH = 1200;
const int WINDOW_HEIGHT = 900;


int main()
{

	if (!glfwInit())
	{
		Debug_Log("glfw failed to init");
	}

	Window m_window;
	m_window.init(WINDOW_WITDH, WINDOW_HEIGHT, "Test Window");

	while (!m_window.shouldWindowClose())
	{
		if (glfwGetKey(m_window.getWindowHandler(), GLFW_KEY_ESCAPE))
		{
			m_window.setWindowClose();
		}
		Debug_Log(m_window.getFramesPerSecond());

		m_window.update();
	}


	return 0;
}