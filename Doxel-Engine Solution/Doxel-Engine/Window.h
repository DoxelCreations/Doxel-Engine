#pragma once
#include <GLFW\glfw3.h>
#include "FpsCounter.h"


#define DEFAULT_TITLE "Doxel Engine"
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600


class Window
{
public:
Window(); ///<  empty.
~Window(); ///< empty.

bool init(int width , int height , char* title = DEFAULT_TITLE); // Init the window, will return true if successful.
bool isInitialized() { return m_window != nullptr; }

void destroy(); ///< Destroy the window.

void update(); ///< to be called at the end of every frame.

void setWindowClose(); // call it when you want to make the window close.
bool shouldWindowClose(); // can be used as the boolean for the game loop.

double getTimePerFrame() { return m_currentTimePerFrame; } // returns avarage time for each frame in the last second.
double getFramesPerSecond() { return 1000.0 / m_currentTimePerFrame; } // returns number of frames for the last second.

GLFWwindow* getWindowHandler() { return m_window; }

private:
FpsCounter m_fpsCounter;
GLFWwindow* m_window = nullptr;
int m_width, m_height;
char* m_title;
double m_currentTimePerFrame;



};
