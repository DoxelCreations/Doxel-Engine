/*

FILE DESCRIPTION

This is the Window class header.

The Window class is a simple wraper for most of the GLFW libary calls.

*/

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

bool init(int width , int height , char* title = DEFAULT_TITLE); // Initlialize the window, will return true if successful. If no title is given at function call, it will use the DEFAULT_TITLE, "Doxel Engine".
bool isInitialized() { return m_window != nullptr; } // Checks if the GLFWwindow is already initlialized.

void destroy(); ///< Destroy the window.

void update(); ///< To be called at the end of every frame.

/// Setters
void setWindowClose(); // Call it when you want to make the window close.
bool shouldWindowClose(); // Can be used as the boolean for the game loop.

/// Getters
double getTimePerFrame() { return m_currentTimePerFrame; } // Returns avarage time for each frame in the last second.
double getFramesPerSecond() { return 1000.0 / m_currentTimePerFrame; } // Returns number of frames for the last second.
GLFWwindow* getWindowHandler() { return m_window; } // Returns a GLFWwindow pointer.


private:
FpsCounter m_fpsCounter;
GLFWwindow* m_window = nullptr;
int m_width = 0, m_height = 0;
char* m_title;
double m_currentTimePerFrame = 0;



};
