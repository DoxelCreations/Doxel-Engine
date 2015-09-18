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
	Debug_Log("the location of vertPos attribute in the shader is " << glGetAttribLocation(m_program.getID(), "vertPos")); 
	Debug_Log("the location of vertColor attribute in the shader is " << glGetAttribLocation(m_program.getID(), "vertColor")); 
	// expected output is vertPos location = 0 and vertColor location = 1, just as specified in the shader.

	

	GLuint m_vao;
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	//GLfloat vertecies[] = {0.0f,1.0f,0.0f,	1.0f,0.0f,0.0f, 0.0f,0.0f,0.0f };
	//Debug_Log(sizeof(vertecies));
	Vertex verts[3];
	verts[0].setPosition(0.0f, 1.0f, 0.0f);
	verts[1].setPosition(1.0f, 0.0f, 0.0f);
	verts[2].setPosition(0.0f, 0.0f, 0.0f);
	Debug_Log(sizeof(verts));
	Debug_Log(sizeof(Vertex));
	GLuint m_vbo;
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	
	m_program.addAttribute("vertPos", 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex,position));
	glEnableVertexAttribArray(glGetAttribLocation(m_program.getID(), "vertColor")); ///< crashing the program.
	glm::mat4 proj, view, model;

	m_program.uploadUniformMatrix("projection", 1, proj, GL_FALSE);
	m_program.uploadUniformMatrix("view", 1, view, GL_FALSE);
	m_program.uploadUniformMatrix("model", 1, model, GL_FALSE);


	while (!m_window.shouldWindowClose()) // The game loop.
	{
		m_inputManager.update();

		if(m_inputManager.isKeyPressed(KEYS::ESC)) // Check if pressed escape.
		{	
			m_window.setWindowClose(); // Close the window if you press the escape button.
		}
		glClearColor(0.0f, 1.0f, 1.0f, 1.0f); // set the background color
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//Debug_Log(m_window.getFramesPerSecond()); // Log the fps, use when you need to actually check the fps
		m_program.use();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		m_program.unuse();

		m_window.update(); // Update the window.
	}
	glDeleteBuffers(1, &m_vbo);
	glDeleteVertexArrays(1, &m_vao);
	m_program.deleteProgram();
	m_window.destroy();
	return 0;
}
