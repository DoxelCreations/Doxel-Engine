/*

FILE DESCRIPTION

This is a test file to test the engine features, and demonstrate a simple use of them.

Note: Always include gl/glew before glfw/glfw3 for forward declaration magic that happends in gl/glew.
that means that Vertex.h should be included before Window.h.

*/

#include "Vertex.h" 
#include "Window.h"
#include "SimpleErrors.h"
#include "InputManager.h"
#include "GLProgram.h"
#include "Camera3D.h"
#include <cstddef>

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

	// some tests to see that everything works correctly
	Debug_Log("the location of vertexPos attribute in the shader is " << glGetAttribLocation(m_program.getID(), "vertexPos")); 
	// expected output is vertPos location = 0 and vertColor location = 1, just as specified in the shader.
	Debug_Log("the location of vertexColor attribute in the shader is " << glGetAttribLocation(m_program.getID(), "vertexColor"));
	
	int v;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &v);
	Debug_Log("max vertex attribs" << v);

	GLuint m_vao;
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//GLfloat vertecies[] = {0.0f,1.0f,0.0f,	1.0f,0.0f,0.0f, 0.0f,0.0f,0.0f };
	//Debug_Log(sizeof(vertecies));
	Vertex verts[3];
	verts[0].setPosition(0.0f, 1.0f, 0.0f);
	verts[0].setColor(Color8(255, 0, 0));
	verts[1].setPosition(1.0f, 0.0f, 0.0f);
	verts[1].setColor(Color8(255, 0, 0));
	verts[2].setPosition(0.0f, 0.0f, 0.0f);
	verts[2].setColor(Color8(255, 255, 0));
	Debug_Log(sizeof(verts));
	Debug_Log(sizeof(Vertex));
	GLuint m_vbo;
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	
	glUseProgram(m_program.getID()); 
	m_program.addAttribute("vertexPos", 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,position));
	m_program.addAttribute("vertexColor", 3, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

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
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f); // set the background color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);

		m_window.update(); // Update the window.
	}
	glDeleteBuffers(1, &m_vbo);
	glDeleteVertexArrays(1, &m_vao);
	m_program.deleteProgram();
	m_window.destroy();
	return 0;
}
