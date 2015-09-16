/*

FILE DESCRIPTION

This is the Window class header.

The Window class is a simple wraper for most of the GLFW libary calls.

*/

#pragma once
#include <GLFW\glfw3.h>
#include "FpsCounter.h"


#define DEFAULT_TITLE "Doxel Engine" ///< default title for the window.
#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600



class Window
{
public:
Window(); ///<  empty.
~Window(); ///< empty.

bool init(int width , int height , char* title = DEFAULT_TITLE); ///< Initlialize the window, will return true if successful. If no title is given at function call, it will use the DEFAULT_TITLE, "Doxel Engine".
bool isInitialized() { return m_window != nullptr; } ///< Checks if the GLFWwindow is already initlialized.

void destroy(); ///< Destroy the window.

void update(); ///< To be called at the end of every frame.

/// Setters
void setWindowClose();///< Call it when you want to make the window close.
bool shouldWindowClose(); ///< Can be used as the boolean for the game loop.

/// Getters
/*
returns the time it took each frame to render
*/
double getTimePerFrame() { return m_currentTimePerFrame; }
/*
returns the fps.
*/
double getFramesPerSecond() { return 1000.0 / m_currentTimePerFrame; } 
/*
returns the window title as a char*.
 */
char* getTitle() { return m_title; }
/*
returns the GLFWwindow pointer
*/
GLFWwindow* getWindowHandler() { return m_window; } 


private:
FpsCounter m_fpsCounter;
GLFWwindow* m_window = nullptr;
int m_width = 0, m_height = 0;
char* m_title;
double m_currentTimePerFrame = 0;



};
