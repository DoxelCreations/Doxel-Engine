#pragma once

#include <unordered_map>
#include <glm\vec2.hpp>
#include <GLFW\glfw3.h>
#include "Window.h"

enum KEYS
{
	A, B, C, D, E, F, f, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, NUM_5, NUM_6, NUM_7, NUM_8, NUM_9,
	ESC, TAB, LFET_SHIFT, LEFT_COTROL, LEFT_ALT, SPACE, RIGHT_ALT, RIGHT_CONTROL, RIGHT_SHIFT, ENTER, BACKSPACE,
	UP, DOWN, LEFT, RIGHT,
	F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
	MOUSE_RIGHT, MOUSE_MIDDLE, MOUSE_LEFT
};

class InputManager
{
public:
	InputManager();
	~InputManager();

	/*

	This function initialize the input manager.

	Input:
	- GLFWwindow *window - a pointer to the GLFWwindow you want to read input from.

	*/
	void init(GLFWwindow *window);
	/*

	This function updates the input manager.
	Should be called at the beginning of every game loop cycle.
	*/
	void update();
	/*

	This function change the state of a specific key to pressed.

	Input:
	- unsinged int keyID - the id of the key you want to press. Should use the enum KEYS
	*/
	void pressKey(unsigned int keyID);
	/*

	This function change the state of a specific key to relesed.

	Input:
	- unsinged int keyID - the id of the key you want to relese. Should use the enum KEYS

	*/
	void releaseKey(unsigned int keyID);
	/*

	This function checks if the state of a specific key is pressed this frame and not the last one.

	Input:
	- unsinged int keyID - the id of the key you want to check. Should use the enum KEYS

	Output:
	- bool - returns true if the key is pressed now and not before. returns false if not.

	*/
	bool isKeyPressed(unsigned int keyID);
	/*

	This function checks if the state of a specific key is pressed this frame and the last one.

	Input:
	- unsinged int keyID - the id of the key you want to check. Should use the enum KEYS

	Output:
	- bool - returns true if the key is pressed now and was before. returns false if not.

	*/
	bool isKeyHeldDown(unsigned int keyID);


	//getters
	/*
	returns the current position of the mouse
	*/
	glm::vec2 getCurrentMouseCoords() const { return m_currentMouseCoords; }
	/*
	returns the last frame position of the mouse
	*/
	glm::vec2 getlastMouseCoords() const { return m_lastMouseCoords; }



private:
	/*

	This function checks if the state of a specific key is pressed this frame.

	Input:
	- unsinged int keyID - the id of the key you want to check. Should use the enum KEYS

	Output:
	- bool - returns true if the key is pressed now. returns false if not.

	*/
	bool isKeyDown(unsigned int keyID);
	/*

	This function checks  the state of a specific key in the last frame.

	Input:
	- unsinged int keyID - the id of the key you want to check. Should use the enum KEYS

	Output:
	- bool - returns true if the key was pressed last frame. returns false if not.

	*/
	bool wasKeyDown(unsigned int keyID);
	/*

	This function update the keys state.

	*/
	void updateKeys();
	/*

	This function update the mouse position.

	*/
	void updateMouse();
	
	std::unordered_map<unsigned int, bool> m_keyMap;
	std::unordered_map<unsigned int, bool> m_previousKeyMap;

	glm::vec2 m_currentMouseCoords;
	glm::vec2 m_lastMouseCoords;
	GLFWwindow* m_window;

};
