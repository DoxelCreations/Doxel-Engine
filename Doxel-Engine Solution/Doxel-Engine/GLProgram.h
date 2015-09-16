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

		void loadShaders(const char* vertexPath, const char* fragmentPath); // load the shaders, compile them and link them and create a glsl program id.
		void loadShadersFromSource(const char* vertexSource, const char* fragmentSource); // its also possible to write the shaders in visual studio and pass them as char*.
		void use(); // use the program and all of it attributes
		void unuse(); // unuse the program and all of it attributes

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
