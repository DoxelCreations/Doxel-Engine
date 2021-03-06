/*

FILE DESCRIPTION

This is a test file to test the engine features, and demonstrate a simple use of them.

Note: Always include gl/glew before glfw/glfw3 for forward declaration magic that happends in gl/glew.
that means that Vertex.h should be included before Window.h.

*/

#include <cstddef>
#include <glm\gtc\type_ptr.hpp>

#include "Vertex.h" 
#include "Window.h"
#include "SimpleErrors.h"
#include "InputManager.h"
#include "GLProgram.h"

const int WINDOW_WITDH = 1200; // the window's width
const int WINDOW_HEIGHT = 900; // the window's height

int main()
{
	if (!glfwInit()) // Initialize glfw and check for errors.
	{
		Debug_Log("glfw failed to init");
	}

	Window m_window; // Create a window.
	if (m_window.init(WINDOW_WITDH, WINDOW_HEIGHT)) // Initialize the window.
	{
		Debug_Log(m_window.getTitle() << " window has been initiated");
	}

	if (glewInit()) // Initialize glew and check for errors, please note that you must init glew after creating a window and initializing it, and before using any gl calls.
	{
		Debug_Log("glew failed to init");
	}

	InputManager m_inputManager; // Create an input manager object
	m_inputManager.init(m_window.getWindowHandler()); // Init it

	GLProgram m_program;// Create a GLProgram object for debug purposes
	m_program.loadShaders("Shaders/Shader.vert", "Shaders/Shader.frag"); // test if the shaders compile

	GLuint m_vao; /// this is the vertex array object, unimportant for now, and the program can run without it.
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	Vertex2D verts[6];
	verts[0].setPosition(0.0f, 1.0f);
	verts[0].setColor(Color8(255, 255, 0));
	verts[1].setPosition(1.0f, 0.0f);
	verts[1].setColor(Color8(255, 0, 255));
	verts[2].setPosition(0.0f, 0.0f);
	verts[2].setColor(Color8(0, 255, 0));
	verts[3].setPosition(1.0f, 0.0f);
	verts[3].setColor(Color8(0, 0, 255));
	verts[4].setPosition(1.0f, 1.0f);
	verts[4].setColor(Color8(0, 255, 255));
	verts[5].setPosition(0.0f, 1.0f);
	verts[5].setColor(Color8(255, 0, 0));

	
	Debug_Log("size of vertecies" << sizeof(verts));
	Debug_Log(sizeof(Vertex3D));


	GLuint m_vbo; ///< this is the vertex buffer object.
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

	/*

	VERTEX:1
		POSITION - 1 
		COLOR - 1
		TEXTURE-COORD -1 
	VERTEX:2
		POSITION-1
		COLOR-1
		TEXTURE-COORD-1
	
	*/

	//glUseProgram(m_program.getID()); 
	m_program.addAttribute("vertexPos", 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (void*)offsetof(Vertex2D,position));
	m_program.addAttribute("vertexColor", 3, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex2D), (void*)offsetof(Vertex2D, color));

	glm::mat4 projection; /*= glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);*/
	glm::mat4 view; /*glm::lookAt(glm::vec3(0.0, -5.0, 0.0), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 0.0, 1.0));*/
	glm::mat4 model;/* = glm::mat4(1.0f);*/
	glm::mat4 MVP = projection * view * model;
	GLint mvpLocation = glGetUniformLocation(m_program.getID(), "MVP");
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(MVP));

	while (!m_window.shouldWindowClose()) // The game loop.
	{
		m_inputManager.update();

		if(m_inputManager.isKeyPressed(KEYS::ESC)) // Check if pressed escape.
		{	
			m_window.setWindowClose(); // Close the window if you press the escape button.
		}
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // set the background color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		m_program.use();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		m_program.unuse();

		m_window.update(); // Update the window.
	}
	glDeleteBuffers(1, &m_vbo);
	glDeleteVertexArrays(1, &m_vao);
	m_program.deleteProgram();
	m_window.destroy();
	return 0;
}
