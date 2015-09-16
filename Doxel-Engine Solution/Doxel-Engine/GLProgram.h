/*

FILE DESCRIPTION

this is the header for the GLProgram class.
the GLProgram will serve as an interface with the shaders we are gonna use, and will manage them.

when creating a GLProgram, load the shaders, then add attributes where they are needed, and use the program, when you are done drawing, unsuse the program.


*/

#pragma once

#include "Shader.h"
#include <glm\glm.hpp>

class GLProgram
{
	public:

		GLProgram();
		~GLProgram();

		/*

		This function loads the shaders, compile them and links them.

		Input:
		-const char* vertexPath - the path file to the vertex shader file from the project folder.
		-const char* fragPath - the path file to the fragment shader file from the project folder.

		Output:
		-

		*/
		void loadShaders(const char* vertexPath, const char* fragmentPath); // load the shaders, compile them and link them and create a glsl program id.

		/*

		This function loads the shaders from a source, compile them and links them.

		Input:
		-const char* vertexSource - the source of the vertex shader (the actual code).
		-const char* fragmentSource - the source of the fragment shader (the actual code).


		Output:
		-

		*/
		void loadShadersFromSource(const char* vertexSource, const char* fragmentSource); // its also possible to write the shaders in visual studio and pass them as char*.

		/*

		This function tell opengl to use the glsl program, and enables the atrributes.

		Input:
		-

		Output:
		-

		*/
		void use(); // use the program and all of it attributes

		/*

		This function tell opengl to unuse the glsl program, and disable the atrributes array.

		Input:
		-

		Output:
		-

		*/
		void unuse(); // unuse the program and all of it attributes
		/*

		This function add an attribute to the glsl program.

		Input:
		-const char* attribName - the name of the attribute in the shader.
		- GLint size - Specifies the number of components per generic vertex attribute. Must be 1, 2, 3, 4.
		- GLenum type - Specifies the data type of each component in the array.The symbolic constants GL_BYTE, GL_UNSIGNED_BYTE, GL_SHORT, GL_UNSIGNED_SHORT,
		GL_INT,  GL_UNSIGNED_INT, GL_HALF_FLOAT, GL_FLOAT, GL_DOUBLE, GL_FIXED are accepted.
		- GLboolean normalized - specifies whether fixed-point data values should be normalized (GL_TRUE) or converted directly as fixed-point values (GL_FALSE) when they are accessed.
		- GLsizei stride - Specifies the byte offset between consecutive generic vertex attributes. If stride is 0,
		the generic vertex attributes are understood to be tightly packed in the array. The initial value is 0.
		- const void* pointer - Specifies a offset of the first component of the first generic vertex attribute in the array in the data store of the buffer currently bound to the GL_ARRAY_BUFFER target.
		The initial value is 0.

		Output:
		-

		*/
		void addAttribute(const char* attribName, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer); 
		/*
		This function deletes this glsl program, call it when you dont need the program anymore.
		*/
		void deleteProgram() { if (m_programID) glDeleteProgram(m_programID); } 
		/*
		This function return the id of the program
		Output:
			- GLuint - the id of the glsl program.
		*/
		GLuint getID() { return m_programID; } 
		/*
		This function uploads a uniform matrix to the shader.

		Input:
		- char* name - the name of the uniform matrix in the shader.
		- int num - the number of matrixes you pass. if it isn't an array, the value should be 1.
		- glm::mat4 &mat - the matrix you want to pass TODO: add a way to pass arrays of matrixes for advance stuff.
		- GLboolean tranpose - specifies whether to transpose the matrix as the values are loaded into the uniform variable.
		Output:
		-

		*/
		void uploadUniformMatrix(char* name, int num, glm::mat4 &mat, GLboolean transpose); // upload a uniform matrix to the shader.
		/*
		this function gets the uniform location in the shader

		Input:
			- char* name - the name of the uniform in the shader.
		
		Output:
			- GLint - the location of the uniform in the shader.
		*/
		GLint getUniformLocation(char* name) { return glGetUniformLocation(m_programID, name); } 



	private:

		GLuint m_programID; // the program id.
		Shader m_shaders; // a shader object for loading compiling and linking.

		unsigned int m_numAttribs = 0; // the number of attributes in the program.
};
